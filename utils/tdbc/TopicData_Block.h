/*
 * @author 008555
 * @for application log interface
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TOPICDATA_BLOCK_H
#define TOPICDATA_BLOCK_H

#include <bits/stdc++.h>
#define DATA_MAX 64


class TopicDataBlock {
public:
    explicit TopicDataBlock(std::string& topicName)
    : topicName_(topicName)
    {
        data_.resize(DATA_MAX);
    }

    const std::vector<uint8_t> GetTopcData() const
    {
        return data_;
    }

    void SetTopicData(const std::vector<uint8_t>& dataVec)
    {
        data_.assign(dataVec.begin(), dataVec.end());
    }
private:
    std::string topicName_;
    std::vector<uint8_t> data_;
};

#endif


