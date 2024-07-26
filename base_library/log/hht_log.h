/*
 * @author 008196
 * @for application log file entry
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HIPHI_LOG_API_H
#define HIPHI_LOG_API_H

#include <string>
#include <memory>
#include <vector>

#include "logging.h"

#define LOG_LEVEL_INFO google::GLOG_INFO
#define LOG_LEVEL_WARNING google::GLOG_WARNING
#define LOG_LEVEL_ERROR google::GLOG_ERROR
#define LOG_LEVEL_FATAL google::GLOG_FATAL

namespace HHT {
class Logger {
public:
    explicit Logger(const char* name);
    void GetCfgParam(const std::string& para, std::vector<std::string>& value) { };
    void GetLogConfig() { };
    void PutPid() {};


    /*以下glog新增接口*/
    //设置日志存放路径及级别
    void  SetLevel(const int nLogSeverityToConsle,const int  nLogSeverityToFile,const char * szLogFile); 
    void  SetLevel(const int consoleOutput,const bool logFileOutput);
    void  SetLevel(const int consoleAndLogFileLevel);
    void  InitLog(const int  nLogSeverityToConsle, const int  nLogSeverityToFile);

private:
    struct Impl;
    const char* name_;
    std::shared_ptr<Impl> pImpl_;
    int curLevel_;
};
}


#define HHT_LOG(severity) LOG(severity)

#endif /* C2E6EE56_3376_4691_B9B7_E4EE84616ADC */
