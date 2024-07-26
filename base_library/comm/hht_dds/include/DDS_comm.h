/**
 * @file DDS_comm.h
 * @brief 
 * @author T001294
 * @version 1.0
 * @date 2023-10-25
 * 
 * @copyright Copyright (c) 2023  HRYT
 * 
 */

#ifndef DDSCOMM_H_
#define DDSCOMM_H_

#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <dds/domain/qos/DomainParticipantQos.hpp> //QOS
#include <rti/request/rtirequest.hpp>
#include <rti/util/util.hpp>     // for sleep
#include <rti/config/Logger.hpp> // for logging

#include "DDS_waitset.h"

namespace HHT {
namespace DDSComm {

class DDSBase {
public:
    virtual void Create() = 0;
    virtual void SetQos() = 0;
};

static dds::core::QosProvider qos_provider_("../../config/dds_config/USER_QOS_PROFILES.xml");
static std::string replier_Qos_ = "RequestReplyExampleProfiles::ReplierExampleProfile";
static std::string request_Qos_ = "RequestReplyExampleProfiles::RequesterExampleProfile";
static dds::domain::DomainParticipant domain_participant_(1, qos_provider_.participant_qos("RequestReplyExampleProfiles::default"));

class DDSrrParams {
public:
    DDSrrParams() :
        max_wait_time_(dds::core::Duration::from_millisecs(500)) {
    }
    DDSrrParams(const uint32_t milliseconds) :
        max_wait_time_(dds::core::Duration::from_millisecs(milliseconds)) {
    }

    DDSrrParams(const DDSrrParams &rhs) = delete;
    DDSrrParams &operator=(const DDSrrParams &rhs) = delete;

    DDSrrParams(DDSrrParams &&rhs) noexcept :
        max_wait_time_(std::move(rhs.max_wait_time_)) {
    }

    DDSrrParams &operator=(DDSrrParams &&rhs) noexcept {
        if (this != &rhs) {
            max_wait_time_ = std::move(rhs.max_wait_time_);
        }
        return *this;
    }

    void SetMaxWaitTime(const uint32_t milliseconds) {
        max_wait_time_ = dds::core::Duration::from_millisecs(milliseconds);
    }

protected:
    dds::core::Duration max_wait_time_;
};

template <typename requesterDataType, typename replierDataType>
class DDSRequesterEntity : public DDSrrParams, public DDSBase {
private:
    using LoanedData = dds::sub::LoanedSamples<replierDataType>;

public:
    DDSRequesterEntity() :
        requester_params_(domain_participant_),
        requester_ptr_(nullptr) {
    }
    DDSRequesterEntity(const std::string &req_topic_name, const std::string &rep_topic_name, const uint32_t max_wait_time = 500) :
        DDSrrParams(max_wait_time),
        requester_params_(domain_participant_) {
        Init(req_topic_name, rep_topic_name);
    }

    DDSRequesterEntity(const std::string &service_name, const uint32_t max_wait_time = 500) :
        DDSrrParams(max_wait_time),
        requester_params_(domain_participant_) {
        Init(service_name);
    }

    DDSRequesterEntity(const DDSRequesterEntity &rhs) = delete;
    DDSRequesterEntity &operator=(const DDSRequesterEntity &rhs) = delete;

    DDSRequesterEntity(DDSRequesterEntity &&rhs) noexcept :
        DDSrrParams(std::move(rhs)),
        requester_params_(std::move(rhs.requester_params_)),
        requester_ptr_(std::move(rhs.requester_ptr_)) {
    }

    DDSRequesterEntity &operator=(DDSRequesterEntity &&rhs) noexcept {
        if (this != &rhs) {
            DDSrrParams::operator=(std::move(rhs));
            requester_ptr_ = std::move(rhs.requester_ptr_);
        }
        return *this;
    }
    ~DDSRequesterEntity() noexcept = default;

    void Init(const std::string &req_topic_name, const std::string &rep_topic_name) {
        SetQos();
        requester_params_.request_topic_name(req_topic_name);
        requester_params_.reply_topic_name(rep_topic_name);
        Create();
    }

    void Init(const std::string &service_name) {
        SetQos();
        requester_params_.service_name(service_name);
        Create();
    }

    void Create() override {
        requester_ptr_ = std::make_unique<rti::request::Requester<requesterDataType, replierDataType>>(requester_params_);
    }

    void WaitForReplier() {
        while (rti::request::matched_replier_count(*requester_ptr_) == 0) {
            rti::util::sleep(dds::core::Duration::from_millisecs(500));
        }
    }

    void SetQos() override {
        requester_params_.datareader_qos(qos_provider_.datareader_qos(request_Qos_));
        requester_params_.datawriter_qos(qos_provider_.datawriter_qos(request_Qos_));
    }

    const char *GetRequestTopicName() const {
        return requester_params_.request_topic_name().c_str();
    }

    const char *GetReplyTopicName() const {
        return requester_params_.reply_topic_name().c_str();
    }

    void SendRequest(const requesterDataType &data) const {
        requester_ptr_->send_request(data);
    }

    LoanedData RecvReply() const {
        return (requester_ptr_->wait_for_replies(max_wait_time_)) ? requester_ptr_->take_replies() : LoanedData();
    }

private:
    rti::request::RequesterParams requester_params_;
    std::unique_ptr<rti::request::Requester<requesterDataType, replierDataType>> requester_ptr_;
};

template <typename requesterDataType, typename replierDataType>
class DDSReplierEntity : public DDSrrParams, public DDSBase {
private:
    using ReplyListener = std::shared_ptr<rti::request::ReplierListener<requesterDataType, replierDataType>>;
    using LoanedData = dds::sub::LoanedSamples<requesterDataType>;

    DDSReplierEntity(const uint32_t max_wait_time) :
        DDSrrParams(max_wait_time),
        replier_params_(domain_participant_) {
    }

public:
    DDSReplierEntity() :
        is_listener_(false),
        replier_params_(domain_participant_),
        replier_ptr_(nullptr),
        async_waitset_(),
        is_waitset_(false),
        recv_samples_() {
    }
    DDSReplierEntity(const std::string &req_topic_name, const std::string &rep_topic_name, ReplyListener listener, const uint32_t max_wait_time = 500) :
        DDSReplierEntity(max_wait_time) {
        is_listener_ = true;
        listener_ = ReplyListener(listener);
        Init(req_topic_name, rep_topic_name);
    }

    DDSReplierEntity(const std::string &service_name, ReplyListener listener, const uint32_t max_wait_time = 500) :
        DDSReplierEntity(max_wait_time) {
        is_listener_ = true;
        listener_ = ReplyListener(listener);
        Init(service_name);
    }

    DDSReplierEntity(const std::string &req_topic_name, const std::string &rep_topic_name, rti::core::cond::AsyncWaitSet async_waitset, const uint32_t max_wait_time = 500) :
        DDSReplierEntity(max_wait_time) {
        async_waitset_ = rti::core::cond::AsyncWaitSet(async_waitset);
        is_waitset_ = true;
        Init(req_topic_name, rep_topic_name);
        dds::core::cond::StatusCondition reader_status_condition(replier_ptr_->request_datareader());
        reader_status_condition.enabled_statuses(dds::core::status::StatusMask::data_available());
        reader_status_condition->handler(RequestDataAvailableHandler<requesterDataType, replierDataType>(*this));
        async_waitset_.attach_condition(reader_status_condition);
    }

    DDSReplierEntity(const DDSReplierEntity &rhs) = delete;

    DDSReplierEntity &operator=(const DDSReplierEntity &rhs) = delete;

    DDSReplierEntity(DDSReplierEntity &&rhs) noexcept :
        DDSrrParams(std::move(rhs)),
        is_listener_(std::move(rhs.is_listener_)),
        listener_(std::move(rhs.listener_)),
        replier_params_(std::move(rhs.replier_params)),
        replier_ptr_(std::move(rhs.replier_ptr)),
        async_waitset_(std::move(rhs.async_waitset_)),
        is_waitset_(std::move(rhs.is_waitset_)),
        recv_samples_(std::move(rhs.recv_samples_)) {
    }

    DDSReplierEntity &operator=(DDSReplierEntity &&rhs) noexcept {
        if (this != &rhs) {
            DDSrrParams::operator=(std::move(rhs));
            is_listener_ = std::move(rhs.is_listener_);
            listener_ = std::move(rhs.listener_);
            replier_params_ = std::move(rhs.replier_params_);
            replier_ptr_ = std::move(rhs.replier_ptr_);
            async_waitset_ = std::move(rhs.async_waitset_);
            is_waitset_ = std::move(rhs.is_waitset_);
            recv_samples_ = std::move(rhs.recv_samples_);
        }
        return *this;
    }

    ~DDSReplierEntity() noexcept {
        if (is_waitset_) {
            async_waitset_.detach_condition(dds::core::cond::StatusCondition(replier_ptr_->request_datareader()));
        }
    }

    void Init(const std::string &req_topic_name, const std::string &rep_topic_name) {
        SetQos();
        SetTopicName(req_topic_name, rep_topic_name);
        Create();
    }

    void Init(const std::string &service_name) {
        SetQos();
        replier_params_.service_name(service_name);
        Create();
    }
    void Create() override {
        if (is_listener_) {
            replier_ptr_ = std::make_unique<rti::request::Replier<requesterDataType, replierDataType>>(replier_params_, listener_);
        } else if (is_waitset_) {
            replier_ptr_ = std::make_unique<rti::request::Replier<requesterDataType, replierDataType>>(replier_params_);
        }
    }

    void SetQos() override {
        replier_params_.datareader_qos(qos_provider_.datareader_qos(replier_Qos_));
        replier_params_.datawriter_qos(qos_provider_.datawriter_qos(replier_Qos_));
    }

    void SetTopicName(const std::string &req_topic_name, const std::string &rep_topic_name) {
        replier_params_.request_topic_name(req_topic_name);
        replier_params_.reply_topic_name(rep_topic_name);
    }

    const char *GetRequestTopicName() const {
        return replier_params_.request_topic_name().c_str();
    }

    const char *GetReplyTopicName() const {
        return replier_params_.reply_topic_name().c_str();
    }

    void GetRequests() {
        recv_samples_ = std::move(replier_ptr_->receive_requests(max_wait_time_));
    }

    LoanedData RecvRequest() {
        return std::move(recv_samples_);
    }

    void SendReply(const replierDataType &send_data, const dds::sub::TSampleInfo<rti::sub::SampleInfoImpl> &request_info) const {
        replier_ptr_->send_reply(send_data, request_info);
    }

private:
    bool is_listener_{false};
    ReplyListener listener_;
    rti::request::ReplierParams replier_params_;
    std::unique_ptr<rti::request::Replier<requesterDataType, replierDataType>> replier_ptr_;

private:
    rti::core::cond::AsyncWaitSet async_waitset_;
    bool is_waitset_{false};

private:
    LoanedData recv_samples_;
};

template <typename dataType>
class DDSpsParams {
public:
    DDSpsParams() :
        topic_(domain_participant_, "") {
    }
    DDSpsParams(const std::string &topic_name) :
        topic_(domain_participant_, topic_name) {
    }
    DDSpsParams(const DDSpsParams &rhs) = delete;
    DDSpsParams &operator=(const DDSpsParams &rhs) = delete;

    DDSpsParams(DDSpsParams &&rhs) noexcept :
        topic_(std::move(rhs.topic)) {
    }

    DDSpsParams &operator=(DDSpsParams &&rhs) noexcept {
        if (this != &rhs) {
            topic_ = std::move(rhs.topic_);
        }
        return *this;
    }

protected:
    dds::topic::Topic<dataType> topic_;
};

template <typename dataType>
class DDSPublisherEntity : public DDSpsParams<dataType>, public DDSBase {
public:
    DDSPublisherEntity() :
        send_sample_(),
        writer_qos_(),
        writer_(nullptr),
        async_waitset_(),
        is_waitset_(false),
        send_condition_() {
    }
    DDSPublisherEntity(const std::string &topic_name) :
        DDSpsParams<dataType>(topic_name), is_waitset_(false) {
        Create();
    }

    DDSPublisherEntity(const std::string &topic_name, rti::core::cond::AsyncWaitSet async_waitset) :
        DDSpsParams<dataType>(topic_name), async_waitset_(async_waitset), is_waitset_(true) {
        Create();
        send_condition_.handler(PublisherSendEventHandler<dataType>(*this));
        async_waitset_.attach_condition(send_condition_);
    }

    DDSPublisherEntity(const DDSPublisherEntity &rhs) = delete;
    DDSPublisherEntity &operator=(const DDSPublisherEntity &rhs) = delete;

    DDSPublisherEntity(DDSPublisherEntity &&rhs) noexcept :
        DDSpsParams<dataType>(std::move(rhs)),
        send_sample_(std::move(rhs.send_sample_)),
        writer_qos_(std::move(rhs.writer_qos_)),
        writer_(std::move(rhs.writer)),
        async_waitset_(std::move(rhs.async_waitset)),
        is_waitset_(std::move(rhs.is_waitset)),
        send_condition_(std::move(rhs.send_condition)) {
    }
    DDSPublisherEntity &operator=(DDSPublisherEntity &&rhs) noexcept {
        if (this != &rhs) {
            DDSpsParams<dataType>::operator=(std::move(rhs));
            send_sample_ = std::move(rhs.send_sample_);
            writer_qos_ = std::move(rhs.writer_qos_);
            writer_ = std::move(rhs.writer_);
            async_waitset_ = std::move(rhs.async_waitset_);
            is_waitset_ = std::move(rhs.is_waitset_);
            send_condition_ = std::move(rhs.send_condition_);
        }
        return *this;
    }

    ~DDSPublisherEntity() noexcept {
        if (is_waitset_) {
            async_waitset_.detach_condition(send_condition_);
        }
    }

    void Create() override {
        writer_ = std::make_unique<dds::pub::DataWriter<dataType>>(dds::pub::Publisher(domain_participant_), DDSpsParams<dataType>::topic_);
    }

    void Set(const dataType &sample) {
        send_sample_ = std::move(sample);
    }

    void SetQos() override {
        // todo: implement
    }

    void publish() const {
        writer_->write(send_sample_);
    }
    void SendEvent() {
        send_condition_.trigger_value(true);
    }

private:
    dataType send_sample_;
    dds::pub::qos::DataWriterQos writer_qos_;
    std::unique_ptr<dds::pub::DataWriter<dataType>> writer_;

private:
    rti::core::cond::AsyncWaitSet async_waitset_;
    bool is_waitset_;
    dds::core::cond::GuardCondition send_condition_;
};

template <typename dataType>
class DDSSubscriberEntity : public DDSpsParams<dataType>, public DDSBase {
private:
    using LoanedData = dds::sub::LoanedSamples<dataType>;

public:
    DDSSubscriberEntity() :
        reader_(nullptr),
        is_waitset_(false) {
    }
    DDSSubscriberEntity(const std::string &topic_name) :
        DDSpsParams<dataType>(topic_name), is_waitset_(false) {
        Create();
    }

    DDSSubscriberEntity(const std::string &topic_name, rti::core::cond::AsyncWaitSet async_waitset) :
        DDSpsParams<dataType>(topic_name), async_waitset_(async_waitset), is_waitset_(true) {
        Create();
        dds::core::cond::StatusCondition reader_status_condition(*reader_);
        reader_status_condition.enabled_statuses(dds::core::status::StatusMask::data_available());
        reader_status_condition->handler(SubscriberDataAvailableHandler<dataType>(*this));
        async_waitset_.attach_condition(reader_status_condition);
    }

    DDSSubscriberEntity(DDSSubscriberEntity &&rhs) noexcept :
        DDSpsParams<dataType>(std::move(rhs)),
        recv_samples_(std::move(rhs.recv_samples_)),
        reader_(std::move(rhs.reader_)),
        async_waitset_(std::move(rhs.async_waitset_)),
        is_waitset_(std::move(rhs.is_waitset_)) {
    }
    DDSSubscriberEntity &operator=(DDSSubscriberEntity &&rhs) noexcept {
        if (this != &rhs) {
            DDSpsParams<dataType>::operator=(std::move(rhs));
            recv_samples_ = std::move(rhs.recv_samples_);
            reader_ = std::move(rhs.reader_);
            async_waitset_ = std::move(rhs.async_waitset_);
            is_waitset_ = std::move(rhs.is_waitset_);
        }
        return *this;
    }

    ~DDSSubscriberEntity() noexcept {
        if (is_waitset_) {
            async_waitset_.detach_condition(dds::core::cond::StatusCondition(*reader_));
        }
    }

    void Create() override {
        reader_ = std::make_unique<dds::sub::DataReader<dataType>>(dds::sub::Subscriber(domain_participant_), DDSpsParams<dataType>::topic_);
    }

    void SetQos() override {
        // todo: implement
    }

    void SubscribeWS() {
        recv_samples_ = std::move(reader_->take());
        // after take data, incase others to use waitset and comes new data
        if (is_waitset_) {
            async_waitset_.unlock_condition(dds::core::cond::StatusCondition(*reader_));
        }
    }

    LoanedData Get() {
        return is_waitset_ ? std::move(recv_samples_) : reader_->take();
    }

private:
    LoanedData recv_samples_;
    dds::sub::qos::DataReaderQos reader_qos_;
    std::unique_ptr<dds::sub::DataReader<dataType>> reader_;

private:
    rti::core::cond::AsyncWaitSet async_waitset_;
    bool is_waitset_;
};

}

} // namespace HHT::DDSComm

#endif //DDSCOMM_H_
