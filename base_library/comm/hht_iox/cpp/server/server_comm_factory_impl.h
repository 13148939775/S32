/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SERVER_COMM_FACTORY_IMPL_H
#define SERVER_COMM_FACTORY_IMPL_H

#include <memory>

#include <node_log.h>
#include "iceOryx_server.h"

namespace HHT {

class ServerCommFactoryImpl {
public:
    explicit ServerCommFactoryImpl(const std::string& owner) noexcept
      : owner_(owner)
    { }

    ~ServerCommFactoryImpl() = default;

    std::unique_ptr<BaseServerCommInterface>  CreateServerComm(const std::string& type)
    {
        HHT_LOG(INFO) << "ServerCommFactoryImpl::CreatePub" << type ;
        if (type.compare("iceOryx") == 0) {
            return std::make_unique<IceOryxServer>(owner_);
        }
        return std::make_unique<IceOryxServer>(owner_);
    };
private:
    std::string owner_;
};
}
#endif /* SERVER_COMM_FACTORY_IMPL_H */
