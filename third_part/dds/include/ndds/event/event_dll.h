/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)event_dll.h    generated by: makeheader    Wed Mar  9 22:30:04 2022
 *
 *		built from:	dll.ifc
 */

#ifndef event_dll_h
#define event_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
  #if defined(RTI_event_DLL_EXPORT)
    #define RTIEventDllExport __declspec( dllexport )
  #else
    #define RTIEventDllExport
  #endif /* RTI_event_DLL_EXPORT */

  #if defined(RTI_event_DLL_VARIABLE) 
    #if defined(RTI_event_DLL_EXPORT)
      #define RTIEventDllVariable __declspec( dllexport )
    #else
      #define RTIEventDllVariable __declspec( dllimport )
      #endif /* RTI_event_DLL_EXPORT */
  #else 
    #define RTIEventDllVariable
  #endif /* RTI_event_DLL_VARIABLE */
#else
  #define RTIEventDllExport
  #define RTIEventDllVariable
#endif /* RTI_WIN32 || RTI_WINCE || RTI_INTIME */


#endif /* event_dll_h */
