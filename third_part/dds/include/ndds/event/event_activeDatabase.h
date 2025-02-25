/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)event_activeDatabase.h    generated by: makeheader    Wed Mar  9 22:30:03 2022
 *
 *		built from:	activeDatabase.ifc
 */

#ifndef event_activeDatabase_h
#define event_activeDatabase_h


  #ifndef reda_database_h
    #include "reda/reda_database.h"
  #endif
  #ifndef event_dll_h
    #include "event/event_dll.h"
  #endif
  #ifndef event_activeObject_h
    #include "event/event_activeObject.h"
  #endif
  #ifndef event_smartTimer_h
    #include "event/event_smartTimer.h"
  #endif
  #ifndef osapi_threadFactory_h
    #include "osapi/osapi_threadFactory.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTIEventActiveDatabase;

struct RTIEventTimer;

struct RTIEventActiveDatabaseProperty {
    /*e This class is a child of REDADatabase */
    struct REDADatabaseProperty parent;
    /*e And this object is active */
    struct RTIEventActiveObjectProperty active;
    /*e Garbage collection period
      @todo consider spliting into slow and fast period
    */
    struct RTINtpTime cleanupPeriod;
    /*e @brief The thread participant identification.
     Used to give a meaningful name to the thread.
    */
    char threadParticipantId[RTI_OSAPI_THREAD_PARTICIPANT_ID_MAX_SIZE];
};


#define RTI_EVENT_ACTIVE_DATABASE_PROPERTY_DEFAULT { \
    REDA_DATABASE_PROPERTY_DEFAULT,                  \
    RTI_EVENT_ACTIVE_OBJECT_PROPERTY_DEFAULT,        \
    {30, 0},                                         \
    "#####", /* threadParticipantId */ \
}

struct RTIEventActiveDatabaseListener;/*forward declare */

extern RTIEventDllExport RTIBool
RTIEventActiveDatabase_delete(struct RTIEventActiveDatabase *me,
                              struct REDAWorker *worker);

extern RTIEventDllExport RTIBool
RTIEventActiveDatabase_shutdown(struct RTIEventActiveDatabase *me,
				struct REDAWorker *worker);

typedef void (*RTIEventActiveDatabaseOnStartedCallback)(
    struct RTIEventActiveDatabase *database, void *onStartedParam,
    struct REDAWorker *worker);

typedef void (*RTIEventActiveDatabaseOnWakeupCallback)(
    const struct RTIEventActiveDatabaseListener* me,
    struct REDAWorker *worker);

struct RTIEventActiveDatabaseListener {
    /*e Parent is the first member */
    struct RTIEventActiveObjectListener parent;
    /*e Active database start-up is asynchronous, so use this method
      to learn when the active database is fully operational.
    */
    RTIEventActiveDatabaseOnStartedCallback onStarted;
    /*e Associated with the onStarted() method */
    void *onStartedParam;

    RTIEventActiveDatabaseOnWakeupCallback onWakeup;
};


#define RTI_EVENT_ACTIVE_DATABASE_LISTENER_DEFAULT { \
    RTI_EVENT_ACTIVE_OBJECT_LISTENER_DEFAULT, \
    NULL, NULL, NULL }

extern RTIEventDllExport struct RTIEventActiveDatabase *
RTIEventActiveDatabase_new(
    struct REDAWorkerFactory *workerFactory,
    struct REDAExclusiveArea *adminEA,
    struct RTIEventTimer *timer,
    const struct RTIEventActiveDatabaseListener *listener,
    const struct RTIEventActiveDatabaseProperty *property,
    struct RTIOsapiThreadFactory *threadFactory,
    struct REDAWorker *worker);

extern RTIEventDllExport void
RTIEventActiveDatabase_getProperty(
    struct RTIEventActiveDatabase *me,
    struct RTIEventActiveDatabaseProperty *property,
    struct REDAWorker *worker);

extern RTIEventDllExport RTIBool
RTIEventActiveDatabase_wakeup(struct RTIEventActiveDatabase *me);

extern RTIEventDllExport
struct REDADatabase *
RTIEventActiveDatabase_getParent(struct RTIEventActiveDatabase *me);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "event/event_activeDatabase_impl.h"

#endif /* event_activeDatabase_h */
