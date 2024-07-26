/*
 * @author 008196
 * @for extern ServerComm kit 
 * @version 0.1
 * @date 2023-05 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ServerComm_KIT_H
#define ServerComm_KIT_H

#include <memory>
#include <string>

#include "server_comm_factory.h"
#include "base_server_comm_interface.h"

namespace HHT {
class ServerComm {
public:
    /* runtime name & which productor*/
    ServerComm(const std::string& owner, const ProtocolType type);
    ~ServerComm();
    bool Init();
    void Pub(const Event evtID);
    void OfferService();
private:
    std::string owner_;
    std::unique_ptr<ServerCommFactory> ServerCommFactoryPtr_{nullptr};
    std::unique_ptr<BaseServerCommInterface> ServerCommPtr_{nullptr};
};
}
#endif /* ServerComm_KIT_H */
