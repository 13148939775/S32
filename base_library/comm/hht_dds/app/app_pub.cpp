
#include "DDS_comm.h"
#include "DDSServiceInterfaceIV3.hpp"

#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>

void TestPublish() {
    HHT::DDSComm::DDSPublisherEntity<BodyDomain::BdArm_Get_struct> publisher("test_ps");
    BodyDomain::BdArm_Get_struct data;
    sleep(5);
    for (int i = 0; i < 15; ++i) {
        data.constant(static_cast<u_int8_t>(i));
        publisher.Set(data);
        std::cout << "publish data " << i << std::endl;
        publisher.publish();
        sleep(1); //sleep
    }
}

void TestWaitsetPublish() {
    rti::core::cond::AsyncWaitSet async_waitset;
    async_waitset.start();
    HHT::DDSComm::DDSPublisherEntity<BodyDomain::BdArm_Get_struct> publisher("test_ps", async_waitset);
    BodyDomain::BdArm_Get_struct data;
    sleep(5);
    for (int i = 0; i < 15; ++i) {
        data.constant(static_cast<u_int8_t>(i));
        publisher.Set(data);
        std::cout << "publish data " << i << std::endl;
        publisher.SendEvent();
        sleep(1); //sleep
    }
}

int main(int argc, char **argv) {
    std::cout << "publish" << std::endl;
    TestPublish();
    // TestWaitsetPublish();
    std::cout << "done" << std::endl;

    // 程序退出前调用
    // dds::domain::DomainParticipant::finalize_participant_factory();
    return 0;
}