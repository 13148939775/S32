
/*
 * @author 008196
 * @for custom scene manager read/conflict
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SCENE_CARD_H
#define SCENE_CARD_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <stack>
#include <functional>
#include <queue>
#include <set>

#include "nlohmann/json.hpp"
#include "meta_ability.h"

#include "node_log.h"
#include <utils/dbc/data_block_center.h>

using timeStamp = uint64_t;
class EnvironmentCond {

};

enum QueSrc : uint8_t{
    Waiting_Que,
    AlwaysOn_Que,
    Suspend_Que,
    Runing_Que
};

// first level: light/Door second level: left/right
class SceneCard : public DataBlockCenter::Observer ,public std::enable_shared_from_this<SceneCard>{
public:
    struct Function {
        Function(std::string& classificationCode0)
        :classificationCode(classificationCode0) {};
        ~Function() {};
        std::string classificationCode;
        std::vector<std::shared_ptr<MetaAbility>> functionDetails;
    };
    struct Action {
        Action(uint8_t& actionType0,std::string trigger0,std::string& condition0)
          : actionType(actionType0),
            trigger(trigger0),
            condition(condition0){ };
        ~Action() { };
        uint8_t actionType;
        std::string trigger;
        std::string condition;
        std::vector<std::shared_ptr<Function>> functions;
    };
    using SceneCardPtr = std::shared_ptr<SceneCard>;

public:
    SceneCard(const std::string& name, const std::string& id, const uint8_t& contributestatus,  const uint8_t& restore, 
    const uint8_t& priority)
      : name_(name),
        id_(id),
        contributeStatus_(contributestatus),
        restore_(restore),
        priority_(priority)
    { }

    virtual ~SceneCard() { }

    struct Cmp {
        bool operator()(const SceneCardPtr& a, const SceneCardPtr& b)
        {
            return a->priority_ > b->priority_;
        }
    };
    
    using SceneCardPtrPriQue = std::priority_queue<SceneCardPtr, std::vector<SceneCardPtr>, Cmp>;
    
    void Init();
    std::shared_ptr<SceneCard> getPtr(){
        return shared_from_this();
    }

    virtual void OnNotify(const DataBlockCenter& dbc);  // triggle this sc play while event occur

    void RemoveCategory(const std::shared_ptr<Function> cg);

    bool AddMeta(std::shared_ptr<Function>& cg, const std::shared_ptr<MetaAbility>& ability);

    bool RemoveMeta(std::shared_ptr<Function>& cg, const std::shared_ptr<MetaAbility>& ability);
    
    void RegisterStatusTrigger();

    void RegisterStatusCondition();

    void RegisterStatusInterrupt();

    const std::set<std::shared_ptr<MetaAbility>>& GetMetaAbilityGroup_() const 
    {
        return metaAbilityGroup_;
    }

    void SplitSceneTrigger(std::string& trigger)
    {
        std::stringstream ss(trigger);
        std::string substr;
        while (std::getline(ss, substr, '|') || std::getline(ss, substr, '&')) {
            if (!substr.empty()) {
                triggerVec_.push_back(substr);
            }
        }
    }

    void SplitSceneCondition(std::string& condition)
    {
        std::stringstream cc(condition);
        std::string substr;
        while (std::getline(cc, substr, '|') || std::getline(cc, substr, '&')) {
            if (!substr.empty()) {
                conditionVec_.push_back(substr);
            }
        }
    }

    void SplitSceneInterrupt(std::string& interrupt)
    {
        std::stringstream str(interrupt);
        std::string substr;
        while (std::getline(str, substr, '|') || std::getline(str, substr, '&')) {
            if (!substr.empty()) {
                interruptVec_.push_back(substr);
            }
        }
    }

    const std::string GetName() const
    {
        return name_;
    }

    const int GetPrority() const
    {
        return priority_;
    }

    const uint8_t GetSrc() const
    {
        return queSrc_;
    }

    const uint32_t GetEventID() const
    {
        return eventID_;
    }

    void SetSrc(const uint8_t& src)
    {
        queSrc_ = src;
    }
    
    void BuildDescriptMatrix();

    void BuildMetaMap(const nlohmann::json& data);

    void BuildTree(const nlohmann::json& data);

    static void BuildMetaAbility(const nlohmann::json& data);

    const std::vector<std::vector<std::string>>& GetMatrxiDes_() const
    {
        return matrixDes_;
    }

    static const std::vector<std::vector<std::string>>& GetZeroMatrxiDes_()
   {
        return zeroMatrixDes_;
    }

    void ExecuteMetaAbility();

private:
    std::string name_;
    std::string id_;
    uint8_t contributeStatus_;
    uint8_t restore_;
    uint8_t priority_;
    
    std::vector<std::string> triggerVec_;
    std::vector<std::string> conditionVec_;
    std::vector<std::string> interruptVec_;


    uint8_t queSrc_;
    uint8_t queDst_; 
    uint32_t eventID_;

    const int categorySize_ = 40;
    const int maxCategoryMem_ = 20;

    std::set<std::shared_ptr<MetaAbility>> metaAbilityGroup_;
    
    std::vector<std::shared_ptr<Function>> categories_;  // 
    std::vector<std::shared_ptr<Action>> actionList_;
    std::vector<std::vector<std::string>> matrixDes_;
    
    static std::vector<std::vector<std::string>> zeroMatrixDes_;
    static std::unordered_map<std::string, int> abilityPosMap_;

    uint32_t MetaAbilityExecCnt_{0}; 

    std::unordered_map<std::string, int> categoryPosMap_ = {
        {"DoorCategory",        0},
        {"LightCategory",       1},
        {"LightColorCategory",  2},
        {"MusicLightCategory",  3},
        {"AirConditioningTemp", 4},
        {"AirConditioningWind", 5},
        {"FragranceStyle",      6},
        {"LoveMusicStyle",      7},
    };

    

    std::unordered_map<std::string, int> categorySizeTable_ = {
        {"DoorCategory",        3},
        {"LightCategory",       3},
        {"LightColorCategory",  3},
        {"MusicLightCategory",  3},
        {"AirConditioningTemp", 3},
        {"AirConditioningWind", 3},
        {"FragranceStyle",      3},
        {"LoveMusicStyle",      3},
    };
};

#endif