/*
 * @author 008196
 * @for extern ClientComm kit 
 * @version 0.1
 * @date 2023-05 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CLIENT_COMM_KIT_H
#define CLIENT_COMM_KIT_H

#include <memory>
#include <functional>
#include <string>

#include "cpp/enum_event.h"

#include "client_comm_factory.h"
#include "base_client_comm_interface.h"

namespace HHT {

class ClientComm {
public:
    ClientComm(const std::string& owner, const ProtocolType type);
    ~ClientComm();
    bool Init();
    int Wait(const Event evtID, const int timeout = 20);
    int WaitCB(const Event evtID, std::function<void*()>& cb) { };  // new add
    int GetValue(const Event evtID) const;
private:
    std::string owner_;
    std::unique_ptr<ClientCommFactory> ClientCommFactoryPtr_{nullptr};
    std::unique_ptr<BaseClientCommInterface> ClientCommPtr_{nullptr};
};

}

#endif /* CLIENT_COMM_KIT_H */
