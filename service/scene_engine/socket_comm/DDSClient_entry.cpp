
#include <thread>
#include "DDSservice.h"
#include "DDSServiceInterface.hpp"
#include "node_log.h"
#include "socketComm.h"

int main()
{
    HHT::NodeLog node("DDS_Client_Log");
    node.SetLevel(LOG_LEVEL_WARNING,LOG_LEVEL_INFO,"./");

    HHT_LOG(INFO)<<"Read S2S Config";
    std::string path = "./s2s.json";
    bool res = SocketDDSComm::GetInstance().InitConfig(path);
    if (res == false) {
        HHT_LOG(WARNING)<<"Read S2S Config Failed";
    }

    HHT_LOG(INFO)<<"Read DDS Config";
    path = "./dds_Config.json";
    res = SocketDDSComm::GetInstance().Init(path);
    if (res == false) {
        HHT_LOG(WARNING)<<"Read DDS Config Failed";
    }

    HHT_LOG(INFO)<<"SocketDDSComm CreateReceiveThread";
    SocketDDSComm::GetInstance().CreateReceiveThread();

    HHT_LOG(INFO)<<"SocketDDSComm CreateSendThread";
    //SocketDDSComm::GetInstance().CreateSendThread();

    HHT_LOG(INFO)<<"SocketDDSComm  CreateSendRsponseThread";
    SocketDDSComm::GetInstance().CreateSendRsponseThread();

    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}

