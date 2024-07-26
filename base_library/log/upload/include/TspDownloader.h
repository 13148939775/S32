/*
 * @author 001293
 * @Requesting log upload rules interface.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TSP_DOWNLOADER_H
#define TSP_DOWNLOADER_H
#include <string>
#include <map>
#include "LogHttpClient.h"
#include "ObsUploader.h"
#include "TspProxy.h"

//ECU 域日志开关 EcuLogSwitch
struct EcuLogSwitch {
    int enable = 1; //是否采集 0：不采集，1：采集；默认值：1
    std::string level = "INFO";  //日志级别 INFO,ERROR；默认值：INFO
};

//ECU 日志规则 EcuLogUploadRule
struct EcuLogUploadRule {
    int fileSize;   //接收文件最大值 单位 Byte
    int IntervalTime = 10;   //文件采集间隔时长 单位分钟 默认是10min
    std::string rangeTimeStart; //文件采集开始时间 2019120912
    std::string rangeTimeEnd;   //文件采集结束时间 2019120916
    std::map<std::string,EcuLogSwitch> config;  //域日志开关 key:ecuid
    std::string configUpdateTime;   //域日志规则更新时间 2021-8-13 12:00:00
};

class TspDownloader {
public:
    std::string DownloadCfgFromTSP();   //获取日志日志上传规则
    bool GetUploadConfFromTSP();    //获取OBSConfg OBS配置参数
    bool ParseObsCfg(std::string response); //解析TSP返回的OBS相关配置json

    std::string GetUploadConfResponse();

private:
    std::string uploadConfResponse_;
};

#endif