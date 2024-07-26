#include <iostream>
#include <thread>
#include <gtest/gtest.h>
#include "DDS_comm.h"
#include "DDSServiceInterfaceIV3.hpp"

using namespace ::testing;
using namespace HHT::DDSComm;
using namespace BodyDomain;

int res_ = -1;
void TestPublish() {
    HHT::DDSComm::DDSPublisherEntity<BodyDomain::BdArm_Get_struct> publisher(1, "test_ps");
    BodyDomain::BdArm_Get_struct data;
    sleep(5);
    for (int i = 0; i < 10; ++i) {
        data.constant(static_cast<u_int8_t>(i));
        publisher.Set(data);
        std::cout << "publish data " << i << std::endl;
        publisher.publish();
        sleep(1); //sleep
    }
}

// waitset
void TestWaitsetSubscriber() {
    rti::core::cond::AsyncWaitSet async_waitset(rti::core::cond::AsyncWaitSetProperty().thread_pool_size(1));
    async_waitset.start();
    HHT::DDSComm::DDSSubscriberEntity<BodyDomain::BdArm_Get_struct> subscriber(1, "test_ps", async_waitset);
    //
    for (int i = 0; i < 20; ++i) {
        auto samples = subscriber.Get();
        for (const auto &sample : samples) {
            if (sample.info().valid()) {
                std::cout << sample.data() << std::endl;
                res_ = sample.data().constant();
            }
        }

        sleep(1);
    }
}

TEST(DdsPub2, PubSub2) {
    std::thread pub_ = std::thread(TestPublish);
    std::thread sub_ = std::thread(TestWaitsetSubscriber);

    sub_.join();
    pub_.join();

    EXPECT_TRUE(res_ != -1);
}