
#include "sceneCard.h"
#include "custom_scene.h"
#include <algorithm>
#include "node_log.h"

std::vector<std::vector<std::string>> SceneCard::zeroMatrixDes_(0);
std::unordered_map<std::string, int> SceneCard::abilityPosMap_;

void SceneCard::Init()
{
    HHT_LOG(INFO)<<"Init MatrixDes";
    matrixDes_.resize(categorySize_);
    for (int i = 0; i < categorySize_; ++i) {
        matrixDes_[i].resize(maxCategoryMem_);
    }
}

void SceneCard::OnNotify(const DataBlockCenter& dbc)
{
    HHT_LOG(INFO)<<"SceneCard Notify"<<name_;
    std::shared_ptr<SceneCard> SC = getPtr();
    if (dbc.GetFlag() == this->GetEventID()) {
        if (DataBlockCenter::GetInstance().GetEventState()) {
            CustomScene::GetInstance().PublishScene(SC);
        } else {
            CustomScene::GetInstance().CancelScene(SC);
        }
            
    }
}

bool SceneCard::AddMeta(std::shared_ptr<Function>& cg, const std::shared_ptr<MetaAbility>& ability)
{
    int pos = 0;
    if (abilityPosMap_.count(ability->GetFunctionCode()) > 0 ) {
        pos = abilityPosMap_[ability->GetFunctionCode()];
    } else {
        pos = 0;
    }
    cg->functionDetails[pos] = ability;
    return true;
}

bool SceneCard::RemoveMeta(std::shared_ptr<Function>& cg, const std::shared_ptr<MetaAbility>& ability)
{
    int pos = 0;
    if (abilityPosMap_.count(ability->GetFunctionCode()) > 0 ) {
        pos = abilityPosMap_[ability->GetFunctionCode()];
    } else {
        pos = 0;
    }
    cg->functionDetails[pos] = nullptr;
    return true;
}

void SceneCard::RemoveCategory(const std::shared_ptr<Function> cg)
{
    std::vector<std::shared_ptr<Function>>::iterator it;
    for (it = categories_.begin(); it != categories_.end();) {
        if (*it == cg) {
            it = categories_.erase(it);
        } else {
            ++it;
        }
    }
}

void SceneCard::BuildDescriptMatrix()
{
    Init();
    for (const auto& ele : categories_) {
        int line = categoryPosMap_[ele->classificationCode];
        for (const auto& metaA : ele->functionDetails) {
            int col = abilityPosMap_[metaA->GetFunctionCode()];
            matrixDes_[line][col] = metaA->GetfunctionValue();
        }
    }
}

void SceneCard::BuildMetaMap(const nlohmann::json& data)
{
    std::string metaName;
    std::string topicName;
    uint8_t pos;
    uint32_t size = data["Meta2Topic"].size();
    for (uint32_t i = 0; i < size; ++i) {
        metaName = data["Meta2Topic"][i]["MetaAbility"];
        pos =  data["Meta2Topic"][i]["Position"];
        abilityPosMap_[metaName] = pos;
    }  
}

void SceneCard::BuildMetaAbility(const nlohmann::json& data)
{
    MetaAbility::ReadMeta2Topic(data);
}

void SceneCard::BuildTree(const nlohmann::json& data)
{
    std::string name;
    std::string functionCode;
    std::string functionValue;
    std::string classificationCode;
    uint8_t cycleCount; 
    uint8_t acton_Type;
    std::string action_condition;
    std::string action_trigger;
    uint16_t actionCnt = data["data"]["actionList"].size();
    HHT_LOG(INFO)<<"SceneCard Build Tree";
    
    for (uint16_t j = 0; j < actionCnt; ++j) { 
        action_trigger = data["data"]["actionList"][j]["trigger"];
        action_condition = data["data"]["actionList"][j]["condition"];
        acton_Type = data["data"]["actionList"][j]["actionType"];
        std::shared_ptr<Action> actionPtr = std::make_shared<Action>(acton_Type, action_trigger, action_condition);

        uint16_t functionCnt = data["data"]["actionList"][j]["functionList"].size();
        for (uint16_t k = 0; k < functionCnt; ++k) {
            classificationCode = data["data"]["actionList"][j]["functionList"][k]["classificationCode"];
            std::shared_ptr<Function> funPtr = std::make_shared<Function>(classificationCode);
            uint16_t funDetailCnt = data["data"]["actionList"][j]["functionList"][k]["functionDetailList"].size();
            for(uint16_t dk = 0; dk < funDetailCnt; ++dk) {
                functionCode =  data["data"]["actionList"][j]["functionList"][k]["functionDetailList"][dk]["functionCode"];
                functionValue = data["data"]["actionList"][j]["functionList"][k]["functionDetailList"][dk]["functionValue"];
                cycleCount    = data["data"]["actionList"][j]["functionList"][k]["functionDetailList"][dk]["cycleCount"];
                std::shared_ptr<MetaAbility> metaPtr = std::make_shared<MetaAbility>(functionCode, functionValue, cycleCount, 0);
                funPtr->functionDetails.push_back(metaPtr);
            }
            actionPtr->functions.push_back(funPtr);
            categories_.push_back(funPtr);
        }

        actionList_.push_back(actionPtr);
    } 
    BuildDescriptMatrix();
}

void SceneCard::RegisterStatusTrigger()
{
    for(auto & eventID : triggerVec_) {
        DataBlockCenter::GetInstance().AttachObserver(eventID, this); 
    }
}

void SceneCard::RegisterStatusCondition()
{
    //DataBlockCenter::GetInstance().RemoveObserver(eventID, this); 
}

void SceneCard::RegisterStatusInterrupt()
{
    for(auto& eventID : interruptVec_) {
        DataBlockCenter::GetInstance().RemoveObserver(eventID, this); 
    }
}

void SceneCard::ExecuteMetaAbility()
{
    uint16_t i;
    DataBlockCenter dbc;

    for (auto& ac : actionList_) {
        for (auto& fun : ac->functions) {
            for (auto& fdetail : fun->functionDetails) {
                for(i = 0; i <= fdetail->GetCycleCount(); ++i) {
                    fdetail->OnNotify(dbc);
                }
            }
        }
    }
}
