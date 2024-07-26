/*
 * @author 001293
 * @Processing HTTP requests and responses.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "LogHttpClient.h"
#include <chrono>
#include <thread> 
#include <sstream>    
#include <curl/curl.h>    
#include <node_log.h> 
   
std::string LogHttpClient::response_ = "";
constexpr long enableTLS = 1L;
size_t LogHttpClient::write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    [[maybe_unused]] struct cb_data *data = (struct cb_data *)userdata;
    response_ = std::string(ptr);
    size_t totalsize = nmemb * size;

    return totalsize;
}

bool LogHttpClient::HttpGet(Request &request, std::string &response)
{
    CURL *curl = curl_easy_init();
    CURLcode res = CURLE_OK;
    int retryCount = 0;  // 重试计数器
    int retryTime = 10;  //设置访问失败的话再次访问的间隔时间
    //重试retryEndCount次就等待sleepRetryTime分钟后再次尝试重试
    int retryEndCount = 3;  
    int sleepRetryTime = 1; 

    //if (curl != nullptr) {
    while (curl != nullptr) { 
        struct curl_slist *chunk = NULL;
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L); // debug info
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, enableTLS);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, enableTLS);
        curl_easy_setopt(curl, CURLOPT_CAINFO, "./certificate/HHTCA_Prod.pem");
        curl_easy_setopt(curl, CURLOPT_URL, request.url.c_str()); // url
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
        std::stringstream ss;
        ss << "accessKeyId:" << request.header.accessKeyId;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        ss << "sign:" << request.header.signature;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        ss << "timestamp:" << request.header.timestamp;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, CONNECTTIMEOUTDEFAULT);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, RESTIMEOUT);
        curl_version_info_data* vinfo = curl_version_info(CURLVERSION_NOW);
        HHT_LOG(INFO) << "CURL version: " << vinfo->version;
        HHT_LOG(INFO) << "TLS version: " << vinfo->ssl_version;
        // start request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            HHT_LOG(ERROR) << "curl HttpGet failed:" << curl_easy_strerror(res);
    	    HHT_LOG(INFO) << "Automatic retry in " << retryTime << "seconds:";
            std::this_thread::sleep_for(std::chrono::seconds(retryTime));  // 暂停等待10秒
            retryCount++;  // 增加重试计数
            HHT_LOG(INFO) << "The " << retryCount << "th retry is being performed";
     	    //每重试retryEndCount次之后就等待更长时间再次重试
            if ( (retryCount % retryEndCount) == 0) {
                HHT_LOG(ERROR) << "curl get failed: " << retryCount << " times, Please Check the network connection";
                HHT_LOG(ERROR) << " It will be retried in " << sleepRetryTime << "miniutes";
                std::this_thread::sleep_for(std::chrono::minutes(sleepRetryTime));  // 暂停等待sleepRetryTime分钟
            } 
     	    continue;
    	} else {
            HHT_LOG(INFO) << "curl sucessed:";
       	    break;  // 请求成功，跳出循环，继续执行接下来的程序
       	}
    }

    response = response_;
    curl_easy_cleanup(curl);
    return (res == CURLE_OK ? true : false);
}

bool LogHttpClient::HttpPostData(Request &request, std::string &response)
{
    CURL *curl = curl_easy_init();
    CURLcode res = CURLE_OK;

    if (curl != nullptr) {
        curl_easy_setopt(curl, CURLOPT_URL, request.url.c_str()); // url
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");

        struct curl_slist *chunk = NULL;
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L); // debug info
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, enableTLS);  
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, enableTLS);
        curl_easy_setopt(curl, CURLOPT_CAINFO, "./certificate/HHTCA_Prod.pem");

        std::stringstream ss;
        ss << "accessKeyId:" << request.header.accessKeyId;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        ss << "sign:" << request.header.signature;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        ss << "timestamp:" << request.header.timestamp;
        chunk = curl_slist_append(chunk, ss.str().c_str());
        ss.str("");
        chunk = curl_slist_append(chunk, "Content-Type:application/json;charset=UTF-8");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        /** set post fields */
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request.data.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, request.data.size());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, CONNECTTIMEOUTDEFAULT);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, RESTIMEOUT);

        // start request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            HHT_LOG(ERROR) << "curl HttpPost failed:" << curl_easy_strerror(res);
        }
    }
    response = response_;
    curl_easy_cleanup(curl);
    return (res == CURLE_OK ? true : false);
}

bool LogHttpClient::HttpPost(Request &request, Response &response)
{
    CURL *curl = curl_easy_init();
    CURLcode res = CURLE_OK;
    curl_httppost *formpost = NULL;
    curl_httppost *lastptr = NULL;
    int64_t ret;
    int64_t httpCode = 0;
    if (curl != nullptr) {
        curl_easy_setopt(curl, CURLOPT_URL, request.url.c_str());
        HHT_LOG(INFO) << "HttpPost url: " << request.url;
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");

        struct curl_slist *headers = NULL;
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_formadd(&formpost, &lastptr,
                     CURLFORM_COPYNAME, "key",
                     CURLFORM_COPYCONTENTS, request.form.key.c_str(), CURLFORM_END);
        HHT_LOG(INFO) << "HttpPost key: " << request.form.key;
        curl_formadd(&formpost, &lastptr,
                     CURLFORM_COPYNAME, "token",
                     CURLFORM_COPYCONTENTS, request.form.token.c_str(), CURLFORM_END);
        HHT_LOG(INFO) << "HttpPost token: " << request.form.token;
        curl_formadd(&formpost, &lastptr,
                     CURLFORM_COPYNAME, "x-obs-expires",
                     CURLFORM_COPYCONTENTS, request.form.obsExpires.c_str(), CURLFORM_END);
        HHT_LOG(INFO) << "HttpPost x-obs-expires: " << request.form.obsExpires;
        curl_formadd(&formpost, &lastptr,
                     CURLFORM_COPYNAME, "file",
                     CURLFORM_FILE, request.form.file.c_str(), CURLFORM_END);
        HHT_LOG(INFO) << "HttpPost file: " << request.form.file;
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &ret);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response.response);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, CONNECTTIMEOUTDEFAULT);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, RESTIMEOUT);

        // start request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::string curlOBSError = curl_easy_strerror(res);
            HHT_LOG(ERROR) << "curl HttpPost on OBS failed:" << curlOBSError;
            if (curlOBSError == "Timeout was reached") {
                std::this_thread::sleep_for(std::chrono::seconds(RESTIMEOUT));
                HttpPost(request, response);
            }
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
        HHT_LOG(INFO) << "HttpPost httpCode:" << httpCode;
        response.httpCode = httpCode;
    }
    response.response = response_;
    HHT_LOG(INFO) << "HttpPost response: " << response.response;
    curl_formfree(formpost);
    curl_easy_cleanup(curl);
    return (res == CURLE_OK ? true : false);
}
