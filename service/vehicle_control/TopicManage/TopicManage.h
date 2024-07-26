
/*
 * @author 008555
 * @for application log interface
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TOPIC_MANAGER_H
#define TOPIC_MANAGER_H

#include "TopicService.h"
class TopicManage {
public:
    static TopicManage& GetInstance()
    {
        static TopicManage tm;
        return tm;
    }

    bool ReadTopicConfig(std::string& filename);

    void BuildTopic(const nlohmann::json& data);

    void AddTopic(std::shared_ptr<TopicService>& tc);

    bool CreateTopicThread();
private:
    std::vector<std::shared_ptr<TopicService>>  topicVec_;
};
#endif