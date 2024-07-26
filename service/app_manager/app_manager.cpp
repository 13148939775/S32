/*
 * @author 008196
 * @for application start and exit manager
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "app_manager.h"

#include <fstream>
#include "linux/process.h"
#include <node_log.h>
#include <platform_health/watchdog.h>

namespace HHT {

struct AppManager::Impl {
    bool StartAppsImpl(AppManager* owner, std::vector<HDBMApp*>& apps, bool isService)
    {
        std::vector<HDBMApp*>& appsStarted = owner->appsStarted_;
        HDBMRegister<HDBMApp*>::GetInstance().GetList(apps, isService);  // first is service
        HHT_LOG(INFO) << "Entry Start App cnt:" << apps.size();
        for (const auto& app : apps) {
            // 1 create the app instance 
            auto ret = 
                std::find_if(appsStarted.begin(), appsStarted.end(), [&](HDBMApp* app2) {
                    return app->GetName() == app2->GetName();
                });
            if (ret != appsStarted.end()) {
                HHT_LOG(INFO) << "app already started:" << app->GetName();
                continue;
            }
            // modify to CreateProcess instead of DoStart()
            HHT_LOG(INFO) << "app ready to create";
	    // 获取开始时间
            auto startTime = std::chrono::high_resolution_clock::now();
            OSAbstraction::ProcessId pid = OSAbstraction::OsProcess::CreateProcess(app->GetPath());
            if ((pid == -1) || (pid == 0)) {
                HHT_LOG(INFO) << "app start failed:" << app->GetName();
            } else {
		// 获取结束时间
                auto endTime = std::chrono::high_resolution_clock::now();
                // 计算时间差
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
                HHT_LOG(INFO) << "app: [" << app->GetName() << "] actually bootTime is " << duration.count() << "ms";
                if (duration.count() > app->GetBootTimeLimit()) {
                    HHT_LOG(WARNING) << "app: [" << app->GetName() << "] actually bootTime is exceeded limit time!" << "actually bootTime is" << duration.count() << "ms " << "limit bootTime is " << app->GetBootTimeLimit() << "ms";
                }

                app->DoInit();
                app->SetStatus(AppStatus::Initialized);
                app->DoStart();
                app->SetStatus(AppStatus::Started);
                app->SetPid(pid);
                appsStarted.push_back(app);
                HHT_LOG(INFO) << "app start sucessed:" << app->GetName() << "/pid:" << app->GetPid() << " total:" <<appsStarted.size();
            }
        }
        return true;
    }
};

void AppManager::StartApps()
{
    std::vector<HDBMApp*> apps;
    HHT_LOG(INFO) << "Entry Start Apps services";
    pImpl_->StartAppsImpl(this, apps, true);  // first is service
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    HHT_LOG(INFO) << "Entry Start Applications";
    pImpl_->StartAppsImpl(this, apps, false);
}

constexpr uint8_t initedHealthWdtTimeout = 10;
AppManager::AppManager()
      : pImpl_(new Impl()),
        ht_(initedHealthWdtTimeout) 
{ };

AppManager::~AppManager()
{ };

bool AppManager::ParserConfig(const std::string& file)
{
    std::ifstream inf(file);
    if (inf.good() == false) {
        HHT_LOG(ERROR) << "file is not ready" << file;
        return false;
    }
    //解析
    nlohmann::json data = nlohmann::json::parse(inf);  // file may not exist, add later

    try {
        //序列化
        std::string s = data.dump();
        HHT_LOG(INFO) << "json is:" << s;
    } catch (const std::exception &e) {
        inf.close();
        return false;
    }

    BuildAppList(data);
    
    inf.close();
    return true;
}

bool AppManager::BuildAppList(const nlohmann::json& data)
{
    if (!ValidJson(data)) {
        HHT_LOG(ERROR) << "wrong app manager version";
        return false;
    }
    int appCnt = data["tracks"].size();
    HHT_LOG(INFO) << "App Cnt:" << appCnt;
    for (int i = 0; i < appCnt; ++i) {
        std::string name = data["tracks"][i]["name"];
        std::string path = data["tracks"][i]["path"];
	int bootTimeLimit  = data["tracks"][i]["bootTimeLimit"];
	std::shared_ptr<HDBMApp> appPtr = std::make_shared<HDBMApp>(name,path,false,bootTimeLimit);
        appsSum_.emplace_back(std::move(appPtr));
    }
}

void EnvMonitor()
{ }
}
