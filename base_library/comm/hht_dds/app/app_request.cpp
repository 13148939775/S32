#include "DDS_comm.h"
#include "DDSServiceInterfaceIV3.hpp"

#include <cstdint>
#include <iostream>
#include <string>

using namespace HHT;
using namespace DDSComm;
using namespace BodyDomain;

void TestRequest() {
    DDSRequesterEntity<BdArm_Srv_Req_Union, BdArm_Srv_Resp_Union> requester("test_request", "test_reply", 1000);
    BdArm_Srv_Req_Union send_data;
    for (int i = 0; i < 100; ++i) {
        if (i % 4 == 0) {
            send_data._d(0);
            send_data.BdArm_Set(BdArm_Set_struct(0, 0, 0, 0, "0"));
        }
        if (i % 4 == 1) {
            send_data._d(1);
            send_data.BdArm_Get(BdArm_Get_struct(1, "1"));
        }

        // send request
        requester.SendRequest(send_data);

        // recv reply
        auto recv_data = requester.RecvReply();
        if (0 < recv_data.length()) {
            for (const auto &reply : recv_data) {
                if (!reply.info().valid()) {
                    continue;
                }
                std::cout << reply.data() << std::endl;
            }
        } else {
            std::cout << "empty data" << std::endl;
        }

        rti::util::sleep(dds::core::Duration::from_millisecs(500));
    }
}

int main(int argc, char **argv) {
    std::cout << "running" << std::endl;
    TestRequest();
    std::cout << "done" << std::endl;

    // 程序退出前调用
    // dds::domain::DomainParticipant::finalize_participant_factory();
    return 0;
}