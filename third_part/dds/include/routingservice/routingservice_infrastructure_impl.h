/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)routingservice_infrastructure_impl.h    generated by: makeheader    Wed Mar  9 22:43:15 2022
 *
 *		built from:	infrastructure_impl.ifc
 */

#ifndef routingservice_infrastructure_impl_h
#define routingservice_infrastructure_impl_h



  #ifndef routingservice_dll_h
    #include "routingservice/routingservice_dll.h"
  #endif
  #ifndef routingservice_infrastructure_h
    #include "routingservice/routingservice_infrastructure.h"
  #endif
  #ifdef __cplusplus
      extern "C" {
  #endif
  


struct RTI_RoutingServiceError {
    int error_code;
    int nativeCode;
    char message[RTI_ROUTING_SERVICE_ERROR_MAX_LENGTH+1];
};


struct RTI_RoutingServiceEnvironmentImpl {

    /*i @brief Error */
    struct RTI_RoutingServiceError error;

    void * _jniGlobal;

    /*i @brief Reserved (e.g. for DDS-specific stuff) */
    void * _reserved;
    /*i @brief Current service verbosity */
    RTI_RoutingServiceVerbosity verbosity;
};



#define RTI_RoutingServiceEnvironment_clearError(env)   \
    (env).error.error_code = RTI_ROUTING_SERVICE_OK;    \
    (env).error.message[0] = 0;                         \
    (env).error.nativeCode = 0;


extern ROUTERDllExport
DDS_Boolean RTI_RoutingServiceProperties_assert_w_override(
        struct RTI_RoutingServiceProperties *self,
        const char *name,
        const char *value,
        RTIBool override_value);


  #ifdef __cplusplus
    }	/* extern "C" */
  #endif

#endif /* routingservice_infrastructure_impl_h */
