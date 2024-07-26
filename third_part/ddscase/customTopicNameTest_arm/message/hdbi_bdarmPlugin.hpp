

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from hdbi_bdarm.idl
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef hdbi_bdarmPlugin_1034191767_h
#define hdbi_bdarmPlugin_1034191767_h

#include "hdbi_bdarm.hpp"

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

#define HDBI_BdArm_Set_structPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define HDBI_BdArm_Set_structPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define HDBI_BdArm_Set_structPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define HDBI_BdArm_Set_structPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define HDBI_BdArm_Set_structPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern HDBI_BdArm_Set_struct*
HDBI_BdArm_Set_structPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern HDBI_BdArm_Set_struct*
HDBI_BdArm_Set_structPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern HDBI_BdArm_Set_struct*
HDBI_BdArm_Set_structPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
HDBI_BdArm_Set_structPluginSupport_copy_data(
    HDBI_BdArm_Set_struct *out,
    const HDBI_BdArm_Set_struct *in);

NDDSUSERDllExport extern void 
HDBI_BdArm_Set_structPluginSupport_destroy_data_w_params(
    HDBI_BdArm_Set_struct *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
HDBI_BdArm_Set_structPluginSupport_destroy_data_ex(
    HDBI_BdArm_Set_struct *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
HDBI_BdArm_Set_structPluginSupport_destroy_data(
    HDBI_BdArm_Set_struct *sample);

NDDSUSERDllExport extern void 
HDBI_BdArm_Set_structPluginSupport_print_data(
    const HDBI_BdArm_Set_struct *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
HDBI_BdArm_Set_structPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
HDBI_BdArm_Set_structPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
HDBI_BdArm_Set_structPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
HDBI_BdArm_Set_structPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
HDBI_BdArm_Set_structPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    HDBI_BdArm_Set_struct *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
HDBI_BdArm_Set_structPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    HDBI_BdArm_Set_struct *out,
    const HDBI_BdArm_Set_struct *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
HDBI_BdArm_Set_structPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const HDBI_BdArm_Set_struct *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
HDBI_BdArm_Set_structPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    HDBI_BdArm_Set_struct **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
HDBI_BdArm_Set_structPlugin_deserialize_from_cdr_buffer(
    HDBI_BdArm_Set_struct *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
HDBI_BdArm_Set_structPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
HDBI_BdArm_Set_structPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
HDBI_BdArm_Set_structPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
HDBI_BdArm_Set_structPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
HDBI_BdArm_Set_structPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    HDBI_BdArm_Set_struct ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
HDBI_BdArm_Set_structPlugin_new(void);

NDDSUSERDllExport extern void
HDBI_BdArm_Set_structPlugin_delete(struct PRESTypePlugin *);

#define HDBM_BdArm_Rsp_structPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define HDBM_BdArm_Rsp_structPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define HDBM_BdArm_Rsp_structPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define HDBM_BdArm_Rsp_structPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define HDBM_BdArm_Rsp_structPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern HDBM_BdArm_Rsp_struct*
HDBM_BdArm_Rsp_structPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern HDBM_BdArm_Rsp_struct*
HDBM_BdArm_Rsp_structPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern HDBM_BdArm_Rsp_struct*
HDBM_BdArm_Rsp_structPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
HDBM_BdArm_Rsp_structPluginSupport_copy_data(
    HDBM_BdArm_Rsp_struct *out,
    const HDBM_BdArm_Rsp_struct *in);

NDDSUSERDllExport extern void 
HDBM_BdArm_Rsp_structPluginSupport_destroy_data_w_params(
    HDBM_BdArm_Rsp_struct *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
HDBM_BdArm_Rsp_structPluginSupport_destroy_data_ex(
    HDBM_BdArm_Rsp_struct *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
HDBM_BdArm_Rsp_structPluginSupport_destroy_data(
    HDBM_BdArm_Rsp_struct *sample);

NDDSUSERDllExport extern void 
HDBM_BdArm_Rsp_structPluginSupport_print_data(
    const HDBM_BdArm_Rsp_struct *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
HDBM_BdArm_Rsp_structPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
HDBM_BdArm_Rsp_structPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
HDBM_BdArm_Rsp_structPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
HDBM_BdArm_Rsp_structPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
HDBM_BdArm_Rsp_structPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    HDBM_BdArm_Rsp_struct *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
HDBM_BdArm_Rsp_structPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    HDBM_BdArm_Rsp_struct *out,
    const HDBM_BdArm_Rsp_struct *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
HDBM_BdArm_Rsp_structPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const HDBM_BdArm_Rsp_struct *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
HDBM_BdArm_Rsp_structPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    HDBM_BdArm_Rsp_struct **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
HDBM_BdArm_Rsp_structPlugin_deserialize_from_cdr_buffer(
    HDBM_BdArm_Rsp_struct *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
HDBM_BdArm_Rsp_structPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
HDBM_BdArm_Rsp_structPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
HDBM_BdArm_Rsp_structPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
HDBM_BdArm_Rsp_structPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
HDBM_BdArm_Rsp_structPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    HDBM_BdArm_Rsp_struct ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
HDBM_BdArm_Rsp_structPlugin_new(void);

NDDSUSERDllExport extern void
HDBM_BdArm_Rsp_structPlugin_delete(struct PRESTypePlugin *);

#define HDBI_BdArm_Act_structPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define HDBI_BdArm_Act_structPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define HDBI_BdArm_Act_structPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define HDBI_BdArm_Act_structPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define HDBI_BdArm_Act_structPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern HDBI_BdArm_Act_struct*
HDBI_BdArm_Act_structPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern HDBI_BdArm_Act_struct*
HDBI_BdArm_Act_structPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern HDBI_BdArm_Act_struct*
HDBI_BdArm_Act_structPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
HDBI_BdArm_Act_structPluginSupport_copy_data(
    HDBI_BdArm_Act_struct *out,
    const HDBI_BdArm_Act_struct *in);

NDDSUSERDllExport extern void 
HDBI_BdArm_Act_structPluginSupport_destroy_data_w_params(
    HDBI_BdArm_Act_struct *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
HDBI_BdArm_Act_structPluginSupport_destroy_data_ex(
    HDBI_BdArm_Act_struct *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
HDBI_BdArm_Act_structPluginSupport_destroy_data(
    HDBI_BdArm_Act_struct *sample);

NDDSUSERDllExport extern void 
HDBI_BdArm_Act_structPluginSupport_print_data(
    const HDBI_BdArm_Act_struct *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
HDBI_BdArm_Act_structPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
HDBI_BdArm_Act_structPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
HDBI_BdArm_Act_structPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
HDBI_BdArm_Act_structPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
HDBI_BdArm_Act_structPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    HDBI_BdArm_Act_struct *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
HDBI_BdArm_Act_structPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    HDBI_BdArm_Act_struct *out,
    const HDBI_BdArm_Act_struct *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
HDBI_BdArm_Act_structPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const HDBI_BdArm_Act_struct *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
HDBI_BdArm_Act_structPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    HDBI_BdArm_Act_struct **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
HDBI_BdArm_Act_structPlugin_deserialize_from_cdr_buffer(
    HDBI_BdArm_Act_struct *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
HDBI_BdArm_Act_structPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
HDBI_BdArm_Act_structPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
HDBI_BdArm_Act_structPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
HDBI_BdArm_Act_structPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
HDBI_BdArm_Act_structPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    HDBI_BdArm_Act_struct ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
HDBI_BdArm_Act_structPlugin_new(void);

NDDSUSERDllExport extern void
HDBI_BdArm_Act_structPlugin_delete(struct PRESTypePlugin *);

#define HDBM_BdArm_St_structPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define HDBM_BdArm_St_structPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define HDBM_BdArm_St_structPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define HDBM_BdArm_St_structPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define HDBM_BdArm_St_structPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern HDBM_BdArm_St_struct*
HDBM_BdArm_St_structPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern HDBM_BdArm_St_struct*
HDBM_BdArm_St_structPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern HDBM_BdArm_St_struct*
HDBM_BdArm_St_structPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
HDBM_BdArm_St_structPluginSupport_copy_data(
    HDBM_BdArm_St_struct *out,
    const HDBM_BdArm_St_struct *in);

NDDSUSERDllExport extern void 
HDBM_BdArm_St_structPluginSupport_destroy_data_w_params(
    HDBM_BdArm_St_struct *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
HDBM_BdArm_St_structPluginSupport_destroy_data_ex(
    HDBM_BdArm_St_struct *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
HDBM_BdArm_St_structPluginSupport_destroy_data(
    HDBM_BdArm_St_struct *sample);

NDDSUSERDllExport extern void 
HDBM_BdArm_St_structPluginSupport_print_data(
    const HDBM_BdArm_St_struct *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
HDBM_BdArm_St_structPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
HDBM_BdArm_St_structPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
HDBM_BdArm_St_structPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
HDBM_BdArm_St_structPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
HDBM_BdArm_St_structPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    HDBM_BdArm_St_struct *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
HDBM_BdArm_St_structPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    HDBM_BdArm_St_struct *out,
    const HDBM_BdArm_St_struct *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
HDBM_BdArm_St_structPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const HDBM_BdArm_St_struct *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
HDBM_BdArm_St_structPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    HDBM_BdArm_St_struct **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
HDBM_BdArm_St_structPlugin_deserialize_from_cdr_buffer(
    HDBM_BdArm_St_struct *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
HDBM_BdArm_St_structPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
HDBM_BdArm_St_structPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
HDBM_BdArm_St_structPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
HDBM_BdArm_St_structPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
HDBM_BdArm_St_structPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    HDBM_BdArm_St_struct ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
HDBM_BdArm_St_structPlugin_new(void);

NDDSUSERDllExport extern void
HDBM_BdArm_St_structPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* hdbi_bdarmPlugin_1034191767_h */

