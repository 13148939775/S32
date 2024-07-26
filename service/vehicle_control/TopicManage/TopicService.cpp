
#include "TopicService.h"

#include <vector>
#include <algorithm>
#include <iostream>

#include "node_log.h"
#include "TopicManage.h"
#include "TopicData_Center.h"

#include "DDSservice.h"
#include "DDSServiceInterface.hpp"
#include "DDSReplierManage.h"

using  dataInitMap = std::unordered_map<std::string, std::vector<uint>>;
std::vector<uint8_t> TopicService::generalVehSt_{0};

std::unordered_map<std::string, std::vector<uint>> TopicDataImpMap_ = {
    {"HDBM_GeneralVehSt",       {0,1}}
};

std::unordered_map<std::string, int> categorySizeTable_ = {
        {"HDBI_Win_Set",        1},
        {"HDBI_Win_Rsp",        1},
        {"HDBI_WinPct_Act",     1},
        {"HDBI_Win_St",         3}
    };

enum SendStrategy : uint8_t
{
    sendStrategy_Event = 0,
    sendStrategy_Timer = 1,
    sendStrategy_Common= 2,
};

enum TopicDataPos : uint8_t
{
    HDBM_PowerModeRsp_Pos0 = 0,
    HDBM_PowerModeRsp_Pos1 = 1,

    HDBM_GeneralVehSt_Pos4 = 4,
};

TopicService::TopicService(const std::string& Name, const std::string& qname, const uint8_t& sendType, const bool trigger)
    : topicName_(Name),
    reqName_(qname),
    sendStrategy_(sendType),
    trigger_(trigger)
{

}

void TopicService::CreateDDSThread()
{
    DDSReplierManage& dds_reply = DDSReplierManage::GetInstance();
    std::thread th_([&dds_reply]() {
        dds_reply.CreateLoopRequest();
    });
    th_.detach();
}

void TopicService::ConstructTopicInfo(const nlohmann::json& data, const uint32_t index)
{
    // std::string name = "";
    // uint32_t topicType = 0;
    // uint32_t topicState = 0;
    // uint32_t topicValue = 0;
    // int value = 0;
    // int topicCnt = data["topics"][index]["category"].size();
    // for (int j = 0; j < topicCnt; ++j) { 
    // } 
}

void TopicService::RegistryStatusCondition(std::string&  tname)
{
    TopticDataCenter::GetInstance().AttachObserver(tname, this); 
}

// void TopicService::RemoveStatusCondition(std::string&  tname)
// {
//     //TopticDataCenter::GetInstance().RemoveObserver(tname, this); 
// }

// void TopicService::Transmission(std::string& topicname)//透传
// {
//     //HHT_LOG_INFO("topics : %c tramission", topicname.c_str());
//     std::shared_ptr<TopicDataBlock> dataPtr = TopticDataCenter::GetInstance().getData(topicname);
//     std::vector<uint8_t> topicData = dataPtr->GetTopcData();
//     if(this->GetSendStrategy() == sendStrategy_Common)
//         generalVehSt_ = dataPtr->GetTopcData();
//     for_each(topicData.begin(), topicData.end(), [&](const uint8_t value){
//         printf("curr topic  is %s,value is %d\n\t", topicname.c_str(), value);
//     });
        
// }

// void TopicService::DealConflict(std::string& topicname)//冲突判断
// {
//     //HHT_LOG_INFO("topics : %c conflict", topicname.c_str());
//     std::shared_ptr<TopicDataBlock> dataPtr = TopticDataCenter::GetInstance().getData(topicname);
//     std::vector<uint8_t> topicDealData = JudgeTopicState(topicname, dataPtr->GetTopcData());
//     for_each(topicDealData.begin(), topicDealData.end(), [&](const uint8_t value) {
//         printf("curr topic  is %s,value is %d\n\t", topicname.c_str(), value);
//     });
// }

// std::vector<uint8_t> TopicService::JudgeTopicState(const std::string& topicname, std::vector<uint8_t> topicVec)
// {
//     uint8_t tvalue;
//     std::vector<uint8_t> tmpValue(topicVec);
//     if (topicname == "HDBM_PowerModeRsp") {
//         if (tmpValue[HDBM_PowerModeRsp_Pos0] == 0x80) { //PowerModeOffReq
//             tvalue = tmpValue[HDBM_PowerModeRsp_Pos1] & 0xf0;
//             if(generalVehSt_[HDBM_GeneralVehSt_Pos4] != 0x00)//Gear not P
//                 tvalue = 0x01;
            
//             tmpValue[HDBM_PowerModeRsp_Pos1] = (tmpValue[HDBM_PowerModeRsp_Pos1]|0xf0) & (tvalue<<4);
//         } else if(tmpValue[HDBM_PowerModeRsp_Pos0] = 0x40) { //PowerModeOnReq
            
//         }
//     }
//     return tmpValue;
// }

// void TopicService::ManageConflict(std::string& topicname)
// {
//     if (TopicManage::GetInstance().GetTopicTriggerState(topicname) == true){
//         DealConflict(topicname);
//     } else {
//         Transmission(topicname);
//     }
// }


void TopicService::OnNotify(TopticDataCenter& siginfo)
 {
//     //ManageConflict(this->GetTopicName());
}

