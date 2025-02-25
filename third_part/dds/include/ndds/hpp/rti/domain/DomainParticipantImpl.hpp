/* $Id$

(c) Copyright, Real-Time Innovations, 2014-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


modification history
--------------------
1.0a,12feb13,acr Created
============================================================================= */

#ifndef RTI_DDS_DOMAIN_DOMAIN_PARTICIPANT_HPP_
#define RTI_DDS_DOMAIN_DOMAIN_PARTICIPANT_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/types.hpp>
#include <dds/core/Value.hpp>

#include <dds/core/ref_traits.hpp>
#include <dds/core/Time.hpp>
#include <dds/domain/qos/DomainParticipantQos.hpp>
#include <dds/domain/qos/DomainParticipantFactoryQos.hpp>
#include <dds/domain/DomainParticipantListener.hpp>
#include <dds/pub/qos/PublisherQos.hpp>
#include <dds/pub/qos/DataWriterQos.hpp>
#include <dds/sub/qos/SubscriberQos.hpp>
#include <dds/sub/qos/DataReaderQos.hpp>
#include <dds/topic/qos/TopicQos.hpp>
#include <rti/core/Entity.hpp>
#include <rti/topic/CustomFilter.hpp>
#include <rti/core/detail/ListenerHolder.hpp>

#include "ndds/ndds_c.h"

namespace rti { namespace domain {

namespace detail {

using namespace rti::core::detail;

OMG_DDS_API
std::pair<DDS_Entity*, bool> create_native_participant(
        uint32_t domain_id,
        const dds::domain::qos::DomainParticipantQos* qos = NULL,
        dds::domain::DomainParticipantListener* listener = NULL,
        const dds::core::status::StatusMask& mask =
                dds::core::status::StatusMask::all());
}

/** @RTI_class_definition NA */
class OMG_DDS_API DomainParticipantImpl : public rti::core::Entity
{
public:
    typedef dds::domain::DomainParticipantListener Listener;

    typedef dds::core::smart_ptr_traits<DomainParticipantImpl>::ref_type
        ref_type;
    typedef dds::core::smart_ptr_traits<DomainParticipantImpl>::weak_ref_type
        weak_ref_type;

    explicit DomainParticipantImpl(uint32_t the_domain_id)
            : rti::core::Entity(
                    detail::create_native_participant(the_domain_id),
                    detail::create_empty_listener_holder<Listener>())
    {
    }

    DomainParticipantImpl(
            uint32_t domain_id,
            const dds::domain::qos::DomainParticipantQos& qos,
            dds::domain::DomainParticipantListener* listener = NULL,
            const dds::core::status::StatusMask& mask =
                    dds::core::status::StatusMask::all())
            : rti::core::Entity(
                    detail::create_native_participant(
                            domain_id,
                            &qos,
                            listener,
                            mask),
                    detail::create_empty_listener_holder<Listener>())
    {
        if (listener != NULL) {
            retain_for_listener();
        }
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    DomainParticipantImpl(
            uint32_t domain_id,
            const dds::domain::qos::DomainParticipantQos& qos,
            std::shared_ptr<Listener> listener,
            const dds::core::status::StatusMask& mask)
            : rti::core::Entity(
                    detail::create_native_participant(
                            domain_id,
                            &qos,
                            listener.get(),
                            mask),
                    detail::create_listener_holder(listener))
    {
    }
#endif

    // For internal use
    DomainParticipantImpl(
            DDS_DomainParticipant* native_object)
            : Entity(
                    DDS_DomainParticipant_as_entity(native_object),
                    detail::create_empty_listener_holder<Listener>())
    {
    }

    ~DomainParticipantImpl();

    void listener_impl(
        Listener * the_listener,
        const ::dds::core::status::StatusMask& event_mask,
        bool retain = true);
    Listener* listener_impl() const;

#ifndef RTI_NO_CXX11_SMART_PTR
    void set_listener_impl(
            std::shared_ptr<Listener> the_listener,
            const dds::core::status::StatusMask& mask)
    {
        assert_not_closed();
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

    dds::domain::qos::DomainParticipantQos qos() const;
    void qos(const dds::domain::qos::DomainParticipantQos& the_qos);

    uint32_t domain_id() const;

    void assert_liveliness();

    bool contains_entity(const dds::core::InstanceHandle& handle);

    dds::core::Time current_time();

    static void participant_factory_qos(
        const dds::domain::qos::DomainParticipantFactoryQos& qos);

    static dds::domain::qos::DomainParticipantFactoryQos participant_factory_qos();

    static dds::domain::qos::DomainParticipantQos default_participant_qos();

    static void default_participant_qos(
        const dds::domain::qos::DomainParticipantQos& qos);

    dds::pub::qos::PublisherQos default_publisher_qos() const;

    DomainParticipantImpl& default_publisher_qos(
        const ::dds::pub::qos::PublisherQos& qos);

    dds::sub::qos::SubscriberQos default_subscriber_qos() const;
    DomainParticipantImpl& default_subscriber_qos(
        const ::dds::sub::qos::SubscriberQos& qos);

    dds::topic::qos::TopicQos default_topic_qos() const;

    DomainParticipantImpl& default_topic_qos(
        const dds::topic::qos::TopicQos& qos);

    // --- From Entity: -------------------------------------------------------

    // Document that calling close() is not thread-safe (undefined behavior) while
    //  accessing the participant. (thread-safety section)
    void close();

    // --- Extensions: --------------------------------------------------------

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Closes all the entities created from this DomainParticipant
     * @extension_member_note
     *
     * @note Calling this function explicitly is not necessary to close a
     * DomainParticipant.
     *
     * @dref_details_DomainParticipant_delete_contained_entities
     */
    void close_contained_entities();

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Get the current default dds::pub::qos::DataWriterQos.
     *
     * @extension_member_note
     *
     * @details The retrieved qos will match the set of values specified on the
     * last successful call to
     * default_datawriter_qos(const ::dds::pub::qos::DataWriterQos& qos),
     * or else, if the call was never made, the \ndds default values for the
     * dds::pub::qos::DataWriterQos.
     *
     * This method may potentially allocate memory depending on the sequences
     * contained in some QoS policies.
     *
     * If no DataWriterQos is specified when a dds::pub::DataWriter is constructed,
     * the default value of the QoS set in the factory, equivalent to the
     * value obtained by calling this method, will be used to create the
     * DataWriter.
     * @dref_Shared_get_default_datawriter_qos_mtsafety
     * @return The current default DataWriterQos
     */
    dds::pub::qos::DataWriterQos default_datawriter_qos() const;

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Set the default dds::pub::qos::DataWriterQos for this
     * DomainParticipant.
     *
     * @extension_member_note
     *
     * @details This set of default values will be used for a newly created
     * dds::pub::DataWriter if no dds::pub::qos::DataWriterQos is specified when
     * constructing the DataWriter.
     * @dref_Shared_set_default_datawriter_qos or creating a DataWriter with
     * default QoS values.
     *
     * @param qos The DataWriterQos to set.
     * @throw One of the standard @ref DDSException,
     * or dds::core::InconsistentPolicyError
     */
    void default_datawriter_qos(const ::dds::pub::qos::DataWriterQos& qos);

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Get the current default dds::sub::qos::DataReaderQos.
     *
     * @extension_member_note
     *
     * @details The retrieved qos will match the set of values specified on the
     * last successful call to
     * default_datareader_qos(const ::dds::sub::qos::DataReaderQos& qos),
     * or else, if the call was never made, the \ndds default values for the
     * dds::sub::qos::DataReaderQos.
     *
     * This method may potentially allocate memory depending on the sequences
     * contained in some QoS policies.
     *
     * If no DataReaderQos is specified when a dds::sub::DataReader is
     constructed,
     * the default value of the QoS set in the factory, equivalent to the
     * value obtained by calling this method, will be used to create the
     * DataReader.
     * @dref_Shared_get_default_datareader_qos_mtsafety
     * @return The current default DataReaderQos
     */
    dds::sub::qos::DataReaderQos default_datareader_qos() const;

    /**
     * @memberof dds::domain::DomainParticipant
     *
     * @brief @extension Set the default dds::sub::qos::DataReaderQos for this
     * DomainParticipant.
     *
     * @extension_member_note
     *
     * @details This set of default values will be used for a newly created
     * dds::sub::DataReader if no dds::sub::qos::DataReaderQos is specified when
     * constructing the DataReader.
     * @dref_Shared_set_default_datareader_qos or creating a DataReader with
     * default QoS values.
     *
     * @param qos The DataReaderQos to set.
     * @throw One of the standard @ref DDSException,
     * or dds::core::InconsistentPolicyError
     */
    void default_datareader_qos(const ::dds::sub::qos::DataReaderQos& qos);

    static void finalize_participant_factory();

    /**
     * @memberof dds::domain::DomainParticipant
     *
     * @brief @extension Register a content filter which can be used to create
     * a dds::topic::ContentFilteredTopic.
     *
     * @extension_member_note
     *
     * @dref_details_DomainParticipant_register_contentfilter
     *
     * @param custom_filter A custom filter
     * @param filter_name Name of the filter. The name must be unique within
     * the DomainParticipant and must not exceed 255 characters.
     * @throw One of the standard @ref DDSException
     *
     * @see \ref NDDSCustomFilterExampleModuleForCpp2
     */
    void register_contentfilter(
    	const rti::topic::CustomFilter<rti::topic::ContentFilterBase>& custom_filter,
    	const std::string& filter_name);

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Unregister a content filter previously registered with
     *  dds::domain::DomainParticipant::register_contentfilter(
     *  const rti::topic::CustomFilter<rti::topic::ContentFilterBase>&
     * custom_filter, const std::string& filter_name).
     *
     * @extension_member_note
     *
     * @details @dref_Shared_unregister_contentfilter
     * @param filter_name Name of the filter to unregister.
     * @throw One of the standard @ref DDSException,
     * or dds::core::PreconditionNotMetError
     */
    void unregister_contentfilter(const std::string &filter_name);

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Unregister a type that has previously been registered
     * to this dds::domain::DomainParticipant.
     *
     * @extension_member_note
     *
     * @param name The name of the type to unregister
     */
    void unregister_type(const std::string& name);

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Check if a type has previously been registered
     * to this dds::domain::DomainParticipant.
     *
     * @param name The name of the type to check
     *
     * @return bool true if it is registered, false otherwise
     */
    bool is_type_registered(const std::string& name) const;

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Attempt to contact one or more additional peer
     *      participants.
     *
     * @extension_member_note
     *
     * @details @dref_Shared_add_peer
     * @param peer_descr_string New peer descriptor to be added.
     * The format is specified in @ref NDDS_DISCOVERY_PEERS_format.
     * @throw One of the standard @ref DDSException
     */
    void add_peer(const std::string& peer_descr_string);

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Remove one or more peer participants from the
     * list of peers with which this \idref_DomainParticipant will try to
     * communicate.
     *
     * @extension_member_note
     *
     * @details @dref_Shared_remove_peer
     * @param peer_descr_string Peer descriptor to be removed. The format is
     * specified in @ref NDDS_DISCOVERY_PEERS_format.
     * @throw One of the standard @ref DDSException
     */
    void remove_peer(const std::string& peer_descr_string);

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief Retrieves the frequency used by the DNS tracker thread to query
     * the DNS service.
     *
     * @extension_member_note
     *
     * \dref_details_DomainParticipant_get_dns_tracker_polling_period
     */
    dds::core::Duration dns_tracker_polling_period() const;

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief Configures the frequency in which the DNS tracker queries the DNS
     * service.
     *
     * @extension_member_note
     *
     * \dref_details_DomainParticipant_set_dns_tracker_polling_period
     */
    void dns_tracker_polling_period(const dds::core::Duration& polling_period);

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Initiates endpoint discovery with the remote
     * dds::domain::DomainParticipant identified by its InstanceHandle.
     *
     * @extension_member_note
     *
     * \dref_details_DomainParticipant_resume_endpoint_discovery
     */
    void resume_endpoint_discovery(const dds::core::InstanceHandle& remote_participant_handle);

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Deletes an existing Durable Subscription on all
     * Persistence Services.
     *
     * @extension_member_note
     *
     * \dref_details_DomainParticipant_delete_durable_subscription
     */
    void delete_durable_subscription(const rti::core::EndpointGroup& group);

    /**
     * @memberof dds::domain::DomainParticipant
     * @brief @extension Registers a Durable Subscription on the specified
     * dds::topic::Topic on all Persistence Services.
     *
     * @extension_member_note
     *
     * \dref_details_DomainParticipant_register_durable_subscription
     */
    void register_durable_subscription(
        const rti::core::EndpointGroup& group,
        const std::string& topic_name);

    /**
     * @memberof dds::domain::DomainParticipant
     *
     * @brief @extension Get the protocol status for this participant
     *
     * @extension_member_note
     *
     * @details \dref_details_DomainParticipant_get_participant_protocol_status
     */
    rti::core::status::DomainParticipantProtocolStatus participant_protocol_status();

    // --- For internal use only: ---------------------------------------------

    DDS_DomainParticipant * native_participant()
    {
        return (DDS_DomainParticipant *) native_entity();
    }

    const DDS_DomainParticipant * native_participant() const
    {
        return (const DDS_DomainParticipant *) native_entity();
    }

    typedef dds::core::smart_ptr_traits<DDS_DynamicDataTypeSupport>::ref_type
        DynamicDataPluginPtr;

    void push_dynamic_data_plugin(DynamicDataPluginPtr type_support)
    {
        registered_dynamic_data_plugins_.push_back(type_support);
    }

private:
    // Check for and unretain any currently registered content filters
    void unregister_content_filters();

    typedef std::vector<DynamicDataPluginPtr> DynamicDataPluginVector;
    // This vector exists solely to ensure that all registered dynamic data
    // type plugins get deleted
    DynamicDataPluginVector registered_dynamic_data_plugins_;
/** RTI_remove_lines 1 */
};

} } // rti::domain namespace

#endif // RTI_DDS_DOMAIN_DOMAIN_PARTICIPANT_HPP_
