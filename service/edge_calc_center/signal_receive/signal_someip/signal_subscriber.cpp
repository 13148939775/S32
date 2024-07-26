/*
 * @author 08555
 * @for signal ipcf someip receive
 * @version 0.1
 * @date 2023-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "signal_subscriber.h"
#include <chrono>
#include <iostream>
#include "iox_interface.h"
#include "topic_config.hpp"
#include <node_log.h>

namespace HHT {
namespace DataManager {
constexpr char CCC_NAME[] = "CCC_SOMEIP5_Subscriber";

void SignalSubscriber::StartThread()
{
    HHT_LOG(INFO)<<"SignalSubscriber::StartThread"<<std::endl;
    Init();
    ReceiveZCUVersionData();
    ReveiveZCULSignalData();
    ReveiveZCURSignalData();
}

void SignalSubscriber::Init()
{
    zcul20_sl_.start("ZCUL20");
    zcul50_sl_.start("ZCUL50");
    zcul100_sl_.start("ZCUL100");
    zcul500_sl_.start("ZCUL500");
    zcur20_sl_.start("ZCUR20");
    zcur50_sl_.start("ZCUR50");
    zcur100_sl_.start("ZCUR100");
    zcur500_sl_.start("ZCUR500");

    //建立sqlite数据表
    //SqliteOperatorModel::init(":memory:");
    std::string createTableZCUL20 = "CREATE TABLE SOMEIP_ZCUL20_DATA(" \
        "TIMESTAMP INT PRIMARY KEY     NOT NULL," \
        "DATA      TEXT    NOT NULL);";
    std::string createTableZCUL50 = "CREATE TABLE SOMEIP_ZCUL50_DATA(" \
        "TIMESTAMP INT PRIMARY KEY     NOT NULL," \
        "DATA      TEXT    NOT NULL);";
    std::string createTableZCUL100 = "CREATE TABLE SOMEIP_ZCUL100_DATA(" \
        "TIMESTAMP INT PRIMARY KEY     NOT NULL," \
        "DATA      TEXT    NOT NULL);";
    std::string createTableZCUL500 = "CREATE TABLE SOMEIP_ZCUL500_DATA(" \
        "TIMESTAMP INT PRIMARY KEY     NOT NULL," \
        "DATA      TEXT    NOT NULL);";
    std::string createTableZCUR20 = "CREATE TABLE SOMEIP_ZCUR20_DATA(" \
        "TIMESTAMP INT PRIMARY KEY     NOT NULL," \
        "DATA      TEXT    NOT NULL);";
    std::string createTableZCUR50 = "CREATE TABLE SOMEIP_ZCUR50_DATA(" \
        "TIMESTAMP INT PRIMARY KEY     NOT NULL," \
        "DATA      TEXT    NOT NULL);";
    std::string createTableZCUR100 = "CREATE TABLE SOMEIP_ZCUR100_DATA(" \
        "TIMESTAMP INT PRIMARY KEY     NOT NULL," \
        "DATA      TEXT    NOT NULL);";
    std::string createTableZCUR500 = "CREATE TABLE SOMEIP_ZCUR500_DATA(" \
        "TIMESTAMP INT PRIMARY KEY     NOT NULL," \
        "DATA      TEXT    NOT NULL);";
    // 直接运行脚本
    SqliteOperator::GetClient()->Exec(createTableZCUL20);
    SqliteOperator::GetClient()->Exec(createTableZCUL50);
    SqliteOperator::GetClient()->Exec(createTableZCUL100);
    SqliteOperator::GetClient()->Exec(createTableZCUL500);
    SqliteOperator::GetClient()->Exec(createTableZCUR20);
    SqliteOperator::GetClient()->Exec(createTableZCUR50);
    SqliteOperator::GetClient()->Exec(createTableZCUR100);
    SqliteOperator::GetClient()->Exec(createTableZCUR500);

}

void SignalSubscriber::ReveiveZCULSignalData()
{
    zcuLT20_ = std::thread( [this]() {
        HHTSubscriber<TopicZcuData> sub_zcul_20(CCC_NAME, "ZCUL_20MS");
        TopicZcuData recv_data;     
        int64_t timestampZCUL20;
        SqliteOperatorCols c1ZCUL20;
        std::string arrZCUL20[]{"TIMESTAMP", "DATA"};
        int dataNumZCUL20;
        while (running_) {
             sub_zcul_20.Subscribe(recv_data,true);
             //生成时间戳
             timestampZCUL20 = GetDataTime();
             //向sqlite插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
             c1ZCUL20.AddInstance(arrZCUL20, "ac", timestampZCUL20, std::string(recv_data.buffer));
             userModel_.Table("SOMEIP_ZCUL20_DATA").Insert(c1ZCUL20).Exec();
             //条数检查
             dataNumZCUL20 = userModel_.Table("SOMEIP_ZCUL20_DATA").Select("TIMESTAMP").FindAlls().size();
             if (dataNumZCUL20>dataNumLimit_) {
                 userModel_.Sql("DELETE FROM SOMEIP_ZCUL20_DATA WHERE TIMESTAMP IN \
                                (SELECT TIMESTAMP FROM SOMEIP_ZCUL20_DATA LIMIT 1)").Exec();
             }
             //另存一份全量数据落盘
             memcpy(&recv_data.buffer[bufferMax_-timestampLength_],&timestampZCUL20,sizeof(timestampZCUL20));
             zcul20_sl_.storeData("CCCSomeipZCUL20", "./CCCSomeipZCUL20_",recv_data.buffer, bufferMax_);     
        }
    });
    zcuLT20_.detach();

    zcuLT50_ = std::thread( [this]() {
       HHTSubscriber<TopicZcuData> sub_zcul_50(CCC_NAME, "ZCUL_50MS");
       TopicZcuData recv_data;     
       int64_t timestampZCUL50;
       SqliteOperatorCols c1ZCUL50;
       std::string arrZCUL50[]{"TIMESTAMP", "DATA"};       
       int dataNumZCUL50;
       while (running_) {
          sub_zcul_50.Subscribe(recv_data,true);
          //生成时间戳
          timestampZCUL50 = GetDataTime();
          //向sqlite插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
          c1ZCUL50.AddInstance(arrZCUL50, "ac", timestampZCUL50, std::string(recv_data.buffer));
          userModel_.Table("SOMEIP_ZCUL50_DATA").Insert(c1ZCUL50).Exec();
          //条数检查
          dataNumZCUL50 = userModel_.Table("SOMEIP_ZCUL50_DATA").Select("TIMESTAMP").FindAlls().size();
          if (dataNumZCUL50>dataNumLimit_) {
              userModel_.Sql("DELETE FROM SOMEIP_ZCUL50_DATA WHERE TIMESTAMP IN \
                              (SELECT TIMESTAMP FROM SOMEIP_ZCUL50_DATA LIMIT 1)").Exec();
          }
          //另存一份全量数据落盘
          memcpy(&recv_data.buffer[bufferMax_-timestampLength_],&timestampZCUL50,sizeof(timestampZCUL50));
          zcul50_sl_.storeData("CCCSomeipZCUL50", "./CCCSomeipZCUL50_",recv_data.buffer, bufferMax_);    
       }
    });
    zcuLT50_.detach();

    zcuLT100_ = std::thread( [this]() {
       HHTSubscriber<TopicZcuData> sub_zcul_100(CCC_NAME, "ZCUL_100MS");
       TopicZcuData recv_data;          
       int64_t timestampZCUL100;
       SqliteOperatorCols c1ZCUL100;
       std::string arrZCUL100[]{"TIMESTAMP", "DATA"};          
       int dataNumZCUL100;
       while (running_) {
          sub_zcul_100.Subscribe(recv_data,true);
          //生成时间戳
          timestampZCUL100 = GetDataTime();
          //向sqlite插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
          c1ZCUL100.AddInstance(arrZCUL100, "ac", timestampZCUL100, std::string(recv_data.buffer));
          userModel_.Table("SOMEIP_ZCUL100_DATA").Insert(c1ZCUL100).Exec();
          //条数检查
          dataNumZCUL100 = userModel_.Table("SOMEIP_ZCUL100_DATA").Select("TIMESTAMP").FindAlls().size();
          if (dataNumZCUL100>dataNumLimit_) {
              userModel_.Sql("DELETE FROM SOMEIP_ZCUL100_DATA WHERE TIMESTAMP IN \
                              (SELECT TIMESTAMP FROM SOMEIP_ZCUL100_DATA LIMIT 1)").Exec();
          }
          //另存一份全量数据落盘
          memcpy(&recv_data.buffer[bufferMax_-timestampLength_],&timestampZCUL100,sizeof(timestampZCUL100));          
          zcul100_sl_.storeData("CCCSomeipZCUL100", "./CCCSomeipZCUL100_",recv_data.buffer, bufferMax_);     
       }
    });
    zcuLT100_.detach();

    zcuLT500_ = std::thread( [this]() {
       HHTSubscriber<TopicZcuData> sub_zcul_500(CCC_NAME, "ZCUL_500MS");
       TopicZcuData recv_data;         
       int64_t timestampZCUL500;
       SqliteOperatorCols c1ZCUL500;
       std::string arrZCUL500[]{"TIMESTAMP", "DATA"};          
       int dataNumZCUL500;
       while (running_) {
          sub_zcul_500.Subscribe(recv_data,true);
          //生成时间戳
          timestampZCUL500 = GetDataTime();
          //向sqlite插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
          c1ZCUL500.AddInstance(arrZCUL500, "ac", timestampZCUL500, std::string(recv_data.buffer));
          userModel_.Table("SOMEIP_ZCUL500_DATA").Insert(c1ZCUL500).Exec();
          //条数检查
          dataNumZCUL500 = userModel_.Table("SOMEIP_ZCUL500_DATA").Select("TIMESTAMP").FindAlls().size();
          if (dataNumZCUL500>dataNumLimit_) {
              userModel_.Sql("DELETE FROM SOMEIP_ZCUL500_DATA WHERE TIMESTAMP IN \
                              (SELECT TIMESTAMP FROM SOMEIP_ZCUL500_DATA LIMIT 1)").Exec();
          }
          //另存一份全量数据落盘
          memcpy(&recv_data.buffer[bufferMax_-timestampLength_],&timestampZCUL500,sizeof(timestampZCUL500));            
          zcul500_sl_.storeData("CCCSomeipZCUL500", "./CCCSomeipZCUL500_",recv_data.buffer, bufferMax_);     
       }
    });
    zcuLT500_.detach();
}


void SignalSubscriber::ReveiveZCURSignalData()
{
    zcuRT20_ = std::thread( [this]() {
        HHTSubscriber<TopicZcuData> sub_zcur_20(CCC_NAME, "ZCUR_20MS");
        TopicZcuData recv_data;             
        int64_t timestampZCUR20;
        SqliteOperatorCols c1ZCUR20;
        std::string arrZCUR20[]{"TIMESTAMP", "DATA"};        
        int dataNumZCUR20;
        while (running_) {
           sub_zcur_20.Subscribe(recv_data, true);
           //生成时间戳
           timestampZCUR20 = GetDataTime();
           //向sqlite插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
           c1ZCUR20.AddInstance(arrZCUR20, "ac", timestampZCUR20, std::string(recv_data.buffer));
           userModel_.Table("SOMEIP_ZCUR20_DATA").Insert(c1ZCUR20).Exec();
           //条数检查
           dataNumZCUR20 = userModel_.Table("SOMEIP_ZCUR20_DATA").Select("TIMESTAMP").FindAlls().size();
           if (dataNumZCUR20>dataNumLimit_) {
               userModel_.Sql("DELETE FROM SOMEIP_ZCUR20_DATA WHERE TIMESTAMP IN \
                              (SELECT TIMESTAMP FROM SOMEIP_ZCUR20_DATA LIMIT 1)").Exec();
           }
           //另存一份全量数据落盘
           memcpy(&recv_data.buffer[bufferMax_-timestampLength_],&timestampZCUR20,sizeof(timestampZCUR20));           
           zcur20_sl_.storeData("CCCSomeipZCUR20", "./CCCSomeipZCUR20_",recv_data.buffer, bufferMax_);     
        }
    });
    zcuRT20_.detach();

    zcuRT50_ = std::thread( [this]() {
        HHTSubscriber<TopicZcuData> sub_zcur_50(CCC_NAME, "ZCUR_50MS");
        TopicZcuData recv_data;         
        int64_t timestampZCUR50;
        SqliteOperatorCols c1ZCUR50;
        std::string arrZCUR50[]{"TIMESTAMP", "DATA"};        
        int dataNumZCUR50;
        while (running_) {
            sub_zcur_50.Subscribe(recv_data, true);
            //生成时间戳
            timestampZCUR50 = GetDataTime();
            //向sqlite插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
            c1ZCUR50.AddInstance(arrZCUR50, "ac", timestampZCUR50, std::string(recv_data.buffer));
            userModel_.Table("SOMEIP_ZCUR50_DATA").Insert(c1ZCUR50).Exec();
            //条数检查
            dataNumZCUR50 = userModel_.Table("SOMEIP_ZCUR50_DATA").Select("TIMESTAMP").FindAlls().size();
            if (dataNumZCUR50>dataNumLimit_) {
                userModel_.Sql("DELETE FROM SOMEIP_ZCUR50_DATA WHERE TIMESTAMP IN \
                                (SELECT TIMESTAMP FROM SOMEIP_ZCUR50_DATA LIMIT 1)").Exec();
            }
            //另存一份全量数据落盘
            memcpy(&recv_data.buffer[bufferMax_-timestampLength_],&timestampZCUR50,sizeof(timestampZCUR50));            
            zcur50_sl_.storeData("CCCSomeipZCUR50", "./CCCSomeipZCUR50_",recv_data.buffer, bufferMax_);     
        }
    });
    zcuRT50_.detach();

    zcuRT100_ = std::thread( [this]() {
         HHTSubscriber<TopicZcuData> sub_zcur_100(CCC_NAME, "ZCUR_100MS");
         TopicZcuData recv_data;            
         int64_t timestampZCUR100;
         SqliteOperatorCols c1ZCUR100;
         std::string arrZCUR100[]{"TIMESTAMP", "DATA"};           
         int dataNumZCUR100;
         while (running_) {
            sub_zcur_100.Subscribe(recv_data, true);
            //生成时间戳
            timestampZCUR100 = GetDataTime();
            //向sqlite插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
            c1ZCUR100.AddInstance(arrZCUR100, "ac", timestampZCUR100, std::string(recv_data.buffer));
            userModel_.Table("SOMEIP_ZCUR100_DATA").Insert(c1ZCUR100).Exec();
            //条数检查
            dataNumZCUR100 = userModel_.Table("SOMEIP_ZCUR100_DATA").Select("TIMESTAMP").FindAlls().size();
            if (dataNumZCUR100>dataNumLimit_) {
                userModel_.Sql("DELETE FROM SOMEIP_ZCUR100_DATA WHERE TIMESTAMP IN \
                                (SELECT TIMESTAMP FROM SOMEIP_ZCUR100_DATA LIMIT 1)").Exec();
            }
            //另存一份全量数据落盘
            memcpy(&recv_data.buffer[bufferMax_-timestampLength_],&timestampZCUR100,sizeof(timestampZCUR100));              
            zcur100_sl_.storeData("CCCSomeipZCUR100", "./CCCSomeipZCUR100_",recv_data.buffer, bufferMax_);    
         }
    });
    zcuRT100_.detach();

    zcuRT500_ = std::thread( [this]() {
       HHTSubscriber<TopicZcuData> sub_zcur_500(CCC_NAME, "ZCUR_500MS");
       TopicZcuData recv_data;                
       int64_t timestampZCUR500;
       SqliteOperatorCols c1ZCUR500;
       std::string arrZCUR500[]{"TIMESTAMP", "DATA"};       
       int dataNumZCUR500;
       while (running_) {
          sub_zcur_500.Subscribe(recv_data, true);
          //生成时间戳
          timestampZCUR500 = GetDataTime();
          //向sqlite插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
          c1ZCUR500.AddInstance(arrZCUR500, "ac", timestampZCUR500, std::string(recv_data.buffer));
          userModel_.Table("SOMEIP_ZCUR500_DATA").Insert(c1ZCUR500).Exec();
          //条数检查
          dataNumZCUR500 = userModel_.Table("SOMEIP_ZCUR500_DATA").Select("TIMESTAMP").FindAlls().size();
          if (dataNumZCUR500>dataNumLimit_) {
              userModel_.Sql("DELETE FROM SOMEIP_ZCUR500_DATA WHERE TIMESTAMP IN \
                              (SELECT TIMESTAMP FROM SOMEIP_ZCUR500_DATA LIMIT 1)").Exec();
          }
          //另存一份全量数据落盘
          memcpy(&recv_data.buffer[bufferMax_-timestampLength_],&timestampZCUR500,sizeof(timestampZCUR500));           
          zcur500_sl_.storeData("CCCSomeipZCUR500", "./CCCSomeipZCUR500_",recv_data.buffer, bufferMax_);    
       }
    });
    zcuRT500_.detach();
}


void SignalSubscriber::ReceiveZCUVersionData()
{
    zcuVer_ = std::thread( [this]() {
        HHTSubscriber<TopicVerData> sub_zcuver(CCC_NAME, "CANMATRIX_VERSION");
        TopicVerData recv_data;
        while (running_) {
           sub_zcuver.Subscribe(recv_data, true);
           HHT_LOG(INFO)<<"sub_zcuver.Subscribe(recv_data, true);"<<std::endl;
           verInfo_ = recv_data.buffer;
        }
   });
    zcuVer_.detach();
}

}
}
