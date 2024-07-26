/*
 * @author 008196
 * @for ClientComm factory impl
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CLIENT_COMM_FACTORY_IMPL_H
#define CLIENT_COMM_FACTORY_IMPL_H

#include <memory>
#include <node_log.h>

#include "iceOryx_client.h"

namespace HHT {

class ClientCommFactoryImpl {
public:
    explicit ClientCommFactoryImpl(const std::string& owner) noexcept
      : owner_(owner)
    { }

    ~ClientCommFactoryImpl() = default;

    std::unique_ptr<BaseClientCommInterface>  CreateClientComm(const std::string& type) const
    {
        HHT_LOG(INFO) << " creat factory :" << type;
        if (type.compare("iceOryx") == 0) {
            return std::make_unique<IceOryxClient>(owner_);
        }
        return std::make_unique<IceOryxClient>(owner_);
    };
private:
    std::string owner_;
};
}
#endif /* CLIENT_COMM_FACTORY_IMPL_H */

