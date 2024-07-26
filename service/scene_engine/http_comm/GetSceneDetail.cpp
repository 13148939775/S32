#include "GetSceneDetail.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/time.h>
#include <curl/curl.h>
#include <string>
#include "nlohmann/json.hpp"
#include "Signature.h"
#include "Encode.h"
// #include "LoginCloud.h" //使用全局变量LoginRespons

//extern std::string LoginRespons;
//std::string login_respons;    //存储登录返回结果
//std::string login_respons_token;    //存储登录返回解析后的token
//std::string login_respons_signKey;  //存储登录返回解析后的signKey

GetSceneDetail::GetSceneDetail()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

//解析登录后返回的json串,存入对应结构体
void GetSceneDetail::parseGetSceneResponse(const std::string &login_respons)
{
    
    std::cout << "场景详情接收登录返回的response" <<login_respons<< std::endl;
    auto j = nlohmann::json::parse(login_respons);

    getSceneResponse = {
        j["code"].get<std::string>(),
        j["msg"].get<std::string>(),
        {j["data"]["token"].get<std::string>(),
         j["data"]["signKey"].get<std::string>(),
         j["data"]["expire"].get<long>(),
         j["data"]["activateFlag"].get<int>()}};

    std::cout << "解析后response" << std::endl;
    std::cout << "code: " << getSceneResponse.code << ", msg: " << getSceneResponse.msg << std::endl;
    std::cout << R"(token: )" << getSceneResponse.data.token
              << R"(, signKey: )" << getSceneResponse.data.signKey
              << R"(, expire: )" << getSceneResponse.data.expire
              << R"(, activateFlag: )" << getSceneResponse.data.activateFlag
              << std::endl;
    respons_token_ = getSceneResponse.data.token;
    respons_signKey_ = getSceneResponse.data.signKey;
    // return getSceneResponse;
}


bool GetSceneDetail::ParserConfig(const std::string &SceneDetail_path)
{
    std::ifstream inf(SceneDetail_path);
    //解析
    nlohmann::json data = nlohmann::json::parse(inf); // file may not exist, add later

    try
    {
        //序列化
        std::string s = data.dump();
        std::cout << "json is:" << s << std::endl;
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

void GetSceneDetail::BuildTree(const nlohmann::json &data)
{
    request.url = data["data"]["url"];
    request.path = data["data"]["path"];
    request.vin = data["data"]["vin"];
    request.sn = data["data"]["sn"];
    request.sceneIds = data["data"]["sceneIds"];
}

bool GetSceneDetail::GetScene(const std::string &SceneDetail_path)
{
    
    std::stringstream ss;
    ParserConfig(SceneDetail_path); // 解析json

    parseGetSceneResponse(respons_);

    // header时间戳
    struct timeval tv;
    gettimeofday(&tv, NULL);
    ss << ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
    header.timestamp = ss.str();
    ss.str("");
    std::cout << "timestamp: " << header.timestamp << std::endl;

    // std::string SignKey = request.vin + header.timestamp;
    std::string SignKey = getSceneResponse.data.signKey;
    // Encode encode;
    // SignKey = encode.Sha256(SignKey);
    std::cout << "HttpGet GetScene SignKey:" << SignKey << std::endl;

    //签名
    header.token = getSceneResponse.data.token;
    std::string headerToSign = "token=" + header.token + "&timestamp=" + header.timestamp;
    std::string cqsString;
    cqsString = request.sceneIds;
    Signature signature;
    std::cout << "HttpGet GetScene cqsString:" << cqsString << std::endl;
    cqsString = signature.GetUrlEncode(cqsString);
    std::cout << "HttpGet GetScene cqsString:" << cqsString << std::endl;
    std::string stringToSign = request.path + "&" + headerToSign + "&sceneIds=" + cqsString;
    std::cout << "HttpGet GetScene headerToSign:" << headerToSign << std::endl;
    std::cout << "HttpGet GetScene stringToSign:" << stringToSign << std::endl;
    
    header.sign = signature.GetSignature(stringToSign, SignKey);
    std::cout << "HttpGet GetScene sign:" << header.sign << std::endl;
    request.url = request.url + "?sceneIds=" + request.sceneIds;
    // 发起请求
    HttpGet(request, response);
    // 请求响应
    std::cout << "HttpGet GetScene response:" << response << std::endl;
    nlohmann::json LoginRes = nlohmann::json::parse(response);
    if ("000000" != LoginRes["code"].get<std::string>())
    {
        std::cout << "GetScene failed, response is " << response << std::endl;
        return false;
    }
    std::cout << "GetScene success, response is " << response << std::endl;
    return true;
}

size_t GetSceneWriteData(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::string *data = reinterpret_cast<std::string *>(userdata);
    if (data)
    {
        data->append(ptr, size * nmemb);
        return size * nmemb;
    }
    return 0;
}
std::string GetSceneDetail::HttpGet(GetSceneRequest &request, std::string &response)
{
    CURL *curl = curl_easy_init();
    CURLcode res = CURLE_OK;
    if (curl)
    {
        struct curl_slist *chunk = NULL;
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_URL, request.url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);

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
        // ss << "url:" << request.url;
        // chunk = curl_slist_append(chunk, ss.str().c_str());
        // ss.str("");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, GetSceneWriteData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, CONNECTTIMEOUTDEFAULT);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, RESTIMEOUT);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            std::cout << "curl get failed:" << curl_easy_strerror(res) << std::endl;
        }
        else
        {
            std::cout << "curl sucessed" << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return response;
}

GetSceneDetail::~GetSceneDetail()
{
    curl_global_cleanup();
}