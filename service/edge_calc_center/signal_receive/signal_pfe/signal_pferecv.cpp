/*
 * @author 08555
 * @for signal ipcf someip pfe receive
 * @version 0.1
 * @date 2023-10
 * @copyright Copyright (c) 2023
 */

#include "signal_pferecv.h"
#include <thread>
#include <chrono>

namespace HHT {
namespace DataManager {
void SignalPfeRecv::Init()
{
    pfeServer_.Init();
    pfeServer_.Bind("aux0");
    pfeSl_.start("pfe");

    //建立sqlite数据表
    //SqliteOperatorModel::init(":memory:");
    std::string createTable = "CREATE TABLE PFE_DATA(" \
        "TIMESTAMP INT PRIMARY KEY     NOT NULL," \
        "DATA      TEXT    NOT NULL);";
    // 直接运行脚本
    SqliteOperator::GetClient()->Exec(createTable); 
}

void SignalPfeRecv::ReceivePfeData()
{
    std::thread th_( [this]() {

        constexpr size_t len = pfeDataLength_;
        const std::string filewayPfe_ = "/home/root/log/cccData/CCCpfe_";
        int64_t timestamp;
        SqliteOperatorCols c1;
        std::string arr[]{"TIMESTAMP", "DATA"};
        int dataNum_;

        while (runSign_) {
            pfeServer_.ReceivePackage(pfeBuffer_, len);
            // filter 1722 data
            if ((pfeBuffer_[featureByte_[0]] == featureValue_[0]) &&
                (pfeBuffer_[featureByte_[1]] == featureValue_[1])) {
                //生成时间戳
                timestamp = GetDataTime();
                //向sqlite插入数据, 第一个参数为字段名列表，第二个参数字符串代表每个字段的数据类型: a--int, b--double, c--string, 第三个参数是字段值列表
                c1.AddInstance(arr, "ac", timestamp, std::string(pfeBuffer_));
                userModel_.Table("PFE_DATA").Insert(c1).Exec();
                //条数检查
                dataNum_ = userModel_.Table("PFE_DATA").Select("TIMESTAMP").FindAlls().size();
                if (dataNum_>dataNumLimit_) {
                    userModel_.Sql("DELETE FROM PFE_DATA WHERE TIMESTAMP IN \
                                    (SELECT TIMESTAMP FROM PFE_DATA LIMIT 1)").Exec();
                }
                //另存一份全量数据落盘
                memcpy(&pfeBuffer_[pfeDataLength_-timestampLength_],&timestamp,sizeof(timestamp));
                pfeSl_.storeData("pfe", filewayPfe_, pfeBuffer_, len);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    });
    th_.detach();
}
}
}
