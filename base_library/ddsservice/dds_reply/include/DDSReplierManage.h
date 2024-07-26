/*
 * @author 008555
 * @for dds Replier manage
 * @version 1.0
 * @date 2023-06 ~ 2023-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DDS_REPLIER_MANAGE_H
#define DDS_REPLIER_MANAGE_H

#include <string>
#include <vector>
#include "DDSservice.h"
#include "DDSServiceInterface.hpp"
#include "nlohmann/json.hpp"
#include "DDSReplierListener.h"
#include "DDSReplyDataDef.h"

using namespace DDSservice;


class DDSReplierManage
{
public:
    static DDSReplierManage &GetInstance()
    {
        static DDSReplierManage dm;
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

    };

public:
    using S2SMapDef = std::unordered_map<std::pair<char, char>, std::shared_ptr<S2SData>, pairHash>;
    using DDSReplyPtr = std::shared_ptr<DDSreplier<DDSCommandSet_struct, DDSCommandRsp_struct>>;
    using DDSReplyVecDef = std::vector<DDSReplyPtr>;

public:
    bool ReadS2SConfig(std::string file);

    bool BuildMap(const nlohmann::json& data);

    bool CreateDDSReply(std::string& reqtopic, std::string& reptopic);

    bool CreateLoopRequest();

    std::string GetReplyName(char big, char small);

private:
    S2SMapDef s2sDataMap_;

    DDSReplyVecDef replyVec_;

private:
    std::shared_ptr<ReplierListenerDDS> replier_Listener_DDS_;
};

#endif