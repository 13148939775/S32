/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)pres_psGroup_impl.h    generated by: makeheader    Wed Mar  9 22:30:19 2022
 *
 *		built from:	psGroup_impl.ifc
 */

#ifndef pres_psGroup_impl_h
#define pres_psGroup_impl_h



#ifndef pres_psService_h
#include "pres/pres_psService.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif



/*---------------------------------------------------------------------------*/
#define PRESPsWriterGroup_getUserObject(me) ((me)->_parent.userObject)
#define PRESPsReaderGroup_getUserObject(me) ((me)->_parent.userObject)
/*---------------------------------------------------------------------------*/

#define PRESPsWriterGroup_isEnabled(me) \
    ((me)->_parent.state == PRES_ENTITY_STATE_ENABLED)
#define PRESPsReaderGroup_isEnabled(me) \
    ((me)->_parent.state == PRES_ENTITY_STATE_ENABLED)
/*---------------------------------------------------------------------------*/

#define PRESPsReaderGroup_getProperty(me, p, worker)                          \
    (me)->_service->getGroupProperty(                                         \
        (me)->_service, (struct PRESGroupProperty *)p, me, worker)

#define PRESPsReaderGroup_setProperty(me, fr, p, worker)                      \
    (me)->_service->setGroupProperty(                                         \
        (me)->_service, fr, me, (struct PRESGroupProperty *)p, worker)

/*---------------------------------------------------------------------------*/

#define PRESPsWriterGroup_getProperty(me, p, worker)                          \
    (me)->_service->getGroupProperty(                                         \
        (me)->_service, (struct PRESGroupProperty *)p, me, worker)

#define PRESPsWriterGroup_setProperty(me, fr, p, worker)                      \
    (me)->_service->setGroupProperty(                                         \
        (me)->_service, fr, me, (struct PRESGroupProperty *)p, worker)

/*---------------------------------------------------------------------------*/

#define PRESPsReaderGroup_getListener(me, worker)                             \
    (me)->_service->getGroupListener((me)->_service, me, worker)

#define PRESPsReaderGroup_setListener(me, fr, l, mask, worker)                \
    (me)->_service->setGroupListener(                                         \
        (me)->_service, fr, me, (struct PRESGroupListener *)l, mask, worker)

/*---------------------------------------------------------------------------*/

#define PRESPsWriterGroup_getListener(me, worker)                             \
    (me)->_service->getGroupListener((me)->_service, me, worker)

#define PRESPsWriterGroup_setListener(me, fr, l, mask, worker)                \
    (me)->_service->setGroupListener(                                         \
        (me)->_service, fr, me, (struct PRESGroupListener *)l, mask, worker)

/*---------------------------------------------------------------------------*/

#define PRESPsWriterGroup_lookupWriter(me, topic, worker)                     \
    (me)->_service->lookupEndpointFromGroup((me)->_service, me, topic, worker)


#define PRESPsReaderGroup_lookupReader(me, topic, worker)                     \
    (me)->_service->lookupEndpointFromGroup((me)->_service, me, topic, worker)

/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/

#define PRESPsWriterGroup_lookupWriterByGuid(me, guid, worker)                     \
    (me)->_service->lookupEndpointByGuidFromGroup((me)->_service, me, guid, worker)


#define PRESPsReaderGroup_lookupReaderByGuid(me, guid, worker)                     \
    (me)->_service->lookupEndpointByGuidFromGroup((me)->_service, me, guid, worker)

/*---------------------------------------------------------------------------*/

#define PRESPsReaderGroup_enable(me, fr, worker)                          \
    (me)->_service->enableGroup((me)->_service, fr, me, worker)

#define PRESPsWriterGroup_enable(me, fr, worker)                          \
    (me)->_service->enableGroup((me)->_service, fr, me, worker)

/*---------------------------------------------------------------------------*/

#define PRESPsReaderGroup_destroyContainedLocalEndpoints(me, fr, worker)    \
    (me)->_service->destroyAllLocalEndpointsInGroup((me)->_service, fr, me, \
     worker)

#define PRESPsWriterGroup_destroyContainedLocalEndpoints(me, fr, worker)    \
    (me)->_service->destroyAllLocalEndpointsInGroup((me)->_service, fr, me, \
     worker)

/*---------------------------------------------------------------------------*/

#define PRESPsReaderGroup_getGuid(__me, __guid)                     \
    (*(__guid)) = (__me)->_parent.guid

#define PRESPsWriterGroup_getGuid(__me, __guid)                     \
    (*(__guid)) = (__me)->_parent.guid



#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* pres_psGroup_impl_h */
