

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DDSServiceInterface.idl
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "DDSServiceInterface.hpp"
#include "DDSServiceInterfacePlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- DDSCommandSet_struct: 

DDSCommandSet_struct::DDSCommandSet_struct() :
    m_code_ (0) ,
    m_subcode_ (0)  {
        ::rti::core::fill_array< char >( m_ctrSource_, 0);
        ::rti::core::fill_array< char >( m_commBuffer_, 0);
}   

DDSCommandSet_struct::DDSCommandSet_struct (
    uint16_t code,
    uint16_t subcode,
    const ::dds::core::array< char, 64L>& ctrSource,
    const ::dds::core::array< char, 256L>& commBuffer)
    :
        m_code_( code ),
        m_subcode_( subcode ),
        m_ctrSource_( ctrSource ),
        m_commBuffer_( commBuffer ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
DDSCommandSet_struct::DDSCommandSet_struct(DDSCommandSet_struct&& other_) OMG_NOEXCEPT  :m_code_ (std::move(other_.m_code_))
,
m_subcode_ (std::move(other_.m_subcode_))
,
m_ctrSource_ (std::move(other_.m_ctrSource_))
,
m_commBuffer_ (std::move(other_.m_commBuffer_))
{
} 

DDSCommandSet_struct& DDSCommandSet_struct::operator=(DDSCommandSet_struct&&  other_) OMG_NOEXCEPT {
    DDSCommandSet_struct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void DDSCommandSet_struct::swap(DDSCommandSet_struct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_code_, other_.m_code_);
    swap(m_subcode_, other_.m_subcode_);
    swap(m_ctrSource_, other_.m_ctrSource_);
    swap(m_commBuffer_, other_.m_commBuffer_);
}  

bool DDSCommandSet_struct::operator == (const DDSCommandSet_struct& other_) const {
    if (m_code_ != other_.m_code_) {
        return false;
    }
    if (m_subcode_ != other_.m_subcode_) {
        return false;
    }
    if (m_ctrSource_ != other_.m_ctrSource_) {
        return false;
    }
    if (m_commBuffer_ != other_.m_commBuffer_) {
        return false;
    }
    return true;
}
bool DDSCommandSet_struct::operator != (const DDSCommandSet_struct& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const DDSCommandSet_struct& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "code: " << sample.code()<<", ";
    o << "subcode: " << sample.subcode()<<", ";
    o << "ctrSource: " << sample.ctrSource()<<", ";
    o << "commBuffer: " << sample.commBuffer() ;
    o <<"]";
    return o;
}

// ---- DDSCommandRsp_struct: 

DDSCommandRsp_struct::DDSCommandRsp_struct() :
    m_code_ (0) ,
    m_subcode_ (0)  {
        ::rti::core::fill_array< char >( m_ctrSource_, 0);
        ::rti::core::fill_array< char >( m_commBuffer_, 0);
}   

DDSCommandRsp_struct::DDSCommandRsp_struct (
    uint16_t code,
    uint16_t subcode,
    const ::dds::core::array< char, 64L>& ctrSource,
    const ::dds::core::array< char, 256L>& commBuffer)
    :
        m_code_( code ),
        m_subcode_( subcode ),
        m_ctrSource_( ctrSource ),
        m_commBuffer_( commBuffer ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
DDSCommandRsp_struct::DDSCommandRsp_struct(DDSCommandRsp_struct&& other_) OMG_NOEXCEPT  :m_code_ (std::move(other_.m_code_))
,
m_subcode_ (std::move(other_.m_subcode_))
,
m_ctrSource_ (std::move(other_.m_ctrSource_))
,
m_commBuffer_ (std::move(other_.m_commBuffer_))
{
} 

DDSCommandRsp_struct& DDSCommandRsp_struct::operator=(DDSCommandRsp_struct&&  other_) OMG_NOEXCEPT {
    DDSCommandRsp_struct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void DDSCommandRsp_struct::swap(DDSCommandRsp_struct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_code_, other_.m_code_);
    swap(m_subcode_, other_.m_subcode_);
    swap(m_ctrSource_, other_.m_ctrSource_);
    swap(m_commBuffer_, other_.m_commBuffer_);
}  

bool DDSCommandRsp_struct::operator == (const DDSCommandRsp_struct& other_) const {
    if (m_code_ != other_.m_code_) {
        return false;
    }
    if (m_subcode_ != other_.m_subcode_) {
        return false;
    }
    if (m_ctrSource_ != other_.m_ctrSource_) {
        return false;
    }
    if (m_commBuffer_ != other_.m_commBuffer_) {
        return false;
    }
    return true;
}
bool DDSCommandRsp_struct::operator != (const DDSCommandRsp_struct& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const DDSCommandRsp_struct& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "code: " << sample.code()<<", ";
    o << "subcode: " << sample.subcode()<<", ";
    o << "ctrSource: " << sample.ctrSource()<<", ";
    o << "commBuffer: " << sample.commBuffer() ;
    o <<"]";
    return o;
}

// ---- DDSCommandAct_struct: 

DDSCommandAct_struct::DDSCommandAct_struct() :
    m_code_ (0) ,
    m_subcode_ (0)  {
        ::rti::core::fill_array< char >( m_ctrSource_, 0);
        ::rti::core::fill_array< char >( m_commBuffer_, 0);
}   

DDSCommandAct_struct::DDSCommandAct_struct (
    uint16_t code,
    uint16_t subcode,
    const ::dds::core::array< char, 64L>& ctrSource,
    const ::dds::core::array< char, 256L>& commBuffer)
    :
        m_code_( code ),
        m_subcode_( subcode ),
        m_ctrSource_( ctrSource ),
        m_commBuffer_( commBuffer ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
DDSCommandAct_struct::DDSCommandAct_struct(DDSCommandAct_struct&& other_) OMG_NOEXCEPT  :m_code_ (std::move(other_.m_code_))
,
m_subcode_ (std::move(other_.m_subcode_))
,
m_ctrSource_ (std::move(other_.m_ctrSource_))
,
m_commBuffer_ (std::move(other_.m_commBuffer_))
{
} 

DDSCommandAct_struct& DDSCommandAct_struct::operator=(DDSCommandAct_struct&&  other_) OMG_NOEXCEPT {
    DDSCommandAct_struct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void DDSCommandAct_struct::swap(DDSCommandAct_struct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_code_, other_.m_code_);
    swap(m_subcode_, other_.m_subcode_);
    swap(m_ctrSource_, other_.m_ctrSource_);
    swap(m_commBuffer_, other_.m_commBuffer_);
}  

bool DDSCommandAct_struct::operator == (const DDSCommandAct_struct& other_) const {
    if (m_code_ != other_.m_code_) {
        return false;
    }
    if (m_subcode_ != other_.m_subcode_) {
        return false;
    }
    if (m_ctrSource_ != other_.m_ctrSource_) {
        return false;
    }
    if (m_commBuffer_ != other_.m_commBuffer_) {
        return false;
    }
    return true;
}
bool DDSCommandAct_struct::operator != (const DDSCommandAct_struct& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const DDSCommandAct_struct& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "code: " << sample.code()<<", ";
    o << "subcode: " << sample.subcode()<<", ";
    o << "ctrSource: " << sample.ctrSource()<<", ";
    o << "commBuffer: " << sample.commBuffer() ;
    o <<"]";
    return o;
}

// ---- DDSCommandSt_struct: 

DDSCommandSt_struct::DDSCommandSt_struct() :
    m_code_ (0) ,
    m_subcode_ (0)  {
        ::rti::core::fill_array< char >( m_ctrSource_, 0);
        ::rti::core::fill_array< char >( m_commBuffer_, 0);
}   

DDSCommandSt_struct::DDSCommandSt_struct (
    uint16_t code,
    uint16_t subcode,
    const ::dds::core::array< char, 64L>& ctrSource,
    const ::dds::core::array< char, 256L>& commBuffer)
    :
        m_code_( code ),
        m_subcode_( subcode ),
        m_ctrSource_( ctrSource ),
        m_commBuffer_( commBuffer ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
DDSCommandSt_struct::DDSCommandSt_struct(DDSCommandSt_struct&& other_) OMG_NOEXCEPT  :m_code_ (std::move(other_.m_code_))
,
m_subcode_ (std::move(other_.m_subcode_))
,
m_ctrSource_ (std::move(other_.m_ctrSource_))
,
m_commBuffer_ (std::move(other_.m_commBuffer_))
{
} 

DDSCommandSt_struct& DDSCommandSt_struct::operator=(DDSCommandSt_struct&&  other_) OMG_NOEXCEPT {
    DDSCommandSt_struct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void DDSCommandSt_struct::swap(DDSCommandSt_struct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_code_, other_.m_code_);
    swap(m_subcode_, other_.m_subcode_);
    swap(m_ctrSource_, other_.m_ctrSource_);
    swap(m_commBuffer_, other_.m_commBuffer_);
}  

bool DDSCommandSt_struct::operator == (const DDSCommandSt_struct& other_) const {
    if (m_code_ != other_.m_code_) {
        return false;
    }
    if (m_subcode_ != other_.m_subcode_) {
        return false;
    }
    if (m_ctrSource_ != other_.m_ctrSource_) {
        return false;
    }
    if (m_commBuffer_ != other_.m_commBuffer_) {
        return false;
    }
    return true;
}
bool DDSCommandSt_struct::operator != (const DDSCommandSt_struct& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const DDSCommandSt_struct& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "code: " << sample.code()<<", ";
    o << "subcode: " << sample.subcode()<<", ";
    o << "ctrSource: " << sample.ctrSource()<<", ";
    o << "commBuffer: " << sample.commBuffer() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< DDSCommandSet_struct > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode DDSCommandSet_struct_g_tc_ctrSource_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,64L, NULL,NULL);
                static DDS_TypeCode DDSCommandSet_struct_g_tc_commBuffer_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,256L, NULL,NULL);

                static DDS_TypeCode_Member DDSCommandSet_struct_g_tc_members[4]=
                {

                    {
                        (char *)"code",/* Member name */
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
                        (char *)"subcode",/* Member name */
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
                        (char *)"ctrSource",/* Member name */
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
                    }, 
                    {
                        (char *)"commBuffer",/* Member name */
                        {
                            3,/* Representation ID */
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

                static DDS_TypeCode DDSCommandSet_struct_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DDSCommandSet_struct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        DDSCommandSet_struct_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DDSCommandSet_struct*/

                if (is_initialized) {
                    return &DDSCommandSet_struct_g_tc;
                }

                DDSCommandSet_struct_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                DDSCommandSet_struct_g_tc_ctrSource_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_char;
                DDSCommandSet_struct_g_tc_commBuffer_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_char;
                DDSCommandSet_struct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DDSCommandSet_struct_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DDSCommandSet_struct_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& DDSCommandSet_struct_g_tc_ctrSource_array;
                DDSCommandSet_struct_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& DDSCommandSet_struct_g_tc_commBuffer_array;

                /* Initialize the values for member annotations. */
                DDSCommandSet_struct_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSet_struct_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
                DDSCommandSet_struct_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSet_struct_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                DDSCommandSet_struct_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSet_struct_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                DDSCommandSet_struct_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSet_struct_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0;
                DDSCommandSet_struct_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSet_struct_g_tc_members[1]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                DDSCommandSet_struct_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSet_struct_g_tc_members[1]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                DDSCommandSet_struct_g_tc._data._sampleAccessInfo = sample_access_info();
                DDSCommandSet_struct_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DDSCommandSet_struct_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DDSCommandSet_struct *sample;

                static RTIXCdrMemberAccessInfo DDSCommandSet_struct_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DDSCommandSet_struct_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DDSCommandSet_struct_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DDSCommandSet_struct);
                if (sample == NULL) {
                    return NULL;
                }

                DDSCommandSet_struct_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->code() - (char *)sample);

                DDSCommandSet_struct_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->subcode() - (char *)sample);

                DDSCommandSet_struct_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ctrSource() - (char *)sample);

                DDSCommandSet_struct_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->commBuffer() - (char *)sample);

                DDSCommandSet_struct_g_sampleAccessInfo.memberAccessInfos = 
                DDSCommandSet_struct_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DDSCommandSet_struct);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        DDSCommandSet_struct_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        DDSCommandSet_struct_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DDSCommandSet_struct_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DDSCommandSet_struct_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DDSCommandSet_struct >;

                DDSCommandSet_struct_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DDSCommandSet_struct_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DDSCommandSet_struct_g_typePlugin = 
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

                return &DDSCommandSet_struct_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DDSCommandSet_struct >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DDSCommandSet_struct >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< DDSCommandRsp_struct > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode DDSCommandRsp_struct_g_tc_ctrSource_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,64L, NULL,NULL);
                static DDS_TypeCode DDSCommandRsp_struct_g_tc_commBuffer_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,256L, NULL,NULL);

                static DDS_TypeCode_Member DDSCommandRsp_struct_g_tc_members[4]=
                {

                    {
                        (char *)"code",/* Member name */
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
                        (char *)"subcode",/* Member name */
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
                        (char *)"ctrSource",/* Member name */
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
                    }, 
                    {
                        (char *)"commBuffer",/* Member name */
                        {
                            3,/* Representation ID */
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

                static DDS_TypeCode DDSCommandRsp_struct_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DDSCommandRsp_struct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        DDSCommandRsp_struct_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DDSCommandRsp_struct*/

                if (is_initialized) {
                    return &DDSCommandRsp_struct_g_tc;
                }

                DDSCommandRsp_struct_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                DDSCommandRsp_struct_g_tc_ctrSource_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_char;
                DDSCommandRsp_struct_g_tc_commBuffer_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_char;
                DDSCommandRsp_struct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DDSCommandRsp_struct_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DDSCommandRsp_struct_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& DDSCommandRsp_struct_g_tc_ctrSource_array;
                DDSCommandRsp_struct_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& DDSCommandRsp_struct_g_tc_commBuffer_array;

                /* Initialize the values for member annotations. */
                DDSCommandRsp_struct_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandRsp_struct_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
                DDSCommandRsp_struct_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandRsp_struct_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                DDSCommandRsp_struct_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandRsp_struct_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                DDSCommandRsp_struct_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandRsp_struct_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0;
                DDSCommandRsp_struct_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandRsp_struct_g_tc_members[1]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                DDSCommandRsp_struct_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandRsp_struct_g_tc_members[1]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                DDSCommandRsp_struct_g_tc._data._sampleAccessInfo = sample_access_info();
                DDSCommandRsp_struct_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DDSCommandRsp_struct_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DDSCommandRsp_struct *sample;

                static RTIXCdrMemberAccessInfo DDSCommandRsp_struct_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DDSCommandRsp_struct_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DDSCommandRsp_struct_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DDSCommandRsp_struct);
                if (sample == NULL) {
                    return NULL;
                }

                DDSCommandRsp_struct_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->code() - (char *)sample);

                DDSCommandRsp_struct_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->subcode() - (char *)sample);

                DDSCommandRsp_struct_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ctrSource() - (char *)sample);

                DDSCommandRsp_struct_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->commBuffer() - (char *)sample);

                DDSCommandRsp_struct_g_sampleAccessInfo.memberAccessInfos = 
                DDSCommandRsp_struct_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DDSCommandRsp_struct);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        DDSCommandRsp_struct_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        DDSCommandRsp_struct_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DDSCommandRsp_struct_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DDSCommandRsp_struct_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DDSCommandRsp_struct >;

                DDSCommandRsp_struct_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DDSCommandRsp_struct_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DDSCommandRsp_struct_g_typePlugin = 
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

                return &DDSCommandRsp_struct_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DDSCommandRsp_struct >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DDSCommandRsp_struct >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< DDSCommandAct_struct > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode DDSCommandAct_struct_g_tc_ctrSource_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,64L, NULL,NULL);
                static DDS_TypeCode DDSCommandAct_struct_g_tc_commBuffer_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,256L, NULL,NULL);

                static DDS_TypeCode_Member DDSCommandAct_struct_g_tc_members[4]=
                {

                    {
                        (char *)"code",/* Member name */
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
                        (char *)"subcode",/* Member name */
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
                        (char *)"ctrSource",/* Member name */
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
                    }, 
                    {
                        (char *)"commBuffer",/* Member name */
                        {
                            3,/* Representation ID */
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

                static DDS_TypeCode DDSCommandAct_struct_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DDSCommandAct_struct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        DDSCommandAct_struct_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DDSCommandAct_struct*/

                if (is_initialized) {
                    return &DDSCommandAct_struct_g_tc;
                }

                DDSCommandAct_struct_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                DDSCommandAct_struct_g_tc_ctrSource_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_char;
                DDSCommandAct_struct_g_tc_commBuffer_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_char;
                DDSCommandAct_struct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DDSCommandAct_struct_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DDSCommandAct_struct_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& DDSCommandAct_struct_g_tc_ctrSource_array;
                DDSCommandAct_struct_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& DDSCommandAct_struct_g_tc_commBuffer_array;

                /* Initialize the values for member annotations. */
                DDSCommandAct_struct_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandAct_struct_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
                DDSCommandAct_struct_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandAct_struct_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                DDSCommandAct_struct_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandAct_struct_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                DDSCommandAct_struct_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandAct_struct_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0;
                DDSCommandAct_struct_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandAct_struct_g_tc_members[1]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                DDSCommandAct_struct_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandAct_struct_g_tc_members[1]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                DDSCommandAct_struct_g_tc._data._sampleAccessInfo = sample_access_info();
                DDSCommandAct_struct_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DDSCommandAct_struct_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DDSCommandAct_struct *sample;

                static RTIXCdrMemberAccessInfo DDSCommandAct_struct_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DDSCommandAct_struct_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DDSCommandAct_struct_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DDSCommandAct_struct);
                if (sample == NULL) {
                    return NULL;
                }

                DDSCommandAct_struct_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->code() - (char *)sample);

                DDSCommandAct_struct_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->subcode() - (char *)sample);

                DDSCommandAct_struct_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ctrSource() - (char *)sample);

                DDSCommandAct_struct_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->commBuffer() - (char *)sample);

                DDSCommandAct_struct_g_sampleAccessInfo.memberAccessInfos = 
                DDSCommandAct_struct_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DDSCommandAct_struct);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        DDSCommandAct_struct_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        DDSCommandAct_struct_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DDSCommandAct_struct_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DDSCommandAct_struct_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DDSCommandAct_struct >;

                DDSCommandAct_struct_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DDSCommandAct_struct_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DDSCommandAct_struct_g_typePlugin = 
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

                return &DDSCommandAct_struct_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DDSCommandAct_struct >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DDSCommandAct_struct >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< DDSCommandSt_struct > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode DDSCommandSt_struct_g_tc_ctrSource_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,64L, NULL,NULL);
                static DDS_TypeCode DDSCommandSt_struct_g_tc_commBuffer_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,256L, NULL,NULL);

                static DDS_TypeCode_Member DDSCommandSt_struct_g_tc_members[4]=
                {

                    {
                        (char *)"code",/* Member name */
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
                        (char *)"subcode",/* Member name */
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
                        (char *)"ctrSource",/* Member name */
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
                    }, 
                    {
                        (char *)"commBuffer",/* Member name */
                        {
                            3,/* Representation ID */
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

                static DDS_TypeCode DDSCommandSt_struct_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DDSCommandSt_struct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        DDSCommandSt_struct_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DDSCommandSt_struct*/

                if (is_initialized) {
                    return &DDSCommandSt_struct_g_tc;
                }

                DDSCommandSt_struct_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                DDSCommandSt_struct_g_tc_ctrSource_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_char;
                DDSCommandSt_struct_g_tc_commBuffer_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_char;
                DDSCommandSt_struct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DDSCommandSt_struct_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DDSCommandSt_struct_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& DDSCommandSt_struct_g_tc_ctrSource_array;
                DDSCommandSt_struct_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& DDSCommandSt_struct_g_tc_commBuffer_array;

                /* Initialize the values for member annotations. */
                DDSCommandSt_struct_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSt_struct_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
                DDSCommandSt_struct_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSt_struct_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                DDSCommandSt_struct_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSt_struct_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                DDSCommandSt_struct_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSt_struct_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0;
                DDSCommandSt_struct_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSt_struct_g_tc_members[1]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                DDSCommandSt_struct_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DDSCommandSt_struct_g_tc_members[1]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                DDSCommandSt_struct_g_tc._data._sampleAccessInfo = sample_access_info();
                DDSCommandSt_struct_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DDSCommandSt_struct_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                DDSCommandSt_struct *sample;

                static RTIXCdrMemberAccessInfo DDSCommandSt_struct_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DDSCommandSt_struct_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DDSCommandSt_struct_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    DDSCommandSt_struct);
                if (sample == NULL) {
                    return NULL;
                }

                DDSCommandSt_struct_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->code() - (char *)sample);

                DDSCommandSt_struct_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->subcode() - (char *)sample);

                DDSCommandSt_struct_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ctrSource() - (char *)sample);

                DDSCommandSt_struct_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->commBuffer() - (char *)sample);

                DDSCommandSt_struct_g_sampleAccessInfo.memberAccessInfos = 
                DDSCommandSt_struct_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(DDSCommandSt_struct);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        DDSCommandSt_struct_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        DDSCommandSt_struct_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DDSCommandSt_struct_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DDSCommandSt_struct_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< DDSCommandSt_struct >;

                DDSCommandSt_struct_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DDSCommandSt_struct_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DDSCommandSt_struct_g_typePlugin = 
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

                return &DDSCommandSt_struct_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< DDSCommandSt_struct >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< DDSCommandSt_struct >::get())));
        }

    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< DDSCommandSet_struct >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DDSCommandSet_structPlugin_new,
                DDSCommandSet_structPlugin_delete);
        }

        std::vector<char>& topic_type_support< DDSCommandSet_struct >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DDSCommandSet_struct& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DDSCommandSet_structPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DDSCommandSet_structPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DDSCommandSet_struct >::from_cdr_buffer(DDSCommandSet_struct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DDSCommandSet_structPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DDSCommandSet_struct from cdr buffer");
        }

        void topic_type_support< DDSCommandSet_struct >::reset_sample(DDSCommandSet_struct& sample) 
        {
            sample.code(0);
            sample.subcode(0);
            ::rti::topic::reset_sample(sample.ctrSource());
            ::rti::topic::reset_sample(sample.commBuffer());
        }

        void topic_type_support< DDSCommandSet_struct >::allocate_sample(DDSCommandSet_struct& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.ctrSource(),  -1, -1);
            ::rti::topic::allocate_sample(sample.commBuffer(),  -1, -1);
        }

        void topic_type_support< DDSCommandRsp_struct >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DDSCommandRsp_structPlugin_new,
                DDSCommandRsp_structPlugin_delete);
        }

        std::vector<char>& topic_type_support< DDSCommandRsp_struct >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DDSCommandRsp_struct& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DDSCommandRsp_structPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DDSCommandRsp_structPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DDSCommandRsp_struct >::from_cdr_buffer(DDSCommandRsp_struct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DDSCommandRsp_structPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DDSCommandRsp_struct from cdr buffer");
        }

        void topic_type_support< DDSCommandRsp_struct >::reset_sample(DDSCommandRsp_struct& sample) 
        {
            sample.code(0);
            sample.subcode(0);
            ::rti::topic::reset_sample(sample.ctrSource());
            ::rti::topic::reset_sample(sample.commBuffer());
        }

        void topic_type_support< DDSCommandRsp_struct >::allocate_sample(DDSCommandRsp_struct& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.ctrSource(),  -1, -1);
            ::rti::topic::allocate_sample(sample.commBuffer(),  -1, -1);
        }

        void topic_type_support< DDSCommandAct_struct >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DDSCommandAct_structPlugin_new,
                DDSCommandAct_structPlugin_delete);
        }

        std::vector<char>& topic_type_support< DDSCommandAct_struct >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DDSCommandAct_struct& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DDSCommandAct_structPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DDSCommandAct_structPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DDSCommandAct_struct >::from_cdr_buffer(DDSCommandAct_struct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DDSCommandAct_structPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DDSCommandAct_struct from cdr buffer");
        }

        void topic_type_support< DDSCommandAct_struct >::reset_sample(DDSCommandAct_struct& sample) 
        {
            sample.code(0);
            sample.subcode(0);
            ::rti::topic::reset_sample(sample.ctrSource());
            ::rti::topic::reset_sample(sample.commBuffer());
        }

        void topic_type_support< DDSCommandAct_struct >::allocate_sample(DDSCommandAct_struct& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.ctrSource(),  -1, -1);
            ::rti::topic::allocate_sample(sample.commBuffer(),  -1, -1);
        }

        void topic_type_support< DDSCommandSt_struct >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DDSCommandSt_structPlugin_new,
                DDSCommandSt_structPlugin_delete);
        }

        std::vector<char>& topic_type_support< DDSCommandSt_struct >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const DDSCommandSt_struct& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DDSCommandSt_structPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DDSCommandSt_structPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< DDSCommandSt_struct >::from_cdr_buffer(DDSCommandSt_struct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DDSCommandSt_structPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DDSCommandSt_struct from cdr buffer");
        }

        void topic_type_support< DDSCommandSt_struct >::reset_sample(DDSCommandSt_struct& sample) 
        {
            sample.code(0);
            sample.subcode(0);
            ::rti::topic::reset_sample(sample.ctrSource());
            ::rti::topic::reset_sample(sample.commBuffer());
        }

        void topic_type_support< DDSCommandSt_struct >::allocate_sample(DDSCommandSt_struct& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.ctrSource(),  -1, -1);
            ::rti::topic::allocate_sample(sample.commBuffer(),  -1, -1);
        }

    }
}  

