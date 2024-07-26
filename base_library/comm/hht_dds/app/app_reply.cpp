
#include <iostream>
#include <memory>
#include <string>
#include <unistd.h>

#include "DDS_comm.h"
#include "DDSServiceInterfaceIV3.hpp"

using namespace HHT;
using namespace DDSComm;
using namespace BodyDomain;

// listener use case
class ReplierListener : public rti::request::ReplierListener<BdArm_Srv_Req_Union, BdArm_Srv_Resp_Union> {
public:
    virtual void on_request_available(
        rti::request::Replier<BdArm_Srv_Req_Union, BdArm_Srv_Resp_Union>
            &replier) {
        // TODO处理函数
        BdArm_Srv_Resp_Union reply;
        auto requests = replier.take_requests();
        if (0 < requests.length()) {
            for (auto &request : requests) {
                if (!request.info().valid()) continue;
                if (request.data()._d() == 0) {
                    reply.BdArm_Set_SOA().VehicleUnlock_Rsp(0);
                }
                if (request.data()._d() == 1) {
                    reply.BdArm_Set_SOA().VehicleUnlock_Rsp(1);
                }
                // debug info
                std::cout << request.data() << std::endl;

                replier.send_reply(reply, request.info());
                // std::cout << "[Request From HDBI_DrLth_Set_struct to
                // HDBM_DrLth_Rsp_struct DONE!]";
            }
        }
    }
};

void TestReply() {
    std::shared_ptr<ReplierListener> listener(std::make_shared<ReplierListener>());
    DDSReplierEntity<BdArm_Srv_Req_Union, BdArm_Srv_Resp_Union> replier("test_request", "test_reply", listener, 1000);
    while (1) {
        // wait available data on listener
        sleep(1);
    }
}

// waitset use case
void TestWaitsetReply() {
    rti::core::cond::AsyncWaitSet async_waitset(rti::core::cond::AsyncWaitSetProperty().thread_pool_size(10));
    async_waitset.start();
    DDSReplierEntity<BdArm_Srv_Req_Union, BdArm_Srv_Resp_Union> replier("test_request", "test_reply", async_waitset, 1000);
    BdArm_Srv_Resp_Union send_data;
    while (1) {
        // recv request
        auto samples = replier.RecvRequest();

        for (auto sample : samples) {
            if (!sample.info().valid()) continue;
            std::cout << sample.data() << std::endl;

            if (sample.data()._d() == 0) {
                send_data.BdArm_Set_SOA(BdArm_Rsp_struct(0, 0, 0, 0));
            }
            if (sample.data()._d() == 1) {
                send_data.BdArm_Get_SOA(BdArm_Rsp_struct(1, 1, 1, 1));
            }

            // send reply
            replier.SendReply(send_data, sample.info());
        }
        sleep(1);
    }
}

int main(int argc, char **argv) {
    std::cout << "running" << std::endl;
    // TestReply();
    TestWaitsetReply();
    std::cout << "done" << std::endl;

    // 程序退出前调用
    // dds::domain::DomainParticipant::finalize_participant_factory();
    return 0;
}