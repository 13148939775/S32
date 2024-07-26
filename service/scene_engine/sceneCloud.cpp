

#include "sceneCloud.h"

#include "LoginCloud.h"
#include "mqtt.h"
#include "UploadExeResult.h"
#include "GetSceneDetail.h"
#include "node_log.h"

bool SceneCloud::SceneCloudLogIn()
{
    HHT_LOG(INFO)<<"Scene Cloud Log In";
    bool res = LoginCloud::GetInstance().Login(loginpath);
    if (res == false) {
        return false;
    }
    login_respons = LoginCloud::GetInstance().GetLoginRespons();
    login_respons_token = LoginCloud::GetInstance().GetResponseToken();
    login_respons_signKey = LoginCloud::GetInstance().GetResponseSignKey();

    HHT_LOG(INFO)<<"Login Response"<<login_respons;
    HHT_LOG(INFO)<<"Login Token"<<login_respons_token;
    HHT_LOG(INFO)<<"Login SignKey"<<login_respons_signKey;
    return true;
}

void SceneCloud::ReceiveScene()
{
    HHT_LOG(INFO)<<"Scene Cloud Receive Scene";
    Mqtt& mqtt = Mqtt::GetInstance();
    std::thread th_([&mqtt]() {
        mqtt.MqttGet();
    });
    th_.detach();
}

bool SceneCloud::GetSceneID(std::string& sceneid)
{
    sceneID_ = Mqtt::GetInstance().GetSceneID();
    sceneid = sceneID_;
    HHT_LOG(INFO)<<"Scene Cloud Receive Scene"<<sceneid;
    return true;
}

std::string SceneCloud::GetSceneInfo()
{
    HHT_LOG(INFO)<<"Scene Cloud Get SceneInfo";
    GetSceneDetail::GetInstance().SetResponseToken(login_respons_token);
    GetSceneDetail::GetInstance().SetSignKey(login_respons_signKey);
    GetSceneDetail::GetInstance().SetLogInResponse(login_respons);
    GetSceneDetail::GetInstance().GetScene(scenepath);

    return GetSceneDetail::GetInstance().GetRes();
}

bool SceneCloud::SceneIDSplit(const std::string& file)
{
    HHT_LOG(INFO)<<"Scene Cloud SceneIDSplit";
        //解析
    nlohmann::json data = nlohmann::json::parse(file,nullptr, false);
        //序列化
    std::string s = data.dump();

    std::cout << "json is:" << s << std::endl;

    //
    std::cout<< "sceneidList:"<< data["sceneIdList"].size()<<std::endl;
    
    if(data["sceneIdList"].size() > 0) {
        for(size_t i=0; i < data["sceneIdList"].size(); ++i) {
            sceneVec_.push_back(data["sceneIdList"][i]);
        }  
    }
    return true;
}

bool SceneCloud::UploadExecResult()
{
    HHT_LOG(INFO)<<"Scene Cloud UploadExecResult";

    UploadExeResult::GetInstance().Setlogin_respons_token(login_respons_token);
    UploadExeResult::GetInstance().SetSignKey(login_respons_signKey);
    UploadExeResult::GetInstance().ExeResultUpload(respath);

    return true;
}


void SceneCloud::SetUploadTime(std::string stime, std::string etime)
{
    UploadExeResult::GetInstance().SetReuestTime(stime, etime);
}

void SceneCloud::SetUploadDetail(std::string resdetailk, int res)
{
    UploadExeResult::GetInstance().SetRequestRes(resdetailk, res);
}