#include "UploadExeResult.h"
#include <curl/curl.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/time.h>
#include "Signature.h"
#include "Encode.h"

//extern std::string login_respons_token;   // 存储登录返回解析后的token
//extern std::string login_respons_signKey; // 存储登录返回解析后的signKey
//
UploadExeResult::UploadExeResult()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

bool UploadExeResult::ParserConfig(const std::string &SceneDetail_path)
{
    std::ifstream inf(SceneDetail_path);
    // 解析
    nlohmann::json data = nlohmann::json::parse(inf); // file may not exist, add later

    try
    {
        // 序列化
        std::string s = data.dump();
        std::cout << "json is:" << s << std::endl;
        uploadResultstr = s; // 序列化后的json串要作为请求体
    }
    catch (const std::exception &e)
    {
        inf.close();
        return false;
    }
    BuildTree(data);
    inf.close();
    return true;
}

void UploadExeResult::BuildTree(const nlohmann::json &data)
{
    request.url = data["url"];
    request.path = data["path"];
    request.data.serialNo = data["serialNo"];
    request.data.actionType = data["actionType"].get<int>();
    request.data.sceneId = data["sceneId"];
    request.data.startTime = data["startTime"];
    request.data.endTime = data["endTime"];
    request.data.result = data["result"].get<int>();
    request.data.exeDetail = data["exeDetail"];
}

bool UploadExeResult::ExeResultUpload(const std::string &eResult_path)
{
    std::string response;
    std::stringstream ss,ss2;
    ParserConfig(eResult_path);
    std::cout << "login_respons_token-->>:" << login_respons_token << std::endl;
    std::cout << "login_respons_signKey-->>:" << login_respons_signKey << std::endl;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    ss << ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
    header.timestamp = ss.str();
    ss.str("");
    std::cout << "timestamp: " << header.timestamp << std::endl;

    std::string SignKey = login_respons_signKey;
    Encode encode;
    //SignKey = encode.Sha256(SignKey);

    ss<<request.data.actionType;
    ss2<<request.data.result;
    header.token = login_respons_token;
    std::string headerToSign = "token=" + header.token + "&timestamp=" + header.timestamp;
    // jsonstr = "{\"serialNo\":\"" + request.data.serialNo+",\"actionType\":\""+request.data.actionType+",\"sceneId\":\""+request.data.sceneId+",\"startTime\":\""+request.data.startTime+",\"endTime\":\""+request.data.endTime+",\"result\":\""+request.data.result+",\"exeDetail\":\""+request.data.exeDetail+"}";
    jsonstr = "{\"serialNo\":\"" + request.data.serialNo +
              "\",\"actionType\":" + ss.str() +
              ",\"sceneId\":\"" + request.data.sceneId +
              "\",\"startTime\":\"" + request.data.startTime +
              "\",\"endTime\":\"" + request.data.endTime +
              "\",\"result\":" + ss2.str() +
              ",\"exeDetail\":\"" + request.data.exeDetail +
              "\"}";
    std::cout << "请求体jsonstr:" << jsonstr << std::endl;
    std::string stringToSign = request.path +"&token="+ login_respons_token+"&" + "timestamp=" + header.timestamp + "&null&" + jsonstr;
    std::cout << "HttpPost uploadExeResult headerToSign:" << headerToSign << std::endl;
    Signature signature;
    header.sign = signature.GetSignature(stringToSign, SignKey);//
    std::cout << "HttpPost uploadExeResult sign:" << header.sign << std::endl;

    // 发起请求
    HttpPost(request, response);
    // 请求响应
    std::cout << "HttpPost uploadExeResult response:" << response << std::endl;
    nlohmann::json LoginRes = nlohmann::json::parse(response);
    if ("000000" != LoginRes["code"].get<std::string>())
    {
        std::cout << "uploadExeResult failed" << std::endl;
        return false;
    }
    std::cout << "uploadExeResult success" << std::endl;
    return true;
}

size_t ExeResultWriteData(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::string *data = reinterpret_cast<std::string *>(userdata);
    if (data)
    {
        data->append(ptr, size * nmemb);
        return size * nmemb;
    }
    return 0;
}

size_t UpLoadWriteData(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::string *data = reinterpret_cast<std::string *>(userdata);
    if (data) {
        data->append(ptr, size * nmemb);
        return size * nmemb;
    }
    return 0;
}

std::string UploadExeResult::HttpPost(ExeResultReqRequest &request, std::string &response)
{
    CURL *curl = curl_easy_init();
    CURLcode res = CURLE_OK;
    if (curl)
    {
        struct curl_slist *chunk = NULL;
        curl_easy_setopt(curl, CURLOPT_URL, request.url.c_str());
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        std::stringstream ss;
        ss << "sign:" << header.sign;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        ss << "timestamp:" << header.timestamp;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        ss << "token:" << header.token;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        ss << "Content-Type: application/json";
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonstr.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, jsonstr.size());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, UpLoadWriteData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);

        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, CONNECTTIMEOUTDEFAULT);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, RESTIMEOUT);

        // start request
        res = curl_easy_perform(curl);
        // std::cout << "jsonstr:" << jsonstr << std::endl;
        if (res != CURLE_OK)
        {
            std::cout << "parse json failed:" << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return response;
}

UploadExeResult::~UploadExeResult()
{
    curl_global_cleanup();
}