/*
 * @author 001293
 * @Processing HTTP requests and responses.
 * @version 1.0
 * @date 2023-05 ~ 2023-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOG_HTTP_CLIENT_H
#define LOG_HTTP_CLIENT_H

#include <string>

struct Header {
    std::string timestamp;	
    std::string signature;	
    std::string token;
    std::string accessKeyId;	
};

struct Form {
    std::string key;
    std::string token;
    std::string obsExpires;
    std::string file;
};

struct Request {
    Header header;
    Form form;
    std::string data;
    std::string url;
};

struct Response{
    std::string response;
    int64_t httpCode;
};

class LogHttpClient {
public:
    static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
    bool HttpGet(Request& request, std::string& response);
    bool HttpPostData(Request& request, std::string& response);
    bool HttpPost(Request& request, Response& response);
    std::string GetResponse();

private:
    static const int32_t CONNECTTIMEOUTDEFAULT = 20;
    static const int32_t RESTIMEOUT = 60;
    static std::string response_;
};

#endif