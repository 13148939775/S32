/*
 * @author 08555
 * @for someip receive
 * @version 0.1
 * @date 2023-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SIGNAL_SUBSCRIBER_H
#define SIGNAL_SUBSCRIBER_H
#include <vector>
#include <thread>
#include "data_storage/recorder_mode/signal_store_ctrl.h"
#include "sqlite_operator.h"

namespace HHT {
namespace DataManager {
class SignalSubscriber {
public:
    SignalSubscriber()
      : running_(true)
    {}

    static SignalSubscriber& GetInstance()
    {
        static SignalSubscriber sub;
        return sub;
    }
    
    void StartThread();

    void Init();

    void ReveiveZCULSignalData();

    void ReveiveZCURSignalData();

    void ReceiveZCUVersionData();
    
    int64_t& GetDataTime(){
        auto now = std::chrono::system_clock::now();
        ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
        return ms;
    }
private:
    std::thread zcuLT20_;
    std::thread zcuLT50_;
    std::thread zcuLT100_;
    std::thread zcuLT500_;

    std::thread zcuRT20_;
    std::thread zcuRT50_;
    std::thread zcuRT100_;
    std::thread zcuRT500_;

    std::thread zcuVer_;

    SignalStoreCtrl zcul20_sl_;
    SignalStoreCtrl zcul50_sl_;
    SignalStoreCtrl zcul100_sl_;
    SignalStoreCtrl zcul500_sl_;

    SignalStoreCtrl zcur20_sl_;
    SignalStoreCtrl zcur50_sl_;
    SignalStoreCtrl zcur100_sl_;
    SignalStoreCtrl zcur500_sl_;

    bool running_;

    std::string verInfo_;

    static const int bufferMax_ = 1032;

    char verDataBuffer_[bufferMax_] = {0};

    SqliteOperatorModel userModel_;

    const int timestampLength_ = 8;

    int64_t ms = 0;

    const int dataNumLimit_ = 2000;
};
}
}
#endif
