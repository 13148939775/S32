
/*
 * @author 008555
 * @for application log interface
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <fstream>
#include <string>

#include "TopicData_Center.h"
#include "Sim_TriggerEvent.h"
#include "TopicManage.h"
#include "serviceComm.h"

#include "node_log.h"

int main()
{
    HHT::NodeLog node("VCS_Log");

    node.SetLevel(LOG_LEVEL_WARNING,LOG_LEVEL_INFO,"./");

    std::string filename = "./topicExample.json";

    bool result = TopicManage::GetInstance().ReadTopicConfig(filename);

    if (result == false) {
        HHT_LOG(INFO)<<"TopicManage ReadTopicConfig Failed";
    }

    HHT_LOG(INFO)<<"ServiceComm ReadConfig";
 
    filename = "./dds_Config.json";
    ServiceComm::GetInstance().ReadConfig(filename);

    HHT_LOG(INFO)<<"ServiceComm Init";

    filename = "./s2s.json";
    ServiceComm::GetInstance().Init(filename);

    HHT_LOG(INFO)<<"ServiceComm ReceivePackage VCC";
    ServiceComm::GetInstance().CreateReceiveThread();


    HHT_LOG(INFO)<<"TopicManage CreateTopicThread";
    TopicManage::GetInstance().CreateTopicThread();


    HHT_LOG(INFO)<<"ServiceComm SendPackage Tickcount";
    ServiceComm::GetInstance().CreateSendTickThread();

    HHT_LOG(INFO)<<"IPCF Comm";
    ServiceComm::GetInstance().ReceiveIpcfPackage();
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}