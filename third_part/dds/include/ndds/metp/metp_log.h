/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)metp_log.h    generated by: makeheader    Wed Mar  9 22:41:49 2022
 *
 *		built from:	log.ifc
 */

#ifndef metp_log_h
#define metp_log_h


  #ifndef log_common_h
    #include "log/log_common.h"
  #endif
  #ifndef metp_dll_h
    #include "metp/metp_dll.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif


#define SUBMODULE_METP_IBMGR                       (0x1000)
#define SUBMODULE_METP_SHMMGR                      (0x2000)
#define SUBMODULE_METP_TYPEPLUGIN                  (0x3000)
#define SUBMODULE_METP_IBLIB                       (0x4000)
#define SUBMODULE_METP_MEMMGR                      (0x5000)
#define SUBMODULE_METP_EVENTMGR                    (0x6000)
#define SUBMODULE_METP_BUILTINMGR                  (0x7000)


  #define METP_SUBMODULE_MASK_IBMGR             (0x0001)


  #define METP_SUBMODULE_MASK_SHMMGR            (0x0002)


  #define METP_SUBMODULE_MASK_TYPEPLUGIN        (0x0004)


  #define METP_SUBMODULE_MASK_IBLIB             (0x0008)


#define METP_SUBMODULE_MASK_MEMMGR              (0x0010)


#define METP_SUBMODULE_MASK_EVENTMGR            (0x0020)


  #define METP_SUBMODULE_MASK_BUILTINMGR	    (0x0040)


  #define METP_SUBMODULE_MASK_ALL               (0xffff)

extern METPDllExport
void METPLog_setVerbosity(RTILogBitmap submoduleMask, int verbosity);

extern METPDllExport
void METPLog_setBitmaps(RTILogBitmap submoduleMask,
                        RTILogBitmap instrumentationMask);

extern METPDllExport
void METPLog_getBitmaps(RTILogBitmap *submoduleMask,
                        RTILogBitmap *instrumentationMask);

extern METPDllVariable const struct RTILogMessage METP_LOG_INTERPRETER_ADD_FAILURE_XXXX;

extern METPDllVariable const struct RTILogMessage METP_LOG_ADD_FAILURE_s;


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* metp_log_h */
