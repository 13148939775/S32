/*
 * @author 008196
 * @for ClientComm factory
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ClientComm_FACTORY_H
#define ClientComm_FACTORY_H

#include <string>
#include <memory>

#include "base_client_comm_interface.h"
#include "client_comm_factory_impl.h"

namespace HHT {

struct ClientCommFactory {
public:
    explicit ClientCommFactory(const std::string& owner);
    virtual ~ClientCommFactory();
    
    virtual std::unique_ptr<BaseClientCommInterface> CreateClientComm(const std::string& type);

private:
  std::string owner_;
  std::unique_ptr<ClientCommFactoryImpl> pImpl_;
};


}
#endif

