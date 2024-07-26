#ifndef CONFIGCTRL_H
#define CONFIGCTRL_H

#include "DMDefine.h"

namespace hht {
namespace datamanager {
class ConfigCtrl {
public:
    ConfigCtrl();
    ~ConfigCtrl();
    bool load(const std::string& cfgPath);

    std::string addrIpv4() const;
    uint16_t stPort() const;         // Begin port for structrued data
    uint16_t usPort() const;         // Begin port for unstructrued data
    uint16_t rmPort() const;         // Port for Recorder Monitor
    uint16_t stChannelNum() const;   // Channel number for structrued data
    uint16_t usChannelNum() const;   // Channel number for unstructrued data
    uint16_t stFlushIntervalMs() const;
    uint16_t usFlushIntervalMs() const;
    bool useStructrued() const;
    bool useUnstructrued() const;
    bool initUnstructured() const;
    bool useNoh() const;
    bool useUpload() const;
    bool useRecord() const;
    uint16_t rmHeartBeatTimeoutMs() const; // The timeout of heart beat of Recorder Monitor
    std::string integrationVersion() const;

private:
    class Impl;
    Impl* mImpl;
};  // ConfigCtrl
}  // namespace datamanager
}  // namespace hht
#endif	// CONFIGCTRL_H
