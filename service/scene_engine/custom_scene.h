
/*
 * @author 008555
 * @for meta ability define
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CUSTOM_SCENE_H
#define CUSTOM_SCENE_H

#include <list>
#include <unordered_map>
#include <thread>

#include "nlohmann/json.hpp"
#include "sceneCard.h"
#include "scheduler/scheduler.h"
#include "node_log.h"

class CustomScene {
using SceneCardPtr = std::shared_ptr<SceneCard>;
using SceneCardPtrPriQue = std::priority_queue<SceneCardPtr, std::vector<SceneCardPtr>, SceneCard::Cmp>;
public:
    struct SceneCardInfo {
        int id;
        int type;
        std::string description;
        bool trigger;
    };

    static CustomScene& GetInstance()
    {
        static CustomScene cs;
        return cs;
    }
    
    bool InitAdj()
    {
        return BuildAdj();
    }
    
    bool ValidJson(const nlohmann::json& data);

    bool BuildTree(const nlohmann::json& data);

    void BuildMetaTopicTree(const nlohmann::json& data);

    bool BuildAdj();
    //based on type classify
    void ExecuteTree();

    void ExecuteSceneSchedule();

    void PrintSC();

    void AddSceneCard(const SceneCardPtr& scPtr)
    {
        sceneCardVec_.emplace_back(scPtr);
    }

    void RemoveSceneCard()
    {
        sceneCardVec_.pop_back();
    }

    const uint16_t GetSize() const
    {
        return sceneCardVec_.size();
    }

    bool EnvSetup()
    {
        Scheduler<SceneCardPtr, CustomScene>::GetInstance().Start();
        return true;
    }

    std::unordered_map<std::shared_ptr<SceneCard>, std::vector<SceneCardPtr>> GetAdjMapV() const
    {
        return adjMapV_;
    }

    bool JudegeRunQueConflict(const std::shared_ptr<SceneCard>& scr, const std::shared_ptr<SceneCard>& smp);

    void PublishScene(std::shared_ptr<SceneCard>& scr);
    void CancelScene(std::shared_ptr<SceneCard>& scr);

    void PopRunQueScene(std::shared_ptr<SceneCard>& scr);
    void PopSuspendQueScene(std::shared_ptr<SceneCard>& scr);
    void PopWaitQueScene(std::shared_ptr<SceneCard>& scr);

    void PushRunQueScene(std::shared_ptr<SceneCard>& scr)
    {   
        Scheduler<SceneCardPtr, CustomScene>::GetInstance().AddtoRunningQue(scr);
        scr->SetSrc(Runing_Que);
    }
    void PushSuspendQueScene(std::shared_ptr<SceneCard>& scr)
    {
        Scheduler<SceneCardPtr, CustomScene>::GetInstance().AddtoSuspendQue(scr);
        scr->SetSrc(Suspend_Que);
    }
    void PushWaitingQueScene(std::shared_ptr<SceneCard>& scr)
    {
        Scheduler<SceneCardPtr, CustomScene>::GetInstance().AddtoWaitingQue(scr);
        scr->SetSrc(Waiting_Que);
    }
    void PushAlwaysQueScene(std::shared_ptr<SceneCard>& scr)
    {
        Scheduler<SceneCardPtr, CustomScene>::GetInstance().AddtoAlwaysQue(scr);
        scr->SetSrc(AlwaysOn_Que);
    }
private:
    CustomScene() 
    { 

    };
    ~CustomScene() = default;
    std::vector<std::shared_ptr<SceneCard>> sceneCardVec_; // top
    std::unordered_map<timeStamp, std::vector<MetaAbility>> metaAbilityMap_;
    std::unordered_map<std::shared_ptr<SceneCard>, std::vector<SceneCardPtr>> adjMapV_;
    std::thread th_;

};
#endif /* CUSTOM_SCENE_H */
