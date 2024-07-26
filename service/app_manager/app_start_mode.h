/*
 * @file app_manager.h
 * @author 008196
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef START_MODE_H
#define START_MODE_H

#include <set>
#include <string>
#include <unordered_map>

enum class StartMode : uint8_t {
    Mode_OTA = 0,
    Mode_Calibration,
    Mode_Normal,
};

class ModeApp {
public:
    using appListType = std::unordered_map<uint8_t, std::set<std::string>>;
    static appListDescript& GetListUnderMode(const StartMode mode)
    {
        if (appList_.empty()) {
            // parse file 
            appList = FileManager::GetInstance()->Parse(mode);
        }
        return appList_;
    }

private:
    constexpr static appListType appList_ = {
        {SartMode::Mode_OTA, {"OTA", ""}},
        {StartMode::Mode_Calibration, {"Calibration", ""}},
        {StartMode::Mode_Normal, "PowerManager", "LogServer", "VehicleControl"}}
};

#endif /* START_MODE_H */
