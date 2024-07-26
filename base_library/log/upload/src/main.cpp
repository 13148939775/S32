/*
 * @author 001293
 * @for application log interface under node manager
 * @version 1.0
 * @date 2023-05 ~ 2023-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <node_log.h>
#include <thread>
#include <atomic>
#include <thread>
#include <chrono>
#include "upload.h"
#include "Control.h"
#include "UploadPretend.h"
#include "LogUploadFile.h"

void LogUpload(std::atomic<bool>& running) {
    int fileNum = 0;    //设置模拟车端文件的名称
    UploadPretend pretend;
    Upload upload;
    Control control;
    LogUploadFile logUploadFile;
    while (running) {
        // control.LoadConfig();
        control.ScheduleUpload();
        //睡眠一定时间(控制日志上传频率)
        control.SleepInterval();

        if(upload.GetFlagTest() == true) {
            //模拟车端不断加入新的日志文件
            std::string fileName;
            fileName = std::to_string((++fileNum)); //创建的新文件的名称
            HHT_LOG(INFO) << "Upload::GetMaxSizeInGB(): " << Upload::GetMaxSizeInGB();
            HHT_LOG(INFO) << "Upload::GetFileCount(): " << Upload::GetFileCount();
            logUploadFile.MonitorDirectorySize(Upload::GetMaxSizeInGB(),Upload::GetFileCount(),Upload::GetSrcFolder());
            pretend.CreateFile(upload.GetSrcFolder(),fileName);
        } else {
            //处理实际车端新文件情况
            //模拟车端不断加入新的日志文件
            std::string fileName;
            fileName = std::to_string((++fileNum)); //创建的新文件的名称

            logUploadFile.MonitorDirectorySize(Upload::GetMaxSizeInGB(),Upload::GetFileCount(),Upload::GetSrcFolder());
            pretend.CreateFile(upload.GetSrcFolder(),fileName);
        }
    }
}

int main(int argc, char **argv)
{
    HHT::NodeLog node("logUpload");
    node.InitLog(LOG_LEVEL_INFO, LOG_LEVEL_INFO);
    node.SetLevel(LOG_LEVEL_WARNING,true);

    LogUploadFile timeCheck;
    bool timeFlag = true;
    // 获取程序开始的时间点
    auto timeCheckStart = std::chrono::high_resolution_clock::now();
    int timeCheckCount = 0;
    std::string checkTimeNodes = "2023";
    while(timeFlag) {
        ++timeCheckCount;
        HHT_LOG(INFO) << "the " << timeCheckCount << "th to check time" ;
        std::string timestamp = timeCheck.GetCurrentDateTime(true);
        if (timestamp.compare(0, 4, checkTimeNodes) != 0) {
            HHT_LOG(INFO) << "The timestamp is NOT from " << checkTimeNodes ;
            auto timeCheckEnd = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(timeCheckEnd - timeCheckStart);
            std::string durationString = std::to_string(duration.count());
            HHT_LOG(INFO) << "It has taken  " << durationString << " seconds to check the time";
            std::this_thread::sleep_for(std::chrono::seconds(5));
        } else {
            HHT_LOG(ERROR) << "The timestamp is from " << checkTimeNodes ;
            break;
        }
    }

    std::atomic<bool> running(true);    //确保在多线程环境下的线程安全性

    std::thread uploadThread(LogUpload,std::ref(running));

    // 主线程执行其他任务

    // 等待上传线程完成
    uploadThread.join();
    
    return 0;
}