#ifndef SCENE_CLOUD_H
#define SCENE_CLOUD_H

#include <string>
#include <vector>
#include <thread>

class SceneCloud {
public:
    static SceneCloud& GetInstance()
    {
        static SceneCloud sc;
        return sc;
    }
public:
    bool SceneCloudLogIn();

    bool GetSceneID(std::string& sceneid);

    void ReceiveScene();

    std::string GetSceneInfo();

    bool SceneIDSplit(const std::string& file);

    bool UploadExecResult();

    void SetUploadTime(std::string stime, std::string etime);
    void SetUploadDetail(std::string resdetailk, int res);

    std::vector<std::string>& GetSceneVec()
    {
        return sceneVec_;
    }
private:
    std::string sceneID_;
    std::vector<std::string> sceneVec_;

    std::string result;
private:
    std::string login_respons;    //存储登录返回结果
    std::string login_respons_token;    //存储登录返回解析后的token
    std::string login_respons_signKey;  //存储登录返回解析后的signKey

    std::string loginpath = "/work/liao_work/git625/s32-Apps/service/scene_engine/http_comm/A_login.json";
    std::string scenepath = "/work/liao_work/git625/s32-Apps/service/scene_engine/http_comm/A_SceneDetail.json";
    std::string respath = "/work/liao_work/git625/s32-Apps/service/scene_engine/http_comm/A_ExeResult.json";
};

#endif