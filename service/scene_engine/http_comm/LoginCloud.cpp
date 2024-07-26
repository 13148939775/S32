/*
 * @author 001293
 * @for application log interface under node manager
 * @version 0.1
 * @date 2023-06 ~ 2023-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "LoginCloud.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/time.h>
#include <curl/curl.h>
#include "Signature.h"
#include "Encode.h"


LoginCloud::LoginCloud()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

LoginCloud::~LoginCloud()
{
    curl_global_cleanup();
}

bool LoginCloud::ParserConfig(const std::string &login)
{
    std::ifstream inf(login);
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

void LoginCloud::BuildTree(const nlohmann::json &data)
{
    request_.url = data["data"]["url"];
    request_.path = data["data"]["path"];
    request_.vin = data["data"]["vin"];
    request_.sn = data["data"]["sn"];
    request_.lng = data["data"]["lng"];
    request_.lat = data["data"]["lat"];
    // request.certificate = data["data"]["certificate"];
}


// 登录使用post请求
bool LoginCloud::Login(const std::string &login)
{
    std::string response;
    ParserConfig(login); // 解析json

    std::stringstream ss;

    // header时间戳
    struct timeval tv;
    gettimeofday(&tv, NULL);
    ss << ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
    header_.timestamp = ss.str();
    ss.str("");
    std::cout << "timestamp: " << header_.timestamp << std::endl;
    std::string SignKey = request_.vin + header_.timestamp;
    Encode encode;
    SignKey = encode.Sha256(SignKey);

    // 登录token为空
    // 计算签名
    std::string headerToSign = "token=" + header_.token + "&" + "&timestamp=" + header_.timestamp;
    // std::string cqsString;  //登录cqsString为空
    jsonstr = "{\"url\":\"" + request_.url + "\",\"vin\":\"" + request_.vin + "\",\"sn\":\"" + request_.sn + 
    "\",\"lng\":\"" + request_.lng + "\",\"lat\":\""+request_.lat+"\"}"; 
    std::cout << "jsonstr:" << jsonstr << std::endl;
    std::string stringToSign = request_.path + "&" + "timestamp=" + header_.timestamp + "&" + jsonstr;
    std::cout << "HttpPost Login headerToSign:" << headerToSign << std::endl;
    std::cout << "HttpPost Login stringToSign:" << stringToSign << std::endl;
    Signature signature;
    header_.sign = signature.GetSignature(stringToSign, SignKey);
    std::cout << "HttpPost Login sign:" << header_.sign << std::endl;
    // 发起请求
    HttpPost(request_, LoginRespons);
    // 请求响应
    std::cout << "HttpPost Login response:" << LoginRespons << std::endl;
    nlohmann::json LoginRes = nlohmann::json::parse(LoginRespons);
    if ("000000" != LoginRes["code"].get<std::string>()) {
        std::cout << "Login failed, response is " << LoginRespons << std::endl;
        return false;
    }

    parseResponse(LoginRespons);
    std::cout << "Login success" << std::endl;
    return true;
}

size_t LoginWriteData(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::string *data = reinterpret_cast<std::string *>(userdata);
    if (data) {
        data->append(ptr, size * nmemb);
        return size * nmemb;
    }
    return 0;
}

// post请求登录
std::string LoginCloud::HttpPost(LoginRequest &request, std::string &response)
{
    CURL *curl = curl_easy_init();
    CURLcode res = CURLE_OK;
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, request.url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");

        struct curl_slist *chunk = NULL;
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        std::stringstream ss;
        ss << "sign:" << header_.sign;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        ss << "timestamp:" << header_.timestamp;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        ss << "token:" << header_.token;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        ss << "Content-Type: application/json";
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        // ss << "url:" << request.url;
        // chunk = curl_slist_append(chunk, ss.str().c_str());
        // ss.str("");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        
        // jsonstr = "{\"url\":\"https://iovcloud-test.human-horizons.com/user-core-data-service/v1/idcm/login/vehicleLogin/v1.0.1\",\"Vin\":\"HRYTTESTVINMGM270\",\"Sn\":\"HRYTTESTVINID0270\",\"lng\":\"0\",\"lat\":\"0\"}";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonstr.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, jsonstr.size());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, LoginWriteData);
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


void LoginCloud::parseResponse(const std::string &login_respons)
{
    auto j = nlohmann::json::parse(login_respons);

    respons_token = j["data"]["token"];
    respons_signKey = j["data"]["signKey"];

}

