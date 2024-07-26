/*
 * @author 001293
 * @Simulating the creation of a log file on the vehicle end.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef UPLOAD_PRETEND
#define UPLOAD_PRETEND

#include <iostream>

// 模拟车端传过来的数据
class UploadPretend
{
public:
    //模拟车端，往指定目录加入新文件
    bool CreateFile(const std::string& folder, const std::string& filename);

private:
};

#endif