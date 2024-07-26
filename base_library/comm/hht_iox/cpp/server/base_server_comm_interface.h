/*
 * @author 008196
 * @for IceOryx server comm c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SERVER_COMM_IMPL_INTERFACE
#define SERVER_COMM_IMPL_INTERFACE

#include "cpp/enum_event.h"

namespace HHT {
class BaseServerCommInterface {
public:

    virtual ~BaseServerCommInterface() = default;
    
    virtual bool Init() = 0;

    // it is the sub part
    virtual int Pub(const Event EvtID) = 0;
    virtual void ReqReply() = 0;
    virtual void OfferService() = 0;
};
}

#endif /* SERVER_COMM_IMPL_INTERFACE */
