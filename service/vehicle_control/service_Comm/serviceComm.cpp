#include "serviceComm.h"

#include <ctime>
#include <chrono>
#include <thread>
#include <fstream>
#include <iostream>
#include <mutex>

#include "node_log.h"

enum DataDef : uint16_t {
    DataHead_Byte0 = 0,
    DataHead_Byte1 = 1,
    DataHead_Byte2 = 2,
    DataHead_Byte3 = 3,
    DataLen_Byte4  = 4,
    DataLen_Byte5  = 5,
    DataCommand_Byte6 = 6,
    DataContext_Byte8 = 8,
    DataContext_Byte9 = 9,
    DataContext_Data10 =10,
    DataContext_Data11 =11
};

ServiceComm::ServiceComm()
{
    runSign_ = true;
}
    
ServiceComm::~ServiceComm()
{

}

bool ServiceComm::ReadConfig(std::string& file)
{
    HHT_LOG(INFO)<<"read json and Build tree";
    std::ifstream inf(file);
    //解析
    nlohmann::json data = nlohmann::json::parse(inf);
        //序列化
    std::string s = data.dump();

    HHT_LOG(INFO)<< "json is:" << s << std::endl;

    return BuildMap(data);
}

bool ServiceComm::BuildMap(const nlohmann::json& data)
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

bool ServiceComm::Init(std::string& file)
{
    dataLen_ = BUFFER_MAX;
    
    bool res = udpClient_.Init(ddsConfig_->GetServerRecvPort(), (ddsConfig_->GetDDSAddress()).c_str());
    if (res == false) {
        return res;
    }
    res = udpDDSClient_.Init(ddsConfig_->GetServerSendPort2(), (ddsConfig_->GetDDSAddress()).c_str());
    if (res == false) {
        return res;
    }

    unsigned short port = ddsConfig_->GetServerIPCFPort();
    udpIpcfServer_.Init(port);
    udpIpcfServer_.Bind();
    ipcfNetworkSign_ = false;

    return DDSReplierManage::GetInstance().ReadS2SConfig(file);
}


bool ServiceComm::DataSplit(const char* data, size_t& len)
{
    short* pShort;
    if (data[DataContext_Byte8] == 31) {
        if (data[DataContext_Byte9] == 0) {
            powerModeSt_.PowerModeStBit = 0x80;     
        } else if (data[DataContext_Byte9] == 1) {
            powerModeSt_.PowerModeStBit = 0x40;
        } else if (data[DataContext_Byte9] == 2) {
            powerModeSt_.PowerModeStBit = 0x20;
        }
        powerModeSt_.PowerModeSt = data[DataContext_Data10];
    } else if (data[DataContext_Byte8] == 37) {
        if (data[DataContext_Byte9] == 0 || data[DataContext_Byte9] == 1) {
            pShort = (short*)&data[DataContext_Data10];
            generalVehSt_.SOCDisplay_Val = pShort[0];
        } else if (data[DataContext_Byte9] == 2) {
            generalVehSt_.DCCharge_St = data[DataContext_Data10];
        } else if (data[DataContext_Byte9] == 3) {
            generalVehSt_.ACCharge_St = data[DataContext_Data10];
        } else if (data[DataContext_Byte9] == 4) {
            generalVehSt_.FLSeatOcp_St = data[DataContext_Data10];
        } else if (data[DataContext_Byte9] == 5) {
            generalVehSt_.ActlGear_St = data[DataContext_Data10];
        } else if (data[DataContext_Byte9] == 6) {
            generalVehSt_.ActlGearVaild_St = data[DataContext_Data10];
        } else if (data[DataContext_Byte9] == 7) {
            generalVehSt_.Ready_St = data[DataContext_Data10];
        } else if (data[DataContext_Byte9] == 8) {
            generalVehSt_.DrvrSeatBeltValid_St = data[DataContext_Data10];
        } else if (data[DataContext_Byte9] == 9) {
            generalVehSt_.DrvrSeatBelt_St = data[DataContext_Data10];
        } else if (data[DataContext_Byte9] == 10) {
            generalVehSt_.EPB_St = data[DataContext_Data10];
        } else if (data[DataContext_Byte9] == 11) {
            generalVehSt_.VehSpdValid_St = data[DataContext_Data10];
        } else if (data[DataContext_Byte9] == 12 || data[DataContext_Byte9] == 13) {
            pShort = (short*)&data[DataContext_Byte9];
            generalVehSt_.VehSpd_Val = pShort[0];
        }
    }
    return true;
}

void ServiceComm::SendPackage(char* data,size_t len)
{
    std::string ip = ddsConfig_->GetVCCAddress();
    u_char ipcfData[] = {0x03,0x01,0x00,0xff,0x09,0x00,0x00,0x00,0x07, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00,0x00};
    u_char ipcfData2[] = {0x68, 0x68, 0x99, 0x11, 0x00, 0x03, 0x09, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    size_t ipcfLen;
    unsigned short port = ddsConfig_->GetServerIPCFPort();
    std::string reply = DDSReplierManage::GetInstance().GetReplyName(data[DataContext_Byte8], data[DataContext_Byte9]);

    if (data[DataContext_Byte8] != 45 || data[DataContext_Byte9] != 4) {
        PrintSendMsg(reply, data, len);
        udpClient_.SendPackage(data, len, ip.c_str(), ddsConfig_->GetServerSendPort());
        if (ipcfNetworkSign_) {
            if (data[DataContext_Byte8] == 0x15 && data[DataContext_Data10] == 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                ipcfLen = sizeof(ipcfData2);
                PrintSendMsg(reply, (char*)ipcfData2, ipcfLen);
                udpIpcfServer_.SendPackage((char*)ipcfData2, ipcfLen,"127.0.0.1", port);
            }
        }
    } else if (ipcfNetworkSign_) {
        ipcfLen = sizeof(ipcfData);
        ipcfData[ipcfLen-1] = data[DataContext_Data10];
        PrintSendMsg(reply, (char*)ipcfData, ipcfLen);
        udpIpcfServer_.SendPackage((char*)ipcfData, ipcfLen,"127.0.0.1", port);
    }
}

bool ServiceComm::PrintSendMsg(std::string &req, char*data, size_t& len)
{
    std::string value = "";
    for(size_t i=0; i < len; ++i) {
        value += (" " + std::to_string((u_char)data[i]));
    }
    HHT_LOG(WARNING)<<"[DDS Server] -> [VCC Server] "<<req<<": "<<value;
}

void ServiceComm::SendTickPackage(uint32_t seconds)
{
    char data[14] = {0x68, 0x68, 0x68, 0x00, 0x04, 0x00,0x00, 0x00};
    uint32_t* pInt = (uint32_t*)&data[8];
    data[12] = 0x00;
    data[13] = 0x00;
    size_t len = 14;
    std::string ip = ddsConfig_->GetVCCAddress();
    while (true) {
        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);
        pInt[0] = localTime->tm_hour*3600 + localTime->tm_min*60 + localTime->tm_sec;

        udpClient_.SendPackage(data, len, ip.c_str(), ddsConfig_->GetServerSendPort());

        std::this_thread::sleep_for(std::chrono::milliseconds(seconds));
    }
}

bool ServiceComm::DataInvalid(char* data)
{
    if (data[DataHead_Byte0] == 0x68 && data[DataHead_Byte1] == 0x68 &&
        data[DataHead_Byte2] == 0x99 && data[DataHead_Byte0] == 0x00) {
            return true;
        }
   return false; 
}

void  ServiceComm::ReceivePackage()
{
    std::string ip = ddsConfig_->GetDDSAddress();
    while (true) {
        udpClient_.ReceivePackage(dataBuffer_, dataLen_, ddsConfig_->GetServerRecvPort());
        udpDDSClient_.SendPackage(dataBuffer_, dataLen_, (ddsConfig_->GetDDSAddress()).c_str(), ddsConfig_->GetServerSendPort2());

        DataDeal();    
    }
}

void ServiceComm::ReceiveIpcfPackage()
{   
    std::thread th_([this]() {
        size_t len = BUFFER_MAX;
        while (runSign_) {            
            if (true == udpIpcfServer_.ReceivePackage(ipcfBuffer_, len)) {
                ipcfNetworkSign_ = true;
                if (0x04 == ipcfBuffer_[dataValid_]) { //ipcf
                    DataFilter(ipcfBuffer_, len);
                }
            }
        }
    });
    th_.detach();
}

bool ServiceComm::DataDeal()
{
    return DataSplit(dataBuffer_, dataLen_); 
}

bool ServiceComm::CreateSendTickThread()
{
    std::thread th_([this]() {
        this->SendTickPackage(sendtimer_);
    });
    th_.detach();
    return true;
}

bool ServiceComm::CreateReceiveThread()
{
    std::thread th_([this]() {
        this->ReceivePackage();
    });
    th_.detach();
    return true;
}

bool ServiceComm::DataFilter(char *data, size_t& len)
{
    uint8_t buf[] = {0x68, 0x68, 0x99, 0x00, 0x03, 0x00, 0x13, 0x00, 0x2a, 0x05, 0x00, 0x00, 0x00};
    size_t slen = 13;
    for (auto it : ipcfDataPos_) {
        if (data[it.first] != ipcfDataSave[it.first]) {
            HHT_LOG(INFO) << "Data Filter Pos1: "<< it.first;
            ipcfDataSave[it.first] = data[it.first];
            buf[bigID] = ipcfDataPos_[it.first].first;
            buf[smallID] = ipcfDataPos_[it.first].second;
            buf[valuePos] = ipcfDataSave[it.first];
            udpDDSClient_.SendPackage((char*)buf, slen, (ddsConfig_->GetDDSAddress()).c_str(), ddsConfig_->GetServerSendPort2());
        }
    }
    return true;
}
