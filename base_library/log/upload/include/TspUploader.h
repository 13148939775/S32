/*
 * @author 001293
 * @Uploading the information returned from OBS to TSP.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TSP_UPLOADER_H
#define TSP_UPLOADER_H
#include <list>
#include "nlohmann/json.hpp"
#include "LogUploadFile.h"

class TspUploader{
public:
    static std::string GetTimeStamps();
    std::string UploadRecordToTSP(const std::list<UploadFileInfo>& fileinfos);
    void BuildJson(const std::list<UploadFileInfo> &fileinfos);
    int square(int x);
private:
    nlohmann::json value_;
};
#endif