/*
 * @author 008196
 * @for IceOryx ClientComm c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BASE_ClIENT_COMM_INTERFACE
#define BASE_ClIENT_COMM_INTERFACE

#include "cpp/enum_event.h"

namespace HHT {
class BaseClientCommInterface {
public:
    virtual ~BaseClientCommInterface() = default;
    virtual bool Init() = 0;

    // it is the sub part
    virtual int Wait(const Event EvtID, const int timeout) = 0;
    virtual int GetValue(const Event evtID) const = 0;
};
}

#endif /* BASE_ClIENT_COMM_INTERFACE */

