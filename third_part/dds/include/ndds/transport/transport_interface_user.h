/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)transport_interface_user.h    generated by: makeheader    Wed Mar  9 22:30:06 2022
 *
 *		built from:	interface_user.ifc
 */

#ifndef transport_interface_user_h
#define transport_interface_user_h



#ifndef transport_dll_h
#include "transport/transport_dll.h"
#endif

#ifndef transport_common_h
#include "transport/transport_common.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

struct NDDS_Transport_Property_t {
    /*e \dref_Transport_Property_t_classid
     */
    NDDS_Transport_ClassId_t classid;

    /*e \dref_Transport_Property_t_address_bit_count
    */
    RTI_INT32 address_bit_count;
        
    /*e \dref_Transport_Property_t_properties_bitmap
    */
    RTI_INT32 properties_bitmap;

    /*e \dref_Transport_Property_t_gather_send_buffer_count_max
    */
    RTI_INT32 gather_send_buffer_count_max;

    /*e \dref_Transport_Property_t_message_size_max
    */
    RTI_INT32 message_size_max;
    
    /*e \dref_Transport_Property_t_allow_interfaces_list
    */
    char** allow_interfaces_list;
        
    /*e \dref_Transport_Property_t_allow_interfaces_list_length
    */   
    RTI_INT32 allow_interfaces_list_length;

    /*e \dref_Transport_Property_t_deny_interfaces_list
    */  
    char** deny_interfaces_list;
        
    /*e \dref_Transport_Property_t_deny_interfaces_list_length
    */      
    RTI_INT32 deny_interfaces_list_length;
                    
    /*e \dref_Transport_Property_t_allow_multicast_interfaces_list
    */
    char** allow_multicast_interfaces_list;

    /*e \dref_Transport_Property_t_allow_multicast_interfaces_list_length
    */   
    RTI_INT32 allow_multicast_interfaces_list_length;

    /*e \dref_Transport_Property_t_deny_multicast_interfaces_list
    */ 
    char** deny_multicast_interfaces_list;
        
    /*e \dref_Transport_Property_t_deny_multicast_interfaces_list_length
    */    
    RTI_INT32 deny_multicast_interfaces_list_length;

    /*e \dref_Transport_Property_t_transport_uuid
     */
    struct NDDS_Transport_UUID transport_uuid;

    /*i \dref_Transport_Property_t_domain_participant_ptr
     */
    void* domain_participant_ptr;

    /*i \dref_Transport_Property_t_domain_participant_forwarder
     */
    const struct NDDS_Transport_Plugin_DomainParticipantForwarder
            *domain_participant_forwarder;

    /*e \dref_Transport_Property_t_thread_name_prefix
     */
    char *thread_name_prefix;
};


#define NDDS_TRANSPORT_THREAD_NAME_PREFIX_DEFAULT "rTr#####"

extern NDDS_Transport_DllExport 
RTIBool NDDS_Transport_Property_copy(
	struct NDDS_Transport_Property_t *dst,
        const struct NDDS_Transport_Property_t *src);

extern NDDS_Transport_DllExport 
void NDDS_Transport_Property_finalize(
	struct NDDS_Transport_Property_t *property);

extern NDDS_Transport_DllExport 
RTI_INT32 NDDS_Transport_Property_verify(
    const struct NDDS_Transport_Property_t *property_in);

extern NDDS_Transport_DllExport
const char ** NDDS_Transport_Property_get_common_properties(void);

extern NDDS_Transport_DllExport
RTIBool NDDS_Transport_parse_transport_class_id(
        const char *property_value,
        NDDS_Transport_ClassId_t *class_id);


#define NDDS_TRANSPORT_PROPERTY_BIT_POLLED (0x1)


#define NDDS_TRANSPORT_PROPERTY_BIT_BUFFER_ALWAYS_LOANED (0x2)


#define NDDS_TRANSPORT_PROPERTY_GATHER_SEND_BUFFER_COUNT_MIN (3)


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* transport_interface_user_h */
