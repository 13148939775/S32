
#include "meta_ability.h"

#include "node_log.h"
#include "DDSservice.h"
#include "ddsrequestmanage.h"
#include "vehicle_door.hpp"

std::unordered_map<std::string, std::string> MetaAbility::function2Topic_;

MetaAbility::MetaAbility(const std::string& functionCode, std::string& value, const uint8_t& count, const uint8_t& compose = 0)
    : functionCode_(functionCode),functionValue_(value),cycleCount_(count), compose_(compose)
{
    HHT_LOG(INFO)<<"MetaAbility "<<functionCode_<<",  topic "<<function2Topic_[functionCode_];
    DDSRequestManage::GetInstance().CreateDDSRequest(function2Topic_[functionCode_]);
    DDSRequestManage::GetInstance().InitDDSRequest(function2Topic_[functionCode_]);
}

void MetaAbility::OnNotify(const DataBlockCenter& dbc)
{
    HHT_LOG(INFO)<<"MetaAbility "<<functionCode_<<",  topic "<<function2Topic_[functionCode_];
    DDSRequestManage::GetInstance().SendDDSRequest(function2Topic_[functionCode_]);
    DDSRequestManage::GetInstance().ReceiveDDSReply(function2Topic_[functionCode_]);
}

void MetaAbility::Enable()
{

}

void MetaAbility::RegistryTime(int time, const std::function<void()>& cb)
{
    // time cb
}

void MetaAbility::ReadMeta2Topic(const nlohmann::json& data)
{
    std::string meta;
    std::string topic;
    HHT_LOG(INFO)<<"Init Meta to Topic";
    uint16_t size = data["Meta2Topic"].size();
    for (uint16_t i=0; i < size; ++i) {
        meta = data["Meta2Topic"][i]["MetaAbility"];
        topic = data["Meta2Topic"][i]["Topic"];
        function2Topic_[meta] = topic;
    }
}