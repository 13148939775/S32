/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)writer_history_dll.h    generated by: makeheader    Wed Mar  9 22:30:16 2022
 *
 *		built from:	dll.ifc
 */

#ifndef writer_history_dll_h
#define writer_history_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
  #if defined(RTI_writer_history_DLL_EXPORT)
    #define WRITERHISTORYDllExport __declspec( dllexport )
  #else
    #define WRITERHISTORYDllExport
  #endif /* NDDS_WriterHistory_DLL_EXPORT */

  #if defined(RTI_writer_history_DLL_VARIABLE) 
    #if defined(RTI_writer_history_DLL_EXPORT)
      #define WRITERHISTORYDllVariable __declspec( dllexport )
    #else
      #define WRITERHISTORYDllVariable __declspec( dllimport )
    #endif /* NDDS_WriterHistory_DLL_EXPORT */
  #else 
    #define WRITERHISTORYDllVariable
    #endif /* NDDS_WriterHistory_DLL_VARIABLE */
#else
  #define WRITERHISTORYDllExport
  #define WRITERHISTORYDllVariable
#endif /* RTI_WIN32 || RTI_WINCE || RTI_INTIME */


#endif /* writer_history_dll_h */
