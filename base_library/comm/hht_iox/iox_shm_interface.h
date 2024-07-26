/**
 * @file iox_publisher_impl.h
 * @author T001294
 * @brief
 * @version 0.1
 * @date 2023-09-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ICEORYX_SHM_IMP_H
#define ICEORYX_SHM_IMP_H

#include "iox_shm_impl.h"
using namespace HHTSHMCOMM;

namespace HHT {
template <typename SubscriberDataType>
class HHTSubscriber {
 public:
  HHTSubscriber(const iox::capro::IdString_t &app_name,
                const iox::capro::IdString_t &topic_name)
      : subscriber_(app_name, topic_name) {}
  virtual ~HHTSubscriber() {}
  void Subscribe(SubscriberDataType &recv_data, bool waitset = false) {
    (!waitset) ? subscriber_.SubscribeData(recv_data)
               : subscriber_.SubscribeData(recv_data, waitset);
  }

 private:
  Subscriber<SubscriberDataType> subscriber_;
};

template <typename PublisherDataType>
class HHTPublisher {
 public:
  HHTPublisher(const iox::capro::IdString_t &app_name,
               const iox::capro::IdString_t &topic_name)
      : publisher_(app_name, topic_name) {}
  virtual ~HHTPublisher() {}
  void Publish(PublisherDataType &send_data) {
    publisher_.PublishData(send_data);
  }

 private:
  Publisher<PublisherDataType> publisher_;
};

}  // namespace HHT

#endif  // ICEORYX_SHM_IMP_H
