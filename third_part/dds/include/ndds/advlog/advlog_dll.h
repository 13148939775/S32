/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)advlog_dll.h    generated by: makeheader    Wed Mar  9 22:30:02 2022
 *
 *		built from:	dll.ifc
 */

#ifndef advlog_dll_h
#define advlog_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
  #if defined(RTI_advlog_DLL_EXPORT)
    #define ADVLOGDllExport __declspec( dllexport )
  #else
    #define ADVLOGDllExport
  #endif /* RTI_advlog_DLL_EXPORT */

  #if defined(RTI_advlog_DLL_VARIABLE) 
    #if defined(RTI_advlog_DLL_EXPORT)
      #define ADVLOGDllVariable __declspec( dllexport )
    #else
      #define ADVLOGDllVariable __declspec( dllimport )
    #endif /* RTI_advlog_DLL_EXPORT */
  #else 
    #define ADVLOGDllVariable
  #endif /* RTI_advlog_DLL_VARIABLE */
#else
  #define ADVLOGDllExport
  #define ADVLOGDllVariable
#endif /* RTI_WIN32 || RTI_WINCE || RTI_INTIME */


#endif /* advlog_dll_h */
