/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef COMM_CONFIG_H
#define COMM_CONFIG_H

#include <string>
#include <vector>
#include <unordered_map>

#include "iceoryx_hoofs/cxx/optional.hpp"
#include "iceoryx_posh/popo/publisher.hpp"
#include "iceoryx_posh/popo/subscriber.hpp"
#include "iceoryx_posh/popo/wait_set.hpp"

#include "enum_event.h"

namespace HHT {
class CommConfig {
public:
    /* Door left  CloseorOpen*/
    struct ServiceProp {
        iox::capro::IdString_t service;
        iox::capro::IdString_t position;
        iox::capro::IdString_t function;
    };
    CommConfig() = default;
    ~CommConfig() = default;
    static CommConfig& GetInstance()
    {
        static CommConfig cc;
        return cc;
    }

    CommConfig& operator=(const CommConfig&) = delete;

    std::unordered_map<Event, ServiceProp> GetCommMap() const
    { return topicMap_;}

    std::unordered_map<ProtocolType, std::string> GetProtocolMap() const
    { return protocolMap_;}

private:
    std::unordered_map<Event, ServiceProp> topicMap_ = 
    {
        {Event::EVENT_START, {"", "", ""}},
        {Event::EVENT_DOIP_ONLINE_EVENT, {"Doip", "", "Online"}},
        {Event::EVENT_APPMng_REQSUSPEND, {"AppMng", "", "Suspend"}},
        {Event::EVENT_APPMng_REQRESUME, {"AppMng", "", "Resume"}},
        {Event::EVENT_APPMng_StateReport, {"AppMng", "", "StateReport"}},
        {Event::EVENT_SYSMng_StateReport, {"SysMng", "", "StateReport"}},
        {Event::EVENT_SYSMng_RELIABILITY_REPORT, {"SysMng","", "ReliabilityReport"}}
    };
    std::unordered_map<ProtocolType, std::string> protocolMap_ = 
    {
        {ProtocolType::PROTOCOL_RTI_DDS, "RTI DDS"},
        {ProtocolType::PROTOCOL_ICEORYX_DDS, "IceOryx DDS"},
        {ProtocolType::PROTOCOL_FDBUS, "Fdbus"},
        {ProtocolType::PROTOCOL_SOMEIP, "Someip"},
        {ProtocolType::PROTOCOL_OTHERS, "others Doip https mqtt"},
    };
};
}
#endif /* COMM_CONFIG_H */
