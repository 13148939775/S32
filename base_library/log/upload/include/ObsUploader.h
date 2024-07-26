/*
 * @author 001293
 * @Uploading files to OBS interface.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef OBS_UPLOAD_H
#define OBS_UPLOAD_H

#include <string>
#include "nlohmann/json.hpp"
#include "LogUploadFile.h"

struct OBSConf {
    std::string downloadUrl;
    int32_t obsFileExpire;
    int32_t obsTokenExpire;
    std::string uploadFolder;
    std::string uploadToken;
    std::string uploadUrl;
    OBSConf()
      : obsFileExpire(0),
        obsTokenExpire(0) {
    }
};

class ObsUploader{
public:
    int64_t  UploadFileToOBS(const UploadFileInfo& fileinfo);
    static const OBSConf& GetObsconfig();
    static void SetObsconfig(const nlohmann::json obsCfg);
    void PrintObsconfig();
    static std::string& GetTimestampOBSDay();
private:
    static OBSConf mObsconfig_;
    static std::string timestampOBSDay_;
};

#endif