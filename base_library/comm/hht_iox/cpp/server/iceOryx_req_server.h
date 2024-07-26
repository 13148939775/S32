/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ICEORYX_REQ_SERVER_H
#define ICEORYX_REQ_SERVER_H

#include "iceoryx_posh/popo/server.hpp"
#include "event_struct_idl.h"

namespace HHT {
class IceOryxReqServer {
public:
    IceOryxReqServer() noexcept = default;

    void ReqReply()
    {
        iox::popo::Server<AddRequest, AddResponse> server({"Example", "Request-Response", "Add"});
        //! [take request]
        server.take().and_then([&](const auto& request) {       
            //! [send response]
            server.loan(request)
                .and_then([&](auto& response) {
                    response->sum = request->augend + request->addend;
                    
                    response.send().or_else(
                        [&](auto& error) {  });
                })
                .or_else([&](auto& error) {

                });
        });
    }
};

}
#endif /* ICEORYX_REQ_SERVER_H */
