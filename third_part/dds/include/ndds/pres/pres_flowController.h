/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)pres_flowController.h    generated by: makeheader    Wed Mar  9 22:30:18 2022
 *
 *		built from:	flowController.ifc
 */

#ifndef pres_flowController_h
#define pres_flowController_h


 #ifndef pres_dll_h
    #include "pres/pres_dll.h"
 #endif
 #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
 #endif
 #ifndef event_jobDispatcher_h
    #include "event/event_jobDispatcher.h"
 #endif
 #ifndef pres_common_h
    #include "pres/pres_common.h"
 #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct PRESFlowController;

struct REDAWorker;

extern PRESDllExport 
PRESWord *PRESFlowController_getUserObject(struct PRESFlowController *me);

extern PRESDllExport 
struct PRESFlowController* PRESParticipant_createFlowController(
    struct PRESParticipant *me,
    int *failReason,
    const char *name,
    RTIBool explicitDestroyOnly,
    struct PRESFlowControllerProperty *property,
    struct REDAWorker *worker);

extern PRESDllExport 
RTIBool PRESParticipant_destroyFlowController(
    struct PRESParticipant *me,
    int *failReason,
    struct PRESFlowController *flowController,
    struct REDAWorker *worker);

extern PRESDllExport 
struct PRESFlowController* PRESParticipant_lookupFlowController(
    struct PRESParticipant *me,
    int *failReason,
    const char *name,
    struct REDAWorker *worker);

extern PRESDllExport 
RTIBool PRESFlowController_getProperty(const struct PRESFlowController *me,
                              struct PRESFlowControllerProperty *property,
                              struct REDAWorker *worker);

extern PRESDllExport 
RTIBool PRESFlowController_setProperty(struct PRESFlowController *me,
                              const struct PRESFlowControllerProperty *property,
                              struct REDAWorker *worker);

extern PRESDllExport 
RTIBool PRESFlowController_triggerFlow(struct PRESFlowController *me,
                              struct REDAWorker *worker);

extern PRESDllExport 
const char* PRESFlowController_getName(
    const struct PRESFlowController* me, struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESParticipant_lockAllFlowControllers(
    struct PRESParticipant *me,
    int *failReason,
    struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESParticipant_unlockAllFlowControllers(
    struct PRESParticipant *me,
    int *failReason,
    struct REDAWorker *worker);

extern PRESDllExport
int PRESParticipant_getFlowControllerCount(
    struct PRESParticipant *me,
    struct REDAWorker *worker);


#define PRESParticipantFlowControllerIterator REDACursor

extern PRESDllExport
struct PRESParticipantFlowControllerIterator *
PRESParticipant_getFlowControllerIterator(
    struct PRESParticipant *me,
    int *failReason,
    struct REDAWorker *worker);

extern PRESDllExport
void PRESParticipant_returnFlowControllerIterator(
    struct PRESParticipant *me,
    struct PRESParticipantFlowControllerIterator *iterator);

extern PRESDllExport
struct PRESFlowController * PRESParticipant_getNextFlowController(
    struct PRESParticipant *me,
    int *failReason,
    struct PRESParticipantFlowControllerIterator *iterator);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* pres_flowController_h */
