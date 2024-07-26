 #include "DDSRequestManage.h"
#include <fstream>
#include <ctime>
#include <iostream>
#include <sstream>

#include "node_log.h"

#define MAX_WAIT_TIME 1

const int PAD_DATA_BUFF_MAX = 256;

enum PADDataDef : uint16_t
{
    PADDataHead_Byte0 = 0,
    PADDataHead_Byte1 = 1,
    PADDataHead_Byte2 = 2,
    PADDataHead_Byte3 = 3,

    PADDataLen_Byte4 = 4,
    PADDataLen_Byte5 = 5,

    PADDataCommand_Byte6 = 6,
    PADDataCommand_Byte7 = 7,

    PADDataContext_Byte8 = 8,
    PADDataContext_Byte9 = 9,
    PADDataContext_Data10 = 10,
    PADDataContext_Data11 = 11,
    PADDataContext_Data12 = 12,
    PADDataContext_Data13 = 13
};


bool DDSRequestManage::ReadS2SConfig(std::string file)
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

bool DDSRequestManage::BuildMap(const nlohmann::json& data)
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


        std::shared_ptr<S2SData> s2sptr = 
        std::make_shared<S2SData>(hname, vname, dqname, dpname,ddsType,ddsValue, sid, bid, pos);
        s2sDataVec_.push_back(s2sptr);
        s2sDataMap_[std::make_pair(bid, sid)] = s2sptr;
        if (save_qname != dqname && save_pname != dpname) {
            CreateDDSRequest(dqname, dpname);
            save_qname = dqname;
            save_pname = dpname;

            HHT_LOG(INFO)<<"dds Client -->"<<save_qname<<"; dds Server-->"<<save_pname;
        }

    }
    return true;
}

bool DDSRequestManage::RevertValue(char* data, size_t len)
{
    if(data[PADDataContext_Byte8] == 50 && data[PADDataContext_Byte9] == 0) {
        if(data[PADDataContext_Data10] == 1) {
            data[PADDataContext_Data10] = 2;
        } else if(data[PADDataContext_Data10] == 2) {
            data[PADDataContext_Data10] = 1;
        }
    }

    if(data[PADDataContext_Byte8] == 15 && data[PADDataContext_Byte9] == 0) {
        if(data[PADDataContext_Data10] == 1) {
            data[PADDataContext_Data10] = 2;
        } else if(data[PADDataContext_Data10] == 2) {
            data[PADDataContext_Data10] = 1;
        }
    }
    return true;
}

bool DDSRequestManage::GetDataState(char* data, size_t len)
{
    size_t size = s2sDataVec_.size();
    std::string rquestname;
    DDSCommandSet_struct ddsCommand;
    std::array<char , 256UL> dataBuffer;

    RevertValue(data, len);

    for (size_t i =0; i < len; ++i) {
        dataBuffer[i] = data[i]; 
    }

    if (data[PADDataCommand_Byte6] != 0x12 && data[PADDataCommand_Byte6] != 0x10) {
        HHT_LOG(INFO)<<"IPAD COMMAND CODE ERROR";
        return false;
    }

    if (s2sDataMap_.find(std::make_pair(data[PADDataContext_Byte8], data[PADDataContext_Byte9])) != s2sDataMap_.end()) {
            std::shared_ptr<S2SData> s2sptr = s2sDataMap_[std::make_pair(data[PADDataContext_Byte8], data[PADDataContext_Byte9])];
            
            ddsCommand.code(data[PADDataContext_Byte8]);

            ddsCommand.subcode(data[PADDataContext_Byte9]);

            ddsCommand.commBuffer(dataBuffer);

            requesterVec_[requestDDSmap_[s2sptr->GetDDSReqName()]]->SendRequests(ddsCommand);

            //PrintDDSLog(s2sDataMap_[std::make_pair(data[PADDataContext_Byte8], data[PADDataContext_Byte9])]);

            PrintHMILog(s2sDataMap_[std::make_pair(data[PADDataContext_Byte8], data[PADDataContext_Byte9])], data, len);

            ReceiveDDSReply(requesterVec_[requestDDSmap_[s2sptr->GetDDSReqName()]]);

            return true;
    }
    return false;
}

void DDSRequestManage::CreateDDSRequest(std::string& request, std::string& reply)
{
    //add requestInfo  
    size_t seq = requesterVec_.size();
    requestDDSmap_[request] = seq;
    //create request
    DDSRequesterPtr req = std::make_shared<DDSrequester<DDSCommandSet_struct, DDSCommandRsp_struct>>();
    req->InitRequester(request, reply), 
    req->CreateRequester();
    req->SetMaxWaitTime(MAX_WAIT_TIME);

    requesterVec_.push_back(req);
}


void DDSRequestManage::ReceiveDDSReply(DDSRequesterPtr requester)
{
    char dataBuf[PAD_DATA_BUFF_MAX];
    size_t len;
    auto receive_data = requester->ReceiveReplies();
    if (receive_data.length() > 0) {
        for (auto &reply : receive_data)
        {
           std::array<char, 256UL> data = reply.data().commBuffer();
            len = data[PADDataLen_Byte4] + 8;
           if (data[PADDataHead_Byte0] != 0x68 || data[PADDataHead_Byte1] != 0x68 || data[PADDataHead_Byte3] != 0x00) {
                    HHT_LOG(INFO)<<"DDSRequestManage ReceiveDDSReply no data";
                    continue;
            }
            for (size_t i = 0; i < len; ++i) {
                    dataBuf[i] = data[i];
            }
            printf("\n");
            HHT_LOG(INFO)<<"DDSClient Send to IPAD"<<remote_iP_ <<", port:"<<remote_port_;
            socketPtr_->SendPackage(dataBuf, len, remote_iP_.c_str(), remote_port_);
        }
    }
    HHT_LOG(INFO)<<"DDSRequestManage ReceiveDDSReply";
}

void DDSRequestManage::PrintHMILog(std::shared_ptr<S2SData> ddsData, const char* buffer, size_t& len)
{
    std::string value = "";
    for(size_t i=0; i < len; ++i) {
        value += (" " + std::to_string((unsigned char)buffer[i]));
    }
    HHT_LOG(WARNING)<<"[VCC Client] -> [DDS Client] "<<ddsData->GetHMIName()<<": "<<value;
}

