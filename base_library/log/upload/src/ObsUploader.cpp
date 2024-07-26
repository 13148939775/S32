/*
 * @author 001293
 * @Uploading files to OBS interface.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ObsUploader.h"
#include <filesystem>
#include <sstream>
#include <node_log.h>
#include "upload.h"
#include "LogHttpClient.h"
#include "LogUploadFile.h"

OBSConf ObsUploader::mObsconfig_; //静态变量
std::string ObsUploader::timestampOBSDay_ = "";
int64_t ObsUploader::UploadFileToOBS(const UploadFileInfo &fileinfo)
{
    LogHttpClient lhc;
    LogUploadFile lp;
    Request request;
    Response response;
    request.url = mObsconfig_.uploadUrl;
    std::stringstream ss;
    std::filesystem::path filePath(fileinfo.file.filePath);
    timestampOBSDay_ = lp.GetCurrentDateTime(false);
    HHT_LOG(INFO) << "TspUploader:  ObsUploader::GetTimestampOBSDay() " << ObsUploader::GetTimestampOBSDay();
    ss << ObsUploader::mObsconfig_.uploadFolder << "/" << fileinfo.ecuId << "/" << fileinfo.logType << "/" + timestampOBSDay_ << "/" << filePath.filename().string();
    request.form.key = ss.str();
    HHT_LOG(INFO) << "request.form.key: " << request.form.key;
    ss.str("");
    request.form.token = ObsUploader::mObsconfig_.uploadToken;
    request.form.obsExpires = std::to_string(ObsUploader::mObsconfig_.obsFileExpire);
    request.form.file = fileinfo.file.filePath;
    HHT_LOG(INFO) << " fileinfo.file.filePath: " <<  fileinfo.file.filePath;
    [[maybe_unused]] auto ret = lhc.HttpPost(request, response);
    HHT_LOG(INFO) << "UploadFileToOBS HttpPost response: " << response.response;
    HHT_LOG(INFO) << "UploadFileToOBS response.httpCode:" << response.httpCode;
    Upload::GetDeleteSourceFile();
    Upload::GetDeleteCompressedFile();
    if (response.httpCode == 204) {
        lp.AddBakSuffix(fileinfo.file.filePath);
        if (Upload::GetDeleteSourceFile() == true) {
            lp.DeleteSourceFiles(LogUploadFile::GetFilesReady());
        }
        if (Upload::GetDeleteCompressedFile() == true) {
            lp.DeleteCompressedFiles(fileinfo.file.filePath);
        }
        return response.httpCode;
    } else {
        HHT_LOG(ERROR) << "UploadFileToOBS Failed!  response.httpCode : " << response.httpCode;
        return -1;
    }
}

const OBSConf &ObsUploader::GetObsconfig()
{
    return mObsconfig_;
}

void ObsUploader::PrintObsconfig()
{
    HHT_LOG(INFO) << "m_obsconfig.uploadToken: " << mObsconfig_.uploadToken;
    HHT_LOG(INFO) << "m_obsconfig.uploadFolder: " << mObsconfig_.uploadFolder;
    HHT_LOG(INFO) << "m_obsconfig.uploadUrl: " << mObsconfig_.uploadUrl;
    HHT_LOG(INFO) << "m_obsconfig.downloadUrl: " << mObsconfig_.downloadUrl;
    HHT_LOG(INFO) << "m_obsconfig.obsFileExpire: " << mObsconfig_.obsFileExpire;
    HHT_LOG(INFO) << "m_obsconfig.obsTokenExpire: " << mObsconfig_.obsTokenExpire;
}

void ObsUploader::SetObsconfig(const nlohmann::json obsCfg)
{
    mObsconfig_.uploadToken = obsCfg["data"]["uploadToken"].get<std::string>();
    mObsconfig_.uploadFolder = obsCfg["data"]["uploadFolder"].get<std::string>();
    mObsconfig_.uploadUrl = obsCfg["data"]["uploadUrl"].get<std::string>();
    mObsconfig_.downloadUrl = obsCfg["data"]["downloadUrl"].get<std::string>();
    mObsconfig_.obsFileExpire = obsCfg["data"]["obsFileExpires"].get<int>();
    mObsconfig_.obsTokenExpire = obsCfg["data"]["obsTokenExpires"].get<int>();
}

std::string &ObsUploader::GetTimestampOBSDay() {
    LogUploadFile lpTime;
    return timestampOBSDay_;
}