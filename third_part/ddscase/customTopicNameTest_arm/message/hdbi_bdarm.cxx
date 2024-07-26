

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from hdbi_bdarm.idl
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "hdbi_bdarm.hpp"
#include "hdbi_bdarmPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- HDBI_BdArm_Set_struct: 

HDBI_BdArm_Set_struct::HDBI_BdArm_Set_struct() :
    m_VehicleUnlock_Set_ (0) ,
    m_ReturnPYnlock_Set_ (0)  {
}   

HDBI_BdArm_Set_struct::HDBI_BdArm_Set_struct (
    uint8_t VehicleUnlock_Set,
    uint8_t ReturnPYnlock_Set)
    :
        m_VehicleUnlock_Set_( VehicleUnlock_Set ),
        m_ReturnPYnlock_Set_( ReturnPYnlock_Set ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
HDBI_BdArm_Set_struct::HDBI_BdArm_Set_struct(HDBI_BdArm_Set_struct&& other_) OMG_NOEXCEPT  :m_VehicleUnlock_Set_ (std::move(other_.m_VehicleUnlock_Set_))
,
m_ReturnPYnlock_Set_ (std::move(other_.m_ReturnPYnlock_Set_))
{
} 

HDBI_BdArm_Set_struct& HDBI_BdArm_Set_struct::operator=(HDBI_BdArm_Set_struct&&  other_) OMG_NOEXCEPT {
    HDBI_BdArm_Set_struct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void HDBI_BdArm_Set_struct::swap(HDBI_BdArm_Set_struct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_VehicleUnlock_Set_, other_.m_VehicleUnlock_Set_);
    swap(m_ReturnPYnlock_Set_, other_.m_ReturnPYnlock_Set_);
}  

bool HDBI_BdArm_Set_struct::operator == (const HDBI_BdArm_Set_struct& other_) const {
    if (m_VehicleUnlock_Set_ != other_.m_VehicleUnlock_Set_) {
        return false;
    }
    if (m_ReturnPYnlock_Set_ != other_.m_ReturnPYnlock_Set_) {
        return false;
    }
    return true;
}
bool HDBI_BdArm_Set_struct::operator != (const HDBI_BdArm_Set_struct& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const HDBI_BdArm_Set_struct& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "VehicleUnlock_Set: " << (int)sample.VehicleUnlock_Set() <<", ";
    o << "ReturnPYnlock_Set: " << (int)sample.ReturnPYnlock_Set()  ;
    o <<"]";
    return o;
}

// ---- HDBM_BdArm_Rsp_struct: 

HDBM_BdArm_Rsp_struct::HDBM_BdArm_Rsp_struct() :
    m_VehicleUnlock_Rsp_ (0) ,
    m_ReturnPYnlock_Rsp_ (0)  {
}   

HDBM_BdArm_Rsp_struct::HDBM_BdArm_Rsp_struct (
    uint8_t VehicleUnlock_Rsp,
    uint8_t ReturnPYnlock_Rsp)
    :
        m_VehicleUnlock_Rsp_( VehicleUnlock_Rsp ),
        m_ReturnPYnlock_Rsp_( ReturnPYnlock_Rsp ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
HDBM_BdArm_Rsp_struct::HDBM_BdArm_Rsp_struct(HDBM_BdArm_Rsp_struct&& other_) OMG_NOEXCEPT  :m_VehicleUnlock_Rsp_ (std::move(other_.m_VehicleUnlock_Rsp_))
,
m_ReturnPYnlock_Rsp_ (std::move(other_.m_ReturnPYnlock_Rsp_))
{
} 

HDBM_BdArm_Rsp_struct& HDBM_BdArm_Rsp_struct::operator=(HDBM_BdArm_Rsp_struct&&  other_) OMG_NOEXCEPT {
    HDBM_BdArm_Rsp_struct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void HDBM_BdArm_Rsp_struct::swap(HDBM_BdArm_Rsp_struct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_VehicleUnlock_Rsp_, other_.m_VehicleUnlock_Rsp_);
    swap(m_ReturnPYnlock_Rsp_, other_.m_ReturnPYnlock_Rsp_);
}  

bool HDBM_BdArm_Rsp_struct::operator == (const HDBM_BdArm_Rsp_struct& other_) const {
    if (m_VehicleUnlock_Rsp_ != other_.m_VehicleUnlock_Rsp_) {
        return false;
    }
    if (m_ReturnPYnlock_Rsp_ != other_.m_ReturnPYnlock_Rsp_) {
        return false;
    }
    return true;
}
bool HDBM_BdArm_Rsp_struct::operator != (const HDBM_BdArm_Rsp_struct& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const HDBM_BdArm_Rsp_struct& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "VehicleUnlock_Rsp: " << (int)sample.VehicleUnlock_Rsp() <<", ";
    o << "ReturnPYnlock_Rsp: " << (int)sample.ReturnPYnlock_Rsp()  ;
    o <<"]";
    return o;
}

// ---- HDBI_BdArm_Act_struct: 

HDBI_BdArm_Act_struct::HDBI_BdArm_Act_struct() :
    m_CenterLck_Act_ (0)  {
}   

HDBI_BdArm_Act_struct::HDBI_BdArm_Act_struct (
    uint8_t CenterLck_Act)
    :
        m_CenterLck_Act_( CenterLck_Act ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
HDBI_BdArm_Act_struct::HDBI_BdArm_Act_struct(HDBI_BdArm_Act_struct&& other_) OMG_NOEXCEPT  :m_CenterLck_Act_ (std::move(other_.m_CenterLck_Act_))
{
} 

HDBI_BdArm_Act_struct& HDBI_BdArm_Act_struct::operator=(HDBI_BdArm_Act_struct&&  other_) OMG_NOEXCEPT {
    HDBI_BdArm_Act_struct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void HDBI_BdArm_Act_struct::swap(HDBI_BdArm_Act_struct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_CenterLck_Act_, other_.m_CenterLck_Act_);
}  

bool HDBI_BdArm_Act_struct::operator == (const HDBI_BdArm_Act_struct& other_) const {
    if (m_CenterLck_Act_ != other_.m_CenterLck_Act_) {
        return false;
    }
    return true;
}
bool HDBI_BdArm_Act_struct::operator != (const HDBI_BdArm_Act_struct& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const HDBI_BdArm_Act_struct& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "CenterLck_Act: " << (int)sample.CenterLck_Act()  ;
    o <<"]";
    return o;
}

// ---- HDBM_BdArm_St_struct: 

HDBM_BdArm_St_struct::HDBM_BdArm_St_struct() :
    m_CenterLck_St_ (0) ,
    m_BodyBglAlarm_St_ (0) ,
    m_ExLckReq_St_ (0)  {
}   

HDBM_BdArm_St_struct::HDBM_BdArm_St_struct (
    uint8_t CenterLck_St,
    uint8_t BodyBglAlarm_St,
    uint8_t ExLckReq_St)
    :
        m_CenterLck_St_( CenterLck_St ),
        m_BodyBglAlarm_St_( BodyBglAlarm_St ),
        m_ExLckReq_St_( ExLckReq_St ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
HDBM_BdArm_St_struct::HDBM_BdArm_St_struct(HDBM_BdArm_St_struct&& other_) OMG_NOEXCEPT  :m_CenterLck_St_ (std::move(other_.m_CenterLck_St_))
,
m_BodyBglAlarm_St_ (std::move(other_.m_BodyBglAlarm_St_))
,
m_ExLckReq_St_ (std::move(other_.m_ExLckReq_St_))
{
} 

HDBM_BdArm_St_struct& HDBM_BdArm_St_struct::operator=(HDBM_BdArm_St_struct&&  other_) OMG_NOEXCEPT {
    HDBM_BdArm_St_struct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void HDBM_BdArm_St_struct::swap(HDBM_BdArm_St_struct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_CenterLck_St_, other_.m_CenterLck_St_);
    swap(m_BodyBglAlarm_St_, other_.m_BodyBglAlarm_St_);
    swap(m_ExLckReq_St_, other_.m_ExLckReq_St_);
}  

bool HDBM_BdArm_St_struct::operator == (const HDBM_BdArm_St_struct& other_) const {
    if (m_CenterLck_St_ != other_.m_CenterLck_St_) {
        return false;
    }
    if (m_BodyBglAlarm_St_ != other_.m_BodyBglAlarm_St_) {
        return false;
    }
    if (m_ExLckReq_St_ != other_.m_ExLckReq_St_) {
        return false;
    }
    return true;
}
bool HDBM_BdArm_St_struct::operator != (const HDBM_BdArm_St_struct& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const HDBM_BdArm_St_struct& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "CenterLck_St: " << (int)sample.CenterLck_St() <<", ";
    o << "BodyBglAlarm_St: " << (int)sample.BodyBglAlarm_St() <<", ";
    o << "ExLckReq_St: " << (int)sample.ExLckReq_St()  ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< HDBI_BdArm_Set_struct > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member HDBI_BdArm_Set_struct_g_tc_members[2]=
                {

                    {
                        (char *)"VehicleUnlock_Set",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ReturnPYnlock_Set",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode HDBI_BdArm_Set_struct_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"HDBI_BdArm_Set_struct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        HDBI_BdArm_Set_struct_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for HDBI_BdArm_Set_struct*/

                if (is_initialized) {
                    return &HDBI_BdArm_Set_struct_g_tc;
                }

                HDBI_BdArm_Set_struct_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                HDBI_BdArm_Set_struct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                HDBI_BdArm_Set_struct_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                /* Initialize the values for member annotations. */
                HDBI_BdArm_Set_struct_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                HDBI_BdArm_Set_struct_g_tc_members[0]._annotations._defaultValue._u.octet_value = 0;
                HDBI_BdArm_Set_struct_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                HDBI_BdArm_Set_struct_g_tc_members[0]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                HDBI_BdArm_Set_struct_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                HDBI_BdArm_Set_struct_g_tc_members[0]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                HDBI_BdArm_Set_struct_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                HDBI_BdArm_Set_struct_g_tc_members[1]._annotations._defaultValue._u.octet_value = 0;
                HDBI_BdArm_Set_struct_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                HDBI_BdArm_Set_struct_g_tc_members[1]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                HDBI_BdArm_Set_struct_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                HDBI_BdArm_Set_struct_g_tc_members[1]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                HDBI_BdArm_Set_struct_g_tc._data._sampleAccessInfo = sample_access_info();
                HDBI_BdArm_Set_struct_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &HDBI_BdArm_Set_struct_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                HDBI_BdArm_Set_struct *sample;

                static RTIXCdrMemberAccessInfo HDBI_BdArm_Set_struct_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo HDBI_BdArm_Set_struct_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &HDBI_BdArm_Set_struct_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    HDBI_BdArm_Set_struct);
                if (sample == NULL) {
                    return NULL;
                }

                HDBI_BdArm_Set_struct_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->VehicleUnlock_Set() - (char *)sample);

                HDBI_BdArm_Set_struct_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ReturnPYnlock_Set() - (char *)sample);

                HDBI_BdArm_Set_struct_g_sampleAccessInfo.memberAccessInfos = 
                HDBI_BdArm_Set_struct_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(HDBI_BdArm_Set_struct);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        HDBI_BdArm_Set_struct_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        HDBI_BdArm_Set_struct_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                HDBI_BdArm_Set_struct_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                HDBI_BdArm_Set_struct_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< HDBI_BdArm_Set_struct >;

                HDBI_BdArm_Set_struct_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &HDBI_BdArm_Set_struct_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin HDBI_BdArm_Set_struct_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &HDBI_BdArm_Set_struct_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< HDBI_BdArm_Set_struct >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< HDBI_BdArm_Set_struct >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< HDBM_BdArm_Rsp_struct > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member HDBM_BdArm_Rsp_struct_g_tc_members[2]=
                {

                    {
                        (char *)"VehicleUnlock_Rsp",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ReturnPYnlock_Rsp",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode HDBM_BdArm_Rsp_struct_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"HDBM_BdArm_Rsp_struct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        HDBM_BdArm_Rsp_struct_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for HDBM_BdArm_Rsp_struct*/

                if (is_initialized) {
                    return &HDBM_BdArm_Rsp_struct_g_tc;
                }

                HDBM_BdArm_Rsp_struct_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                HDBM_BdArm_Rsp_struct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                HDBM_BdArm_Rsp_struct_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                /* Initialize the values for member annotations. */
                HDBM_BdArm_Rsp_struct_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_Rsp_struct_g_tc_members[0]._annotations._defaultValue._u.octet_value = 0;
                HDBM_BdArm_Rsp_struct_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_Rsp_struct_g_tc_members[0]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                HDBM_BdArm_Rsp_struct_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_Rsp_struct_g_tc_members[0]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                HDBM_BdArm_Rsp_struct_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_Rsp_struct_g_tc_members[1]._annotations._defaultValue._u.octet_value = 0;
                HDBM_BdArm_Rsp_struct_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_Rsp_struct_g_tc_members[1]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                HDBM_BdArm_Rsp_struct_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_Rsp_struct_g_tc_members[1]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                HDBM_BdArm_Rsp_struct_g_tc._data._sampleAccessInfo = sample_access_info();
                HDBM_BdArm_Rsp_struct_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &HDBM_BdArm_Rsp_struct_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                HDBM_BdArm_Rsp_struct *sample;

                static RTIXCdrMemberAccessInfo HDBM_BdArm_Rsp_struct_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo HDBM_BdArm_Rsp_struct_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &HDBM_BdArm_Rsp_struct_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    HDBM_BdArm_Rsp_struct);
                if (sample == NULL) {
                    return NULL;
                }

                HDBM_BdArm_Rsp_struct_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->VehicleUnlock_Rsp() - (char *)sample);

                HDBM_BdArm_Rsp_struct_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ReturnPYnlock_Rsp() - (char *)sample);

                HDBM_BdArm_Rsp_struct_g_sampleAccessInfo.memberAccessInfos = 
                HDBM_BdArm_Rsp_struct_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(HDBM_BdArm_Rsp_struct);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        HDBM_BdArm_Rsp_struct_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        HDBM_BdArm_Rsp_struct_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                HDBM_BdArm_Rsp_struct_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                HDBM_BdArm_Rsp_struct_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< HDBM_BdArm_Rsp_struct >;

                HDBM_BdArm_Rsp_struct_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &HDBM_BdArm_Rsp_struct_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin HDBM_BdArm_Rsp_struct_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &HDBM_BdArm_Rsp_struct_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< HDBM_BdArm_Rsp_struct >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< HDBM_BdArm_Rsp_struct >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< HDBI_BdArm_Act_struct > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member HDBI_BdArm_Act_struct_g_tc_members[1]=
                {

                    {
                        (char *)"CenterLck_Act",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode HDBI_BdArm_Act_struct_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"HDBI_BdArm_Act_struct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        HDBI_BdArm_Act_struct_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for HDBI_BdArm_Act_struct*/

                if (is_initialized) {
                    return &HDBI_BdArm_Act_struct_g_tc;
                }

                HDBI_BdArm_Act_struct_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                HDBI_BdArm_Act_struct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                /* Initialize the values for member annotations. */
                HDBI_BdArm_Act_struct_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                HDBI_BdArm_Act_struct_g_tc_members[0]._annotations._defaultValue._u.octet_value = 0;
                HDBI_BdArm_Act_struct_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                HDBI_BdArm_Act_struct_g_tc_members[0]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                HDBI_BdArm_Act_struct_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                HDBI_BdArm_Act_struct_g_tc_members[0]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                HDBI_BdArm_Act_struct_g_tc._data._sampleAccessInfo = sample_access_info();
                HDBI_BdArm_Act_struct_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &HDBI_BdArm_Act_struct_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                HDBI_BdArm_Act_struct *sample;

                static RTIXCdrMemberAccessInfo HDBI_BdArm_Act_struct_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo HDBI_BdArm_Act_struct_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &HDBI_BdArm_Act_struct_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    HDBI_BdArm_Act_struct);
                if (sample == NULL) {
                    return NULL;
                }

                HDBI_BdArm_Act_struct_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CenterLck_Act() - (char *)sample);

                HDBI_BdArm_Act_struct_g_sampleAccessInfo.memberAccessInfos = 
                HDBI_BdArm_Act_struct_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(HDBI_BdArm_Act_struct);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        HDBI_BdArm_Act_struct_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        HDBI_BdArm_Act_struct_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                HDBI_BdArm_Act_struct_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                HDBI_BdArm_Act_struct_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< HDBI_BdArm_Act_struct >;

                HDBI_BdArm_Act_struct_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &HDBI_BdArm_Act_struct_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin HDBI_BdArm_Act_struct_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &HDBI_BdArm_Act_struct_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< HDBI_BdArm_Act_struct >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< HDBI_BdArm_Act_struct >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< HDBM_BdArm_St_struct > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member HDBM_BdArm_St_struct_g_tc_members[3]=
                {

                    {
                        (char *)"CenterLck_St",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"BodyBglAlarm_St",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ExLckReq_St",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode HDBM_BdArm_St_struct_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"HDBM_BdArm_St_struct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        HDBM_BdArm_St_struct_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for HDBM_BdArm_St_struct*/

                if (is_initialized) {
                    return &HDBM_BdArm_St_struct_g_tc;
                }

                HDBM_BdArm_St_struct_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                HDBM_BdArm_St_struct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                HDBM_BdArm_St_struct_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                HDBM_BdArm_St_struct_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                /* Initialize the values for member annotations. */
                HDBM_BdArm_St_struct_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_St_struct_g_tc_members[0]._annotations._defaultValue._u.octet_value = 0;
                HDBM_BdArm_St_struct_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_St_struct_g_tc_members[0]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                HDBM_BdArm_St_struct_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_St_struct_g_tc_members[0]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                HDBM_BdArm_St_struct_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_St_struct_g_tc_members[1]._annotations._defaultValue._u.octet_value = 0;
                HDBM_BdArm_St_struct_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_St_struct_g_tc_members[1]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                HDBM_BdArm_St_struct_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_St_struct_g_tc_members[1]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                HDBM_BdArm_St_struct_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_St_struct_g_tc_members[2]._annotations._defaultValue._u.octet_value = 0;
                HDBM_BdArm_St_struct_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_St_struct_g_tc_members[2]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                HDBM_BdArm_St_struct_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                HDBM_BdArm_St_struct_g_tc_members[2]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                HDBM_BdArm_St_struct_g_tc._data._sampleAccessInfo = sample_access_info();
                HDBM_BdArm_St_struct_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &HDBM_BdArm_St_struct_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                HDBM_BdArm_St_struct *sample;

                static RTIXCdrMemberAccessInfo HDBM_BdArm_St_struct_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo HDBM_BdArm_St_struct_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &HDBM_BdArm_St_struct_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    HDBM_BdArm_St_struct);
                if (sample == NULL) {
                    return NULL;
                }

                HDBM_BdArm_St_struct_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CenterLck_St() - (char *)sample);

                HDBM_BdArm_St_struct_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->BodyBglAlarm_St() - (char *)sample);

                HDBM_BdArm_St_struct_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ExLckReq_St() - (char *)sample);

                HDBM_BdArm_St_struct_g_sampleAccessInfo.memberAccessInfos = 
                HDBM_BdArm_St_struct_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(HDBM_BdArm_St_struct);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        HDBM_BdArm_St_struct_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        HDBM_BdArm_St_struct_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                HDBM_BdArm_St_struct_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                HDBM_BdArm_St_struct_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< HDBM_BdArm_St_struct >;

                HDBM_BdArm_St_struct_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &HDBM_BdArm_St_struct_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin HDBM_BdArm_St_struct_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &HDBM_BdArm_St_struct_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< HDBM_BdArm_St_struct >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< HDBM_BdArm_St_struct >::get())));
        }

    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< HDBI_BdArm_Set_struct >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                HDBI_BdArm_Set_structPlugin_new,
                HDBI_BdArm_Set_structPlugin_delete);
        }

        std::vector<char>& topic_type_support< HDBI_BdArm_Set_struct >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const HDBI_BdArm_Set_struct& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = HDBI_BdArm_Set_structPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = HDBI_BdArm_Set_structPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< HDBI_BdArm_Set_struct >::from_cdr_buffer(HDBI_BdArm_Set_struct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = HDBI_BdArm_Set_structPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create HDBI_BdArm_Set_struct from cdr buffer");
        }

        void topic_type_support< HDBI_BdArm_Set_struct >::reset_sample(HDBI_BdArm_Set_struct& sample) 
        {
            sample.VehicleUnlock_Set(0);
            sample.ReturnPYnlock_Set(0);
        }

        void topic_type_support< HDBI_BdArm_Set_struct >::allocate_sample(HDBI_BdArm_Set_struct& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< HDBM_BdArm_Rsp_struct >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                HDBM_BdArm_Rsp_structPlugin_new,
                HDBM_BdArm_Rsp_structPlugin_delete);
        }

        std::vector<char>& topic_type_support< HDBM_BdArm_Rsp_struct >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const HDBM_BdArm_Rsp_struct& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = HDBM_BdArm_Rsp_structPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = HDBM_BdArm_Rsp_structPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< HDBM_BdArm_Rsp_struct >::from_cdr_buffer(HDBM_BdArm_Rsp_struct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = HDBM_BdArm_Rsp_structPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create HDBM_BdArm_Rsp_struct from cdr buffer");
        }

        void topic_type_support< HDBM_BdArm_Rsp_struct >::reset_sample(HDBM_BdArm_Rsp_struct& sample) 
        {
            sample.VehicleUnlock_Rsp(0);
            sample.ReturnPYnlock_Rsp(0);
        }

        void topic_type_support< HDBM_BdArm_Rsp_struct >::allocate_sample(HDBM_BdArm_Rsp_struct& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< HDBI_BdArm_Act_struct >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                HDBI_BdArm_Act_structPlugin_new,
                HDBI_BdArm_Act_structPlugin_delete);
        }

        std::vector<char>& topic_type_support< HDBI_BdArm_Act_struct >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const HDBI_BdArm_Act_struct& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = HDBI_BdArm_Act_structPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = HDBI_BdArm_Act_structPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< HDBI_BdArm_Act_struct >::from_cdr_buffer(HDBI_BdArm_Act_struct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = HDBI_BdArm_Act_structPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create HDBI_BdArm_Act_struct from cdr buffer");
        }

        void topic_type_support< HDBI_BdArm_Act_struct >::reset_sample(HDBI_BdArm_Act_struct& sample) 
        {
            sample.CenterLck_Act(0);
        }

        void topic_type_support< HDBI_BdArm_Act_struct >::allocate_sample(HDBI_BdArm_Act_struct& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< HDBM_BdArm_St_struct >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                HDBM_BdArm_St_structPlugin_new,
                HDBM_BdArm_St_structPlugin_delete);
        }

        std::vector<char>& topic_type_support< HDBM_BdArm_St_struct >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const HDBM_BdArm_St_struct& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = HDBM_BdArm_St_structPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = HDBM_BdArm_St_structPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< HDBM_BdArm_St_struct >::from_cdr_buffer(HDBM_BdArm_St_struct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = HDBM_BdArm_St_structPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create HDBM_BdArm_St_struct from cdr buffer");
        }

        void topic_type_support< HDBM_BdArm_St_struct >::reset_sample(HDBM_BdArm_St_struct& sample) 
        {
            sample.CenterLck_St(0);
            sample.BodyBglAlarm_St(0);
            sample.ExLckReq_St(0);
        }

        void topic_type_support< HDBM_BdArm_St_struct >::allocate_sample(HDBM_BdArm_St_struct& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

    }
}  

