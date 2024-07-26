/*
 * @author 008196
 * @for application log file entry
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "hht_log.h"
#include <filesystem>


namespace HHT {

struct Logger::Impl {
public:
    explicit Impl(const char* name)
             :appName_(static_cast<std::string>(name))
    {
        google::InitGoogleLogging(name);
    }

    ~Impl()
    {
        google::ShutdownGoogleLogging();
    }
    

    /*以下glog新增接口*/
    void  SetLevel(const int consoleOutput,const bool logFileOutput)
    {
        google::SetStderrLogging(consoleOutput);
        FLAGS_logtostderr= !logFileOutput;
    }

    //20230625根据新需求不对用户开发自定义存放log路径，log路径全部指定为/home/root/sysbin/log
    //20230921根据新需求，在日志基本目录下，需要创建应用程序名字的文件夹，每个应用的日志文件存放在自己对应的文件夹中
    void SetLevel(const int  nLogSeverityToConsle, const int  nLogSeverityToFile, const char * szLogFile)
    {
       //the symbol / at the end of string is a must,otherwise the new path won't work
       std::string logSavePathOfApps = logFileBasePath_ + appName_ + "/";
       if (!std::filesystem::exists(logSavePathOfApps)) {
           if (!std::filesystem::create_directory(logSavePathOfApps)) {
               return;
           }
       }
        google::SetStderrLogging(nLogSeverityToConsle);
        google::SetLogDestination(nLogSeverityToFile,logSavePathOfApps.c_str());
    }

    void SetLevel(const int consoleAndLogFileLevel)
    {
        FLAGS_minloglevel = consoleAndLogFileLevel;
    }

    //20230625根据新需求不对用户开发自定义存放log路径，log路径全部指定为/home/root/sysbin/log
    //20230921根据新需求，在日志基本目录下，需要创建应用程序名字的文件夹，每个应用的日志文件存放在自己对应的文件夹中
    void InitLog(const int  nLogSeverityToConsle, const int  nLogSeverityToFile)
    {
        //the symbol / at the end of string is a must,otherwise the new path won't work
        std::string logSavePathOfApps = logFileBasePath_ + appName_ + "/";
        if (!std::filesystem::exists(logSavePathOfApps)) {
           if (!std::filesystem::create_directory(logSavePathOfApps)) {
               return;
           }
        }
        google::SetStderrLogging(nLogSeverityToConsle);
        google::SetLogDestination(nLogSeverityToFile, logSavePathOfApps.c_str());
    }
private:
    const std::string logFileBasePath_ = "/home/root/log/";
    std::string appName_;
};

 Logger::Logger(const char* name)
    :name_(name),
     pImpl_(std::make_shared<Impl>(name))
    {
    };


/*glog新增接口*/
void  Logger::SetLevel(const int consoleOutput,const bool logFileOutput)
{
     pImpl_->SetLevel( consoleOutput, logFileOutput);
}

void Logger::SetLevel(const int  nLogSeverityToConsle,const int  nLogSeverityToFile,const char * szLogFile)
{
     pImpl_->SetLevel( nLogSeverityToConsle, nLogSeverityToFile,szLogFile);
}
void Logger::SetLevel(const int consoleAndLogFileLevel)
{
    pImpl_->SetLevel(consoleAndLogFileLevel);
}

void Logger::InitLog(const int  nLogSeverityToConsle, const int  nLogSeverityToFile)
{
    pImpl_->InitLog( nLogSeverityToConsle, nLogSeverityToFile);
}


}

