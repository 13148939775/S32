
/*
 * @author 008196
 * @for IceOryx enum class
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ENUM_EVENT_H
#define ENUM_EVENT_H

namespace HHT {
enum class Event : std::uint8_t {
    EVENT_START = 0,
    EVENT_DOIP_ONLINE_EVENT,
    EVENT_APPMng_REQSUSPEND,
    EVENT_APPMng_REQRESUME,
    EVENT_APPMng_StateReport,
    EVENT_SYSMng_StateReport,
    EVENT_SYSMng_RELIABILITY_REPORT,    
    EVENT_MAX
};

enum class ProtocolType : std::uint8_t {
    PROTOCOL_START = 0,
    PROTOCOL_RTI_DDS,
    PROTOCOL_ICEORYX_DDS,
    PROTOCOL_SOMEIP,
    PROTOCOL_FDBUS,
    PROTOCOL_DOIP,
    PROTOCOL_OTHERS
};
}
#endif