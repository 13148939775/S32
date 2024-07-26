/**
 * @file    replier.cpp
 * @author  Jeremy_Xu
 * @brief   custom_topic_name_replier_demo
 * @version 0.1
 * @date    2023-05-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string.h>

#include <rti/request/rtirequest.hpp>
#include <rti/config/Logger.hpp>
#include "hdbi_bdarm.hpp"

const unsigned int domain_id = 0;
const dds::core::Duration MAX_WAIT_TIME = dds::core::Duration::from_secs(1);

class ReplierListenerHdbiBdarmRsp : public rti::request::ReplierListener<HDBI_BdArm_Set_struct, HDBM_BdArm_Rsp_struct>
{
    virtual void on_request_available(rti::request::Replier<HDBI_BdArm_Set_struct, HDBM_BdArm_Rsp_struct> &replier)
    {
        dds::sub::LoanedSamples<HDBI_BdArm_Set_struct> requests = replier.take_requests();

        if (0 < requests.length()) {
            for (auto &request : requests) {
                // 此处如何区分A-B-C多个请求，回复对应的其中一个?
                if (!request.info().valid()) {
                    continue;
                }
                // debug info
                std::cout << "[receive request: "
                          << std::to_string(request.data().VehicleUnlock_Set())
                          << ","
                          << std::to_string(request.data().ReturnPYnlock_Set()) << "]" << std::endl;
                // data feedback
                HDBM_BdArm_Rsp_struct reply(request.data().VehicleUnlock_Set(), request.data().ReturnPYnlock_Set());
                replier.send_reply(reply, request.info());
                std::cout << "[Request From HDBI_BdArm_Set_struct to HDBM_BdArm_Rsp_struct DONE!]" << std::endl;
            }
        } else {
            std::cout << "[NO MESSAGE!!!]" << std::endl;
        }
    }
};
class ReplierListenerHdbiBdarmSt : public rti::request::ReplierListener<HDBI_BdArm_Act_struct, HDBM_BdArm_St_struct>
{
    virtual void on_request_available(rti::request::Replier<HDBI_BdArm_Act_struct, HDBM_BdArm_St_struct> &replier)
    {
        dds::sub::LoanedSamples<HDBI_BdArm_Act_struct> requests = replier.take_requests();

        if (0 < requests.length()) {
            for (auto &request : requests) {
                if (!request.info().valid()) {
                    continue;
                }
                // debug info
                std::cout << "[receive request: "
                          << std::to_string(request.data().CenterLck_Act())
                          << "]" << std::endl;
                // data feedback
                HDBM_BdArm_St_struct reply(1, 1, 1);
                replier.send_reply(reply, request.info());
                std::cout << "[Request From HDBI_BdArm_Act_struct to HDBM_BdArm_St_struct DONE!]" << std::endl;
            }
        } else {
            std::cout << "[NO MESSAGE!!!]" << std::endl;
        }
    }
};

void run_replier(const unsigned int domain_id)
{
    // participant&qos
    dds::domain::DomainParticipant participant(domain_id);
    dds::core::QosProvider qos_provider("../USER_QOS_PROFILES.xml");
    rti::request::ReplierParams replier_params(participant);
    replier_params.datareader_qos(
        qos_provider.datareader_qos("RequestReplyExampleProfiles::ReplierExampleProfile"));
    replier_params.datawriter_qos(
        qos_provider.datawriter_qos("RequestReplyExampleProfiles::ReplierExampleProfile"));

    /*************************车身防盗设置*************************/
    // listener
    auto listener_hdbi_bdarm_set = std::make_shared<ReplierListenerHdbiBdarmRsp>();
    replier_params.request_topic_name("HDBI_BdArm_Set");
    replier_params.reply_topic_name("HDBI_BdArm_Act");
    // replier
    rti::request::Replier<HDBI_BdArm_Set_struct, HDBM_BdArm_Rsp_struct> replier_hdbi_bdarm_rsp(replier_params, listener_hdbi_bdarm_set);

    /*************************车身防盗执行*************************/
    // listener
    auto listener_hdbi_bdarm_st = std::make_shared<ReplierListenerHdbiBdarmSt>();
    replier_params.request_topic_name("HDBM_BdArm_St");
    replier_params.reply_topic_name("HDBM_BdArm_Rsp");
    // replier
    rti::request::Replier<HDBI_BdArm_Act_struct, HDBM_BdArm_St_struct> replier_hdbi_bdarm_st(replier_params, listener_hdbi_bdarm_st);

    while (1) {
        replier_hdbi_bdarm_rsp.receive_requests(MAX_WAIT_TIME);
        replier_hdbi_bdarm_st.receive_requests(MAX_WAIT_TIME);
    }
}

int main(int argc, char *argv[])
{
    try
    {
        run_replier(domain_id);
    }
    catch (const std::exception &e)
    {
        std::cerr << "[Exception: " << e.what() << "]" << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}