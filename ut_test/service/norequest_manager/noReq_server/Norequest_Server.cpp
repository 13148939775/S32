/*** 
 * @Author: T001291
 * @Date: 2023-11-01 14:09:36
 * @Mailbox: zuren_yuan@human-horizons.com
 * @Version: 0.1
 * @Description: socket test server
 * @FilePath: /s32-Apps/ut_test/service/norequest_manager/noReq_server/Norequest_Server.cpp
 * @LastEditors: T001291
 */

#include <gtest/gtest.h>
#include "socket_udp_server.h"
#include "NoReqManager.h"
#include "SignalTimer.h"
#include <iostream>

#define BUFSIZE 32
#define PORT 19999


//单元测试用例
class TestNoReqManager : public NoReqManager {
public:
    TestNoReqManager()
    { }

    ~TestNoReqManager()
    { }
};

class TestSignalTimer : public NoReqTimer {
public:
    TestSignalTimer()
    { }

    ~TestSignalTimer()
    { }
};

//json初始化
TEST(NoReqManager, Init)
{
    std::string fliename = "../../../../../service/norequest_manager/noReqList.json";
    unsigned char buf[BUFSIZE] = {0x68, 0x68, 0x00, 0x00, 0x05, 0x00, 0x10, 0x00, 0x22, 0x01, 0x03, 0x00, 0x00};//超时1s
    int len = sizeof(buf);
   
    TestNoReqManager noReq;
    bool initResult = noReq.Init(fliename);

    EXPECT_TRUE(initResult);

    nlohmann::json data;
    bool getDataResult = noReq.SetValueMap(data);

    EXPECT_TRUE(getDataResult);
    std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>> valuMap;
    bool isSendNoReq = noReq.IsSendNoReq(buf,len,valuMap);

    EXPECT_TRUE(isSendNoReq);
}

//1、不需要发送norequeset
TEST(NoReqManager,NoSendNoReq)
{
    std::string filename = "../../../../../service/norequest_manager/noReqList.json";
    NoReqManager noreq;
    unsigned char buf[BUFSIZE] = {0x68, 0x68, 0x99, 0x00, 0x05, 0x00, 0x12, 0x00, 0x08, 0x01, 0x01, 0x00, 0x00}; //不发norequest
    int len = sizeof(buf);
    std::string vccname = "ReturnPUnlock_Rsp";//车身防盗设置反馈

    bool initResult = noreq.Init(filename);
    EXPECT_TRUE(initResult);
    std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>> valueMap;

    bool isSendNoReq = noreq.IsSendNoReq(buf,len,valueMap);

    EXPECT_FALSE(isSendNoReq);//测试通过
    
}

//2、需要发norequest/timeout=1s
TEST(NoReqUT,Once_SendNoReq_1)
{
    std::string filename = "../../../../../service/norequest_manager/noReqList.json";
    NoReqManager noreq;
    unsigned char buf[BUFSIZE] = {0x68, 0x68, 0x00, 0x00, 0x05, 0x00, 0x10, 0x00, 0x22, 0x01, 0x03, 0x00, 0x00}; //发norequest
    int len = sizeof(buf);
    std::string vccname;

    bool initResult = noreq.Init(filename);
    EXPECT_TRUE(initResult);
    std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>> valueMap;

    bool isSendNoReq = noreq.IsSendNoReq(buf,len,valueMap);

    EXPECT_TRUE(isSendNoReq);
    TestSignalTimer timer;
    int timeout;
    ASSERT_NO_THROW({
        timer.CheckTimeout(buf, timeout,vccname);
    });
}

//3、需要发norequest/timeout=10s
TEST(NoReqUT,Once_SendNoReq_10)
{
    std::string filename = "../../../../../service/norequest_manager/noReqList.json";
    NoReqManager noreq;
    unsigned char buf[BUFSIZE] = {0x68, 0x68, 0x00, 0x00, 0x05, 0x00, 0x10, 0x00, 0x34, 0x01, 0x03, 0x00, 0x00}; //发norequest10s
    int len = sizeof(buf);
    std::string vccname;

    bool initResult = noreq.Init(filename);
    EXPECT_TRUE(initResult);
    std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>> valueMap;

    bool isSendNoReq = noreq.IsSendNoReq(buf,len,valueMap);

    EXPECT_TRUE(isSendNoReq);
    TestSignalTimer timer;
    int timeout;
    ASSERT_NO_THROW({
        timer.CheckTimeout(buf, timeout,vccname);
    });
    
}

//4、不需要发norequest/循环
TEST(NoReqUT, Loop_NoSendNoReq) {
    std::string filename = "../../../../../service/norequest_manager/noReqList.json";
    NoReqManager noreq;
    unsigned char buf[BUFSIZE] = {0x68, 0x68, 0x99, 0x00, 0x05, 0x00, 0x12, 0x00, 0x08, 0x01, 0x01, 0x00, 0x00}; //不发norequest
    int len = sizeof(buf);

    bool initResult = noreq.Init(filename);

    EXPECT_TRUE(initResult);
    for (int i = 0 ;i < 100; ++i) {
        std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>> valueMap;
        bool isSendNoReq = noreq.IsSendNoReq(buf,len,valueMap);
        EXPECT_FALSE(isSendNoReq);//测试通过
    }
}

//5、需要发norequest/timeout=1s/循环
TEST(NoReqUT,Loop_SendNoReq_1)
{
    std::string filename = "../../../../../service/norequest_manager/noReqList.json";
    NoReqManager noreq;
    unsigned char buf[BUFSIZE] = {0x68,0x68,0x99,0x00,0x05,0x00,0x10,0x00,0x02,0x02,0x02,0x00,0x00}; //发norequest
    int len = sizeof(buf);
    std::string vccname;

    bool initResult = noreq.Init(filename);
    EXPECT_TRUE(initResult);
    std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>> valueMap;
    for (int i = 0 ;i < 100; ++i) {
        bool isSendNoReq = noreq.IsSendNoReq(buf,len,valueMap);

        EXPECT_TRUE(isSendNoReq);
        TestSignalTimer timer;
        int timeout;
        ASSERT_NO_THROW({
            timer.CheckTimeout(buf, timeout,vccname);
        });
    }
}

//6、需要发norequest/timeout=10s/循环
TEST(NoReqUT,Loop_SendNoReq_10)
{
    std::string filename = "../../../../../service/norequest_manager/noReqList.json";
    NoReqManager noreq;
    unsigned char buf[BUFSIZE] = {0x68,0x68,0x99,0x00,0x05,0x00,0x10,0x00,0x17,0x03,0x01,0x00,0x00}; //发norequest
    int len = sizeof(buf);
    std::string vccname;

    bool initResult = noreq.Init(filename);
    EXPECT_TRUE(initResult);
    std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>> valueMap;
    for (int i = 0 ;i < 100; ++i) {
        bool isSendNoReq = noreq.IsSendNoReq(buf,len,valueMap);

        EXPECT_TRUE(isSendNoReq);
        TestSignalTimer timer;
        int timeout;
        ASSERT_NO_THROW({
            timer.CheckTimeout(buf, timeout,vccname);
        });
    }
}

//7、需要发norequest/timeout=1/10s/循环
TEST(NoReqUT,Once_SendNoReq_1and10)
{
    std::string filename = "../../../../../service/norequest_manager/noReqList.json";
    NoReqManager noreq;
    unsigned char buf1[BUFSIZE] = {0x68,0x68,0x99,0x00,0x05,0x00,0x10,0x00,0x02,0x02,0x02,0x00,0x00}; //1s
    unsigned char buf2[BUFSIZE] = {0x68,0x68,0x99,0x00,0x05,0x00,0x10,0x00,0x17,0x03,0x01,0x00,0x00}; //10s
    int len = sizeof(buf1);
    unsigned char* buf =buf1;
    std::string vccname;

    bool initResult = noreq.Init(filename);
    EXPECT_TRUE(initResult);
    std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>> valueMap;
    for (int i = 0 ;i < 100; ++i) {
        bool isSendNoReq = noreq.IsSendNoReq(buf,len,valueMap);

        EXPECT_TRUE(isSendNoReq);
        TestSignalTimer timer;
        int timeout;
        ASSERT_NO_THROW({
            timer.CheckTimeout(buf, timeout,vccname);
        });
        if (buf == buf1) {
            buf =buf2;
        } else {
            buf = buf1;
        }
    }
}


// 添加测试用例

