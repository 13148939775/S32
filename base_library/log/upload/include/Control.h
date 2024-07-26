/*
 * @author 001293
 * @Control the entire log upload process, including the frequency.
 * @version 1.0
 * @date 2023-07 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include "nlohmann/json.hpp"
#include "TspDownloader.h"

class Control
{
public:
    void LoadConfig();   //读取json配置文件中的信息(url等)
    bool ScheduleUpload();  //上传总控制函数
    void SleepInterval(); //睡眠一定时间(控制日志上传频率)

    //解析TSP返回的日志上传规则json串,获得上传频率参数
    void ParseJson(const std::string &responseRule_);
    void BuildTree(const nlohmann::json &data);
    void ShowRuleJson();

    EcuLogUploadRule GetEcuLogUploadRule();
    void ReadVinSnOTA();

private:
    std::string responseRule_; //用于接收从云端返回的日志上传规则json串
    EcuLogUploadRule ecuLogUploadRule_;
};
