#ifndef UPLOAD_EXE_RESULT_H
#define UPLOAD_EXE_RESULT_H
#include <string>
#include "nlohmann/json.hpp"

struct ExeResultReqHeader {
    std::string timestamp;
    std::string sign;
    std::string token;
};

struct ExeResultReq {
   std::string serialNo;    
   int actionType;
   std::string sceneId;
   std::string startTime;
   std::string endTime;
   int result;
   std::string exeDetail;
};

struct ExeResultReqRequest {
    std::string url;  
    std::string path;  
    ExeResultReq data;
};

class UploadExeResult {
public:
    static UploadExeResult& GetInstance()
    {
        static UploadExeResult uer;
        return uer;
    }
private:
    UploadExeResult();
    ~UploadExeResult();
public:
    bool ExeResultUpload(const std::string &eResult_path);
    bool ParserConfig(const std::string& eResult_path);  //解析json串
    void BuildTree(const nlohmann::json& data);  //处理json、

public:
    std::string HttpPost(ExeResultReqRequest& request, std::string& response);

    void Setlogin_respons_token(std::string token)
    {
        login_respons_token = token;
    }

    void SetSignKey(std::string key)
    {
        login_respons_signKey = key;
    }

    void SetReuestTime(std::string stime, std::string etime)
    {
        begintime_  = stime;
        endtime_ = etime;
    }

    void SetRequestRes(std::string resdetailk, int res)
    {
        resdetail_ = resdetailk;
    }


private:
    ExeResultReqHeader header;
    ExeResultReqRequest request;
    std::string uploadResultstr;
    static const int32_t CONNECTTIMEOUTDEFAULT = 20;
    static const int32_t RESTIMEOUT = 60;

    std::string login_respons_token;   // 存储登录返回解析后的token
    std::string login_respons_signKey; // 存储登录返回解析后的signKey
    std::string jsonstr;               // post请求体
    std::string begintime_;
    std::string endtime_;
    std::string resdetail_;
};

#endif