/*
 * @author 008196
 * @for app manager service entry
 * @version 0.1
 * @date 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <thread>
#include <chrono>
#include <iostream>

#include "app_manager.h"
#include <node_log.h>
#include "app_manager_config.h"

inline void WaitForShutdown() {
  while (!false) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

// entry for start as an services
int main(int argc, char * argv[])
{
    HHT::NodeLog node("AppManagerLog");
    node.SetLevel(LOG_LEVEL_INFO, LOG_LEVEL_INFO, "./");
    HHT_LOG(INFO) << "entry app manager";
    if (argc != 2) {
        HHT_LOG(ERROR) << "exit app manager for lack para";
        return -1;
    }
    std::string cfg = HHT::AppManagerConfig::GetCfg(atoi(argv[1]));

    HHT_LOG(INFO) << "curr para:" << argv[1] << " curr cfg :" << cfg;
    HHT::AppManager::GetInstance().ParserConfig(cfg);
    HHT::AppManager::GetInstance().InitApps();
    HHT_LOG(INFO) << "Entry Start Apps";
    HHT::AppManager::GetInstance().StartApps();
    WaitForShutdown();

    return 0;
}