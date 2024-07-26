/*
 * @author 08555
 * @for signal ipcf someip pfe receive
 * @version 0.1
 * @date 2023-10
 * @copyright Copyright (c) 2023
 */

#ifndef SIGNAL_PFE_RECV_H
#define SIGNAL_PFE_RECV_H

#include "socket/socket_avtp.h"
#include "data_storage/recorder_mode/signal_store_ctrl.h"
#include "sqlite_operator.h"

namespace HHT {
namespace DataManager {
class SignalPfeRecv {
public:
    SignalPfeRecv()
      : runSign_(true)
    { }

    static SignalPfeRecv& GetInstance()
    {
        static SignalPfeRecv spr;
        return spr;
    }

    void Init();

    void ReceivePfeData();

    std::string GetPfeData() const
    {
        return std::string(pfeBuffer_);
    }

    int64_t& GetDataTime(){
        auto now = std::chrono::system_clock::now();
        ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
        return ms;
    }
private:
    SocketAVTP pfeServer_;

    static const int pfeDataLength_ = 1032;

    char pfeBuffer_[pfeDataLength_] = {0};

    SignalStoreCtrl pfeSl_;

    bool runSign_;

    //feature parameters of 1722
    const int featureByte_[2] = {12,13};

    const int featureValue_[2] = {0x22,0xF0};

    SqliteOperatorModel userModel_;

    const int timestampLength_ = 8;

    int64_t ms = 0;

    const int dataNumLimit_ = 2000;
};
} // namespace DataManager
} // namespace HHT
#endif
