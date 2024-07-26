/*
 * @file signal_store_ctrl.h
 * @author 008196
 * @for store vehicle signal to file
 * @version 0.1
 * @date 2023-02 ~ 2023-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "signal_store_ctrl.h"

#include <string>
#include <map>
#include <list>
#include <iomanip>
#include <cstdio>

#include "PathTool.h"
#include "HhtLooperThread.h"
#include "HhtTaskLooper.h"
#include "HhtAtomicFile.h"
#include "HhtBufPool.h"
#include "HhtTimeTick.h"

#include <node_log.h>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>
#include "signal_inject/signal_inject.h"

namespace HHT {
namespace DataManager {

static constexpr char const * APA_DATA_ROOT = "/home/root/log";
static constexpr char const * TRANS_TMP_DIR = "cccData";

// TODO: add to config?
static constexpr uint32_t LOCAL_STORAGE_MAX_SIZE = 1032 * 1024 * 1024; // 1G Bytes
static constexpr uint32_t RECEIVE_BUFFER_LENGTH = 1032 * 1024;  // 1M Bytes
static constexpr uint32_t RECEIVE_BUFFER_COUNT = 128;
static constexpr uint32_t IO_STEP_LENGTH = 1032; // 1K Bytes
static constexpr uint32_t IO_THROUGHPUT_BYTE_PRE_S = 10 * 1032; // 10 KByes / S
static constexpr uint32_t DATA_LENGTH = 1024;
static constexpr uint32_t TIMESTAMP_LENGTH = 8;

static uint64_t parseTimeSec(std::string& time_str, std::string& format) {
    std::istringstream ss(time_str);
    std::tm tm = {};
    ss >> std::get_time(&tm, format.data());
    std::time_t t = std::mktime(&tm);
    return t;
}

class SignalStoreCtrl::Impl {
public:
    struct FileInfo {
        std::string name;  // TODO: rename to path
        size_t size;
    };

    struct PkgInfo {
        std::string name;
        size_t size;
        std::map<std::string, FileInfo> files;
    };

    struct TransInfo {
        std::string pkgName;
        size_t totalSize;
        std::string filePath;
        uint8_t* buffer;
        size_t bufWriteSize;
    };

    struct BufInfo {
        uint8_t* ptr;
        size_t len;
    };

    struct IoCache {
        std::string pkgName;
        std::map<std::string, std::list<BufInfo>> fileDatas;  // <filePath, BufList>

        void clear() {
            pkgName.clear();
            fileDatas.clear();
        }
    };

    enum AbnormalStatus {
       onPkgFailed = 1,
       OnFileFailed,
       Unknown
    };
public:
    Impl(SignalStoreCtrl& owner);
    ~Impl();

    // Run in WorkThread
    void Init();
    void start(std::string& sn);
    void OnFileFragmentReceived(TransInfo& info);
    void OnErrHandle(AbnormalStatus);

    // Run in IoThread
    void WritePkg(IoCache& cache);

    std::string GetCurrentDataTime();

public:
    void OnDataReceived(const std::string& pkgName, const std::string& filepath, const char* data, size_t length);
public:
    SignalStoreCtrl& mOwner;
    LooperThread workThread_;
    LooperThread IoThread_;

    BufPool bufPool_;
    TransInfo transInfo_;
    IoCache IoCache_;

    bool simRunning_;
    bool mPreventIoAccess;
private:
    std::thread tl_;
};

SignalStoreCtrl::Impl::Impl(SignalStoreCtrl& owner)
    : mOwner(owner),
      workThread_(),
      IoThread_(),
      bufPool_(RECEIVE_BUFFER_LENGTH, RECEIVE_BUFFER_COUNT),
      transInfo_({"", 0, "", nullptr, 0}),
      IoCache_(),
      simRunning_(true),
      mPreventIoAccess(false)

    { }

SignalStoreCtrl::Impl::~Impl() {

}

void SignalStoreCtrl::Impl::Init()
{
}

void SignalStoreCtrl::Impl::start(std::string& sn) {
    Init();
}

void SignalStoreCtrl::storeData(const std::string& pkgName, const std::string& filepath, char* buffer , const size_t len)
{
    mImpl->OnDataReceived(pkgName, filepath, buffer, len);
}

/**
  * @brief file frag accumulate to 5M , then ready to save file
  */
void SignalStoreCtrl::Impl::OnFileFragmentReceived(TransInfo& info) {

    HHT_LOG(INFO) <<info.filePath<< "  OnFileFragmentReceived " << IoCache_.fileDatas[info.filePath].size();
    if (IoCache_.pkgName != info.pkgName) {
        HHT_LOG(ERROR) << "OnFileFragmentReceived: pkgName not matched: " << IoCache_.pkgName << ", " << info.pkgName;
        return;
    }


    IoCache_.fileDatas[info.filePath].push_back({info.buffer, info.bufWriteSize});
    constexpr std::size_t filethreshold = 2; // 2 * 1032 *1024;
    HHT_LOG(INFO) <<info.filePath << " check filedatas size:" << IoCache_.fileDatas[info.filePath].size();
    if (IoCache_.fileDatas[info.filePath].size() > 2) {
        IoThread_.looper().postTask(std::bind(&SignalStoreCtrl::Impl::WritePkg, this, IoCache_));
        IoCache_.clear();
    }
}

void SignalStoreCtrl::Impl::WritePkg(IoCache& cache)
{
    HHT_LOG(INFO) << "WritePkg" << cache.fileDatas.size();
    const int64_t INTERVAL_PER_STEP_MS = (int64_t)IO_STEP_LENGTH * 1000 / (int64_t)IO_THROUGHPUT_BYTE_PRE_S;
    char buffer[10];
    std::string pkgPath = PathTool::join(APA_DATA_ROOT, cache.pkgName);
    std::string tmpPkgPath = PathTool::join(APA_DATA_ROOT, TRANS_TMP_DIR);
    tmpPkgPath = PathTool::join(tmpPkgPath, cache.pkgName);

    std::cout<<"SignalStoreCtrl::Impl::WritePkg"<<std::endl;
    char enterSym = '\n';
    for (auto it = cache.fileDatas.begin(); it != cache.fileDatas.end(); ++it) {
        std::string filePath = PathTool::join(tmpPkgPath, it->first);
        PathTool::mkDir(PathTool::dirName(filePath), true);

        std::string filePatht = GetCurrentDataTime() + ".txt";
        filePath += filePatht;
        int fd = open(filePath.c_str(), O_WRONLY | O_CREAT | S_IRUSR | S_IWUSR);
        if (fd < 0) {
            HHT_LOG(ERROR) << "WritePkg: open file failed: " << filePath ;
             std::perror("Error");
            continue;
        }
        for (BufInfo& bufInfo: it->second) {
            size_t offset = 0;
            while (offset < bufInfo.len) {
        	memset(buffer,0,sizeof(buffer));
                if (mPreventIoAccess && fd >= 0) {
                    HHT_LOG(INFO) << "PowerOff when writing: " << filePath;
                    close(fd);
                    fd = -1;
                } else if (!mPreventIoAccess && fd < 0) {
                    HHT_LOG(WARNING) << "PowerOn and Start Writing: " << filePath;
                    fd = open(filePath.c_str(), O_WRONLY | O_CREAT | O_APPEND | S_IRUSR | S_IWUSR);
                }

                int64_t stepBeginMs = timeTickMs();
                if (fd >= 0) {  // ready to push into storage
                    size_t writelen = std::min(IO_STEP_LENGTH, (uint32_t)(bufInfo.len - offset));
                    
                    int64_t *pTime = (int64_t *)(bufInfo.ptr + offset + DATA_LENGTH);
                    std::string timestamp = std::to_string(*pTime) + " " ;
                    
                    write(fd, timestamp.c_str(), timestamp.length() );
                    //data save
                    char *p = (char*)(bufInfo.ptr + offset);

                    for (int i=0; i < writelen-TIMESTAMP_LENGTH; ++i) {
                        sprintf(buffer, "%02X", static_cast<unsigned char>(p[i])); 
                        write(fd, buffer,2);
                    }
                    //换行
                    write(fd,&enterSym,1);

                    offset += writelen;
                }

                int64_t intervalMs = timeTickMs() - stepBeginMs;
                if (INTERVAL_PER_STEP_MS > intervalMs) {
                    usleep(INTERVAL_PER_STEP_MS - intervalMs);
                } else {
                    // sleep a short time to rlease IO & CPU
                    usleep(1);
                }
            }
            bufPool_.releaseBuf(bufInfo.ptr);
        }
        close(fd);
    }
    HHT_LOG(INFO) << "exit write file ";
    rename(tmpPkgPath.c_str(), pkgPath.c_str());
}

/**
  * @brief while Get the pub data
  */
void SignalStoreCtrl::Impl::OnDataReceived(const std::string& pkgName, const std::string& filepath,
                                     const char* data, size_t length) {
    if (!data || !length) {
        HHT_LOG(ERROR) << "OnDataReceived: invalid data: " << (void*)data << ", " << length;
        return;
    }
    if (transInfo_.filePath.empty()) {
        transInfo_.filePath = filepath;
    }

    size_t offset = 0;
    while (length > offset) {
        if (!transInfo_.buffer) {
            transInfo_.buffer = bufPool_.mallocBuf();
            if (!transInfo_.buffer) {
                HHT_LOG(ERROR) << "OnDataReceived: not enough buffer. discard the whole pkg.";
                workThread_.looper().postTask(
                    std::bind(&SignalStoreCtrl::Impl::OnErrHandle, this, onPkgFailed));
                // clear TransInfo
                transInfo_ = {"", 0, "", nullptr, 0};
            }
            transInfo_.bufWriteSize = 0;
        }
        size_t writeLen = std::min(RECEIVE_BUFFER_LENGTH - transInfo_.bufWriteSize, length - offset);
        if (writeLen) {
            memcpy(transInfo_.buffer + transInfo_.bufWriteSize, data + offset, writeLen);
            offset += writeLen;
            transInfo_.bufWriteSize += writeLen;
        }
        if (RECEIVE_BUFFER_LENGTH == transInfo_.bufWriteSize) {

            // buffer full, send buffer
            workThread_.looper().postTask(
                std::bind(&SignalStoreCtrl::Impl::OnFileFragmentReceived, this, transInfo_));
            transInfo_.buffer = nullptr;
            transInfo_.bufWriteSize = 0;
        }
    }
}

/**
  * @brief while Get the pub data
  */
void SignalStoreCtrl::Impl::OnErrHandle(AbnormalStatus as)
{
    HHT_LOG(ERROR) << "Err Center occur:" << as ;
}

std::string SignalStoreCtrl::Impl::GetCurrentDataTime()
{
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::string timestamp = std::to_string(ms);
    return timestamp;
}

SignalStoreCtrl::SignalStoreCtrl() : mImpl(new Impl(*this)) {}
SignalStoreCtrl::~SignalStoreCtrl() { delete mImpl; }

void SignalStoreCtrl::start(const std::string& sn) {
    mImpl->workThread_.start();
    mImpl->IoThread_.start();
    mImpl->workThread_.looper().postTask(std::bind(&SignalStoreCtrl::Impl::start, mImpl, sn));
}

void SignalStoreCtrl::stop() {
    // TODO: on workthread
    mImpl->workThread_.stop();
    mImpl->workThread_.join();
    mImpl->IoThread_.stop();
    mImpl->IoThread_.join();
}

}  // namespace datamanager
}  // namespace HHT
