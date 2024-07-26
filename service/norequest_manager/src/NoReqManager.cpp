/***
 * @Author: T001291
 * @Date: 2023-10-29 23:14:49
 * @Mailbox: zuren_yuan@human-horizons.com
 * @Version: 0.1
 * @Description:
 * @FilePath: /s32-Apps/service/norequest_manager/src/NoRequest.cpp
 * @LastEditors: T001291
 */

#include "socket_udp_server.h"
#include "NoReqManager.h"
#include "SignalTimer.h"
#include "nlohmann/json.hpp"
#include <future>
#include <fstream>
#include <thread>

#define PORT 19999
#define BUFFSIZE 32

NoReqManager::NoReqManager(std::string filename) : mFileName(filename) {
    Init(filename);
}

bool NoReqManager::Init(std::string filename) {
    this -> mFileName = filename;
    SetData(mFileName);
}

bool NoReqManager::SetData(std::string filename) {
    std::ifstream inf(mFileName);
    if (!inf.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
    //解析
     mData = nlohmann::json::parse(inf);
    //序列化
    try {
        mFileName = mData.dump();
        std::cout << "read json successful " << std::endl;
    }   catch (const std::exception &e) {
            std::cerr << "JSON serialization error: " << e.what() << std::endl;
            inf.close();
            return false;
        }
    SetValueMap(mData);
    return true;
}

bool NoReqManager::SetValueMap(nlohmann::json& data) {
    std::unordered_map<int, std::unordered_map<int, std::tuple<int, int, std::string>>> valueMap;
    //std::cout << "data=" <<data <<std::endl;
    int noReqComm = data["norequest"].size();
    std::cout << "noReqCommSum="  << noReqComm << std::endl;
    uint8_t bigID, smallID;
    int timeout, signal;
    std::string vccName;
        for (int i = 0; i < noReqComm; ++i) {
            bigID = data["norequest"][i]["bigID"];
            smallID = data["norequest"][i]["smallID"];
            timeout = data["norequest"][i]["timeout"];
            signal = data["norequest"][i]["signal"];
            vccName = data["norequest"][i]["vccname"];
            mValueMap[bigID][smallID] = std::make_tuple(static_cast<int>(timeout), signal, static_cast<std::string>(vccName));        
        }

    SocketUDPServer udpServer;
    unsigned short port = PORT;
    unsigned char buf[BUFFSIZE] = {"0"};
    size_t len = sizeof(buf); 
    bool isInit = udpServer.Init(port);
    bool isBind = udpServer.Bind();
    if(isInit == false || isBind == false) {
        std::cout << "udp socket failed" << std::endl;
    } 
    while(len) {
          bool received = udpServer.ReceivePackage(buf, len);             
          if(received) {
            std::cout << "received successful" <<std::endl;
            //std::thread([this,buf, len, &valueMap]() {
               IsSendNoReq(buf, len, mValueMap);
        //}).detach();
        } else {
            std::cout << "Failed to receive data package." << std:: endl;
            return false;
        }
    }
    return true;
}

bool NoReqManager::IsSendNoReq(const unsigned char* buf,int len,std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>>& valueMap) {
        std::shared_ptr<NoReqTimer> timer = std::make_shared<NoReqTimer>();
        uint8_t bigID = static_cast<int>(buf[8]);
        uint8_t smallID = static_cast<int>(buf[9]); 
        uint8_t signal = static_cast<int>(buf[10]);

        bool found = false;
        for (const auto& entry1 : valueMap) {
        if (entry1.first == bigID) {
            const auto& innerMap = entry1.second;
            for (const auto& entry2 : innerMap) {
                if (entry2.first == smallID) {
                    std::cout << "send Norequest" << std::endl;
                    int timeout = std::get<0>(entry2.second); // 超时发送时间（1s、10s)
                    std::string vccName = std::get<2>(entry2.second); // 获取第三个元素
                        timer -> CheckTimeout(buf, timeout,vccName);
                    found = true;
                }
            }
        }
    }
        if (found == false){
            std::cout << "not found for bigID or smallID" << std::endl;
            return false;
        }   
}


