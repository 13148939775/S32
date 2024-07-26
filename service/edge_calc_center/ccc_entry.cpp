/*
 * @author 008196
 * @for app manager service entry
 * @version 0.1
 * @date 2023-05
 * @copyright Copyright (c) 2023
 */

#include <thread>
#include <chrono>
#include <iostream>

#include <node_log.h>
#include "ccc_instance.h"
#include "signal_receive/signal_ipcf/signal_ipcfrecv.h"
#include "signal_receive/signal_someip/signal_subscriber.h"
#include "signal_receive/signal_pfe/signal_pferecv.h"
#include "data_storage/recorder_mode/signal_store_ctrl.h"
#include "sqlite_operator.h"


inline void WaitForShutdown()
{
    while (!false) {
        HHT_LOG(INFO) << "CCC is alive";
        std::this_thread::sleep_for(std::chrono::seconds(15));
    }
}

// entry for start as an services
int main(int argc, char * argv[])
{
    HHT::SqliteOperatorModel::Init(":memory:");
    HHT::NodeLog node("CCCLog");
    node.InitLog(LOG_LEVEL_INFO, LOG_LEVEL_INFO);
    HHT_LOG(INFO) << "entry CCC";
    HHT::CCC ccc("centralCompute");
    HHT_LOG(INFO) << "entry IPCF";
    HHT::DataManager::SignalIpcfRecv::GetInstance().Init();
    HHT::DataManager::SignalIpcfRecv::GetInstance().ReceiveIPCFData();
    HHT_LOG(INFO) << "entry SOMEIP"; 
    HHT::DataManager::SignalSubscriber::GetInstance().StartThread();
    HHT_LOG(INFO) << "entry PFE"; 
    HHT::DataManager::SignalPfeRecv::GetInstance().Init();
    HHT::DataManager::SignalPfeRecv::GetInstance().ReceivePfeData();
    WaitForShutdown();

    return 0;
}
