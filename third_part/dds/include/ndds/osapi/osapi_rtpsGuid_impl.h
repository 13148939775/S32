/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_rtpsGuid_impl.h    generated by: makeheader    Wed Mar  9 22:29:44 2022
 *
 *		built from:	rtpsGuid_impl.ifc
 */

#ifndef osapi_rtpsGuid_impl_h
#define osapi_rtpsGuid_impl_h


#ifdef __cplusplus
    extern "C" {
#endif


#define RTIOsapiRtpsGuid_equals(a, b) \
    ((a)->prefix.hostId == (b)->prefix.hostId && \
    (a)->prefix.appId == (b)->prefix.appId &&  \
    (a)->prefix.instanceId == (b)->prefix.instanceId &&  \
    (a)->objectId == (b)->objectId)

#define RTIOsapiRtpsGuidPrefix_equals(a, b) \
    ((a)->hostId == (b)->hostId && \
    (a)->appId == (b)->appId &&  \
    (a)->instanceId == (b)->instanceId)


#ifdef __cplusplus
    }	/* extern "C" */
#endif


#endif /* osapi_rtpsGuid_impl_h */
