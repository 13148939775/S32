/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ICEORYX_PUB_H
#define ICEORYX_PUB_H

#include <string>
#include <memory>
#include "cpp/comm_config.h"

#include "iceoryx_hoofs/cxx/optional.hpp"
#include "iceoryx_posh/popo/publisher.hpp"
#include "iceoryx_posh/popo/subscriber.hpp"
#include "iceoryx_posh/popo/wait_set.hpp"

namespace HHT {

// template <typnename T>
class IceOryxPub  {
public:
    struct CounterTopic
    {
        uint32_t counter;
    };

    IceOryxPub() noexcept = default;

    ~IceOryxPub() = default;

    bool Init()
    {
        return true;
    }

    int Pub(const Event EvtID)
    {
        uint32_t counter = 8U;

        iox::popo::Publisher<CounterTopic> myPublisher(
            {CommConfig::GetInstance().GetCommMap()[EvtID].service,
             CommConfig::GetInstance().GetCommMap()[EvtID].position, 
             CommConfig::GetInstance().GetCommMap()[EvtID].function}
            );

        myPublisher.publishCopyOf(CounterTopic{counter})
            .and_then([&] { std::cout << "Sending: " << counter << std::endl; })
            .or_else([&](auto) { std::cout << "Failed sending: " << counter << std::endl; });
        return 1;
    }
    uid_t GetUid() const
    {
        if (pbPtr_ != nullptr) {
            pbPtr_->getUid();
            return 1;
        }
        return -1;
    }
    void OfferService() noexcept
    {
        if (pbPtr_ != nullptr) {
            pbPtr_->offer();
        }
    }
    void StopOfferService() noexcept
    {
        if (pbPtr_ != nullptr) {
            pbPtr_->stopOffer();
        }
    }

private:
    std::string  owner_;
    std::unique_ptr<iox::popo::Publisher<CounterTopic>> pbPtr_{nullptr};
};

}

#endif