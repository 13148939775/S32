/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_buffer_impl.h    generated by: makeheader    Wed Mar  9 22:29:59 2022
 *
 *		built from:	buffer_impl.ifc
 */

#ifndef reda_buffer_impl_h
#define reda_buffer_impl_h


#ifdef __cplusplus
    extern "C" {
#endif



  #define REDABufferArray_getSize(answer, array, arrayCount) \
  { \
      register int i = 0; \
      for (*(answer) = 0; i < (arrayCount); ++i) { \
          *(answer) += ((array)[i]).length; \
      } \
  }

  #define REDABuffer_set(buf, ptr, len) \
  { \
      (buf)->length = (len); \
      (buf)->pointer = (ptr); \
  }

  #define REDABuffer_reset(buf) REDABuffer_set(buf, NULL, 0)

  #define REDABufferManager_initMacro(me, ptr, len) \
  { \
      (me)->buffer.length = (len); \
      (me)->buffer.pointer = (ptr); \
      (me)->currentPosition = ((me)->buffer.pointer); \
      (me)->errorCount = 0; \
  }

  #ifndef RTI_PRECONDITION_TEST
    #define REDABufferManager_init REDABufferManager_initMacro
  #endif /* !RTI_PRECONDITION_TEST */


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* reda_buffer_impl_h */
