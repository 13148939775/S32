#include "ConfigCtrl.h"

#include <fstream>

#include "json.h"

#include "ConfigInfo.h"
#include "VehicleConfigDefine.h"
#include "glog/logging.h"

namespace hht {
namespace datamanager {

// Attibute Keys
static constexpr const char * const ADDR_IPV4 = "AddrIpv4";
static constexpr const char * const ST_PORT = "StructruedPort";
static constexpr const char * const US_PORT = "UnstructruedPort";
static constexpr const char * const RM_PORT = "RecoderMonitorPort";
static constexpr const char * const ST_CH_NUM = "StructruedChannelNum";
static constexpr const char * const US_CH_NUM = "UnstructruedChannelNum";
static constexpr const char * const ST_FLUSH_INTERVAL_MS = "StructruedFlushIntervalMs";
static constexpr const char * const US_FLUSH_INTERVAL_MS = "UnstructruedFlushIntervalMs";
static constexpr const char * const USE_ST = "UseStructruedData";
static constexpr const char * const USE_US = "UseUnstructruedData";
static constexpr const char * const INIT_US = "InitUnstructuredData";
static constexpr const char * const USE_NOH = "UseNoh";
static constexpr const char * const USE_UPLOAD = "UseUpload";
static constexpr const char * const USE_RECORD = "UseRecord";
static constexpr const char * const RM_HB_TIMEOUT_MS = "RmHeartBeatTimeoutMs";
static constexpr const char * const VER_JSON_INTEGRATION = "Integration";
static constexpr const char * const VER_JSON_PATH = "/hht_svp/version.json";

// Attibute Default Values
static constexpr const char * const DEFAULT_ATTR_ADDRIPV4 = "*";
static constexpr uint16_t DEFAULT_ATTR_STPORT = 30505;
static constexpr uint16_t DEFAULT_ATTR_USPORT = 20000;
static constexpr uint16_t DEFAULT_ATTR_RMPORT = 10040;
static constexpr uint16_t DEFAULT_ATTR_STCHANNELNUM = 1;
static constexpr uint16_t DEFAULT_ATTR_USCHANNELNUM = 2;
static constexpr uint16_t DEFAULT_ATTR_STFLUSHINTERVALMS = 500;
static constexpr uint16_t DEFAULT_ATTR_USFLUSHINTERVALMS = 500;
static constexpr bool DEFAULT_ATTR_USESTRUCTRUED = true;
static constexpr bool DEFAULT_ATTR_USEUNSTRUCTRUED = true;
static constexpr bool DEFAULT_ATTR_INITUNSTRUCTURED = true;
static constexpr bool DEFAULT_ATTR_USENOH = false;
static constexpr bool DEFAULT_ATTR_USEUPLOAD = true;
static constexpr bool DEFAULT_ATTR_USERECORD = false;
static constexpr uint16_t DEFAULT_ATTR_RMHEARTBEATTIMEOUTMS = 5 * 1000;  // 5S

class ConfigCtrl::Impl {
public:
    Impl();
    ~Impl();

public:
    std::string mCfgPath;

    std::string mAttrAddrIpv4;
    uint16_t mAttrStPort;
    uint16_t mAttrUsPort;
    uint16_t mAttrRmPort;
    uint16_t mAttrStChannelNum;
    uint16_t mAttrUsChannelNum;
    uint16_t mAttrStFlushIntervalMs;
    uint16_t mAttrUsFlushIntervalMs;
    bool mAttrUseStructrued;
    bool mAttrUseUnstructrued;
    bool mAttrInitUnstructured;
    bool mAttrUseNoh;
    bool mAttrUseUpload;
    bool mAttrUseRecord;
    uint16_t mAttrRmHeartBeatTimeoutMs;
    std::string mIntegrationVersion;

public:
    void loopReadCameraArrange();
};

ConfigCtrl::Impl::Impl()
    : mAttrAddrIpv4(DEFAULT_ATTR_ADDRIPV4)
    , mAttrStPort(DEFAULT_ATTR_STPORT)
    , mAttrUsPort(DEFAULT_ATTR_USPORT)
    , mAttrRmPort(DEFAULT_ATTR_RMPORT)
    , mAttrStChannelNum(DEFAULT_ATTR_STCHANNELNUM)
    , mAttrUsChannelNum(DEFAULT_ATTR_USCHANNELNUM)
    , mAttrStFlushIntervalMs(DEFAULT_ATTR_STFLUSHINTERVALMS)
    , mAttrUsFlushIntervalMs(DEFAULT_ATTR_USFLUSHINTERVALMS)
    , mAttrUseStructrued(DEFAULT_ATTR_USESTRUCTRUED)
    , mAttrUseUnstructrued(DEFAULT_ATTR_USEUNSTRUCTRUED)
    , mAttrInitUnstructured(DEFAULT_ATTR_INITUNSTRUCTURED)
    , mAttrUseNoh(DEFAULT_ATTR_USENOH)
    , mAttrUseUpload(DEFAULT_ATTR_USEUPLOAD)
    , mAttrUseRecord(DEFAULT_ATTR_USERECORD)
    , mAttrRmHeartBeatTimeoutMs(DEFAULT_ATTR_RMHEARTBEATTIMEOUTMS)
    , mIntegrationVersion(std::string()) {}
ConfigCtrl::Impl::~Impl() {}

void ConfigCtrl::Impl::loopReadCameraArrange() {
    uint16_t cameraArrange = 2;
    hht::Variant cameraCount = hht::ConfigInfo::value(VEHCFGKEY_CAMERAARRANGE);
    while (hht::Variant::Int != cameraCount.type()) {
        sleep(1);
        LOG_EVERY_N(ERROR, 5) << "wait for VEHCFGKEY_CAMERAARRANGE.";
        cameraCount = hht::ConfigInfo::value(VEHCFGKEY_CAMERAARRANGE);
    };

    const int cameraCountInt = cameraCount.intValue();
    if(127 == cameraCountInt) {
        cameraArrange = 7;
        LOG(INFO) << "get camera_count success," << cameraCountInt;
    } else if(3 == cameraCountInt) {
        cameraArrange = 2;
        LOG(INFO) << "get camera_count," << cameraCountInt;
    } else {
        cameraArrange = 2;
        LOG(WARNING) << "get camera_count " << cameraCountInt << ",not suppot(use default 2).";
    }
    mAttrUsChannelNum = cameraArrange;
    LOG(ERROR) << "get VEHCFGKEY_CAMERAARRANGE successed," << mAttrUsChannelNum;
}

////////////////////////////////

ConfigCtrl::ConfigCtrl() : mImpl(new Impl()) {}
ConfigCtrl::~ConfigCtrl() { delete mImpl; }

bool ConfigCtrl::load(const std::string& cfgPath) {
    bool result = false;
    do {
        std::ifstream ifs;
        ifs.open(cfgPath);
        if (!ifs.is_open()) {
            LOG(ERROR) << "load: open cfg file failed, use default setting. path: " << cfgPath;
            // cfg has been inited in constructor
            break;
        }

        Json::Value root;
        bool ret = Json::Reader().parse(ifs, root);
        ifs.close();
        if (!ret) {
            LOG(ERROR) << "load: parse cfg file failed. path: " << cfgPath;
            break;
        }

        mImpl->mAttrAddrIpv4 = root.get(ADDR_IPV4, DEFAULT_ATTR_ADDRIPV4).asString();
        mImpl->mAttrStPort = root.get(ST_PORT, DEFAULT_ATTR_STPORT).asUInt();
        mImpl->mAttrUsPort = root.get(US_PORT, DEFAULT_ATTR_USPORT).asUInt();
        mImpl->mAttrRmPort = root.get(RM_PORT, DEFAULT_ATTR_RMPORT).asUInt();
        mImpl->mAttrStChannelNum = root.get(ST_CH_NUM, DEFAULT_ATTR_STCHANNELNUM).asUInt();
        mImpl->mAttrStFlushIntervalMs = root.get(ST_FLUSH_INTERVAL_MS, DEFAULT_ATTR_STFLUSHINTERVALMS).asUInt();
        mImpl->mAttrUsFlushIntervalMs = root.get(US_FLUSH_INTERVAL_MS, DEFAULT_ATTR_USFLUSHINTERVALMS).asUInt();
        mImpl->mAttrUseStructrued = root.get(USE_ST, DEFAULT_ATTR_USESTRUCTRUED).asBool();
        mImpl->mAttrUseUnstructrued = root.get(USE_US, DEFAULT_ATTR_USEUNSTRUCTRUED).asBool();
        mImpl->mAttrInitUnstructured = root.get(INIT_US, DEFAULT_ATTR_INITUNSTRUCTURED).asBool();
        mImpl->mAttrUseNoh = root.get(USE_NOH, DEFAULT_ATTR_USENOH).asBool();
        mImpl->mAttrUseUpload = root.get(USE_UPLOAD, DEFAULT_ATTR_USEUPLOAD).asBool();
        mImpl->mAttrUseRecord = root.get(USE_RECORD, DEFAULT_ATTR_USERECORD).asBool();
        mImpl->mAttrRmHeartBeatTimeoutMs = root.get(RM_HB_TIMEOUT_MS, DEFAULT_ATTR_RMHEARTBEATTIMEOUTMS).asUInt();
        result = true;
    } while (0);

    if(mImpl->mAttrUseUnstructrued) {
        mImpl->loopReadCameraArrange();
    }

    // TODO get IntegrationVersion from hhtconfig
    do {
        std::ifstream ifs;
        ifs.open(VER_JSON_PATH);
        if (!ifs.is_open()) {
            LOG(ERROR) << "Get Version Json Failed:" << VER_JSON_PATH;
            break;;
        }
        Json::Value root;
        bool ret = Json::Reader().parse(ifs, root);
        if (!ret) {
            LOG(ERROR) << "Parse Json Failed!";
            break;;
        }
        mImpl->mIntegrationVersion = root.get(VER_JSON_INTEGRATION, std::string()).asString();
        LOG(INFO) << "Get Integration Version: " << mImpl->mIntegrationVersion;
    } while (0);

    return result;
}

std::string ConfigCtrl::addrIpv4() const {
    return mImpl->mAttrAddrIpv4;
}

uint16_t ConfigCtrl::stPort() const {
    return mImpl->mAttrStPort;
}

uint16_t ConfigCtrl::usPort() const {
    return mImpl->mAttrUsPort;
}

uint16_t ConfigCtrl::rmPort() const {
    return mImpl->mAttrRmPort ;
}

uint16_t ConfigCtrl::stChannelNum() const {
    return mImpl->mAttrStChannelNum;
}

uint16_t ConfigCtrl::usChannelNum() const {
    return mImpl->mAttrUsChannelNum;
}

uint16_t ConfigCtrl::stFlushIntervalMs() const {
    return mImpl->mAttrStFlushIntervalMs;
}

uint16_t ConfigCtrl::usFlushIntervalMs() const {
    return mImpl->mAttrUsFlushIntervalMs;
}

bool ConfigCtrl::useStructrued() const {
    return mImpl->mAttrUseStructrued;
}

bool ConfigCtrl::useUnstructrued() const {
    return mImpl->mAttrUseUnstructrued;
}

bool ConfigCtrl::initUnstructured() const {
    return mImpl->mAttrInitUnstructured;
}

bool ConfigCtrl::useNoh() const {
    return mImpl->mAttrUseNoh;
}

bool ConfigCtrl::useUpload() const {
    return mImpl->mAttrUseUpload;
}

bool ConfigCtrl::useRecord() const {
    return mImpl->mAttrUseRecord;
}

uint16_t ConfigCtrl::rmHeartBeatTimeoutMs() const {
    return mImpl->mAttrRmHeartBeatTimeoutMs; // 5S
}

std::string ConfigCtrl::integrationVersion() const {
    return mImpl->mIntegrationVersion;
}

}  // namespace datamanager
}  // namespace hht
