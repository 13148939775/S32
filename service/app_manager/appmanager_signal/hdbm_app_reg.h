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

#ifndef HDB_APP_REG_H
#define HDB_APP_REG_H

#include <chrono>
#include <string>
#include <iostream>
#include <sys/time.h>

#include "app_status.h"
#include "hdbm_register.h"
#include <utils/system_time.h>
#include <linux/process.h>
#include <node_log.h>

namespace HHT {

const static std::string DefaultName = "HDBMAppReg";
template <typename T>
class HDBMAppReg {
public:
    HDBMAppReg() = delete;
    explicit HDBMAppReg(T& owner, const std::string& name, std::string path = "", bool isService = false)
      : owner_(owner),
        name_(name),
        absoluteBinaryPath_(path),
        isService_(isService),
        status_(AppStatus::UnInitialized),
        pid_(0),  // when to set ?? 
        startTime_(Utils::GetTimeofDay())
    {
        std::cout << "appIF " << name_ << " is constructe" << std::endl;
        DoRegister(isService);
    }

    ~HDBMAppReg()
    {
        name_ = DefaultName;
        status_ = AppStatus::Stopped;
        HDBMRegister<HDBMAppReg*>::GetInstance().UnRegister(owner_, isService_);
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
    
    void DoRegister(bool isService)
    {
        std::cout << "appIF " << name_ << " is registered" << std::endl;
        HDBMRegister<HDBMAppReg*>::GetInstance().Register(owner_, isService_);
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
    //signalHandler()
    //{
        // term quit

        // suspend
     //   app.DoSuspend(); 
      //  reportStatus();
    //}
    //Report() { }
private:
    std::string name_;
    std::string absoluteBinaryPath_;
    bool isService_;  // 服务应先启动，比如诊断
    AppStatus status_;
    OSAbstraction::ProcessId pid_;     // for case restart serveral times, how to set
    timeval startTime_;
    timeval stopTime_;
    T owner_;
};
}

#endif /* APP_BASE_H */
