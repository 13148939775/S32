/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_bloomFilter.h    generated by: makeheader    Wed Mar  9 22:29:58 2022
 *
 *		built from:	bloomFilter.ifc
 */

#ifndef reda_bloomFilter_h
#define reda_bloomFilter_h



#include "limits.h"

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


typedef void (*REDABloomFilterHashDefinition_ComputeHashesFunction) (
        RTI_UINT32 *hashesOut,
        RTI_UINT16 hashCount,
        const void* element,
        RTI_UINT32 elementSize);


struct REDABloomFilterHashDefinition {
    /*e @brief implementation data */
    void *hash_definition_data;
    /*e @brief handles the computation of the hashes */
    REDABloomFilterHashDefinition_ComputeHashesFunction computeHashes;
};

extern REDADllExport
void REDABlooFilterHashDefinitionHelper_getHashesFromMd5(
        RTI_UINT32 *hashesOut,
        RTI_UINT8 *md5Digest);


struct REDABloomFilter;

extern REDADllExport
RTI_UINT32 REDABloomFilter_size(struct REDABloomFilter *self);

extern REDADllExport
int REDABloomFilter_compare(
        struct REDABloomFilter *left, 
        struct REDABloomFilter *right);

extern REDADllExport
RTIBool REDABloomFilter_equals(
        struct REDABloomFilter *self, 
        struct REDABloomFilter *other);

extern REDADllExport
RTIBool REDABloomFilter_copy(
        struct REDABloomFilter *self, 
        struct REDABloomFilter *from);

extern REDADllExport
void REDABloomFilter_add(
        struct REDABloomFilter *self,
        const void *element,
        RTI_INT32 elementSize);

extern REDADllExport
RTIBool REDABloomFilter_query(
        struct REDABloomFilter *self,
        const void *element,
        RTI_INT32 elementSize);

extern REDADllExport
void REDABloomFilter_addFromHashes(
        struct REDABloomFilter *self,
        const RTI_UINT32 *hashes);

extern REDADllExport
RTIBool REDABloomFilter_queryFromHashes(
        struct REDABloomFilter *self,
        const RTI_UINT32 *hashes);

extern REDADllExport
struct REDABloomFilter* REDABloomFilter_union(
        struct REDABloomFilter *self,  
        struct REDABloomFilter *other);

extern REDADllExport
RTIBool REDABloomFilter_scale(
        struct REDABloomFilter* self, 
        RTI_UINT32 scaleFactor);

extern REDADllExport
void REDABloomFilter_empty(struct REDABloomFilter* self);

extern REDADllExport
void REDABloomFilter_fill(struct REDABloomFilter *self);

extern REDADllExport
void REDABloomFilter_delete(struct REDABloomFilter *self);

extern REDADllExport
struct REDABloomFilter* REDABloomFilter_new(
        RTI_INT32 size,
        RTI_UINT16 hashCount,
        const struct REDABloomFilterHashDefinition *hashDefinition);


#ifdef __cplusplus
    }	/* extern "C" */
#endif
    
#include "reda/reda_bloomFilter_impl.h"


#endif /* reda_bloomFilter_h */
