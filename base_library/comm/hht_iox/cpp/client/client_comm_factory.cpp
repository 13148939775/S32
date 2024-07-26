/*
 * @author 008196
 * @for application log file entry
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "client_comm_factory.h"

namespace HHT {

ClientCommFactory::ClientCommFactory(const std::string& owner)
  : owner_(owner), 
    pImpl_(new ClientCommFactoryImpl(owner))
{ }

ClientCommFactory::~ClientCommFactory() = default;
    
std::unique_ptr<BaseClientCommInterface> ClientCommFactory::CreateClientComm(const std::string& type)
{
    return pImpl_->CreateClientComm(type);
}

}