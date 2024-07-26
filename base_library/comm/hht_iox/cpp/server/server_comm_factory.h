/*
 * @author 008196
 * @for pub factory
 * @version 0.1
 * @date 2023-4 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PUB_FACTORY_H
#define PUB_FACTORY_H

#include <string>
#include <memory>

#include "base_server_comm_interface.h"
#include "server_comm_factory_impl.h"

namespace HHT {

class ServerCommFactory {
public:
    explicit ServerCommFactory(const std::string& owner);
    virtual ~ServerCommFactory();
    
    std::unique_ptr<BaseServerCommInterface> CreateServerComm(const std::string& type);

private:
  std::string owner_;
  std::unique_ptr<ServerCommFactoryImpl> pImpl_;

};


}
#endif