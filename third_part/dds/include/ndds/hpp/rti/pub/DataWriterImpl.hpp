/* $Id$

(c) Copyright, Real-Time Innovations, 2013-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


modification history
--------------------
1.0a,22feb13,acr Created
===================================================================== */

#ifndef RTI_DDS_PUB_DATAWRITER_HPP_
#define RTI_DDS_PUB_DATAWRITER_HPP_

#include <utility> // for std::pair

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "ndds/ndds_c.h"
#include "dds_c/dds_c_publication_impl.h"

#include <dds/core/types.hpp>
#include <dds/core/Value.hpp>

#include <dds/core/ref_traits.hpp>
#include <rti/core/Entity.hpp>

#include <dds/domain/DomainParticipant.hpp>
#include <dds/pub/Publisher.hpp>
#include <dds/topic/Topic.hpp>
#include <dds/topic/TopicInstance.hpp>

#include <dds/pub/pubfwd.hpp> // for forward declaration of DataWriterListener
#include <dds/pub/qos/DataWriterQos.hpp>
#include <rti/core/Locator.hpp>
#include <rti/pub/WriteParams.hpp>
#include <rti/pub/detail/DataWriterListenerForwarder.hpp>
#include <rti/core/detail/NativeEntity.hpp> // for create_from_native_entity()
#include <rti/core/detail/NativeConversion.hpp>
#include <rti/core/detail/ListenerHolder.hpp>

namespace rti { namespace pub {

namespace detail {

using namespace rti::core::detail;

OMG_DDS_API
void get_flat_loan_untyped(
        DDS_DataWriter * self,
        char ** sample,
		RTIXCdrInterpreterPrograms* programs,
		bool is_final);

OMG_DDS_API
DDS_ReturnCode_t initialize_flat_loan_untyped(
        DDS_DataWriter * self,
        char ** sample,
        RTIXCdrInterpreterPrograms * programs,
        bool is_final);
}

// NativeWritePolicy implements the way DataWriter calls the C API to write
// a sample.
//
// NativeWritePolicy provides a default implementation and allows injecting
// a different implementation to customize how the DataWriter writes a sample
// depending on properties of the topic-type T (via SFINAE on the the Enable 
// template argument).
// 
// Currently two specializations exist: 
// - For Zero Copy types, the specialization included by metp.1.0 is used
// - For FlatData types, the specialization included by rti/topic/FlatData.hpp 
//   is used
//
template <typename T, typename Enable = void>
struct NativeWritePolicy {
public:
    static DDS_ReturnCode_t write(
            DDS_DataWriter *self,
            const T *data,
            const DDS_InstanceHandle_t *handle)
    {
        return DDS_DataWriter_write_untypedI(
                self,
                (void *)data,
                handle);
    }

    static DDS_ReturnCode_t write(
            DDS_DataWriter *self,
            const T *data,
            const DDS_InstanceHandle_t *handle,
            const DDS_Time_t *source_timestamp)
    {
        return DDS_DataWriter_write_w_timestamp_untypedI(
                self,
                (void *)data,
                handle,
                source_timestamp);
    }

    static DDS_ReturnCode_t write(
            DDS_DataWriter *self,
            const T *data,
            DDS_WriteParams_t *params)
    {
        return DDS_DataWriter_write_w_params_untypedI(
                self,
                (void *)data,
                params);
    }
};

// Native get loan and discard loan policy have 2 different implementations and
// work similar to native write policy. Refer to comments in Native write policy
template <typename T, typename Enable = void>
struct NativeGetLoanPolicy {
public:
    static T* get_loan(DDS_DataWriter *)
    {
        throw dds::core::UnsupportedError("get_loan() only supported for "
                "topic-types with FlatData language binding or "
                "transfer mode shmem ref");
    }
};

template <typename T, typename Enable = void>
struct NativeDiscardLoanPolicy {
public:
    static void discard_loan(DDS_DataWriter *, T *)
    {
        throw dds::core::UnsupportedError("discard_loan() only supported for "
                "topic-types with FlatData language binding or "
                "transfer mode shmem ref");
    }
};

template <typename T, typename Enable = void>
struct NativeCreateDataPolicy {
public:
    static T* create_data(DDS_DataWriter *)
    {
        return new T();
    }

};

template <typename T, typename Enable = void>
struct NativeDeleteDataPolicy {
public:
    static bool delete_data(DDS_DataWriter *, T *sample)
    {
        delete sample;
        return true;
    }
};

// Specializations for DynamicData
template <>
struct OMG_DDS_API NativeCreateDataPolicy<dds::core::xtypes::DynamicData> {
public:
    static dds::core::xtypes::DynamicData* create_data(DDS_DataWriter* writer);
};

template <>
struct OMG_DDS_API NativeDeleteDataPolicy<dds::core::xtypes::DynamicData> {
public:
    static bool delete_data(
            DDS_DataWriter *writer,
            dds::core::xtypes::DynamicData *sample);
};

/** @RTI_class_definition NA */
class OMG_DDS_API UntypedDataWriter : public rti::core::Entity {
protected:

    // We use a pair instead of two arguments because this is the return type
    // of a function that we call directly in the derived class constructor
    UntypedDataWriter(
            const std::pair<DDS_Entity*, bool>& writer_enable,
            rti::core::detail::ListenerHolderPtr listener_holder)
        : rti::core::Entity(writer_enable, listener_holder)
    {
    }

public:
    DDS_DataWriter * native_writer()
    {
        return (DDS_DataWriter *) native_entity();
    }

    const DDS_DataWriter * native_writer() const
    {
        return (const DDS_DataWriter *) native_entity();
    }

public:

    // --- Type-independent instance-management functions: --------------------

    void unregister_instance(const dds::core::InstanceHandle& instance);

    void unregister_instance(
        const dds::core::InstanceHandle& instance,
        const dds::core::Time& timestamp);

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Unregister an instance with parameters
     *
     * @extension_member_note
     *
     * @details \dref_details_FooDataWriter_unregister_instance_w_params
     */
    void unregister_instance(rti::pub::WriteParams& params);

    void dispose_instance(const dds::core::InstanceHandle& instance);

    void dispose_instance(
        const dds::core::InstanceHandle& instance,
        const dds::core::Time& timestamp);

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Dispose an instance with parameters
     *
     * @extension_member_note
     *
     * @details \dref_details_FooDataWriter_dispose_w_params
     */
    void dispose_instance(rti::pub::WriteParams& params);

    // --- Qos management: ----------------------------------------------------
    const dds::pub::qos::DataWriterQos qos() const;
    void qos(const dds::pub::qos::DataWriterQos& the_qos);

    // --- Acknowledgments: ---------------------------------------------------

    void wait_for_acknowledgments(const dds::core::Duration& max_wait);


    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Indicates if a sample is considered application-acknowledged
     *
     * @extension_member_note
     *
     * @details \dref_details_DataWriter_is_sample_app_acknowledged
     */
    bool is_sample_app_acknowledged(const rti::core::SampleIdentity& sample_id);

    /*i
     * \dref_DataWriter_is_sample_app_acknowledged
     */
    void wait_for_sample_acknowledgment(
        const rti::core::SampleIdentity& sample_id,
        const dds::core::Duration& max_wait);

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension
     *
     * @extension_member_note
     *
     * @details \dref_details_DataWriter_wait_for_asynchronous_publishing
     */
    void wait_for_asynchronous_publishing(const dds::core::Duration& max_wait);

    // --- Entity navigation: -------------------------------------------------

    virtual const dds::pub::Publisher& publisher() const = 0;
    virtual const std::string& topic_name() const = 0;
    virtual const std::string& type_name() const = 0;

    // --- Status getters: ----------------------------------------------------

    const dds::core::status::LivelinessLostStatus liveliness_lost_status();
    const dds::core::status::OfferedDeadlineMissedStatus offered_deadline_missed_status();
    const dds::core::status::OfferedIncompatibleQosStatus offered_incompatible_qos_status();
    const dds::core::status::PublicationMatchedStatus publication_matched_status();

    // Extensions

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Get the reliable cache status for this writer.
     *
     * @extension_member_note
     *
     * @details \dref_details_DataWriter_get_reliable_writer_cache_changed_status
     */
    rti::core::status::ReliableWriterCacheChangedStatus reliable_writer_cache_changed_status();

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Get the reliable reader activity changed status for
     * this writer
     *
     * @extension_member_note
     * @details \dref_details_DataWriter_get_reliable_reader_activity_changed_status
     */
    rti::core::status::ReliableReaderActivityChangedStatus reliable_reader_activity_changed_status();

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Get the cache status for this writer
     *
     * @extension_member_note
     *
     * @details \dref_details_DataWriter_get_datawriter_cache_status
     */
    rti::core::status::DataWriterCacheStatus datawriter_cache_status();

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Get the protocol status for this writer
     *
     * @extension_member_note
     *
     * @details \dref_details_DataWriter_get_datawriter_protocol_status
     */
    rti::core::status::DataWriterProtocolStatus datawriter_protocol_status();

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Get the datawriter protocol status for this writer, per
     * matched subscription identified by the subscription_handle.
     *
     * @extension_member_note
     *
     * @details \dref_details_DataWriter_get_matched_subscription_datawriter_protocol_status
     */
    rti::core::status::DataWriterProtocolStatus matched_subscription_datawriter_protocol_status(
        const dds::core::InstanceHandle& subscription_handle);

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Get the datawriter protocol status for this writer,
     * per matched subscription identified by the locator
     *
     * @extension_member_note
     *
     * @details \dref_details_DataWriter_get_matched_subscription_datawriter_protocol_status_by_locator 
     *  
     * @param subscription_locator \st_in Locator to a specific locator 
     * associated with the DataReader. Must correspond to a locator of 
     * one or more subscriptions currently associated with the DataWriter.
     */
    rti::core::status::DataWriterProtocolStatus matched_subscription_datawriter_protocol_status(
        const rti::core::Locator& subscription_locator);

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Get the service request accepted status for this writer
     *
     * @extension_member_note
     *
     * @details \dref_details_DataWriter_get_matched_subscription_datawriter_protocol_status_by_locator 
     *  
     */
    rti::core::status::ServiceRequestAcceptedStatus service_request_accepted_status();

    // --- Liveliness Management: ---------------------------------------------

    void assert_liveliness();

    // --- Other: -------------------------------------------------------------

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Flushes the batch in progress in the context of the
     * calling thread.
     *
     * @extension_member_note
     *
     * @details \dref_details_DataWriter_flush
     */
    void flush();
};

namespace detail {

OMG_DDS_API
std::pair<DDS_Entity*, bool> create_native_writer_untyped(
    const dds::pub::Publisher& pub,
    const DDS_Topic * topic,
    const dds::pub::qos::DataWriterQos * qos,
    DDS_DataWriterListener * listener,
    const dds::core::status::StatusMask& mask);

// Returns native writer and boolean indicating if it needs to be enabled
template <typename T>
std::pair<DDS_Entity*, bool> create_native_writer(
    const dds::pub::Publisher& pub,
    const dds::topic::Topic<T>& topic,
    const dds::pub::qos::DataWriterQos * qos = NULL,
    dds::pub::DataWriterListener<T>* listener = NULL,
    const dds::core::status::StatusMask& mask =
        dds::core::status::StatusMask::all())
{
    DDS_DataWriterListener native_listener;
    if (listener != NULL) {
        native_listener = create_native_listener<T>(listener);
    }

    return create_native_writer_untyped(
        pub, topic->native_topic(), qos, listener ? &native_listener : NULL, mask);
}

} // namespace detail

/** @RTI_class_definition NA */
template<typename T>
class OMG_DDS_API DataWriterImpl : public UntypedDataWriter {
public:
    typedef dds::pub::DataWriterListener<T> Listener;

    DataWriterImpl(
            const dds::pub::Publisher& pub,
            const dds::topic::Topic<T>& the_topic)
            : UntypedDataWriter(
                    detail::create_native_writer(pub, the_topic),
                    detail::create_empty_listener_holder<Listener>()),
              publisher_(pub),
              topic_(the_topic)
    {
    }

    DataWriterImpl(
            const dds::pub::Publisher& pub,
            const dds::topic::Topic<T>& the_topic,
            const dds::pub::qos::DataWriterQos& the_qos,
            dds::pub::DataWriterListener<T>* the_listener = NULL,
            const dds::core::status::StatusMask& mask =
                    dds::core::status::StatusMask::all())
            : UntypedDataWriter(
                    detail::create_native_writer(
                            pub,
                            the_topic,
                            &the_qos,
                            the_listener,
                            mask),
                    detail::create_empty_listener_holder<Listener>()),
              publisher_(pub),
              topic_(the_topic)
    {
        if (the_listener != NULL) {
            retain_for_listener();
        }
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    DataWriterImpl(
            const dds::pub::Publisher& pub,
            const dds::topic::Topic<T>& the_topic,
            const dds::pub::qos::DataWriterQos& the_qos,
            std::shared_ptr<Listener> the_listener,
            const dds::core::status::StatusMask& mask =
                    dds::core::status::StatusMask::all())
            : UntypedDataWriter(
                    detail::create_native_writer(
                            pub,
                            the_topic,
                            &the_qos,
                            the_listener.get(),
                            mask),
                    detail::create_listener_holder(the_listener)),
              publisher_(pub),
              topic_(the_topic)
    {
    }
#endif

    // For internal use
    DataWriterImpl(DDS_DataWriter* the_native_writer)
            : UntypedDataWriter(
                    std::make_pair(
                            DDS_DataWriter_as_entity(the_native_writer),
                            false),
                    detail::create_empty_listener_holder<Listener>()),
              publisher_(dds::core::null),
              topic_(dds::core::null)
    {
        using rti::core::detail::create_from_native_entity;

        //RTI_ASSERT_PRECONDITION(native_writer != NULL);

        // Rebuild the C++ publisher from the native one
        DDS_Publisher * native_publisher =
            DDS_DataWriter_get_publisher(the_native_writer);
        //RTI_ASSERT_PRECONDITION(native_publisher != NULL);

        publisher_ = create_from_native_entity<dds::pub::Publisher>(
            native_publisher);

        // Rebuild the C++ topic from the native one
        DDS_Topic * native_topic =
            DDS_DataWriter_get_topic(the_native_writer);
        //RTI_ASSERT_PRECONDITION(native_topic != NULL);

        topic_ = create_from_native_entity<dds::topic::Topic<T> >(native_topic);
    }

    ~DataWriterImpl()
    {
        try {
            // Close with force_close = false so that entities that were created
            // from C (such as those defined in XML) are not deleted. They are
            // only deleted if this object is explicitly closed (close()).
            close_impl(false);
        } catch (const std::exception& ex) {
            DDSLog_logWithFunctionName(
                    RTI_LOG_BIT_EXCEPTION,
                    "~DataWriterImpl()",
                    &RTI_LOG_ANY_FAILURE_s,
                    ex.what());
        }
    }

    // --- Write API: ---------------------------------------------------------

    void write(const T& sample)
    {
        write(sample, dds::core::InstanceHandle::nil());
    }

    void write(const T& sample, const dds::core::Time& timestamp)
    {
        write(sample, dds::core::InstanceHandle::nil(), timestamp);
    }

    void write(const T& sample, const dds::core::InstanceHandle& instance)
    {
        DDS_ReturnCode_t retcode = NativeWritePolicy<T>::write(
                native_writer(),
                &sample,
                &instance->native());
        rti::core::check_return_code(retcode, "write");
    }

    void write(
        const T& sample,
        const dds::core::InstanceHandle& instance,
        const dds::core::Time& timestamp)
    {
        using dds::core::Time;

        DDS_Time_t native_time = DDS_TIME_ZERO;
        rti::core::native_conversions::to_native(native_time, timestamp);
        DDS_ReturnCode_t retcode = NativeWritePolicy<T>::write(
                native_writer(),
                &sample,
                &instance->native(),
                &native_time);
        rti::core::check_return_code(retcode, "write");
    }

    void write(const dds::topic::TopicInstance<T>& topic_instance)
    {
        write(
            topic_instance.sample(),
            topic_instance.handle());
    }

    void write(
        const dds::topic::TopicInstance<T>& topic_instance,
        const dds::core::Time& timestamp)
    {
        write(
            (void *) &topic_instance.sample(),
            &topic_instance.handle()->native(),
            timestamp);
    }

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Write with advanced parameters
     *
     * @extension_member_note
     *
     * @details \dref_details_FooDataWriter_write_w_params
     *
     */
    void write(const T& instance_data, rti::pub::WriteParams& params)
    {
        DDS_ReturnCode_t retcode = NativeWritePolicy<T>::write(
                native_writer(),
                &instance_data,
                &params.native());
       rti::core::check_return_code(retcode, "write with params");
    }


    // --- Data creation and deletion API: ---------------------------------------------------------
    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Create data from writer and initialize it
     *
     * @extension_member_note
     *
     * @details \dref_details_FooDataWriter_create_data
     *
     */
    T* create_data()
    {
        return NativeCreateDataPolicy<T>::create_data(native_writer());
    }

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Delete data from writer
     *
     * @extension_member_note
     *
     * @extension_member_note
     *
     * @details \dref_details_FooDataWriter_delete_data
     *
     */
    bool delete_data(T *sample)
    {
        return NativeDeleteDataPolicy<T>::delete_data(native_writer(), sample);
    }

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Get a loaned sample from this writer
     *
     * @extension_member_note
     *
     * @details \dref_details_FooDataWriter_get_loan
     *
     */
    T* get_loan()
    {
        return NativeGetLoanPolicy<T>::get_loan(native_writer());

    }

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Discard a loaned sample from this writer
     *
     * @extension_member_note
     *
     * @details \dref_details_FooDataWriter_discard_loan
     *
     */
    void discard_loan(T& sample)
    {
        return NativeDiscardLoanPolicy<T>::discard_loan(native_writer(), &sample);
    }

    // --- Instance management: -----------------------------------------------

    const dds::core::InstanceHandle register_instance(const T& key)
    {
        DDS_InstanceHandle_t native_handle =
            DDS_DataWriter_register_instance_untypedI(
                native_writer(), (void *) &key);

        return dds::core::InstanceHandle(native_handle);
    }


    const dds::core::InstanceHandle register_instance(
        const T& key,
        const dds::core::Time& timestamp)
    {
        using dds::core::Time;

        DDS_Time_t native_time = DDS_TIME_ZERO;
        rti::core::native_conversions::to_native(native_time, timestamp);
        DDS_InstanceHandle_t native_handle =
            DDS_DataWriter_register_instance_w_timestamp_untypedI(
                native_writer(), (void *) &key, &native_time);

        return dds::core::InstanceHandle(native_handle);
    }

    /**
     * @memberof dds::pub::DataWriter
     *
     * @brief @extension Registers and instance with parameters
     *
     * @extension_member_note
     *
     * @details \dref_details_FooDataWriter_register_instance_w_params
     */
    const dds::core::InstanceHandle register_instance(
        const T& key,
        rti::pub::WriteParams& params)
    {
        DDS_DataWriter_register_instance_w_params_untypedI(
            native_writer(),
            (void *) &key,
            &params.native());

        return params.handle();
    }


    dds::topic::TopicInstance<T>& key_value(
        dds::topic::TopicInstance<T>& topic_instance,
        const dds::core::InstanceHandle& handle)
    {
        DDS_ReturnCode_t retcode = DDS_DataWriter_get_key_value_untypedI(
            native_writer(), (void *) &topic_instance.sample(), &handle->native());
        rti::core::check_return_code(retcode, "get key value");

        topic_instance.handle(handle);

        return topic_instance;
    }

    T& key_value(T& key_holder, const dds::core::InstanceHandle& handle)
    {
        DDS_ReturnCode_t retcode = DDS_DataWriter_get_key_value_untypedI(
            native_writer(), (void *) &key_holder, &handle->native());
        rti::core::check_return_code(retcode, "get key value");

        return key_holder;
    }

    dds::core::InstanceHandle lookup_instance(const T& key)
    {
        DDS_InstanceHandle_t native_handle =
            DDS_DataWriter_lookup_instance_untypedI(
                native_writer(), (void *) &key);

        return dds::core::InstanceHandle(native_handle);
    }

    // --- Entity navigation: -------------------------------------------------

    const dds::topic::Topic<T>& topic() const
    {
        return topic_;
    }

    dds::topic::Topic<T>& topic()
    {
        return topic_;
    }

    const std::string& topic_name() const
    {
        return topic().name();
    }

    const std::string& type_name() const
    {
        return topic().type_name();
    }

    const dds::pub::Publisher& publisher() const
    {
        return publisher_;
    }

    dds::pub::Publisher& publisher()
    {
        return publisher_;
    }

    // --- Listeners: ---------------------------------------------------------

    void listener_impl(
            Listener* the_listener,
            const dds::core::status::StatusMask& mask,
            bool retain = true)
    {
        assert_legal_listener_setter_call(retain);
        if (the_listener == NULL) {
            DDS_DataWriter_set_listener(
                native_writer(), NULL, DDS_STATUS_MASK_NONE);
            if (retain) {
                this->unretain_for_listener();
            }
        } else {
            DDS_DataWriterListener native_listener =
                detail::create_native_listener(the_listener);
            DDS_ReturnCode_t retcode = DDS_DataWriter_set_listener(
                native_writer(), &native_listener, mask.to_ulong());
            rti::core::check_return_code(retcode, "failed to set listener");

            if (retain) {
                this->retain_for_listener();
            }
        }
    }

    Listener* listener_impl() const
    {
        DDS_DataWriterListener native_listener =
            DDS_DataWriter_get_listener((DDS_DataWriter *) native_writer());

        return static_cast<Listener *>(
            native_listener.as_listener.listener_data);
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    void set_listener_impl(
            std::shared_ptr<Listener> the_listener,
            const dds::core::status::StatusMask& mask)
    {
        listener_impl(the_listener.get(), mask, false);
        rti::core::detail::set_listener(listener_holder_, the_listener);
    }

    void set_listener_impl(std::shared_ptr<Listener> the_listener)
    {
        if (the_listener) {
            set_listener_impl(
                    the_listener,
                    dds::core::status::StatusMask::all());
        } else {
            set_listener_impl(nullptr, dds::core::status::StatusMask::none());
        }
    }

    std::shared_ptr<Listener> get_listener_impl() const
    {
        assert_not_closed();
        return rti::core::detail::get_listener<Listener>(listener_holder_);
    }
#endif

    // --- From Entity: -------------------------------------------------------
    void close()
    {
        // Close with force_close = true so that entities that were created
        // from C (such as those defined in XML) are deleted.
        close_impl(true);
    }

private:
    void close_impl(bool force_close)
    {
        if (!this->closed()) {
            reserved_data(NULL);

            if (!this->created_from_c() || force_close) {
                DDS_ReturnCode_t retcode = DDS_Publisher_delete_datawriter(
                    this->publisher()->native_publisher(), native_writer());
                rti::core::check_return_code(retcode, "Failed to close DataWriter");
            }

            publisher_ = dds::core::null;
            topic_ = dds::core::null;

            Entity::close();
        }
    }
    dds::pub::Publisher publisher_;
    dds::topic::Topic<T> topic_;
};

} } // namespace rti::pub

#endif // RTI_DDS_PUB_DATAWRITER_HPP_
