/*
 * @author 008555
 * @for application log interface
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <node_log.h>
#include "custom_scene_manager.h"
#include "scheduler/scheduler.h"
#include "sim_trigger_event.h"
#include "sceneCard.h"
#include  "custom_scene.h"

TEST(CustomScene, Init)
{
    char buffer[256];
    memset(buffer, 0,256);
    strcpy(buffer, "/tmp/exampleTest9.json");
    bool res = CustomSceneManager::GetInstance().Init(buffer);
    EXPECT_EQ(res, true);
}

TEST(CustomScene, InitAdj)
{
    char buffer[256];
    memset(buffer, 0,256);
    strcpy(buffer, "/tmp/exampleTest9.json");
    CustomSceneManager::GetInstance().Init(buffer);
    bool res = CustomSceneManager::GetInstance().Start();
    EXPECT_EQ(res, true);
}


TEST(CustomScene, OPEN_DEFAULTSC)
{
    char buffer[256];
    memset(buffer, 0,256);
    strcpy(buffer, "/tmp/exampleTest9.json");
    CustomSceneManager::GetInstance().Init(buffer);
    CustomSceneManager::GetInstance().Start();
    
    std::shared_ptr<SimTriggerEventTable>  simTrigger = std::make_shared<SimTriggerEventTable>();
    
    //register default event;
    printf("1.打开 缺省场景\t\n");
    simTrigger->PublishEvent(BLK_DEFAULTSC);
    DataBlockCenter::GetInstance().Notify();

    uint32_t  runsize = Scheduler<SceneCardPtr, CustomScene>::GetInstance().GetRunningQueSize();
    EXPECT_EQ(runsize, 1);
}

TEST(CustomScene, OPEN_READINGSC)
{
    char buffer[256];
    memset(buffer, 0,256);
    strcpy(buffer, "/tmp/exampleTest9.json");
    CustomSceneManager::GetInstance().Init(buffer);
    CustomSceneManager::GetInstance().Start();
    
    std::shared_ptr<SimTriggerEventTable>  simTrigger = std::make_shared<SimTriggerEventTable>();
    
    //register default event;
    printf("1.打开 缺省场景\t\n");
    simTrigger->PublishEvent(BLK_DEFAULTSC);
    DataBlockCenter::GetInstance().Notify();

    printf("2.打开 阅读场景 \t\n");
    simTrigger->PublishEvent(BLK_READINGSC);
    DataBlockCenter::GetInstance().Notify();

    uint32_t  runsize = Scheduler<SceneCardPtr, CustomScene>::GetInstance().GetRunningQueSize();
    uint32_t  suspendsize = Scheduler<SceneCardPtr, CustomScene>::GetInstance().GetSuspendQueSize();
    EXPECT_EQ(runsize, 1);
    EXPECT_EQ(suspendsize, 1);
}