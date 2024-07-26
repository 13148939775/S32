/*
 * @author 008196
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


TEST(log1, logFileExist)
{
     std::string file = "/home/root/sysbin/log/logTest0530.INFO";
    HHT::NodeLog node("logTest0530");
    node.SetLevel(LOG_LEVEL_INFO,LOG_LEVEL_INFO,"./logs/");
    node.InitLog(LOG_LEVEL_INFO,LOG_LEVEL_INFO);
    HHT_LOG(INFO)<<"hello"<<"111";
    node.SetLevel(LOG_LEVEL_WARNING,true); 
    HHT_LOG(WARNING)<<"hello"<<"111";
    HHT_LOG(ERROR)<<"hello"<<"111";
    HHT_LOG(INFO)<<"hello"<<"111";
    HHT_LOG(INFO)<<"hello"<<"222";
    HHT_LOG(WARNING)<<"hello"<<"222";
    node.SetLevel(LOG_LEVEL_WARNING);
    HHT_LOG(ERROR)<<"hello"<<"222";
    HHT_LOG(INFO)<<"hello"<<"222";

    std::fstream rfile;
    rfile.open(file.c_str());
    bool exist = rfile.good();
    EXPECT_EQ(exist, true);
}

TEST(log2, logNodeUsage)
{
  HHT::NodeLog node("logTest0530111");
   node.SetLevel(LOG_LEVEL_INFO,LOG_LEVEL_INFO,"./logs2/");
    HHT_LOG(INFO)<<"hello"<<"111";
    node.SetLevel(LOG_LEVEL_WARNING,true); 
    HHT_LOG(WARNING)<<"hello"<<"111";
    HHT_LOG(ERROR)<<"hello"<<"111";
    HHT_LOG(INFO)<<"hello"<<"111";
    HHT_LOG(INFO)<<"hello"<<"222";
    HHT_LOG(WARNING)<<"hello"<<"222";
    node.SetLevel(LOG_LEVEL_WARNING);
    HHT_LOG(ERROR)<<"hello"<<"222";
    HHT_LOG(INFO)<<"hello"<<"222";
}

TEST(log3, logFileExist)
{
     std::string file = "/home/root/sysbin/log/logTest0625.INFO";
    HHT::NodeLog node("logTest0625");
   node.InitLog(LOG_LEVEL_INFO,LOG_LEVEL_INFO);
    HHT_LOG(INFO)<<"hello"<<"111";
    node.SetLevel(LOG_LEVEL_WARNING,true); 
    HHT_LOG(WARNING)<<"hello"<<"111";
    HHT_LOG(ERROR)<<"hello"<<"111";
    HHT_LOG(INFO)<<"hello"<<"111";
    HHT_LOG(INFO)<<"hello"<<"222";
    HHT_LOG(WARNING)<<"hello"<<"222";
    node.SetLevel(LOG_LEVEL_WARNING);
    HHT_LOG(ERROR)<<"hello"<<"222";
    HHT_LOG(INFO)<<"hello"<<"222";

    std::fstream rfile;
    rfile.open(file.c_str());
    bool exist = rfile.good();
    EXPECT_EQ(exist, true);
}

TEST(log4, logNodeUsage)
{
    HHT::NodeLog node("Test06251624");
   node.InitLog(LOG_LEVEL_INFO,LOG_LEVEL_INFO);
    HHT_LOG(INFO)<<"hello"<<"111";
    node.SetLevel(LOG_LEVEL_WARNING,true); 
    HHT_LOG(WARNING)<<"hello"<<"111";
    HHT_LOG(ERROR)<<"hello"<<"111";
    HHT_LOG(INFO)<<"hello"<<"111";
    HHT_LOG(INFO)<<"hello"<<"222";
    HHT_LOG(WARNING)<<"hello"<<"222";
    node.SetLevel(LOG_LEVEL_WARNING);
    HHT_LOG(ERROR)<<"hello"<<"222";
    HHT_LOG(INFO)<<"hello"<<"222";
}


