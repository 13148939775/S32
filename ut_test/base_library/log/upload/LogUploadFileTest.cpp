#include <string>
#include <fstream>
#include <gtest/gtest.h>
#include "LogUploadFile.h"
#include "Control.h"

TEST(LogUploadFileTest, GetFilters)
{
    LogUploadFile upload;
    std::vector<Filter> filters = upload.GetFilters();
    EXPECT_EQ(filters.size(), 6) << "filters.size() unequal right num";
    EXPECT_EQ(filters[0].ext, "txt");
    EXPECT_TRUE(filters[0].enabled);
    EXPECT_EQ(filters[1].ext, "docx");
    EXPECT_TRUE(filters[1].enabled);
    EXPECT_EQ(filters[2].ext, "pdf");
    EXPECT_TRUE(filters[2].enabled);
    EXPECT_EQ(filters[3].ext, "xls");
    EXPECT_FALSE(filters[3].enabled);
    EXPECT_EQ(filters[4].ext, "xml");
    EXPECT_TRUE(filters[4].enabled);
}

TEST(LogUploadFileTest, GetListFromFilelist)
{
    LogUploadFile upload;
    std::vector<Filter> filters = upload.GetFilters();

    std::vector<std::string> files;
    std::string path = "./mylog";
    upload.GetListFromFilelist(files, path, filters);

    EXPECT_EQ(files.size(), 5);
}

TEST(LogUploadFileTest, CompressFiles) {
    LogUploadFile upload;
    Control ctr;
    ctr.LoadConfig(); 
    std::vector<Filter> filters = upload.GetFilters();
    std::vector<std::string> files;
    std::string path = "./mylog";
    upload.GetListFromFilelist(files, path, filters);
    upload.SetZipFilePath(files);
    bool res = upload.CompressFiles(files);
    EXPECT_TRUE(res);
}

TEST(LogUploadFileTest, MonitorDirectorySize) {
    LogUploadFile logUpload;
    std::string directoryPath = "./testfile";
    long long maxSizeInBytes = 5; //50bytes
    int fileCount = 1;
    logUpload.MonitorDirectorySize(maxSizeInBytes, fileCount, directoryPath);

    std::filesystem::path folderPath = directoryPath; // 文件夹路径

    int count = 0; // 文件数量计数器

    // 遍历文件夹中的每个文件
    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) { // 如果是普通文件
            count++; // 增加文件数量计数
        }
    }
    EXPECT_EQ(count, 2);
}

TEST(LogUploadFileTest, CreateFolder) {
    LogUploadFile lp;
    std::string folder_name1 = "test_folder1";
    int result1 = lp.CreateFolder(folder_name1);
    EXPECT_EQ(result1, 0) << "Failed to create folder " << folder_name1;

    std::string folder_name2 = "test_folder2";
    std::filesystem::create_directory(folder_name2);
    int result2 = lp.CreateFolder(folder_name2);
    EXPECT_EQ(result2, -1) << "Unexpectedly created folder " << folder_name2;
    std::filesystem::remove(folder_name2);
}

TEST(LogUploadFileTest, DeleteSourceFiles) {
    LogUploadFile lp;
    std::string file1 = "file1.txt";
    std::string file2 = "file2.txt";
    std::string file3 = "file3.txt";
    std::string file4 = "file4.txt";

    std::ofstream(file1).close();
    std::ofstream(file2).close();
    std::ofstream(file3).close();
    std::ofstream("file4.txt.uploadbak").close();

    std::vector<std::string> filesReady = {file1, file2, file3, file4};

    int result = lp.DeleteSourceFiles(filesReady);
    
    EXPECT_EQ(result, -1) << "Failed to delete files.";
    bool fileExists1 = std::filesystem::exists(file1);
    bool fileExists2 = std::filesystem::exists(file2);
    bool fileExists3 = std::filesystem::exists(file3);
    bool fileExists4 = std::filesystem::exists(file4);
    EXPECT_TRUE(fileExists1) << "File1 is missing.";
    EXPECT_TRUE(fileExists2) << "File2 is missing.";
    EXPECT_TRUE(fileExists3) << "File3 is missing.";
    EXPECT_FALSE(fileExists4) << "File4 is not missing.";

    std::filesystem::remove(file1);
    std::filesystem::remove(file2);
    std::filesystem::remove(file3);
}
