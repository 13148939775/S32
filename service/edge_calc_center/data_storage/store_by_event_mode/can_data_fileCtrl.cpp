/*
 * @author 007313 008196
 * @for Can Data written into compressed file before upload
 * @incase of discotinue network
 * @version 0.1
 * @date 2023-05
 * 
 * @Copyrigh (c) HIPHI Co., LTD 2023
 * 
 */

#include "AdcmDataFileCtrl.h"

#include <node_log.h>
#include "zip.h"

#include "can_data_handler.h"

#include "PathTool.h"
#include "HhtTaskLooper.h"
#include "HhtAtomicFile.h"
#include "HhtTimeTick.h"

constexpr uint32_t POWEROFF_IO_WAITING_MS = 500;

namespace HHT {
namespace DataManager {

static bool strEndsWith(const std::string& str, const std::string& suffix) {
    if (str.length() < suffix.length()) {
        return false;
    }
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
}

CanDataFileCtrl::CanDataFileCtrl(const AdcmHandler& handler)
    : mHandler(handler),
      mDFInfos(),
      mDfTotalSize(0),
      mUploadingName(),
      mDFInfoLock(),
      mIoThread(),
      mActivated(false),
      mPreventIoAccess(false) 
{ }

CanDataFileCtrl::~AdcmDataFileCtrl() 
{ }

void CanDataFileCtrl::Init() 
{
    // remove uncompleted data
    PathTool::rmPath(PathTool::join(ADCM_DATA_ROOT, ADCM_DATA_TMP_DIR));

    // Try to make ADCM_DATA_ROOT
    PathTool::mkDir(ADCM_DATA_ROOT, true);

    std::list<std::string> dirs;
    std::list<std::string> files;
    PathTool::walkDir(ADCM_DATA_ROOT, dirs, files);

    // check subDirs
    for (auto& dpath: dirs) {
        LOG(WARNING) << "init: unkown dir: " << PathTool::join(ADCM_DATA_ROOT, dpath);
        // TODO: remove unkown dirs?
    }

    // find datafile and descfile
    std::map<std::string, size_t> dfileCount;  // <name, count>
    for (auto& fpath: files) {
        if (PathTool::deep(fpath) > 1) {
            // TODO: how to deal with files in subDirs?
            continue;
        }

        std::string filename;
        if (strEndsWith(fpath, ADCM_DATA_FILE_SUFFIX)) {
            filename = fpath.substr(0, fpath.length() - strlen(ADCM_DATA_FILE_SUFFIX));
        } else if (strEndsWith(fpath, ADCM_DATA_DESC_FILE_SUFFIX)) {
            filename = fpath.substr(0, fpath.length() - strlen(ADCM_DATA_DESC_FILE_SUFFIX));
        } else {
            // TODO: Maybe config file
            std::string absPath = PathTool::join(ADCM_DATA_ROOT, fpath);
            LOG(WARNING) << "init: unkown file suffix, remove it. fpath: " << absPath;

            PathTool::rmPath(absPath);
            continue;
        }

        assert(!filename.empty());

        // TODO: Check if matched the naming conventions.
        ++dfileCount[filename];
    }

    AutoLock lk(mDFInfoLock);

    // fill mDFInfos
    for (auto& element: dfileCount) {
        std::string dataFPath =
            PathTool::join(ADCM_DATA_ROOT, element.first) + ADCM_DATA_FILE_SUFFIX;
        std::string descFPath =
            PathTool::join(ADCM_DATA_ROOT, element.first) + ADCM_DATA_DESC_FILE_SUFFIX;

        if (2 != element.second) {
            assert(1 == element.second);
            LOG(WARNING) << "init: data file count not matched: " << element.first << ": "
                         << element.second;

            if (PathTool::isExist(dataFPath)) {
                LOG(WARNING) << "init: for count not matched: remove: " << dataFPath;
                PathTool::rmPath(dataFPath);
            }
            if (PathTool::isExist(descFPath)) {
                LOG(WARNING) << "init: for count not matched: remove: " << descFPath;
                PathTool::rmPath(descFPath);
            }
            continue;
        }

        // 2 == element.second: datafile + descfile
        assert(PathTool::isExist(dataFPath));
        assert(PathTool::isExist(descFPath));
        assert(0 == mDFInfos.count(element.first));

        size_t daSize = PathTool::fileLength(dataFPath);
        size_t deSize = PathTool::fileLength(descFPath);
        mDFInfos[element.first] = {daSize + deSize, true};

        mDfTotalSize += (uint64_t)mDFInfos[element.first].size;
    }

    // Check Overflow
    while (mDfTotalSize > ADCM_DATA_MAX_LENGTH && !mDFInfos.empty()) {
        std::string name = mDFInfos.begin()->first;
        std::string dataFPath = PathTool::join(ADCM_DATA_ROOT, name) + ADCM_DATA_FILE_SUFFIX;
        std::string descFPath = PathTool::join(ADCM_DATA_ROOT, name) + ADCM_DATA_DESC_FILE_SUFFIX;
        PathTool::rmPath(dataFPath);
        PathTool::rmPath(descFPath);
        mDfTotalSize -= mDFInfos.begin()->second.size;
        mDFInfos.erase(mDFInfos.begin());
    }

    assert(mDfTotalSize <= ADCM_DATA_MAX_LENGTH);
    PathTool::mkDir(PathTool::join(ADCM_DATA_ROOT, ADCM_DATA_TMP_DIR));
    mIoThread.start();
}

void CanDataFileCtrl::deinit() {
    // TODO:

    mIoThread.stop();
    mIoThread.join();
}

void CanDataFileCtrl::Activate() {
    // mActivated = true;
    enablePro_[id] = true;
}

void CanDataFileCtrl::Deactivate(const CanID id) {
    // mActivated = false;
    enablePro_[id] = false;
}

void CanDataFileCtrl::Dump(const DumpInfo& info) 
{
    mIoThread.looper().postTask(std::bind(&CanDataFileCtrl::dumpImpl, this, info));
}

void CanDataFileCtrl::Confirm(const DumpHeader& header) {
    mIoThread.looper().postTask(std::bind(&CanDataFileCtrl::confirmImpl, this, header));
}

std::string CanDataFileCtrl::lock() {
    AutoLock al(mDFInfoLock);
    if (!mUploadingName.empty()) {
        LOG(ERROR) << "lock: already has locked datafile: " << mUploadingName;
        return "";
    }

    if (mDFInfos.empty()) {
        // no datafile
        return "";
    }

    for (auto it = mDFInfos.begin(); it != mDFInfos.end(); ++it) {
        if (it->second.confirmed) {
            mUploadingName = it->first;
            break;
        }
    }
    return mUploadingName;
}

void CanDataFileCtrl::unlock(const std::string& lckName) {
    {
        AutoLock al(mDFInfoLock);
        if (mUploadingName != lckName) {
            LOG(ERROR) << "unlock: lockName not equal: " << lckName << " vs. " << mUploadingName;
        } else {
            mUploadingName.clear();
        }

        // Remove unlocked
        auto it = mDFInfos.find(lckName);
        if (it == mDFInfos.end()) {
            LOG(ERROR) << "unlock: lockName not in DataFileInfos: " << lckName;
        } else {
            mDFInfos.erase(it);
        }
    }

    std::string dataFPath = PathTool::join(ADCM_DATA_ROOT, lckName) + ADCM_DATA_FILE_SUFFIX;
    std::string descFPath = PathTool::join(ADCM_DATA_ROOT, lckName) + ADCM_DATA_DESC_FILE_SUFFIX;
    uint64_t dataLength = PathTool::fileLength(dataFPath);
    uint64_t descLength = PathTool::fileLength(descFPath);
    PathTool::rmPath(dataFPath);
    PathTool::rmPath(descFPath);
    mDfTotalSize -= dataLength;
    mDfTotalSize -= descLength;
}

void CanDataFileCtrl::preventIoAccess(bool prevent) {
    mPreventIoAccess = prevent;
}

void CanDataFileCtrl::DumpImpl(DumpInfo info) 
{
    // const uint32_t INTERVAL_PER_STEP_MS =
    //     ADCM_DATA_IO_STEP_LENGTH / ADCM_DATA_IO_THROUGHPUT_BYTE_PRE_MS;

    do {
        // TODO: check mActivated
        // TODO: power down

        std::string name = StrTool::format("%ju", info.header.beginMs);
        {
            AutoLock lk(mDFInfoLock);
            if (mDFInfos.count(name) != 0) {
                LOG(ERROR) << "dumpImpl: duplicate data file, discard! " << name;
                break;
            }
        }

        std::string headerContext = header2str(info.header);
        size_t descSize = headerContext.length();
        {
            AutoLock lk(mDFInfoLock);

            for (auto it = mDFInfos.begin(); it != mDFInfos.end();) {

			    // if current space is enough after remove oldest data.
                if (mDfTotalSize + descSize + info.buffer.dataLength < ADCM_DATA_MAX_LENGTH) {
                    // has enough space
                    break;
                }

                if (it->first == mUploadingName) {
                    // skip uploading datafile
                    ++it;
                    continue;
                }

				// Overflow strategy: remove oldest
                std::string dataFPath =
                    PathTool::join(ADCM_DATA_ROOT, it->first) + ADCM_DATA_FILE_SUFFIX;
                std::string descFPath =
                    PathTool::join(ADCM_DATA_ROOT, it->first) + ADCM_DATA_DESC_FILE_SUFFIX;
                uint64_t dataLength = PathTool::fileLength(dataFPath);
                uint64_t descLength = PathTool::fileLength(descFPath);
                PathTool::rmPath(dataFPath);
                PathTool::rmPath(descFPath);
                mDfTotalSize -= dataLength;
                mDfTotalSize -= descLength;

                it = mDFInfos.erase(it);
            }

            if (mDfTotalSize + descSize + info.buffer.dataLength >= ADCM_DATA_MAX_LENGTH) {
                // Release failed, still no space to write new datafile
                LOG(ERROR) << "dumpImpl: Release failed. Still no space to write new datafile";
                break;
            }
        }

        // write to ADCM_DATA_ROOT/ADCM_DATA_TMP_DIR, and move to ADCM_DATA_ROOT when confirmed
        std::string tmpPathBase =
            PathTool::join(PathTool::join(ADCM_DATA_ROOT, ADCM_DATA_TMP_DIR), name);
        std::string dataFPath = tmpPathBase + ADCM_DATA_FILE_SUFFIX;

#ifdef ADCM_USE_ZIP
        bool ret = writeZip(dataFPath, info.buffer);
        (void)ret;
#else
        bool ret = writeRaw(dataFPath, info.buffer);
#endif
        // write descfile
        std::string descFPath = tmpPathBase + ADCM_DATA_DESC_FILE_SUFFIX;
        AtomicFile descFile(descFPath);
        descFile.write(headerContext);

        // Add to mDFInfos
        {
            AutoLock lk(mDFInfoLock);
            uint64_t dFLength = PathTool::fileLength(dataFPath) + PathTool::fileLength(descFPath);
            mDFInfos[name] = {dFLength, false};
            mDfTotalSize += dFLength;
        }
    } while (false);

    mHandler.onWritten(info.header.id, info.buffer.buffer);
}

void CanDataFileCtrl::confirmImpl(DumpHeader header) 
{
    std::string name = StrTool::format("%ju", header.beginMs);
    std::string descFPath;
    std::string headerContext;
    {
        AutoLock al(mDFInfoLock);
        if (mUploadingName == name) {
            LOG(ERROR) << "confirmImpl: datafile is uploading, refuse to update header: "
                       << name;
            return;
        }
        auto it = mDFInfos.find(name);
        if (it == mDFInfos.end()) {
            LOG(ERROR) << "confirmImpl: header not found: " << name;
            return;
        }

        if (it->second.confirmed) {
            // TODO: should refust update confirmed header?
            LOG(ERROR) << "confirmImpl: update a confirmed header: " << name;
            return;
        }

        headerContext = header2str(header);
        std::string basePath =
            it->second.confirmed
                ? PathTool::join(ADCM_DATA_ROOT, name)
                : PathTool::join(PathTool::join(ADCM_DATA_ROOT, ADCM_DATA_TMP_DIR), name);
        descFPath = basePath + ADCM_DATA_DESC_FILE_SUFFIX;
        size_t oldLength = PathTool::fileLength(descFPath);
        size_t newLength = headerContext.length();

        it->second.size -= oldLength;
        it->second.size += newLength;

        mDfTotalSize -= oldLength;
        mDfTotalSize += newLength;

        it->second.confirmed = true;
    }

    {
        if (descFPath.empty() || headerContext.empty()) {
            LOG(ERROR) << "confirmImpl: descFPath or Context is empty: path: " << descFPath.size() << ", cxt: " << headerContext.size();
            return;
        }
        AtomicFile descFile(descFPath);
        descFile.write(headerContext);
    }

    // move tmp to uploader directory
    std::string oldBasePath = PathTool::join(PathTool::join(ADCM_DATA_ROOT, ADCM_DATA_TMP_DIR), name);
    std::string newBasePath = PathTool::join(ADCM_DATA_ROOT, name);
    rename((oldBasePath + ADCM_DATA_DESC_FILE_SUFFIX).c_str(), (newBasePath + ADCM_DATA_DESC_FILE_SUFFIX).c_str());
    rename((oldBasePath + ADCM_DATA_FILE_SUFFIX).c_str(), (newBasePath + ADCM_DATA_FILE_SUFFIX).c_str());

    mHandler.onWritterConfirmed(header.id);  // ready to upload
}

std::string CanDataFileCtrl::header2str(const DumpHeader& header) {
    std::string ret("{\n");

    ret += "    \"SWVersion\": \"" + mHandler.cfg().integrationVersion() + "\",\n";
    ret += "    \"begin\": " + StrTool::format("%ju", header.beginMs) + ",\n";
    ret += "    \"end\": " + StrTool::format("%ju", header.endMs) + ",\n";

    std::list<std::string> triggerInfos;
    std::string triggerStr;
    for (auto& triggerInfo: header.triInfos) {
        triggerStr  = "    \"Trigger_" + StrTool::format("%d", triggerInfo.triggerId) + "_" + StrTool::format("%ju", triggerInfo.triggerMs) + "\": {\n";
        triggerStr += "        begin: " + StrTool::format("%ju", triggerInfo.beginMs) + ",\n";
        triggerStr += "        end: " + StrTool::format("%ju", triggerInfo.endMs) + "\n";
        triggerStr += "    }";

        triggerInfos.push_back(triggerStr);
    }
    ret += StrTool::join(triggerInfos, ",\n");

    #ifdef ENABLE_MD5_CHECKSUM
    std::string digest_str;
    for (size_t i = 0; i != 16; ++i)
    {
        digest_str += "0123456789abcdef"[header.digest[i] / 16];
        digest_str += "0123456789abcedf"[header.digest[i] % 16];
    }
    ret += ",\n";
    ret += "    \"Md5\": " + digest_str + ",";
    #endif
    ret += "\n";
    ret += "}\n";
    return ret;
}

bool CanDataFileCtrl::writeRaw(const std::string& path, RingBuffer data) {
    const uint32_t INTERVAL_PER_STEP_MS =
        ADCM_DATA_IO_STEP_LENGTH / ADCM_DATA_IO_THROUGHPUT_BYTE_PRE_MS;

    int fd = open(path.c_str(), O_WRONLY | O_CREAT | S_IRUSR | S_IWUSR);
    if (fd < 0) {
        LOG(ERROR) << "writeRaw: open file failed: " << path;
        return false;
    }
    size_t offset = 0;
    while (offset < data.dataLength) {
        if(mPreventIoAccess){
            LOG_EVERY_T(INFO, 0.5) << "PowerOff when writing: " << path;
            close(fd);
            fd = -1;
        } else if (!mPreventIoAccess && fd < 0) {
            LOG(WARNING) << "PowerOn and Start Writing: " << path;
            fd = open(path.c_str(), O_WRONLY | O_CREAT | O_APPEND | S_IRUSR | S_IWUSR);
        }

        int64_t stepBeginMs = timeTickMs();

        if (fd >= 0) {
            size_t writelen = std::min(ADCM_DATA_IO_STEP_LENGTH, (data.dataLength - offset));
            if (data.offset + offset < data.bufferSize && data.offset + offset + writelen > data.bufferSize) {
                // For Boundary
                write(fd, data.buffer + data.offset + offset, data.bufferSize - data.offset - offset);
                write(fd, data.buffer, data.offset + offset + writelen - data.bufferSize);
            } else {
                if (data.offset + offset >= data.bufferSize) {
                    write(fd, data.buffer + data.offset + offset - data.bufferSize, writelen);
                } else {
                    write(fd, data.buffer + data.offset + offset, writelen);
                }
            }
            offset += writelen;
        }

        int64_t intervalMs = timeTickMs() - stepBeginMs;
        if (INTERVAL_PER_STEP_MS > intervalMs) {
            usleep((INTERVAL_PER_STEP_MS - intervalMs) * 1000);
        } else {
            // sleep to release IO/CPU, event if INTERVAL_PER_STEP_MS <= intervalMs
            usleep(1);
        }
    }

    close(fd);
    return true;
}

bool CanDataFileCtrl::WriteZip(const std::string& path, RingBuffer data) 
{
    const uint32_t INTERVAL_PER_STEP_MS =
        ADCM_DATA_IO_STEP_LENGTH / ADCM_DATA_IO_THROUGHPUT_BYTE_PRE_MS;
    bool isDone = false;

    while (!isDone) {
        zipFile zf = zipOpen(path.c_str(), APPEND_STATUS_CREATE);
        if (!zf) {
            LOG(ERROR) << "writeZip: open zipOpen failed.";
            return false;
        }

        std::string name = PathTool::baseName(path);
        int ret = zipOpenNewFileInZip(zf, name.c_str(), NULL, NULL, 0, NULL, 0, NULL, Z_DEFLATED, Z_BEST_COMPRESSION);
        if (ret != ZIP_OK) {
            LOG(ERROR) << "writeZip: add " << name << " to zf failed: " << path;
            return false;
        }

        size_t offset = 0;
        while (offset < data.dataLength) {
            if(mPreventIoAccess){
                break;
            }
            int64_t stepBeginMs = timeTickMs();

            if (zf) {
                size_t writelen = std::min(ADCM_DATA_IO_STEP_LENGTH, (data.dataLength - offset));
                if (data.offset + offset < data.bufferSize && data.offset + offset + writelen > data.bufferSize) {
                    // For Boundary
                    zipWriteInFileInZip(zf, data.buffer + data.offset + offset, data.bufferSize - data.offset - offset);
                    zipWriteInFileInZip(zf, data.buffer, data.offset + offset + writelen - data.bufferSize);
                } else {
                    if (data.offset + offset >= data.bufferSize) {
                        zipWriteInFileInZip(zf, data.buffer + data.offset + offset - data.bufferSize, writelen);
                    } else {
                        zipWriteInFileInZip(zf, data.buffer + data.offset + offset, writelen);
                    }
                }
                offset += writelen;
            }

            int64_t intervalMs = timeTickMs() - stepBeginMs;
            if (INTERVAL_PER_STEP_MS > intervalMs) {
                usleep((INTERVAL_PER_STEP_MS - intervalMs) * 1000);
            } else {
                // sleep to release IO/CPU, event if INTERVAL_PER_STEP_MS <= intervalMs
                usleep(1);
            }
        }

        zipCloseFileInZip(zf);
        zipClose(zf, NULL);

        if(offset == data.dataLength){
            isDone = true;
        }
        usleep(POWEROFF_IO_WAITING_MS * 1000);
    }
    return isDone;
}

}  // namespace datamanager
}  // namespace hht
