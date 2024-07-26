/*
 * @file app_manager.h
 * @author 008196
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HDB_APP_BASE_H
#define HDB_APP_BASE_H

#include <chrono>
#include <string>
#include <iostream>
#include <sys/time.h>

#include "app_status.h"
#include "hdbm_register.h"
#include <utils/system_time.h>
#include <linux/process.h>

namespace HHT {

const static std::string DefaultName = "HDBMApp";
class HDBMApp {
public:
    explicit HDBMApp(const std::string& name, std::string path = "", bool isService = false, const int bootTimeLimit=0)
      : name_(name),
        absoluteBinaryPath_(path),
	bootTimeLimit_(bootTimeLimit),
        isService_(isService),
        status_(AppStatus::UnInitialized),
        pid_(0),  // when to set ?? 
        startTime_(Utils::GetTimeofDay())
    {
        std::cout << "app " << name_ << " is constructed" << std::endl;
        HDBMRegister<HDBMApp*>::GetInstance().Register(this, isService_);
    }

    ~HDBMApp()
    {
        name_ = DefaultName;
        status_ = AppStatus::Stopped;
        HDBMRegister<HDBMApp*>::GetInstance().UnRegister(this, isService_);
        stopTime_ = Utils::GetTimeofDay();
    }

    void SetStatus(AppStatus st)
    {
        status_ = st;
    }

    void SetPid(OSAbstraction::ProcessId pid)
    {
        pid_ = pid;
    }

    const OSAbstraction::ProcessId GetPid() const
    {
        return pid_;
    }

    virtual bool DoInit()
    {
        status_ = AppStatus::Initialized;
        return true;
    }

    virtual bool DoStart() 
    {    
        status_ = AppStatus::Started;
        std::cout << "app " << name_ << " is started" << std::endl;
        return true; 
    }

    virtual bool DoStop() 
    { 
        status_ = AppStatus::Normal_Stopped;  
        return true; 
    }

    const std::string& GetName() const
    {
        return name_;
    }
 
    const std::string& GetPath() const
    {
        return absoluteBinaryPath_;
    }

    const AppStatus GetStatus() const
    {
        return status_;
    }

    const int& GetBootTimeLimit() const
    {
        return bootTimeLimit_;
    }


    virtual void ReportEvent() { };
private:
    std::string name_;
    std::string absoluteBinaryPath_;
    int bootTimeLimit_=0;
    bool isService_;  // 服务应先启动，比如诊断
    AppStatus status_;
    OSAbstraction::ProcessId pid_;     // for case restart serveral times, how to set
    std::set<HDBMApp> listerners_;
    timeval startTime_;
    timeval stopTime_;
};
}

#endif /* APP_BASE_H */
