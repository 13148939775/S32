#ifndef LOGIN_CLOUD_H
#define LOGIN_CLOUD_H

#include <string>
#include <nlohmann/json.hpp>

struct LoginHeader {
    std::string timestamp;	
    std::string sign;	
    std::string token;	
};


struct LoginRequest
{
    std::string url;    //请求url
    std::string path;    //请求url
    std::string vin;    //车架号 必填
    std::string sn;     //Idcm 序列号 必填
    std::string lng;    //纬度
    std::string lat;    //经度
    // std::string certificate;    //证书序列号
};

class LoginCloud {
public:
    static LoginCloud& GetInstance()
    {
        static LoginCloud lc;
        return lc;
    }
private:
    LoginCloud();
    ~LoginCloud();

public:
    bool ParserConfig(const std::string &login);
    void BuildTree(const nlohmann::json &data);
    bool Login(const std::string &login);
    std::string HttpPost(LoginRequest &request, std::string &response);
    void parseResponse(const std::string &login_respons);

    std::string& GetLoginRespons()
    {
        return LoginRespons;
    }

    std::string& GetResponseToken()
    {
        return respons_token;
    }

    std::string& GetResponseSignKey()
    {
        return respons_signKey;
    }
private:
    LoginHeader header_;
    LoginRequest request_;
    std::string LoginRespons;
    std::string respons_token;    //存储登录返回解析后的token
    std::string respons_signKey;  //存储登录返回解析后的signKey
    std::string jsonstr;
    const int32_t CONNECTTIMEOUTDEFAULT = 20;
    const int32_t RESTIMEOUT = 60;
};

#endif