/*
 * @@author: 008555
 * @@for : application vehicle control
 * @@version: 01
 * @@date: 2023-04 ~ 2023-05
 * @@copyright Copyright (c): 2023
 */

#ifndef SIM_TRIGGEREVENT_H
#define SIM_TRIGGEREVENT_H

#include <queue>
#include <string>

#include <TopicData_Center.h>
#include <TopicData_Block.h>

class SimTriggerEvent {
public:
    void PublishEvent(std::string topic, std::vector<uint8_t>& dataVec)
    {
        auto blk = std::make_shared<TopicDataBlock>(topic);
        blk->SetTopicData(dataVec);
        TopticDataCenter::GetInstance().Push(topic, blk);
    }
};
#endif