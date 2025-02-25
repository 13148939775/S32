/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_cpp_builtin.h    generated by: makeheader    Wed Mar  9 22:40:04 2022
 *
 *		built from:	builtin.ifcxx
 */

#ifndef dds_cpp_builtin_h
#define dds_cpp_builtin_h


  #ifndef dds_cpp_dll_h
    #include "dds_cpp/dds_cpp_dll.h"
  #endif
  #ifndef dds_c_builtin_h
    #include "dds_c/dds_c_builtin.h"
  #endif
  #ifndef dds_cpp_data_h
    #include "dds_cpp/dds_cpp_data.h"
  #endif


DDS_TYPESUPPORT_CPP(DDSParticipantBuiltinTopicDataTypeSupport, DDS_ParticipantBuiltinTopicData);


DDS_DATAREADER_CPP(DDSParticipantBuiltinTopicDataDataReader, DDS_ParticipantBuiltinTopicDataSeq, DDS_ParticipantBuiltinTopicData);


DDS_TYPESUPPORT_CPP(DDSTopicBuiltinTopicDataTypeSupport, DDS_TopicBuiltinTopicData);


DDS_DATAREADER_CPP(DDSTopicBuiltinTopicDataDataReader, DDS_TopicBuiltinTopicDataSeq, DDS_TopicBuiltinTopicData);


DDS_TYPESUPPORT_CPP(DDSPublicationBuiltinTopicDataTypeSupport, DDS_PublicationBuiltinTopicData);


DDS_DATAREADER_CPP(DDSPublicationBuiltinTopicDataDataReader, DDS_PublicationBuiltinTopicDataSeq, DDS_PublicationBuiltinTopicData);


DDS_TYPESUPPORT_CPP(DDSSubscriptionBuiltinTopicDataTypeSupport, DDS_SubscriptionBuiltinTopicData);


DDS_DATAREADER_CPP(DDSSubscriptionBuiltinTopicDataDataReader, DDS_SubscriptionBuiltinTopicDataSeq, DDS_SubscriptionBuiltinTopicData);


DDS_TYPESUPPORT_CPP(DDSServiceRequestTypeSupport, DDS_ServiceRequest);


DDS_DATAREADER_CPP(DDSServiceRequestDataReader, DDS_ServiceRequestSeq, DDS_ServiceRequest);


DDS_DATAWRITER_CPP(DDSServiceRequestDataWriter, DDS_ServiceRequest);

#endif /* dds_cpp_builtin_h */
