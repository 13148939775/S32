/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)pres_condition.h    generated by: makeheader    Wed Mar  9 22:30:18 2022
 *
 *		built from:	condition.ifc
 */

#ifndef pres_condition_h
#define pres_condition_h


 #ifndef pres_dll_h
    #include "pres/pres_dll.h"
 #endif
 #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
 #endif
 #ifndef osapi_time_h
    #include "osapi/osapi_ntptime.h"
 #endif
 #ifndef osapi_semaphore_h
    #include "osapi/osapi_semaphore.h"
 #endif
 #ifndef reda_sequenceNumber_h
    #include "reda/reda_sequenceNumber.h"
 #endif
 #ifndef reda_inlineList_h
    #include "reda/reda_inlineList.h"
 #endif



typedef enum {
    TRIGGER_VALUE_FALSE             = 0x00,
    TRIGGER_VALUE_TRUE              = 0x01,
    TRIGGER_VALUE_IGNORE            = 0x02
} PRESConditionTriggerValue;


struct PRESWaitSet;

struct WaitSetNode {
    struct REDAInlineListNode _node;
    struct PRESWaitSet *_presWaitSetPtr;
};

/*e \ingroup PRESConditionModule
 * \brief A Condition.
 */
struct PRESCondition {
    RTIBool _triggerValue;
    RTIBool _isIndexCondition;
    struct REDAInlineList _waitSetList;
    struct REDAExclusiveArea* _ea;
    void *_userObject;
};


extern PRESDllExport
RTIBool PRESCondition_get_trigger_value(struct PRESCondition *self,
                                        struct REDAWorker* worker);

extern PRESDllExport
RTIBool PRESCondition_set_trigger_valueI(
        struct PRESCondition *self,
        PRESConditionTriggerValue trigger_value,
        struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESCondition_is_index_condition(struct PRESCondition *self);

extern PRESDllExport
void PRESCondition_initialize(struct PRESCondition *self,
                              void *userObject,
                              RTIBool isIndexCondition,
                              struct REDAExclusiveArea* ea);

extern PRESDllExport
void* PRESCondition_get_user_object(struct PRESCondition *self,
                                    struct REDAWorker* worker);

#endif /* pres_condition_h */
