/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)clock_monotonic.h    generated by: makeheader    Wed Mar  9 22:29:48 2022
 *
 *		built from:	monotonic.ifc
 */

#ifndef clock_monotonic_h
#define clock_monotonic_h


  #ifndef clock_interface_h
    #include "clock/clock_interface.h"
  #endif
  #ifndef clock_dll_h
    #include "clock/clock_dll.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTIMonotonicClock; /* forward declare to appease compiler */

extern RTIClockDllExport void RTIMonotonicClock_delete(struct RTIClock *me);

extern RTIClockDllExport struct RTIClock *RTIMonotonicClock_new(void);

extern RTIClockDllExport RTIBool RTIMonotonicClockUtility_isSupported(void);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* clock_monotonic_h */
