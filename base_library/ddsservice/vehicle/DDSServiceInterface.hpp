

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DDSServiceInterface.idl
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef DDSServiceInterface_716994028_hpp
#define DDSServiceInterface_716994028_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

class NDDSUSERDllExport DDSCommandSet_struct {
  public:
    DDSCommandSet_struct();

    DDSCommandSet_struct(
        uint16_t code,
        uint16_t subcode,
        const ::dds::core::array< char, 64L>& ctrSource,
        const ::dds::core::array< char, 256L>& commBuffer);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DDSCommandSet_struct (DDSCommandSet_struct&&) = default;
    DDSCommandSet_struct& operator=(DDSCommandSet_struct&&) = default;
    DDSCommandSet_struct& operator=(const DDSCommandSet_struct&) = default;
    DDSCommandSet_struct(const DDSCommandSet_struct&) = default;
    #else
    DDSCommandSet_struct(DDSCommandSet_struct&& other_) OMG_NOEXCEPT;  
    DDSCommandSet_struct& operator=(DDSCommandSet_struct&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    uint16_t& code() OMG_NOEXCEPT {
        return m_code_;
    }

    const uint16_t& code() const OMG_NOEXCEPT {
        return m_code_;
    }

    void code(uint16_t value) {
        m_code_ = value;
    }

    uint16_t& subcode() OMG_NOEXCEPT {
        return m_subcode_;
    }

    const uint16_t& subcode() const OMG_NOEXCEPT {
        return m_subcode_;
    }

    void subcode(uint16_t value) {
        m_subcode_ = value;
    }

    ::dds::core::array< char, 64L>& ctrSource() OMG_NOEXCEPT {
        return m_ctrSource_;
    }

    const ::dds::core::array< char, 64L>& ctrSource() const OMG_NOEXCEPT {
        return m_ctrSource_;
    }

    void ctrSource(const ::dds::core::array< char, 64L>& value) {
        m_ctrSource_ = value;
    }

    void ctrSource(::dds::core::array< char, 64L>&& value) {
        m_ctrSource_ = std::move(value);
    }
    ::dds::core::array< char, 256L>& commBuffer() OMG_NOEXCEPT {
        return m_commBuffer_;
    }

    const ::dds::core::array< char, 256L>& commBuffer() const OMG_NOEXCEPT {
        return m_commBuffer_;
    }

    void commBuffer(const ::dds::core::array< char, 256L>& value) {
        m_commBuffer_ = value;
    }

    void commBuffer(::dds::core::array< char, 256L>&& value) {
        m_commBuffer_ = std::move(value);
    }

    bool operator == (const DDSCommandSet_struct& other_) const;
    bool operator != (const DDSCommandSet_struct& other_) const;

    void swap(DDSCommandSet_struct& other_) OMG_NOEXCEPT ;

  private:

    uint16_t m_code_;
    uint16_t m_subcode_;
    ::dds::core::array< char, 64L> m_ctrSource_;
    ::dds::core::array< char, 256L> m_commBuffer_;

};

inline void swap(DDSCommandSet_struct& a, DDSCommandSet_struct& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DDSCommandSet_struct& sample);

class NDDSUSERDllExport DDSCommandRsp_struct {
  public:
    DDSCommandRsp_struct();

    DDSCommandRsp_struct(
        uint16_t code,
        uint16_t subcode,
        const ::dds::core::array< char, 64L>& ctrSource,
        const ::dds::core::array< char, 256L>& commBuffer);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DDSCommandRsp_struct (DDSCommandRsp_struct&&) = default;
    DDSCommandRsp_struct& operator=(DDSCommandRsp_struct&&) = default;
    DDSCommandRsp_struct& operator=(const DDSCommandRsp_struct&) = default;
    DDSCommandRsp_struct(const DDSCommandRsp_struct&) = default;
    #else
    DDSCommandRsp_struct(DDSCommandRsp_struct&& other_) OMG_NOEXCEPT;  
    DDSCommandRsp_struct& operator=(DDSCommandRsp_struct&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    uint16_t& code() OMG_NOEXCEPT {
        return m_code_;
    }

    const uint16_t& code() const OMG_NOEXCEPT {
        return m_code_;
    }

    void code(uint16_t value) {
        m_code_ = value;
    }

    uint16_t& subcode() OMG_NOEXCEPT {
        return m_subcode_;
    }

    const uint16_t& subcode() const OMG_NOEXCEPT {
        return m_subcode_;
    }

    void subcode(uint16_t value) {
        m_subcode_ = value;
    }

    ::dds::core::array< char, 64L>& ctrSource() OMG_NOEXCEPT {
        return m_ctrSource_;
    }

    const ::dds::core::array< char, 64L>& ctrSource() const OMG_NOEXCEPT {
        return m_ctrSource_;
    }

    void ctrSource(const ::dds::core::array< char, 64L>& value) {
        m_ctrSource_ = value;
    }

    void ctrSource(::dds::core::array< char, 64L>&& value) {
        m_ctrSource_ = std::move(value);
    }
    ::dds::core::array< char, 256L>& commBuffer() OMG_NOEXCEPT {
        return m_commBuffer_;
    }

    const ::dds::core::array< char, 256L>& commBuffer() const OMG_NOEXCEPT {
        return m_commBuffer_;
    }

    void commBuffer(const ::dds::core::array< char, 256L>& value) {
        m_commBuffer_ = value;
    }

    void commBuffer(::dds::core::array< char, 256L>&& value) {
        m_commBuffer_ = std::move(value);
    }

    bool operator == (const DDSCommandRsp_struct& other_) const;
    bool operator != (const DDSCommandRsp_struct& other_) const;

    void swap(DDSCommandRsp_struct& other_) OMG_NOEXCEPT ;

  private:

    uint16_t m_code_;
    uint16_t m_subcode_;
    ::dds::core::array< char, 64L> m_ctrSource_;
    ::dds::core::array< char, 256L> m_commBuffer_;

};

inline void swap(DDSCommandRsp_struct& a, DDSCommandRsp_struct& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DDSCommandRsp_struct& sample);

class NDDSUSERDllExport DDSCommandAct_struct {
  public:
    DDSCommandAct_struct();

    DDSCommandAct_struct(
        uint16_t code,
        uint16_t subcode,
        const ::dds::core::array< char, 64L>& ctrSource,
        const ::dds::core::array< char, 256L>& commBuffer);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DDSCommandAct_struct (DDSCommandAct_struct&&) = default;
    DDSCommandAct_struct& operator=(DDSCommandAct_struct&&) = default;
    DDSCommandAct_struct& operator=(const DDSCommandAct_struct&) = default;
    DDSCommandAct_struct(const DDSCommandAct_struct&) = default;
    #else
    DDSCommandAct_struct(DDSCommandAct_struct&& other_) OMG_NOEXCEPT;  
    DDSCommandAct_struct& operator=(DDSCommandAct_struct&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    uint16_t& code() OMG_NOEXCEPT {
        return m_code_;
    }

    const uint16_t& code() const OMG_NOEXCEPT {
        return m_code_;
    }

    void code(uint16_t value) {
        m_code_ = value;
    }

    uint16_t& subcode() OMG_NOEXCEPT {
        return m_subcode_;
    }

    const uint16_t& subcode() const OMG_NOEXCEPT {
        return m_subcode_;
    }

    void subcode(uint16_t value) {
        m_subcode_ = value;
    }

    ::dds::core::array< char, 64L>& ctrSource() OMG_NOEXCEPT {
        return m_ctrSource_;
    }

    const ::dds::core::array< char, 64L>& ctrSource() const OMG_NOEXCEPT {
        return m_ctrSource_;
    }

    void ctrSource(const ::dds::core::array< char, 64L>& value) {
        m_ctrSource_ = value;
    }

    void ctrSource(::dds::core::array< char, 64L>&& value) {
        m_ctrSource_ = std::move(value);
    }
    ::dds::core::array< char, 256L>& commBuffer() OMG_NOEXCEPT {
        return m_commBuffer_;
    }

    const ::dds::core::array< char, 256L>& commBuffer() const OMG_NOEXCEPT {
        return m_commBuffer_;
    }

    void commBuffer(const ::dds::core::array< char, 256L>& value) {
        m_commBuffer_ = value;
    }

    void commBuffer(::dds::core::array< char, 256L>&& value) {
        m_commBuffer_ = std::move(value);
    }

    bool operator == (const DDSCommandAct_struct& other_) const;
    bool operator != (const DDSCommandAct_struct& other_) const;

    void swap(DDSCommandAct_struct& other_) OMG_NOEXCEPT ;

  private:

    uint16_t m_code_;
    uint16_t m_subcode_;
    ::dds::core::array< char, 64L> m_ctrSource_;
    ::dds::core::array< char, 256L> m_commBuffer_;

};

inline void swap(DDSCommandAct_struct& a, DDSCommandAct_struct& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DDSCommandAct_struct& sample);

class NDDSUSERDllExport DDSCommandSt_struct {
  public:
    DDSCommandSt_struct();

    DDSCommandSt_struct(
        uint16_t code,
        uint16_t subcode,
        const ::dds::core::array< char, 64L>& ctrSource,
        const ::dds::core::array< char, 256L>& commBuffer);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DDSCommandSt_struct (DDSCommandSt_struct&&) = default;
    DDSCommandSt_struct& operator=(DDSCommandSt_struct&&) = default;
    DDSCommandSt_struct& operator=(const DDSCommandSt_struct&) = default;
    DDSCommandSt_struct(const DDSCommandSt_struct&) = default;
    #else
    DDSCommandSt_struct(DDSCommandSt_struct&& other_) OMG_NOEXCEPT;  
    DDSCommandSt_struct& operator=(DDSCommandSt_struct&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    uint16_t& code() OMG_NOEXCEPT {
        return m_code_;
    }

    const uint16_t& code() const OMG_NOEXCEPT {
        return m_code_;
    }

    void code(uint16_t value) {
        m_code_ = value;
    }

    uint16_t& subcode() OMG_NOEXCEPT {
        return m_subcode_;
    }

    const uint16_t& subcode() const OMG_NOEXCEPT {
        return m_subcode_;
    }

    void subcode(uint16_t value) {
        m_subcode_ = value;
    }

    ::dds::core::array< char, 64L>& ctrSource() OMG_NOEXCEPT {
        return m_ctrSource_;
    }

    const ::dds::core::array< char, 64L>& ctrSource() const OMG_NOEXCEPT {
        return m_ctrSource_;
    }

    void ctrSource(const ::dds::core::array< char, 64L>& value) {
        m_ctrSource_ = value;
    }

    void ctrSource(::dds::core::array< char, 64L>&& value) {
        m_ctrSource_ = std::move(value);
    }
    ::dds::core::array< char, 256L>& commBuffer() OMG_NOEXCEPT {
        return m_commBuffer_;
    }

    const ::dds::core::array< char, 256L>& commBuffer() const OMG_NOEXCEPT {
        return m_commBuffer_;
    }

    void commBuffer(const ::dds::core::array< char, 256L>& value) {
        m_commBuffer_ = value;
    }

    void commBuffer(::dds::core::array< char, 256L>&& value) {
        m_commBuffer_ = std::move(value);
    }

    bool operator == (const DDSCommandSt_struct& other_) const;
    bool operator != (const DDSCommandSt_struct& other_) const;

    void swap(DDSCommandSt_struct& other_) OMG_NOEXCEPT ;

  private:

    uint16_t m_code_;
    uint16_t m_subcode_;
    ::dds::core::array< char, 64L> m_ctrSource_;
    ::dds::core::array< char, 256L> m_commBuffer_;

};

inline void swap(DDSCommandSt_struct& a, DDSCommandSt_struct& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DDSCommandSt_struct& sample);

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< DDSCommandSet_struct > {
            NDDSUSERDllExport static std::string value() {
                return "DDSCommandSet_struct";
            }
        };

        template<>
        struct is_topic_type< DDSCommandSet_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DDSCommandSet_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DDSCommandSet_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DDSCommandSet_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DDSCommandSet_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DDSCommandSet_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DDSCommandRsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "DDSCommandRsp_struct";
            }
        };

        template<>
        struct is_topic_type< DDSCommandRsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DDSCommandRsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DDSCommandRsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DDSCommandRsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DDSCommandRsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DDSCommandRsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DDSCommandAct_struct > {
            NDDSUSERDllExport static std::string value() {
                return "DDSCommandAct_struct";
            }
        };

        template<>
        struct is_topic_type< DDSCommandAct_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DDSCommandAct_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DDSCommandAct_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DDSCommandAct_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DDSCommandAct_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DDSCommandAct_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< DDSCommandSt_struct > {
            NDDSUSERDllExport static std::string value() {
                return "DDSCommandSt_struct";
            }
        };

        template<>
        struct is_topic_type< DDSCommandSt_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< DDSCommandSt_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const DDSCommandSt_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(DDSCommandSt_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(DDSCommandSt_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DDSCommandSt_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DDSCommandSet_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DDSCommandSet_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DDSCommandRsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DDSCommandRsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DDSCommandAct_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DDSCommandAct_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< DDSCommandSt_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< DDSCommandSt_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // DDSServiceInterface_716994028_hpp

