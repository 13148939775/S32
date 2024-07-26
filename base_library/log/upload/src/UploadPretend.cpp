/*
 * @author 001293
 * @Simulating the creation of a log file on the vehicle end.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "UploadPretend.h"  
#include <fstream>
#include <filesystem>
#include <node_log.h> 
#include "LogUploadFile.h"

//模拟车端往目录加入新的文件
bool UploadPretend::CreateFile(const std::string &mSrcFolder, const std::string &fileName)
{
    LogUploadFile lp;
    //组成路径
    std::string pretendFolderPath =  mSrcFolder + "/pretend";
    HHT_LOG(INFO) << "pretendFolderPath: " << pretendFolderPath;
    lp.CreateFolder(pretendFolderPath);
    std::filesystem::path filePath = pretendFolderPath + "/pretend_" + fileName + "_.txt";
    // 创建文件
    std::ofstream outfile(filePath);
    // 修改文件权限
    std::filesystem::permissions(filePath, std::filesystem::perms::owner_read | 
                                 std::filesystem::perms::owner_write);
    if (!outfile) {
      HHT_LOG(ERROR) << "Failed to create file: " << filePath;
      return false;
    }
    outfile << "Level:INFO\n"; // 写入一些内容
    outfile << "This is an example file.\n"; // 写入一些内容
    HHT_LOG(INFO) << "Succeeded to create file: " << filePath;
    outfile.close();
    return true;
}