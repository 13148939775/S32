/*
 * @author 008196
 * @for application log file implement
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "node_log.h"
#include "hht_log.h"

namespace HHT {
    NodeLog::NodeLog(const char* name) 
      :name_(name),
       loggerPtr_(std::make_shared<Logger>(name))
    {
    }
    
    std::shared_ptr<Logger> NodeLog::GetLogger() const
    {
        return loggerPtr_;
    }
    
    const std::string NodeLog::GetLoggerName() const
    {
        return name_;
    }


    void  NodeLog::SetLevel(const int consoleOutput,const bool logFileOutput)
    {
        loggerPtr_->SetLevel(consoleOutput,logFileOutput);
    }
    void NodeLog::SetLevel(const int  nLogSeverityToConsle,const int  nLogSeverityToFile,const char * szLogFile)
    {
        loggerPtr_->SetLevel( nLogSeverityToConsle, nLogSeverityToFile,szLogFile);
    }
    void NodeLog::SetLevel(const int consoleAndLogFileLevel)
    {
        loggerPtr_->SetLevel(consoleAndLogFileLevel);
    }
    void NodeLog::InitLog(const int  nLogSeverityToConsle,const int  nLogSeverityToFile)
    {
        loggerPtr_->InitLog( nLogSeverityToConsle, nLogSeverityToFile);
    }
}
