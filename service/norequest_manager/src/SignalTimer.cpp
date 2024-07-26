/*** 
 * @Author: T001291
 * @Date: 2023-10-31 17:47:32
 * @Mailbox: zuren_yuan@human-horizons.com
 * @Version: 0.1
 * @Description: 
 * @FilePath: /s32-Apps/service/norequest_manager/src/SignalTimer.cpp
 * @LastEditors: T001291
 */
#include "SignalTimer.h"
#include "NoReqManager.h"
#include "GenerateNoReq.h"
#include "CommStruct.h"
#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <fstream>

#define BUFSIZE 32

NoReqTimer::NoReqTimer() {}

bool NoReqTimer::CheckTimeout(const unsigned char* buf, int& timeout,std::string vccName) {
        std::lock_guard<std::mutex> lock(mTimerMutex);
        uint8_t bigID = static_cast<uint8_t>(buf[8]);
        uint8_t smallID = static_cast<uint8_t>(buf[9]);
        std::cout <<"bigID = " << static_cast<int>(bigID) << std::endl;
        std::cout <<"smallID = " << static_cast<int>(smallID) << std::endl;
        
        std::pair<uint8_t, uint8_t> key(bigID, smallID);
        auto iter = timerMap.find(key);      
        TimerSignalData& timerdata = *iter -> second;

        if (iter == timerMap.end() || timerMap.empty()) {
            auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::cout << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S") << std::endl;
            std::shared_ptr<TimerSignalData> newTimerData = std::make_shared<TimerSignalData>();
            timerMap[key] = newTimerData;
            newTimerData->timeout = timeout;
            newTimerData->vccname = vccName;
            newTimerData -> lastReceivedTime = std::chrono::high_resolution_clock::now();
            newTimerData -> timer -> RunTimer(buf,newTimerData->timeout,newTimerData->vccname);

        }  else { 
                 //print current time
                auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                std::cout << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S") << std::endl;
                auto nowTime = std::chrono::high_resolution_clock::now();
                auto timeSpan = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime - timerdata.lastReceivedTime);
                
                if (timeSpan.count() >= timeout) {
                    timerMap.erase(iter);
                    GenerateNoReq noreq;
                    noreq.GenerateNoReqComm(buf);
                } else {
                    RunTimer(buf,timeout,vccName);
                    timerdata.lastReceivedTime = std::chrono::high_resolution_clock::now();
                }
              
        }
}

void NoReqTimer::RunTimer(const unsigned char* buf,int timeout,std::string vccname) {
        std::lock_guard<std::mutex> lock(mTimerMutex);
        //time stamp
        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S") << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
}

NoReqTimer::~NoReqTimer() {
    if (mTaskThread.joinable()) {
        mTaskThread.join();
    }
}
