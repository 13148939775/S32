
/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "server_comm_kit.h"

#include <node_log.h>
#include "comm_config.h"

namespace HHT {
ServerComm::ServerComm(const std::string& owner, const ProtocolType type)
  : owner_(owner),
    ServerCommFactoryPtr_(new ServerCommFactory(owner_)) 
{ 
    ServerCommPtr_ = ServerCommFactoryPtr_->CreateServerComm(
        CommConfig::GetInstance().GetProtocolMap()[type]);
    if (ServerCommPtr_ == nullptr) {
        HHT_LOG(ERROR) << "ServerCommFactory::CreateServerComm invalid"; //  ;
        return;
    }
    HHT_LOG(INFO) << "ServerCommFactory::CreateServerComm Succ"; // << type ;
}

ServerComm::~ServerComm() = default;

bool ServerComm::Init()
{ }

void ServerComm::Pub(const Event evtID)
{
    ServerCommPtr_->Pub(evtID);
}

void ServerComm::OfferService()
{
    ServerCommPtr_->OfferService();
}
}