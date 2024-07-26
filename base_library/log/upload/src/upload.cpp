/*
 * @author 001293
 * @Loading configuration file-related content.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "upload.h"
#include <fstream>
#include <node_log.h>

std::string LogUrl::logrtHost_ = "";
std::string LogUrl::logrtServiceName_ = "";
std::string LogUrl::logrtDownloadUploadRule_ = "";
std::string LogUrl::logrtGetObsPath_ = "";
std::string LogUrl::logrtUploadRecordToTsp_ = "";

std::string VinSn::mVin_ = "";
std::string VinSn::mSn_ = "";

std::string GetPath::mZipFolder_ = "";
std::string GetPath::mSrcFolder_ = "";
std::string GetPath::filiterFilePath_ = "";
std::string GetPath::configPath_ = "";
std::string GetPath::logfilePath_ = "";

bool Upload::flagTest_ = false;
int Upload::maxSizeInGB_ = 0;
int Upload::fileCount_ = 0;
int Upload::uploadFilesNumEachtime_ = 0;
int Upload::intervalTime_ = 60;
bool Upload::deleteSourceFile_ = false;
bool Upload::deleteCompressedFile_ = false;

void Upload::ParseJson(const std::string &jsonPath)
{
    std::ifstream inf(jsonPath);
    //解析
    nlohmann::json data = nlohmann::json::parse(inf); // file may not exist, add later

    try {
        //序列化
        std::string s = data.dump();
        HHT_LOG(INFO) << "json is:" << s;
    } catch (const std::exception &e) {
        inf.close();
        return;
    }
    BuildTree(data);
    inf.close();
}

void Upload::BuildTree(const nlohmann::json &data)
{
    logUrl_.logrtHost_ = data["logrt_host"];
    logUrl_.logrtServiceName_ = data["logrt_service_name"];
    logUrl_.logrtDownloadUploadRule_ = data["logrt_download_upload_rule"];
    logUrl_.logrtGetObsPath_ = data["logrt_get_obs_path"];
    logUrl_.logrtUploadRecordToTsp_ = data["logrt_upload_record_to_tsp"];
    flagTest_ = data["flagTest"].get<bool>();
    getPath_.logfilePath_ = data["logfile_path"];
    fileCount_ = data["fileCount"].get<int>();
    maxSizeInGB_ = data["maxSizeInGB"].get<int>();
    uploadFilesNumEachtime_ = data["upload_files_num_eachtime"].get<int>();
    intervalTime_ = data["intervalTime"].get<int>();
    deleteSourceFile_ = data["delete_source_file"].get<bool>();
    deleteCompressedFile_ = data["delete_compressed_file"].get<bool>();
}

//return 0: successful, -1: failed
int Upload::ManageVinSnOTAData() {
    int ret = 0;
    std::vector<unsigned char> f190(18);
    std::vector<unsigned char> f18c(19);
    std::stringstream ss;
    ret = get_vin_sn(0, 0xf190, &f190[0]);
    if (ret == -1) {
        HHT_LOG(ERROR) << "read Vin failed : " << ret;
        return ret;
    }
    vinSn_.mVin_.assign(f190.begin(), f190.end()-1);
    ret = get_vin_sn(0, 0xf18c, &f18c[0]);
    if (ret == -1) {
        HHT_LOG(ERROR) << "read Sn failed : " << ret;
        return ret;
    }
    vinSn_.mSn_.assign(f18c.begin(), f18c.end()-1);
    HHT_LOG(INFO) << "read VIN: " << vinSn_.mVin_;
    HHT_LOG(INFO) << "read SN: " << vinSn_.mSn_;
    return ret;
}

const std::string &Upload::GetLogrtHost()
{
    return logUrl_.logrtHost_;
}

const std::string &Upload::GetLogrtServiceName()
{
    return logUrl_.logrtServiceName_;
}

const std::string &Upload::GetLogrtDownloadUploadRule()
{
    return logUrl_.logrtDownloadUploadRule_;
}

const std::string &Upload::GetLogrtGetObsPath()
{
    return logUrl_.logrtGetObsPath_;
}

const std::string &Upload::GetLogrtUploadRecordToTsp()
{
    return logUrl_.logrtUploadRecordToTsp_;
}

const std::string &Upload::GetVin()
{
    return vinSn_.mVin_;
}

const std::string &Upload::GetSn()
{
    return vinSn_.mSn_;
}

const std::string &Upload::GetZipFolder()
{
    return getPath_.mZipFolder_;
}

const std::string &Upload::GetSrcFolder()
{
    return getPath_.mSrcFolder_;
}

void Upload::SetZipFolder()
{
    std::filesystem::path workingObj = std::filesystem::current_path();
    std::string workingPath = workingObj.string();
    getPath_.mZipFolder_ = workingPath;
    HHT_LOG(INFO) << "mZipFolder_ is: " << getPath_.mZipFolder_;
}

void Upload::SetSrcFolder() 
{ 
    getPath_.mSrcFolder_ = getPath_.logfilePath_;
    HHT_LOG(INFO) << "mSrcFolder_ is: " << getPath_.mSrcFolder_;
}

//获取过滤文件的json文件路径
void Upload::SetFiliterFilePath()
{
    getPath_.filiterFilePath_ = "./docs/filter.json";
}

//获取配置的json文件路径
void Upload::SetConfigPath()
{
    getPath_.configPath_ = "./docs/config.json";
}

const std::string& Upload::GetFiliterFilePath()
{ 
    return getPath_.filiterFilePath_;
}
const std::string& Upload::GetConfigPath()
{
    return getPath_.configPath_;
}

const bool& Upload::GetFlagTest() {
    return flagTest_;
}

const int& Upload::GetFileCount() {
    return fileCount_;
}

const int& Upload::GetMaxSizeInGB() {
    return maxSizeInGB_;
}

const int& Upload::GetUploadFilesNumEachtime() {
    return uploadFilesNumEachtime_;
}

const int& Upload::GetIntervalTime() {
    return intervalTime_;
}

const bool& Upload::GetDeleteSourceFile() {
    HHT_LOG(INFO) << "deleteSourceFile_ is: " << deleteSourceFile_;
    return deleteSourceFile_;
}

const bool& Upload::GetDeleteCompressedFile() {
    HHT_LOG(INFO) << "deleteCompressedFile_ is: " << deleteCompressedFile_;
    return deleteCompressedFile_;
}