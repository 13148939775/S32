/*
 * @author 008196
 * @for Can Data Provide
 * @version 0.1
 * @date 2023-05
 * 
 * @Copyrigh (c) HIPHI Co., LTD 2023
 * 
 */

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "DMDefine.h"
#include "ConfigCtrl.h"

namespace hht {
namespace datamanager {
class ConfigCtrl;
class DataManager {
public:
    DataManager();
    ~DataManager();

    void start();
    void stop();

    void onlineChanged(ModuleId id, bool isOnline);
    void onAcivated(ModuleId id, bool isActivated, ErrorCode ecode);
    void onSn(const std::string& sn);
    void onPowerSwitch(bool isDown);

    inline const ConfigCtrl& cfg() const { return mConfig; }

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl_;
    ConfigCtrl mConfig;
};  // DataManager
}  // namespace datamanager
}  // namespace hht
#endif	// DATAMANAGER_H
