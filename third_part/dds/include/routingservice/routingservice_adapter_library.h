/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)routingservice_adapter_library.h    generated by: makeheader    Wed Mar  9 22:43:15 2022
 *
 *		built from:	adapter_library.ifc
 */

#ifndef routingservice_adapter_library_h
#define routingservice_adapter_library_h


  #ifndef router_dll_h
    #include "routingservice/routingservice_dll.h"
  #endif
  #ifndef router_adapter_h
    #include "routingservice/routingservice_adapter.h"
  #endif
  #ifndef router_adapter_new_h
    #include "routingservice/routingservice_adapter_new.h"
  #endif
  #ifdef __cplusplus
      extern "C" {
  #endif

extern ROUTERDllExport
struct RTI_RoutingServiceAdapterPlugin * ROUTERC37118Adapter_create(
    const struct RTI_RoutingServiceProperties * properties,
    RTI_RoutingServiceEnvironment * env);

extern ROUTERDllExport
struct RTI_RoutingServiceAdapterPlugin * ROUTERTimerAdapter_create(
    const struct RTI_RoutingServiceProperties * properties,
    RTI_RoutingServiceEnvironment * env);

extern ROUTERDllExport
struct RTI_RoutingServiceAdapterPlugin * ROUTERPollingAdapter_create(
    const struct RTI_RoutingServiceProperties * properties,
    RTI_RoutingServiceEnvironment * env);

extern ROUTERDllExport
struct RTI_RoutingServiceAdapterPluginExt * ROUTERTestAdapter_create(
    const struct RTI_RoutingServiceProperties * properties,
    RTI_RoutingServiceEnvironment * env);


  #ifdef __cplusplus
    }	/* extern "C" */
  #endif

#endif /* routingservice_adapter_library_h */
