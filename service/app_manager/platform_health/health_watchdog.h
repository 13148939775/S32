#ifndef HEALTH_WATCHDOG_H
#define HEALTH_WATCHDOG_H

#include <atomic>
#include "watchdog.h"
#include <node_log.h>

namespace HHT {
class HealthWatchTask : public Watchdog::TaskIF {
public:
    HealthWatchTask(uint8_t threshold = 5)
      : timeoutCnt_(0),
        threshold_(threshold),
        enabled_(true) 
    { 
        Watchdog::GetInstance()->AddTask(this);
    }

    ~HealthWatchTask()
    { 
        Watchdog::GetInstance()->RemoveTask(this);
    }

    // how about its context ??
    void FeedWdt()  
    {
        timeoutCnt_ = 0;
    }

    void Suspend()
    {
        enabled_ = false;
    }

    void Resume()
    {
        enabled_ = true;
    }

    void Run() override
    {
        if (enabled_ == false) {
            return;
        }
        timeoutCnt_++;
        if (timeoutCnt_ > threshold_) {  // can not be scheduled
            HHT_LOG(ERROR) << " health monitor wdt is triggled";
        }
    }
private:
    std::atomic<uint8_t> timeoutCnt_;
    uint8_t threshold_;
    std::atomic<bool> enabled_;
};
}

#endif /* HEALTH_WATCHDOG_H */
