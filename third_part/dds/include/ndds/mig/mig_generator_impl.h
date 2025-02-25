/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)mig_generator_impl.h    generated by: makeheader    Wed Mar  9 22:30:13 2022
 *
 *		built from:	generator_impl.ifc
 */

#ifndef mig_generator_impl_h
#define mig_generator_impl_h


  #ifndef osapi_bufferUtils_h
    #include "osapi/osapi_bufferUtils.h"
  #endif
  #ifndef reda_worker_h
    #include "reda/reda_worker.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif



#define MIGGenerator_addDataFrag( \
        __me, \
        __size, \
        __readerGuidIn, \
        __writerObjectId, \
        __readerDirectedInterceptorHandles, \
        __sample, \
        __numFragsToAdd, \
        __firstFragNumber, \
        __fragSize, \
        __numFragsAdded, \
        __use43DataFragFormat, \
        __encapsulationIndex, \
        __worker) \
    MIGGenerator_addDataFragEx( \
        __me, \
        __size, \
        __readerGuidIn, \
        __writerObjectId, \
        __readerDirectedInterceptorHandles, \
        __sample, \
        __numFragsToAdd, \
        __firstFragNumber, \
        __fragSize, \
        __numFragsAdded, \
        __use43DataFragFormat, \
        __encapsulationIndex, \
        RTI_FALSE, /* addVirtualSn */ \
        __worker)

#define MIGGeneratorSample_isValid(me, index)           \
    (me != NULL &&                             \
     (((me)->serializedData[index].serializedData.pointer == NULL ||       \
       ((me)->serializedData[index].serializedData.length & 0x3) == 0)) && \
     (((me)->protocolParameters.pointer == NULL ||      \
       ((me)->protocolParameters.length & 0x3) == 0)))

#define MIG_GENERATOR_SAMPLE_BIT_NONE      (0x0)
#define MIG_GENERATOR_SAMPLE_BIT_TIMESTAMP (0x01)

#define MIGGeneratorSample_isTimestamped(me) \
    (((me)->_bitmap & MIG_GENERATOR_SAMPLE_BIT_TIMESTAMP) != 0)

#define MIGGeneratorSample_compare ((REDAOrderedDataTypeCompareFunction) \
                                  REDASequenceNumber_compare)

#define MIGGeneratorSample_copy(me, src) \
    RTIOsapiMemory_copy(me, src, sizeof(struct MIGGeneratorSample))

MIGDllVariable extern struct REDAObjectPerWorker *MIG_GENERATOR_STAT_PER_WORKER;

#define MIGGeneratorWorkerStat_getStorageLazy(statPtr, worker) \
    ( *(statPtr) = (struct MIGGeneratorWorkerStat *)           \
        REDAWorker_assertObject(worker, MIG_GENERATOR_STAT_PER_WORKER) )

#define MIGGeneratorSecurityProperty_setDirectedInterceptorHandles( \
        __self, \
        __interceptorHandles) \
    MIGGeneratorSecurityProperty_removeDirectedInterceptorHandles(__self); \
    (__self)->clearDirectedInterceptorHandleLists = RTI_FALSE; \
    MIGGeneratorSecurityProperty_assertDirectedInterceptorHandles( \
            __self, \
            __interceptorHandles);



#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* mig_generator_impl_h */
