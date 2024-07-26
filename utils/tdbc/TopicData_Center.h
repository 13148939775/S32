/*
 * @author 008555
 * @for application log interface
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TOPICDATA_CENTER_H
#define TOPICDATA_CENTER_H

#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "TopicData_Block.h"
class TopticDataCenter {
public:
    class Observer {
    public:
        virtual void OnNotify(TopticDataCenter& siginfo) = 0;
    };
public:
    static TopticDataCenter& GetInstance()
    {
        static TopticDataCenter dbc;
        return dbc;
    }


    bool AttachObserver(std::string& blk, Observer* ob)
    {
        auto res = observers_[blk].insert(ob);
        return res.second;
    }

    bool RemoveObserver(std::string& blk, Observer* ob)
    {
        auto res = observers_[blk].erase(ob);
        return res == 1;
    }

    void Notify(std::string& topic)
    {
        for(const auto& ele : observers_[topic]) {
            ele->OnNotify(*this);
        }
    }

    void Push(std::string& topic, std::shared_ptr<TopicDataBlock> blk)  // store one event
    {
        topicMap_[topic] = blk;
    }

    std::shared_ptr<TopicDataBlock>& getData(std::string& topicName)
    {
        return topicMap_[topicName];
    }

private:
    std::unordered_map<std::string, std::unordered_set<Observer*>> observers_;
    std::unordered_map<std::string, std::shared_ptr<TopicDataBlock>> topicMap_;
};

#endif