
#include "custom_scene_manager.h"

#include <vector>
#include <fstream>
#include <iostream>
#include "node_log.h"

bool CustomSceneManager::ReadAllSceneJson(std::vector<std::string>& vecStr)
{
    HHT_LOG(INFO)<<"Read All Scene Json Size:"<<vecStr.size();
    for(size_t i =0; i < vecStr.size(); ++i) {
        InitSceneJson(vecStr[i]);
    }
    return true;
}

bool CustomSceneManager::InitSceneJson(const std::string& configFile)
{
    HHT_LOG(INFO)<<"Init Scene Json";
    return ParserConfig(configFile);
}

bool CustomSceneManager::ScheduleStart()
{
    return CustomScene::GetInstance().EnvSetup();//scheduler start
}

bool CustomSceneManager::InitMeta2Topic(const std::string& configFile)
{
    HHT_LOG(INFO)<<"Init Scene Json";
    ParserMetaConfig(configFile);
    return true;
}


bool CustomSceneManager::Start()
{
    HHT_LOG(INFO)<<"CustomScene ExecuteTree";
    CustomScene::GetInstance().ExecuteTree();
    HHT_LOG(INFO)<<"CustomScene InitAdj";
    return CustomScene::GetInstance().InitAdj();
}

// read json and Build tree
bool CustomSceneManager::ParserConfig(const std::string& file)
{
    HHT_LOG(INFO)<<"read json and Build tree";
    std::ifstream inf(file);
    //解析
    nlohmann::json data = nlohmann::json::parse(inf);
        //序列化
    std::string s = data.dump();

    HHT_LOG(INFO)<< "json is:" << s << std::endl;

    BuildTree(data);
    
    return true;
}

bool CustomSceneManager::ParserMetaConfig(const std::string& file)
{
    std::ifstream inf(file);
    HHT_LOG(INFO)<<"Parse Meta Config";
    //解析
    nlohmann::json data = nlohmann::json::parse(inf);  // file may not exist, add later

    try {
        //序列化
        std::string s = data.dump();
        HHT_LOG(INFO)<< "json is:" << s << std::endl;
    } catch (const std::exception &e) {
        inf.close();
        return false;
    }
    HHT_LOG(INFO)<<"BuileMetaTree";
    
    BuileMetaTree(data);
    
    inf.close();

    return true;
}
//build Scene 
void CustomSceneManager::BuildTree(nlohmann::json& data)
{
    CustomScene::GetInstance().BuildTree(data);
}

void CustomSceneManager::BuileMetaTree(nlohmann::json& data)
{
    CustomScene::GetInstance().BuildMetaTopicTree(data);
}

//Scene Schedule
 bool CustomSceneManager::SceneSchedule()
 {
    CustomScene::GetInstance().ExecuteSceneSchedule();
    return true;
 }