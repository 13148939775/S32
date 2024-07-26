/*
 * @author 008555
 * @for dds_reply listerner
 * @version 1.0
 * @date 2023-06 ~ 2023-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DDS_REPLIER_LISTENER_H
#define DDS_REPLIER_LISTENER_H

#include "DDSservice.h"
#include "DDSServiceInterface.hpp"
#include "node_log.h"

using namespace DDSservice;

#define DATABUFFER_MAX 256

enum VCCDataDef : uint16_t
{
    VCCDataHead_Byte0 = 0,
    VCCDataHead_Byte1 = 1,
    VCCDataHead_Byte2 = 2,
    VCCDataHead_Byte3 = 3,

    VCCDataLen_Byte4 = 4,
    VCCDataLen_Byte5 = 5,

    VCCDataCommand_Byte6 = 6,
    VCCDataCommand_Byte7 = 7,

    VCCDataContext_Byte8 = 8,
    VCCDataContext_Byte9 = 9,
    VCCDataContext_Data10 = 10,
    VCCDataContext_Data11 = 11,
    VCCDataContext_Data12 = 12
};

class ReplierListenerDDS : public rti::request::ReplierListener<DDSCommandSet_struct, DDSCommandRsp_struct>
{
public:
    virtual void on_request_available(rti::request::Replier<DDSCommandSet_struct, DDSCommandRsp_struct> &replier);

private:
    void SendDataToIPCF(std::array<char, 256UL> cmdData);

    bool RecvDataFromIPCF();

    void printSendData(char *data, size_t& len);

    bool DataJudge(std::array<char, 256UL>& data);

private:
    std::array<char, 256UL> dataBuf;
    std::array<char, 256UL> return_DataBuf_;
    char vccData_[DATABUFFER_MAX];
    size_t revLen_;
    size_t len_;
    std::string vccname;
    DDSCommandRsp_struct ddsCommandRsp_;
};


#endif