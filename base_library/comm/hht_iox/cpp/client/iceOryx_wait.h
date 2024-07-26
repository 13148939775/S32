/*
 * @author 008196
 * @for iceOryx wait
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ICEORYX_WAIT_H
#define ICEORYX_WAIT_H

#include <string>
#include <thread>
#include <chrono>

#include "cpp/comm_config.h"

#include "iceoryx_hoofs/cxx/optional.hpp"
#include "iceoryx_posh/popo/subscriber.hpp"
#include "iceoryx_posh/popo/wait_set.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"
#include "iceoryx_hoofs/internal/units/duration.hpp"
#include "iceoryx_hoofs/cxx/vector.hpp"
#include "iceoryx_posh/iceoryx_posh_types.hpp"
#include "iceoryx_posh/internal/popo/building_blocks/condition_variable_data.hpp"

namespace HHT {

class IceOryxWait {
public:
    struct CounterTopic
    {
        uint32_t counter;
    };

    IceOryxWait() = default;

    ~IceOryxWait() = default;

    bool Init() 
    {
      
    }

    int Wait(const Event evtID, const int timeout)
    {
        waitset_.emplace();
       
        iox::popo::Subscriber<CounterTopic> subscriber({CommConfig::GetInstance().GetCommMap()[evtID].service,
            CommConfig::GetInstance().GetCommMap()[evtID].position, CommConfig::GetInstance().GetCommMap()[evtID].function});
        waitset_->attachState(subscriber, iox::popo::SubscriberState::HAS_DATA).or_else([](auto) {
            std::cerr << "failed to attach subscriber" << std::endl;
        });
                //while (!exit_) {
        
        // auto notificationVector = waitset_->timedWait(10_s);
        auto notificationVector = waitset_->wait();
        for (auto& notification : notificationVector) {
        if (notification->doesOriginateFrom(&subscriber)) {
                            // Consume a sample
            subscriber.take()
                .and_then([this](auto& sample) { 
                                    std::cout << " got value: " << sample->counter << std::endl; 
                                    res_ = sample->counter;
                                    })
                                .or_else([](auto& reason) {
                                    std::cout << "got no data, return code: " << static_cast<uint64_t>(reason) << std::endl;
                                });
                        }
                    }
                //}
            //}
        //);
        return res_;
    }
private:
    std::string  owner_;
    iox::cxx::optional<iox::popo::WaitSet<>> waitset_;
    //std::unique_ptr<iox::popo::Subscriber<CounterTopic>> subscriberPtr_{nullptr};
    //std::thread worker_;
    //std::atomic<bool> exit_{false};
    int res_{-1};
    //int evtID_{-1};
    //int timeout_{0};
};

}

#endif

