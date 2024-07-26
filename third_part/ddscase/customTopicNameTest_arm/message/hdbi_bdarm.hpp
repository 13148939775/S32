

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from hdbi_bdarm.idl
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef hdbi_bdarm_1034191767_hpp
#define hdbi_bdarm_1034191767_hpp

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

class NDDSUSERDllExport HDBI_BdArm_Set_struct {
  public:
    HDBI_BdArm_Set_struct();

    HDBI_BdArm_Set_struct(
        uint8_t VehicleUnlock_Set,
        uint8_t ReturnPYnlock_Set);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    HDBI_BdArm_Set_struct (HDBI_BdArm_Set_struct&&) = default;
    HDBI_BdArm_Set_struct& operator=(HDBI_BdArm_Set_struct&&) = default;
    HDBI_BdArm_Set_struct& operator=(const HDBI_BdArm_Set_struct&) = default;
    HDBI_BdArm_Set_struct(const HDBI_BdArm_Set_struct&) = default;
    #else
    HDBI_BdArm_Set_struct(HDBI_BdArm_Set_struct&& other_) OMG_NOEXCEPT;  
    HDBI_BdArm_Set_struct& operator=(HDBI_BdArm_Set_struct&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    uint8_t& VehicleUnlock_Set() OMG_NOEXCEPT {
        return m_VehicleUnlock_Set_;
    }

    const uint8_t& VehicleUnlock_Set() const OMG_NOEXCEPT {
        return m_VehicleUnlock_Set_;
    }

    void VehicleUnlock_Set(uint8_t value) {
        m_VehicleUnlock_Set_ = value;
    }

    uint8_t& ReturnPYnlock_Set() OMG_NOEXCEPT {
        return m_ReturnPYnlock_Set_;
    }

    const uint8_t& ReturnPYnlock_Set() const OMG_NOEXCEPT {
        return m_ReturnPYnlock_Set_;
    }

    void ReturnPYnlock_Set(uint8_t value) {
        m_ReturnPYnlock_Set_ = value;
    }

    bool operator == (const HDBI_BdArm_Set_struct& other_) const;
    bool operator != (const HDBI_BdArm_Set_struct& other_) const;

    void swap(HDBI_BdArm_Set_struct& other_) OMG_NOEXCEPT ;

  private:

    uint8_t m_VehicleUnlock_Set_;
    uint8_t m_ReturnPYnlock_Set_;

};

inline void swap(HDBI_BdArm_Set_struct& a, HDBI_BdArm_Set_struct& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const HDBI_BdArm_Set_struct& sample);

class NDDSUSERDllExport HDBM_BdArm_Rsp_struct {
  public:
    HDBM_BdArm_Rsp_struct();

    HDBM_BdArm_Rsp_struct(
        uint8_t VehicleUnlock_Rsp,
        uint8_t ReturnPYnlock_Rsp);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    HDBM_BdArm_Rsp_struct (HDBM_BdArm_Rsp_struct&&) = default;
    HDBM_BdArm_Rsp_struct& operator=(HDBM_BdArm_Rsp_struct&&) = default;
    HDBM_BdArm_Rsp_struct& operator=(const HDBM_BdArm_Rsp_struct&) = default;
    HDBM_BdArm_Rsp_struct(const HDBM_BdArm_Rsp_struct&) = default;
    #else
    HDBM_BdArm_Rsp_struct(HDBM_BdArm_Rsp_struct&& other_) OMG_NOEXCEPT;  
    HDBM_BdArm_Rsp_struct& operator=(HDBM_BdArm_Rsp_struct&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    uint8_t& VehicleUnlock_Rsp() OMG_NOEXCEPT {
        return m_VehicleUnlock_Rsp_;
    }

    const uint8_t& VehicleUnlock_Rsp() const OMG_NOEXCEPT {
        return m_VehicleUnlock_Rsp_;
    }

    void VehicleUnlock_Rsp(uint8_t value) {
        m_VehicleUnlock_Rsp_ = value;
    }

    uint8_t& ReturnPYnlock_Rsp() OMG_NOEXCEPT {
        return m_ReturnPYnlock_Rsp_;
    }

    const uint8_t& ReturnPYnlock_Rsp() const OMG_NOEXCEPT {
        return m_ReturnPYnlock_Rsp_;
    }

    void ReturnPYnlock_Rsp(uint8_t value) {
        m_ReturnPYnlock_Rsp_ = value;
    }

    bool operator == (const HDBM_BdArm_Rsp_struct& other_) const;
    bool operator != (const HDBM_BdArm_Rsp_struct& other_) const;

    void swap(HDBM_BdArm_Rsp_struct& other_) OMG_NOEXCEPT ;

  private:

    uint8_t m_VehicleUnlock_Rsp_;
    uint8_t m_ReturnPYnlock_Rsp_;

};

inline void swap(HDBM_BdArm_Rsp_struct& a, HDBM_BdArm_Rsp_struct& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const HDBM_BdArm_Rsp_struct& sample);

class NDDSUSERDllExport HDBI_BdArm_Act_struct {
  public:
    HDBI_BdArm_Act_struct();

    explicit HDBI_BdArm_Act_struct(
        uint8_t CenterLck_Act);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    HDBI_BdArm_Act_struct (HDBI_BdArm_Act_struct&&) = default;
    HDBI_BdArm_Act_struct& operator=(HDBI_BdArm_Act_struct&&) = default;
    HDBI_BdArm_Act_struct& operator=(const HDBI_BdArm_Act_struct&) = default;
    HDBI_BdArm_Act_struct(const HDBI_BdArm_Act_struct&) = default;
    #else
    HDBI_BdArm_Act_struct(HDBI_BdArm_Act_struct&& other_) OMG_NOEXCEPT;  
    HDBI_BdArm_Act_struct& operator=(HDBI_BdArm_Act_struct&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    uint8_t& CenterLck_Act() OMG_NOEXCEPT {
        return m_CenterLck_Act_;
    }

    const uint8_t& CenterLck_Act() const OMG_NOEXCEPT {
        return m_CenterLck_Act_;
    }

    void CenterLck_Act(uint8_t value) {
        m_CenterLck_Act_ = value;
    }

    bool operator == (const HDBI_BdArm_Act_struct& other_) const;
    bool operator != (const HDBI_BdArm_Act_struct& other_) const;

    void swap(HDBI_BdArm_Act_struct& other_) OMG_NOEXCEPT ;

  private:

    uint8_t m_CenterLck_Act_;

};

inline void swap(HDBI_BdArm_Act_struct& a, HDBI_BdArm_Act_struct& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const HDBI_BdArm_Act_struct& sample);

class NDDSUSERDllExport HDBM_BdArm_St_struct {
  public:
    HDBM_BdArm_St_struct();

    HDBM_BdArm_St_struct(
        uint8_t CenterLck_St,
        uint8_t BodyBglAlarm_St,
        uint8_t ExLckReq_St);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    HDBM_BdArm_St_struct (HDBM_BdArm_St_struct&&) = default;
    HDBM_BdArm_St_struct& operator=(HDBM_BdArm_St_struct&&) = default;
    HDBM_BdArm_St_struct& operator=(const HDBM_BdArm_St_struct&) = default;
    HDBM_BdArm_St_struct(const HDBM_BdArm_St_struct&) = default;
    #else
    HDBM_BdArm_St_struct(HDBM_BdArm_St_struct&& other_) OMG_NOEXCEPT;  
    HDBM_BdArm_St_struct& operator=(HDBM_BdArm_St_struct&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    uint8_t& CenterLck_St() OMG_NOEXCEPT {
        return m_CenterLck_St_;
    }

    const uint8_t& CenterLck_St() const OMG_NOEXCEPT {
        return m_CenterLck_St_;
    }

    void CenterLck_St(uint8_t value) {
        m_CenterLck_St_ = value;
    }

    uint8_t& BodyBglAlarm_St() OMG_NOEXCEPT {
        return m_BodyBglAlarm_St_;
    }

    const uint8_t& BodyBglAlarm_St() const OMG_NOEXCEPT {
        return m_BodyBglAlarm_St_;
    }

    void BodyBglAlarm_St(uint8_t value) {
        m_BodyBglAlarm_St_ = value;
    }

    uint8_t& ExLckReq_St() OMG_NOEXCEPT {
        return m_ExLckReq_St_;
    }

    const uint8_t& ExLckReq_St() const OMG_NOEXCEPT {
        return m_ExLckReq_St_;
    }

    void ExLckReq_St(uint8_t value) {
        m_ExLckReq_St_ = value;
    }

    bool operator == (const HDBM_BdArm_St_struct& other_) const;
    bool operator != (const HDBM_BdArm_St_struct& other_) const;

    void swap(HDBM_BdArm_St_struct& other_) OMG_NOEXCEPT ;

  private:

    uint8_t m_CenterLck_St_;
    uint8_t m_BodyBglAlarm_St_;
    uint8_t m_ExLckReq_St_;

};

inline void swap(HDBM_BdArm_St_struct& a, HDBM_BdArm_St_struct& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const HDBM_BdArm_St_struct& sample);

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< HDBI_BdArm_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "HDBI_BdArm_Set_struct";
            }
        };

        template<>
        struct is_topic_type< HDBI_BdArm_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< HDBI_BdArm_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const HDBI_BdArm_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(HDBI_BdArm_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(HDBI_BdArm_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(HDBI_BdArm_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< HDBM_BdArm_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "HDBM_BdArm_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< HDBM_BdArm_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< HDBM_BdArm_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const HDBM_BdArm_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(HDBM_BdArm_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(HDBM_BdArm_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(HDBM_BdArm_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< HDBI_BdArm_Act_struct > {
            NDDSUSERDllExport static std::string value() {
                return "HDBI_BdArm_Act_struct";
            }
        };

        template<>
        struct is_topic_type< HDBI_BdArm_Act_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< HDBI_BdArm_Act_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const HDBI_BdArm_Act_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(HDBI_BdArm_Act_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(HDBI_BdArm_Act_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(HDBI_BdArm_Act_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< HDBM_BdArm_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "HDBM_BdArm_St_struct";
            }
        };

        template<>
        struct is_topic_type< HDBM_BdArm_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< HDBM_BdArm_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const HDBM_BdArm_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(HDBM_BdArm_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(HDBM_BdArm_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(HDBM_BdArm_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< HDBI_BdArm_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< HDBI_BdArm_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< HDBM_BdArm_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< HDBM_BdArm_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< HDBI_BdArm_Act_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< HDBI_BdArm_Act_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< HDBM_BdArm_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< HDBM_BdArm_St_struct > {
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

#endif // hdbi_bdarm_1034191767_hpp

