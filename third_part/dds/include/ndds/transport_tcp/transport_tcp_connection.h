/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)transport_tcp_connection.h    generated by: makeheader    Wed Mar  9 22:42:55 2022
 *
 *		built from:	connection.ifc
 */

#ifndef transport_tcp_connection_h
#define transport_tcp_connection_h


  #ifndef dds_c_infrastructure_impl_h
    #include "dds_c/dds_c_infrastructure_impl.h"
  #endif
  #ifndef transport_tcp_dll_h
    #include "transport_tcp/transport_tcp_dll.h"
  #endif
/*  #ifndef transport_endpoint_h
    #include "transport/transport_endpoint.h"
  #endif*/
  #ifndef rtitls_endpoint_h
    #include "rtitls/rtitls_endpoint.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct NDDS_Transport_TCP_ConnectionEndpointFactoryPropertyTCPv4 {
    struct NDDS_Transport_ConnectionEndpointFactoryProperty parent;

    /*e The size of the send buffers for the TCP sockets that are 
     *  used for control AND data communication.
     *
     *  \default NDDS_Transport_TCPv4_Plugin#NDDS_TRANSPORT_TCPV4_SOCKET_BUFFER_SIZE_OS_DEFAULT
     */
    RTI_INT32 send_socket_buffer_size;


    /*e The size of the receive buffers for the TCP sockets used for control
     *  AND data communication.
     *
     *  \default NDDS_Transport_TCPv4_Plugin#NDDS_TRANSPORT_TCPV4_SOCKET_BUFFER_SIZE_OS_DEFAULT
     */
    RTI_INT32 recv_socket_buffer_size;


    /*e
     * If different than -1, assigns it to the socket option TCP_MAXSEG.
     *
     * \default -1 (use system's socket default)
     */
    RTI_INT32 max_packet_size;

    /*e 
     * Enable keep alive. If this is set to a value different than 0, the parameters
     * \ref keep_alive_time, \ref keep_alive_interval, \ref keep_alive_retry_count
     * will be used to configure the keep alive feature of the created socket.
     *
     * NOTE: This parameter is not supported on all the architectures. You will
     *       see a warning message if keep alive is enabled on a non-supported
     *       architecture.
     *
     * Currently this feature is supported only on Linux.
     *
     * On Windows, you can modify those settings (at system's level) through
     * the system's registry at:
     * \code
     * \HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Tcpip\Parameters.
     * \endcode
     * See MSDN or Windows documentation for more information.
     *
     * \default 0 (disabled)
     */
    RTI_INT32 enable_keep_alive;

    /*e
     * Keep alive time in seconds of inactivity.
     *
     * Valid only if \ref enable_keep_alive is set to 1.
     * 
     * \default -1 (use system's default).
     */
    RTI_INT32 keep_alive_time;

    /*e
     * Keep alive interval in seconds.
     *
     * Valid only if \ref enable_keep_alive is set to 1.
     * 
     * \default -1 (use system's default).
     */
    RTI_INT32 keep_alive_interval;


    /*e
     * Keep alive retry count. 
     *
     * Valid only if \ref enable_keep_alive is set to 1.
     * 
     * \default -1 (use system's default).
     */
    RTI_INT32 keep_alive_retry_count;

    /*e
     * Changes the default OS TCP User Timeout configuration. If set to a value
     * greater than 0, it represents the TCP User Timeout in seconds.
     *
     * Currently this feature is supported only on Linux 2.6.37 and above.
     *
     * \default 0 (use system's default).
     */
    RTI_INT32 user_timeout;

    /*e 
     * Disable Nagle algorithm for TCP communication.
     *
     * \default 0 (disabled)
     */
    RTI_INT32 disable_nagle;
    

    /*e
         This is used in conjunction with
         \ref transport_priority_mapping_low and \ref transport_priority_mapping_high
         to define the mapping from DDS transport priority (see
         \ref DDSTransportPriorityQosModule) to the
         IPv4 TOS field.  Defines a contiguous region of bits in the
         32-bit transport priority value that is used
         to generate values for the IPv4 TOS field on an outgoing
         socket.

         For example, the value 0x0000ff00 causes bits 9-16
         (8 bits) to be used in the mapping.  The value will be
         scaled from the mask range (0x0000 - 0xff00 in this case) to
         the range specified by low and high.

         If the mask is set to zero, then the transport will not
         set IPv4 TOS for send sockets.
    */

    RTI_INT32 transport_priority_mask;

    /*e
        This is used in conjunction with
        \ref transport_priority_mask and \ref transport_priority_mapping_high
        to define the mapping from DDS transport priority to the
        IPv4 TOS field.  Defines the low value of the
        output range for scaling.

        Note that IPv4 TOS is generally an 8-bit value.

        \see transport_priority_mask 

        \default 0.
     */ 
    RTI_INT32 transport_priority_mapping_low;

    /*e
        This is used in conjunction with
        \ref transport_priority_mask and \ref transport_priority_mapping_high
        to define the mapping from DDS transport priority to the
        IPv4 TOS field.  Defines the high value of the
        output range for scaling.

        Note that IPv4 TOS is generally an 8-bit value.

        \see transport_priority_mask

        \default 0.
     */ 
    RTI_INT32 transport_priority_mapping_high;

    
    /*e 
     * This is used to select between synchronous or asynchronous accept.
     * Currently this is set to one only when using Windows IOCP.
     *
     * \default 0
     */
    RTIBool use_asynchronous_accept;


};


#define NDDS_TRANSPORT_TCP_CONNECTION_ENDPOINT_FACTORY_PROPERTY_TCPV4_DEFAULT { \
    { NDDS_TRANSPORT_CONNECTION_ENDPOINT_KIND_TCPv4 }, /* parent.kind */ \
    -1, /* send_socket_buffer_size */ \
    -1, /* recv_socket_buffer_size */ \
    -1, /* max_packet_size */ \
     0, /* enable_keep_alive */ \
    -1, /* keep_alive_time */ \
    -1, /* keep_alive_interval */ \
    -1, /* keep_alive_retry_count */ \
     0, /* user_timeout */ \
     0, /* disable_nagle */ \
     0, /* transport_priority_mask */ \
     0, /* transport_priority_mapping_low */ \
     0, /* transport_priority_mapping_high */ \
     0  /* use_asynchronous_accept */ \
}

extern NDDS_Transport_TCP_DllExport 
RTI_UINT32 NDDS_Transport_TCP_ConnectionEndpointFactoryPropertyTCPv4_parseDDSProperties(
    struct NDDS_Transport_TCP_ConnectionEndpointFactoryPropertyTCPv4 *factory_property,
    const struct DDS_PropertyQosPolicy *property_in);

extern NDDS_Transport_TCP_DllExport 
struct NDDS_Transport_ConnectionEndpointFactory *
NDDS_Transport_TCP_ConnectionEndpointFactoryTCPv4_create(
    struct NDDS_Transport_TCP_ConnectionEndpointFactoryPropertyTCPv4 *factory_property);

extern NDDS_Transport_TCP_DllExport 
void NDDS_Transport_TCP_ConnectionEndpointFactoryTCPv4_delete(
    struct NDDS_Transport_ConnectionEndpointFactory *);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* transport_tcp_connection_h */
