/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)persistence_version.h    generated by: makeheader    Wed Mar  9 23:16:48 2022
 *
 *		built from:	version.ifc
 */

#ifndef persistence_version_h
#define persistence_version_h

 
#ifndef log_makeheader_h
  #include "log/log_makeheader.h"
#endif
#ifndef lua_binding_dll_h
  #include "persistence/persistence_dll.h"
#endif
#ifndef dds_c_infrastructure_h 
  #include "dds_c/dds_c_infrastructure.h"
#endif
  
#ifdef __cplusplus
  extern "C" {
#endif


typedef struct DDS_ProductVersion_t RTI_PersistenceServiceLibraryVersion;

extern PERSISTENCEDllExport
const RTI_PersistenceServiceLibraryVersion *
        RTI_PersistenceService_get_library_version();

extern PERSISTENCEDllExport
const char *RTI_PersistenceService_get_build_version_string();


#ifdef __cplusplus
}       /* extern "C" */
#endif


#endif /* persistence_version_h */
