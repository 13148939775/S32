#include <memory>
#include <string>
#include <iostream>

#include <gtest/gtest.h>

#include <cpp/server/server_comm_kit.h>
#include <cpp/client/client_comm_kit.h>
#include <cpp/enum_event.h>

using namespace ::testing;

class PublisherTest : public Test{
public:
    PublisherTest()
      : client_(new HHT::ClientComm("test-client", HHT::ProtocolType::PROTOCOL_ICEORYX_DDS)),
        server_(new HHT::ServerComm("test-server", HHT::ProtocolType::PROTOCOL_ICEORYX_DDS))
    { }

    void SetUp()
    {

    }

    void TearDown()
    { }

//private:

    int res_{-1};
    std::unique_ptr<HHT::ClientComm> client_{nullptr};
    std::unique_ptr<HHT::ServerComm> server_{nullptr};
};

TEST_F(PublisherTest, Pub)
{
    ::testing::Test::RecordProperty("TEST_ID", "38d0779a-1fd5-407d-95aa-2cf24fcf3a09");

    std::thread work1 = std::thread([this]() {
      bool exit = false;
      res_ = client_->Wait(HHT::Event::EVENT_DOIP_ONLINE_EVENT, 20);
      if (res_ != -1) {
        exit = true;
      }
    });

    std::thread work2 = std::thread([this]() {
        bool exit = false;
        int cnt = 0;
        while (exit == false) {
            server_->Pub(HHT::Event::EVENT_DOIP_ONLINE_EVENT);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cnt++;
            if (cnt > 3) {
              exit = true;
            }
        }
    });
    work1.join();
    work2.join();
    EXPECT_TRUE(res_ != -1);
}

TEST_F(PublisherTest, DiscoveryService)
{

}