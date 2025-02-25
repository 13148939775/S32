/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_sharedMemory.h    generated by: makeheader    Wed Mar  9 22:29:44 2022
 *
 *		built from:	sharedMemory.ifc
 */

#ifndef osapi_sharedMemory_h
#define osapi_sharedMemory_h


  #ifndef osapi_log_h
    #include "osapi/osapi_log.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif



/* Precondition not met */
#define RTI_OSAPI_SHARED_MEMORY_FAIL_REASON_PRECONDITION                \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_OSAPI,                   \
                                        SUBMODULE_OSAPI_SHARED_MEMORY, 1)

/* Memory segment already claimed (and creator process still alive) */
#define RTI_OSAPI_SHARED_MEMORY_FAIL_REASON_ALREADY_CLAIMED             \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_OSAPI,                   \
                                        SUBMODULE_OSAPI_SHARED_MEMORY, 2)

/* The shared object (segment/semaphore) doesn't exist */
#define RTI_OSAPI_SHARED_MEMORY_FAIL_REASON_NO_ENTRY                    \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_OSAPI,                   \
                                        SUBMODULE_OSAPI_SHARED_MEMORY, 3)

/* The requested operation failed because of a system (uncontrolled) error
 * Output log will print the error code
 */
#define RTI_OSAPI_SHARED_MEMORY_FAIL_REASON_UNKNOWN                     \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_OSAPI,                   \
                                        SUBMODULE_OSAPI_SHARED_MEMORY, 4)


/* Attempt to release a mutex when the caller thread is not the owner */
#define RTI_OSAPI_SHARED_MEMORY_FAIL_REASON_NOT_OWNER			\
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_OSAPI,                   \
                                        SUBMODULE_OSAPI_SHARED_MEMORY, 5)

/* Shared object succesfully created from a new segment */
#define RTI_OSAPI_SHARED_MEMORY_CREATED                                 \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_OSAPI,                   \
                                        SUBMODULE_OSAPI_SHARED_MEMORY, 6)

/* Attached to an existing shared memory segment */
#define RTI_OSAPI_SHARED_MEMORY_ATTACHED                                \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_OSAPI,                   \
                                        SUBMODULE_OSAPI_SHARED_MEMORY, 7)

/* Semaphore has reached its max count */
#define RTI_OSAPI_SHARED_MEMORY_MAXCOUNT_REACHED			\
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_OSAPI,                   \
                                        SUBMODULE_OSAPI_SHARED_MEMORY, 8)

/* A generic no-error status value */
#define RTI_OSAPI_SHARED_MEMORY_SUCCESS					\
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_OSAPI,                   \
                                        SUBMODULE_OSAPI_SHARED_MEMORY, 9)



#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif
  #ifndef osapi_dll_h
    #include "osapi/osapi_dll.h"
  #endif

  #include "osapi/osapi_sharedMemory_impl.h"

#endif /* osapi_sharedMemory_h */
