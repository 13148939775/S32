/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_thread_impl.h    generated by: makeheader    Wed Mar  9 22:29:45 2022
 *
 *		built from:	thread_impl.ifc
 */

#ifndef osapi_thread_impl_h
#define osapi_thread_impl_h


  
#ifdef cplusplus
    extern "C" {
#endif


#define RTIOsapiThread_spin(spinCount)		\
{														\
	RTI_UINT64 spin;									\
	RTI_UINT64 ad, bd, cd;								\
	volatile RTI_UINT64 * a, * b, * c;					\
	a = &ad;											\
	b = &bd;											\
	c = &cd;											\
	for (spin = 0; spin < (spinCount); ++spin) {		\
		*a = 3;											\
		*b = 1;											\
		*c = (*a/(*b))*spin;							\
	}													\
}


#ifdef RTI_OSAPI_SIGNAL_HANDLER_SUPPORTED

extern RTIOsapiDllExport
void RTIOsapiThread_setRaiseSignalOnHandler(RTIBool raiseSignalOnHandler);


#endif /* RTI_OSAPI_SIGNAL_HANDLER_SUPPORTED */


#ifdef RTI_FUNCTION_HISTORY_SUPPORTED
    #define RTIOsapiThread_addFunctionToDebugInfo(pointerFuncName)   \
    {                                                                \
        if (RTILog_addToFunctionHistory != NULL) {                   \
            RTILog_addToFunctionHistory(pointerFuncName);            \
        }                                                            \
    }

#else

    #define RTIOsapiThread_addFunctionToDebugInfo(pointerFuncName) \
        ((void) 0);

#endif /* RTI_FUNCTION_HISTORY_SUPPORTED */

extern RTIOsapiDllExport
void RTIOsapiThread_setCreateContextOnSpawned(RTIBool createContext);


#define RTIOsapiThread_getTssAsInteger(key__) \
    RTIOsapiUtility_pointerToInt(RTIOsapiThread_getTss((key__)))

#define RTIOsapiThread_setTssAsInteger(key__, value__) \
    RTIOsapiThread_setTss((key__), RTIOsapiUtility_intToPointer((value__)))



#ifdef cplusplus
    }	/* extern "C" */
#endif

#endif /* osapi_thread_impl_h */
