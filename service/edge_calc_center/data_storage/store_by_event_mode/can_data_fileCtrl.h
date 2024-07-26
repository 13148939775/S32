/*
 * @author 007313 008196
 * @for Can Data written into file
 * @version 0.1
 * @date 2023-05
 * 
 * @Copyrigh (c) HIPHI Co., LTD 2023
 * 
 */

#ifndef ADCM_DATAFILECTRL_H
#define ADCM_DATAFILECTRL_H

#include <cstdint>
#include <list>
#include <map>
#include <atomic>

#include "DMDefine.h"

#include "HhtLooperThread.h"
#include "HhtMutex.h"

namespace HHT {
namespace DataManager {

// TODO: add to config?
constexpr char const * ADCM_DATA_ROOT = "/data/adcmdata";   // TBD
constexpr char const * ADCM_DATA_TMP_DIR = "tmp";
constexpr size_t ADCM_DATA_MAX_LENGTH = 15LL * 1024LL * 1024LL * 1024LL;  // 15G  TBD
constexpr char const * ADCM_ST_DATA_DIR = "structdata";
constexpr char const * ADCM_US_DATA_DIR = "nostructdata";
constexpr char const * ADCM_DATA_FILE_SUFFIX = ".data";
constexpr char const * ADCM_DATA_DESC_FILE_SUFFIX = ".cfg";
constexpr uint32_t ADCM_DATA_IO_REQUEST_MAX_COUNT = 8;  // TODO
constexpr size_t ADCM_DATA_IO_STEP_LENGTH = 1 * 1024 * 1024; // 1M Bytes
constexpr uint32_t ADCM_DATA_IO_THROUGHPUT_BYTE_PRE_MS = 1 * 1024 * 1024; // 1M Bytes / MS

//class AdcmHandler;
class CanDataFileCtrl {
using CanID = std::uint8_t;
public:
    // TODO: add DumpId and name to DataFileInfo, use DumpId as the key of DFInfos
    struct DataFileInfo {
        size_t size;
        bool confirmed;
    };

    using DFInfos = std::map<std::string, DataFileInfo>; // <name, FileInfo>
public:
    CanDataFileCtrl(AdcmHandler& handler);
    ~CanDataFileCtrl();

    void Init();
    void Deinit();
    void Activate(const CanID id);  // include all the signal of can
    void Deactivate(const CanID id);

    //////////////////////////
    void Dump(const DumpInfo& info);
    void Confirm(const DumpHeader& header);

    std::string lock();
    void unlock(const std::string& lckName);
    void preventIoAccess(bool prevent);

private:
    void dumpImpl(DumpInfo info);
    void confirmImpl(DumpHeader header);

    std::string header2str(const DumpHeader& header);

    bool WriteRaw(const std::string& path, RingBuffer data);
    bool WriteZip(const std::string& path, RingBuffer data);

private:
    AdcmHandler& mHandler;
    DFInfos mDFInfos;
    uint64_t mDfTotalSize;
    std::string mUploadingName;
    Mutex mDFInfoLock;  // lock: mDFInfos/mDfTotalSize/mUploadingName
    LooperThread mIoThread;
    bool mActivated;
    bool mPreventIoAccess;
    std::unordered_map<int, bool> enablePro_;
};  
}  // namespace datamanager
}  // namespace hht
#endif	// ADCMDATAFILECTRL_H
