
#include <string>
#include <vector>
#include "custom_scene_manager.h"
#include "sceneCloud.h"
#include "node_log.h"

int main()
{
    HHT::NodeLog node("SceneEngineLog");
    node.SetLevel(LOG_LEVEL_INFO,LOG_LEVEL_INFO,"/work/liao_wCDork/logs/");

    HHT_LOG(INFO)<<"Load meta to topic json";
    std::string path = "/work/liao_work/git625/s32-Apps/service/scene_engine/A_meta2topic.json";
    if (CustomSceneManager::GetInstance().InitMeta2Topic(path) == false) {
        HHT_LOG(ERROR)<<"Load meta to topic json failed";
        return -1;
    }

    path = "/work/liao_work/git625/s32-Apps/service/scene_engine/A_SPA.json";
    if (CustomSceneManager::GetInstance().InitSceneJson(path) == false) {
        HHT_LOG(ERROR)<<"CustomSceneManager InitSceneJson";
        return -1;
    }



    HHT_LOG(INFO)<<"Scene Cloud Log In";
    if (SceneCloud::GetInstance().SceneCloudLogIn() == false) {
        HHT_LOG(ERROR)<<"Scene Cloud LogIn failed";
        return -1;
    }

    SceneCloud::GetInstance().UploadExecResult();

    

    CustomSceneManager::GetInstance().Start();

    CustomSceneManager::GetInstance().SceneSchedule();

/*
    std::string sceneid;
    std::string scene_json;
    std::vector<std::string> sceneIDVect;
    SceneCloud::GetInstance().ReceiveScene();

    while(true) {
        SceneCloud::GetInstance().GetSceneID(sceneid);
        if(sceneid == "") {
            continue;
        }
            
        SceneCloud::GetInstance().SceneIDSplit(sceneid);
        
        sceneIDVect = SceneCloud::GetInstance().GetSceneVec();

        for(auto it : sceneIDVect) {
            scene_json = SceneCloud::GetInstance().GetSceneInfo();
            CustomSceneManager::GetInstance().InitSceneJson(scene_json);
        }

        CustomSceneManager::GetInstance().Start();

        CustomSceneManager::GetInstance().SceneSchedule();
    }
*/

    return 0;
}


