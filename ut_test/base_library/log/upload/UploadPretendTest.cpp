#include <gtest/gtest.h>
#include "UploadPretend.h"
#include "upload.h"

TEST(UploadPretendTest, CreateFileTest)
{
    UploadPretend pretend;
    Upload upload;
    int fileNum = 0; //设置模拟车端文件的名称
    //模拟车端不断加入新的日志文件
    std::string fileName;
    fileName = std::to_string((++fileNum)); //创建的新文件的名称
    bool result = pretend.CreateFile(upload.GetSrcFolder(), fileName);

    ASSERT_TRUE(result) << "Failed to create file.";
}