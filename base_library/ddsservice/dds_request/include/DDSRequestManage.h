/*
 * @author 008555
 * @for dds request manage
 * @version 1.0
 * @date 2023-06 ~ 2023-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef DDS_REQUEST_MANAGE_h
#define DDS_REQUEST_MANAGE_h

#include <string>
#include <vector>
#include <unordered_map>
#include "DDSservice.h"
#include "DDSServiceInterface.hpp"
#include "node_log.h"
#include "nlohmann/json.hpp"
#include "socket_udp_server.h"

using namespace DDSservice;



class DDSRequestManage
{

private:
public:
    static DDSRequestManage &GetInstance()
    {
        static DDSRequestManage dm;
        return dm;
    }

public:
    struct pairHash{
    public:
        template <typename T, typename U>
        size_t operator() (const std::pair<T, U>&x) const {
            return std::hash<T>()(x.first)^std::hash<U>()(x.second);
        }
    };

public:
    struct S2SData {
        S2SData(const std::string& hmiName, const std::string& vccName, const std::string& ddsReqName, const std::string& ddsRepName, 
        const std::string& ddsType, const std::string& ddsValue, const uint8_t& smallID, const uint8_t& bigID, const uint8_t& pos)
        :hmi_Name(hmiName),
         vcc_Name(vccName),
         dds_ReqName(ddsReqName),
         dds_RepName(ddsRepName),
         dds_Type(ddsType),
         dds_Value(ddsValue),
         small_ID(smallID),
         big_ID(bigID),
         bit_pos(pos) {};

        ~S2SData() {};

        std::string hmi_Name;
        std::string vcc_Name;
        std::string dds_ReqName;
        std::string dds_RepName;
        std::string dds_Type;
        std::string dds_Value;
        uint8_t small_ID;
        uint8_t big_ID;
        uint8_t bit_pos;


        std::string GetHMIName() const
        {
            return hmi_Name;
        }

        std::string GetVccName() const
        {
            return vcc_Name;
        }
        
        std::string GetDDSReqName() const
        {
            return dds_ReqName;
        }

        std::string GetDDSRepName() const
        {
            return dds_RepName;
        }

        uint8_t GetSmallID() const
        {
            return small_ID;
        }

        uint8_t GetBigID() const
        {
            return big_ID;
        }

        std::string GetDDSType() const 
        {
            return dds_Type;
        }

        std::string GetDDSValue() const
        {
            return dds_Value;
        }
    };

    using DDSRequesterPtr = std::shared_ptr<DDSrequester<DDSCommandSet_struct, DDSCommandRsp_struct>>;
    using S2SMapDef = std::unordered_map<std::pair<char, char>, std::shared_ptr<S2SData>, pairHash>;
    using DDSRequestVecDef = std::vector<DDSRequesterPtr>;

    void GetUdpServer(std::shared_ptr<SocketUDPServer> socketPtr)
    {
        socketPtr_ = socketPtr;
    }

    std::string  GetDDSReply(char big , char small)
    {
        std::string reply = "";
        if(s2sDataMap_.find(std::make_pair(big, small)) != s2sDataMap_.end()) {
            reply = s2sDataMap_[std::make_pair(big, small)]->GetDDSRepName();
        }
       return reply;
    }

    bool ReadS2SConfig(std::string file);

    bool BuildMap(const nlohmann::json& data);

    bool GetDataState(char* data, size_t len);

    bool RevertValue(char* data, size_t len);

    void SendDDSRequest(const std::string &reqtopic,const std::string& reptopic,const std::string &hminame, const std::string &ipcfname, const char& value);

    void CreateDDSRequest(std::string& request, std::string& reply);

    void ReceiveDDSReply(DDSRequesterPtr requester);

    void PrintHMILog(std::shared_ptr<S2SData> ddsData, const char* buffer, size_t& len);

private:
    std::string remote_iP_;
    unsigned int remote_port_; 
    
    std::vector<std::shared_ptr<S2SData>> s2sDataVec_;
    std::shared_ptr<SocketUDPServer> socketPtr_;
    S2SMapDef s2sDataMap_;
    DDSRequestVecDef requesterVec_;
    std::unordered_map<std::string, size_t> requestDDSmap_;
};
#endif