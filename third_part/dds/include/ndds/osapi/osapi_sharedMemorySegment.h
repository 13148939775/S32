/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_sharedMemorySegment.h    generated by: makeheader    Wed Mar  9 22:29:44 2022
 *
 *		built from:	sharedMemorySegment.ifc
 */

#ifndef osapi_sharedMemorySegment_h
#define osapi_sharedMemorySegment_h


  #ifndef osapi_sharedMemory_h
    #include "osapi/osapi_sharedMemory.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTIOsapiSharedMemorySegmentHandle;

extern RTIOsapiDllExport RTIBool
RTIOsapiSharedMemorySegment_create(
		struct RTIOsapiSharedMemorySegmentHandle *handle,
		int* statusOut,
		int key, 
		int size, 
		RTI_UINT64 pidIn);

extern RTIOsapiDllExport RTIBool
RTIOsapiSharedMemorySegment_attach(
		struct RTIOsapiSharedMemorySegmentHandle *handle,
		int* statusOut,
		int key);

extern RTIOsapiDllExport RTIBool
RTIOsapiSharedMemorySegment_createOrAttach(
		struct RTIOsapiSharedMemorySegmentHandle *handle,
		int* statusOut,
		int key, 
		int size, 
		RTI_UINT64 pidIn);

extern RTIOsapiDllExport
char *RTIOsapiSharedMemorySegment_getAddress(
		struct RTIOsapiSharedMemorySegmentHandle *handle);

extern RTIOsapiDllExport
int RTIOsapiSharedMemorySegment_getSize(
		struct RTIOsapiSharedMemorySegmentHandle *handle);

extern RTIOsapiDllExport
int RTIOsapiSharedMemorySegment_getKey(
		struct RTIOsapiSharedMemorySegmentHandle *handle);

extern RTIOsapiDllExport
RTIBool RTIOsapiSharedMemorySegment_detach(
		struct RTIOsapiSharedMemorySegmentHandle *handle);

extern RTIOsapiDllExport
RTIBool RTIOsapiSharedMemorySegment_delete(
		struct RTIOsapiSharedMemorySegmentHandle *handle);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "osapi/osapi_sharedMemorySegment_impl.h"

#endif /* osapi_sharedMemorySegment_h */
