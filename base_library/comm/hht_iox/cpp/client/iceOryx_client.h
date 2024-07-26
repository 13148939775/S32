/*
 * @author 008196
 * @for iceOryx wait
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ICEORYX_CLIENT_H
#define ICEORYX_CLIENT_H

#include <string>
#include "iceOryx_wait.h"
#include "iceOryx_req.h"

namespace HHT {

class IceOryxClient : public BaseClientCommInterface {
public:
    explicit IceOryxClient(const std::string& owner) noexcept
    { 
        iox::runtime::PoshRuntime::initRuntime("Client");
    }

    bool Init() override
    {
      
    }

    int Wait(const Event evtID, const int timeout) override
    {
      return waiter_.Wait(evtID, timeout);
    }

    int GetValue(const Event evtID) const override
    {
      return req_.GetValue(evtID);
    }
private:
    IceOryxWait waiter_;
    IceOryxReq req_;
};
}
#endif /* ICEORYX_CLIENT_H */
