/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_hash_impl.h    generated by: makeheader    Wed Mar  9 22:29:42 2022
 *
 *		built from:	hash_impl.ifc
 */

#ifndef osapi_hash_impl_h
#define osapi_hash_impl_h


  #include <stdlib.h>

  #ifndef osapi_dll_h
    #include "osapi/osapi_dll.h"
  #endif

#include "osapi/osapi_type.h"
#include "osapi/osapi_bufferUtils.h"
#include "osapi/osapi_bufferUtils_impl.h"

#ifdef __cplusplus
    extern "C" {
#endif



#define RTIOsapiHash_initializeMacro(a) \
       (a)->flags = 0, \
       (a)->length  = 0, \
       RTIOsapiMemory_zero((a)->value, RTI_OSAPI_HASH_MAX_LENGTH) \

#define RTIOsapiHash_isValidMacro(a) ( \
    ((a)->flags & RTI_OSAPI_HASH_FLAG_VALID) ? RTI_TRUE : RTI_FALSE)

#define RTIOsapiHash_lengthMacro(a) ((a)->length)

#define RTIOsapiHash_valueMacro(a) ((a)->value)

#define RTIOsapiHash_resetMacro(a) {(a)->flags &= ~RTI_OSAPI_HASH_FLAG_VALID;}

#define RTIOsapiHash_equalsMacro(a, b) \
    ((RTIOsapiHash_isValid(a) != RTIOsapiHash_isValid(b)) ?                    \
        (RTI_FALSE) :                                                          \
            (RTIOsapiHash_length(a) != RTIOsapiHash_length(b)) ?               \
                (RTI_FALSE) :                                                  \
                    RTIOsapiMemory_compare(                                    \
                        RTIOsapiHash_value(a),                                 \
                        RTIOsapiHash_value(b),                                 \
                        RTIOsapiHash_length(a)) == 0)

#define RTIOsapiHash_compareMacro(a, b) \
    ((RTIOsapiHash_isValid(a) - RTIOsapiHash_isValid(b)) ?                     \
        (RTIOsapiHash_isValid(a) - RTIOsapiHash_isValid(b)) :                  \
            (RTIOsapiHash_length(a) - RTIOsapiHash_length(b)) ?                \
                (RTIOsapiHash_length(a) - RTIOsapiHash_length(b)) :            \
                    RTIOsapiMemory_compare(                                    \
                        RTIOsapiHash_value(a),                                 \
                        RTIOsapiHash_value(b),                                 \
                        RTIOsapiHash_length(a)))


#ifdef RTI_PRECONDITION_TEST
  RTIOsapiDllExport
  void RTIOsapiHash_initialize(RTIOsapiHash *self);

  RTIOsapiDllExport
  RTIBool RTIOsapiHash_equals(const RTIOsapiHash *a, const RTIOsapiHash *b);

  RTIOsapiDllExport
  int RTIOsapiHash_compare(const RTIOsapiHash *a, const RTIOsapiHash *b);

  RTIOsapiDllExport
  RTIBool RTIOsapiHash_isValid(const RTIOsapiHash *self);

  RTIOsapiDllExport
  RTI_UINT8 RTIOsapiHash_length(const RTIOsapiHash *self);

  RTIOsapiDllExport
  RTI_UINT8 *RTIOsapiHash_value(const RTIOsapiHash *self);

  RTIOsapiDllExport
  void RTIOsapiHash_reset(struct RTIOsapiHash *self);

#else
  #define RTIOsapiHash_initialize RTIOsapiHash_initializeMacro
  #define RTIOsapiHash_equals     RTIOsapiHash_equalsMacro
  #define RTIOsapiHash_compare    RTIOsapiHash_compareMacro
  #define RTIOsapiHash_isValid    RTIOsapiHash_isValidMacro
  #define RTIOsapiHash_length     RTIOsapiHash_lengthMacro
  #define RTIOsapiHash_value      RTIOsapiHash_valueMacro
  #define RTIOsapiHash_reset      RTIOsapiHash_resetMacro
#endif




#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* osapi_hash_impl_h */
