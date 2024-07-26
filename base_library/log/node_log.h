/*
 * @author 008196
 * @for application log interface under node manager
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NODE_LOG_H
#define NODE_LOG_H

#include <string>
#include <memory>


#include "node_log_interface.h"
#include "hht_log.h"

namespace HHT {
class NodeLog : public NodeLogInterface<Logger> {
public:
    explicit NodeLog(const char* name);
    std::shared_ptr<Logger> GetLogger() const override;
    const std::string GetLoggerName() const override;

    ~NodeLog() { };

    /**
     * @brief 函数名称 SetLevel
     *
     * @param[in]  参数1  设置console的日志打印级别，比如设置为warnning级别，那么
     *                    console只会打印高于和等于此级别的信息，供输入的参数为，
     *                    LOG_LEVEL_INFO,LOG_LEVEL_WARNING,LOG_LEVEL_ERROR,LOG_LEVEL_FATAL 
     * @param[in]  参数2  true:日志信息打印到日志文件
     *                    false:代表只把之后的日志信息打印到console
     * @param[out] 结果   无
     *
     * @return 返回值的描述
     *
     * @details 注意：如果把参数2设置为false，那么日志信息将会忽略掉console的级别，而直接打印到console
     */
    void  SetLevel(const int consoleOutput,const bool logFileOutput);

    /**
     * @brief 函数名称 SetLevel
     *
     * @param[in]  参数1   初始化consle的打印级别，一般设置LOG_LEVEL_INFO
     *                     
     * @param[in]  参数2   初始化日志文件的打印级别，一般设置LOG_LEVEL_INFO
     *                   
     * @param[out] 结果   无
     *
     * @return 返回值的描述
     *
     * @details  分别初始化console和日志文件的打印级别和指定日志文件的路径
     *          (20230625，根据新需求，不对外暴露设置路径，路径统一写到/home/root/sysbin/log)
     */
    void  SetLevel(const int  nLogSeverityToConsle,const int  nLogSeverityToFile,const char * szLogFile); 

    /**
     * @brief 函数名称 SetLevel
     *
     * @param[in]  参数1   把consle和日志文件的打印级别设置成一个值
     *                     供输入的参数为，LOG_LEVEL_INFO,LOG_LEVEL_WARNING,LOG_LEVEL_ERROR,
     *                     LOG_LEVEL_FATAL   
     * @param[out] 结果   无
     *
     * @return 返回值的描述
     *
     * @details  
     */
    void  SetLevel(const int consoleAndLogFileLevel);

    /**
     * @brief 函数名称 initlog
     *
     * @param[in]  参数1   初始化consle的打印级别，一般设置LOG_LEVEL_INFO
     *                     
     * @param[in]  参数2   初始化日志文件的打印级别，一般设置LOG_LEVEL_INFO
     *                   
     * @param[out] 结果   无
     *
     * @return 返回值的描述
     *
     * @details  分别初始化console和日志文件的打印级别和指定日志文件的
     *           路径(路径全部设置为/home/root/sysbin/log，不能修改为其他路径)
     *
     */
    void  InitLog(const int  nLogSeverityToConsle, const int  nLogSeverityToFile);

private:
    NodeLog();
    const char* name_;
    std::shared_ptr<Logger> loggerPtr_;
};

}

#endif /* NODE_LOG_H */
