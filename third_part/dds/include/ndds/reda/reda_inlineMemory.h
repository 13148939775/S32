/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_inlineMemory.h    generated by: makeheader    Wed Mar  9 22:30:00 2022
 *
 *		built from:	inlineMemory.ifc
 */

#ifndef reda_inlineMemory_h
#define reda_inlineMemory_h


  #include <stdio.h> /* for FILE */
  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif

 #ifndef osapi_type_h
   #include "osapi/osapi_type.h"
 #endif

 #ifndef osapi_alignment_h
    #include "osapi/osapi_alignment.h"
 #endif

#ifdef __cplusplus
    extern "C" {
#endif

               
#ifdef REDA_INLINE_MEMORY_SUPPORT_BUFFERS_LARGER_THAN_TWO_GIGABYTES
    typedef RTI_INT64 REDAInlineMemoryOffset;
    #define REDA_INLINE_MEMORY_MANAGER_MAX_SIZE 0x7fffffffffffffffLL
    typedef RTI_INT64 REDAInlineMemorySize;
    typedef RTI_INT64 REDAInlineMemoryCounter;
#else
    typedef RTI_INT32 REDAInlineMemoryOffset;
    #define REDA_INLINE_MEMORY_MANAGER_MAX_SIZE 0x7fffffff 
    typedef RTI_INT32 REDAInlineMemorySize;
    typedef RTI_INT32 REDAInlineMemoryCounter;
#endif

 
 typedef void * (*REDAInlineMemory_lowerLevelAllocatorFunction)(void *data, REDAInlineMemorySize size);

 
 typedef void (*REDAInlineMemory_lowerLevelFreeFunction)(void *data, void *buffer);

struct REDAInlineMemoryProperty {
    
   /*e \brief The initial size of the memory managed by the manager 
    */
   REDAInlineMemorySize initial;
   
   /*e \brief The maximum size in bytes of the memory managed by the manager. 
    *  Use REDA_INLINE_MEMORY_MANAGER_MAX_SIZE for unlimited memory. 
    *  When equal to REDA_INLINE_MEMORY_MANAGER_MAX_SIZE,the size is
    *  only limited by the device's available memory.  
    *  In case initial==maximal, the memory reserved size is set on initialization
    *  and does not grow dynamically. 
    */
   REDAInlineMemorySize maximal;
   
   /*e \brief The increment rate at which the memory grows when needed. It is 
    *  measured in additional percentage points, so an increment of 100 implies 
    *  a duplication of size. Maximal should be larger to initial for increment to
    *  be utilized. The manager grows enough to successfully reserve a buffer of
    *  any size, therefore the capacity of the manager may increase beyond that 
    *  set by the increment parameter.   
    */
   RTI_UINT32 increment; 
   
   /*e \brief If false, the manager grows by creating an in-line list of memory
    *  managers. Neither the manager nor the buffers move once created or reserved.  
    *  If forceContiguousMemory is set to true, the manager copies itself into a
    *  larger manager when more memory is needed. In this case the manager as well
    *  as the reserved buffers can change location after a reserveBufferWihRelocation
    *  call. 
    *  @see   reserveBufferWihRelocation   
    */
   RTIBool forceContiguousMemory;  
   
   /*e \brief Sets the buffer's content to zero when the buffer is reserved  
    */
   RTIBool initializeBuffersToZero;
   
   /*  \brief A function pointer used to allocate memory from within the memory 
    *  manager. This function can call malloc, call other memory manager object, 
    *  a fast-buffer or any other memory allocating code. The function should 
    *  return NULL in case of failure or a pointer to the memory in case of success. 
    */
   REDAInlineMemory_lowerLevelAllocatorFunction lowerLevelAllocator;
   
   /*  \brief A function pointer used to free memory from within the memory 
    *  manager. This function can call free, call release of other lower level
    *  memory manager object, or a fast-buffer or any other memory freeing code. 
    *  @param buffer: memory address to release.
    *  @param data:The data field should be the same used for the
    *  lowerLevelAllocator function. 
    */
   REDAInlineMemory_lowerLevelFreeFunction lowerLevelFree;
   
   /*  \brief A data field used to allocate memory from a lower level allocator.
    */
   void *lowerLevelAllocatorData;
};

extern REDADllExport
void * REDAInlineMemoryLowerLevelAllocator_mallocAllocate(
        void *data,
        REDAInlineMemorySize size);

extern REDADllExport
void REDAInlineMemoryLowerLevelAllocator_mallocFree(
        void *data,
        void *buffer);

extern REDADllExport
void * REDAInlineMemoryLowerLevelAllocator_memoryManagerAllocate(
        void *data,
        REDAInlineMemorySize size);

extern REDADllExport
void REDAInlineMemoryLowerLevelAllocator_memoryManagerRelease(
        void *data,
        void *buffer);

 
#define REDAInlineMemoryProperty_INITIALIZER { \
    1024, /* initial */ \
    REDA_INLINE_MEMORY_MANAGER_MAX_SIZE, /* maximal */ \
    50, /* increment */ \
    RTI_FALSE, /* forceContiguousMemory */ \
    RTI_FALSE, /* initializeBuffersToZero */ \
    REDAInlineMemoryLowerLevelAllocator_mallocAllocate, /* lowerLevelAllocator */ \
    REDAInlineMemoryLowerLevelAllocator_mallocFree, /* lowerLevelFree */\
    NULL /* lowerLevelAllocatorData */ \
}

 
typedef void REDAInlineMemoryBuffer;

struct REDAInlineMemory;

extern REDADllExport
RTIBool REDAInlineMemory_initialize(
        struct REDAInlineMemory *self, 
        const struct REDAInlineMemoryProperty *property);

extern REDADllExport
struct REDAInlineMemory * REDAInlineMemory_new(
        const struct REDAInlineMemoryProperty *property);

extern REDADllExport
void REDAInlineMemory_getProperty(
        const struct REDAInlineMemory *self,
        struct REDAInlineMemoryProperty *property);

extern REDADllExport
void REDAInlineMemory_finalize(
        struct REDAInlineMemory *self);

extern REDADllExport
void REDAInlineMemory_delete(struct REDAInlineMemory *self);

extern REDADllExport
RTIBool REDAInlineMemory_reset(
        struct REDAInlineMemory *self);

extern REDADllExport
RTIBool REDAInlineMemory_copy(
        struct REDAInlineMemory **destPt,
        const struct REDAInlineMemory *src);

extern REDADllExport
struct REDAInlineMemory *REDAInlineMemory_clone(
        const struct REDAInlineMemory *self);

extern REDADllExport
REDAInlineMemoryBuffer * REDAInlineMemory_reserveBuffer(
        struct REDAInlineMemory **selfPt, 
        REDAInlineMemorySize bufferSize);

extern REDADllExport
RTIBool REDAInlineMemBuffer_release(REDAInlineMemoryBuffer *buffer);

extern REDADllExport
REDAInlineMemorySize REDAInlineMemBuffer_getSize(
        const REDAInlineMemoryBuffer *buffer);

extern REDADllExport
REDAInlineMemorySize REDAInlineMemory_size(
        const struct REDAInlineMemory *self);

extern REDADllExport
void REDAInlineMemory_print(
        const struct REDAInlineMemory *self);

extern REDADllExport
void REDAInlineMemory_printToFile(
        const struct REDAInlineMemory *self,
        FILE * fileDescriptor);

 
typedef REDAInlineMemoryOffset  REDAInlineReference;


#define REDA_INLINE_MEMORY_MANAGER_REFERENCE_INVALID (0)

extern REDADllExport
REDAInlineReference REDAInlineMemory_getReferenceFromBuffer(
        const REDAInlineMemoryBuffer *buffer);

extern REDADllExport
REDAInlineMemoryBuffer * REDAInlineMemory_getBufferFromReference(
        const struct REDAInlineMemory *self, 
        REDAInlineReference reference);

struct REDAInlineMemory_stat {
    /*e \brief Number of free blocks. */
    REDAInlineMemoryCounter freeBlockCount;
    /*e \brief Combined size of all the free blocks. */
    REDAInlineMemorySize totalFreeMemory;
    /*e \brief Size of the largest free block. */
    REDAInlineMemorySize biggestFreeBlock;
    /*e \brief Size of the smallest free block. */
    REDAInlineMemorySize smallestFreeBlock;
    
    /*e \brief Number of blocks reserved by the user. */
    REDAInlineMemoryCounter usedBlocksCount;
    /*e \brief Combined size of all the blocks reserved by the user. */
    REDAInlineMemorySize totalUsedMemory;
    /*e \brief Size of the largest block reserved by the user. */
    REDAInlineMemorySize biggestUsedBlock;
    /*e \brief Size of the smallest block reserved by the user. */
    REDAInlineMemorySize smallestUsedBlock;
};

 
#define REDAInlineMemoryStat_INITIALIZER { \
    0, /* freeBlockCount */ \
    0, /* totalFreeMemory */ \
    0, /* biggestFreeBlock */ \
    0, /* smallestFreeBlock */\
    0, /* usedBlocksCount */ \
    0, /* totalUsedMemory */ \
    0, /* biggestUsedBlock */\
    0  /* smallestUsedBlock */ \
}

extern REDADllExport
void REDAInlineMemory_getStat(
        const struct REDAInlineMemory *self,
        struct REDAInlineMemory_stat *stat);

extern REDADllExport
RTIBool REDAInlineMemory_allBuffersReturned(
        const struct REDAInlineMemory  *self);

extern REDADllExport
REDAInlineMemorySize REDAInlineMemory_minimumBlockSizeForBuffer(
        REDAInlineMemorySize bufferSize);

extern REDADllExport
REDAInlineMemorySize REDAInlineMemory_userDataSize(
        const struct REDAInlineMemory *self);

extern REDADllExport
RTIBool REDAInlineMemory_isAliveManager(const struct REDAInlineMemory *self);

extern REDADllExport
REDAInlineMemorySize REDAInlineMemory_minManagerSizeToHoldBuffer(
        REDAInlineMemorySize bufferSize);


#ifdef __cplusplus
    }	/* extern "C" */
#endif
    
  #include "reda/reda_inlineMemory_impl.h"

#endif /* reda_inlineMemory_h */
