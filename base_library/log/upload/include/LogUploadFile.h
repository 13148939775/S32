/*
 * @author 001293
 * @Handling log file uploads.
 * @version 1.0
 * @date 2023-05 ~ 2023-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOG_UPLOAD_FILE_H
#define LOG_UPLOAD_FILE_H

#include <string>
#include <tuple>
#include <list>
#include <map>
#include <vector>
#include <functional>
#include <fts.h>
#include <filesystem>
#include "upload.h"

struct FileInfo {
    std::string createTime;
    std::string fileName;
    std::string fileId;
    std::string filePath;
    uint64_t fileSize;
};

struct UploadFileInfo {
    std::string code;
    std::string vin;
    std::string ecuId;
    std::string deviceId;
    std::string businessId;
    std::string logType;
    FileInfo file;
};

struct Filter {
    std::string ext;
    bool enabled;
};

enum class Level{
    INFO,
    WARN,
    ERROR,
    FATAL,
    NOLEVEL     //表示日志文件没有标注日志级别
};

class LogUploadFile {
public:
    std::string GetCurrentDateTime(bool includeTime);
    static uint64_t GetFileSize(const std::string& path);
    bool CompressFiles(const std::vector<std::string>& files);
    int CreateFolder(const std::string& folder_name);      //如果目录不存在，就创建一个
    void GetListFromFilelist(std::vector<std::string>& files, const std::string& path,const std::vector<Filter>& filters);
    UploadFileInfo GetUploadFileList();
    std::vector<Filter> GetFilters();
    void AddBakSuffix(std::string file); //给已经上传过的文件添加bak后缀
    int DeleteFiles(std::string filePath);      //删除单个文件filePath
    int DeleteSourceFiles(std::vector<std::string> filesReady);     //文件压缩上传完后立即删除.zip文件内源文件
    int DeleteCompressedFiles(std::string zipFilePath);     //压缩文件上传成功后删除.zip文件

    /*directoryPat:目录路径、maxSizeInBytes:目录里的文件最大总大小、fileCount:每次删除的文件数量
    如果将 maxSizeInBytes 设置为 10GB，那么可以将其设置为 10 * 1024 * 1024 * 1024字节。
    监控文件大小，超出范围，循环覆盖(把时间最早的fileCount个文件删除)*/
    void MonitorDirectorySize(long long maxSizeInBytes, int fileCount,std::string directoryPath = "defaultNull");
    std::vector<std::filesystem::path> FilesSortByTime(std::vector<std::string>& files_,std::string directoryPath = "defaultNull");

    void ConfigZipFileInfo();   //配置zipFileInfo_成员变量的内容
    void GetLevelStr(const std::string file); //根据文件内容读取到文件级别，并返回这个级别
    void GetFileSizeByLevel();     //根据日志级别分别统计压缩后的日志文件大小
    std::string StoreLevelInfoOnDay();     //按日存储不同级别日志文件信息
    std::string GetLevelLogFilePath();

    //只在程序开始执行时调用一次，用于记录最开始的一次文件写入时间
    //目的是为了方便与下一次文件写入时间做对比
    void SetlevelLogFilePathLast();  
    static std::string GetlevelLogFilePathLast();
    void ResetFileSizeMap();    //重置fileSizeMap_内的数据

    std::string FileNamePrefix(std::string fileName);   //获取文件前缀，如CCC_，用于判断文件来源

    void SetZipFilePath(std::vector<std::string>& files);
    static const std::vector<std::string>& GetFilesReady();

private:
    static std::map<std::string, UploadFileInfo> filelist_;
    static std::uint32_t count_;  //记录上传的文件总数量
    static UploadFileInfo zipFileInfo_;
    const std::string zipStoragePath_ = "./Zip_Storage/";
    std::string zipFilePath_;
    // const std::string zipFilePath_ = "Zip_Storage/" + Upload::GetSn() + "_" + LogUploadFile::GetCurrentTime() + ".zip";
    std::tuple<std::string, int32_t, std::string, std::string, int32_t> ecuConfig_;
    std::vector<Filter> filters_;
    static std::vector<std::string> filesReady_;
    long long totalSize_;  //当前目录下(日志文件所在目录，即要上传的那些文件所在目录)的文件大小
    std::vector<std::filesystem::path> filePaths_; //根据时间顺序存储文件路径

    std::vector<std::string> files_;        //获取要压缩的文件列表
    static std::map<std::string, std::uint32_t> fileSizeMap_;   //存储不同日志级别的流量大小(压缩后文件大小)
    std::string levelStr_;      //存储当前文件的日志级别

    //记录保存不同日志级别信息文件的时间
    static std::string levelLogFilePathLast_;  
    std::string levelLogFilePathNow_;
};

#endif