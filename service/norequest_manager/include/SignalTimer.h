/*** 
 * @Author: T001291
 * @Date: 2023-10-31 17:46:59
 * @Mailbox: zuren_yuan@human-horizons.com
 * @Version: 0.1
 * @Description: 
 * @FilePath: /s32-Apps/service/norequest_manager/include/SignalTimer.h
 * @LastEditors: T001291
 */

#ifndef SIGNAL_TIMER_H
#define SIGNAL_TIMER_H

#include "NoReqManager.h"
#include "CommStruct.h"
#include "GenerateNoReq.h"
#include <cstdint>
#include <map>
#include <unordered_set>
#include <thread>
#include <mutex>
#include <vector>
#include "nlohmann/json.hpp"

class NoReqTimer;

struct TimerSignalData {
    TimerSignalData() : timer(std::make_shared<NoReqTimer>()), 
    timeout(0), 
    vccname(""),
    lastReceivedTime(), 
    isLastReceived(false) {}
    
    int timeout;
    std::string vccname;
    std::shared_ptr<NoReqTimer> timer;
    std::chrono::high_resolution_clock::time_point lastReceivedTime;
    bool isLastReceived;
};

class NoReqTimer {
public:
    NoReqTimer();
    bool CheckTimeout(const unsigned char* buf, int& timeout,std::string vccname);
    void RunTimer(const unsigned char* buf,int timeout,std::string vccname);
    ~NoReqTimer();
    
private:
    std::mutex mTimerMutex;
    std::map<std::pair<uint8_t, uint8_t>, std::shared_ptr<TimerSignalData>> timerMap;
    std::thread mTaskThread;
};

#endif