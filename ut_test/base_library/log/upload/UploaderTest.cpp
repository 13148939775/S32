#include <string>
#include <fstream>
#include <gtest/gtest.h>
#include "LogUploadFile.h"
#include "ObsUploader.h"
#include "TspDownloader.h"
#include "TspUploader.h"
#include "upload.h"

struct ResponseTest
{
    std::string code;
    std::string msg;
};

class TspUploaderTest : public testing::Test
{
public:
    void SetUp() override {
        upload.SetSrcFolder();
        upload.SetConfigPath();
        std::string configPath = upload.GetConfigPath();
        upload.ParseJson(configPath);
        tspDownloader.DownloadCfgFromTSP();
        tspDownloader.GetUploadConfFromTSP();
        zipFileInfo = logUploadFile.GetUploadFileList();
    }

    void TearDown() override {
        // 清理操作，可根据实际需要添加
        // 例如：清理 obsUploader.uploadId，zipFileInfo 等资源
    }

protected:
    Upload upload;
    ObsUploader obsUploader;
    TspDownloader tspDownloader;
    LogUploadFile logUploadFile;
    UploadFileInfo zipFileInfo;
};

//ut_test/base_library/log/upload/创建本地文件mylog,根据config.json文件创建对应格式文件
TEST_F(TspUploaderTest, UploadFileToOBS)
{
    Response response;
    response.httpCode = obsUploader.UploadFileToOBS(zipFileInfo);
    //HTTP状态码204表示服务器接收并成功处理了请求，但未返回任何实体内容（响应消息是空的）。
    EXPECT_EQ(response.httpCode, 204) << "UploadFileToOBS defeat";  //如果不相等，则输出对应的错误信息
}

TEST_F(TspUploaderTest, UploadRecordToTSP)
{
    ObsUploader obsUploader;
    obsUploader.UploadFileToOBS(zipFileInfo);

    std::string data;
    ResponseTest response;
    std::list<UploadFileInfo> mRecordUploadFileList;
    mRecordUploadFileList.clear();
    mRecordUploadFileList.push_back(zipFileInfo);
    TspUploader tspUploader;
    data = tspUploader.UploadRecordToTSP(mRecordUploadFileList);

    //解析TSP响应的json串
    auto json = nlohmann::json::parse(data);
    response.code = json["code"].get<std::string>();
    response.msg = json["msg"].get<std::string>();
    EXPECT_EQ(response.code, "000000");
    EXPECT_EQ(response.msg, "SUCCESS");
}

