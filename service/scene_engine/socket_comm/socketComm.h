
/*
 * @author 008555
 * @for DDSClient communicate with ipad by socket
 * @version 1.0
 * @date 2023-06 ~ 2023-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SOCKET_COMM_H
#define SOCKET_COMM_H

#include <string>
#include <vector>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include "socket_udp_server.h"

#define BUFFER_MAX 512

class SocketDDSComm
{
public:
    static SocketDDSComm &GetInstance()
    {
        static SocketDDSComm socket_ddscomm;
        return socket_ddscomm;
    }

private:
    SocketDDSComm();
    ~SocketDDSComm();    

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
public:
    bool Init(std::string& file);

    bool InitConfig(std::string& file);

    bool ReadConfig(std::string& file);

    bool BuildMap(const nlohmann::json& data);

    void ReceivePackage(uint32_t seconds);

    bool ReceiveDataPackage();

    void SendPackage(uint32_t seconds);

    bool SendDataPackage();

    bool printRecvData(char *data, size_t& len);

    bool VccToDDS(const char *data);

    bool DataDeal(char &big, char &small, uint16_t len);

    bool CreateReceiveThread();

    bool CreateSendThread();

    bool CreateSendRsponseThread();

    bool SendResponse();

    bool PrintReplyLog(std::string& reply, const char* buffer, size_t& len);
private:
    char dataBuffer_[BUFFER_MAX];
    size_t dataLen_;
    const uint32_t receivetimer = 100;
    const uint32_t sendtimer = 1000;
    std::shared_ptr<SocketUDPServer> udpServerPtr_;


    std::shared_ptr<SocketUDPServer> udpDDSServerPtr_;
    char respBuffer_[BUFFER_MAX];
    size_t respdataLen_;

    bool breceiveSign;

private:
    std::shared_ptr<DDSConfig> ddsConfig_;
};
#endif