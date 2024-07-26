/*
 * @@author: 008555
 * @@for : application vehicle control
 * @@version: 01
 * @@date: 2023-04 ~ 2023-05
 * @@copyright Copyright (c): 2023
 */

#include "TopicManage.h"
#include "node_log.h"
#include <fstream>
#include <iostream>
void TopicManage::BuildTopic(const nlohmann::json& data)
{
    int topicsCnt = data["topics"].size();
    std::shared_ptr<TopicService> tcPtr;
    std::string topicName;
    std::string topicQname;
    int id;
    int type;
    int priority;
    bool trigger = true;
    int sendStrategy = 0;
    for (int i = 0; i < topicsCnt; ++i) {
        topicName = data["topics"][i]["name"];
        id = data["topics"][i]["id"];
        type = data["topics"][i]["type"];
        topicQname = data["topics"][i]["qname"];
        trigger = data["topics"][i]["trigger"];
        priority = data["topics"][i]["priority"];
        sendStrategy = data["topics"][i]["sendStrategy"];
        tcPtr = std::make_shared<TopicService>(topicName, topicQname, sendStrategy, trigger);
        TopicManage::GetInstance().AddTopic(tcPtr);
        tcPtr->ConstructTopicInfo(data, i);
        tcPtr->RegistryStatusCondition(topicName);
    }
}

bool TopicManage::ReadTopicConfig(std::string& filename)
{
    std::ifstream inf(filename);
    HHT_LOG(INFO)<<"Readfile config";
    //解析
    nlohmann::json data = nlohmann::json::parse(inf);
    try {
        //序列化
        std::string s = data.dump();
        HHT_LOG(INFO) << "json is:" << s;
    } catch (const std::exception &e) {
        inf.close();
        return false;
    }
    BuildTopic(data);
    inf.close();

    return true;
}


void TopicManage::AddTopic(std::shared_ptr<TopicService>& tc)
{
    topicVec_.push_back(tc);
}

bool TopicManage::CreateTopicThread()
{
    HHT_LOG(INFO)<<"TopicManage CreateTopicThread";
    TopicService::CreateDDSThread();
    return true;
}
