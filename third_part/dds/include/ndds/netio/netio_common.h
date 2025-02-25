/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)netio_common.h    generated by: makeheader    Wed Mar  9 22:30:11 2022
 *
 *		built from:	common.ifc
 */

#ifndef netio_common_h
#define netio_common_h


  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif
  #ifndef osapi_ntptime_h
    #include "osapi/osapi_ntptime.h"
  #endif
  #ifndef reda_buffer_h
    #include "reda/reda_buffer.h"
  #endif
  #ifndef reda_inlineList_h
    #include "reda/reda_inlineList.h"
  #endif
  #ifndef netio_cap_include_manager_h
    #include "netio_cap/netio_cap_manager.h"
  #endif
  #ifndef netio_dll_h
    #include "netio/netio_dll.h"
  #endif
  #ifndef transport_interface_h
    #include "transport/transport_interface.h"
  #endif
  #ifndef cdr_encapsulation_h
    #include "cdr/cdr_encapsulation.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDAWorker;/* forward declare to appease compiler */

struct RTINetioAddressFilter {
    /*e Address portion of the filter.  Only the bits that correspond to
      the "1" of the mask bit matter.
    */
    NDDS_Transport_Address_t address;
    /*e mask for the address */
    NDDS_Transport_Address_t mask;
};

extern RTINetioDllExport void
RTINetioAddressFilter_print(const struct RTINetioAddressFilter *address,
			    const char *desc, 
			    int indent);

extern RTINetioDllExport
int RTINetioAddressFilter_compare(const struct RTINetioAddressFilter *l, 
				  const struct RTINetioAddressFilter *r);

extern RTINetioDllExport
RTIBool RTINetioAddressFilter_filter(const struct RTINetioAddressFilter *me,
				     const NDDS_Transport_Address_t *address);


#define RTI_NETIO_ADDRESS_INVALID { \
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} }


#define RTI_NETIO_ADDRESS_FILTER_ANY {\
      RTI_NETIO_ADDRESS_INVALID, \
      RTI_NETIO_ADDRESS_INVALID}


#define RTI_NETIO_ADDRESS_FILTER_UNSPECIFIED { \
      RTI_NETIO_ADDRESS_INVALID, \
      {{0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF, \
                0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF}} }


#define RTI_NETIO_ADDRESS_FILTER_LOOPBACK { \
      {{0, 0, 0, 1}}, \
      {{0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF, \
                0xFF,0xFF,0xFF,0xFF, 0xFF,0xFF,0xFF,0xFF}} }                                                           


#define RTI_NETIO_ADDRESS_FILTER_MULTICAST { \
      {{0xFF,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, \
                0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00}}, \
      {{0xFF,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, \
                0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00}} }                                                                   


#define RTI_NETIO_ADDRESS_FILTER_SITE_LOCAL_UNICAST { \
      {{0xFE,0xC0,0x00,0x00, 0x00,0x00,0x00,0x00, \
                0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00}}, \
      {{0xFF,0xC0,0x00,0x00, 0x00,0x00,0x00,0x00, \
                0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00}} }                                                                     

extern RTINetioDllExport RTIBool
RTINetioAddressFilter_from(struct RTINetioAddressFilter   *me, 
			   const NDDS_Transport_Address_t *address_range_in,
			   int transport_address_bit_count_in);


#define RTI_NETIO_ALIAS_LIST_LENGTH_MAX (128)

struct RTINetioAliasList {
    /*e @brief An NULL terminated string of characters. 
      
        One extra element, to guarantee that it is always 
        terminated by a '\0' character. Thus strncpy()
        can be safely used:
        
        \code
        RTIAliasList aliasList = RTI_NETIO_ALIAS_LIST_DEFAULT;
        strncpy(aliasList.element, sourceAliasString, 
                RTI_NETIO_ALIAS_LIST_LENGTH_MAX);
       \endcode
     */
    char element[RTI_NETIO_ALIAS_LIST_LENGTH_MAX+1]; 
};

extern RTINetioDllExport void 
RTINetioAliasList_init(struct RTINetioAliasList* me);

extern RTINetioDllExport void 
RTINetioAliasList_fromString(struct RTINetioAliasList* me, 
                             const char* stringValueIn);

extern RTINetioDllExport 
void RTINetioAliasList_fromLocatorString(
        struct RTINetioAliasList *me,
        const char *locatorString);

extern RTINetioDllExport RTIBool 
RTINetioAliasList_fromStringArray(
            struct RTINetioAliasList *me, 
            const char **stringArray,
            int stringArrayLength);

extern RTINetioDllExport const char* 
RTINetioAliasList_toString(struct RTINetioAliasList* me);

extern RTINetioDllExport RTIBool 
RTINetioAliasList_append(struct RTINetioAliasList* me, 
                         const struct RTINetioAliasList* listIn);

extern RTINetioDllExport RTIBool 
RTINetioAliasList_appendFromString(struct RTINetioAliasList* me, 
                         const char *stringIn);

extern RTINetioDllExport RTIBool
RTINetioAliasList_split(const struct RTINetioAliasList* me, 
                        struct RTINetioAliasList* headOut, 
                        struct RTINetioAliasList* tailOut);

extern RTINetioDllExport RTI_INT32 
RTINetioAliasList_count(const struct RTINetioAliasList* me);

extern RTINetioDllExport RTIBool 
RTINetioAliasList_match(struct RTINetioAliasList* candidateListIn, 
                        struct RTINetioAliasList* targetListIn);

extern RTINetioDllExport int 
RTINetioAliasList_compare(const struct RTINetioAliasList *l,
			  const struct RTINetioAliasList *r);

extern RTINetioDllExport void 
RTINetioAliasList_print(const struct RTINetioAliasList *data, 
			const char *desc, int indent);


#define RTI_NETIO_ALIAS_LIST_SEPARATOR   ','


#define RTI_NETIO_ALIAS_LIST_DEFAULT { {\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0 /* Guarantee NULL terminated */ \
}}


#define RTI_NETIO_ALIAS_LIST_UDPv4 { {\
    'u', 'd', 'p', 'v', '4', 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0 /* Guarantee NULL terminated */ \
}}

#define RTI_NETIO_ALIAS_LIST_UDPv4_WAN { { \
    'u', 'd', 'p', 'v', '4', '_', 'w', 'a', 'n', 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0 /* Guarantee NULL terminated */ \
}}


#define RTI_NETIO_ALIAS_LIST_UDPv6 { {\
    'u', 'd', 'p', 'v', '6', 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0 /* Guarantee NULL terminated */ \
}}


#define RTI_NETIO_ALIAS_LIST_INTRA { {\
    'i', 'n', 't', 'r', 'a', 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0 /* Guarantee NULL terminated */ \
}}


#define RTI_NETIO_ALIAS_LIST_SHMEM { {\
    's', 'h', 'm', 'e', 'm', 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0 /* Guarantee NULL terminated */ \
}}


#define RTI_NETIO_ALIAS_LIST_STARFABRIC { {\
    's', 't', 'a', 'r', 'f', 'a', 'b', 'r', 'i', 'c', \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0 /* Guarantee NULL terminated */ \
}}


#define RTI_NETIO_ALIAS_LIST_INTRA_UDPv4 { {\
    'i', 'n', 't', 'r', 'a', RTI_NETIO_ALIAS_LIST_SEPARATOR, 'u', 'd', 'p', 'v', \
    '4', 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0 /* Guarantee NULL terminated */ \
}}


/* This maximum is obtained from the RTPS spec:
 * 9.4.2.10 LocatorList: The PSM mapping for the LocatorList SubmessageElement
 * defined in Section 8.3.5.11 is given by the following IDL definition:
 *    typedef sequence<Locator_t, 8> LocatorList;
 */
#define RTPS_LOCATOR_LIST_MAX_SIZE   (8)

/* This is the current maximum number of locators RTI Connext DDS supports.
 * This is a hard limit used for preallocating multiple structures across the
 * whole tree. Also, it is used as a hard limit for multiple checks we perform
 * in higher modules. Note that while this defines a hard limit, a should limit
 * can be imposed by the middleware configuration.
 *
 * Right now, we have decided to set this to two times the RTPS limit. This
 * should provide plenty locators for supporting three interfaces while enabling
 * three ip transports plus shared memory.
 */
#define RTI_NETIO_RTPS_LOCATOR_LIST_MAX_SIZE   (2*RTPS_LOCATOR_LIST_MAX_SIZE)

/*
 * Maximum used for lists that don't need more that a couple of locators (e.g.,
 * multicast locators). Used to reduce memory usage.
 */
#define RTI_NETIO_RTPS_LOCATOR_REDUCED_LIST_MAX_SIZE   (RTPS_LOCATOR_LIST_MAX_SIZE/2)


#define RTI_NETIO_RTPS_LOCATOR_LIST_DEFAULT { \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID  \
}

#define RTI_NETIO_RTPS_LOCATOR_REDUCED_LIST_DEFAULT { \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID, \
         RTI_NETIO_LOCATOR_INVALID  \
}



#define NETIO_LOCATOR_ENCAPSULATION_COUNT_MAX (4)
#define NETIO_LOCATOR_ENCAPSULATION_ARRAY_INVALID {0, 0, 0, 0}

struct RTINetioLocator {
    /*e
      @brief A transport class.
     */
    NDDS_Transport_ClassId_t transport;

    /*e
      @brief An address. Must be unique for the transport class
      in the domain.
     */
    NDDS_Transport_Address_t address;

    /*e
     @brief Address hostname
     */
    char *hostname;

    /*e
      @brief A port number.
     */
    NDDS_Transport_Port_t port;

    /*e
      @brief Number of encapsulations
    */
    RTI_UINT32 encapsulationCount;

    /*e
      @brief encapsulation IDs
     */
    RTIEncapsulationId encapsulations[NETIO_LOCATOR_ENCAPSULATION_COUNT_MAX];

    /*e
      @brief loss probability
     */
    RTI_FLOAT32 lossProbability;
};

extern RTINetioDllExport
void RTINetioLocator_from(struct RTINetioLocator *me, 
		     NDDS_Transport_ClassId_t             transportIn,
		     const NDDS_Transport_Address_t      *addressIn,
		     NDDS_Transport_Port_t                portIn);

extern RTINetioDllExport 
void RTINetioLocator_print(const struct RTINetioLocator *me, 
			   const char *desc,
			   int indent);

extern RTINetioDllExport 
void RTINetioLocator_printODT(void *me, 
			   const char *desc,
			   int indent);


#define RTI_NETIO_LOCATOR_STRING_BUFFER_SIZE \
    RTI_NETIO_ALIAS_LIST_LENGTH_MAX + 3 /*strlen("://")*/ + \
    NDDS_TRANSPORT_ADDRESS_STRING_BUFFER_SIZE + 6/*strlen(":99999")*/ + 1

extern RTINetioDllExport 
RTIBool RTINetioLocator_toString(
    const struct RTINetioLocator *me, 
    const struct RTINetioAliasList * aliasList,
    char * buffer,
    RTI_UINT32 bufferSize);

extern RTINetioDllExport
int RTINetioLocator_compare(const struct RTINetioLocator *l, 
			    const struct RTINetioLocator *r);

extern RTINetioDllExport
int RTINetioLocator_compareWithEncapsulationODT(void *l, void *r);

extern RTINetioDllExport
int RTINetioLocator_compareWithEncapsulation(const struct RTINetioLocator *l, 
                                             const struct RTINetioLocator *r);

struct RTINetioLocatorCompareOptions {
    RTIBool compareEncapsulations;
    RTIBool compareHostname;
    RTIBool compareAddress;
    RTIBool comparePort;
};


#define RTI_NETIO_LOCATOR_COMPARE_OPTIONS_DEFAULT {\
    RTI_FALSE, /* compareEncapsulations */ \
    RTI_FALSE, /* compareHostname */ \
    RTI_FALSE, /* compareAddress*/ \
    RTI_FALSE /* comparePort */ }

extern RTINetioDllExport
int RTINetioLocator_compareWithCompareOptions(
        const struct RTINetioLocator *l,
        const struct RTINetioLocator *r,
        const struct RTINetioLocatorCompareOptions *compareOptions);

extern RTINetioDllExport
void RTINetioLocator_addEncapsulations(
                    struct RTINetioLocator *me, 
                    int encapsulationCount,
                    RTIEncapsulationId *encapsulations,
                    RTIBool *foundMoreThanProvidedFor);

extern RTINetioDllExport
void RTINetioLocator_initialize(struct RTINetioLocator *me);

extern RTINetioDllExport
void RTINetioLocator_finalize(
        struct RTINetioLocator *me);

extern RTINetioDllExport
RTIBool RTINetioLocator_copy(
        struct RTINetioLocator *me,
        const struct RTINetioLocator *base);


#define RTI_NETIO_LOCATOR_INVALID { \
  NDDS_TRANSPORT_CLASSID_INVALID, /* transportClass */ \
  RTI_NETIO_ADDRESS_INVALID, /* address */ \
  NULL, /* hostname */ \
  0, /* port */ \
  0, /* encapsulationCount */ \
  NETIO_LOCATOR_ENCAPSULATION_ARRAY_INVALID, /* encapsulationIDs */ \
  0.0, /* lossProbability */ \
}

struct RTINetioLocatorInlineNode {
    struct REDAInlineListNode parent;
    struct RTINetioLocator self;
};

struct REDAFastBufferPool;

extern RTINetioDllExport struct RTINetioLocatorInlineNode*
RTINetioLocatorInlineList_findEA(struct REDAInlineList* me,
				 const struct RTINetioLocator* locatorIn);

extern RTINetioDllExport struct RTINetioLocatorInlineNode*
RTINetioLocatorInlineList_addEA(struct REDAInlineList* me,
				struct REDAFastBufferPool* nodePoolIn,
				const struct RTINetioLocator* locatorIn);

extern RTINetioDllExport void
RTINetioLocatorInlineList_removeEA(
        struct REDAInlineList *me,
        struct REDAFastBufferPool *nodePoolIn,
        const struct RTINetioLocator *locatorIn);

extern RTINetioDllExport void
RTINetioLocatorInlineList_finalizeEA(struct REDAInlineList* me,
				     struct REDAFastBufferPool* nodePoolIn);


#define RTI_NETIO_DESTINATION_LIST_NODE_INVALID_IP_FLAG 0x01
#define RTI_NETIO_DESTINATION_LIST_NODE_FLAGS_DEFAULT 0x00

struct RTINetioDestinationListNode {
    struct RTINetioLocatorInlineNode parent;
    RTI_UINT32 refcount;
    RTI_UINT32 flags;
};

struct RTINetioDestinationList {
    struct REDAInlineList list;
    struct REDAInlineList listWithNames;
    struct REDAFastBufferPool* pool;
    struct REDAExclusiveArea *ea;
};

extern RTINetioDllExport
void RTINetioDestinationList_finalize(
        struct RTINetioDestinationList * me);

extern RTINetioDllExport RTIBool
RTINetioDestinationList_init(
        struct RTINetioDestinationList * me,
        struct REDAExclusiveArea *ea);

extern RTINetioDllExport
RTIBool RTINetioDestinationList_assert(
    struct RTINetioDestinationList *me,
    int *newHostAdded,
    int *newHostWithNameAdded,
    const struct RTINetioLocator *destinationList,
    int destinationCount,
    struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioDestinationList_remove(
    struct RTINetioDestinationList *me,
    const struct RTINetioLocator *destinationList,
    int destinationCount,
    RTIBool forceDestinationRemoval,
    RTIBool *destinationWasRemoved,
    struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioDestinationList_removeName(
    struct RTINetioDestinationList *me,
    RTIBool *destinationWasRemoved,
    RTIBool *destinationWithNameWasRemoved,
    const struct RTINetioLocator *destinationList,
    int destinationCount,
    RTIBool forceDestinationRemoval,
    struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioDestinationList_update(
    struct RTINetioDestinationList *me,
    const struct RTINetioLocator *destinationWithName,
    const NDDS_Transport_Address_t *newAddress,
    RTIBool *destinationUpdated,
    struct REDAWorker *worker);

extern RTINetioDllExport
RTIBool
RTINetioDestinationList_startIteration(
    struct RTINetioDestinationList *me,
    struct RTINetioDestinationListNode **nodeOut,
    RTIBool useNameList,
    struct REDAWorker *worker);

extern RTINetioDllExport
RTIBool
RTINetioDestinationList_endIteration(
    struct RTINetioDestinationList *me,
    struct REDAWorker *worker);

struct RTINetioLocatorInfo { 
    /*e @brief A locator. */
    struct RTINetioLocator locator;

    /*e @brief Transport specific priority */
    int transport_priority;

    /*e @brief Alias list, that specifies the list of transport plugin 
      instances that should handle the locator.      
    */
    struct RTINetioAliasList aliasList;
};

extern RTINetioDllExport 
void RTINetioLocatorInfo_print(const struct RTINetioLocatorInfo *me, 
			       const char *desc,
			       int indent);

extern RTINetioDllExport
int RTINetioLocatorInfo_compare(
        const struct RTINetioLocatorInfo *l, 
        const struct RTINetioLocatorInfo *r,
        RTIBool compareAddress);

extern RTINetioDllExport
void RTINetioLocatorInfo_from(struct RTINetioLocatorInfo *me, 
                         NDDS_Transport_ClassId_t        transportIn,
                         const NDDS_Transport_Address_t *addressIn,
                         NDDS_Transport_Port_t           portIn,
                         int transport_priorityIn,
                         const char* stringAliasListIn);


#define RTI_NETIO_LOCATOR_INFO_DEFAULT {        \
    RTI_NETIO_LOCATOR_INVALID, /* Locator */    \
    NDDS_TRANSPORT_PRIORITY_DEFAULT, /* transport priority */  \
    RTI_NETIO_ALIAS_LIST_DEFAULT /* aliasList */ }


#define RTI_NETIO_LOCATOR_INFO_INTRA {         \
    { NDDS_TRANSPORT_CLASSID_INTRA,         \
      RTI_NETIO_ADDRESS_INVALID, NULL, 0, 0, {0}, 0 }, \
    NDDS_TRANSPORT_PRIORITY_DEFAULT, /* transport priority */  \
    RTI_NETIO_ALIAS_LIST_INTRA /* aliasList */ }


#define RTI_NETIO_LOCATOR_INFO_SHMEM {        \
    { NDDS_TRANSPORT_CLASSID_SHMEM, \
      RTI_NETIO_ADDRESS_INVALID, NULL, 0, 0, {0}, 0 }, \
    NDDS_TRANSPORT_PRIORITY_DEFAULT, /* transport priority */  \
    RTI_NETIO_ALIAS_LIST_SHMEM /* aliasList */ }


#define RTI_NETIO_LOCATOR_INFO_UDPv4 {        \
    { NDDS_TRANSPORT_CLASSID_UDPv4, \
      RTI_NETIO_ADDRESS_INVALID, NULL, 0, 0, {0}, 0 }, \
    NDDS_TRANSPORT_PRIORITY_DEFAULT, /* transport priority */  \
    RTI_NETIO_ALIAS_LIST_UDPv4 /* aliasList */ }


#define RTI_NETIO_LOCATOR_INFO_UDPv4_WAN {        \
    { NDDS_TRANSPORT_CLASSID_UDPv4_WAN, \
      RTI_NETIO_ADDRESS_INVALID, NULL, 0, 0, {0}, 0 }, \
    NDDS_TRANSPORT_PRIORITY_DEFAULT, /* transport priority */  \
    RTI_NETIO_ALIAS_LIST_UDPv4_WAN /* aliasList */ }


#define RTI_NETIO_LOCATOR_INFO_UDPv6 {        \
    { NDDS_TRANSPORT_CLASSID_UDPv6, \
      RTI_NETIO_ADDRESS_INVALID, NULL, 0, 0, {0}, 0 }, \
    NDDS_TRANSPORT_PRIORITY_DEFAULT, /* transport priority */  \
    RTI_NETIO_ALIAS_LIST_UDPv6 /* aliasList */ }

struct RTINetioMessage {
    NDDS_Transport_Message_t message;
    struct RTINtpTime timestamp;
    struct NDDS_Transport_Context_t transportContext;
};


#define RTI_NETIO_MESSAGE_INVALID  { \
    NDDS_TRANSPORT_MESSAGE_INVALID, \
    RTI_NTP_TIME_ZERO, \
    NDDS_TRANSPORT_CONTEXT_INVALID \
}


struct RTINetioCapArguments {
    struct RTINetioCapManager *manager;
    struct RTINetioCapTransportGatherBuffer rtpsBuffer;
    struct RTINetioCapTransportGatherBuffer rtpsDecodedBuffer;
    struct RTINetioCapTransportGatherBuffer rtpsDecodedSubmessagesBuffer;
};


#define RTINetioCapArguments_INITIALIZER { \
    NULL, \
    RTI_NETIO_CAP_TRANSPORT_GATHER_BUFFER_INITIALIZER, \
    RTI_NETIO_CAP_TRANSPORT_GATHER_BUFFER_INITIALIZER, \
    RTI_NETIO_CAP_TRANSPORT_GATHER_BUFFER_INITIALIZER }

struct RTINetioTransportInfo {
   NDDS_Transport_ClassId_t classid;
   RTI_INT32 messageSizeMax;
};

struct RTINetioConcurrency {
    struct REDAExclusiveArea *configuratorTableEa;
    struct REDAExclusiveArea *senderTableEa;
    struct REDAExclusiveArea *receiverTableEa;
};


#define RTINetioConcurrency_INITIALIZER {NULL, NULL, NULL}


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "netio/netio_common_impl.h"

#endif /* netio_common_h */
