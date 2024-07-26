/*** 
 * @Author: T001291
 * @Date: 2023-11-01 14:10:20
 * @Mailbox: zuren_yuan@human-horizons.com
 * @Version: 
 * @Description: socket test client
 * @FilePath: /s32-Apps/ut_test/service/norequest_manager/noReq_client/Norequest_Client.cpp
 * @LastEditors: T001291
 */

#include <gtest/gtest.h>
#include "socket_udp_client.h"
#include "NoReqManager.h"
#include <iostream>
#include <string>
#include <thread>
#include <iomanip>
#include "nlohmann/json.hpp"

#define PORT 19999
#define IP "127.0.0.1"
#define BUFSIZE 32

TEST(SocketUDPClientUT, Init) {
    SocketUDPClient udpClient;
    unsigned short port = PORT;
    char* ip = IP;

    bool initResult = udpClient.Init(port, ip);
    EXPECT_TRUE(initResult);
}


//不需要发norequest的command
TEST(NoSendNoReqUT, SendPackage) {
    SocketUDPClient udpClient;
    unsigned short port = PORT;
    char* ip = IP;

    bool initResult = udpClient.Init(port, ip);

    EXPECT_TRUE(initResult);
    unsigned char buf[32] = {0x68, 0x68, 0x99, 0x00, 0x05, 0x00, 0x12, 0x00, 0x08, 0x01, 0x01, 0x00, 0x00}; //不发norequest
    int len = sizeof(buf);

    EXPECT_NO_THROW(udpClient.SendPackage(buf, len, ip, port));
}


TEST(SocketUDPClientUT, once_SendPackage_1s) {
    SocketUDPClient udpClient;
    unsigned short port = PORT;
    char* ip = IP;

    bool initResult = udpClient.Init(port, ip);
    EXPECT_TRUE(initResult);

     unsigned char buf[BUFSIZE] = {0x68, 0x68, 0x99, 0x00, 0x05, 0x00, 0x10, 0x00, 0x22, 0x01, 0x03, 0x00, 0x00}; //timeout=1s
    int len = sizeof(buf);

    EXPECT_NO_THROW(udpClient.SendPackage(buf, len, ip, port));
}

TEST(SocketUDPClientUT, once_SendPackage_10s) {
    SocketUDPClient udpClient;
    unsigned short port = PORT;
    char* ip = IP;

    bool initResult = udpClient.Init(port, ip);
    EXPECT_TRUE(initResult);

     unsigned char buf[BUFSIZE] = {0x68, 0x68, 0x99, 0x00, 0x05, 0x00, 0x10, 0x00, 0x34, 0x01, 0x01, 0x00, 0x00}; //timeout=10s
    int len = sizeof(buf);

    EXPECT_NO_THROW(udpClient.SendPackage(buf, len, ip, port));
}


TEST(SocketUDPClientUT, Circulation_SendPackage_1s) {
    SocketUDPClient udpClient;
    unsigned short port = PORT;
    char* ip = IP;

    bool initResult = udpClient.Init(port, ip);
    EXPECT_TRUE(initResult);
    unsigned char buf[BUFSIZ] = {0x68, 0x68, 0x99, 0x00, 0x05, 0x00, 0x10, 0x00, 0x22, 0x01, 0x03, 0x00, 0x00};//timeout=1s
    int len = sizeof(buf);

    for(int i = 0;i < 100; ++i) {
        EXPECT_NO_THROW(udpClient.SendPackage(buf, len, ip, port));
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    }
}


//循环发送超时10s
TEST(SocketUDPClientTest, Circulation_SendPackage_10s) {
    SocketUDPClient udpClient;
    unsigned short port = PORT;
    char* ip = IP;

    bool initResult = udpClient.Init(port, ip);
    EXPECT_TRUE(initResult);
    unsigned char buf[BUFSIZ] = {0x68, 0x68, 0x99, 0x00, 0x05, 0x00, 0x10, 0x00, 0x34, 0x01, 0x01, 0x00, 0x00};//timeout=10s
    int len = sizeof(buf);
     for(int i = 0;i < 100; ++i) {
        EXPECT_NO_THROW(udpClient.SendPackage(buf, len, ip, port));
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    }
}



//循环发送不同信号
TEST(SocketUDPClientTest, Circulation_SendPackage) {
    SocketUDPClient udpClient;
    unsigned short port = PORT;
    char* ip = IP;

    bool initResult = udpClient.Init(port, ip);
    EXPECT_TRUE(initResult);
    unsigned char buf1[BUFSIZE] = {0x68, 0x68, 0x99, 0x00, 0x05, 0x00, 0x10, 0x00, 0x22, 0x01, 0x03, 0x00, 0x00};
    unsigned char buf2[BUFSIZE] = {0x68, 0x68, 0x99, 0x00, 0x05, 0x00, 0x10, 0x00, 0x34, 0x01, 0x01, 0x00, 0x00};
    unsigned char* current_buf = buf1; 
    int len = sizeof(buf1);
    while(true) {
        bool isSend = udpClient.SendPackage(current_buf, len, ip, port);
        EXPECT_TRUE(isSend);
        std::cout << "Sent successful" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Command: " << std::dec << static_cast<int>(current_buf[8]) << "-" << std::dec << static_cast<int>(current_buf[9]) << std::endl;
        for (int i = 0; i < len; ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << (static_cast<int>(current_buf[i]) & 0xff) << " ";
        }
        std::cout << std::endl;

        //切换当前的 buf
         if (current_buf == buf1) {
             current_buf = buf2;
         } else {
             current_buf = buf1;
         }
     }
}
