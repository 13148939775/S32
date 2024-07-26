/*
 * @author 001293
 * @Uploading the information returned from OBS to TSP.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "TspUploader.h"
#include <string>
#include <sstream>
#include <sys/time.h>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <node_log.h>
#include "upload.h"
#include "TspProxy.h"
#include "LogHttpClient.h"
#include "LogUploadFile.h"
#include "ObsUploader.h"

std::string TspUploader::GetTimeStamps()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    std::stringstream ss;
    ss << ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
    return ss.str();
}

void TspUploader::BuildJson(const std::list<UploadFileInfo> &fileinfos)
{
    LogUploadFile lp;
    value_["vin"] = Upload::GetVin();
    value_["sn"] = Upload::GetSn();
    value_["fileNum"] = 1;

    uint32_t index = 0;
    for (auto &fileinfo : fileinfos)
    {
        std::filesystem::path filePath(fileinfo.file.filePath);
        std::stringstream ss;
        HHT_LOG(INFO) << "TspUploader:  ObsUploader::GetTimestampOBSDay() " << ObsUploader::GetTimestampOBSDay();
        ss << ObsUploader::GetObsconfig().downloadUrl << "/"
           << ObsUploader::GetObsconfig().uploadFolder << "/"
           << fileinfo.ecuId << "/"
           << fileinfo.logType << "/"
           << ObsUploader::GetTimestampOBSDay() << "/"
           << filePath.filename().string();
        value_["ecuLogInfos"][index]["downloadUrl"] = ss.str();
        ss.str("");
        value_["ecuLogInfos"][index]["ecuid"] = fileinfo.ecuId;
        value_["ecuLogInfos"][index]["fileSize"] = fileinfo.file.fileSize;
        value_["ecuLogInfos"][index]["logFileCreateTime"] = fileinfo.file.createTime;
        value_["ecuLogInfos"][index]["logFileName"] = fileinfo.file.fileName;
        if (fileinfo.ecuId == "IDCM" || fileinfo.ecuId == "FSEM") {
            value_["ecuLogInfos"][index]["logType"] = fileinfo.logType;
        }

        value_["ecuLogInfos"][index]["uploadFileName"] = filePath.filename().string();
        index++;
    }
    value_["fileNum"] = index;
}

std::string TspUploader::UploadRecordToTSP(const std::list<UploadFileInfo> &fileinfos)
{
    Request request;
    std::string response;
    std::stringstream ss;
    std::string str;
    ss << Upload::GetLogrtHost() << Upload::GetLogrtServiceName() << Upload::GetLogrtUploadRecordToTsp();
    request.url = ss.str();
    ss.str("");
    request.header.accessKeyId = Upload::GetSn();
    request.header.timestamp = TspUploader::GetTimeStamps();
    HHT_LOG(INFO) << "uploadRecordToTPS request url " << request.url;
    HHT_LOG(INFO) << "uploadRecordToTPS request accessKeyId " << request.header.accessKeyId;
    HHT_LOG(INFO) << "uploadRecordToTPS request timestamp " << request.header.timestamp;
    BuildJson(fileinfos);
    request.data = value_.dump();
    ss << Upload::GetLogrtServiceName() << Upload::GetLogrtUploadRecordToTsp();
    str = ss.str();
    std::string stringToSign = str + "&accessKeyId=" + Upload::GetSn() + "&timestamp=" + request.header.timestamp + "&null&" + request.data;
    TspProxy tp;
    request.header.signature = tp.GetSignature(stringToSign, Upload::GetVin());
    HHT_LOG(INFO) << "uploadRecordToTPS request sign " << request.header.signature;

    LogHttpClient lhc;
    HHT_LOG(INFO) << "----LogUpload::uploadRecordToTPS request " << request.data;
    [[maybe_unused]] auto ret = lhc.HttpPostData(request, response);
    HHT_LOG(INFO) << "-----LogUpload::uploadRecordToTPS response " << response;

    return response;
}