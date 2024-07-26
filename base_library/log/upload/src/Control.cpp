/*
 * @author 001293
 * @Control the entire log upload process, including the frequency.
 * @version 1.0
 * @date 2023-07 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Control.h"
#include <thread>
#include <node_log.h>
#include "upload.h"
#include "TspDownloader.h"
#include "TspUploader.h"
#include "LogUploadFile.h"

void Control::ReadVinSnOTA() {
    Upload upload;
    int ret = -1;
    int count = 1;
    while (ret != 0) {
        HHT_LOG(INFO) << "try " << count << "th time to read Vin/Sn";
        ret = upload.ManageVinSnOTAData();
        if (ret == -1) {
            int reTryTime = 30;
            HHT_LOG(ERROR) << "Read Vin/Sn failed, it will be retried after " << reTryTime << "s " ;
            std::this_thread::sleep_for(std::chrono::seconds(reTryTime)); 
        }
    }
}

void Control::LoadConfig()
{
    //获取json配置，主要是关于请求url
    Upload upload;
    LogUploadFile logUploadFile;
    upload.SetConfigPath();
    ReadVinSnOTA();
    HHT_LOG(INFO) << "upload.GetVin(): " << upload.GetVin();
    HHT_LOG(INFO) << "upload.GetSn(): " << upload.GetSn();
    std::string configPath = upload.GetConfigPath();
    upload.ParseJson(configPath);
    upload.SetSrcFolder();
    logUploadFile.SetlevelLogFilePathLast();
}

void Control::ParseJson(const std::string &responseRule_)
{
    nlohmann::json data = nlohmann::json::parse(responseRule_); 
    std::string s = data.dump();
    BuildTree(data);
}

void Control::BuildTree(const nlohmann::json &data)
{
    std::string msgGet = data["msg"];
    HHT_LOG(INFO) << "ecuLogUploadRule msgGet: " << msgGet;
    if (msgGet == "SUCCESS") {
        ecuLogUploadRule_.fileSize = data["data"]["fileSize"].get<int>();
        ecuLogUploadRule_.rangeTimeStart = data["data"]["rangeTimeStart"];
        ecuLogUploadRule_.rangeTimeEnd = data["data"]["rangeTimeEnd"];
        ecuLogUploadRule_.configUpdateTime = data["data"]["configUpdateTime"];

        // 解析config字段
        for (const auto& item : data["data"]["config"].items()) {
            std::string ecuid = item.key();
            EcuLogSwitch ecuLogSwitch;
            ecuLogSwitch.enable = item.value()["enable"].get<int>();
            ecuLogSwitch.level = item.value()["level"].get<std::string>();
            ecuLogUploadRule_.config[ecuid] = ecuLogSwitch;
        }
    } else {
        HHT_LOG(ERROR) << "Please check that VinSn is right/valid";
        HHT_LOG(ERROR) << "Replace the file in /home/root/ota with the correct file";
        HHT_LOG(ERROR) << "The program will retry to read VinSn after 1min";
        std::this_thread::sleep_for(std::chrono::minutes(1));
        ScheduleUpload();
    }
}

void Control::ShowRuleJson() {
    HHT_LOG(INFO) << "ecuLogUploadRule_.fileSize: " << ecuLogUploadRule_.fileSize;
    HHT_LOG(INFO) << "ecuLogUploadRule_.rangeTimeStart: " << ecuLogUploadRule_.rangeTimeStart;
    HHT_LOG(INFO) << "ecuLogUploadRule_.rangeTimeEnd: " << ecuLogUploadRule_.rangeTimeEnd;
    HHT_LOG(INFO) << "ecuLogUploadRule_.configUpdateTime: " << ecuLogUploadRule_.configUpdateTime;
    for (const auto& item : ecuLogUploadRule_.config)
    {
        HHT_LOG(INFO) << "ECUID: " << item.first;
        HHT_LOG(INFO) << "Enable: " << item.second.enable;
        HHT_LOG(INFO) << "Level: " << item.second.level;
        HHT_LOG(INFO) << std::endl;
    }
}

bool Control::ScheduleUpload()
{
    HHT_LOG(INFO) << " ";
    HHT_LOG(INFO) << " ";
    HHT_LOG(INFO) << " ";
    HHT_LOG(INFO) << "ScheduleUpload started:";
    LoadConfig();

    TspDownloader tspDownloader;
    LogUploadFile logUploadFile;
    ObsUploader obsUploader;
    HHT_LOG(INFO) << "";
    HHT_LOG(INFO) << "----DownloadCfgFromTSP: get uploadRule from TSP----";
    responseRule_ = tspDownloader.DownloadCfgFromTSP();
    try {
        ParseJson(responseRule_);
    } catch (const std::exception& e) {
        HHT_LOG(ERROR) << "Catch exception: " << e.what();
    }
    // ShowRuleJson();

    HHT_LOG(INFO) << "";
    HHT_LOG(INFO) << "----GetUploadConfFromTSP: get OBSconfig from TSP----";
    tspDownloader.GetUploadConfFromTSP();

    HHT_LOG(INFO) << "";
    HHT_LOG(INFO) << "----UploadFileToOBS: upload files to OBS----";
    UploadFileInfo zipFileInfo = logUploadFile.GetUploadFileList();
    obsUploader.UploadFileToOBS(zipFileInfo);

    std::list<UploadFileInfo> mRecordUploadFileList;
    mRecordUploadFileList.clear();
    mRecordUploadFileList.push_back(zipFileInfo);

    HHT_LOG(INFO) << "";
    HHT_LOG(INFO) << "----UploadRecordToTSP: upload OBS files information to TSP----";
    TspUploader tspUploader;
    std::string data = tspUploader.UploadRecordToTSP(mRecordUploadFileList);
    //解析TSP响应的json串
    auto json = nlohmann::json::parse(data);
    std::string code;
    std::string msg;
    code = json["code"].get<std::string>();
    msg = json["msg"].get<std::string>();
    if (code == "000000" && msg == "SUCCESS") {
        return true;
    } else {
        return false;
    } 
}

EcuLogUploadRule Control::GetEcuLogUploadRule()
{
    return ecuLogUploadRule_;
}

void Control::SleepInterval()
{
    // 获取当前时间(表示自 1970 年 1 月 1 日 00:00:00 UTC 开始至今的时间)
    auto now = std::chrono::system_clock::now();

    // 计算下一个调用时间
    auto next = now;
    next = now + std::chrono::seconds(Upload::GetIntervalTime()); 
    
    // 将下一个调用时间转换为时间戳(1970 年 1 月 1 日至当前时间所经过的秒数)，并输出
    auto nextTimestamp = std::chrono::system_clock::to_time_t(next);
    HHT_LOG(INFO) << "";
    HHT_LOG(INFO) << "";
    HHT_LOG(INFO) << "";
    HHT_LOG(INFO) << "Next call at: " << std::ctime(&nextTimestamp);

    // 计算需要休眠的时间
    auto sleepTime = std::chrono::duration_cast<std::chrono::seconds>(next - now);

    // 等待
    std::this_thread::sleep_for(sleepTime);
}
