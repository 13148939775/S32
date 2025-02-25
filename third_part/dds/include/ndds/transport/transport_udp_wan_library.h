/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)transport_udp_wan_library.h    generated by: makeheader    Wed Mar  9 22:30:07 2022
 *
 *		built from:	udp_wan_library.ifc
 */

#ifndef transport_udp_wan_library_h
#define transport_udp_wan_library_h


#define RTI_ENABLEWAN_LIB_NAME "nddsrwt"
#define NDDS_TRANSPORT_UDP_WAN_LIBRARY_IS_PLUGIN_ENABLED_FUNCTION_NAME \
    "NDDS_Transport_UDP_WAN_Library_is_plugin_enabled"
#define NDDS_TRANSPORT_UDP_WAN_LIBRARY_SET_PLUGIN_ENABLED_FUNCTION_NAME \
    "NDDS_Transport_UDP_WAN_Library_set_plugin_enabled"

#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
    #define Ndds_Transport_Udp_Wan_Library_DllExport __declspec(dllexport)
#else
    #define Ndds_Transport_Udp_Wan_Library_DllExport
#endif /* RTI_WIN32 || RTI_WINCE || RTI_INTIME */

#ifndef RTI_EXCLUDE_BB_RWT
#define NDDS_TRANSPORT_UDP_WAN_ENABLE_WAN_TRANSPORT_VALUE 362833236
#endif

#ifdef __cplusplus
    extern "C" {
#endif

extern Ndds_Transport_Udp_Wan_Library_DllExport
unsigned int NDDS_Transport_UDP_WAN_Library_is_plugin_enabled(void);

extern Ndds_Transport_Udp_Wan_Library_DllExport
void NDDS_Transport_UDP_WAN_Library_set_plugin_enabled(
        unsigned int newEnableValue);

typedef unsigned int (
        *NDDS_Transport_UDP_WAN_Library_Is_Plugin_Enabled_Function)(void);


typedef void (*NDDS_Transport_UDP_WAN_Library_Set_Plugin_Enabled_Function)(
        unsigned int newVal);


#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* transport_udp_wan_library_h */
