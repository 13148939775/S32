/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ICEORYX_SERVER_H
#define ICEORYX_SERVER_H

#include <string>
#include "iceOryx_pub.h"
#include "iceOryx_req_server.h"

namespace HHT {

class IceOryxServer : public BaseServerCommInterface {
public:
    explicit IceOryxServer(std::string& owner) noexcept
    { 
        iox::runtime::PoshRuntime::initRuntime("Server");
    }
    bool Init() override
    {
        return true;
    }

    int Pub(const Event evtID) override
    {
      pub_.Pub(evtID);
    }
    
    void ReqReply() override
    {
        reqServer_.ReqReply();
    }

    void OfferService() override
    {
        pub_.OfferService();
    }
private:
    IceOryxPub pub_;
    IceOryxReqServer reqServer_;
};
}
#endif /* ICEORYX_SERVER_H */

