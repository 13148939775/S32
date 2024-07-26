#include "DDSReplierManage.h"
#include <fstream>
#include "node_log.h"

#define REPLY_MAX_WAIT_TIME 1

bool DDSReplierManage::ReadS2SConfig(std::string file)
{
    HHT_LOG(INFO)<<"read json and Build tree";
    std::ifstream inf(file);
    //解析
    nlohmann::json data = nlohmann::json::parse(inf);
        //序列化
    std::string s = data.dump();

    //HHT_LOG(INFO)<< "json is:" << s << std::endl;

    return BuildMap(data);
}

bool DDSReplierManage::BuildMap(const nlohmann::json& data)
{
    std::string hname;
    std::string vname;
    std::string dqname;
    std::string dpname;
    std::string ddsType;
    std::string ddsValue;
    std::string save_qname = "";
    std::string save_pname = "";

    uint8_t pos;
    uint8_t sid;
    uint8_t bid;
    size_t size = data["S2S"].size();
    for (size_t i= 0; i < size; ++i) {
        hname = data["S2S"][i]["hmiName"];
        vname = data["S2S"][i]["vccName"];
        dqname = data["S2S"][i]["ddsReqName"];
        dpname = data["S2S"][i]["ddsRepName"];
        ddsType = data["S2S"][i]["ddsType"];
        ddsValue = data["S2S"][i]["ddsValue"];
        sid = data["S2S"][i]["smallID"];
        bid = data["S2S"][i]["bigID"];
        pos = data["S2S"][i]["pos"];

        std::shared_ptr<S2SData> s2sptr = std::make_shared<S2SData>(hname, vname, dqname, dpname,ddsType,ddsValue, sid, bid, pos);

        s2sDataMap_[std::make_pair(bid, sid)] = s2sptr;

        if (save_qname != dqname && save_pname != dpname) {
            CreateDDSReply(dqname, dpname);
            save_qname = dqname;
            save_pname = dpname;

            HHT_LOG(INFO)<<"dds Client -->"<<save_qname<<"; dds Server-->"<<save_pname;
        }
    }

    return true;
}

std::string DDSReplierManage::GetReplyName(char big, char small)
{
    std::string reply = "";
    if(s2sDataMap_.find(std::make_pair(big, small)) != s2sDataMap_.end()) {

        reply =  s2sDataMap_[std::make_pair(big, small)]->GetDDSRepName();
    }

    return reply;
}

bool DDSReplierManage::CreateDDSReply(std::string& reqtopic, std::string& reptopic)
{
    DDSReplyPtr replier = std::make_shared<DDSreplier<DDSCommandSet_struct, DDSCommandRsp_struct>>();
    replier->InitReplier(reqtopic, reptopic);
    replier_Listener_DDS_ = std::make_shared<ReplierListenerDDS>();
    replier->CreateReplier(replier_Listener_DDS_);
    replier->SetMaxWaitTime(REPLY_MAX_WAIT_TIME);

    replyVec_.push_back(replier);

    return true;
}

bool DDSReplierManage::CreateLoopRequest()
{
    while (true)
    {
        for (auto& it : replyVec_) {
            it->ReceiveRequests();
        }
    }
}