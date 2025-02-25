/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)pres_participant_impl.h    generated by: makeheader    Wed Mar  9 22:30:19 2022
 *
 *		built from:	participant_impl.ifc
 */

#ifndef pres_participant_impl_h
#define pres_participant_impl_h


#ifdef __cplusplus
    extern "C" {
#endif



 #define PRESReducedLocatorDerivableQosPolicy_asLocatorDerivableQosPolicy(qos) \
        ((struct PRESLocatorDerivableQosPolicy *) (qos))

#define PRESParticipant_calculateTotalSize(testType, userObjectSize, userObjectAlignment) \
  (((userObjectSize) <= 0) ? (int) sizeof(testType) : \
    (RTIOsapiAlignment_alignSizeUp(sizeof(testType), (userObjectAlignment)) + (userObjectSize)))

/*
 * userObjectSize__ and userObjectAlignment__ are ints.
 * RTIOsapiAlignment_getAlignmentOf returns a size_t (unsigned).
 * We cast the result of RTIOsapiAlignment_getAlignmentOf so that we don't get
 * a warning while comparing. It assumes that the alignment of testType__ will
 * fit in a signed integer.
 */
#define PRESParticipant_calculateTotalAlignment(\
    testType__, userObjectSize__, userObjectAlignment__) \
  (((userObjectSize__) > 0 \
      && (userObjectAlignment__) > (int) RTIOsapiAlignment_getAlignmentOf(testType__)) \
          ? (userObjectAlignment__) \
          : (int) RTIOsapiAlignment_getAlignmentOf(testType__))

#define PRESParticipant_calculateUserObjectPointer(entityPtr, testType, userObjectSize, userObjectAlignment) \
  (((userObjectSize) <= 0) ? (void *)NULL : \
   (void *)((char *)(entityPtr) + RTIOsapiAlignment_alignSizeUp(sizeof(testType), (userObjectAlignment))))

#define PRESInstanceHandle_compare(handle1, handle2)                           \
 (((handle1)->isValid - (handle2)->isValid)                                    \
  ? ((handle1)->isValid - (handle2)->isValid)                                  \
  : (MIGRtpsKeyHash_compare(&(handle1)->keyHash,                        \
      &(handle2)->keyHash)))

#define PRESInstanceHandle_copy(__dst, __src) (*(__dst) = *(__src))

#define PRESInstanceHandle_isNil(__me) \
    ((__me)->isValid == PRES_INSTANCE_HANDLE_INVALID_KEYHASH)

#define PRESInstanceHandle_isProtected(__me) \
    ((__me)->isValid == PRES_INSTANCE_HANDLE_VALID_SECURE_KEYHASH \
            || (__me)->isValid == PRES_INSTANCE_HANDLE_VALID_SECURE_KEYHASH_V2)

#define PRESInstanceHandle_isV2(__me) \
    ((__me)->isValid == PRES_INSTANCE_HANDLE_VALID_UNSECURE_KEYHASH_V2 \
            || (__me)->isValid == PRES_INSTANCE_HANDLE_VALID_SECURE_KEYHASH_V2)

#define PRESInstanceHandle_fromGuid(__me, __guid) \
{ \
    MIGRtpsKeyHash_fromGuid(&(__me)->keyHash, (__guid)); \
    (__me)->isValid = PRES_INSTANCE_HANDLE_VALID_UNSECURE_KEYHASH; \
}

#define PRESInstanceHandle_getInstanceHandleIsValidValue( \
        useV2Encapsulation, \
        useKeyProtection) \
( \
    (useV2Encapsulation) \
        ? ((useKeyProtection) \
            ? (PRES_INSTANCE_HANDLE_VALID_SECURE_KEYHASH_V2) \
            : (PRES_INSTANCE_HANDLE_VALID_UNSECURE_KEYHASH_V2)) \
        : ((useKeyProtection) \
            ? (PRES_INSTANCE_HANDLE_VALID_SECURE_KEYHASH) \
            : (PRES_INSTANCE_HANDLE_VALID_UNSECURE_KEYHASH)) \
)

#define PRESInstanceHandle_isInstanceHandleCompatible( \
        instanceHandle, \
        useV2Encapsulation, \
        useKeyProtection) \
( \
    ((instanceHandle)->isValid  == PRES_INSTANCE_HANDLE_INVALID_KEYHASH) \
    || ((useV2Encapsulation) \
        ? ((useKeyProtection) \
            ? ((instanceHandle)->isValid == PRES_INSTANCE_HANDLE_VALID_SECURE_KEYHASH_V2) \
            : ((instanceHandle)->isValid == PRES_INSTANCE_HANDLE_VALID_UNSECURE_KEYHASH_V2)) \
        : ((useKeyProtection) \
            ? ((instanceHandle)->isValid == PRES_INSTANCE_HANDLE_VALID_SECURE_KEYHASH) \
            : ((instanceHandle)->isValid == PRES_INSTANCE_HANDLE_VALID_UNSECURE_KEYHASH))) \
)

/*
 * If a remote participant has an identity token, then it is able to do
 * authentication, which is the foundation for the rest of security. Without
 * authentication, it can do no security.
 */
#define PRESRemoteParticipant_isAuthenticationEnabled( \
    /* struct PRESParticipantParameter * */parameter) \
    (!PRESDataHolder_isNil((parameter)->securityTokens.identity))


extern PRESDllExport
RTIBool PRESParticipant_assertRemoteParticipantI(
    struct PRESParticipant *me,
    int *failReason, /* out */
    struct PRESRemoteParticipantProperty *verifiedProperty, /* out */
    struct PRESReducedLocatorQosPolicy *oldMetatrafficMulticastLocator, /* out */
    struct PRESLocatorQosPolicy *oldMetatrafficUnicastLocator, /* out */
    const PRESSampleHash *sampleHash,
    const struct PRESSampleSignature *sampleSignature,
    const struct PRESParticipantParameter *participantParameter, /* Used only if called from disc.2.0 */
    const MIGRtpsParticipantId *remoteParticipantId /*RTPS.2.0*/,
    const struct PRESRemoteParticipantProperty *property,
    struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESParticipant_verifyRemoteParticipantSignedDataI(
    struct PRESParticipant *me,
    const MIGRtpsParticipantId *remoteParticipantId,
    const struct REDABuffer *signedData,
    const struct REDABuffer *signature,
    struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESParticipant_verifyRemoteParticipantDiscoverySampleSignatureI(
    struct PRESParticipant *me,
    const MIGRtpsParticipantId *remoteParticipantId,
    const struct PRESSampleSignature *sampleSignature,
    MIGRtpsStatusInfo signatureStatusInfo,
    const PRESSampleHash *sampleHash,
    RTIBool isDiscoveryService,
    struct REDAWorker *worker);



#define PRESParticipantSecurityInfo_isDefault(info) \
        ((info)->bitmask == PRES_PARTICIPANT_SECURITY_ATTRIBUTES_BITMASK_DEFAULT \
                && (info)->pluginBitmask == PRES_PLUGIN_PARTICIPANT_SECURITY_ATTRIBUTES_BITMASK_DEFAULT)

#define PRESParticipantPluginPromiscuityKind_isDefault(pluginPromiscuityKind) \
    ((*pluginPromiscuityKind) == PRES_DISCOVER_MATCHING_REMOTE_ENTITIES_PROMISCUITY)

#define PRESParticipantDomainId_isDefault(domainId) \
    ((int)(*domainId) == MIG_RTPS_DOMAIN_DEFAULT)

#define PRESParticipantTransportInfoSeq_isEmpty(transportInfoSeq) \
    (PRESSequenceOctet_isEmpty(*(transportInfoSeq)))

#define PRESParticipantServiceQosPolicy_isDefault(serviceQosPolicy) \
    ((serviceQosPolicy)->kind == PRES_NO_SERVICE_QOS)

#define PRESParticipantUserData_isEmpty(userData) \
    (PRESSequenceOctet_isEmpty((userData)->data))

#define PRESParticipantPeerHostEpoch_isDefault(peerHostEpoch) \
    ((*peerHostEpoch) == 0)

#define PRESParticipantPropertyList_isEmpty(propertyList) \
    (PRESSequenceOctet_isEmpty((propertyList)->data))

#define PRESParticipantParticipantName_isDefault(participantName) \
    ((*participantName) == NULL)

#define PRESParticipantParticipantRoleName_isDefault(participantRoleName) \
    ((*participantRoleName) == NULL)

#define PRESParticipantSecurityTokensIdentity_isDefault(securityTokensIdentity) \
    (PRESDataHolder_isNil(*securityTokensIdentity))

#define PRESParticipantSecurityTokensPermissions_isDefault(securityTokensPermissions) \
    (PRESDataHolder_isNil(*securityTokensPermissions))


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* pres_participant_impl_h */
