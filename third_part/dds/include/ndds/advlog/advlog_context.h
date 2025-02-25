/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)advlog_context.h    generated by: makeheader    Wed Mar  9 22:30:02 2022
 *
 *		built from:	context.ifc
 */

#ifndef advlog_context_h
#define advlog_context_h


#ifndef osapi_activityContext_h
  #include "osapi/osapi_activityContext.h"
#endif
#ifndef advlog_dll_h
  #include "advlog/advlog_dll.h"
#endif

  #ifdef __cplusplus
    extern "C" {
  #endif


typedef RTI_UINT32 ADVLOGActivityID;


struct ADVLOGContextTemplate {
    ADVLOGActivityID activityId;  /* ID# for the activity */
    const char *format;    /* format of the activity string */
};

extern ADVLOGDllExport
void ADVLOGContextScope_beginWithEntries(RTI_UINT32 maxEntryCount);

extern ADVLOGDllExport
void ADVLOGContextScope_beginWithEntriesAndParams(
        RTI_UINT32 maxEntryCount,
        RTI_UINT32 maxParamsCount);

extern ADVLOGDllExport
void ADVLOGContextScope_enterActivity(
        const struct ADVLOGContextTemplate *contextTemplate);

extern ADVLOGDllExport
void ADVLOGContextScope_enterActivityWithParams(
        const struct ADVLOGContextTemplate *contextTemplate,
        ...);

extern ADVLOGDllExport
void ADVLOGContextScope_enterResource(
        const char *resource);

extern ADVLOGDllExport
void ADVLOGContextScope_enterResourceWithParams(
        const struct ADVLOGContextTemplate *contextTemplate,
        ...);

extern ADVLOGDllExport
void ADVLOGContextScope_enterResourceGuidWithParams(
        const struct ADVLOGContextTemplate *contextTemplate,
        ...);

extern ADVLOGDllExport
void ADVLOGContextScope_leave(void);

extern ADVLOGDllExport
void ADVLOGContextScope_end(void);

extern ADVLOGDllExport
void ADVLOGContext_enter(struct RTIOsapiActivityContextStackEntry *entry);

extern ADVLOGDllExport
void ADVLOGContext_enterPair(
        struct RTIOsapiContext *self,
        struct RTIOsapiActivityContextStackEntry *entry1,
        struct RTIOsapiActivityContextStackEntry *entry2);

extern ADVLOGDllExport
void ADVLOGContext_enterGroup(RTI_UINT32 groupSize, ...);

extern ADVLOGDllExport
void ADVLOGContext_leave(void);

extern ADVLOGDllExport
void ADVLOGContext_leaveGroup(
        struct RTIOsapiContext *self,
        RTI_UINT32 groupSize);

extern ADVLOGDllVariable
const struct ADVLOGContextTemplate RTI_ADVLOG_CONTEXT_TEMPLATE_RESOURCE_s;

extern ADVLOGDllVariable
const struct ADVLOGContextTemplate
        RTI_ADVLOG_CONTEXT_TEMPLATE_RESOURCE_TO_TY_KI_DO_ssssd;

extern ADVLOGDllVariable
const struct ADVLOGContextTemplate RTI_ADVLOG_CONTEXT_TEMPLATE_GUID_g;

extern ADVLOGDllVariable
const struct ADVLOGContextTemplate RTI_ADVLOG_CONTEXT_TEMPLATE_GUID_DO_gd;

extern ADVLOGDllVariable
const struct ADVLOGContextTemplate RTI_ADVLOG_CONTEXT_TEMPLATE_GUID_NA_DO_gsd;

extern ADVLOGDllVariable
const struct ADVLOGContextTemplate RTI_ADVLOG_CONTEXT_TEMPLATE_GUID_KI_DO_gsd;

extern ADVLOGDllVariable
const struct ADVLOGContextTemplate RTI_ADVLOG_CONTEXT_TEMPLATE_TOPIC_KI_s;

extern ADVLOGDllVariable
const struct ADVLOGContextTemplate
        RTI_ADVLOG_CONTEXT_TEMPLATE_GUID_KI_TO_TY_DO_gsssd;

extern ADVLOGDllVariable
const struct ADVLOGContextTemplate
        RTI_ADVLOG_CONTEXT_TEMPLATE_GUID_TO_TY_KI_DO_gssd;

extern ADVLOGDllVariable
const struct ADVLOGContextTemplate
        RTI_ADVLOG_CONTEXT_TEMPLATE_GUID_KI_ID_RECEIVE_gdg;


#define ADVLOG_ENTITY_SHORTNAME_PARTICIPANT "DP"
#define ADVLOG_ENTITY_SHORTNAME_PUBLISHER "Pu"
#define ADVLOG_ENTITY_SHORTNAME_SUBSCRIBER "Su"
#define ADVLOG_ENTITY_SHORTNAME_TOPIC "To"
#define ADVLOG_ENTITY_SHORTNAME_DATAWRITER "DW"
#define ADVLOG_ENTITY_SHORTNAME_DATAREADER "DR"


  #ifdef __cplusplus
    }	/* extern "C" */
  #endif

#include "advlog/advlog_context_impl.h"


#endif /* advlog_context_h */
