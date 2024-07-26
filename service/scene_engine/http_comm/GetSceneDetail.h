#ifndef GET_SCENE_DETAIL_H
#define GET_SCENE_DETAIL_H
#include <string>
// #include <list>
#include "nlohmann/json.hpp"

struct GetSceneHeader
{
    std::string timestamp;
    std::string sign;
    std::string token;
};

struct GetSceneRequest
{
    std::string url;    //请求url
    std::string path;    //请求url
    std::string vin;    //车架号
    std::string sn;     //Idcm 序列号
    std::string sceneIds;    //场景 id
    // std::list<std::string> sceneIdList;    //场景 id 集合
};

//车辆登陆返回结果
struct VehicleLoginResponse{
    std::string token;  //访问时使用的令牌
    std::string signKey;    //签名需要使用到的 key（32位）
    long expire;    //超过时间会过期
    int activateFlag;   //是否激活 0：激活 1：未激活 2: 展销激活
};  

struct GetSceneResponse{
    std::string code;
    std::string msg;
    VehicleLoginResponse data;
};

class GetSceneDetail
{
public:
    static GetSceneDetail& GetInstance()
    {
        static GetSceneDetail gsd;
        return gsd;
    }

private:
    GetSceneDetail();
    ~GetSceneDetail();
    
public:
    bool GetScene(const std::string &SceneDetail_path);
    bool ParserConfig(const std::string& SceneDetail_path);  //解析json串
    void BuildTree(const nlohmann::json& data);  //处理json
    void parseGetSceneResponse(const std::string& jsonData);
public:
    //获取场景详情 使用get
    std::string HttpGet(GetSceneRequest &request, std::string &response);


    void SetResponseToken(std::string& responstoken)
    {
        respons_token_ = responstoken;
    }

    void SetSignKey(std::string& signkey)
    {
        respons_signKey_ = signkey;
    }

    void SetLogInResponse(std::string& respons)
    {
        respons_ = respons;
    }

    std::string GetRes()
    {
        return response;
    }

private:
    GetSceneHeader header;
    GetSceneRequest request;
    std::string jsonstr;
    static const int32_t CONNECTTIMEOUTDEFAULT = 20;
    static const int32_t RESTIMEOUT = 60;
    GetSceneResponse getSceneResponse;

    std::string respons_token_;
    std::string respons_signKey_;
    std::string respons_;
    std::string response;
};

#endif