/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <string>
#include <thread>
#include <chrono>

#include "cpp/base_wait_interface.h"
#include "cpp/comm_config.h"

#include "iceoryx_hoofs/cxx/optional.hpp"
#include "iceoryx_posh/popo/subscriber.hpp"
#include "iceoryx_posh/popo/wait_set.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"
#include "iceoryx_hoofs/internal/units/duration.hpp"
#include "iceoryx_hoofs/cxx/vector.hpp"
#include "iceoryx_posh/iceoryx_posh_types.hpp"
#include "iceoryx_posh/internal/popo/building_blocks/condition_variable_data.hpp"

int WaitEvt(const int evtID, const int timeout)
{
    struct CounterTopic
    {
        uint32_t counter;
    };
    int res = -1;
    iox::runtime::PoshRuntime::initRuntime("iox-cpp-basic-doip-wait"); // (owner_);
    iox::cxx::optional<iox::popo::WaitSet<>> waitset_;
    waitset_.emplace();
    uint32_t counter = 8U;
       
    iox::popo::Subscriber<CounterTopic> subscriber({HHT::CommConfig::GetInstance().GetCommMap()[evtID].service,
            HHT::CommConfig::GetInstance().GetCommMap()[evtID].position, 
            HHT::CommConfig::GetInstance().GetCommMap()[evtID].function});
    waitset_->attachState(subscriber, iox::popo::SubscriberState::HAS_DATA).or_else([](auto) {
            std::cerr << "failed to attach subscriber" << std::endl;
    });
    auto notificationVector = waitset_->wait();
    for (auto& notification : notificationVector) {
    if (notification->doesOriginateFrom(&subscriber)) {
        // Consume a sample
        subscriber.take()
            .and_then([&res](auto& sample) { 
                std::cout << " got value: " << sample->counter << std::endl; 
                res = sample->counter;
                })
            .or_else([](auto& reason) {
                    std::cout << "got no data, return code: " << static_cast<uint64_t>(reason) << std::endl;
            });
        }
    }
    return res;
}
