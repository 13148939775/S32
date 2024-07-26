/*
 * @file app_manager.h
 * @author 008196
 * @for application start and exit manager
 * @version 0.1
 * @date 2023-02 ~ 2023-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include <set>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <algorithm>
#include <thread>

#include "app_status.h"
#include "hdbm_app.h"
#include "nlohmann/json.hpp"
#include <platform_health/health_watchdog.h>

namespace HHT {

class AppManager {
public:
    ~AppManager();

    static AppManager& GetInstance()
    {
        static AppManager am;
        return  am;
    }
    
    bool ParserConfig(const std::string& file);

    void InitApps()
    {
        std::vector<HDBMApp*> apps;
        HDBMRegister<HDBMApp*>::GetInstance().GetList(apps);
        for (const auto& app : apps) {
            // 1 create the app instance 
            auto ret = 
                std::find_if(appsStarted_.begin(), appsStarted_.end(), [&](HDBMApp* app2) {
                    return app == app2;
                });
            if (ret != appsStarted_.end()) {
                if (HDBMRegister<HDBMApp*>::GetInstance().IsValid(app))
                app->DoInit();
                app->SetStatus(AppStatus::Initialized);
            }
        }
    }

    void StartApps();

    void StopApps()
    {
        std::vector<HDBMApp*> apps;
        HDBMRegister<HDBMApp*>::GetInstance().GetList(apps);
        for (const auto& app : apps) {
            // 1 create the app instance 
            auto ret = 
                std::find_if(appsStarted_.begin(), appsStarted_.end(), [&](HDBMApp* app2) {
                    return app == app2;
                });
            if (ret != appsStarted_.end()) {
                if (HDBMRegister<HDBMApp*>::GetInstance().IsValid(app))
                app->DoStop();
            }
        }
    }
    
    std::string GetPid() { return "";}

    bool BuildAppList(const nlohmann::json& data);
    bool ValidJson(const nlohmann::json& data) { return true; }
    void EnvMonitor();

private:
    AppManager();
    AppManager(const AppManager& other) = delete;
    AppManager& operator=(const AppManager& other) = delete;
    std::vector<HDBMApp*> appsStarted_;
    std::vector<std::shared_ptr<HDBMApp>> appsSum_;  // just for init all the app from config
    struct Impl;
    std::unique_ptr<Impl> pImpl_;
    std::unordered_map<uint8_t, std::set<std::shared_ptr<HDBMApp>>> appG_;  // mode and app
    uint8_t curStartMode_{0};
    HealthWatchTask ht_;
};
}

#endif /* APP_MANAGER_H */
