/* $Id$

(c) Copyright, Real-Time Innovations, 2013-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


modification history
--------------------
1.0a,15mar13,acr Created
===================================================================== */

#ifndef RTI_DDS_SUB_DATAREADER_HPP_
#define RTI_DDS_SUB_DATAREADER_HPP_

#include <string>
#include <algorithm> // for std::copy
#include <vector>
#include <utility> // for std::pair

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "ndds/ndds_c.h"
#include "dds_c/dds_c_publication_impl.h"
#include "dds_c/dds_c_subscription_impl.h"

#include <dds/sub/LoanedSamples.hpp>
#include <rti/core/Entity.hpp>
#include <dds/sub/Subscriber.hpp>
#include <dds/topic/ContentFilteredTopic.hpp>
#include <rti/sub/detail/DataReaderListenerForwarder.hpp>
#include <rti/topic/TopicImpl.hpp> // for builtin_topic()
#include <rti/topic/TopicTraits.hpp>
#include <dds/sub/SampleInfo.hpp>
#include <rti/sub/AckResponseData.hpp>
#include <rti/core/detail/ListenerHolder.hpp>

namespace rti { namespace sub {

template <typename T, typename Enable = void>
struct NativeDataConsistencyPolicy {
public:
    static bool is_data_consistent(
            DDS_DataReader *,
            const T*,
            const DDS_SampleInfo *)
    {
        return true;
    }

};

/**
 * @RTI_class_definition NA
 */
class OMG_DDS_API UntypedDataReader : public rti::core::Entity {
protected:
    UntypedDataReader(
        const std::pair<DDS_Entity*, bool>& reader_enable,
        rti::core::detail::ListenerHolderPtr listener_holder,
        size_t sample_size)
        : rti::core::Entity(reader_enable, listener_holder),
          sample_size_(sample_size)
    {
    }

public:
    DDS_DataReader * native_reader()
    {
        return (DDS_DataReader *) native_entity();
    }

    const DDS_DataReader * native_reader() const
    {
        return (const DDS_DataReader *) native_entity();
    }

public:
    // --- Qos management: ----------------------------------------------------

    const dds::sub::qos::DataReaderQos qos() const;
    void qos(const dds::sub::qos::DataReaderQos& the_qos);

    // --- Entity navigation: -------------------------------------------------

    virtual const dds::sub::Subscriber& subscriber() const = 0;
    virtual const std::string& topic_name() const = 0;
    virtual const std::string& type_name() const = 0;

    // --- Historical data: ---------------------------------------------------

    void wait_for_historical_data(const dds::core::Duration& timeout);

    // --- Status getters: ----------------------------------------------------

    dds::core::status::LivelinessChangedStatus liveliness_changed_status() const;

    dds::core::status::SampleRejectedStatus sample_rejected_status() const;

    dds::core::status::SampleLostStatus sample_lost_status() const;

    dds::core::status::RequestedDeadlineMissedStatus
    requested_deadline_missed_status();

    dds::core::status::RequestedIncompatibleQosStatus
    requested_incompatible_qos_status() const;

    dds::core::status::SubscriptionMatchedStatus
    subscription_matched_status() const;

    // Extension statuses
    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Get the DataReaderCacheStatus for this DataReader
     *
     * @extension_member_note
     *
     * @see rti::core::status::DataReaderCacheStatus
     */
    rti::core::status::DataReaderCacheStatus datareader_cache_status() const;

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Get the DataReaderProtocolStatus for this DataReader
     *
     * @extension_member_note
     *
     * @see rti::core::status::DataReaderProtocolStatus
     */
    rti::core::status::DataReaderProtocolStatus
    datareader_protocol_status() const;

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Get the DataReaderProtocolStatus for this DataReader
     *
     * @extension_member_note
     *
     * @see rti::core::status::DataReaderProtocolStatus
     */
    rti::core::status::DataReaderProtocolStatus
    matched_publication_datareader_protocol_status(
        const dds::core::InstanceHandle& publication_handle);

    // --- Application acknowledgments: ---------------------------------------

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Acknowledge all previously accessed samples
     *
     * @extension_member_note
     *
     * @details @dref_details_DataReader_acknowledge_all
     */
    void acknowledge_all();

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Acknowledge all previously accessed samples
     *
     * @extension_member_note
     *
     * @details @dref_details_DataReader_acknowledge_all_w_response
     */
    void acknowledge_all(const AckResponseData& response_data);

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Acknowledge a single sample explicitly
     *
     * @extension_member_note
     *
     * @details @dref_details_DataReader_acknowledge_sample
     */
    void acknowledge_sample(const dds::sub::SampleInfo& sample_info);

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Acknowledge a single sample explicitly
     *
     * @extension_member_note
     *
     * @details @dref_details_DataReader_acknowledge_sample_w_response
     */
    void acknowledge_sample(
        const dds::sub::SampleInfo& sample_info, 
        const AckResponseData& response_data);

    // --- Internal use: ------------------------------------------------------

    uint32_t read_or_take_untyped(
        void **& received_data,
        DDS_SampleInfoSeq& info_seq,
        const SelectorState& selector_state,
        bool take);

    void return_loan_untyped(
        void ** data,
        DDS_SampleInfoSeq& info_seq);

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Closes all the entities created from this DataReader
     *
     * @note Calling this function explicitly is not necessary to close a
     * DataReader.
     *
     * @dref_details_DataReader_delete_contained_entities
     */
    void  close_contained_entities();

protected:
    bool read_or_take_next_sample(
            void* sample,
            dds::sub::SampleInfo& sample_info,
            bool take);
    bool read_or_take_next_valid_sample(void* sample, bool take);

    // ------------------------------------------------------------------------
private:

    size_t sample_size_;
/** @RTI_remove_lines 1 */
};

namespace detail {

using namespace rti::core::detail;

OMG_DDS_API
std::pair<DDS_Entity*, bool> create_native_reader_untyped(
    const dds::sub::Subscriber& sub,
    const DDS_TopicDescription * topic,
    const dds::sub::qos::DataReaderQos * qos,
    DDS_DataReaderListener * listener,
    const dds::core::status::StatusMask& mask);

template <typename T>
std::pair<DDS_Entity*, bool> create_native_reader(
    const dds::sub::Subscriber& sub,
    const dds::topic::TopicDescription<T>& topic_description,
    const dds::sub::qos::DataReaderQos * qos = NULL,
    dds::sub::DataReaderListener<T>* listener = NULL,
    const dds::core::status::StatusMask& mask =
        dds::core::status::StatusMask::all())
{
    DDS_DataReaderListener native_listener;
    if (listener != NULL) {
        native_listener = create_native_listener<T>(listener);
    }

    return create_native_reader_untyped(
        sub,
        topic_description->native_topic_description(),
        qos,
        listener ? &native_listener : NULL,
        mask);
}

} // namespace detail


/**
 * @RTI_class_definition NA
 */
template <typename T>
class OMG_DDS_API DataReaderImpl : public UntypedDataReader {
public: 
    typedef rti::sub::Selector<T> Selector;
    typedef rti::sub::ManipulatorSelector<T> ManipulatorSelector;

public:
    typedef dds::sub::DataReaderListener<T> Listener;

    DataReaderImpl(
            const dds::sub::Subscriber& sub,
            const dds::topic::TopicDescription<T>& the_topic_description)
            : UntypedDataReader(
                    detail::create_native_reader(sub, the_topic_description),
                    detail::create_empty_listener_holder<Listener>(),
                    sizeof(T)),
              subscriber_(sub),
              topic_description_(the_topic_description)
    {
    }

    DataReaderImpl(
            const dds::sub::Subscriber& sub,
            const dds::topic::TopicDescription<T>& the_topic_description,
            const dds::sub::qos::DataReaderQos& the_qos,
            dds::sub::DataReaderListener<T>* the_listener = NULL,
            const dds::core::status::StatusMask& mask =
                    dds::core::status::StatusMask::all())
            : UntypedDataReader(
                    detail::create_native_reader(
                            sub,
                            the_topic_description,
                            &the_qos,
                            the_listener,
                            mask),
                    detail::create_empty_listener_holder<Listener>(),
                    sizeof(T)),
              subscriber_(sub),
              topic_description_(the_topic_description)
    {
        if (the_listener != NULL) {
            retain_for_listener();
        }
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    DataReaderImpl(
            const dds::sub::Subscriber& sub,
            const dds::topic::TopicDescription<T>& the_topic_description,
            const dds::sub::qos::DataReaderQos& the_qos,
            std::shared_ptr<Listener> the_listener,
            const dds::core::status::StatusMask& mask)
            : UntypedDataReader(
                    detail::create_native_reader(
                            sub,
                            the_topic_description,
                            &the_qos,
                            the_listener.get(),
                            mask),
                    detail::create_listener_holder(the_listener),
                    sizeof(T)),
              subscriber_(sub),
              topic_description_(the_topic_description)
    {
    }
#endif

    // For internal use
    DataReaderImpl(DDS_DataReader* the_native_reader)
            : UntypedDataReader(
                    std::make_pair(
                            DDS_DataReader_as_entity(the_native_reader),
                            false),
                    detail::create_empty_listener_holder<Listener>(),
                    sizeof(T)),
              subscriber_(dds::core::null),
              topic_description_(dds::core::null)
    {
        using rti::core::detail::create_from_native_entity;

        // Rebuild the C++ subscriber from the native one
        DDS_Subscriber * native_subscriber =
            DDS_DataReader_get_subscriber(the_native_reader);
        //RTI_ASSERT_PRECONDITION(native_subscriber != NULL);

        subscriber_ = create_from_native_entity<dds::sub::Subscriber>(
            native_subscriber);

        // Rebuild the C++ topic from the native one
        DDS_TopicDescription * native_topic_description =
            DDS_DataReader_get_topicdescription(the_native_reader);
        //RTI_ASSERT_PRECONDITION(native_topic != NULL);

        topic_description_ = rti::topic::create_topic_description_from_native<T>(
            native_topic_description);
    }

    ~DataReaderImpl()
    {
        try {
            // Close with force_close = false so that entities that were created
            // from C (such as those defined in XML) are not deleted. They are
            // only deleted if this object is explicitly closed (close()).
            close_impl(false);
        } catch (const std::exception& ex) {
            DDSLog_logWithFunctionName(
                    RTI_LOG_BIT_EXCEPTION,
                    "~DataReaderImpl()",
                    &RTI_LOG_ANY_FAILURE_s,
                    ex.what());
        }
    }

    const dds::sub::status::DataState& default_filter_state()
    {
        return default_selector_.get_selector_state().data_state;
    }

    void default_filter_state(const dds::sub::status::DataState& data_state)
    {
        default_selector_.state(data_state);
    }

    dds::sub::LoanedSamples<T> read_or_take(const SelectorState& selector_state, bool is_take)
    {
        DDS_SampleInfoSeq info_seq = DDS_SEQUENCE_INITIALIZER;
        void ** data_array_ptr = NULL;
        uint32_t count = read_or_take_untyped(
            data_array_ptr, 
            info_seq, selector_state, is_take);

        if (count == 0) {
            return LoanedSamples<T>(); // Empty collection
        }

        // Create a LoanedSamples object with a shared reference to this object
        // and the data/info sequences.
        //
        // The shared reference serves two purposes: retain this object (i.e.
        // avoid deleting it while the LoanedSamples object exists) and give
        // access to this->return_loan()
        //
        // TODO: try to get rid of the cast. Or move it to an rti namespace
        // so we can conditionally use boost or std for C++11
        return LoanedSamples<T>::create_from_loans(
            rtiboost::static_pointer_cast<DataReaderImpl<T> >(get_reference()),
            data_array_ptr,
            info_seq);
    }

    dds::sub::LoanedSamples<T> read()
    {
        return read_or_take(default_selector_.get_selector_state(), false);
    }

    dds::sub::LoanedSamples<T> take()
    {
        return read_or_take(default_selector_.get_selector_state(), true);
    }

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Copies the next not-previously-accessed valid data
     * value from the DataReader via a read operation.
     *
     * @extension_member_note
     *
     * This function ignores SampleInfo and therefore also skips samples with
     * invalid data.
     *
     * @param sample The sample where to copy the values of the next unread
     * sample if the function returned true, or undefinded values otherwise.
     *
     * @return True if there was an unread sample
     *
     * @see read(T& sample, dds::sub::SampleInfo& sample_info)
     */
    bool read(T& sample)
    {
        OMG_DDS_STATIC_ASSERT(
            !rti::topic::topic_type_disabled_copy<T>::value,
            "type T cannot be copied--use LoanedSamples");

        return read_or_take_next_valid_sample(&sample, false);
    }

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Copies the next not-previously-accessed data value
     * from the DataReader via a read operation.
     *
     * @extension_member_note
     *
     * @return True if there was an unread sample
     *
     * \dref_details_FooDataReader_read_next_sample
     */
    bool read(T& sample, dds::sub::SampleInfo& sample_info)
    {
        OMG_DDS_STATIC_ASSERT(
            !rti::topic::topic_type_disabled_copy<T>::value,
            "type T cannot be copied--use LoanedSamples");

        return read_or_take_next_sample(&sample, sample_info, false);
    }

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Copies the next not-previously-accessed valid data
     * value from the DataReader via a take operation.
     *
     * @extension_member_note
     *
     * This function ignores SampleInfo and therefore also skips samples with
     * invalid data.
     *
     * @param sample The sample where to copy the values of the next unread
     * sample if the function returned true, or undefinded values otherwise.
     *
     * @return True if there was an unread sample to take. When this returns
     * false, the argument is not modified.
     *
     * Example:
     *
     * \code
     * Foo sample;
     * bool read_new_sample = reader.extensions().take(sample);
     * \endcode
     *
     * @see take(T& sample, dds::sub::SampleInfo& sample_info)
     *
     */
    bool take(T& sample)
    {
        OMG_DDS_STATIC_ASSERT(
            !rti::topic::topic_type_disabled_copy<T>::value,
            "type T cannot be copied--use LoanedSamples");

        return read_or_take_next_valid_sample(&sample, true);
    }

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Copies the next not-previously-accessed data value
     * from the DataReader via a take operation.
     *
     * @extension_member_note
     *
     * \dref_details_FooDataReader_take_next_sample
     */
    bool take(T& sample, dds::sub::SampleInfo& sample_info)
    {
        OMG_DDS_STATIC_ASSERT(
            !rti::topic::topic_type_disabled_copy<T>::value,
            "type T cannot be copied--use LoanedSamples");

        return read_or_take_next_sample(&sample, sample_info, true);
    }

    // Copying read/take operations 

    template<typename SamplesIterator>
    uint32_t read_or_take(
       SamplesIterator& sit, const SelectorState& selector_state, bool is_take)
    {
        // When type T contains IDL pointers, read/take operations that copy
        // samples (as opposed to returning a LoanedSamples collection) are
        // disabled.
        OMG_DDS_STATIC_ASSERT(
            !rti::topic::topic_type_disabled_copy<T>::value,
            "type T cannot be copied--use LoanedSamples");

        LoanedSamples<T> loaned_samples =
            read_or_take(selector_state,is_take);

        // Take the returned loaned samples and convert to Samples, placing
        // each sample into the container pointed to by the iterator
        unsigned int length = loaned_samples.length();
        std::transform(
            loaned_samples.begin(), loaned_samples.end(),
            sit,
            rti::sub::copy_to_sample<T>);

        return length;
    }

    // --- Back-Inserting Iterators: --- //
    template<typename SamplesBIIterator>
    uint32_t read(SamplesBIIterator sbit)
    {
        return read_or_take(
           sbit, default_selector_.get_selector_state(), false);
    }

    template<typename SamplesBIIterator>
    uint32_t take(SamplesBIIterator sbit)
    {
        return read_or_take(
           sbit, default_selector_.get_selector_state(), true);
    }

    template<typename SamplesFWIterator>
    uint32_t read(SamplesFWIterator sfit, int32_t max_samples)
    {
        // In case the read_or_take fails, the default_selector_
        // won't be affected
        DefaultSelector<T> tmp_selector(default_selector_);

        tmp_selector.max_samples(max_samples);
        return read_or_take(sfit, tmp_selector.get_selector_state(), false);
    }

    template<typename SamplesFWIterator>
    uint32_t take(SamplesFWIterator sfit, int32_t max_samples)
    {
        // In case the read_or_take fails, the default_selector_
        // won't be affected
        DefaultSelector<T> tmp_selector(default_selector_);

        tmp_selector.max_samples(max_samples);
        return read_or_take(sfit, tmp_selector.get_selector_state(), true);
    }
    // --- Instance management: -----------------------------------------------

    dds::topic::TopicInstance<T>& key_value(
        dds::topic::TopicInstance<T>& topic_instance,
        const dds::core::InstanceHandle& handle)
    {
        DDS_ReturnCode_t retcode = DDS_DataReader_get_key_value_untypedI(
            native_reader(), (void *) &topic_instance.sample(), &handle->native());
        rti::core::check_return_code(retcode, "get key value");

        topic_instance.handle(handle);

        return topic_instance;
    }

    T& key_value(T& key_holder, const dds::core::InstanceHandle& handle)
    {
        DDS_ReturnCode_t retcode = DDS_DataReader_get_key_value_untypedI(
            native_reader(), (void *) &key_holder, &handle->native());
        rti::core::check_return_code(retcode, "get key value");

        return key_holder;
    }

    dds::core::InstanceHandle lookup_instance(const T& key_holder)
    {
        return dds::core::InstanceHandle(
                DDS_DataReader_lookup_instance_untypedI(
                        const_cast<DDS_DataReader*>(
                                native_reader()),
                                (void *) &key_holder));
    }

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Checks if the sample has been overwritten by the
     * DataWriter
     *
     * @extension_member_note
     *
     * @param sample Sample to be validated
     * @param sample_info \idref_SampleInfo object received with the sample
     *
     * @see  \idref_FooDataReader_is_data_consistent
     */
    bool is_data_consistent(const T& sample, const dds::sub::SampleInfo& sample_info)
    {
        return NativeDataConsistencyPolicy<T>::is_data_consistent(
                native_reader(),
                &sample,
                &sample_info->native());
    }

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Checks if the sample has been overwritten by the
     * DataWriter
     *
     * @extension_member_note
     *
     * @details \dref_details_FooDataReader_is_data_consistent
     */
    bool is_data_consistent(const rti::sub::LoanedSample<T>& sample)
    {
        return NativeDataConsistencyPolicy<T>::is_data_consistent(
                native_reader(),
                &sample->data(),
                &sample->info()->native());
    }
    // --- Entity navigation: -------------------------------------------------

    const dds::topic::TopicDescription<T>& topic_description() const
    {
        return topic_description_;
    }

    dds::topic::TopicDescription<T>& topic_description()
    {
        return topic_description_;
    }

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Get the topic name associated with this DataReader
     *
     * @extension_member_note
     *
     */
    const std::string& topic_name() const
    {
        return topic_description().name();
    }

    /**
     * @memberof dds::sub::DataReader
     * @brief @extension Get the type name associated with this DataReader
     *
     * @extension_member_note
     *
     */
    const std::string& type_name() const
    {
        return topic_description().type_name();
    }

    const dds::sub::Subscriber& subscriber() const
    {
        return subscriber_;
    }

    dds::sub::Subscriber& subscriber()
    {
        return subscriber_;
    }

    // --- Listeners: ---------------------------------------------------------

    void listener_impl(
        Listener * the_listener,
        const dds::core::status::StatusMask& mask,
        bool retain = true)
    {
        assert_legal_listener_setter_call(retain);
        if (the_listener == NULL) {
            DDS_DataReader_set_listener(
                native_reader(), NULL, DDS_STATUS_MASK_NONE);
            if (retain) {
                this->unretain_for_listener();
            }
        } else {
            DDS_DataReaderListener native_listener =
                detail::create_native_listener(the_listener);
            DDS_ReturnCode_t retcode = DDS_DataReader_set_listener(
                native_reader(), &native_listener, mask.to_ulong());
            rti::core::check_return_code(retcode, "failed to set listener");
            if (retain) {
                this->retain_for_listener();
            }
        }
    }

    Listener * listener_impl() const
    {
        DDS_DataReaderListener native_listener =
            DDS_DataReader_get_listener((DDS_DataReader *) native_reader());

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
            set_listener_impl(the_listener, dds::core::status::StatusMask::all());
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

    // --- Status getters: ----------------------------------------------------

public:
    // --- From Entity: -------------------------------------------------------

    /** 
     * @memberof dds::sub::DataReader
     * @brief Close this DataReader
     */
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
            close_contained_entities();
            reserved_data(NULL);

            // Don't delete the builtin datareaders, the participant will take
            // care of that. Only close natively created entities if 
            // force_close is true.
            if (!rti::topic::is_builtin_topic(topic_name()) && 
                (!this->created_from_c() || force_close)) {
                DDS_ReturnCode_t retcode = DDS_Subscriber_delete_datareader(
                        this->subscriber()->native_subscriber(), 
                        native_reader());

                rti::core::check_return_code(retcode, "Failed to close DataReader");
            }

            subscriber_ = dds::core::null;
            topic_description_ = dds::core::null;

            Entity::close();
        }
    }

    dds::sub::Subscriber subscriber_;
    dds::topic::TopicDescription<T> topic_description_;
    rti::sub::DefaultSelector<T> default_selector_;
    /** @RTI_remove_lines 1 */
};

} } // namespace rti::sub

#endif // RTI_DDS_SUB_DATAREADER_HPP_
