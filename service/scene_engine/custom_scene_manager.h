
/*
 * @author 008555
 * @for meta ability define
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SCENE_TREE_MANAGER
#define SCENE_TREE_MANAGER

#include <string>
#include "nlohmann/json.hpp"
#include "custom_scene.h"

class CustomSceneManager {
public:
    explicit CustomSceneManager(const std::string& file = "")
      : configFile_(file) { }
      
    static CustomSceneManager& GetInstance()
    {
        static CustomSceneManager cs;
        return cs;
    }
    bool InitSceneJson(const std::string& configFile);

    bool InitMeta2Topic(const std::string& configFile);

    bool ReadAllSceneJson(std::vector<std::string>& vecStr);

    bool ScheduleStart();

    bool Start();

    bool ParserConfig(const std::string& file);

    bool ParserMetaConfig(const std::string& file);

    void BuildTree(nlohmann::json& data);

    void BuileMetaTree(nlohmann::json& data);

    bool SceneSchedule();
    
private:
    std::string configFile_;
};

#endif /* SCENE_TREE_MANAGER */
