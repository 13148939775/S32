/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)transport_dll.h    generated by: makeheader    Wed Mar  9 22:30:06 2022
 *
 *		built from:	dll.ifc
 */

#ifndef transport_dll_h
#define transport_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
  #if defined(RTI_transport_DLL_EXPORT)
    #define NDDS_Transport_DllExport __declspec( dllexport )
  #else
    #define NDDS_Transport_DllExport
  #endif /* NDDS_transport_DLL_EXPORT */

  #if defined(RTI_transport_DLL_VARIABLE) 
    #if defined(RTI_transport_DLL_EXPORT)
      #define NDDS_Transport_DllVariable __declspec( dllexport )
    #else
      #define NDDS_Transport_DllVariable __declspec( dllimport )
    #endif /* NDDS_transport_DLL_EXPORT */
  #else 
    #define NDDS_Transport_DllVariable
    #endif /* NDDS_transport_DLL_VARIABLE */
#else
  #define NDDS_Transport_DllExport
  #define NDDS_Transport_DllVariable
#endif /* RTI_WIN32 || RTI_WINCE || RTI_INTIME */

#endif /* transport_dll_h */
