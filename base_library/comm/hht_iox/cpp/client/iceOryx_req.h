/*
 * @author 008196
 * @for iceOryx wait
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ICEORYX_REG_H
#define ICEORYX_REG_H

#include "iceoryx_posh/popo/client.hpp"
#include "event_struct_idl.h"
#include "enum_event.h"

namespace HHT {

class IceOryxReq {
public:
    explicit IceOryxReq() noexcept { };
    /* send Req and wait for the result consequency*/
    int GetValue(const Event evtID) const
    {
        int res = -1;

        uint64_t fibonacciLast = 0;
        uint64_t fibonacciCurrent = 1;
        int64_t requestSequenceId = 0;
        int64_t expectedResponseSequenceId = requestSequenceId;

        iox::popo::Client<AddRequest, AddResponse> client({"Example", "Request-Response", "Add"});
        client.loan()
            .and_then([&](auto& request) {
                request.getRequestHeader().setSequenceId(requestSequenceId);
                expectedResponseSequenceId = requestSequenceId;
                requestSequenceId += 1;
                request->augend = fibonacciLast;
                request->addend = fibonacciCurrent;
                //std::cout << APP_NAME << " Send Request: " << fibonacciLast << " + " << fibonacciCurrent << std::endl;
                request.send().or_else(
                    [&](auto& error) { std::cout << "Could not send Request! Error: " << error << std::endl; });
            })
            .or_else([](auto& error) { std::cout << "Could not allocate Request! Error: " << error << std::endl; });

    // wait for result of pre request

            //! [take response]
        while (client.take().and_then([&](const auto& response) {
            auto receivedSequenceId = response.getResponseHeader().getSequenceId();
            if (receivedSequenceId == expectedResponseSequenceId) {
                fibonacciLast = fibonacciCurrent;
                fibonacciCurrent = response->sum;
                //std::cout << APP_NAME << " Got Response : " << fibonacciCurrent << std::endl;
            } else {
                //std::cout << "Got Response with outdated sequence ID! Expected = " << expectedResponseSequenceId
                       //   << "; Actual = " << receivedSequenceId << "! -> skip" << std::endl;
            }
        }))
        { };
        return res;
    }

};
}

#endif /* ICEORYX_REG_H */
