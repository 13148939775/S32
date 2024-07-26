/*
 * @author 08555
 * @for signal ipcf someip receive
 * @version 0.1
 * @date 2023-09
 * @copyright Copyright (c) 2023
 */
#include "signal_ipcfrecv.h"
#include <thread>
#include <chrono>

namespace HHT {
namespace DataManager {
void SignalIpcfRecv::Init()
{
    ipcfClient_.Init(ipcfPort_, ip);
    SendTickCount();
    ipcfSl_.start("ipcf");

    //建立sqlite数据表
    //SqliteOperatorModel::init(":memory:");
    std::string createTable = "CREATE TABLE IPCF_DATA(" \
        "TIMESTAMP INT PRIMARY KEY     NOT NULL," \
        "DATA      TEXT    NOT NULL);";
    // 直接运行脚本
    SqliteOperator::GetClient()->Exec(createTable); 
}

void SignalIpcfRecv::SendTickCount()
{
    std::thread th_( [this]() {
        for (int i=0; i < 10; ++i) {
            ipcfClient_.SendPackage(ipcfBuffer_, ipcfDataLength_, ip, ipcfPort_);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    });
    th_.detach();
}
void SignalIpcfRecv::ReceiveIPCFData()
{
    std::thread th_( [this]() {

        size_t len = ipcfDataLength_;
        int64_t timestamp;
        SqliteOperatorCols c1;
        std::string arr[]{"TIMESTAMP", "DATA"};
        int dataNum_;

        while (runSign_) {
            ipcfClient_.ReceivePackage(ipcfBuffer_, len, ipcfPort_);
            //生成时间戳
            timestamp = GetDataTime();
            //向sqlite插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
            c1.AddInstance(arr, "ac", timestamp, std::string(ipcfBuffer_));
            userModel_.Table("IPCF_DATA").Insert(c1).Exec();
            //条数检查
            dataNum_ = userModel_.Table("IPCF_DATA").Select("TIMESTAMP").FindAlls().size();
            if (dataNum_>dataNumLimit_) {
                userModel_.Sql("DELETE FROM IPCF_DATA WHERE TIMESTAMP IN \
                                (SELECT TIMESTAMP FROM IPCF_DATA LIMIT 1)").Exec();
            }
            //另存一份全量数据落盘
            memcpy(&ipcfBuffer_[ipcfDataLength_-timestampLength_],&timestamp,sizeof(timestamp));
            ipcfSl_.storeData("ipcf", "/home/root/log/cccData/CCCipcf_",ipcfBuffer_, ipcfDataLength_);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });
    th_.detach();
}
}
}
