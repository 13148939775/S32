#include "DDSReplierListener.h"
#include "serviceComm.h"
#include <mutex>

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

void ReplierListenerDDS::on_request_available(rti::request::Replier<DDSCommandSet_struct, DDSCommandRsp_struct> &replier)
{
    // TODO处理函数
    auto requests = replier.take_requests();
    if (0 < requests.length())
    {
        for (auto &request : requests)
        {
            if (!request.info().valid())
                continue;

            HHT_LOG(INFO) << "DDS replier-->ReplierListener";

            std::array<char, 256UL> data = request.data().commBuffer();

            ddsCommandRsp_.code(request.data().code());

            ddsCommandRsp_.subcode(request.data().subcode());

            if (DataJudge(data) == false) {

                SendDataToIPCF(data);

                // if(data[PADDataCommand_Byte6] == 0x12 && data[PADDataCommand_Byte7] == 0x00) {  // getonce 
                //     revLen_ = DATABUFFER_MAX;
                //     memset(vccData_,0,  DATABUFFER_MAX);
                //     ServiceComm::GetInstance().ReceivePackage();
                //     RecvDataFromIPCF();
                // }

                replier.send_reply(ddsCommandRsp_, request.info());

            } else {

                if (data[PADDataContext_Byte8] == 29 && data[PADDataContext_Byte9] == 0) {

                    if(data[PADDataContext_Data10] ==  0x00) { //power off
                        GeneralVehSt_Struct  generalVehSt = ServiceComm::GetInstance().GetGeneralVehSt();
                        if(generalVehSt.ActlGear_St != 0x00) {//not p
                            return_DataBuf_[0] = 0x68;
                            return_DataBuf_[1] = 0x68;
                            return_DataBuf_[2] = 0x99;
                            return_DataBuf_[3] = 0x00;
                            return_DataBuf_[4] = 0x05;
                            return_DataBuf_[5] = 0x00;
                            return_DataBuf_[6] = 0x13;
                            return_DataBuf_[7] = 0x00;
                            return_DataBuf_[8] = 0x1E;
                            return_DataBuf_[9] = 0x01;
                            return_DataBuf_[10] = 0x01;
                            return_DataBuf_[11] = 0x00;
                            return_DataBuf_[12] = 0x00;
                            ddsCommandRsp_.commBuffer(return_DataBuf_);
                            
                        } else {
                            SendDataToIPCF(data);
                        }
                    } else {
                        SendDataToIPCF(data);
                    }
                }
                replier.send_reply(ddsCommandRsp_, request.info());
            } 
        }
    }
}

bool ReplierListenerDDS::DataJudge(std::array<char, 256UL>& data)
{
    if (data[PADDataContext_Byte8] == 29 && data[PADDataContext_Byte9] == 0) {
        return true;
    } else {
        return false;
    }
}

#define DATA_BUFFER  256

void ReplierListenerDDS::SendDataToIPCF(std::array<char, 256UL> cmdData)
{
    size_t size;
    if(cmdData[PADDataLen_Byte4]  != 0x00) {
        size = cmdData[PADDataLen_Byte4] + 8;
    }
    ServiceComm::GetInstance().SendPackage(cmdData.data(), size); 
}

bool ReplierListenerDDS::RecvDataFromIPCF() 
{ 
    HHT_LOG(INFO)<<"ReplierListenerDDS get data:";
    for (size_t i=0; i < revLen_; ++i) {
        dataBuf[i] = vccData_[i];
    }

    HHT_LOG(INFO)<<"ReplierListenerDDS get data end";
    ddsCommandRsp_.commBuffer(dataBuf);
    return true;
}