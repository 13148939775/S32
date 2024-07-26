#include "socketComm.h"

#include <ctime>
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
#include "node_log.h"
#include "DDSservice.h"
#include "DDSRequestManage.h"
#include "DDSServiceInterface.hpp"

using namespace DDSservice;

enum DataDef : uint16_t
{
    DataHead_Byte0 = 0,
    DataHead_Byte1 = 1,
    DataHead_Byte2 = 2,
    DataHead_Byte3 = 3,
    DataLen_Byte4 = 4,
    DataCommand_Byte6 = 6,
    DataContext_Byte8 = 8,
    DataContext_Byte9 = 9,
    DataContext_Data10 = 10
};


SocketDDSComm::SocketDDSComm()
:breceiveSign(false)
{
}
SocketDDSComm::~SocketDDSComm()
{
}

bool SocketDDSComm::ReadConfig(std::string& file)
{
    HHT_LOG(INFO)<<"read json and Build tree";
    std::ifstream inf(file);
    //解析
    nlohmann::json data = nlohmann::json::parse(inf);
        //序列化
    std::string s = data.dump();

   return BuildMap(data);
}

bool SocketDDSComm::BuildMap(const nlohmann::json& data)
{
    std::string dds_DefDate;
    std::string dds_Version;

    std::string dds_Address;
    std::string vcc_Address;
    unsigned int clientRecv_Port;
    unsigned int clientRecv2_Port;
    unsigned int clientSend_Port;

    unsigned int serverRecv_Port;
    unsigned int serverSend_Port;
    unsigned int serverSend_Port2;
    unsigned int serverIpcf_Port;

    dds_DefDate = data["DDS_DefDate"];
    dds_Version = data["DDS_Version"];
    dds_Address = data["DDS_IPConfig"]["DDS_Address"];
    vcc_Address = data["DDS_IPConfig"]["VCC_Address"];
    clientRecv_Port = data["DDS_IPConfig"]["DDSClientRecv_Port"];
    clientRecv2_Port = data["DDS_IPConfig"]["DDSClientRecv2_Port"];
    clientSend_Port = data["DDS_IPConfig"]["DDSClientSend_Port"];

    serverRecv_Port = data["DDS_IPConfig"]["DDSServerRecv_Port"];
    serverSend_Port = data["DDS_IPConfig"]["DDSServerSend_Port"];
    serverSend_Port2 = data["DDS_IPConfig"]["DDSServerSend2_Port"];
    serverIpcf_Port = data["DDS_IPConfig"]["DDSServerToIPCF_Port"];

    ddsConfig_ = std::make_shared<DDSConfig>(dds_DefDate,           dds_Version, 
                                             dds_Address,            vcc_Address,            
                                             clientRecv_Port,
                                             clientRecv2_Port,       clientSend_Port,  
                                             serverRecv_Port,        serverSend_Port, 
                                             serverSend_Port2,       serverIpcf_Port);

    return true;
}

bool SocketDDSComm::Init(std::string& file)
{
    HHT_LOG(INFO)<<"read DDS config";
    ReadConfig(file);
    HHT_LOG(INFO)<<"DDSClient udp Init";
    dataLen_ = BUFFER_MAX;
    unsigned short port = ddsConfig_->GetClientRecvPort();
    udpServerPtr_ = std::make_shared<SocketUDPServer>();
    udpServerPtr_->Init(port);
    udpServerPtr_->Bind();

    port = ddsConfig_->GetClientRecvPort2();
    udpDDSServerPtr_ = std::make_shared<SocketUDPServer>();
    udpDDSServerPtr_->Init(port);
    udpDDSServerPtr_->Bind();

    DDSRequestManage::GetInstance().GetUdpServer(udpServerPtr_);

   return true;
}

bool SocketDDSComm::InitConfig(std::string& file)
{
    return DDSRequestManage::GetInstance().ReadS2SConfig(file);
}

void  SocketDDSComm::SendPackage(uint32_t seconds)
{
    while (true){
        if (breceiveSign == false){
            continue;
        }
        SendDataPackage();
        std::this_thread::sleep_for(std::chrono::milliseconds(seconds));
    }
}

bool SocketDDSComm::SendDataPackage()
{
    size_t len;
    char data[14] = {0x68, 0x68, 0x68, 0x00, 0x04, 0x00,0x00, 0x00};
    uint32_t *pInt = (uint32_t *)&data[8];
    len = 14;
    const char *ip = (ddsConfig_->GetDDSAddress()).c_str();
    time_t currentTime = time(nullptr);
    tm *localTime = localtime(&currentTime);
    pInt[0] = localTime->tm_hour * 3600 + localTime->tm_min * 60 + localTime->tm_sec;
    udpServerPtr_->SendPackage(data, len, ip, ddsConfig_->GetClientSendPort());       
    return true;
}

void SocketDDSComm::ReceivePackage(uint32_t seconds)
{
    while (true) {
        ReceiveDataPackage();
    }
}

bool SocketDDSComm::ReceiveDataPackage()
{
    memset(dataBuffer_, 0, BUFFER_MAX); 

    dataLen_ = BUFFER_MAX;

    udpServerPtr_->ReceivePackage(dataBuffer_, dataLen_);

    breceiveSign = true;

    VccToDDS(dataBuffer_);
    
    return true;
}

bool SocketDDSComm::printRecvData(char *data, size_t& len)
{
    for (size_t i=0; i < len; ++i) {
        printf("%02X ", (unsigned char)data[i]);
    }
    printf("\n");
    HHT_LOG(WARNING)<<"VCC Client -> DDS Client"<<"";
    return true;
}

bool SocketDDSComm::VccToDDS(const char *data)
{
    short *datalen = (short *)&data[DataLen_Byte4];
    short len = datalen[0];
    if (len < 1){
        return false;
    }
    if(data[DataCommand_Byte6] == 0x10 || data[DataCommand_Byte6] == 0x12) {
        char *functonDat = (char *)&data[DataContext_Byte8];
        DataDeal(functonDat[0], functonDat[1], len);
    }
    return true;
}

bool SocketDDSComm::DataDeal(char &big, char &small, uint16_t len)
{
    if (DDSRequestManage::GetInstance().GetDataState(dataBuffer_, dataLen_) == true) {
        return true;
    } else {
        HHT_LOG(INFO)<<"big small iD not same!";
        return false;
    }
}

bool SocketDDSComm::CreateReceiveThread()
{
    std::thread th_([this]()
                    { this->ReceivePackage(receivetimer); });
    th_.detach();
    return true;
}

bool SocketDDSComm::CreateSendThread()
{
    std::thread th_([this]()
                    { this->SendPackage(sendtimer); });
    th_.detach();
    return true;
}


bool SocketDDSComm::CreateSendRsponseThread()
{
    std::thread th_([this]()
                    { this->SendResponse(); });
    th_.detach();
    return true;
}


bool SocketDDSComm::SendResponse()
{
    bool res;
    while(true) {
        if (breceiveSign) {
            memset(respBuffer_, 0, BUFFER_MAX); 

            respdataLen_ = BUFFER_MAX;

            res = udpDDSServerPtr_->ReceivePackage(respBuffer_, respdataLen_);

            if (res == false) {
                return res;
            }

            if(breceiveSign == false) {
                continue;
            }


            if(respBuffer_[DataCommand_Byte6] == 0x13) {
                std::string temp = DDSRequestManage::GetInstance().GetDDSReply(respBuffer_[DataContext_Byte8], respBuffer_[DataContext_Byte9]);
                PrintReplyLog(temp, respBuffer_, respdataLen_);
            }
            
            res = udpServerPtr_->SendPackage(respBuffer_, respdataLen_,
                                    (ddsConfig_->GetDDSAddress()).c_str(), ddsConfig_->GetClientSendPort());
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
}

bool SocketDDSComm::PrintReplyLog(std::string& reply, const char* buffer, size_t& len)
{
    std::string value = "";
    for(size_t i=0; i < len; ++i) {
        value += (" " + std::to_string((unsigned char)buffer[i]));
    }
    HHT_LOG(WARNING)<<"[DDS Client] -> [VCC Client] "<<reply<<": "<<value;
}