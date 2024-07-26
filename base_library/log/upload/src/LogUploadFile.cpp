/*
 * @author 001293
 * @Handling log file uploads.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "LogUploadFile.h"
#include <fcntl.h>
#include <chrono>
#include <sys/stat.h>
#include <unistd.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>
#include <node_log.h>
#include <unzip.h>
#include <zip.h>
#include <zlib.h> //minizip库与zlib库进行链接，此头文件在zlib中
#include "upload.h"

std::uint32_t LogUploadFile::count_ = 0;                        //静态变量初始化
UploadFileInfo LogUploadFile::zipFileInfo_;                     //静态成员
std::map<std::string, UploadFileInfo> LogUploadFile::filelist_; //静态成员
std::vector<std::string> LogUploadFile::filesReady_{};

//文件前缀
std::string flagFileNamePrefix = "";
const int MAX_FILE_SORT = 11;           

std::map<std::string, std::uint32_t> LogUploadFile::fileSizeMap_ = {
    {"INFO", 0},
    {"WARN", 0},
    {"ERROR", 0},
    {"FATAL", 0},
    {"NOLEVEL", 0}
};

std::string LogUploadFile::levelLogFilePathLast_ = " ";

std::string LogUploadFile::GetCurrentDateTime(bool includeTime)
{
    time_t timep;
    time(&timep);
    char timestamp[64] = {0};
    if (includeTime) {
        strftime(timestamp, sizeof(timestamp) - 1, "%Y%m%d%H%M%S", localtime(&timep));
        HHT_LOG(INFO) << "current time: " << timestamp;
    } else {
        strftime(timestamp, sizeof(timestamp) - 1, "%Y%m%d", localtime(&timep));
        HHT_LOG(INFO) << "current date: " << timestamp;
    }
    return timestamp;
}

int LogUploadFile::CreateFolder(const std::string& folder_name) {
    // 判断文件夹是否存在
    if (!std::filesystem::exists(folder_name)) {
        // 如果文件夹不存在，则创建文件夹
        std::filesystem::create_directory(folder_name);
        // 输出成功信息
        HHT_LOG(INFO) << "Folder created!" << std::endl;
        return 0;
    } else {
        // 文件夹已存在，不需要再创建
        return -1;
    }
}


//获取文件的大小
uint64_t LogUploadFile::GetFileSize(const std::string &path)
{
    int size = 0;
    struct stat buf;
    int fd = open(path.c_str(), O_RDONLY);
    if (fd >= 0) {
        if (fstat(fd, &buf) == 0) {
            size = buf.st_size;
        }
        close(fd);
    } else {
        HHT_LOG(ERROR) << "File open failed: " << path;
        return 0;
    }
    return size;
}

//根据文件内容读取到文件级别，并返回这个级别
void LogUploadFile::GetLevelStr(const std::string file) {
    std::ifstream ifs;
    ifs.open(file.c_str(),std::ios_base::in);
    if(!ifs.is_open()) {
        HHT_LOG(INFO)<<"open failed" << file;
        return ;
	}
    std::string buff;
    HHT_LOG(INFO)<<"open success : " << file;
    //只需读取首行
    if(getline(ifs,buff)) {
        if( buff.substr(0,6) == "Level:" ) {
            levelStr_ = buff.substr(6); 
        }
    }
    ifs.close();
    HHT_LOG(INFO) << "log levelStr: " << levelStr_;
}

//将std::string类型映射到枚举类型中
Level StringToLevel(std::string levelStr){
    //读取的文件级别映射到级别枚举中
    const std::map<std::string, Level> LevelMap{
        {"INFO", Level::INFO},
        {"WARN", Level::WARN},
        {"ERROR", Level::ERROR},
        {"FATAL", Level::FATAL},
        {"Open Failed", Level::NOLEVEL}
    };
    auto level = LevelMap.find(levelStr);
    if (level != LevelMap.end()) {
        return level->second;
    }
    return Level::NOLEVEL;
}

//在ConfigZipFileInfo()函数之后调用，zipFileInfo_.file.fileSize已经是调用压缩后的文件大小
void LogUploadFile::GetFileSizeByLevel() {
    Level level = StringToLevel(levelStr_);
    switch(level) {
        case Level::INFO:
            fileSizeMap_["INFO"] += zipFileInfo_.file.fileSize;  
            HHT_LOG(INFO) << "INFO level log fileSize: " << fileSizeMap_["INFO"];  
            break;
        case Level::WARN:
            fileSizeMap_["WARN"] += zipFileInfo_.file.fileSize; 
            HHT_LOG(INFO) << "WARN level log fileSize: " << fileSizeMap_["WARN"]; 
            break;
        case Level::ERROR:
            fileSizeMap_["ERROR"] += zipFileInfo_.file.fileSize; 
            HHT_LOG(INFO) << "ERROR level log fileSize: " << fileSizeMap_["ERROR"]; 
            break;
        case Level::FATAL:
            fileSizeMap_["FATAL"] += zipFileInfo_.file.fileSize; 
            HHT_LOG(INFO) << "FATAL level log fileSize: " << fileSizeMap_["FATAL"]; 
            break;
        case Level::NOLEVEL:
            fileSizeMap_["NOLEVEL"] += zipFileInfo_.file.fileSize; 
            HHT_LOG(INFO) << "NOLEVEL level log fileSize: " << fileSizeMap_["NOLEVEL"]; 
            break;
    }
}

std::string LogUploadFile::GetLevelLogFilePath() {
    Upload upload;
    std::string timestampDay;    //当前时间
    if(upload.GetFlagTest() == true) {
        timestampDay = GetCurrentDateTime(true);
    } else {
        timestampDay = GetCurrentDateTime(false);
    }
    std::string levelLogFileFolder = "./levelLogFile/";
    CreateFolder(levelLogFileFolder);
    std::string levelLogFilePath = levelLogFileFolder + timestampDay + ".log";
    HHT_LOG(INFO) << "level log info path: " << levelLogFilePath; 
    return levelLogFilePath;
} 

//按日存储不同级别日志文件信息
std::string LogUploadFile::StoreLevelInfoOnDay() {
    std::string levelLogFilePath = GetLevelLogFilePath();
    // 打开文件
    std::ofstream logFile(levelLogFilePath);
    // 检查文件是否成功打开
    if (logFile.is_open()) {
        // 写入内容
        logFile << "Level:INFO FileSize: " << fileSizeMap_["INFO"] <<  "\n";
        logFile << "Level:WARN FileSize: " << fileSizeMap_["WARN"] << "\n";
        logFile << "Level:ERROR FileSize: " << fileSizeMap_["ERROR"] << "\n";
        logFile << "Level:FATAL FileSize: " << fileSizeMap_["FATAL"] << "\n";
        logFile << "Level:NOLEVEL FileSize: " << fileSizeMap_["NOLEVEL"] << "\n";
        // 关闭文件
        logFile.close();
        return levelLogFilePath;
    } else {
        // 文件打开失败
        HHT_LOG(ERROR) << "Failed to open levelLogFile file: " << levelLogFilePath;
        HHT_LOG(ERROR) << "Please check if the './levelLogFile' folder exists.";
        return levelLogFilePath;
    }
}

//获取文件前缀，如CCC_，用于判断文件来源
std::string LogUploadFile::FileNamePrefix(std::string fileName) {
    // 获取第一个"_"的位置
    size_t underscorePos = fileName.find("_");
    // 提取第一个"_"前的子字符串
    std::string firstPart = fileName.substr(0, underscorePos);
    return firstPart + "_";
}

bool LogUploadFile::CompressFiles(const std::vector<std::string> &files)
{
    int uploadFileNum = 0;
    CreateFolder(zipStoragePath_);
    // 打开要创建的zip文件
    zipFile archive = zipOpen(zipFilePath_.c_str(), APPEND_STATUS_CREATE);
    HHT_LOG(INFO) << "zipFilePath_: " << zipFilePath_ ;
    if (archive == nullptr) {
        HHT_LOG(ERROR) << "Failed to open zip file: " << zipFilePath_;
        return false;
    }
    // 设置zip文件的加密密码为vin 字符串的后六位字符
    std::string vin = Upload::GetVin();
    std::string mPassword = vin.substr(vin.size() - 6);
    int flagPrefix = 0;     //用于保证每次压缩的文件前缀一致(同一应用)
    filesReady_.clear();
    // 将要压缩的文件添加到zip文件中
    for (const auto &file : files) {
        flagPrefix += 1;
        //获取文件日志级别
        GetLevelStr(file);  
        // 获取文件信息
        std::filesystem::path filePath(file);
        std::string fileName = filePath.filename().string();
        if (flagPrefix ==1) {
            flagFileNamePrefix = FileNamePrefix(fileName);
            HHT_LOG(INFO) << "const auto &file : files 's file : " << file;
            filesReady_.emplace_back(file);
        } else {
            std::string flagFileNamePrefixFollow = FileNamePrefix(fileName);
            if (flagFileNamePrefixFollow != flagFileNamePrefix) {
                continue;
            }
            HHT_LOG(INFO) << "const auto &file : files 's file : " << file;
            filesReady_.emplace_back(file);
        }
        FILE *srcFile = fopen(file.c_str(), "rb");
        if (srcFile == nullptr) {
            HHT_LOG(ERROR) << "Failed to open source file: " << file;
            zipClose(archive, nullptr);
            return false;
        }
        zip_fileinfo fileInfo = {};      
        zipOpenNewFileInZip3(archive, fileName.c_str(), &fileInfo, nullptr, 0, nullptr, 0, nullptr, Z_DEFLATED, Z_DEFAULT_COMPRESSION,
                            0, -MAX_WBITS, DEF_MEM_LEVEL, Z_DEFAULT_STRATEGY, mPassword.c_str(),mPassword.size());
        //使用constexpr关键字可以声明一个编译时常量，在程序编译过程中被计算出来，并在运行时不可修改
        constexpr int bufferSize = 4096;
        std::vector<char> buffer(bufferSize);
        size_t bytesRead = 0;
        while ((bytesRead = fread(buffer.data(), 1, bufferSize, srcFile)) > 0) {
            zipWriteInFileInZip(archive, buffer.data(), static_cast<unsigned int>(bytesRead));
        }
        zipCloseFileInZip(archive);
        fclose(srcFile);
        AddBakSuffix(file); //给已上传(压缩)的文件添加bak后缀
        ++uploadFileNum;    //设置上传文件颗粒度临时变量
        if( uploadFileNum >= Upload::GetUploadFilesNumEachtime() ) {
            break;
        }
    }
    // 关闭zip文件
    zipClose(archive, nullptr);
    HHT_LOG(INFO) << "Compressed files created successfully.";
    return true;
}

//配置压缩文件的相关信息
void LogUploadFile::ConfigZipFileInfo() {
    zipFileInfo_.file.filePath = zipFilePath_;
    zipFileInfo_.file.fileSize = GetFileSize(zipFilePath_); //获取压缩后的文件大小
    zipFileInfo_.file.createTime = GetCurrentDateTime(true);
    zipFileInfo_.file.fileName = flagFileNamePrefix + Upload::GetSn() + "_" + zipFileInfo_.file.createTime;
    HHT_LOG(INFO) << "zipFileInfo_.file.fileName:  " << zipFileInfo_.file.fileName;
    zipFileInfo_.logType = std::get<3>(ecuConfig_);
    zipFileInfo_.ecuId = std::string(std::get<2>(ecuConfig_));/*  */
}

// 使用递归的方式遍历指定目录 path 下的所有文件，包括子目录里面的文件，并将这些文件的路径添加到 files 向量中
void LogUploadFile::GetListFromFilelist(std::vector<std::string> &files, const std::string &path, const std::vector<Filter> &filters)
{
    HHT_LOG(INFO) << "path:---------" << path;
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_directory() == true) {
            // 如果是目录，则递归调用
            GetListFromFilelist(files, entry.path().string(), filters);
        } else if (entry.is_regular_file() == true) {
            bool is_filtered = false;
            for (const auto &filter : filters) {
                if (filter.enabled && entry.path().extension() == ("." + filter.ext)) {
                    is_filtered = true;
                    break;
                }
            }
            // 如果是正常文件，且不符合过滤条件，则添加到文件列表中
            if (is_filtered != false) {
                files.emplace_back(entry.path().string());
                ++count_;
            }
        }
    }
}

//得到json文件中有效的文件后缀
std::vector<Filter> LogUploadFile::GetFilters()
{
    Upload upload;
    upload.SetFiliterFilePath();
    std::string filterFilePath = Upload::GetFiliterFilePath();
    std::ifstream configFile(filterFilePath);
    nlohmann::json config;
    configFile >> config;
    for (auto &filter_json : config["filterfiles"]) {
        if (filter_json.contains("ext") == true && filter_json.contains("enabled") == true &&
            filter_json["ext"].is_string() == true && filter_json["enabled"].is_boolean() == true) {
            filters_.push_back({filter_json["ext"].get<std::string>(),
                                filter_json["enabled"].get<bool>()});
        }
    }
    return filters_;
}

//修改已经上传过的文件后缀，如a.txt改为a.txt.bak
void LogUploadFile::AddBakSuffix(std::string file)
{
    std::filesystem::path filePath(file); //把每个文件路径转换为路径对象
    std::filesystem::path fileOldPath(file);
    std::string newExt = filePath.extension().string() + ".uploadbak";
    std::filesystem::path newFilePath = fileOldPath.replace_extension(newExt); //修改文件后缀

    if (std::rename(filePath.c_str(), newFilePath.c_str()) == 0) {
        HHT_LOG(INFO) << "renamed file: " << filePath << " to " << newFilePath;
        file = newFilePath.string();
    } else {
        int errorno = errno;
        HHT_LOG(ERROR) << "failed to rename file: " << filePath
                       << " to " << newFilePath
                       << " with error code: " << errorno
                       << ", error message: " << std::strerror(errorno);
        // 输出原始和新文件名
        HHT_LOG(INFO) << "Failed to rename: " << fileOldPath.c_str() << " to " << newFilePath.c_str();
    }
}

int LogUploadFile::DeleteFiles(std::string filePath) {
    int result = 0;
    if (std::filesystem::exists(filePath)) {
        if (std::filesystem::remove(filePath) != true) {
            HHT_LOG(ERROR) << "Failed to delete file: " << filePath;
            result = -1;
        } else {
            HHT_LOG(INFO) << "Successfully deleting the file: " << filePath;
        }
    } else {
        HHT_LOG(ERROR) << "File doesn't exist: " << filePath;
        result = -1;
    }
    return result;
}

int LogUploadFile::DeleteSourceFiles(std::vector<std::string> filesReady)
{
    int result = 0;
    HHT_LOG(INFO) << "filesReady.size()" << filesReady.size();
    for (const auto& file : filesReady) {
        std::string fileUploaded = file + ".uploadbak";
        result = DeleteFiles(fileUploaded);
    }
    return result;
}

int LogUploadFile::DeleteCompressedFiles(std::string zipFilePath) {
    int result = 0;
    std::string fileUploaded = zipFilePath + ".uploadbak";
    result = DeleteFiles(fileUploaded);
    return result; 
}

void LogUploadFile::ResetFileSizeMap() {
    HHT_LOG(INFO) << "levelLogFilePathLast:" << levelLogFilePathLast_;
    levelLogFilePathNow_ = StoreLevelInfoOnDay();
    HHT_LOG(INFO) << "levelLogFilePathNow:" << levelLogFilePathNow_;
    if(levelLogFilePathLast_ != levelLogFilePathNow_) {
        fileSizeMap_["INFO"] = 0;
        fileSizeMap_["WARN"] = 0;
        fileSizeMap_["ERROR"] = 0;
        fileSizeMap_["FATAL"] = 0;
        fileSizeMap_["NOLEVEL"] = 0;
        levelLogFilePathLast_ = levelLogFilePathNow_;
        HHT_LOG(INFO) << "The next day beginning!";
    }
}

UploadFileInfo LogUploadFile::GetUploadFileList()
{
    std::get<0>(ecuConfig_) = Upload::GetSrcFolder();
    std::get<1>(ecuConfig_) = -1;
    std::get<2>(ecuConfig_) = "IDCM";
    std::get<3>(ecuConfig_) = "301";
    std::get<4>(ecuConfig_) = 1;
    HHT_LOG(INFO) << "mSrcFolder: " << Upload::GetSrcFolder();
    // // 获取要压缩的文件列表
    // std::vector<std::string> files;
    GetFilters();
    if (std::filesystem::exists(Upload::GetSrcFolder()) == false) {
        HHT_LOG(ERROR) << "SrcFolder get failed:";
        return zipFileInfo_;
    }
    GetListFromFilelist(files_, Upload::GetSrcFolder(), filters_);
    HHT_LOG(INFO) << "curl upload file numbers sucessed is:" << count_;
    ResetFileSizeMap();
    FilesSortByTime(files_);
    SetZipFilePath(files_);
    // 将文件列表的文件压缩成一个文件
    if (CompressFiles(files_) != true) {
        HHT_LOG(ERROR) << "Failed to compress files.";
        return zipFileInfo_;
    }
    ConfigZipFileInfo();    //配置压缩文件信息，包括文件大小
    GetFileSizeByLevel();
    return zipFileInfo_;
}

// 比较两个文件的创建时间,要作为std::sort()的回调函数，不能是成员函数
bool CompareFileCreationTime(const std::filesystem::path &filePath1, const std::filesystem::path &filePath2)
{
    auto time1 = std::filesystem::last_write_time(filePath1);
    auto time2 = std::filesystem::last_write_time(filePath2);
    return time1 < time2;
}

//把files_向量中的文件按照时间顺序存储到filePaths_中
//参数1：必填 存储了所有文件的向量
//参数2：可选 默认为"defaultNull"，用于单元测试，详见MonitorDirectorySize函数的单元测试
std::vector<std::filesystem::path> LogUploadFile::FilesSortByTime(std::vector<std::string>& files, std::string directoryPath) {
    if (directoryPath ==  "defaultNull") {  //路径为实际日志上传路径，即Upload::GetSrcFolder()
        // 对 files_ 按照文件创建时间进行排序
        std::sort(files.begin(), files.end(), CompareFileCreationTime);
        files_ = files;
        for (const auto& file : files) {
            filePaths_.push_back(std::filesystem::path(file));
            totalSize_ += std::filesystem::file_size(std::filesystem::path(file));
        }

        HHT_LOG(INFO) << "After sorting:" ;
        int filesCount = MAX_FILE_SORT;
        for (const auto &file : files) {
            try {
                if (std::filesystem::exists(file)) {
                    --filesCount;
                    if (filesCount != 0) {
                        HHT_LOG(INFO) << file;
                    } else {
                        break;
                    }
                }
            } catch (std::filesystem::filesystem_error& e) {
                HHT_LOG(INFO) << "File does not exist or cannot be accessed: " << file;
            } catch (...) {
                HHT_LOG(INFO) << "An unexpected issue occurred while accessing file: " << file;
            }
        }
    } else {    //单元测试传入路径
        for (const auto &entry : std::filesystem::directory_iterator(directoryPath)) {
            if (entry.is_regular_file() == true) {
                totalSize_ += std::filesystem::file_size(entry.path());
                filePaths_.push_back(entry.path());
            }
        }
    }
    std::sort(filePaths_.begin(), filePaths_.end(), CompareFileCreationTime);
    return filePaths_;
}

uintmax_t getDirectorySize(const std::filesystem::path& dir_path) {
    uintmax_t size = 0;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(dir_path)) {
        if (entry.is_regular_file()) {
            size += entry.file_size();
        }
    }
    return size;
}

/*directoryPat:目录路径、maxSizeInGB:目录里的文件最大总大小
如果将 10GB = 10 * 1024 * 1024 * 1024字节。
监控文件大小，超出范围，删除14天以前的所有文件*/
void LogUploadFile::MonitorDirectorySize(long long maxSizeInGB, int fileCount, std::string directoryPath)
{
    HHT_LOG(INFO) << "std::string directoryPath: " << directoryPath;
    std::filesystem::path dirPath(directoryPath);
    uintmax_t dirSize = getDirectorySize(directoryPath);
    
    HHT_LOG(INFO) << "dirSize: " << dirSize;        //单位是bytes
    uintmax_t maxSize = maxSizeInGB * 1024 *1024 *1024;      //maxSizeInGB单位是GB
    HHT_LOG(INFO) << "maxSizeInGB: " << maxSizeInGB;
    HHT_LOG(INFO) << "maxSize: " << maxSize;
    if (dirSize > maxSize) {
        std::vector<std::string> files;
        GetListFromFilelist(files,directoryPath,GetFilters());
        // FilesSortByTime(files);  
        // 计算14天前的时间点
        auto now = std::filesystem::file_time_type::clock::now();
        auto twoWeeksAgo = now - std::chrono::hours(24 * 14);
        // auto twoWeeksAgo = now - std::chrono::minutes(1);
        for (const auto &file : files) {
            if (std::filesystem::exists(file)) {
                // HHT_LOG(INFO) << file ;
                std::filesystem::path filePath(file);
                std::filesystem::file_time_type lastModifiedTime = std::filesystem::last_write_time(filePath);
                if (lastModifiedTime <= twoWeeksAgo) {
                    HHT_LOG(INFO) << "Deleting file: " << file;
                    std::filesystem::remove(file);
                }
            }  
        }

        // HHT_LOG(INFO) << "Deleted " << filesDeletedcount << " files";
    } else {
        HHT_LOG(INFO) << "spance enough, no need to delete";
    }
}

void LogUploadFile::SetlevelLogFilePathLast() {
    this->levelLogFilePathLast_ = GetLevelLogFilePath();
    HHT_LOG(INFO) << "SetlevelLogFilePathLast(): " << this->levelLogFilePathLast_ ;
}

std::string LogUploadFile::GetlevelLogFilePathLast() {
    return levelLogFilePathLast_;
}

void LogUploadFile::SetZipFilePath(std::vector<std::string>& files) {
    std::string& firstFile = files[0];
    std::string filePrefix = FileNamePrefix(firstFile);
    filePrefix = filePrefix.substr(filePrefix.find_last_of("/") + 1);
    HHT_LOG(INFO) << "filePrefix: " << filePrefix ;
    zipFilePath_ = zipStoragePath_ + filePrefix + "_" + Upload::GetSn() + "_" + GetCurrentDateTime(true) + ".zip";
    HHT_LOG(INFO) << "zipFilePath_: " << zipFilePath_ ;
}

const std::vector<std::string>& LogUploadFile::GetFilesReady(){
    return filesReady_;
}