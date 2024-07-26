#ifndef DMDEFINE_H
#define DMDEFINE_H

#include <stdint.h>
#include <stdlib.h>

#include <string>
#include <list>

// #define DEBUG_NOT_USE_CAM
#define ADCM_USE_ZIP
// #define ENABLE_MD5_CHECKSUM

#define TRIGGER_CFG_PATH "/hht_svp/DataManager-runtime/etc/TriggerCfgGen.yaml"

namespace hht {
namespace datamanager {

using ModuleId = uint32_t;
using DumpId = uint32_t;

enum ErrorCode {
    OK,
    // TODO:... Error Codes ...
    UnkownError
};

enum DataType {
    Structured,
    Unstructured,
    Apa
};

enum State {
    Uninit,
    Inited,
    Activated,

    InvalidState
};

struct StDataInfo {
    int32_t topic;
};

struct UsDataInfo {
    uint64_t timestamp;
    uint32_t frameindex;
};

struct ApaDataInfo {
    int32_t pakgId;
    int32_t fileId;
};

struct DataInfo {
    ModuleId mid;
    DataType dtype;
    size_t channel;
    union {
        StDataInfo stInfo;
        UsDataInfo usInfo;
        ApaDataInfo apaInfo;
    };
};


///////////////////////////

struct TriggerInfo {
    int32_t triggerId;
    uint64_t triggerMs;
    uint64_t beginMs;
    uint64_t endMs;
};

using TriggerInfoList = std::list<TriggerInfo>;

struct RingBuffer {
    uint8_t* buffer;
    size_t bufferSize;
    size_t offset;
    size_t dataLength;
};

struct DumpHeader {
    DumpId id;
    uint64_t beginMs;
    uint64_t endMs;
    TriggerInfoList triInfos;
#ifdef ENABLE_MD5_CHECKSUM
    unsigned char digest[16];
#endif
};
struct DumpInfo {
    DumpHeader header;
    RingBuffer buffer;
};

//////////////////////////////////////

constexpr ModuleId INVALID_MODULEID = 0xFFFFFFFF;
constexpr ModuleId PROVIDERID_DSV = 0;
constexpr ModuleId PROVIDERID_NOH = 1;
constexpr ModuleId PROVIDERID_CAM = 2;  // Camera
constexpr ModuleId HADNLERID_ADCM = 3;
constexpr ModuleId HADNLERID_RECD = 4;  // last module
constexpr ModuleId PROVIDERID_CAN = 5;  // Camera

constexpr size_t MODULE_COUNT = PROVIDERID_CAN + 1;  // last moduleId + 1

}  // namespace datamanager
}  // namespace hht
#endif	// DMDEFINE_H
