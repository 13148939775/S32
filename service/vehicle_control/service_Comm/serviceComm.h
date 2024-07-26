/*
 * @author 008555
 * @for VehicleControlService communicate with VCC by socket
 * @version 1.0
 * @date 2023-06 ~ 2023-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SERVICE_COMM_H
#define SERVICE_COMM_H

#include <string>
#include <vector>
#include <unordered_map>

#include "socket_udp_client.h"
#include "socket_udp_server.h"
#include "DDSServiceInterface.hpp"

#include "nlohmann/json.hpp"
#include "DDSReplyDataDef.h"

#include "DDSReplierManage.h"

#define BUFFER_MAX 1024

class ServiceComm {
public:
    static ServiceComm& GetInstance()
    {
        static ServiceComm sc;
        return sc;
    }
private:
    ServiceComm();
    ~ServiceComm();

public:
    struct DDSConfig {
        DDSConfig(const std::string& DDS_DefDate,       const std::string& DDS_Version, 
                  const std::string& DDS_Address,       const std::string& VCC_Address,
                  const unsigned short& cclient_Port, 
                  const unsigned short& cclient_Port2,  const unsigned short& csend_Port, 
                  const unsigned short&  srecv_Port,    const unsigned short&  ssend_Port,
                  const unsigned short&  ssend_Port2,   const unsigned short& ipcf_Port)
        :dds_DefDate(DDS_DefDate),
         dds_Version(DDS_Version),
         dds_Address(DDS_Address),
         vcc_Address(VCC_Address),
         clientrecv_Port(cclient_Port),
         clientrecv2_Port(cclient_Port2),
         clientsend_Port(csend_Port),
         serverrecv_Port(srecv_Port),
         serversend_Port(ssend_Port),
         serversend2_Port(ssend_Port2),
         serveripcf_Port(ipcf_Port)
         {};

        ~DDSConfig() {};

        std::string dds_DefDate;
        std::string dds_Version;

        std::string dds_Address;
        std::string vcc_Address;
        unsigned short clientrecv_Port;
        unsigned short clientrecv2_Port;
        unsigned short clientsend_Port;

        unsigned short serverrecv_Port;
        unsigned short serversend_Port;
        unsigned short serversend2_Port;
        unsigned short serveripcf_Port;

        std::string GetDDSDefDate() const
        {
            return dds_DefDate;
        }

        std::string GetDDSVersion() const
        {
            return dds_Version;
        }
        
        std::string GetDDSAddress() const
        {
            return dds_Address;
        }

        std::string GetVCCAddress() const
        {
            return vcc_Address;
        }

        unsigned int GetClientRecvPort() const 
        {
            return clientrecv_Port;
        }

        unsigned int GetClientRecvPort2() const 
        {
            return clientrecv2_Port;
        }

        unsigned int GetClientSendPort() const
        {
            return clientsend_Port;
        }

        unsigned int GetServerRecvPort() const
        {
            return serverrecv_Port;
        }

        unsigned int GetServerSendPort() const
        {
            return serversend_Port;
        }

        unsigned int GetServerSendPort2() const
        {
            return serversend2_Port;
        }

        unsigned int GetServerIPCFPort() const
        {
            return serveripcf_Port;
        }
    };

    using IpcfDataPosDef = std::unordered_map<uint16_t, std::pair<uint8_t, uint8_t>>;
    using IpcfDataSave   = std::unordered_map<uint16_t, uint8_t>;
public:
    bool ReadConfig(std::string& file);

    bool BuildMap(const nlohmann::json& data);

    bool Init(std::string& file);

    bool DataInvalid(char* data);

    bool PrintSendMsg(std::string &req, char*data, size_t& len);

    bool DataSplit(const char* data, size_t& len);

    void SendPackage(char* data,size_t len);

    void SendTickPackage(uint32_t seconds);

    void ReceivePackage();

    void ReceiveIpcfPackage();

    bool CreateReceiveThread();

    bool CreateSendTickThread();

    bool DataDeal();

    GeneralVehSt_Struct& GetGeneralVehSt()
    {
        return generalVehSt_;
    }

private:
    char dataBuffer_[BUFFER_MAX];

    const uint32_t sendtimer_ = 1000;

    size_t dataLen_;

    SocketUDPClient udpClient_;

    SocketUDPClient udpDDSClient_;

    std::shared_ptr<DDSConfig> ddsConfig_;

    DDSReplierManage::S2SMapDef s2sDataMap_;
private:
    SocketUDPServer udpIpcfServer_;
    std::atomic<bool> ipcfNetworkSign_;
    std::atomic<bool> runSign_;

    char ipcfBuffer_[BUFFER_MAX];

    constexpr static uint16_t dataValid_ = 5;
    constexpr static uint8_t bigID = 8;
    constexpr static uint8_t smallID = 9;
    constexpr static uint8_t valuePos = 10;

    bool DataFilter(char *data, size_t& len);

    IpcfDataPosDef  ipcfDataPos_ = {
        {248, {42, 1}},
        {250, {42, 3}},
        {252, {42, 5}},
        {254, {42, 7}},
        {256, {42, 9}},
        {258, {42, 11}}
    };

    IpcfDataSave  ipcfDataSave = {
            {248, 0},
            {250, 0},
            {252, 0},
            {254, 0},
            {256, 0},
            {258, 0}
    };

private:
    GeneralVehSt_Struct  generalVehSt_;
    PowerModeSt_Struct   powerModeSt_;
    DringMode_St_Struct  dringMode_St_; 
};

#endif