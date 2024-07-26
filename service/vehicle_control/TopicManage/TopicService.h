
/*
 * @author 008555
 * @for application log interface
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TOPIC_H
#define TOPIC_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <stack>
#include <functional>
#include <queue>
#include <set>

#include "nlohmann/json.hpp"
#include "TopicData_Center.h"

class TopicService : public TopticDataCenter::Observer {
public:
    struct TopicData
    {
        TopicData(uint32_t& kind, uint32_t& state)
        : kind(kind), state(state) {};
        ~TopicData() {};
        uint32_t  kind;
        uint32_t  state;
    };

    struct Category {
        Category(std::string& name)
          : name_(name) { }
        ~Category() { };
        std::string name_;
        //std::unordered_map<TopicData, uint32_t>  topicContextMap_;
    };

    using TopicPtr = std::shared_ptr<TopicService>;
    using TopicQueue = std::queue<TopicPtr>;
public:
    TopicService(const std::string& Name, const std::string& qname, const uint8_t& sendType, const bool trigger);

    virtual ~TopicService() { }

    void ConstructTopicInfo(const nlohmann::json& data, const uint32_t index);
    
    void RegistryStatusCondition(std::string&  tname);

   void OnNotify(TopticDataCenter& siginfo);

    static void CreateDDSThread();
public:
    std::string& GetTopicName(){
        return topicName_;
    }

    const bool GetTopicTrigger() const {
        return trigger_;
    }

    const uint8_t GetSendStrategy() const {
        return sendStrategy_;
    }

private:
    std::string topicName_;
    std::string reqName_;
    uint8_t sendStrategy_;
    bool trigger_;
    std::vector<std::shared_ptr<Category>> categories_;
    static std::vector<uint8_t>  generalVehSt_;
};

#endif