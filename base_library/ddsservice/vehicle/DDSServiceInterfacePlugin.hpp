

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DDSServiceInterface.idl
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef DDSServiceInterfacePlugin_716994028_h
#define DDSServiceInterfacePlugin_716994028_h

#include "DDSServiceInterface.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define DDSCommandSet_structPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define DDSCommandSet_structPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DDSCommandSet_structPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DDSCommandSet_structPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DDSCommandSet_structPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DDSCommandSet_struct*
DDSCommandSet_structPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DDSCommandSet_struct*
DDSCommandSet_structPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DDSCommandSet_struct*
DDSCommandSet_structPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DDSCommandSet_structPluginSupport_copy_data(
    DDSCommandSet_struct *out,
    const DDSCommandSet_struct *in);

NDDSUSERDllExport extern void 
DDSCommandSet_structPluginSupport_destroy_data_w_params(
    DDSCommandSet_struct *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DDSCommandSet_structPluginSupport_destroy_data_ex(
    DDSCommandSet_struct *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DDSCommandSet_structPluginSupport_destroy_data(
    DDSCommandSet_struct *sample);

NDDSUSERDllExport extern void 
DDSCommandSet_structPluginSupport_print_data(
    const DDSCommandSet_struct *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DDSCommandSet_structPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DDSCommandSet_structPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DDSCommandSet_structPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DDSCommandSet_structPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DDSCommandSet_structPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandSet_struct *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DDSCommandSet_structPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandSet_struct *out,
    const DDSCommandSet_struct *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
DDSCommandSet_structPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DDSCommandSet_struct *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
DDSCommandSet_structPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandSet_struct **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DDSCommandSet_structPlugin_deserialize_from_cdr_buffer(
    DDSCommandSet_struct *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
DDSCommandSet_structPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DDSCommandSet_structPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DDSCommandSet_structPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DDSCommandSet_structPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DDSCommandSet_structPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandSet_struct ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DDSCommandSet_structPlugin_new(void);

NDDSUSERDllExport extern void
DDSCommandSet_structPlugin_delete(struct PRESTypePlugin *);

#define DDSCommandRsp_structPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define DDSCommandRsp_structPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DDSCommandRsp_structPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DDSCommandRsp_structPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DDSCommandRsp_structPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DDSCommandRsp_struct*
DDSCommandRsp_structPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DDSCommandRsp_struct*
DDSCommandRsp_structPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DDSCommandRsp_struct*
DDSCommandRsp_structPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DDSCommandRsp_structPluginSupport_copy_data(
    DDSCommandRsp_struct *out,
    const DDSCommandRsp_struct *in);

NDDSUSERDllExport extern void 
DDSCommandRsp_structPluginSupport_destroy_data_w_params(
    DDSCommandRsp_struct *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DDSCommandRsp_structPluginSupport_destroy_data_ex(
    DDSCommandRsp_struct *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DDSCommandRsp_structPluginSupport_destroy_data(
    DDSCommandRsp_struct *sample);

NDDSUSERDllExport extern void 
DDSCommandRsp_structPluginSupport_print_data(
    const DDSCommandRsp_struct *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DDSCommandRsp_structPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DDSCommandRsp_structPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DDSCommandRsp_structPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DDSCommandRsp_structPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DDSCommandRsp_structPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandRsp_struct *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DDSCommandRsp_structPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandRsp_struct *out,
    const DDSCommandRsp_struct *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
DDSCommandRsp_structPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DDSCommandRsp_struct *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
DDSCommandRsp_structPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandRsp_struct **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DDSCommandRsp_structPlugin_deserialize_from_cdr_buffer(
    DDSCommandRsp_struct *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
DDSCommandRsp_structPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DDSCommandRsp_structPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DDSCommandRsp_structPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DDSCommandRsp_structPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DDSCommandRsp_structPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandRsp_struct ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DDSCommandRsp_structPlugin_new(void);

NDDSUSERDllExport extern void
DDSCommandRsp_structPlugin_delete(struct PRESTypePlugin *);

#define DDSCommandAct_structPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define DDSCommandAct_structPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DDSCommandAct_structPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DDSCommandAct_structPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DDSCommandAct_structPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DDSCommandAct_struct*
DDSCommandAct_structPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DDSCommandAct_struct*
DDSCommandAct_structPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DDSCommandAct_struct*
DDSCommandAct_structPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DDSCommandAct_structPluginSupport_copy_data(
    DDSCommandAct_struct *out,
    const DDSCommandAct_struct *in);

NDDSUSERDllExport extern void 
DDSCommandAct_structPluginSupport_destroy_data_w_params(
    DDSCommandAct_struct *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DDSCommandAct_structPluginSupport_destroy_data_ex(
    DDSCommandAct_struct *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DDSCommandAct_structPluginSupport_destroy_data(
    DDSCommandAct_struct *sample);

NDDSUSERDllExport extern void 
DDSCommandAct_structPluginSupport_print_data(
    const DDSCommandAct_struct *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DDSCommandAct_structPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DDSCommandAct_structPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DDSCommandAct_structPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DDSCommandAct_structPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DDSCommandAct_structPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandAct_struct *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DDSCommandAct_structPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandAct_struct *out,
    const DDSCommandAct_struct *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
DDSCommandAct_structPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DDSCommandAct_struct *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
DDSCommandAct_structPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandAct_struct **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DDSCommandAct_structPlugin_deserialize_from_cdr_buffer(
    DDSCommandAct_struct *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
DDSCommandAct_structPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DDSCommandAct_structPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DDSCommandAct_structPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DDSCommandAct_structPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DDSCommandAct_structPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandAct_struct ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DDSCommandAct_structPlugin_new(void);

NDDSUSERDllExport extern void
DDSCommandAct_structPlugin_delete(struct PRESTypePlugin *);

#define DDSCommandSt_structPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define DDSCommandSt_structPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DDSCommandSt_structPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DDSCommandSt_structPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DDSCommandSt_structPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DDSCommandSt_struct*
DDSCommandSt_structPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DDSCommandSt_struct*
DDSCommandSt_structPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DDSCommandSt_struct*
DDSCommandSt_structPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DDSCommandSt_structPluginSupport_copy_data(
    DDSCommandSt_struct *out,
    const DDSCommandSt_struct *in);

NDDSUSERDllExport extern void 
DDSCommandSt_structPluginSupport_destroy_data_w_params(
    DDSCommandSt_struct *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DDSCommandSt_structPluginSupport_destroy_data_ex(
    DDSCommandSt_struct *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DDSCommandSt_structPluginSupport_destroy_data(
    DDSCommandSt_struct *sample);

NDDSUSERDllExport extern void 
DDSCommandSt_structPluginSupport_print_data(
    const DDSCommandSt_struct *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DDSCommandSt_structPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DDSCommandSt_structPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DDSCommandSt_structPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DDSCommandSt_structPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DDSCommandSt_structPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandSt_struct *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DDSCommandSt_structPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandSt_struct *out,
    const DDSCommandSt_struct *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
DDSCommandSt_structPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DDSCommandSt_struct *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
DDSCommandSt_structPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandSt_struct **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DDSCommandSt_structPlugin_deserialize_from_cdr_buffer(
    DDSCommandSt_struct *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
DDSCommandSt_structPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DDSCommandSt_structPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DDSCommandSt_structPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DDSCommandSt_structPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DDSCommandSt_structPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DDSCommandSt_struct ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DDSCommandSt_structPlugin_new(void);

NDDSUSERDllExport extern void
DDSCommandSt_structPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* DDSServiceInterfacePlugin_716994028_h */

