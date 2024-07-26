/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "server_comm_factory.h"

namespace HHT {

ServerCommFactory::ServerCommFactory(const std::string& owner)
    : owner_(owner),
      pImpl_(new ServerCommFactoryImpl(owner_))
{ }

ServerCommFactory::~ServerCommFactory() = default;
    
std::unique_ptr<BaseServerCommInterface> ServerCommFactory::CreateServerComm(const std::string& type)
{
    HHT_LOG(INFO) << "ServerCommFactory::CreatePub" << type ;
    return pImpl_->CreateServerComm(type);
}

}