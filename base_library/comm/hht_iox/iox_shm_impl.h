/**
 * @file iox_publisher_impl.h
 * @author T001294
 * @brief
 * @version 0.1
 * @date 2023-08-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ICEORYX_SHM_H_
#define ICEORYX_SHM_H_

#include "iceoryx_hoofs/cxx/optional.hpp"
#include "iceoryx_posh/popo/publisher.hpp"
#include "iceoryx_posh/popo/subscriber.hpp"
#include "iceoryx_posh/popo/wait_set.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"

namespace HHTSHMCOMM {
class BaseRuntime {
 public:
  BaseRuntime(const iox::capro::IdString_t &app_name) : app_name_(app_name) {
    iox::runtime::PoshRuntime::initRuntime(app_name_);
  }
  virtual ~BaseRuntime() {}

 private:
  iox::capro::IdString_t app_name_;
};

template <typename SubscriberDataType>
class Subscriber : public BaseRuntime {
 public:
  Subscriber(const iox::capro::IdString_t &app_name,
             const iox::capro::IdString_t &topic_name)
      : BaseRuntime(app_name), subscriber_({topic_name, "", ""}) {
    Init();
  }

  virtual ~Subscriber() {
    // unsubscribe
    wait_set_.reset();
    subscriber_.unsubscribe();
  }

  void Init() {
    // TODO:
    //  subscriber_options_.queueCapacity = queue_capacity;
    //  subscriber_options_.subscribeOnCreate = false;
    //  // 队列满默认阻止生产者，可选丢弃
    //  subscriber_options_.queueFullPolicy =
    //  iox::popo::QueueFullPolicy::BLOCK_PRODUCER;

    // subscribe
    subscriber_.subscribe();
    InitWaitSet();
  }

  void SubscribeData(SubscriberDataType &recv_data) {
    subscriber_.take().and_then(
        [&](auto &sample) { recv_data = std::move(*sample); });
  }

  void SubscribeData(SubscriberDataType &recv_data, bool wait_set) {
    if (!wait_set) {
      return;
    } else {
      auto notification_vector = wait_set_->wait();
      for (auto &notification : notification_vector) {
        if (notification->doesOriginateFrom(&subscriber_)) {
          SubscribeData(recv_data);
        }
      }
    }
  }

  void InitWaitSet() {
    wait_set_.emplace();
    wait_set_->attachState(subscriber_, iox::popo::SubscriberState::HAS_DATA)
        .or_else([](auto) {
          std::cerr << "waitset failed to attach subscriber" << std::endl;
        });
  }

 private:
  iox::popo::Subscriber<SubscriberDataType> subscriber_;
  iox::cxx::optional<iox::popo::WaitSet<>> wait_set_;
};

template <typename PublisherDataType>
class Publisher : public BaseRuntime {
 public:
  Publisher(const iox::capro::IdString_t &app_name,
            const iox::capro::IdString_t &topic_name)
      : BaseRuntime(app_name), publisher_({topic_name, "", ""}) {}

  virtual ~Publisher() { std::cout << "析构.." << std::endl; }

  void Init() { publisher_.offer(); }

  void PublishData(PublisherDataType &send_data) {
    publisher_.loan(send_data).and_then([](auto &sample) { sample.publish(); });
  }

 private:
  iox::popo::Publisher<PublisherDataType> publisher_;
};
};  // namespace HHTSHMCOMM

#endif  // ICEORYX_SHM_H_