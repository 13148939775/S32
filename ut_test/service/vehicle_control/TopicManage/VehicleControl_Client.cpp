
/*
 * @author 008555
 * @for application log interface
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <gtest/gtest.h>
#include <fstream>
#include <string>

#include "TopicData_Center.h"
#include "Sim_TriggerEvent.h"
#include "TopicManage.h"

TEST(VehicleControl, ReadTopicConfig)
{
    std::string filename = "/home/aliao/s32-Apps/service/vehicle_control/topicExample.json";
    bool result = TopicManage::GetInstance().ReadTopicConfig(filename);

    EXPECT_EQ(result, true);
}

TEST(VehicleControl, HDBI_Win_Set_Topic)
{
    std::string filename = "/home/aliao/s32-Apps/service/vehicle_control/topicExample.json";
    TopicManage::GetInstance().ReadTopicConfig(filename);

    bool result = TopicManage::GetInstance().GetTopicTriggerState("HDBI_Win_Set");
    EXPECT_EQ(result, false);
}

TEST(VehicleControl, HDBI_PowerModeReq_Topic)
{
    std::string filename = "/home/aliao/s32-Apps/service/vehicle_control/topicExample.json";
    TopicManage::GetInstance().ReadTopicConfig(filename);

    bool result = TopicManage::GetInstance().GetTopicTriggerState("HDBI_PowerModeReq");
    EXPECT_EQ(result, true);
}

TEST(VehicleControl, RunTopic)
{
    std::string filename = "/home/aliao/s32-Apps/service/vehicle_control/topicExample.json";
    bool result = TopicManage::GetInstance().ReadTopicConfig(filename);
    //TopicEventTrigger
    std::shared_ptr<SimTriggerEvent> simTrigger = std::make_shared<SimTriggerEvent>();
    std::vector<uint8_t> topicVec_ = {1,0};
    simTrigger->PublishEvent("HDBI_Win_Set",topicVec_);
    TopticDataCenter::GetInstance().Notify("HDBI_Win_Set");

    topicVec_ = {1,1,1,1,1,1,1,1,1,1,1,1,1};
    simTrigger->PublishEvent("HDBM_GeneralVehSt",topicVec_);
    TopticDataCenter::GetInstance().Notify("HDBM_GeneralVehSt");


    topicVec_ = {0x80,0};
    simTrigger->PublishEvent("HDBM_PowerModeRsp",topicVec_);
    TopticDataCenter::GetInstance().Notify("HDBM_PowerModeRsp");
}