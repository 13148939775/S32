/*
 * @author 008196
 * @for extern ClientComm kit 
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "client_comm_kit.h"

#include "comm_config.h"

namespace HHT {
ClientComm::ClientComm(const std::string& owner, const ProtocolType type)
  : owner_(owner),
    ClientCommFactoryPtr_(new ClientCommFactory(owner_)) 
{ 
    ClientCommPtr_ = ClientCommFactoryPtr_->CreateClientComm(
        CommConfig::GetInstance().GetProtocolMap()[type]);
}

ClientComm::~ClientComm() = default;

bool ClientComm::Init()
{ }

int ClientComm::Wait(const Event evtID, const int timeout)
{
    return ClientCommPtr_->Wait(evtID, timeout);
}

int ClientComm::GetValue(const Event evtID) const
{
    return ClientCommPtr_->GetValue(evtID);
}
}