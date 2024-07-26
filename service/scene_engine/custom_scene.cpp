/*
 * @author 008555
 * @for meta ability define
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "custom_scene.h"

#include <memory>
#include <iostream>
#include <memory>
#include <string>

#include "node_log.h"
#include "nlohmann/json.hpp"
#include <utils/math/matrix.h>
#include <utils/dbc/data_block_center.h>
#include "event_occur/sim_trigger_event.h"


bool CustomScene::ValidJson(const nlohmann::json& data)
{
    return true;
}
// build Tree
bool CustomScene::BuildTree(const nlohmann::json& data)
{
    if (!ValidJson(data)) {
        HHT_LOG(ERROR)<<"wrong Json version";
        return false;
    }
    std::shared_ptr<SceneCard> scPtr;
    std::string name;
    std::string id;
    std::string trigger;
    std::string condition;
    std::string interrupt;
    int restore = 0;
    int contributeStatus = 0;
    int priority = 0;

    HHT_LOG(INFO)<<"Build Scene Tree";

    if (data["data"].contains("name")) {
        name = data["data"]["name"];
    }
    if (data["data"].contains("sceneId")) {
        id = data["data"]["sceneId"];
    }
    if (data["data"].contains("contributeStatus")) {
        contributeStatus = data["data"]["contributeStatus"];
    }
    if (data["data"].contains("restore")) {
        restore = data["data"]["restore"];
    }
    if (data["data"].contains("priority")) {
        priority = data["data"]["priority"];
    }
    if (data["data"].contains("trigger")) {
        trigger = data["data"]["trigger"];
    }
    if (data["data"].contains("condition")) {
        condition = data["data"]["condition"];
    }
    if (data["data"].contains("interrupt")) {
        interrupt = data["data"]["interrupt"];
    }
    scPtr = std::make_shared<SceneCard>(name, id, contributeStatus,restore, priority);
    CustomScene::GetInstance().AddSceneCard(scPtr);
    scPtr->SplitSceneTrigger(trigger);
    scPtr->SplitSceneCondition(condition);
    scPtr->SplitSceneInterrupt(interrupt);
    
    scPtr->BuildTree(data);
    scPtr->RegisterStatusCondition();

    return true;
}

void CustomScene::BuildMetaTopicTree(const nlohmann::json& data)
{
    SceneCard::BuildMetaAbility(data);
}
// classify scenecard,
void CustomScene::ExecuteTree()
{
    HHT_LOG(INFO)<<"CustomScene ExecuteTree";
    if (sceneCardVec_.empty()) {
        HHT_LOG(ERROR)<<"Custom SC is empty";
        return;
    }
    for (auto& scPtr : sceneCardVec_) {
        // add to the running thread
        if (scPtr->GetPrority() == static_cast<int>(-1)) {
            this->PushAlwaysQueScene(scPtr);
        } else {
            //this->PushWaitingQueScene(scPtr);
            this->PushRunQueScene(scPtr);
        }
    }
    
}

//jude piority conflict between scenecards
bool CustomScene::BuildAdj()
{
    const uint32_t size = sceneCardVec_.size();
    if (size == 1) {
        return false;
    }
    for (uint32_t i = 0; i < size; ++i) {
        std::shared_ptr<SceneCard> scSrcPtr = sceneCardVec_[i];
        for (uint32_t i = 0; i < size; ++i) {
            std::shared_ptr<SceneCard> scComPtr = sceneCardVec_[i];
            if (scSrcPtr->GetName() == scComPtr->GetName()) {
                continue;
            }
            if (Matrix::judgeConflict(scSrcPtr->GetMatrxiDes_(), scComPtr->GetMatrxiDes_()) == true) {
                adjMapV_[scSrcPtr].push_back(scComPtr);
            }
        }
    }
    return true;
}

bool CustomScene::JudegeRunQueConflict(const std::shared_ptr<SceneCard>& scr, const std::shared_ptr<SceneCard>& smp)
{
    bool fndsign = false;
    //HHT_LOG_INFO("CustomScene JudegeRunQueConflict");
    for(auto &scr : adjMapV_[scr]) {
        if (scr->GetName() == smp->GetName()) {
            fndsign = true;
            break;
        }
    }
    return fndsign;
}

void CustomScene::PublishScene(std::shared_ptr<SceneCard>& scr)
{
    bool fndsign = false;
    SceneCardPtr smp;
    //HHT_LOG_INFO("Custom Scene PublishScene");
    if (Scheduler<SceneCardPtr, CustomScene>::GetInstance().IsRunningQueEmpty()) {
        if (scr->GetPrority() == static_cast<int>(-1)) {
            Scheduler<SceneCardPtr, CustomScene>::GetInstance().PoptoAlwaysQue(smp);
        } else {
            CustomScene::GetInstance().PopWaitQueScene(smp);
        }
        CustomScene::GetInstance().PushRunQueScene(smp);
    } else {
        if (scr->GetSrc() == Waiting_Que) {
            CustomScene::GetInstance().PopWaitQueScene(scr);
        }    
        uint32_t size = Scheduler<SceneCardPtr, CustomScene>::GetInstance().GetRunningQueSize();
        for (uint32_t i=0; i < size; ++i) {
            Scheduler<SceneCardPtr, CustomScene>::GetInstance().PoptoRunningQue(smp);
            if ((JudegeRunQueConflict(scr,smp) == true) && scr->GetPrority() > smp->GetPrority()) {
                if (smp->GetPrority() == static_cast<int>(-1)) { 
                    CustomScene::GetInstance().PushAlwaysQueScene(smp);
                } else {
                    CustomScene::GetInstance().PushSuspendQueScene(smp);
                }
                CustomScene::GetInstance().PushRunQueScene(scr);
                fndsign = true;
                std::cout<<scr->GetName()<<" 与 "<<smp->GetName()<<" 场景冲突"<<std::endl;
            } else {
                CustomScene::GetInstance().PushRunQueScene(smp);
            }
        }
        if (fndsign == false) {
            CustomScene::GetInstance().PushRunQueScene(scr);
        }  
    }
}
void CustomScene::CancelScene(std::shared_ptr<SceneCard>& scr)
{
    int pority = -1;
    SceneCardPtr smp;
    //HHT_LOG_INFO("Custom Scene CancelScene");
    if (Scheduler<SceneCardPtr, CustomScene>::GetInstance().isSuspendQueEmpty()) {
        if (scr->GetSrc() == Runing_Que) {
            PopRunQueScene(scr);
            PushWaitingQueScene(scr);
            if (Scheduler<SceneCardPtr, CustomScene>::GetInstance().IsRunningQueEmpty()) {
                Scheduler<SceneCardPtr, CustomScene>::GetInstance().PoptoAlwaysQue(smp);
                PushRunQueScene(smp);
            }
        }
    } else {
        if (scr->GetSrc() == Runing_Que) {
            PopRunQueScene(scr);
            if(scr->GetPrority() == static_cast<int>(-1)) {
                PushAlwaysQueScene(scr);
            } else {
                PushWaitingQueScene(scr);
            }
            uint32_t size = Scheduler<SceneCardPtr, CustomScene>::GetInstance().GetSuspendQueSize();
            for (uint32_t i=0; i < size; ++i) {
                Scheduler<SceneCardPtr, CustomScene>::GetInstance().PoptoSuspendQue(smp);
                if((JudegeRunQueConflict(scr,smp) == true) && smp->GetPrority() > pority){
                    pority = smp->GetPrority();
                 }
                 Scheduler<SceneCardPtr, CustomScene>::GetInstance().AddtoSuspendQue(smp);
            }

            for(uint32_t i=0; i < size; ++i){
                Scheduler<SceneCardPtr, CustomScene>::GetInstance().PoptoSuspendQue(smp);
                if((JudegeRunQueConflict(scr,smp) == true) && smp->GetPrority() == pority){
                    PopSuspendQueScene(smp);
                    PushRunQueScene(smp);

                    std::cout<<scr->GetName()<<" 退出场景运行 "<<"与之相冲突的场景上线运行"<<smp->GetName()<<std::endl;
                 } else {
                    Scheduler<SceneCardPtr, CustomScene>::GetInstance().AddtoSuspendQue(smp);
                 } 
            }
        }
    }
}

void CustomScene::PrintSC()
{   
    SceneCardPtr smp;
    HHT_LOG(INFO)<<"Scene Execute Meta Ability";
    uint32_t RunSize = Scheduler<SceneCardPtr, CustomScene>::GetInstance().GetRunningQueSize();
    for (uint32_t i=0; i < RunSize; ++i) {
         Scheduler<SceneCardPtr, CustomScene>::GetInstance().PoptoRunningQue(smp);
         std::cout<<"<<----------结果---------->>"<<smp->GetName()<<"正在运行"<<std::endl;
         smp->ExecuteMetaAbility();
         PushRunQueScene(smp);
    }
}

void CustomScene::PopRunQueScene(std::shared_ptr<SceneCard>& scr)
{
    uint32_t size = Scheduler<SceneCardPtr, CustomScene>::GetInstance().GetRunningQueSize();
    std::shared_ptr<SceneCard> cmp;
    for (uint32_t i=0; i < size; ++i) {
        Scheduler<SceneCardPtr, CustomScene>::GetInstance().PoptoRunningQue(cmp);
        if (scr->GetName() != cmp->GetName()) {
            Scheduler<SceneCardPtr, CustomScene>::GetInstance().AddtoRunningQue(cmp);
        }
    }
}
void CustomScene::PopSuspendQueScene(std::shared_ptr<SceneCard>& scr)
{
    uint32_t size = Scheduler<SceneCardPtr, CustomScene>::GetInstance().GetSuspendQueSize();
    std::shared_ptr<SceneCard> cmp;
    for (uint32_t i=0; i < size; ++i) {
        Scheduler<SceneCardPtr, CustomScene>::GetInstance().PoptoSuspendQue(cmp);
        if (scr->GetName() != cmp->GetName()) {
            Scheduler<SceneCardPtr, CustomScene>::GetInstance().AddtoSuspendQue(cmp);
        }
    }
}
void CustomScene::PopWaitQueScene(std::shared_ptr<SceneCard>& scr)
{
    uint32_t size = Scheduler<SceneCardPtr, CustomScene>::GetInstance().GetWaitingQueSize();
    std::shared_ptr<SceneCard> cmp;
    for (uint32_t i=0; i < size; ++i) {
        Scheduler<SceneCardPtr, CustomScene>::GetInstance().PoptoWaitingQue(cmp);
        if (scr->GetName() != cmp->GetName()) {
            Scheduler<SceneCardPtr, CustomScene>::GetInstance().AddtoWaitingQue(cmp);
        }
    }
}


void CustomScene::ExecuteSceneSchedule()
{
    std::shared_ptr<SimTriggerEventTable>  simTrigger = std::make_shared<SimTriggerEventTable>();
    
    //register default event;
    std::string topic = "Scene1";
    printf("1.打开 场景1\t\n");
    simTrigger->PublishEvent(topic);
    DataBlockCenter::GetInstance().Notify(topic);

    printf("2.打开 场景2 \t\n");
    topic = "Scene2";
    simTrigger->PublishEvent(topic);
    DataBlockCenter::GetInstance().Notify(topic);

    PrintSC();
}


