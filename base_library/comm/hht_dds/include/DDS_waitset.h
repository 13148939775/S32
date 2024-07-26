/**
 * @file DDS_waitset.h
 * @brief 
 * @author T001294
 * @version 1.0
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023  HRYT
 * 
 */

#ifndef DDSWAITSET_H_
#define DDSWAITSET_H_

#include <dds/core/ddscore.hpp>
#include <rti/core/cond/AsyncWaitSet.hpp>

namespace HHT {
namespace DDSComm {

template <typename requesterDataType, typename replierDataType>
class DDSReplierEntity;

template <typename dataType>
class DDSPublisherEntity;

template <typename dataType>
class DDSSubscriberEntity;

class DDSConditionHandler {
public:
    virtual void operator()() = 0;
};

template <typename requesterDataType, typename replierDataType>
class RequestDataAvailableHandler : public DDSConditionHandler {
public:
    void operator()() override {
        replier_.GetRequests();
    }
    explicit RequestDataAvailableHandler(DDSReplierEntity<requesterDataType, replierDataType> &replier) :
        replier_(replier) {
    }

private:
    DDSReplierEntity<requesterDataType, replierDataType> &replier_;
};

template <typename dataType>
class SubscriberDataAvailableHandler : public DDSConditionHandler {
public:
    void operator()() override {
        subscriber_.SubscribeWS();
    }
    explicit SubscriberDataAvailableHandler(DDSSubscriberEntity<dataType> &subscriber) :
        subscriber_(subscriber) {
    }

private:
    DDSSubscriberEntity<dataType> &subscriber_;
};

template <typename dateType>
class PublisherSendEventHandler {
public:
    void operator()(dds::core::cond::Condition condition) {
        dds::core::cond::GuardCondition guard_condition = dds::core::polymorphic_cast<dds::core::cond::GuardCondition>(condition);
        guard_condition.trigger_value(false);
        publisher_.publish();
    }
    explicit PublisherSendEventHandler(DDSPublisherEntity<dateType> &publisher) :
        publisher_(publisher) {
    }

private:
    DDSPublisherEntity<dateType> &publisher_;
};

}
} // namespace HHT::DDSComm

#endif // DDSWAITSET_H_