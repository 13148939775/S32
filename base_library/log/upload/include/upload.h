/*
 * @author 001293
 * @Loading configuration file-related content.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef UPLOAD_H
#define UPLOAD_H
#include <string>
#include "nlohmann/json.hpp"
#include "hh_ota_interface.h"

struct LogUrl {
    static std::string logrtHost_;
    static std::string logrtServiceName_;
    static std::string logrtDownloadUploadRule_;
    static std::string logrtGetObsPath_;
    static std::string logrtUploadRecordToTsp_;
};

struct GetPath {
    static std::string mZipFolder_;
    static std::string mSrcFolder_;
    static std::string filiterFilePath_;
    static std::string configPath_;
    static std::string logfilePath_;
};

struct VinSn {
    static std::string mVin_;
    static std::string mSn_;
};

class Upload{
public:
    void ParseJson(const std::string &jsonPath);
    static void BuildTree(const nlohmann::json &data);
    int ManageVinSnOTAData();       //获取ota的vin sn

    static const std::string& GetLogrtHost();
    static const std::string& GetLogrtServiceName();
    static const std::string& GetLogrtDownloadUploadRule();
    static const std::string& GetLogrtGetObsPath();
    static const std::string& GetLogrtUploadRecordToTsp();

    void SetZipFolder();
    void SetSrcFolder();    //设置日志上传的日志文件的路径
    void SetFiliterFilePath();
    void SetConfigPath();

    static const std::string& GetZipFolder();
    static const std::string& GetSrcFolder();   
    static const std::string& GetFiliterFilePath();
    static const std::string& GetConfigPath();

    static const std::string& GetVin();
    static const std::string& GetSn();
    static const bool& GetFlagTest();
    static const int& GetFileCount();
    static const int& GetMaxSizeInGB();
    static const int& GetUploadFilesNumEachtime();
    static const int& GetIntervalTime();
    static const bool& GetDeleteSourceFile();
    static const bool& GetDeleteCompressedFile();

private:
    static LogUrl logUrl_;
    static VinSn vinSn_;
    static GetPath getPath_;
    static bool flagTest_;  //从配置json文件读取是否是test状态，以此控制频率是秒还是分(分太久了,不便开发)
    static int maxSizeInGB_;
    static int fileCount_;
    static int uploadFilesNumEachtime_;
    static int intervalTime_;       //两次上传间隔，单位秒
    static bool deleteSourceFile_;   //上传成功后是否删除源文件
    static bool deleteCompressedFile_;   //上传成功后是否删除压缩文件
};

#endif