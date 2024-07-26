/*
 * @author 08555
 * @for signal ipcf someip receive
 * @version 0.1
 * @date 2023-09
 * @copyright Copyright (c) 2023
 */

#ifndef SIGNAL_IPCF_RECV_H
#define SIGNAL_IPCF_RECV_H

#include "socket/socket_udp_client.h"
#include "data_storage/recorder_mode/signal_store_ctrl.h"
#include "sqlite_operator.h"

namespace HHT {
namespace DataManager {
class SignalIpcfRecv {
public:
    SignalIpcfRecv()
      : runSign_(true)
    { }

    static SignalIpcfRecv& GetInstance()
    {
        static SignalIpcfRecv sifr;
        return sifr;
    }

    void Init();

    void SendTickCount();

    void ReceiveIPCFData();

    std::string GetIPCFData() const
    {
        return std::string(ipcfBuffer_);
    }

    int64_t& GetDataTime(){
        auto now = std::chrono::system_clock::now();
        ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
        return ms;
    }
private:
    SocketUDPClient ipcfClient_;

    static const int ipcfDataLength_ = 1032;

    char ipcfBuffer_[ipcfDataLength_] = {0};

    const unsigned short ipcfPort_ = 9988;

    const char* ip = "127.0.0.1";

    SignalStoreCtrl ipcfSl_;

    bool runSign_;

    SqliteOperatorModel userModel_;

    const int timestampLength_ = 8;

    int64_t ms = 0;

    const int dataNumLimit_ = 2000;
};
} // namespace DataManager
} // namespace HHT
#endif
