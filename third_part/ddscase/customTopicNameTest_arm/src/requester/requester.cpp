/**
 * @file    requester.cpp
 * @author  Jeremy_Xu
 * @brief   custom_topic_name_requester_demo
 * @version 0.1
 * @date    2023-05-24
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

void runRequester(unsigned int domain_id)
{
    // participant&QoS
    dds::domain::DomainParticipant HDBI_BdArm_participant(domain_id);
    dds::core::QosProvider qos_provider("../USER_QOS_PROFILES.xml");
    rti::request::RequesterParams requester_params(HDBI_BdArm_participant);
    requester_params.datareader_qos(
        qos_provider.datareader_qos("RequestReplyExampleProfiles::RequesterExampleProfile"));
    requester_params.datawriter_qos(
        qos_provider.datawriter_qos("RequestReplyExampleProfiles::RequesterExampleProfile"));

    /*************************车身防盗设置*************************/
    requester_params.request_topic_name("HDBI_BdArm_Set");
    requester_params.reply_topic_name("HDBI_BdArm_Act");
    // requester
    rti::request::Requester<HDBI_BdArm_Set_struct, HDBM_BdArm_Rsp_struct>
        requester_hdbi_bdarm_set(requester_params);
    HDBI_BdArm_Set_struct hdbi_bdarm_set_data(0, 1);
    // send_request
    requester_hdbi_bdarm_set.send_request(hdbi_bdarm_set_data);
    // receive data
    // auto replier_hdbm_bdarm_rsp = requester_hdbi_bdarm_set.receive_replies(MAX_WAIT_TIME);
    bool is_received_hdbi_bdarm_act = requester_hdbi_bdarm_set.wait_for_replies(MAX_WAIT_TIME);
    auto replier_hdbm_bdarm_rsp = requester_hdbi_bdarm_set.take_replies();
    // if (!is_received_hdbi_bdarm_act)
    //     std::cout << "[等待 " << requester_params.reply_topic_name().c_str() << " 超时]" << std::endl;
    if (0 < replier_hdbm_bdarm_rsp.length()) {
        for (const auto &replies : replier_hdbm_bdarm_rsp) {
            if (!replies.info().valid()) {
                continue;
            }   
            // debug info
            std::cout << "[From replier HDBM_BdArm_Rsp_struct: VehicleUnlock_Rsp-"
                      << std::to_string(replies.data().VehicleUnlock_Rsp())
                      << ","
                      << "ReturnPYnlock_Rsp-"
                      << std::to_string(replies.data().ReturnPYnlock_Rsp())
                      << " ]" << std::endl;
        }
        std::cout << "[Request From HDBI_BdArm_Set_struct to HDBM_BdArm_Rsp_struct DONE!]" << std::endl;
    }

    /*************************车身防盗执行*************************/
    requester_params.request_topic_name("HDBM_BdArm_St");
    requester_params.reply_topic_name("HDBM_BdArm_Rsp");
    // requester
    rti::request::Requester<HDBI_BdArm_Act_struct, HDBM_BdArm_St_struct>
        requester_hdbi_bdarm_act(requester_params);
    HDBI_BdArm_Act_struct hdbi_bdarm_act_data(0);
    // send_request
    requester_hdbi_bdarm_act.send_request(hdbi_bdarm_act_data);
    // receive data
    // auto replier_hdbm_bdarm_st = requester_hdbi_bdarm_act.receive_replies(MAX_WAIT_TIME);
    bool is_received_hdbm_bdarm_rsp_replies = requester_hdbi_bdarm_act.wait_for_replies(MAX_WAIT_TIME);
    auto replier_hdbm_bdarm_st = requester_hdbi_bdarm_act.take_replies();
    // if (!is_received_hdbm_bdarm_rsp_replies)
    //     std::cout << "[等待 " << requester_params.reply_topic_name().c_str() << " 超时]" << std::endl;
    if (0 < replier_hdbm_bdarm_st.length()) {
        for (const auto &replies : replier_hdbm_bdarm_st) {
            if (!replies.info().valid()) {
                continue;
            }
            // debug info
            std::cout << "[From replier HDBM_BdArm_St_struct: CenterLck_St-"
                      << std::to_string(replies.data().CenterLck_St())
                      << ","
                      << "BodyBglAlarm_St-"
                      << std::to_string(replies.data().BodyBglAlarm_St())
                      << ","
                      << "ExLckReq_St-"
                      << std::to_string(replies.data().ExLckReq_St())
                      << " ]" << std::endl;
        }
        std::cout << "[Request From HDBI_BdArm_Act_struct to HDBM_BdArm_St_struct DONE!]" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    try
    {
        runRequester(domain_id);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}