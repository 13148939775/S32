
#include "DDS_comm.h"
#include "DDSServiceInterfaceIV3.hpp"

#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>

void TestSubscriber() {
    HHT::DDSComm::DDSSubscriberEntity<BodyDomain::BdArm_Get_struct> subscriber("test_ps");
    while (1) {
        auto samples = subscriber.Get();
        for (const auto &sample : samples) {
            if (sample.info().valid()) {
                std::cout << sample.data() << std::endl;
            }
        }
        sleep(1);
    }
}

// waitset
void TestWaitsetSubscriber() {
    rti::core::cond::AsyncWaitSet async_waitset(rti::core::cond::AsyncWaitSetProperty().thread_pool_size(1));
    async_waitset.start();
    HHT::DDSComm::DDSSubscriberEntity<BodyDomain::BdArm_Get_struct> subscriber("test_ps", async_waitset);
    //
    while (1) {
        auto samples = subscriber.Get();
        for (const auto &sample : samples) {
            if (sample.info().valid()) {
                std::cout << sample.data() << std::endl;
            }
        }
        sleep(1);
    }
}

int main(int argc, char **argv) {
    std::cout << "subscribe" << std::endl;
    // TestSubscriber();
    TestWaitsetSubscriber();
    std::cout << "done" << std::endl;

    // 程序退出前调用
    // dds::domain::DomainParticipant::finalize_participant_factory();
    return 0;
}