

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DDSServiceInterfaceIV3.idl
using RTI Code Generator (rtiddsgen) version 3.1.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef DDSServiceInterfaceIV3_1314393390_hpp
#define DDSServiceInterfaceIV3_1314393390_hpp

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

namespace BodyDomain {

    class NDDSUSERDllExport BdArm_Set_struct {
      public:
        BdArm_Set_struct();

        BdArm_Set_struct(
            uint8_t VehicleUnlock_Set,
            uint8_t ReturnPUnlock_Set,
            uint8_t AwayVclLck_Set,
            uint8_t CloseVclUnlck_Set,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdArm_Set_struct (BdArm_Set_struct&&) = default;
        BdArm_Set_struct& operator=(BdArm_Set_struct&&) = default;
        BdArm_Set_struct& operator=(const BdArm_Set_struct&) = default;
        BdArm_Set_struct(const BdArm_Set_struct&) = default;
        #else
        BdArm_Set_struct(BdArm_Set_struct&& other_) OMG_NOEXCEPT;  
        BdArm_Set_struct& operator=(BdArm_Set_struct&&  other_) OMG_NOEXCEPT;
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

        uint8_t& ReturnPUnlock_Set() OMG_NOEXCEPT {
            return m_ReturnPUnlock_Set_;
        }

        const uint8_t& ReturnPUnlock_Set() const OMG_NOEXCEPT {
            return m_ReturnPUnlock_Set_;
        }

        void ReturnPUnlock_Set(uint8_t value) {
            m_ReturnPUnlock_Set_ = value;
        }

        uint8_t& AwayVclLck_Set() OMG_NOEXCEPT {
            return m_AwayVclLck_Set_;
        }

        const uint8_t& AwayVclLck_Set() const OMG_NOEXCEPT {
            return m_AwayVclLck_Set_;
        }

        void AwayVclLck_Set(uint8_t value) {
            m_AwayVclLck_Set_ = value;
        }

        uint8_t& CloseVclUnlck_Set() OMG_NOEXCEPT {
            return m_CloseVclUnlck_Set_;
        }

        const uint8_t& CloseVclUnlck_Set() const OMG_NOEXCEPT {
            return m_CloseVclUnlck_Set_;
        }

        void CloseVclUnlck_Set(uint8_t value) {
            m_CloseVclUnlck_Set_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdArm_Set_struct& other_) const;
        bool operator != (const BdArm_Set_struct& other_) const;

        void swap(BdArm_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_VehicleUnlock_Set_;
        uint8_t m_ReturnPUnlock_Set_;
        uint8_t m_AwayVclLck_Set_;
        uint8_t m_CloseVclUnlck_Set_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdArm_Set_struct& a, BdArm_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdArm_Set_struct& sample);

    class NDDSUSERDllExport BdArm_Get_struct {
      public:
        BdArm_Get_struct();

        BdArm_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdArm_Get_struct (BdArm_Get_struct&&) = default;
        BdArm_Get_struct& operator=(BdArm_Get_struct&&) = default;
        BdArm_Get_struct& operator=(const BdArm_Get_struct&) = default;
        BdArm_Get_struct(const BdArm_Get_struct&) = default;
        #else
        BdArm_Get_struct(BdArm_Get_struct&& other_) OMG_NOEXCEPT;  
        BdArm_Get_struct& operator=(BdArm_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdArm_Get_struct& other_) const;
        bool operator != (const BdArm_Get_struct& other_) const;

        void swap(BdArm_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdArm_Get_struct& a, BdArm_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdArm_Get_struct& sample);

    class NDDSUSERDllExport BdArm_Rsp_struct {
      public:
        BdArm_Rsp_struct();

        BdArm_Rsp_struct(
            uint8_t VehicleUnlock_Rsp,
            uint8_t ReturnPUnlock_Rsp,
            uint8_t AwayVclLck_Rsp,
            uint8_t CloseVclUnlck_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdArm_Rsp_struct (BdArm_Rsp_struct&&) = default;
        BdArm_Rsp_struct& operator=(BdArm_Rsp_struct&&) = default;
        BdArm_Rsp_struct& operator=(const BdArm_Rsp_struct&) = default;
        BdArm_Rsp_struct(const BdArm_Rsp_struct&) = default;
        #else
        BdArm_Rsp_struct(BdArm_Rsp_struct&& other_) OMG_NOEXCEPT;  
        BdArm_Rsp_struct& operator=(BdArm_Rsp_struct&&  other_) OMG_NOEXCEPT;
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

        uint8_t& ReturnPUnlock_Rsp() OMG_NOEXCEPT {
            return m_ReturnPUnlock_Rsp_;
        }

        const uint8_t& ReturnPUnlock_Rsp() const OMG_NOEXCEPT {
            return m_ReturnPUnlock_Rsp_;
        }

        void ReturnPUnlock_Rsp(uint8_t value) {
            m_ReturnPUnlock_Rsp_ = value;
        }

        uint8_t& AwayVclLck_Rsp() OMG_NOEXCEPT {
            return m_AwayVclLck_Rsp_;
        }

        const uint8_t& AwayVclLck_Rsp() const OMG_NOEXCEPT {
            return m_AwayVclLck_Rsp_;
        }

        void AwayVclLck_Rsp(uint8_t value) {
            m_AwayVclLck_Rsp_ = value;
        }

        uint8_t& CloseVclUnlck_Rsp() OMG_NOEXCEPT {
            return m_CloseVclUnlck_Rsp_;
        }

        const uint8_t& CloseVclUnlck_Rsp() const OMG_NOEXCEPT {
            return m_CloseVclUnlck_Rsp_;
        }

        void CloseVclUnlck_Rsp(uint8_t value) {
            m_CloseVclUnlck_Rsp_ = value;
        }

        bool operator == (const BdArm_Rsp_struct& other_) const;
        bool operator != (const BdArm_Rsp_struct& other_) const;

        void swap(BdArm_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_VehicleUnlock_Rsp_;
        uint8_t m_ReturnPUnlock_Rsp_;
        uint8_t m_AwayVclLck_Rsp_;
        uint8_t m_CloseVclUnlck_Rsp_;

    };

    inline void swap(BdArm_Rsp_struct& a, BdArm_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdArm_Rsp_struct& sample);

    class NDDSUSERDllExport BdArm_St_struct {
      public:
        BdArm_St_struct();

        BdArm_St_struct(
            uint8_t CenterLck_St,
            uint8_t BodyBglAlarm_St,
            uint8_t ExLckReq_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdArm_St_struct (BdArm_St_struct&&) = default;
        BdArm_St_struct& operator=(BdArm_St_struct&&) = default;
        BdArm_St_struct& operator=(const BdArm_St_struct&) = default;
        BdArm_St_struct(const BdArm_St_struct&) = default;
        #else
        BdArm_St_struct(BdArm_St_struct&& other_) OMG_NOEXCEPT;  
        BdArm_St_struct& operator=(BdArm_St_struct&&  other_) OMG_NOEXCEPT;
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

        bool operator == (const BdArm_St_struct& other_) const;
        bool operator != (const BdArm_St_struct& other_) const;

        void swap(BdArm_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_CenterLck_St_;
        uint8_t m_BodyBglAlarm_St_;
        uint8_t m_ExLckReq_St_;

    };

    inline void swap(BdArm_St_struct& a, BdArm_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdArm_St_struct& sample);

    class NDDSUSERDllExport BdArm_St_Get_struct {
      public:
        BdArm_St_Get_struct();

        BdArm_St_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdArm_St_Get_struct (BdArm_St_Get_struct&&) = default;
        BdArm_St_Get_struct& operator=(BdArm_St_Get_struct&&) = default;
        BdArm_St_Get_struct& operator=(const BdArm_St_Get_struct&) = default;
        BdArm_St_Get_struct(const BdArm_St_Get_struct&) = default;
        #else
        BdArm_St_Get_struct(BdArm_St_Get_struct&& other_) OMG_NOEXCEPT;  
        BdArm_St_Get_struct& operator=(BdArm_St_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdArm_St_Get_struct& other_) const;
        bool operator != (const BdArm_St_Get_struct& other_) const;

        void swap(BdArm_St_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdArm_St_Get_struct& a, BdArm_St_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdArm_St_Get_struct& sample);

    class NDDSUSERDllExport BdArm_Ctrl_struct {
      public:
        BdArm_Ctrl_struct();

        BdArm_Ctrl_struct(
            uint8_t CenterLck_Act,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdArm_Ctrl_struct (BdArm_Ctrl_struct&&) = default;
        BdArm_Ctrl_struct& operator=(BdArm_Ctrl_struct&&) = default;
        BdArm_Ctrl_struct& operator=(const BdArm_Ctrl_struct&) = default;
        BdArm_Ctrl_struct(const BdArm_Ctrl_struct&) = default;
        #else
        BdArm_Ctrl_struct(BdArm_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        BdArm_Ctrl_struct& operator=(BdArm_Ctrl_struct&&  other_) OMG_NOEXCEPT;
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

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdArm_Ctrl_struct& other_) const;
        bool operator != (const BdArm_Ctrl_struct& other_) const;

        void swap(BdArm_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_CenterLck_Act_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdArm_Ctrl_struct& a, BdArm_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdArm_Ctrl_struct& sample);

    class NDDSUSERDllExport BdArm_Ctrl_SOA_struct {
      public:
        BdArm_Ctrl_SOA_struct();

        explicit BdArm_Ctrl_SOA_struct(
            uint8_t BdArm_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdArm_Ctrl_SOA_struct (BdArm_Ctrl_SOA_struct&&) = default;
        BdArm_Ctrl_SOA_struct& operator=(BdArm_Ctrl_SOA_struct&&) = default;
        BdArm_Ctrl_SOA_struct& operator=(const BdArm_Ctrl_SOA_struct&) = default;
        BdArm_Ctrl_SOA_struct(const BdArm_Ctrl_SOA_struct&) = default;
        #else
        BdArm_Ctrl_SOA_struct(BdArm_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        BdArm_Ctrl_SOA_struct& operator=(BdArm_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& BdArm_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_BdArm_Ctrl_SOA_u8_;
        }

        const uint8_t& BdArm_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_BdArm_Ctrl_SOA_u8_;
        }

        void BdArm_Ctrl_SOA_u8(uint8_t value) {
            m_BdArm_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const BdArm_Ctrl_SOA_struct& other_) const;
        bool operator != (const BdArm_Ctrl_SOA_struct& other_) const;

        void swap(BdArm_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_BdArm_Ctrl_SOA_u8_;

    };

    inline void swap(BdArm_Ctrl_SOA_struct& a, BdArm_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdArm_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport BdArm_Srv_Req_Union {
      public:
        BdArm_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdArm_Srv_Req_Union (BdArm_Srv_Req_Union&&) = default;
        BdArm_Srv_Req_Union& operator=(BdArm_Srv_Req_Union&&) = default;
        BdArm_Srv_Req_Union& operator=(const BdArm_Srv_Req_Union&) = default;
        BdArm_Srv_Req_Union(const BdArm_Srv_Req_Union&) = default;
        #else
        BdArm_Srv_Req_Union(BdArm_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        BdArm_Srv_Req_Union& operator=(BdArm_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::BdArm_Set_struct& BdArm_Set()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Req_Union::BdArm_Set not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Set_;
        }

        const BodyDomain::BdArm_Set_struct& BdArm_Set() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Req_Union::BdArm_Set not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Set_;
        }

        void BdArm_Set(const BodyDomain::BdArm_Set_struct& value) {
            m_u_.m_BdArm_Set_ = value;
            m_d_= 0;
        }

        void BdArm_Set(BodyDomain::BdArm_Set_struct&& value) {
            m_u_.m_BdArm_Set_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::BdArm_Get_struct& BdArm_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Req_Union::BdArm_Get not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Get_;
        }

        const BodyDomain::BdArm_Get_struct& BdArm_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Req_Union::BdArm_Get not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Get_;
        }

        void BdArm_Get(const BodyDomain::BdArm_Get_struct& value) {
            m_u_.m_BdArm_Get_ = value;
            m_d_= 1;
        }

        void BdArm_Get(BodyDomain::BdArm_Get_struct&& value) {
            m_u_.m_BdArm_Get_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::BdArm_Ctrl_struct& BdArm_Ctrl()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Req_Union::BdArm_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Ctrl_;
        }

        const BodyDomain::BdArm_Ctrl_struct& BdArm_Ctrl() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Req_Union::BdArm_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Ctrl_;
        }

        void BdArm_Ctrl(const BodyDomain::BdArm_Ctrl_struct& value) {
            m_u_.m_BdArm_Ctrl_ = value;
            m_d_= 2;
        }

        void BdArm_Ctrl(BodyDomain::BdArm_Ctrl_struct&& value) {
            m_u_.m_BdArm_Ctrl_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::BdArm_St_Get_struct& BdArm_St_Get()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Req_Union::BdArm_St_Get not selected by the discriminator" );
            }
            return m_u_.m_BdArm_St_Get_;
        }

        const BodyDomain::BdArm_St_Get_struct& BdArm_St_Get() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Req_Union::BdArm_St_Get not selected by the discriminator" );
            }
            return m_u_.m_BdArm_St_Get_;
        }

        void BdArm_St_Get(const BodyDomain::BdArm_St_Get_struct& value) {
            m_u_.m_BdArm_St_Get_ = value;
            m_d_= 3;
        }

        void BdArm_St_Get(BodyDomain::BdArm_St_Get_struct&& value) {
            m_u_.m_BdArm_St_Get_ = std::move(value);
            m_d_= 3;
        }

        bool operator == (const BdArm_Srv_Req_Union& other_) const;
        bool operator != (const BdArm_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(BdArm_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::BdArm_Set_struct m_BdArm_Set_;
            BodyDomain::BdArm_Get_struct m_BdArm_Get_;
            BodyDomain::BdArm_Ctrl_struct m_BdArm_Ctrl_;
            BodyDomain::BdArm_St_Get_struct m_BdArm_St_Get_;
            Union_();
            Union_(
                const BodyDomain::BdArm_Set_struct& BdArm_Set,
                const BodyDomain::BdArm_Get_struct& BdArm_Get,
                const BodyDomain::BdArm_Ctrl_struct& BdArm_Ctrl,
                const BodyDomain::BdArm_St_Get_struct& BdArm_St_Get);
        };
        Union_ m_u_;

    };

    inline void swap(BdArm_Srv_Req_Union& a, BdArm_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdArm_Srv_Req_Union& sample);

    class NDDSUSERDllExport BdArm_Srv_Resp_Union {
      public:
        BdArm_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdArm_Srv_Resp_Union (BdArm_Srv_Resp_Union&&) = default;
        BdArm_Srv_Resp_Union& operator=(BdArm_Srv_Resp_Union&&) = default;
        BdArm_Srv_Resp_Union& operator=(const BdArm_Srv_Resp_Union&) = default;
        BdArm_Srv_Resp_Union(const BdArm_Srv_Resp_Union&) = default;
        #else
        BdArm_Srv_Resp_Union(BdArm_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        BdArm_Srv_Resp_Union& operator=(BdArm_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::BdArm_Rsp_struct& BdArm_Set_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Resp_Union::BdArm_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Set_SOA_;
        }

        const BodyDomain::BdArm_Rsp_struct& BdArm_Set_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Resp_Union::BdArm_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Set_SOA_;
        }

        void BdArm_Set_SOA(const BodyDomain::BdArm_Rsp_struct& value) {
            m_u_.m_BdArm_Set_SOA_ = value;
            m_d_= 0;
        }

        void BdArm_Set_SOA(BodyDomain::BdArm_Rsp_struct&& value) {
            m_u_.m_BdArm_Set_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::BdArm_Rsp_struct& BdArm_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Resp_Union::BdArm_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Get_SOA_;
        }

        const BodyDomain::BdArm_Rsp_struct& BdArm_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Resp_Union::BdArm_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Get_SOA_;
        }

        void BdArm_Get_SOA(const BodyDomain::BdArm_Rsp_struct& value) {
            m_u_.m_BdArm_Get_SOA_ = value;
            m_d_= 1;
        }

        void BdArm_Get_SOA(BodyDomain::BdArm_Rsp_struct&& value) {
            m_u_.m_BdArm_Get_SOA_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::BdArm_Ctrl_SOA_struct& BdArm_Ctrl_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Resp_Union::BdArm_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Ctrl_SOA_;
        }

        const BodyDomain::BdArm_Ctrl_SOA_struct& BdArm_Ctrl_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Resp_Union::BdArm_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdArm_Ctrl_SOA_;
        }

        void BdArm_Ctrl_SOA(const BodyDomain::BdArm_Ctrl_SOA_struct& value) {
            m_u_.m_BdArm_Ctrl_SOA_ = value;
            m_d_= 2;
        }

        void BdArm_Ctrl_SOA(BodyDomain::BdArm_Ctrl_SOA_struct&& value) {
            m_u_.m_BdArm_Ctrl_SOA_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::BdArm_St_struct& BdArm_St_Get_struct()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Resp_Union::BdArm_St_Get_struct not selected by the discriminator" );
            }
            return m_u_.m_BdArm_St_Get_struct_;
        }

        const BodyDomain::BdArm_St_struct& BdArm_St_Get_struct() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdArm_Srv_Resp_Union::BdArm_St_Get_struct not selected by the discriminator" );
            }
            return m_u_.m_BdArm_St_Get_struct_;
        }

        void BdArm_St_Get_struct(const BodyDomain::BdArm_St_struct& value) {
            m_u_.m_BdArm_St_Get_struct_ = value;
            m_d_= 3;
        }

        void BdArm_St_Get_struct(BodyDomain::BdArm_St_struct&& value) {
            m_u_.m_BdArm_St_Get_struct_ = std::move(value);
            m_d_= 3;
        }

        bool operator == (const BdArm_Srv_Resp_Union& other_) const;
        bool operator != (const BdArm_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(BdArm_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::BdArm_Rsp_struct m_BdArm_Set_SOA_;
            BodyDomain::BdArm_Rsp_struct m_BdArm_Get_SOA_;
            BodyDomain::BdArm_Ctrl_SOA_struct m_BdArm_Ctrl_SOA_;
            BodyDomain::BdArm_St_struct m_BdArm_St_Get_struct_;
            Union_();
            Union_(
                const BodyDomain::BdArm_Rsp_struct& BdArm_Set_SOA,
                const BodyDomain::BdArm_Rsp_struct& BdArm_Get_SOA,
                const BodyDomain::BdArm_Ctrl_SOA_struct& BdArm_Ctrl_SOA,
                const BodyDomain::BdArm_St_struct& BdArm_St_Get_struct);
        };
        Union_ m_u_;

    };

    inline void swap(BdArm_Srv_Resp_Union& a, BdArm_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdArm_Srv_Resp_Union& sample);

    class NDDSUSERDllExport VsWsh_Set_struct {
      public:
        VsWsh_Set_struct();

        VsWsh_Set_struct(
            uint8_t FwiperSW_Set,
            uint8_t FwiperAutoSenst_Set,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VsWsh_Set_struct (VsWsh_Set_struct&&) = default;
        VsWsh_Set_struct& operator=(VsWsh_Set_struct&&) = default;
        VsWsh_Set_struct& operator=(const VsWsh_Set_struct&) = default;
        VsWsh_Set_struct(const VsWsh_Set_struct&) = default;
        #else
        VsWsh_Set_struct(VsWsh_Set_struct&& other_) OMG_NOEXCEPT;  
        VsWsh_Set_struct& operator=(VsWsh_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FwiperSW_Set() OMG_NOEXCEPT {
            return m_FwiperSW_Set_;
        }

        const uint8_t& FwiperSW_Set() const OMG_NOEXCEPT {
            return m_FwiperSW_Set_;
        }

        void FwiperSW_Set(uint8_t value) {
            m_FwiperSW_Set_ = value;
        }

        uint8_t& FwiperAutoSenst_Set() OMG_NOEXCEPT {
            return m_FwiperAutoSenst_Set_;
        }

        const uint8_t& FwiperAutoSenst_Set() const OMG_NOEXCEPT {
            return m_FwiperAutoSenst_Set_;
        }

        void FwiperAutoSenst_Set(uint8_t value) {
            m_FwiperAutoSenst_Set_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const VsWsh_Set_struct& other_) const;
        bool operator != (const VsWsh_Set_struct& other_) const;

        void swap(VsWsh_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FwiperSW_Set_;
        uint8_t m_FwiperAutoSenst_Set_;
        std::string m_CtrlSource_;

    };

    inline void swap(VsWsh_Set_struct& a, VsWsh_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VsWsh_Set_struct& sample);

    class NDDSUSERDllExport VsWsh_Get_struct {
      public:
        VsWsh_Get_struct();

        VsWsh_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VsWsh_Get_struct (VsWsh_Get_struct&&) = default;
        VsWsh_Get_struct& operator=(VsWsh_Get_struct&&) = default;
        VsWsh_Get_struct& operator=(const VsWsh_Get_struct&) = default;
        VsWsh_Get_struct(const VsWsh_Get_struct&) = default;
        #else
        VsWsh_Get_struct(VsWsh_Get_struct&& other_) OMG_NOEXCEPT;  
        VsWsh_Get_struct& operator=(VsWsh_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const VsWsh_Get_struct& other_) const;
        bool operator != (const VsWsh_Get_struct& other_) const;

        void swap(VsWsh_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(VsWsh_Get_struct& a, VsWsh_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VsWsh_Get_struct& sample);

    class NDDSUSERDllExport VsWsh_Rsp_struct {
      public:
        VsWsh_Rsp_struct();

        VsWsh_Rsp_struct(
            uint8_t FwiperSW_Rsp,
            uint8_t FwiperAutoSenst_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VsWsh_Rsp_struct (VsWsh_Rsp_struct&&) = default;
        VsWsh_Rsp_struct& operator=(VsWsh_Rsp_struct&&) = default;
        VsWsh_Rsp_struct& operator=(const VsWsh_Rsp_struct&) = default;
        VsWsh_Rsp_struct(const VsWsh_Rsp_struct&) = default;
        #else
        VsWsh_Rsp_struct(VsWsh_Rsp_struct&& other_) OMG_NOEXCEPT;  
        VsWsh_Rsp_struct& operator=(VsWsh_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FwiperSW_Rsp() OMG_NOEXCEPT {
            return m_FwiperSW_Rsp_;
        }

        const uint8_t& FwiperSW_Rsp() const OMG_NOEXCEPT {
            return m_FwiperSW_Rsp_;
        }

        void FwiperSW_Rsp(uint8_t value) {
            m_FwiperSW_Rsp_ = value;
        }

        uint8_t& FwiperAutoSenst_Rsp() OMG_NOEXCEPT {
            return m_FwiperAutoSenst_Rsp_;
        }

        const uint8_t& FwiperAutoSenst_Rsp() const OMG_NOEXCEPT {
            return m_FwiperAutoSenst_Rsp_;
        }

        void FwiperAutoSenst_Rsp(uint8_t value) {
            m_FwiperAutoSenst_Rsp_ = value;
        }

        bool operator == (const VsWsh_Rsp_struct& other_) const;
        bool operator != (const VsWsh_Rsp_struct& other_) const;

        void swap(VsWsh_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FwiperSW_Rsp_;
        uint8_t m_FwiperAutoSenst_Rsp_;

    };

    inline void swap(VsWsh_Rsp_struct& a, VsWsh_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VsWsh_Rsp_struct& sample);

    class NDDSUSERDllExport VsWsh_St_Get_struct {
      public:
        VsWsh_St_Get_struct();

        VsWsh_St_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VsWsh_St_Get_struct (VsWsh_St_Get_struct&&) = default;
        VsWsh_St_Get_struct& operator=(VsWsh_St_Get_struct&&) = default;
        VsWsh_St_Get_struct& operator=(const VsWsh_St_Get_struct&) = default;
        VsWsh_St_Get_struct(const VsWsh_St_Get_struct&) = default;
        #else
        VsWsh_St_Get_struct(VsWsh_St_Get_struct&& other_) OMG_NOEXCEPT;  
        VsWsh_St_Get_struct& operator=(VsWsh_St_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const VsWsh_St_Get_struct& other_) const;
        bool operator != (const VsWsh_St_Get_struct& other_) const;

        void swap(VsWsh_St_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(VsWsh_St_Get_struct& a, VsWsh_St_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VsWsh_St_Get_struct& sample);

    class NDDSUSERDllExport VsWsh_St_struct {
      public:
        VsWsh_St_struct();

        VsWsh_St_struct(
            uint8_t Fwiper_St,
            uint8_t WashLqdHgtWarn_St,
            uint8_t ExMirHt_Rsp,
            uint8_t FwiperSWDisplay_st,
            uint8_t RWndShldHt_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VsWsh_St_struct (VsWsh_St_struct&&) = default;
        VsWsh_St_struct& operator=(VsWsh_St_struct&&) = default;
        VsWsh_St_struct& operator=(const VsWsh_St_struct&) = default;
        VsWsh_St_struct(const VsWsh_St_struct&) = default;
        #else
        VsWsh_St_struct(VsWsh_St_struct&& other_) OMG_NOEXCEPT;  
        VsWsh_St_struct& operator=(VsWsh_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& Fwiper_St() OMG_NOEXCEPT {
            return m_Fwiper_St_;
        }

        const uint8_t& Fwiper_St() const OMG_NOEXCEPT {
            return m_Fwiper_St_;
        }

        void Fwiper_St(uint8_t value) {
            m_Fwiper_St_ = value;
        }

        uint8_t& WashLqdHgtWarn_St() OMG_NOEXCEPT {
            return m_WashLqdHgtWarn_St_;
        }

        const uint8_t& WashLqdHgtWarn_St() const OMG_NOEXCEPT {
            return m_WashLqdHgtWarn_St_;
        }

        void WashLqdHgtWarn_St(uint8_t value) {
            m_WashLqdHgtWarn_St_ = value;
        }

        uint8_t& ExMirHt_Rsp() OMG_NOEXCEPT {
            return m_ExMirHt_Rsp_;
        }

        const uint8_t& ExMirHt_Rsp() const OMG_NOEXCEPT {
            return m_ExMirHt_Rsp_;
        }

        void ExMirHt_Rsp(uint8_t value) {
            m_ExMirHt_Rsp_ = value;
        }

        uint8_t& FwiperSWDisplay_st() OMG_NOEXCEPT {
            return m_FwiperSWDisplay_st_;
        }

        const uint8_t& FwiperSWDisplay_st() const OMG_NOEXCEPT {
            return m_FwiperSWDisplay_st_;
        }

        void FwiperSWDisplay_st(uint8_t value) {
            m_FwiperSWDisplay_st_ = value;
        }

        uint8_t& RWndShldHt_Rsp() OMG_NOEXCEPT {
            return m_RWndShldHt_Rsp_;
        }

        const uint8_t& RWndShldHt_Rsp() const OMG_NOEXCEPT {
            return m_RWndShldHt_Rsp_;
        }

        void RWndShldHt_Rsp(uint8_t value) {
            m_RWndShldHt_Rsp_ = value;
        }

        bool operator == (const VsWsh_St_struct& other_) const;
        bool operator != (const VsWsh_St_struct& other_) const;

        void swap(VsWsh_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_Fwiper_St_;
        uint8_t m_WashLqdHgtWarn_St_;
        uint8_t m_ExMirHt_Rsp_;
        uint8_t m_FwiperSWDisplay_st_;
        uint8_t m_RWndShldHt_Rsp_;

    };

    inline void swap(VsWsh_St_struct& a, VsWsh_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VsWsh_St_struct& sample);

    class NDDSUSERDllExport VsWsh_Ctrl_struct {
      public:
        VsWsh_Ctrl_struct();

        VsWsh_Ctrl_struct(
            uint8_t FWiperSvcSW_Req,
            uint8_t ExMirHt_Req,
            uint8_t RWndShldHt_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VsWsh_Ctrl_struct (VsWsh_Ctrl_struct&&) = default;
        VsWsh_Ctrl_struct& operator=(VsWsh_Ctrl_struct&&) = default;
        VsWsh_Ctrl_struct& operator=(const VsWsh_Ctrl_struct&) = default;
        VsWsh_Ctrl_struct(const VsWsh_Ctrl_struct&) = default;
        #else
        VsWsh_Ctrl_struct(VsWsh_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        VsWsh_Ctrl_struct& operator=(VsWsh_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FWiperSvcSW_Req() OMG_NOEXCEPT {
            return m_FWiperSvcSW_Req_;
        }

        const uint8_t& FWiperSvcSW_Req() const OMG_NOEXCEPT {
            return m_FWiperSvcSW_Req_;
        }

        void FWiperSvcSW_Req(uint8_t value) {
            m_FWiperSvcSW_Req_ = value;
        }

        uint8_t& ExMirHt_Req() OMG_NOEXCEPT {
            return m_ExMirHt_Req_;
        }

        const uint8_t& ExMirHt_Req() const OMG_NOEXCEPT {
            return m_ExMirHt_Req_;
        }

        void ExMirHt_Req(uint8_t value) {
            m_ExMirHt_Req_ = value;
        }

        uint8_t& RWndShldHt_Req() OMG_NOEXCEPT {
            return m_RWndShldHt_Req_;
        }

        const uint8_t& RWndShldHt_Req() const OMG_NOEXCEPT {
            return m_RWndShldHt_Req_;
        }

        void RWndShldHt_Req(uint8_t value) {
            m_RWndShldHt_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const VsWsh_Ctrl_struct& other_) const;
        bool operator != (const VsWsh_Ctrl_struct& other_) const;

        void swap(VsWsh_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FWiperSvcSW_Req_;
        uint8_t m_ExMirHt_Req_;
        uint8_t m_RWndShldHt_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(VsWsh_Ctrl_struct& a, VsWsh_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VsWsh_Ctrl_struct& sample);

    class NDDSUSERDllExport VsWsh_Ctrl_SOA_struct {
      public:
        VsWsh_Ctrl_SOA_struct();

        explicit VsWsh_Ctrl_SOA_struct(
            uint8_t VsWsh_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VsWsh_Ctrl_SOA_struct (VsWsh_Ctrl_SOA_struct&&) = default;
        VsWsh_Ctrl_SOA_struct& operator=(VsWsh_Ctrl_SOA_struct&&) = default;
        VsWsh_Ctrl_SOA_struct& operator=(const VsWsh_Ctrl_SOA_struct&) = default;
        VsWsh_Ctrl_SOA_struct(const VsWsh_Ctrl_SOA_struct&) = default;
        #else
        VsWsh_Ctrl_SOA_struct(VsWsh_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        VsWsh_Ctrl_SOA_struct& operator=(VsWsh_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& VsWsh_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_VsWsh_Ctrl_SOA_u8_;
        }

        const uint8_t& VsWsh_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_VsWsh_Ctrl_SOA_u8_;
        }

        void VsWsh_Ctrl_SOA_u8(uint8_t value) {
            m_VsWsh_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const VsWsh_Ctrl_SOA_struct& other_) const;
        bool operator != (const VsWsh_Ctrl_SOA_struct& other_) const;

        void swap(VsWsh_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_VsWsh_Ctrl_SOA_u8_;

    };

    inline void swap(VsWsh_Ctrl_SOA_struct& a, VsWsh_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VsWsh_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport VsWsh_Srv_Req_Union {
      public:
        VsWsh_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VsWsh_Srv_Req_Union (VsWsh_Srv_Req_Union&&) = default;
        VsWsh_Srv_Req_Union& operator=(VsWsh_Srv_Req_Union&&) = default;
        VsWsh_Srv_Req_Union& operator=(const VsWsh_Srv_Req_Union&) = default;
        VsWsh_Srv_Req_Union(const VsWsh_Srv_Req_Union&) = default;
        #else
        VsWsh_Srv_Req_Union(VsWsh_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        VsWsh_Srv_Req_Union& operator=(VsWsh_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::VsWsh_Set_struct& VsWsh_Set()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Req_Union::VsWsh_Set not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Set_;
        }

        const BodyDomain::VsWsh_Set_struct& VsWsh_Set() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Req_Union::VsWsh_Set not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Set_;
        }

        void VsWsh_Set(const BodyDomain::VsWsh_Set_struct& value) {
            m_u_.m_VsWsh_Set_ = value;
            m_d_= 0;
        }

        void VsWsh_Set(BodyDomain::VsWsh_Set_struct&& value) {
            m_u_.m_VsWsh_Set_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::VsWsh_Get_struct& VsWsh_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Req_Union::VsWsh_Get not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Get_;
        }

        const BodyDomain::VsWsh_Get_struct& VsWsh_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Req_Union::VsWsh_Get not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Get_;
        }

        void VsWsh_Get(const BodyDomain::VsWsh_Get_struct& value) {
            m_u_.m_VsWsh_Get_ = value;
            m_d_= 1;
        }

        void VsWsh_Get(BodyDomain::VsWsh_Get_struct&& value) {
            m_u_.m_VsWsh_Get_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::VsWsh_Ctrl_struct& VsWsh_Ctrl()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Req_Union::VsWsh_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Ctrl_;
        }

        const BodyDomain::VsWsh_Ctrl_struct& VsWsh_Ctrl() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Req_Union::VsWsh_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Ctrl_;
        }

        void VsWsh_Ctrl(const BodyDomain::VsWsh_Ctrl_struct& value) {
            m_u_.m_VsWsh_Ctrl_ = value;
            m_d_= 2;
        }

        void VsWsh_Ctrl(BodyDomain::VsWsh_Ctrl_struct&& value) {
            m_u_.m_VsWsh_Ctrl_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::VsWsh_St_Get_struct& VsWsh_St_Get()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Req_Union::VsWsh_St_Get not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_St_Get_;
        }

        const BodyDomain::VsWsh_St_Get_struct& VsWsh_St_Get() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Req_Union::VsWsh_St_Get not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_St_Get_;
        }

        void VsWsh_St_Get(const BodyDomain::VsWsh_St_Get_struct& value) {
            m_u_.m_VsWsh_St_Get_ = value;
            m_d_= 3;
        }

        void VsWsh_St_Get(BodyDomain::VsWsh_St_Get_struct&& value) {
            m_u_.m_VsWsh_St_Get_ = std::move(value);
            m_d_= 3;
        }

        bool operator == (const VsWsh_Srv_Req_Union& other_) const;
        bool operator != (const VsWsh_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(VsWsh_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::VsWsh_Set_struct m_VsWsh_Set_;
            BodyDomain::VsWsh_Get_struct m_VsWsh_Get_;
            BodyDomain::VsWsh_Ctrl_struct m_VsWsh_Ctrl_;
            BodyDomain::VsWsh_St_Get_struct m_VsWsh_St_Get_;
            Union_();
            Union_(
                const BodyDomain::VsWsh_Set_struct& VsWsh_Set,
                const BodyDomain::VsWsh_Get_struct& VsWsh_Get,
                const BodyDomain::VsWsh_Ctrl_struct& VsWsh_Ctrl,
                const BodyDomain::VsWsh_St_Get_struct& VsWsh_St_Get);
        };
        Union_ m_u_;

    };

    inline void swap(VsWsh_Srv_Req_Union& a, VsWsh_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VsWsh_Srv_Req_Union& sample);

    class NDDSUSERDllExport VsWsh_Srv_Resp_Union {
      public:
        VsWsh_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VsWsh_Srv_Resp_Union (VsWsh_Srv_Resp_Union&&) = default;
        VsWsh_Srv_Resp_Union& operator=(VsWsh_Srv_Resp_Union&&) = default;
        VsWsh_Srv_Resp_Union& operator=(const VsWsh_Srv_Resp_Union&) = default;
        VsWsh_Srv_Resp_Union(const VsWsh_Srv_Resp_Union&) = default;
        #else
        VsWsh_Srv_Resp_Union(VsWsh_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        VsWsh_Srv_Resp_Union& operator=(VsWsh_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::VsWsh_Rsp_struct& VsWsh_Set_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Resp_Union::VsWsh_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Set_SOA_;
        }

        const BodyDomain::VsWsh_Rsp_struct& VsWsh_Set_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Resp_Union::VsWsh_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Set_SOA_;
        }

        void VsWsh_Set_SOA(const BodyDomain::VsWsh_Rsp_struct& value) {
            m_u_.m_VsWsh_Set_SOA_ = value;
            m_d_= 0;
        }

        void VsWsh_Set_SOA(BodyDomain::VsWsh_Rsp_struct&& value) {
            m_u_.m_VsWsh_Set_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::VsWsh_Rsp_struct& VsWsh_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Resp_Union::VsWsh_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Get_SOA_;
        }

        const BodyDomain::VsWsh_Rsp_struct& VsWsh_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Resp_Union::VsWsh_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Get_SOA_;
        }

        void VsWsh_Get_SOA(const BodyDomain::VsWsh_Rsp_struct& value) {
            m_u_.m_VsWsh_Get_SOA_ = value;
            m_d_= 1;
        }

        void VsWsh_Get_SOA(BodyDomain::VsWsh_Rsp_struct&& value) {
            m_u_.m_VsWsh_Get_SOA_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::VsWsh_Ctrl_SOA_struct& VsWsh_Ctrl_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Resp_Union::VsWsh_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Ctrl_SOA_;
        }

        const BodyDomain::VsWsh_Ctrl_SOA_struct& VsWsh_Ctrl_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Resp_Union::VsWsh_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_Ctrl_SOA_;
        }

        void VsWsh_Ctrl_SOA(const BodyDomain::VsWsh_Ctrl_SOA_struct& value) {
            m_u_.m_VsWsh_Ctrl_SOA_ = value;
            m_d_= 2;
        }

        void VsWsh_Ctrl_SOA(BodyDomain::VsWsh_Ctrl_SOA_struct&& value) {
            m_u_.m_VsWsh_Ctrl_SOA_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::VsWsh_St_struct& VsWsh_St_Get_SOA()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Resp_Union::VsWsh_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_St_Get_SOA_;
        }

        const BodyDomain::VsWsh_St_struct& VsWsh_St_Get_SOA() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::VsWsh_Srv_Resp_Union::VsWsh_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_VsWsh_St_Get_SOA_;
        }

        void VsWsh_St_Get_SOA(const BodyDomain::VsWsh_St_struct& value) {
            m_u_.m_VsWsh_St_Get_SOA_ = value;
            m_d_= 3;
        }

        void VsWsh_St_Get_SOA(BodyDomain::VsWsh_St_struct&& value) {
            m_u_.m_VsWsh_St_Get_SOA_ = std::move(value);
            m_d_= 3;
        }

        bool operator == (const VsWsh_Srv_Resp_Union& other_) const;
        bool operator != (const VsWsh_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(VsWsh_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::VsWsh_Rsp_struct m_VsWsh_Set_SOA_;
            BodyDomain::VsWsh_Rsp_struct m_VsWsh_Get_SOA_;
            BodyDomain::VsWsh_Ctrl_SOA_struct m_VsWsh_Ctrl_SOA_;
            BodyDomain::VsWsh_St_struct m_VsWsh_St_Get_SOA_;
            Union_();
            Union_(
                const BodyDomain::VsWsh_Rsp_struct& VsWsh_Set_SOA,
                const BodyDomain::VsWsh_Rsp_struct& VsWsh_Get_SOA,
                const BodyDomain::VsWsh_Ctrl_SOA_struct& VsWsh_Ctrl_SOA,
                const BodyDomain::VsWsh_St_struct& VsWsh_St_Get_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(VsWsh_Srv_Resp_Union& a, VsWsh_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VsWsh_Srv_Resp_Union& sample);

    class NDDSUSERDllExport SSd_Set_struct {
      public:
        SSd_Set_struct();

        SSd_Set_struct(
            uint8_t LockVoiWarn_Req,
            uint8_t LowSpdVoi_Set,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SSd_Set_struct (SSd_Set_struct&&) = default;
        SSd_Set_struct& operator=(SSd_Set_struct&&) = default;
        SSd_Set_struct& operator=(const SSd_Set_struct&) = default;
        SSd_Set_struct(const SSd_Set_struct&) = default;
        #else
        SSd_Set_struct(SSd_Set_struct&& other_) OMG_NOEXCEPT;  
        SSd_Set_struct& operator=(SSd_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& LockVoiWarn_Req() OMG_NOEXCEPT {
            return m_LockVoiWarn_Req_;
        }

        const uint8_t& LockVoiWarn_Req() const OMG_NOEXCEPT {
            return m_LockVoiWarn_Req_;
        }

        void LockVoiWarn_Req(uint8_t value) {
            m_LockVoiWarn_Req_ = value;
        }

        uint8_t& LowSpdVoi_Set() OMG_NOEXCEPT {
            return m_LowSpdVoi_Set_;
        }

        const uint8_t& LowSpdVoi_Set() const OMG_NOEXCEPT {
            return m_LowSpdVoi_Set_;
        }

        void LowSpdVoi_Set(uint8_t value) {
            m_LowSpdVoi_Set_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const SSd_Set_struct& other_) const;
        bool operator != (const SSd_Set_struct& other_) const;

        void swap(SSd_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_LockVoiWarn_Req_;
        uint8_t m_LowSpdVoi_Set_;
        std::string m_CtrlSource_;

    };

    inline void swap(SSd_Set_struct& a, SSd_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SSd_Set_struct& sample);

    class NDDSUSERDllExport SSd_Get_struct {
      public:
        SSd_Get_struct();

        SSd_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SSd_Get_struct (SSd_Get_struct&&) = default;
        SSd_Get_struct& operator=(SSd_Get_struct&&) = default;
        SSd_Get_struct& operator=(const SSd_Get_struct&) = default;
        SSd_Get_struct(const SSd_Get_struct&) = default;
        #else
        SSd_Get_struct(SSd_Get_struct&& other_) OMG_NOEXCEPT;  
        SSd_Get_struct& operator=(SSd_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const SSd_Get_struct& other_) const;
        bool operator != (const SSd_Get_struct& other_) const;

        void swap(SSd_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(SSd_Get_struct& a, SSd_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SSd_Get_struct& sample);

    class NDDSUSERDllExport SSd_Rsp_struct {
      public:
        SSd_Rsp_struct();

        SSd_Rsp_struct(
            uint8_t LockVoiWarn_Rsp,
            uint8_t LowSpdVoi_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SSd_Rsp_struct (SSd_Rsp_struct&&) = default;
        SSd_Rsp_struct& operator=(SSd_Rsp_struct&&) = default;
        SSd_Rsp_struct& operator=(const SSd_Rsp_struct&) = default;
        SSd_Rsp_struct(const SSd_Rsp_struct&) = default;
        #else
        SSd_Rsp_struct(SSd_Rsp_struct&& other_) OMG_NOEXCEPT;  
        SSd_Rsp_struct& operator=(SSd_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& LockVoiWarn_Rsp() OMG_NOEXCEPT {
            return m_LockVoiWarn_Rsp_;
        }

        const uint8_t& LockVoiWarn_Rsp() const OMG_NOEXCEPT {
            return m_LockVoiWarn_Rsp_;
        }

        void LockVoiWarn_Rsp(uint8_t value) {
            m_LockVoiWarn_Rsp_ = value;
        }

        uint8_t& LowSpdVoi_Rsp() OMG_NOEXCEPT {
            return m_LowSpdVoi_Rsp_;
        }

        const uint8_t& LowSpdVoi_Rsp() const OMG_NOEXCEPT {
            return m_LowSpdVoi_Rsp_;
        }

        void LowSpdVoi_Rsp(uint8_t value) {
            m_LowSpdVoi_Rsp_ = value;
        }

        bool operator == (const SSd_Rsp_struct& other_) const;
        bool operator != (const SSd_Rsp_struct& other_) const;

        void swap(SSd_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_LockVoiWarn_Rsp_;
        uint8_t m_LowSpdVoi_Rsp_;

    };

    inline void swap(SSd_Rsp_struct& a, SSd_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SSd_Rsp_struct& sample);

    class NDDSUSERDllExport SSd_Srv_Req_Union {
      public:
        SSd_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SSd_Srv_Req_Union (SSd_Srv_Req_Union&&) = default;
        SSd_Srv_Req_Union& operator=(SSd_Srv_Req_Union&&) = default;
        SSd_Srv_Req_Union& operator=(const SSd_Srv_Req_Union&) = default;
        SSd_Srv_Req_Union(const SSd_Srv_Req_Union&) = default;
        #else
        SSd_Srv_Req_Union(SSd_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        SSd_Srv_Req_Union& operator=(SSd_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::SSd_Set_struct& SSd_Set()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::SSd_Srv_Req_Union::SSd_Set not selected by the discriminator" );
            }
            return m_u_.m_SSd_Set_;
        }

        const BodyDomain::SSd_Set_struct& SSd_Set() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::SSd_Srv_Req_Union::SSd_Set not selected by the discriminator" );
            }
            return m_u_.m_SSd_Set_;
        }

        void SSd_Set(const BodyDomain::SSd_Set_struct& value) {
            m_u_.m_SSd_Set_ = value;
            m_d_= 0;
        }

        void SSd_Set(BodyDomain::SSd_Set_struct&& value) {
            m_u_.m_SSd_Set_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::SSd_Get_struct& SSd_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::SSd_Srv_Req_Union::SSd_Get not selected by the discriminator" );
            }
            return m_u_.m_SSd_Get_;
        }

        const BodyDomain::SSd_Get_struct& SSd_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::SSd_Srv_Req_Union::SSd_Get not selected by the discriminator" );
            }
            return m_u_.m_SSd_Get_;
        }

        void SSd_Get(const BodyDomain::SSd_Get_struct& value) {
            m_u_.m_SSd_Get_ = value;
            m_d_= 1;
        }

        void SSd_Get(BodyDomain::SSd_Get_struct&& value) {
            m_u_.m_SSd_Get_ = std::move(value);
            m_d_= 1;
        }

        bool operator == (const SSd_Srv_Req_Union& other_) const;
        bool operator != (const SSd_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(SSd_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::SSd_Set_struct m_SSd_Set_;
            BodyDomain::SSd_Get_struct m_SSd_Get_;
            Union_();
            Union_(
                const BodyDomain::SSd_Set_struct& SSd_Set,
                const BodyDomain::SSd_Get_struct& SSd_Get);
        };
        Union_ m_u_;

    };

    inline void swap(SSd_Srv_Req_Union& a, SSd_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SSd_Srv_Req_Union& sample);

    class NDDSUSERDllExport SSd_Srv_Resp_Union {
      public:
        SSd_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SSd_Srv_Resp_Union (SSd_Srv_Resp_Union&&) = default;
        SSd_Srv_Resp_Union& operator=(SSd_Srv_Resp_Union&&) = default;
        SSd_Srv_Resp_Union& operator=(const SSd_Srv_Resp_Union&) = default;
        SSd_Srv_Resp_Union(const SSd_Srv_Resp_Union&) = default;
        #else
        SSd_Srv_Resp_Union(SSd_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        SSd_Srv_Resp_Union& operator=(SSd_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::SSd_Rsp_struct& SSd_Set_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::SSd_Srv_Resp_Union::SSd_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_SSd_Set_SOA_;
        }

        const BodyDomain::SSd_Rsp_struct& SSd_Set_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::SSd_Srv_Resp_Union::SSd_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_SSd_Set_SOA_;
        }

        void SSd_Set_SOA(const BodyDomain::SSd_Rsp_struct& value) {
            m_u_.m_SSd_Set_SOA_ = value;
            m_d_= 0;
        }

        void SSd_Set_SOA(BodyDomain::SSd_Rsp_struct&& value) {
            m_u_.m_SSd_Set_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::SSd_Rsp_struct& SSd_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::SSd_Srv_Resp_Union::SSd_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_SSd_Get_SOA_;
        }

        const BodyDomain::SSd_Rsp_struct& SSd_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::SSd_Srv_Resp_Union::SSd_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_SSd_Get_SOA_;
        }

        void SSd_Get_SOA(const BodyDomain::SSd_Rsp_struct& value) {
            m_u_.m_SSd_Get_SOA_ = value;
            m_d_= 1;
        }

        void SSd_Get_SOA(BodyDomain::SSd_Rsp_struct&& value) {
            m_u_.m_SSd_Get_SOA_ = std::move(value);
            m_d_= 1;
        }

        bool operator == (const SSd_Srv_Resp_Union& other_) const;
        bool operator != (const SSd_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(SSd_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::SSd_Rsp_struct m_SSd_Set_SOA_;
            BodyDomain::SSd_Rsp_struct m_SSd_Get_SOA_;
            Union_();
            Union_(
                const BodyDomain::SSd_Rsp_struct& SSd_Set_SOA,
                const BodyDomain::SSd_Rsp_struct& SSd_Get_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(SSd_Srv_Resp_Union& a, SSd_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SSd_Srv_Resp_Union& sample);

    class NDDSUSERDllExport Win_Set_struct {
      public:
        Win_Set_struct();

        Win_Set_struct(
            uint8_t LckCloseWin_Set,
            uint8_t RainCloseWin_Set,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Win_Set_struct (Win_Set_struct&&) = default;
        Win_Set_struct& operator=(Win_Set_struct&&) = default;
        Win_Set_struct& operator=(const Win_Set_struct&) = default;
        Win_Set_struct(const Win_Set_struct&) = default;
        #else
        Win_Set_struct(Win_Set_struct&& other_) OMG_NOEXCEPT;  
        Win_Set_struct& operator=(Win_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& LckCloseWin_Set() OMG_NOEXCEPT {
            return m_LckCloseWin_Set_;
        }

        const uint8_t& LckCloseWin_Set() const OMG_NOEXCEPT {
            return m_LckCloseWin_Set_;
        }

        void LckCloseWin_Set(uint8_t value) {
            m_LckCloseWin_Set_ = value;
        }

        uint8_t& RainCloseWin_Set() OMG_NOEXCEPT {
            return m_RainCloseWin_Set_;
        }

        const uint8_t& RainCloseWin_Set() const OMG_NOEXCEPT {
            return m_RainCloseWin_Set_;
        }

        void RainCloseWin_Set(uint8_t value) {
            m_RainCloseWin_Set_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const Win_Set_struct& other_) const;
        bool operator != (const Win_Set_struct& other_) const;

        void swap(Win_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_LckCloseWin_Set_;
        uint8_t m_RainCloseWin_Set_;
        std::string m_CtrlSource_;

    };

    inline void swap(Win_Set_struct& a, Win_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Win_Set_struct& sample);

    class NDDSUSERDllExport Win_Get_struct {
      public:
        Win_Get_struct();

        Win_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Win_Get_struct (Win_Get_struct&&) = default;
        Win_Get_struct& operator=(Win_Get_struct&&) = default;
        Win_Get_struct& operator=(const Win_Get_struct&) = default;
        Win_Get_struct(const Win_Get_struct&) = default;
        #else
        Win_Get_struct(Win_Get_struct&& other_) OMG_NOEXCEPT;  
        Win_Get_struct& operator=(Win_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const Win_Get_struct& other_) const;
        bool operator != (const Win_Get_struct& other_) const;

        void swap(Win_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(Win_Get_struct& a, Win_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Win_Get_struct& sample);

    class NDDSUSERDllExport Win_Rsp_struct {
      public:
        Win_Rsp_struct();

        Win_Rsp_struct(
            uint8_t LckCloseWin_Rsp,
            uint8_t RainCloseWin_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Win_Rsp_struct (Win_Rsp_struct&&) = default;
        Win_Rsp_struct& operator=(Win_Rsp_struct&&) = default;
        Win_Rsp_struct& operator=(const Win_Rsp_struct&) = default;
        Win_Rsp_struct(const Win_Rsp_struct&) = default;
        #else
        Win_Rsp_struct(Win_Rsp_struct&& other_) OMG_NOEXCEPT;  
        Win_Rsp_struct& operator=(Win_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& LckCloseWin_Rsp() OMG_NOEXCEPT {
            return m_LckCloseWin_Rsp_;
        }

        const uint8_t& LckCloseWin_Rsp() const OMG_NOEXCEPT {
            return m_LckCloseWin_Rsp_;
        }

        void LckCloseWin_Rsp(uint8_t value) {
            m_LckCloseWin_Rsp_ = value;
        }

        uint8_t& RainCloseWin_Rsp() OMG_NOEXCEPT {
            return m_RainCloseWin_Rsp_;
        }

        const uint8_t& RainCloseWin_Rsp() const OMG_NOEXCEPT {
            return m_RainCloseWin_Rsp_;
        }

        void RainCloseWin_Rsp(uint8_t value) {
            m_RainCloseWin_Rsp_ = value;
        }

        bool operator == (const Win_Rsp_struct& other_) const;
        bool operator != (const Win_Rsp_struct& other_) const;

        void swap(Win_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_LckCloseWin_Rsp_;
        uint8_t m_RainCloseWin_Rsp_;

    };

    inline void swap(Win_Rsp_struct& a, Win_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Win_Rsp_struct& sample);

    class NDDSUSERDllExport WinPct_Ctrl_struct {
      public:
        WinPct_Ctrl_struct();

        WinPct_Ctrl_struct(
            uint8_t FLWinPst_Act,
            uint8_t FRWinPst_Act,
            uint8_t RLWinPst_Act,
            uint8_t RRWinPst_Act,
            uint8_t WinFastCtl_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        WinPct_Ctrl_struct (WinPct_Ctrl_struct&&) = default;
        WinPct_Ctrl_struct& operator=(WinPct_Ctrl_struct&&) = default;
        WinPct_Ctrl_struct& operator=(const WinPct_Ctrl_struct&) = default;
        WinPct_Ctrl_struct(const WinPct_Ctrl_struct&) = default;
        #else
        WinPct_Ctrl_struct(WinPct_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        WinPct_Ctrl_struct& operator=(WinPct_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLWinPst_Act() OMG_NOEXCEPT {
            return m_FLWinPst_Act_;
        }

        const uint8_t& FLWinPst_Act() const OMG_NOEXCEPT {
            return m_FLWinPst_Act_;
        }

        void FLWinPst_Act(uint8_t value) {
            m_FLWinPst_Act_ = value;
        }

        uint8_t& FRWinPst_Act() OMG_NOEXCEPT {
            return m_FRWinPst_Act_;
        }

        const uint8_t& FRWinPst_Act() const OMG_NOEXCEPT {
            return m_FRWinPst_Act_;
        }

        void FRWinPst_Act(uint8_t value) {
            m_FRWinPst_Act_ = value;
        }

        uint8_t& RLWinPst_Act() OMG_NOEXCEPT {
            return m_RLWinPst_Act_;
        }

        const uint8_t& RLWinPst_Act() const OMG_NOEXCEPT {
            return m_RLWinPst_Act_;
        }

        void RLWinPst_Act(uint8_t value) {
            m_RLWinPst_Act_ = value;
        }

        uint8_t& RRWinPst_Act() OMG_NOEXCEPT {
            return m_RRWinPst_Act_;
        }

        const uint8_t& RRWinPst_Act() const OMG_NOEXCEPT {
            return m_RRWinPst_Act_;
        }

        void RRWinPst_Act(uint8_t value) {
            m_RRWinPst_Act_ = value;
        }

        uint8_t& WinFastCtl_Req() OMG_NOEXCEPT {
            return m_WinFastCtl_Req_;
        }

        const uint8_t& WinFastCtl_Req() const OMG_NOEXCEPT {
            return m_WinFastCtl_Req_;
        }

        void WinFastCtl_Req(uint8_t value) {
            m_WinFastCtl_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const WinPct_Ctrl_struct& other_) const;
        bool operator != (const WinPct_Ctrl_struct& other_) const;

        void swap(WinPct_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLWinPst_Act_;
        uint8_t m_FRWinPst_Act_;
        uint8_t m_RLWinPst_Act_;
        uint8_t m_RRWinPst_Act_;
        uint8_t m_WinFastCtl_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(WinPct_Ctrl_struct& a, WinPct_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const WinPct_Ctrl_struct& sample);

    class NDDSUSERDllExport WinPct_Ctrl_SOA_struct {
      public:
        WinPct_Ctrl_SOA_struct();

        explicit WinPct_Ctrl_SOA_struct(
            uint8_t WinPct_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        WinPct_Ctrl_SOA_struct (WinPct_Ctrl_SOA_struct&&) = default;
        WinPct_Ctrl_SOA_struct& operator=(WinPct_Ctrl_SOA_struct&&) = default;
        WinPct_Ctrl_SOA_struct& operator=(const WinPct_Ctrl_SOA_struct&) = default;
        WinPct_Ctrl_SOA_struct(const WinPct_Ctrl_SOA_struct&) = default;
        #else
        WinPct_Ctrl_SOA_struct(WinPct_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        WinPct_Ctrl_SOA_struct& operator=(WinPct_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& WinPct_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_WinPct_Ctrl_SOA_u8_;
        }

        const uint8_t& WinPct_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_WinPct_Ctrl_SOA_u8_;
        }

        void WinPct_Ctrl_SOA_u8(uint8_t value) {
            m_WinPct_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const WinPct_Ctrl_SOA_struct& other_) const;
        bool operator != (const WinPct_Ctrl_SOA_struct& other_) const;

        void swap(WinPct_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_WinPct_Ctrl_SOA_u8_;

    };

    inline void swap(WinPct_Ctrl_SOA_struct& a, WinPct_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const WinPct_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport Win_St_Get_struct {
      public:
        Win_St_Get_struct();

        Win_St_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Win_St_Get_struct (Win_St_Get_struct&&) = default;
        Win_St_Get_struct& operator=(Win_St_Get_struct&&) = default;
        Win_St_Get_struct& operator=(const Win_St_Get_struct&) = default;
        Win_St_Get_struct(const Win_St_Get_struct&) = default;
        #else
        Win_St_Get_struct(Win_St_Get_struct&& other_) OMG_NOEXCEPT;  
        Win_St_Get_struct& operator=(Win_St_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const Win_St_Get_struct& other_) const;
        bool operator != (const Win_St_Get_struct& other_) const;

        void swap(Win_St_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(Win_St_Get_struct& a, Win_St_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Win_St_Get_struct& sample);

    class NDDSUSERDllExport Win_St_struct {
      public:
        Win_St_struct();

        Win_St_struct(
            uint8_t FLWinPst_St,
            uint8_t FRWinPst_St,
            uint8_t RLWinPst_St,
            uint8_t RRWinPst_St,
            uint8_t FLWdwMov_St,
            uint8_t FRWdwMov_St,
            uint8_t RLWdwMov_St,
            uint8_t RRWdwMov_St,
            uint8_t FLWinStpRsn_St,
            uint8_t FRWinStpRsn_St,
            uint8_t RLWinStpRsn_St,
            uint8_t RRWinStpRsn_St,
            uint8_t AllWinClose_St,
            uint8_t AllWinOpen_St,
            uint8_t AllWinFrshAir_St,
            uint8_t WinVent_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Win_St_struct (Win_St_struct&&) = default;
        Win_St_struct& operator=(Win_St_struct&&) = default;
        Win_St_struct& operator=(const Win_St_struct&) = default;
        Win_St_struct(const Win_St_struct&) = default;
        #else
        Win_St_struct(Win_St_struct&& other_) OMG_NOEXCEPT;  
        Win_St_struct& operator=(Win_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLWinPst_St() OMG_NOEXCEPT {
            return m_FLWinPst_St_;
        }

        const uint8_t& FLWinPst_St() const OMG_NOEXCEPT {
            return m_FLWinPst_St_;
        }

        void FLWinPst_St(uint8_t value) {
            m_FLWinPst_St_ = value;
        }

        uint8_t& FRWinPst_St() OMG_NOEXCEPT {
            return m_FRWinPst_St_;
        }

        const uint8_t& FRWinPst_St() const OMG_NOEXCEPT {
            return m_FRWinPst_St_;
        }

        void FRWinPst_St(uint8_t value) {
            m_FRWinPst_St_ = value;
        }

        uint8_t& RLWinPst_St() OMG_NOEXCEPT {
            return m_RLWinPst_St_;
        }

        const uint8_t& RLWinPst_St() const OMG_NOEXCEPT {
            return m_RLWinPst_St_;
        }

        void RLWinPst_St(uint8_t value) {
            m_RLWinPst_St_ = value;
        }

        uint8_t& RRWinPst_St() OMG_NOEXCEPT {
            return m_RRWinPst_St_;
        }

        const uint8_t& RRWinPst_St() const OMG_NOEXCEPT {
            return m_RRWinPst_St_;
        }

        void RRWinPst_St(uint8_t value) {
            m_RRWinPst_St_ = value;
        }

        uint8_t& FLWdwMov_St() OMG_NOEXCEPT {
            return m_FLWdwMov_St_;
        }

        const uint8_t& FLWdwMov_St() const OMG_NOEXCEPT {
            return m_FLWdwMov_St_;
        }

        void FLWdwMov_St(uint8_t value) {
            m_FLWdwMov_St_ = value;
        }

        uint8_t& FRWdwMov_St() OMG_NOEXCEPT {
            return m_FRWdwMov_St_;
        }

        const uint8_t& FRWdwMov_St() const OMG_NOEXCEPT {
            return m_FRWdwMov_St_;
        }

        void FRWdwMov_St(uint8_t value) {
            m_FRWdwMov_St_ = value;
        }

        uint8_t& RLWdwMov_St() OMG_NOEXCEPT {
            return m_RLWdwMov_St_;
        }

        const uint8_t& RLWdwMov_St() const OMG_NOEXCEPT {
            return m_RLWdwMov_St_;
        }

        void RLWdwMov_St(uint8_t value) {
            m_RLWdwMov_St_ = value;
        }

        uint8_t& RRWdwMov_St() OMG_NOEXCEPT {
            return m_RRWdwMov_St_;
        }

        const uint8_t& RRWdwMov_St() const OMG_NOEXCEPT {
            return m_RRWdwMov_St_;
        }

        void RRWdwMov_St(uint8_t value) {
            m_RRWdwMov_St_ = value;
        }

        uint8_t& FLWinStpRsn_St() OMG_NOEXCEPT {
            return m_FLWinStpRsn_St_;
        }

        const uint8_t& FLWinStpRsn_St() const OMG_NOEXCEPT {
            return m_FLWinStpRsn_St_;
        }

        void FLWinStpRsn_St(uint8_t value) {
            m_FLWinStpRsn_St_ = value;
        }

        uint8_t& FRWinStpRsn_St() OMG_NOEXCEPT {
            return m_FRWinStpRsn_St_;
        }

        const uint8_t& FRWinStpRsn_St() const OMG_NOEXCEPT {
            return m_FRWinStpRsn_St_;
        }

        void FRWinStpRsn_St(uint8_t value) {
            m_FRWinStpRsn_St_ = value;
        }

        uint8_t& RLWinStpRsn_St() OMG_NOEXCEPT {
            return m_RLWinStpRsn_St_;
        }

        const uint8_t& RLWinStpRsn_St() const OMG_NOEXCEPT {
            return m_RLWinStpRsn_St_;
        }

        void RLWinStpRsn_St(uint8_t value) {
            m_RLWinStpRsn_St_ = value;
        }

        uint8_t& RRWinStpRsn_St() OMG_NOEXCEPT {
            return m_RRWinStpRsn_St_;
        }

        const uint8_t& RRWinStpRsn_St() const OMG_NOEXCEPT {
            return m_RRWinStpRsn_St_;
        }

        void RRWinStpRsn_St(uint8_t value) {
            m_RRWinStpRsn_St_ = value;
        }

        uint8_t& AllWinClose_St() OMG_NOEXCEPT {
            return m_AllWinClose_St_;
        }

        const uint8_t& AllWinClose_St() const OMG_NOEXCEPT {
            return m_AllWinClose_St_;
        }

        void AllWinClose_St(uint8_t value) {
            m_AllWinClose_St_ = value;
        }

        uint8_t& AllWinOpen_St() OMG_NOEXCEPT {
            return m_AllWinOpen_St_;
        }

        const uint8_t& AllWinOpen_St() const OMG_NOEXCEPT {
            return m_AllWinOpen_St_;
        }

        void AllWinOpen_St(uint8_t value) {
            m_AllWinOpen_St_ = value;
        }

        uint8_t& AllWinFrshAir_St() OMG_NOEXCEPT {
            return m_AllWinFrshAir_St_;
        }

        const uint8_t& AllWinFrshAir_St() const OMG_NOEXCEPT {
            return m_AllWinFrshAir_St_;
        }

        void AllWinFrshAir_St(uint8_t value) {
            m_AllWinFrshAir_St_ = value;
        }

        uint8_t& WinVent_St() OMG_NOEXCEPT {
            return m_WinVent_St_;
        }

        const uint8_t& WinVent_St() const OMG_NOEXCEPT {
            return m_WinVent_St_;
        }

        void WinVent_St(uint8_t value) {
            m_WinVent_St_ = value;
        }

        bool operator == (const Win_St_struct& other_) const;
        bool operator != (const Win_St_struct& other_) const;

        void swap(Win_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLWinPst_St_;
        uint8_t m_FRWinPst_St_;
        uint8_t m_RLWinPst_St_;
        uint8_t m_RRWinPst_St_;
        uint8_t m_FLWdwMov_St_;
        uint8_t m_FRWdwMov_St_;
        uint8_t m_RLWdwMov_St_;
        uint8_t m_RRWdwMov_St_;
        uint8_t m_FLWinStpRsn_St_;
        uint8_t m_FRWinStpRsn_St_;
        uint8_t m_RLWinStpRsn_St_;
        uint8_t m_RRWinStpRsn_St_;
        uint8_t m_AllWinClose_St_;
        uint8_t m_AllWinOpen_St_;
        uint8_t m_AllWinFrshAir_St_;
        uint8_t m_WinVent_St_;

    };

    inline void swap(Win_St_struct& a, Win_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Win_St_struct& sample);

    class NDDSUSERDllExport Win_Srv_Req_Union {
      public:
        Win_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Win_Srv_Req_Union (Win_Srv_Req_Union&&) = default;
        Win_Srv_Req_Union& operator=(Win_Srv_Req_Union&&) = default;
        Win_Srv_Req_Union& operator=(const Win_Srv_Req_Union&) = default;
        Win_Srv_Req_Union(const Win_Srv_Req_Union&) = default;
        #else
        Win_Srv_Req_Union(Win_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        Win_Srv_Req_Union& operator=(Win_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::Win_Set_struct& Win_Set()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Req_Union::Win_Set not selected by the discriminator" );
            }
            return m_u_.m_Win_Set_;
        }

        const BodyDomain::Win_Set_struct& Win_Set() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Req_Union::Win_Set not selected by the discriminator" );
            }
            return m_u_.m_Win_Set_;
        }

        void Win_Set(const BodyDomain::Win_Set_struct& value) {
            m_u_.m_Win_Set_ = value;
            m_d_= 0;
        }

        void Win_Set(BodyDomain::Win_Set_struct&& value) {
            m_u_.m_Win_Set_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::Win_Get_struct& Win_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Req_Union::Win_Get not selected by the discriminator" );
            }
            return m_u_.m_Win_Get_;
        }

        const BodyDomain::Win_Get_struct& Win_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Req_Union::Win_Get not selected by the discriminator" );
            }
            return m_u_.m_Win_Get_;
        }

        void Win_Get(const BodyDomain::Win_Get_struct& value) {
            m_u_.m_Win_Get_ = value;
            m_d_= 1;
        }

        void Win_Get(BodyDomain::Win_Get_struct&& value) {
            m_u_.m_Win_Get_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::WinPct_Ctrl_struct& WinPct_Ctrl()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Req_Union::WinPct_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_WinPct_Ctrl_;
        }

        const BodyDomain::WinPct_Ctrl_struct& WinPct_Ctrl() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Req_Union::WinPct_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_WinPct_Ctrl_;
        }

        void WinPct_Ctrl(const BodyDomain::WinPct_Ctrl_struct& value) {
            m_u_.m_WinPct_Ctrl_ = value;
            m_d_= 2;
        }

        void WinPct_Ctrl(BodyDomain::WinPct_Ctrl_struct&& value) {
            m_u_.m_WinPct_Ctrl_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::Win_St_Get_struct& Win_St_Get()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Req_Union::Win_St_Get not selected by the discriminator" );
            }
            return m_u_.m_Win_St_Get_;
        }

        const BodyDomain::Win_St_Get_struct& Win_St_Get() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Req_Union::Win_St_Get not selected by the discriminator" );
            }
            return m_u_.m_Win_St_Get_;
        }

        void Win_St_Get(const BodyDomain::Win_St_Get_struct& value) {
            m_u_.m_Win_St_Get_ = value;
            m_d_= 3;
        }

        void Win_St_Get(BodyDomain::Win_St_Get_struct&& value) {
            m_u_.m_Win_St_Get_ = std::move(value);
            m_d_= 3;
        }

        bool operator == (const Win_Srv_Req_Union& other_) const;
        bool operator != (const Win_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(Win_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::Win_Set_struct m_Win_Set_;
            BodyDomain::Win_Get_struct m_Win_Get_;
            BodyDomain::WinPct_Ctrl_struct m_WinPct_Ctrl_;
            BodyDomain::Win_St_Get_struct m_Win_St_Get_;
            Union_();
            Union_(
                const BodyDomain::Win_Set_struct& Win_Set,
                const BodyDomain::Win_Get_struct& Win_Get,
                const BodyDomain::WinPct_Ctrl_struct& WinPct_Ctrl,
                const BodyDomain::Win_St_Get_struct& Win_St_Get);
        };
        Union_ m_u_;

    };

    inline void swap(Win_Srv_Req_Union& a, Win_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Win_Srv_Req_Union& sample);

    class NDDSUSERDllExport Win_Srv_Resp_Union {
      public:
        Win_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Win_Srv_Resp_Union (Win_Srv_Resp_Union&&) = default;
        Win_Srv_Resp_Union& operator=(Win_Srv_Resp_Union&&) = default;
        Win_Srv_Resp_Union& operator=(const Win_Srv_Resp_Union&) = default;
        Win_Srv_Resp_Union(const Win_Srv_Resp_Union&) = default;
        #else
        Win_Srv_Resp_Union(Win_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        Win_Srv_Resp_Union& operator=(Win_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::Win_Rsp_struct& Win_Set_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Resp_Union::Win_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_Win_Set_SOA_;
        }

        const BodyDomain::Win_Rsp_struct& Win_Set_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Resp_Union::Win_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_Win_Set_SOA_;
        }

        void Win_Set_SOA(const BodyDomain::Win_Rsp_struct& value) {
            m_u_.m_Win_Set_SOA_ = value;
            m_d_= 0;
        }

        void Win_Set_SOA(BodyDomain::Win_Rsp_struct&& value) {
            m_u_.m_Win_Set_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::Win_Rsp_struct& Win_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Resp_Union::Win_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_Win_Get_SOA_;
        }

        const BodyDomain::Win_Rsp_struct& Win_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Resp_Union::Win_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_Win_Get_SOA_;
        }

        void Win_Get_SOA(const BodyDomain::Win_Rsp_struct& value) {
            m_u_.m_Win_Get_SOA_ = value;
            m_d_= 1;
        }

        void Win_Get_SOA(BodyDomain::Win_Rsp_struct&& value) {
            m_u_.m_Win_Get_SOA_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::WinPct_Ctrl_SOA_struct& WinPct_Ctrl_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Resp_Union::WinPct_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_WinPct_Ctrl_SOA_;
        }

        const BodyDomain::WinPct_Ctrl_SOA_struct& WinPct_Ctrl_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Resp_Union::WinPct_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_WinPct_Ctrl_SOA_;
        }

        void WinPct_Ctrl_SOA(const BodyDomain::WinPct_Ctrl_SOA_struct& value) {
            m_u_.m_WinPct_Ctrl_SOA_ = value;
            m_d_= 2;
        }

        void WinPct_Ctrl_SOA(BodyDomain::WinPct_Ctrl_SOA_struct&& value) {
            m_u_.m_WinPct_Ctrl_SOA_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::Win_St_struct& Win_St_Get_SOA()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Resp_Union::Win_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_Win_St_Get_SOA_;
        }

        const BodyDomain::Win_St_struct& Win_St_Get_SOA() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Win_Srv_Resp_Union::Win_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_Win_St_Get_SOA_;
        }

        void Win_St_Get_SOA(const BodyDomain::Win_St_struct& value) {
            m_u_.m_Win_St_Get_SOA_ = value;
            m_d_= 3;
        }

        void Win_St_Get_SOA(BodyDomain::Win_St_struct&& value) {
            m_u_.m_Win_St_Get_SOA_ = std::move(value);
            m_d_= 3;
        }

        bool operator == (const Win_Srv_Resp_Union& other_) const;
        bool operator != (const Win_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(Win_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::Win_Rsp_struct m_Win_Set_SOA_;
            BodyDomain::Win_Rsp_struct m_Win_Get_SOA_;
            BodyDomain::WinPct_Ctrl_SOA_struct m_WinPct_Ctrl_SOA_;
            BodyDomain::Win_St_struct m_Win_St_Get_SOA_;
            Union_();
            Union_(
                const BodyDomain::Win_Rsp_struct& Win_Set_SOA,
                const BodyDomain::Win_Rsp_struct& Win_Get_SOA,
                const BodyDomain::WinPct_Ctrl_SOA_struct& WinPct_Ctrl_SOA,
                const BodyDomain::Win_St_struct& Win_St_Get_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(Win_Srv_Resp_Union& a, Win_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Win_Srv_Resp_Union& sample);

    class NDDSUSERDllExport BdPst_Set_struct {
      public:
        BdPst_Set_struct();

        BdPst_Set_struct(
            uint8_t ExMirAutoTurnOver_Set,
            uint8_t ExMirFoldEn_Set,
            uint8_t ExMirUnfoldAlt_Set,
            uint8_t FLSeatWelcome_Set,
            uint8_t ExitVehicleMemory_Set,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdPst_Set_struct (BdPst_Set_struct&&) = default;
        BdPst_Set_struct& operator=(BdPst_Set_struct&&) = default;
        BdPst_Set_struct& operator=(const BdPst_Set_struct&) = default;
        BdPst_Set_struct(const BdPst_Set_struct&) = default;
        #else
        BdPst_Set_struct(BdPst_Set_struct&& other_) OMG_NOEXCEPT;  
        BdPst_Set_struct& operator=(BdPst_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& ExMirAutoTurnOver_Set() OMG_NOEXCEPT {
            return m_ExMirAutoTurnOver_Set_;
        }

        const uint8_t& ExMirAutoTurnOver_Set() const OMG_NOEXCEPT {
            return m_ExMirAutoTurnOver_Set_;
        }

        void ExMirAutoTurnOver_Set(uint8_t value) {
            m_ExMirAutoTurnOver_Set_ = value;
        }

        uint8_t& ExMirFoldEn_Set() OMG_NOEXCEPT {
            return m_ExMirFoldEn_Set_;
        }

        const uint8_t& ExMirFoldEn_Set() const OMG_NOEXCEPT {
            return m_ExMirFoldEn_Set_;
        }

        void ExMirFoldEn_Set(uint8_t value) {
            m_ExMirFoldEn_Set_ = value;
        }

        uint8_t& ExMirUnfoldAlt_Set() OMG_NOEXCEPT {
            return m_ExMirUnfoldAlt_Set_;
        }

        const uint8_t& ExMirUnfoldAlt_Set() const OMG_NOEXCEPT {
            return m_ExMirUnfoldAlt_Set_;
        }

        void ExMirUnfoldAlt_Set(uint8_t value) {
            m_ExMirUnfoldAlt_Set_ = value;
        }

        uint8_t& FLSeatWelcome_Set() OMG_NOEXCEPT {
            return m_FLSeatWelcome_Set_;
        }

        const uint8_t& FLSeatWelcome_Set() const OMG_NOEXCEPT {
            return m_FLSeatWelcome_Set_;
        }

        void FLSeatWelcome_Set(uint8_t value) {
            m_FLSeatWelcome_Set_ = value;
        }

        uint8_t& ExitVehicleMemory_Set() OMG_NOEXCEPT {
            return m_ExitVehicleMemory_Set_;
        }

        const uint8_t& ExitVehicleMemory_Set() const OMG_NOEXCEPT {
            return m_ExitVehicleMemory_Set_;
        }

        void ExitVehicleMemory_Set(uint8_t value) {
            m_ExitVehicleMemory_Set_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdPst_Set_struct& other_) const;
        bool operator != (const BdPst_Set_struct& other_) const;

        void swap(BdPst_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_ExMirAutoTurnOver_Set_;
        uint8_t m_ExMirFoldEn_Set_;
        uint8_t m_ExMirUnfoldAlt_Set_;
        uint8_t m_FLSeatWelcome_Set_;
        uint8_t m_ExitVehicleMemory_Set_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdPst_Set_struct& a, BdPst_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdPst_Set_struct& sample);

    class NDDSUSERDllExport BdPst_Get_struct {
      public:
        BdPst_Get_struct();

        BdPst_Get_struct(
            uint8_t BdPstSetBit,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdPst_Get_struct (BdPst_Get_struct&&) = default;
        BdPst_Get_struct& operator=(BdPst_Get_struct&&) = default;
        BdPst_Get_struct& operator=(const BdPst_Get_struct&) = default;
        BdPst_Get_struct(const BdPst_Get_struct&) = default;
        #else
        BdPst_Get_struct(BdPst_Get_struct&& other_) OMG_NOEXCEPT;  
        BdPst_Get_struct& operator=(BdPst_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& BdPstSetBit() OMG_NOEXCEPT {
            return m_BdPstSetBit_;
        }

        const uint8_t& BdPstSetBit() const OMG_NOEXCEPT {
            return m_BdPstSetBit_;
        }

        void BdPstSetBit(uint8_t value) {
            m_BdPstSetBit_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdPst_Get_struct& other_) const;
        bool operator != (const BdPst_Get_struct& other_) const;

        void swap(BdPst_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_BdPstSetBit_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdPst_Get_struct& a, BdPst_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdPst_Get_struct& sample);

    class NDDSUSERDllExport BdPst_Rsp_struct {
      public:
        BdPst_Rsp_struct();

        BdPst_Rsp_struct(
            uint8_t ExMirAutoTurnOverSet_Rsp,
            uint8_t ExMirFoldEn_Rsp,
            uint8_t ExMirUnfoldAlt_Rsp,
            uint8_t FLSeatWelcome_Rsp,
            uint8_t ExitVehicleMemory_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdPst_Rsp_struct (BdPst_Rsp_struct&&) = default;
        BdPst_Rsp_struct& operator=(BdPst_Rsp_struct&&) = default;
        BdPst_Rsp_struct& operator=(const BdPst_Rsp_struct&) = default;
        BdPst_Rsp_struct(const BdPst_Rsp_struct&) = default;
        #else
        BdPst_Rsp_struct(BdPst_Rsp_struct&& other_) OMG_NOEXCEPT;  
        BdPst_Rsp_struct& operator=(BdPst_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& ExMirAutoTurnOverSet_Rsp() OMG_NOEXCEPT {
            return m_ExMirAutoTurnOverSet_Rsp_;
        }

        const uint8_t& ExMirAutoTurnOverSet_Rsp() const OMG_NOEXCEPT {
            return m_ExMirAutoTurnOverSet_Rsp_;
        }

        void ExMirAutoTurnOverSet_Rsp(uint8_t value) {
            m_ExMirAutoTurnOverSet_Rsp_ = value;
        }

        uint8_t& ExMirFoldEn_Rsp() OMG_NOEXCEPT {
            return m_ExMirFoldEn_Rsp_;
        }

        const uint8_t& ExMirFoldEn_Rsp() const OMG_NOEXCEPT {
            return m_ExMirFoldEn_Rsp_;
        }

        void ExMirFoldEn_Rsp(uint8_t value) {
            m_ExMirFoldEn_Rsp_ = value;
        }

        uint8_t& ExMirUnfoldAlt_Rsp() OMG_NOEXCEPT {
            return m_ExMirUnfoldAlt_Rsp_;
        }

        const uint8_t& ExMirUnfoldAlt_Rsp() const OMG_NOEXCEPT {
            return m_ExMirUnfoldAlt_Rsp_;
        }

        void ExMirUnfoldAlt_Rsp(uint8_t value) {
            m_ExMirUnfoldAlt_Rsp_ = value;
        }

        uint8_t& FLSeatWelcome_Rsp() OMG_NOEXCEPT {
            return m_FLSeatWelcome_Rsp_;
        }

        const uint8_t& FLSeatWelcome_Rsp() const OMG_NOEXCEPT {
            return m_FLSeatWelcome_Rsp_;
        }

        void FLSeatWelcome_Rsp(uint8_t value) {
            m_FLSeatWelcome_Rsp_ = value;
        }

        uint8_t& ExitVehicleMemory_Rsp() OMG_NOEXCEPT {
            return m_ExitVehicleMemory_Rsp_;
        }

        const uint8_t& ExitVehicleMemory_Rsp() const OMG_NOEXCEPT {
            return m_ExitVehicleMemory_Rsp_;
        }

        void ExitVehicleMemory_Rsp(uint8_t value) {
            m_ExitVehicleMemory_Rsp_ = value;
        }

        bool operator == (const BdPst_Rsp_struct& other_) const;
        bool operator != (const BdPst_Rsp_struct& other_) const;

        void swap(BdPst_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_ExMirAutoTurnOverSet_Rsp_;
        uint8_t m_ExMirFoldEn_Rsp_;
        uint8_t m_ExMirUnfoldAlt_Rsp_;
        uint8_t m_FLSeatWelcome_Rsp_;
        uint8_t m_ExitVehicleMemory_Rsp_;

    };

    inline void swap(BdPst_Rsp_struct& a, BdPst_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdPst_Rsp_struct& sample);

    class NDDSUSERDllExport BdPst_Ctrl_struct {
      public:
        BdPst_Ctrl_struct();

        BdPst_Ctrl_struct(
            uint8_t ExMirCtrl_Act,
            uint8_t LExMirUDAdj_Act,
            uint8_t LExMirLRAdj_Act,
            uint8_t RExMirUDAdj_Act,
            uint8_t RExMirLRAdj_Act,
            uint8_t SteerTiltAdj_Act,
            uint8_t SteerTeleAdj_Act,
            uint8_t SteerLongStroke_Req,
            uint8_t FLMemPstExport_req,
            uint8_t FRMemPstExPort_req,
            uint8_t FLSeatPstMem_Req,
            uint8_t FRSeatPstMem_Req,
            uint8_t SteerTiltPst_Req,
            uint8_t SteerTelePst_Req,
            uint8_t LExMirUDPst_Req,
            uint8_t LExMirLRPst_Req,
            uint8_t RExMirUDPst_Req,
            uint8_t RExMirLRPst_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdPst_Ctrl_struct (BdPst_Ctrl_struct&&) = default;
        BdPst_Ctrl_struct& operator=(BdPst_Ctrl_struct&&) = default;
        BdPst_Ctrl_struct& operator=(const BdPst_Ctrl_struct&) = default;
        BdPst_Ctrl_struct(const BdPst_Ctrl_struct&) = default;
        #else
        BdPst_Ctrl_struct(BdPst_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        BdPst_Ctrl_struct& operator=(BdPst_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& ExMirCtrl_Act() OMG_NOEXCEPT {
            return m_ExMirCtrl_Act_;
        }

        const uint8_t& ExMirCtrl_Act() const OMG_NOEXCEPT {
            return m_ExMirCtrl_Act_;
        }

        void ExMirCtrl_Act(uint8_t value) {
            m_ExMirCtrl_Act_ = value;
        }

        uint8_t& LExMirUDAdj_Act() OMG_NOEXCEPT {
            return m_LExMirUDAdj_Act_;
        }

        const uint8_t& LExMirUDAdj_Act() const OMG_NOEXCEPT {
            return m_LExMirUDAdj_Act_;
        }

        void LExMirUDAdj_Act(uint8_t value) {
            m_LExMirUDAdj_Act_ = value;
        }

        uint8_t& LExMirLRAdj_Act() OMG_NOEXCEPT {
            return m_LExMirLRAdj_Act_;
        }

        const uint8_t& LExMirLRAdj_Act() const OMG_NOEXCEPT {
            return m_LExMirLRAdj_Act_;
        }

        void LExMirLRAdj_Act(uint8_t value) {
            m_LExMirLRAdj_Act_ = value;
        }

        uint8_t& RExMirUDAdj_Act() OMG_NOEXCEPT {
            return m_RExMirUDAdj_Act_;
        }

        const uint8_t& RExMirUDAdj_Act() const OMG_NOEXCEPT {
            return m_RExMirUDAdj_Act_;
        }

        void RExMirUDAdj_Act(uint8_t value) {
            m_RExMirUDAdj_Act_ = value;
        }

        uint8_t& RExMirLRAdj_Act() OMG_NOEXCEPT {
            return m_RExMirLRAdj_Act_;
        }

        const uint8_t& RExMirLRAdj_Act() const OMG_NOEXCEPT {
            return m_RExMirLRAdj_Act_;
        }

        void RExMirLRAdj_Act(uint8_t value) {
            m_RExMirLRAdj_Act_ = value;
        }

        uint8_t& SteerTiltAdj_Act() OMG_NOEXCEPT {
            return m_SteerTiltAdj_Act_;
        }

        const uint8_t& SteerTiltAdj_Act() const OMG_NOEXCEPT {
            return m_SteerTiltAdj_Act_;
        }

        void SteerTiltAdj_Act(uint8_t value) {
            m_SteerTiltAdj_Act_ = value;
        }

        uint8_t& SteerTeleAdj_Act() OMG_NOEXCEPT {
            return m_SteerTeleAdj_Act_;
        }

        const uint8_t& SteerTeleAdj_Act() const OMG_NOEXCEPT {
            return m_SteerTeleAdj_Act_;
        }

        void SteerTeleAdj_Act(uint8_t value) {
            m_SteerTeleAdj_Act_ = value;
        }

        uint8_t& SteerLongStroke_Req() OMG_NOEXCEPT {
            return m_SteerLongStroke_Req_;
        }

        const uint8_t& SteerLongStroke_Req() const OMG_NOEXCEPT {
            return m_SteerLongStroke_Req_;
        }

        void SteerLongStroke_Req(uint8_t value) {
            m_SteerLongStroke_Req_ = value;
        }

        uint8_t& FLMemPstExport_req() OMG_NOEXCEPT {
            return m_FLMemPstExport_req_;
        }

        const uint8_t& FLMemPstExport_req() const OMG_NOEXCEPT {
            return m_FLMemPstExport_req_;
        }

        void FLMemPstExport_req(uint8_t value) {
            m_FLMemPstExport_req_ = value;
        }

        uint8_t& FRMemPstExPort_req() OMG_NOEXCEPT {
            return m_FRMemPstExPort_req_;
        }

        const uint8_t& FRMemPstExPort_req() const OMG_NOEXCEPT {
            return m_FRMemPstExPort_req_;
        }

        void FRMemPstExPort_req(uint8_t value) {
            m_FRMemPstExPort_req_ = value;
        }

        uint8_t& FLSeatPstMem_Req() OMG_NOEXCEPT {
            return m_FLSeatPstMem_Req_;
        }

        const uint8_t& FLSeatPstMem_Req() const OMG_NOEXCEPT {
            return m_FLSeatPstMem_Req_;
        }

        void FLSeatPstMem_Req(uint8_t value) {
            m_FLSeatPstMem_Req_ = value;
        }

        uint8_t& FRSeatPstMem_Req() OMG_NOEXCEPT {
            return m_FRSeatPstMem_Req_;
        }

        const uint8_t& FRSeatPstMem_Req() const OMG_NOEXCEPT {
            return m_FRSeatPstMem_Req_;
        }

        void FRSeatPstMem_Req(uint8_t value) {
            m_FRSeatPstMem_Req_ = value;
        }

        uint8_t& SteerTiltPst_Req() OMG_NOEXCEPT {
            return m_SteerTiltPst_Req_;
        }

        const uint8_t& SteerTiltPst_Req() const OMG_NOEXCEPT {
            return m_SteerTiltPst_Req_;
        }

        void SteerTiltPst_Req(uint8_t value) {
            m_SteerTiltPst_Req_ = value;
        }

        uint8_t& SteerTelePst_Req() OMG_NOEXCEPT {
            return m_SteerTelePst_Req_;
        }

        const uint8_t& SteerTelePst_Req() const OMG_NOEXCEPT {
            return m_SteerTelePst_Req_;
        }

        void SteerTelePst_Req(uint8_t value) {
            m_SteerTelePst_Req_ = value;
        }

        uint8_t& LExMirUDPst_Req() OMG_NOEXCEPT {
            return m_LExMirUDPst_Req_;
        }

        const uint8_t& LExMirUDPst_Req() const OMG_NOEXCEPT {
            return m_LExMirUDPst_Req_;
        }

        void LExMirUDPst_Req(uint8_t value) {
            m_LExMirUDPst_Req_ = value;
        }

        uint8_t& LExMirLRPst_Req() OMG_NOEXCEPT {
            return m_LExMirLRPst_Req_;
        }

        const uint8_t& LExMirLRPst_Req() const OMG_NOEXCEPT {
            return m_LExMirLRPst_Req_;
        }

        void LExMirLRPst_Req(uint8_t value) {
            m_LExMirLRPst_Req_ = value;
        }

        uint8_t& RExMirUDPst_Req() OMG_NOEXCEPT {
            return m_RExMirUDPst_Req_;
        }

        const uint8_t& RExMirUDPst_Req() const OMG_NOEXCEPT {
            return m_RExMirUDPst_Req_;
        }

        void RExMirUDPst_Req(uint8_t value) {
            m_RExMirUDPst_Req_ = value;
        }

        uint8_t& RExMirLRPst_Req() OMG_NOEXCEPT {
            return m_RExMirLRPst_Req_;
        }

        const uint8_t& RExMirLRPst_Req() const OMG_NOEXCEPT {
            return m_RExMirLRPst_Req_;
        }

        void RExMirLRPst_Req(uint8_t value) {
            m_RExMirLRPst_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdPst_Ctrl_struct& other_) const;
        bool operator != (const BdPst_Ctrl_struct& other_) const;

        void swap(BdPst_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_ExMirCtrl_Act_;
        uint8_t m_LExMirUDAdj_Act_;
        uint8_t m_LExMirLRAdj_Act_;
        uint8_t m_RExMirUDAdj_Act_;
        uint8_t m_RExMirLRAdj_Act_;
        uint8_t m_SteerTiltAdj_Act_;
        uint8_t m_SteerTeleAdj_Act_;
        uint8_t m_SteerLongStroke_Req_;
        uint8_t m_FLMemPstExport_req_;
        uint8_t m_FRMemPstExPort_req_;
        uint8_t m_FLSeatPstMem_Req_;
        uint8_t m_FRSeatPstMem_Req_;
        uint8_t m_SteerTiltPst_Req_;
        uint8_t m_SteerTelePst_Req_;
        uint8_t m_LExMirUDPst_Req_;
        uint8_t m_LExMirLRPst_Req_;
        uint8_t m_RExMirUDPst_Req_;
        uint8_t m_RExMirLRPst_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdPst_Ctrl_struct& a, BdPst_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdPst_Ctrl_struct& sample);

    class NDDSUSERDllExport BdPst_Ctrl_SOA_struct {
      public:
        BdPst_Ctrl_SOA_struct();

        explicit BdPst_Ctrl_SOA_struct(
            uint8_t BdPst_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdPst_Ctrl_SOA_struct (BdPst_Ctrl_SOA_struct&&) = default;
        BdPst_Ctrl_SOA_struct& operator=(BdPst_Ctrl_SOA_struct&&) = default;
        BdPst_Ctrl_SOA_struct& operator=(const BdPst_Ctrl_SOA_struct&) = default;
        BdPst_Ctrl_SOA_struct(const BdPst_Ctrl_SOA_struct&) = default;
        #else
        BdPst_Ctrl_SOA_struct(BdPst_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        BdPst_Ctrl_SOA_struct& operator=(BdPst_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& BdPst_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_BdPst_Ctrl_SOA_u8_;
        }

        const uint8_t& BdPst_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_BdPst_Ctrl_SOA_u8_;
        }

        void BdPst_Ctrl_SOA_u8(uint8_t value) {
            m_BdPst_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const BdPst_Ctrl_SOA_struct& other_) const;
        bool operator != (const BdPst_Ctrl_SOA_struct& other_) const;

        void swap(BdPst_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_BdPst_Ctrl_SOA_u8_;

    };

    inline void swap(BdPst_Ctrl_SOA_struct& a, BdPst_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdPst_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport BdPst_St_Get_struct {
      public:
        BdPst_St_Get_struct();

        BdPst_St_Get_struct(
            uint16_t BdPstBit,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdPst_St_Get_struct (BdPst_St_Get_struct&&) = default;
        BdPst_St_Get_struct& operator=(BdPst_St_Get_struct&&) = default;
        BdPst_St_Get_struct& operator=(const BdPst_St_Get_struct&) = default;
        BdPst_St_Get_struct(const BdPst_St_Get_struct&) = default;
        #else
        BdPst_St_Get_struct(BdPst_St_Get_struct&& other_) OMG_NOEXCEPT;  
        BdPst_St_Get_struct& operator=(BdPst_St_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint16_t& BdPstBit() OMG_NOEXCEPT {
            return m_BdPstBit_;
        }

        const uint16_t& BdPstBit() const OMG_NOEXCEPT {
            return m_BdPstBit_;
        }

        void BdPstBit(uint16_t value) {
            m_BdPstBit_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdPst_St_Get_struct& other_) const;
        bool operator != (const BdPst_St_Get_struct& other_) const;

        void swap(BdPst_St_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint16_t m_BdPstBit_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdPst_St_Get_struct& a, BdPst_St_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdPst_St_Get_struct& sample);

    class NDDSUSERDllExport FLMemPstExportRsp_struct {
      public:
        FLMemPstExportRsp_struct();

        FLMemPstExportRsp_struct(
            uint8_t FLSeatExportPst,
            uint8_t FLMemPstExportSt_Rsp,
            uint8_t FLMemPstExportMvSt_Rsp,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        FLMemPstExportRsp_struct (FLMemPstExportRsp_struct&&) = default;
        FLMemPstExportRsp_struct& operator=(FLMemPstExportRsp_struct&&) = default;
        FLMemPstExportRsp_struct& operator=(const FLMemPstExportRsp_struct&) = default;
        FLMemPstExportRsp_struct(const FLMemPstExportRsp_struct&) = default;
        #else
        FLMemPstExportRsp_struct(FLMemPstExportRsp_struct&& other_) OMG_NOEXCEPT;  
        FLMemPstExportRsp_struct& operator=(FLMemPstExportRsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLSeatExportPst() OMG_NOEXCEPT {
            return m_FLSeatExportPst_;
        }

        const uint8_t& FLSeatExportPst() const OMG_NOEXCEPT {
            return m_FLSeatExportPst_;
        }

        void FLSeatExportPst(uint8_t value) {
            m_FLSeatExportPst_ = value;
        }

        uint8_t& FLMemPstExportSt_Rsp() OMG_NOEXCEPT {
            return m_FLMemPstExportSt_Rsp_;
        }

        const uint8_t& FLMemPstExportSt_Rsp() const OMG_NOEXCEPT {
            return m_FLMemPstExportSt_Rsp_;
        }

        void FLMemPstExportSt_Rsp(uint8_t value) {
            m_FLMemPstExportSt_Rsp_ = value;
        }

        uint8_t& FLMemPstExportMvSt_Rsp() OMG_NOEXCEPT {
            return m_FLMemPstExportMvSt_Rsp_;
        }

        const uint8_t& FLMemPstExportMvSt_Rsp() const OMG_NOEXCEPT {
            return m_FLMemPstExportMvSt_Rsp_;
        }

        void FLMemPstExportMvSt_Rsp(uint8_t value) {
            m_FLMemPstExportMvSt_Rsp_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const FLMemPstExportRsp_struct& other_) const;
        bool operator != (const FLMemPstExportRsp_struct& other_) const;

        void swap(FLMemPstExportRsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLSeatExportPst_;
        uint8_t m_FLMemPstExportSt_Rsp_;
        uint8_t m_FLMemPstExportMvSt_Rsp_;
        std::string m_CtrlSource_;

    };

    inline void swap(FLMemPstExportRsp_struct& a, FLMemPstExportRsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const FLMemPstExportRsp_struct& sample);

    class NDDSUSERDllExport FRMemPstExportRsp_struct {
      public:
        FRMemPstExportRsp_struct();

        FRMemPstExportRsp_struct(
            uint8_t FRSeatExportPst,
            uint8_t FRMemPstExportSt_Rsp,
            uint8_t FRMemPstExportMvSt_Rsp,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        FRMemPstExportRsp_struct (FRMemPstExportRsp_struct&&) = default;
        FRMemPstExportRsp_struct& operator=(FRMemPstExportRsp_struct&&) = default;
        FRMemPstExportRsp_struct& operator=(const FRMemPstExportRsp_struct&) = default;
        FRMemPstExportRsp_struct(const FRMemPstExportRsp_struct&) = default;
        #else
        FRMemPstExportRsp_struct(FRMemPstExportRsp_struct&& other_) OMG_NOEXCEPT;  
        FRMemPstExportRsp_struct& operator=(FRMemPstExportRsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FRSeatExportPst() OMG_NOEXCEPT {
            return m_FRSeatExportPst_;
        }

        const uint8_t& FRSeatExportPst() const OMG_NOEXCEPT {
            return m_FRSeatExportPst_;
        }

        void FRSeatExportPst(uint8_t value) {
            m_FRSeatExportPst_ = value;
        }

        uint8_t& FRMemPstExportSt_Rsp() OMG_NOEXCEPT {
            return m_FRMemPstExportSt_Rsp_;
        }

        const uint8_t& FRMemPstExportSt_Rsp() const OMG_NOEXCEPT {
            return m_FRMemPstExportSt_Rsp_;
        }

        void FRMemPstExportSt_Rsp(uint8_t value) {
            m_FRMemPstExportSt_Rsp_ = value;
        }

        uint8_t& FRMemPstExportMvSt_Rsp() OMG_NOEXCEPT {
            return m_FRMemPstExportMvSt_Rsp_;
        }

        const uint8_t& FRMemPstExportMvSt_Rsp() const OMG_NOEXCEPT {
            return m_FRMemPstExportMvSt_Rsp_;
        }

        void FRMemPstExportMvSt_Rsp(uint8_t value) {
            m_FRMemPstExportMvSt_Rsp_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const FRMemPstExportRsp_struct& other_) const;
        bool operator != (const FRMemPstExportRsp_struct& other_) const;

        void swap(FRMemPstExportRsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FRSeatExportPst_;
        uint8_t m_FRMemPstExportSt_Rsp_;
        uint8_t m_FRMemPstExportMvSt_Rsp_;
        std::string m_CtrlSource_;

    };

    inline void swap(FRMemPstExportRsp_struct& a, FRMemPstExportRsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const FRMemPstExportRsp_struct& sample);

    class NDDSUSERDllExport BdPst_St_struct {
      public:
        BdPst_St_struct();

        BdPst_St_struct(
            bool ExMirCtrl_St,
            uint8_t LExMirUDMv_St,
            uint8_t LExMirLRMv_St,
            uint8_t RExMirUDMv_St,
            uint8_t RExMirLRMv_St,
            uint8_t SteerTiltMv_St,
            uint8_t SteerTeleMv_St,
            uint8_t LExMirCtrlMv_St,
            uint8_t RExMirCtrlMv_St,
            uint8_t SteerLongStrokeSt_Rsp,
            uint8_t SteerLongStrokeMoveSt_Rsp,
            uint8_t SteerLongStrokeStpRsn_Rsp,
            uint8_t FLSeatPstMemWin_Req,
            uint8_t FRSeatPstMemWin_Req,
            uint8_t SteerTiltPst_Rsp,
            uint8_t SteerTelePst_Rsp,
            uint8_t LExMirUDPst_Rsp,
            uint8_t LExMirLRPst_Rsp,
            uint8_t RExMirUDPst_Rsp,
            uint8_t RExMirLRPst_Rsp,
            const ::dds::core::array< BodyDomain::FLMemPstExportRsp_struct, 5L>& FLMemPstExportRsp,
            const ::dds::core::array< BodyDomain::FRMemPstExportRsp_struct, 4L>& FRMemPstExportRsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdPst_St_struct (BdPst_St_struct&&) = default;
        BdPst_St_struct& operator=(BdPst_St_struct&&) = default;
        BdPst_St_struct& operator=(const BdPst_St_struct&) = default;
        BdPst_St_struct(const BdPst_St_struct&) = default;
        #else
        BdPst_St_struct(BdPst_St_struct&& other_) OMG_NOEXCEPT;  
        BdPst_St_struct& operator=(BdPst_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        bool& ExMirCtrl_St() OMG_NOEXCEPT {
            return m_ExMirCtrl_St_;
        }

        const bool& ExMirCtrl_St() const OMG_NOEXCEPT {
            return m_ExMirCtrl_St_;
        }

        void ExMirCtrl_St(bool value) {
            m_ExMirCtrl_St_ = value;
        }

        uint8_t& LExMirUDMv_St() OMG_NOEXCEPT {
            return m_LExMirUDMv_St_;
        }

        const uint8_t& LExMirUDMv_St() const OMG_NOEXCEPT {
            return m_LExMirUDMv_St_;
        }

        void LExMirUDMv_St(uint8_t value) {
            m_LExMirUDMv_St_ = value;
        }

        uint8_t& LExMirLRMv_St() OMG_NOEXCEPT {
            return m_LExMirLRMv_St_;
        }

        const uint8_t& LExMirLRMv_St() const OMG_NOEXCEPT {
            return m_LExMirLRMv_St_;
        }

        void LExMirLRMv_St(uint8_t value) {
            m_LExMirLRMv_St_ = value;
        }

        uint8_t& RExMirUDMv_St() OMG_NOEXCEPT {
            return m_RExMirUDMv_St_;
        }

        const uint8_t& RExMirUDMv_St() const OMG_NOEXCEPT {
            return m_RExMirUDMv_St_;
        }

        void RExMirUDMv_St(uint8_t value) {
            m_RExMirUDMv_St_ = value;
        }

        uint8_t& RExMirLRMv_St() OMG_NOEXCEPT {
            return m_RExMirLRMv_St_;
        }

        const uint8_t& RExMirLRMv_St() const OMG_NOEXCEPT {
            return m_RExMirLRMv_St_;
        }

        void RExMirLRMv_St(uint8_t value) {
            m_RExMirLRMv_St_ = value;
        }

        uint8_t& SteerTiltMv_St() OMG_NOEXCEPT {
            return m_SteerTiltMv_St_;
        }

        const uint8_t& SteerTiltMv_St() const OMG_NOEXCEPT {
            return m_SteerTiltMv_St_;
        }

        void SteerTiltMv_St(uint8_t value) {
            m_SteerTiltMv_St_ = value;
        }

        uint8_t& SteerTeleMv_St() OMG_NOEXCEPT {
            return m_SteerTeleMv_St_;
        }

        const uint8_t& SteerTeleMv_St() const OMG_NOEXCEPT {
            return m_SteerTeleMv_St_;
        }

        void SteerTeleMv_St(uint8_t value) {
            m_SteerTeleMv_St_ = value;
        }

        uint8_t& LExMirCtrlMv_St() OMG_NOEXCEPT {
            return m_LExMirCtrlMv_St_;
        }

        const uint8_t& LExMirCtrlMv_St() const OMG_NOEXCEPT {
            return m_LExMirCtrlMv_St_;
        }

        void LExMirCtrlMv_St(uint8_t value) {
            m_LExMirCtrlMv_St_ = value;
        }

        uint8_t& RExMirCtrlMv_St() OMG_NOEXCEPT {
            return m_RExMirCtrlMv_St_;
        }

        const uint8_t& RExMirCtrlMv_St() const OMG_NOEXCEPT {
            return m_RExMirCtrlMv_St_;
        }

        void RExMirCtrlMv_St(uint8_t value) {
            m_RExMirCtrlMv_St_ = value;
        }

        uint8_t& SteerLongStrokeSt_Rsp() OMG_NOEXCEPT {
            return m_SteerLongStrokeSt_Rsp_;
        }

        const uint8_t& SteerLongStrokeSt_Rsp() const OMG_NOEXCEPT {
            return m_SteerLongStrokeSt_Rsp_;
        }

        void SteerLongStrokeSt_Rsp(uint8_t value) {
            m_SteerLongStrokeSt_Rsp_ = value;
        }

        uint8_t& SteerLongStrokeMoveSt_Rsp() OMG_NOEXCEPT {
            return m_SteerLongStrokeMoveSt_Rsp_;
        }

        const uint8_t& SteerLongStrokeMoveSt_Rsp() const OMG_NOEXCEPT {
            return m_SteerLongStrokeMoveSt_Rsp_;
        }

        void SteerLongStrokeMoveSt_Rsp(uint8_t value) {
            m_SteerLongStrokeMoveSt_Rsp_ = value;
        }

        uint8_t& SteerLongStrokeStpRsn_Rsp() OMG_NOEXCEPT {
            return m_SteerLongStrokeStpRsn_Rsp_;
        }

        const uint8_t& SteerLongStrokeStpRsn_Rsp() const OMG_NOEXCEPT {
            return m_SteerLongStrokeStpRsn_Rsp_;
        }

        void SteerLongStrokeStpRsn_Rsp(uint8_t value) {
            m_SteerLongStrokeStpRsn_Rsp_ = value;
        }

        uint8_t& FLSeatPstMemWin_Req() OMG_NOEXCEPT {
            return m_FLSeatPstMemWin_Req_;
        }

        const uint8_t& FLSeatPstMemWin_Req() const OMG_NOEXCEPT {
            return m_FLSeatPstMemWin_Req_;
        }

        void FLSeatPstMemWin_Req(uint8_t value) {
            m_FLSeatPstMemWin_Req_ = value;
        }

        uint8_t& FRSeatPstMemWin_Req() OMG_NOEXCEPT {
            return m_FRSeatPstMemWin_Req_;
        }

        const uint8_t& FRSeatPstMemWin_Req() const OMG_NOEXCEPT {
            return m_FRSeatPstMemWin_Req_;
        }

        void FRSeatPstMemWin_Req(uint8_t value) {
            m_FRSeatPstMemWin_Req_ = value;
        }

        uint8_t& SteerTiltPst_Rsp() OMG_NOEXCEPT {
            return m_SteerTiltPst_Rsp_;
        }

        const uint8_t& SteerTiltPst_Rsp() const OMG_NOEXCEPT {
            return m_SteerTiltPst_Rsp_;
        }

        void SteerTiltPst_Rsp(uint8_t value) {
            m_SteerTiltPst_Rsp_ = value;
        }

        uint8_t& SteerTelePst_Rsp() OMG_NOEXCEPT {
            return m_SteerTelePst_Rsp_;
        }

        const uint8_t& SteerTelePst_Rsp() const OMG_NOEXCEPT {
            return m_SteerTelePst_Rsp_;
        }

        void SteerTelePst_Rsp(uint8_t value) {
            m_SteerTelePst_Rsp_ = value;
        }

        uint8_t& LExMirUDPst_Rsp() OMG_NOEXCEPT {
            return m_LExMirUDPst_Rsp_;
        }

        const uint8_t& LExMirUDPst_Rsp() const OMG_NOEXCEPT {
            return m_LExMirUDPst_Rsp_;
        }

        void LExMirUDPst_Rsp(uint8_t value) {
            m_LExMirUDPst_Rsp_ = value;
        }

        uint8_t& LExMirLRPst_Rsp() OMG_NOEXCEPT {
            return m_LExMirLRPst_Rsp_;
        }

        const uint8_t& LExMirLRPst_Rsp() const OMG_NOEXCEPT {
            return m_LExMirLRPst_Rsp_;
        }

        void LExMirLRPst_Rsp(uint8_t value) {
            m_LExMirLRPst_Rsp_ = value;
        }

        uint8_t& RExMirUDPst_Rsp() OMG_NOEXCEPT {
            return m_RExMirUDPst_Rsp_;
        }

        const uint8_t& RExMirUDPst_Rsp() const OMG_NOEXCEPT {
            return m_RExMirUDPst_Rsp_;
        }

        void RExMirUDPst_Rsp(uint8_t value) {
            m_RExMirUDPst_Rsp_ = value;
        }

        uint8_t& RExMirLRPst_Rsp() OMG_NOEXCEPT {
            return m_RExMirLRPst_Rsp_;
        }

        const uint8_t& RExMirLRPst_Rsp() const OMG_NOEXCEPT {
            return m_RExMirLRPst_Rsp_;
        }

        void RExMirLRPst_Rsp(uint8_t value) {
            m_RExMirLRPst_Rsp_ = value;
        }

        ::dds::core::array< BodyDomain::FLMemPstExportRsp_struct, 5L>& FLMemPstExportRsp() OMG_NOEXCEPT {
            return m_FLMemPstExportRsp_;
        }

        const ::dds::core::array< BodyDomain::FLMemPstExportRsp_struct, 5L>& FLMemPstExportRsp() const OMG_NOEXCEPT {
            return m_FLMemPstExportRsp_;
        }

        void FLMemPstExportRsp(const ::dds::core::array< BodyDomain::FLMemPstExportRsp_struct, 5L>& value) {
            m_FLMemPstExportRsp_ = value;
        }

        void FLMemPstExportRsp(::dds::core::array< BodyDomain::FLMemPstExportRsp_struct, 5L>&& value) {
            m_FLMemPstExportRsp_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::FRMemPstExportRsp_struct, 4L>& FRMemPstExportRsp() OMG_NOEXCEPT {
            return m_FRMemPstExportRsp_;
        }

        const ::dds::core::array< BodyDomain::FRMemPstExportRsp_struct, 4L>& FRMemPstExportRsp() const OMG_NOEXCEPT {
            return m_FRMemPstExportRsp_;
        }

        void FRMemPstExportRsp(const ::dds::core::array< BodyDomain::FRMemPstExportRsp_struct, 4L>& value) {
            m_FRMemPstExportRsp_ = value;
        }

        void FRMemPstExportRsp(::dds::core::array< BodyDomain::FRMemPstExportRsp_struct, 4L>&& value) {
            m_FRMemPstExportRsp_ = std::move(value);
        }

        bool operator == (const BdPst_St_struct& other_) const;
        bool operator != (const BdPst_St_struct& other_) const;

        void swap(BdPst_St_struct& other_) OMG_NOEXCEPT ;

      private:

        bool m_ExMirCtrl_St_;
        uint8_t m_LExMirUDMv_St_;
        uint8_t m_LExMirLRMv_St_;
        uint8_t m_RExMirUDMv_St_;
        uint8_t m_RExMirLRMv_St_;
        uint8_t m_SteerTiltMv_St_;
        uint8_t m_SteerTeleMv_St_;
        uint8_t m_LExMirCtrlMv_St_;
        uint8_t m_RExMirCtrlMv_St_;
        uint8_t m_SteerLongStrokeSt_Rsp_;
        uint8_t m_SteerLongStrokeMoveSt_Rsp_;
        uint8_t m_SteerLongStrokeStpRsn_Rsp_;
        uint8_t m_FLSeatPstMemWin_Req_;
        uint8_t m_FRSeatPstMemWin_Req_;
        uint8_t m_SteerTiltPst_Rsp_;
        uint8_t m_SteerTelePst_Rsp_;
        uint8_t m_LExMirUDPst_Rsp_;
        uint8_t m_LExMirLRPst_Rsp_;
        uint8_t m_RExMirUDPst_Rsp_;
        uint8_t m_RExMirLRPst_Rsp_;
        ::dds::core::array< BodyDomain::FLMemPstExportRsp_struct, 5L> m_FLMemPstExportRsp_;
        ::dds::core::array< BodyDomain::FRMemPstExportRsp_struct, 4L> m_FRMemPstExportRsp_;

    };

    inline void swap(BdPst_St_struct& a, BdPst_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdPst_St_struct& sample);

    class NDDSUSERDllExport FLSeatMemPst_Req_struct {
      public:
        FLSeatMemPst_Req_struct();

        FLSeatMemPst_Req_struct(
            uint8_t FLSeatMemPstPurpose_Req,
            uint8_t FLSeatMemFBPst_Req,
            uint8_t FLSeatMemBackrestPst_Req,
            uint8_t FLSeatMemHgtPst_Req,
            uint8_t FLSeatMemCshnAngPst_Req,
            uint8_t FLMemLegAngCshnExtPst_Req,
            uint8_t FLSeatMemLegLengthPst_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        FLSeatMemPst_Req_struct (FLSeatMemPst_Req_struct&&) = default;
        FLSeatMemPst_Req_struct& operator=(FLSeatMemPst_Req_struct&&) = default;
        FLSeatMemPst_Req_struct& operator=(const FLSeatMemPst_Req_struct&) = default;
        FLSeatMemPst_Req_struct(const FLSeatMemPst_Req_struct&) = default;
        #else
        FLSeatMemPst_Req_struct(FLSeatMemPst_Req_struct&& other_) OMG_NOEXCEPT;  
        FLSeatMemPst_Req_struct& operator=(FLSeatMemPst_Req_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLSeatMemPstPurpose_Req() OMG_NOEXCEPT {
            return m_FLSeatMemPstPurpose_Req_;
        }

        const uint8_t& FLSeatMemPstPurpose_Req() const OMG_NOEXCEPT {
            return m_FLSeatMemPstPurpose_Req_;
        }

        void FLSeatMemPstPurpose_Req(uint8_t value) {
            m_FLSeatMemPstPurpose_Req_ = value;
        }

        uint8_t& FLSeatMemFBPst_Req() OMG_NOEXCEPT {
            return m_FLSeatMemFBPst_Req_;
        }

        const uint8_t& FLSeatMemFBPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatMemFBPst_Req_;
        }

        void FLSeatMemFBPst_Req(uint8_t value) {
            m_FLSeatMemFBPst_Req_ = value;
        }

        uint8_t& FLSeatMemBackrestPst_Req() OMG_NOEXCEPT {
            return m_FLSeatMemBackrestPst_Req_;
        }

        const uint8_t& FLSeatMemBackrestPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatMemBackrestPst_Req_;
        }

        void FLSeatMemBackrestPst_Req(uint8_t value) {
            m_FLSeatMemBackrestPst_Req_ = value;
        }

        uint8_t& FLSeatMemHgtPst_Req() OMG_NOEXCEPT {
            return m_FLSeatMemHgtPst_Req_;
        }

        const uint8_t& FLSeatMemHgtPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatMemHgtPst_Req_;
        }

        void FLSeatMemHgtPst_Req(uint8_t value) {
            m_FLSeatMemHgtPst_Req_ = value;
        }

        uint8_t& FLSeatMemCshnAngPst_Req() OMG_NOEXCEPT {
            return m_FLSeatMemCshnAngPst_Req_;
        }

        const uint8_t& FLSeatMemCshnAngPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatMemCshnAngPst_Req_;
        }

        void FLSeatMemCshnAngPst_Req(uint8_t value) {
            m_FLSeatMemCshnAngPst_Req_ = value;
        }

        uint8_t& FLMemLegAngCshnExtPst_Req() OMG_NOEXCEPT {
            return m_FLMemLegAngCshnExtPst_Req_;
        }

        const uint8_t& FLMemLegAngCshnExtPst_Req() const OMG_NOEXCEPT {
            return m_FLMemLegAngCshnExtPst_Req_;
        }

        void FLMemLegAngCshnExtPst_Req(uint8_t value) {
            m_FLMemLegAngCshnExtPst_Req_ = value;
        }

        uint8_t& FLSeatMemLegLengthPst_Req() OMG_NOEXCEPT {
            return m_FLSeatMemLegLengthPst_Req_;
        }

        const uint8_t& FLSeatMemLegLengthPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatMemLegLengthPst_Req_;
        }

        void FLSeatMemLegLengthPst_Req(uint8_t value) {
            m_FLSeatMemLegLengthPst_Req_ = value;
        }

        bool operator == (const FLSeatMemPst_Req_struct& other_) const;
        bool operator != (const FLSeatMemPst_Req_struct& other_) const;

        void swap(FLSeatMemPst_Req_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLSeatMemPstPurpose_Req_;
        uint8_t m_FLSeatMemFBPst_Req_;
        uint8_t m_FLSeatMemBackrestPst_Req_;
        uint8_t m_FLSeatMemHgtPst_Req_;
        uint8_t m_FLSeatMemCshnAngPst_Req_;
        uint8_t m_FLMemLegAngCshnExtPst_Req_;
        uint8_t m_FLSeatMemLegLengthPst_Req_;

    };

    inline void swap(FLSeatMemPst_Req_struct& a, FLSeatMemPst_Req_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const FLSeatMemPst_Req_struct& sample);

    class NDDSUSERDllExport FRSeatMemPst_Req_struct {
      public:
        FRSeatMemPst_Req_struct();

        FRSeatMemPst_Req_struct(
            uint8_t FRSeatPstPurpose_Req,
            uint8_t FRSeatMemFBPst_Req,
            uint8_t FRSeatMemBackrestPst_Req,
            uint8_t FRSeatMemHgtPst_Req,
            uint8_t FRSeatMemCshnAngPst_Req,
            uint8_t FRSeatMemLegAngCshnExtPst_Req,
            uint8_t FRSeatMemLegLengthPst_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        FRSeatMemPst_Req_struct (FRSeatMemPst_Req_struct&&) = default;
        FRSeatMemPst_Req_struct& operator=(FRSeatMemPst_Req_struct&&) = default;
        FRSeatMemPst_Req_struct& operator=(const FRSeatMemPst_Req_struct&) = default;
        FRSeatMemPst_Req_struct(const FRSeatMemPst_Req_struct&) = default;
        #else
        FRSeatMemPst_Req_struct(FRSeatMemPst_Req_struct&& other_) OMG_NOEXCEPT;  
        FRSeatMemPst_Req_struct& operator=(FRSeatMemPst_Req_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FRSeatPstPurpose_Req() OMG_NOEXCEPT {
            return m_FRSeatPstPurpose_Req_;
        }

        const uint8_t& FRSeatPstPurpose_Req() const OMG_NOEXCEPT {
            return m_FRSeatPstPurpose_Req_;
        }

        void FRSeatPstPurpose_Req(uint8_t value) {
            m_FRSeatPstPurpose_Req_ = value;
        }

        uint8_t& FRSeatMemFBPst_Req() OMG_NOEXCEPT {
            return m_FRSeatMemFBPst_Req_;
        }

        const uint8_t& FRSeatMemFBPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatMemFBPst_Req_;
        }

        void FRSeatMemFBPst_Req(uint8_t value) {
            m_FRSeatMemFBPst_Req_ = value;
        }

        uint8_t& FRSeatMemBackrestPst_Req() OMG_NOEXCEPT {
            return m_FRSeatMemBackrestPst_Req_;
        }

        const uint8_t& FRSeatMemBackrestPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatMemBackrestPst_Req_;
        }

        void FRSeatMemBackrestPst_Req(uint8_t value) {
            m_FRSeatMemBackrestPst_Req_ = value;
        }

        uint8_t& FRSeatMemHgtPst_Req() OMG_NOEXCEPT {
            return m_FRSeatMemHgtPst_Req_;
        }

        const uint8_t& FRSeatMemHgtPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatMemHgtPst_Req_;
        }

        void FRSeatMemHgtPst_Req(uint8_t value) {
            m_FRSeatMemHgtPst_Req_ = value;
        }

        uint8_t& FRSeatMemCshnAngPst_Req() OMG_NOEXCEPT {
            return m_FRSeatMemCshnAngPst_Req_;
        }

        const uint8_t& FRSeatMemCshnAngPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatMemCshnAngPst_Req_;
        }

        void FRSeatMemCshnAngPst_Req(uint8_t value) {
            m_FRSeatMemCshnAngPst_Req_ = value;
        }

        uint8_t& FRSeatMemLegAngCshnExtPst_Req() OMG_NOEXCEPT {
            return m_FRSeatMemLegAngCshnExtPst_Req_;
        }

        const uint8_t& FRSeatMemLegAngCshnExtPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatMemLegAngCshnExtPst_Req_;
        }

        void FRSeatMemLegAngCshnExtPst_Req(uint8_t value) {
            m_FRSeatMemLegAngCshnExtPst_Req_ = value;
        }

        uint8_t& FRSeatMemLegLengthPst_Req() OMG_NOEXCEPT {
            return m_FRSeatMemLegLengthPst_Req_;
        }

        const uint8_t& FRSeatMemLegLengthPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatMemLegLengthPst_Req_;
        }

        void FRSeatMemLegLengthPst_Req(uint8_t value) {
            m_FRSeatMemLegLengthPst_Req_ = value;
        }

        bool operator == (const FRSeatMemPst_Req_struct& other_) const;
        bool operator != (const FRSeatMemPst_Req_struct& other_) const;

        void swap(FRSeatMemPst_Req_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FRSeatPstPurpose_Req_;
        uint8_t m_FRSeatMemFBPst_Req_;
        uint8_t m_FRSeatMemBackrestPst_Req_;
        uint8_t m_FRSeatMemHgtPst_Req_;
        uint8_t m_FRSeatMemCshnAngPst_Req_;
        uint8_t m_FRSeatMemLegAngCshnExtPst_Req_;
        uint8_t m_FRSeatMemLegLengthPst_Req_;

    };

    inline void swap(FRSeatMemPst_Req_struct& a, FRSeatMemPst_Req_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const FRSeatMemPst_Req_struct& sample);

    class NDDSUSERDllExport SRLSeatMemPst_Req_struct {
      public:
        SRLSeatMemPst_Req_struct();

        SRLSeatMemPst_Req_struct(
            uint8_t SRLSeatMemPstPurpose_Req,
            uint8_t SRLSeatMemFBPst_Req,
            uint8_t SRLSeatMemBackrestPst_Req,
            uint8_t SRLSeatMemHgtPst_Req,
            uint8_t SRLSeatMemCshnAngPst_Req,
            uint8_t SRLSeatMemLegAngCshnExtPst_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SRLSeatMemPst_Req_struct (SRLSeatMemPst_Req_struct&&) = default;
        SRLSeatMemPst_Req_struct& operator=(SRLSeatMemPst_Req_struct&&) = default;
        SRLSeatMemPst_Req_struct& operator=(const SRLSeatMemPst_Req_struct&) = default;
        SRLSeatMemPst_Req_struct(const SRLSeatMemPst_Req_struct&) = default;
        #else
        SRLSeatMemPst_Req_struct(SRLSeatMemPst_Req_struct&& other_) OMG_NOEXCEPT;  
        SRLSeatMemPst_Req_struct& operator=(SRLSeatMemPst_Req_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& SRLSeatMemPstPurpose_Req() OMG_NOEXCEPT {
            return m_SRLSeatMemPstPurpose_Req_;
        }

        const uint8_t& SRLSeatMemPstPurpose_Req() const OMG_NOEXCEPT {
            return m_SRLSeatMemPstPurpose_Req_;
        }

        void SRLSeatMemPstPurpose_Req(uint8_t value) {
            m_SRLSeatMemPstPurpose_Req_ = value;
        }

        uint8_t& SRLSeatMemFBPst_Req() OMG_NOEXCEPT {
            return m_SRLSeatMemFBPst_Req_;
        }

        const uint8_t& SRLSeatMemFBPst_Req() const OMG_NOEXCEPT {
            return m_SRLSeatMemFBPst_Req_;
        }

        void SRLSeatMemFBPst_Req(uint8_t value) {
            m_SRLSeatMemFBPst_Req_ = value;
        }

        uint8_t& SRLSeatMemBackrestPst_Req() OMG_NOEXCEPT {
            return m_SRLSeatMemBackrestPst_Req_;
        }

        const uint8_t& SRLSeatMemBackrestPst_Req() const OMG_NOEXCEPT {
            return m_SRLSeatMemBackrestPst_Req_;
        }

        void SRLSeatMemBackrestPst_Req(uint8_t value) {
            m_SRLSeatMemBackrestPst_Req_ = value;
        }

        uint8_t& SRLSeatMemHgtPst_Req() OMG_NOEXCEPT {
            return m_SRLSeatMemHgtPst_Req_;
        }

        const uint8_t& SRLSeatMemHgtPst_Req() const OMG_NOEXCEPT {
            return m_SRLSeatMemHgtPst_Req_;
        }

        void SRLSeatMemHgtPst_Req(uint8_t value) {
            m_SRLSeatMemHgtPst_Req_ = value;
        }

        uint8_t& SRLSeatMemCshnAngPst_Req() OMG_NOEXCEPT {
            return m_SRLSeatMemCshnAngPst_Req_;
        }

        const uint8_t& SRLSeatMemCshnAngPst_Req() const OMG_NOEXCEPT {
            return m_SRLSeatMemCshnAngPst_Req_;
        }

        void SRLSeatMemCshnAngPst_Req(uint8_t value) {
            m_SRLSeatMemCshnAngPst_Req_ = value;
        }

        uint8_t& SRLSeatMemLegAngCshnExtPst_Req() OMG_NOEXCEPT {
            return m_SRLSeatMemLegAngCshnExtPst_Req_;
        }

        const uint8_t& SRLSeatMemLegAngCshnExtPst_Req() const OMG_NOEXCEPT {
            return m_SRLSeatMemLegAngCshnExtPst_Req_;
        }

        void SRLSeatMemLegAngCshnExtPst_Req(uint8_t value) {
            m_SRLSeatMemLegAngCshnExtPst_Req_ = value;
        }

        bool operator == (const SRLSeatMemPst_Req_struct& other_) const;
        bool operator != (const SRLSeatMemPst_Req_struct& other_) const;

        void swap(SRLSeatMemPst_Req_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_SRLSeatMemPstPurpose_Req_;
        uint8_t m_SRLSeatMemFBPst_Req_;
        uint8_t m_SRLSeatMemBackrestPst_Req_;
        uint8_t m_SRLSeatMemHgtPst_Req_;
        uint8_t m_SRLSeatMemCshnAngPst_Req_;
        uint8_t m_SRLSeatMemLegAngCshnExtPst_Req_;

    };

    inline void swap(SRLSeatMemPst_Req_struct& a, SRLSeatMemPst_Req_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SRLSeatMemPst_Req_struct& sample);

    class NDDSUSERDllExport SRRSeatMemPst_Req_struct {
      public:
        SRRSeatMemPst_Req_struct();

        SRRSeatMemPst_Req_struct(
            uint8_t SRRSeatMemPstPurpose_Req,
            uint8_t SRRSeatMemFBPst_Req,
            uint8_t SRRSeatMemBackrestPst_Req,
            uint8_t SRRSeatMemHgtPst_Req,
            uint8_t SRRSeatMemCshnAngPst_Req,
            uint8_t SRRSeatMemLegAngCshnExtPst_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SRRSeatMemPst_Req_struct (SRRSeatMemPst_Req_struct&&) = default;
        SRRSeatMemPst_Req_struct& operator=(SRRSeatMemPst_Req_struct&&) = default;
        SRRSeatMemPst_Req_struct& operator=(const SRRSeatMemPst_Req_struct&) = default;
        SRRSeatMemPst_Req_struct(const SRRSeatMemPst_Req_struct&) = default;
        #else
        SRRSeatMemPst_Req_struct(SRRSeatMemPst_Req_struct&& other_) OMG_NOEXCEPT;  
        SRRSeatMemPst_Req_struct& operator=(SRRSeatMemPst_Req_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& SRRSeatMemPstPurpose_Req() OMG_NOEXCEPT {
            return m_SRRSeatMemPstPurpose_Req_;
        }

        const uint8_t& SRRSeatMemPstPurpose_Req() const OMG_NOEXCEPT {
            return m_SRRSeatMemPstPurpose_Req_;
        }

        void SRRSeatMemPstPurpose_Req(uint8_t value) {
            m_SRRSeatMemPstPurpose_Req_ = value;
        }

        uint8_t& SRRSeatMemFBPst_Req() OMG_NOEXCEPT {
            return m_SRRSeatMemFBPst_Req_;
        }

        const uint8_t& SRRSeatMemFBPst_Req() const OMG_NOEXCEPT {
            return m_SRRSeatMemFBPst_Req_;
        }

        void SRRSeatMemFBPst_Req(uint8_t value) {
            m_SRRSeatMemFBPst_Req_ = value;
        }

        uint8_t& SRRSeatMemBackrestPst_Req() OMG_NOEXCEPT {
            return m_SRRSeatMemBackrestPst_Req_;
        }

        const uint8_t& SRRSeatMemBackrestPst_Req() const OMG_NOEXCEPT {
            return m_SRRSeatMemBackrestPst_Req_;
        }

        void SRRSeatMemBackrestPst_Req(uint8_t value) {
            m_SRRSeatMemBackrestPst_Req_ = value;
        }

        uint8_t& SRRSeatMemHgtPst_Req() OMG_NOEXCEPT {
            return m_SRRSeatMemHgtPst_Req_;
        }

        const uint8_t& SRRSeatMemHgtPst_Req() const OMG_NOEXCEPT {
            return m_SRRSeatMemHgtPst_Req_;
        }

        void SRRSeatMemHgtPst_Req(uint8_t value) {
            m_SRRSeatMemHgtPst_Req_ = value;
        }

        uint8_t& SRRSeatMemCshnAngPst_Req() OMG_NOEXCEPT {
            return m_SRRSeatMemCshnAngPst_Req_;
        }

        const uint8_t& SRRSeatMemCshnAngPst_Req() const OMG_NOEXCEPT {
            return m_SRRSeatMemCshnAngPst_Req_;
        }

        void SRRSeatMemCshnAngPst_Req(uint8_t value) {
            m_SRRSeatMemCshnAngPst_Req_ = value;
        }

        uint8_t& SRRSeatMemLegAngCshnExtPst_Req() OMG_NOEXCEPT {
            return m_SRRSeatMemLegAngCshnExtPst_Req_;
        }

        const uint8_t& SRRSeatMemLegAngCshnExtPst_Req() const OMG_NOEXCEPT {
            return m_SRRSeatMemLegAngCshnExtPst_Req_;
        }

        void SRRSeatMemLegAngCshnExtPst_Req(uint8_t value) {
            m_SRRSeatMemLegAngCshnExtPst_Req_ = value;
        }

        bool operator == (const SRRSeatMemPst_Req_struct& other_) const;
        bool operator != (const SRRSeatMemPst_Req_struct& other_) const;

        void swap(SRRSeatMemPst_Req_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_SRRSeatMemPstPurpose_Req_;
        uint8_t m_SRRSeatMemFBPst_Req_;
        uint8_t m_SRRSeatMemBackrestPst_Req_;
        uint8_t m_SRRSeatMemHgtPst_Req_;
        uint8_t m_SRRSeatMemCshnAngPst_Req_;
        uint8_t m_SRRSeatMemLegAngCshnExtPst_Req_;

    };

    inline void swap(SRRSeatMemPst_Req_struct& a, SRRSeatMemPst_Req_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SRRSeatMemPst_Req_struct& sample);

    class NDDSUSERDllExport SteerMemPst_Req_struct {
      public:
        SteerMemPst_Req_struct();

        SteerMemPst_Req_struct(
            uint8_t SteerMemPstPurpose_Req,
            uint8_t SteerMemTiltPst_Req,
            uint8_t SteerMemTelePst_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SteerMemPst_Req_struct (SteerMemPst_Req_struct&&) = default;
        SteerMemPst_Req_struct& operator=(SteerMemPst_Req_struct&&) = default;
        SteerMemPst_Req_struct& operator=(const SteerMemPst_Req_struct&) = default;
        SteerMemPst_Req_struct(const SteerMemPst_Req_struct&) = default;
        #else
        SteerMemPst_Req_struct(SteerMemPst_Req_struct&& other_) OMG_NOEXCEPT;  
        SteerMemPst_Req_struct& operator=(SteerMemPst_Req_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& SteerMemPstPurpose_Req() OMG_NOEXCEPT {
            return m_SteerMemPstPurpose_Req_;
        }

        const uint8_t& SteerMemPstPurpose_Req() const OMG_NOEXCEPT {
            return m_SteerMemPstPurpose_Req_;
        }

        void SteerMemPstPurpose_Req(uint8_t value) {
            m_SteerMemPstPurpose_Req_ = value;
        }

        uint8_t& SteerMemTiltPst_Req() OMG_NOEXCEPT {
            return m_SteerMemTiltPst_Req_;
        }

        const uint8_t& SteerMemTiltPst_Req() const OMG_NOEXCEPT {
            return m_SteerMemTiltPst_Req_;
        }

        void SteerMemTiltPst_Req(uint8_t value) {
            m_SteerMemTiltPst_Req_ = value;
        }

        uint8_t& SteerMemTelePst_Req() OMG_NOEXCEPT {
            return m_SteerMemTelePst_Req_;
        }

        const uint8_t& SteerMemTelePst_Req() const OMG_NOEXCEPT {
            return m_SteerMemTelePst_Req_;
        }

        void SteerMemTelePst_Req(uint8_t value) {
            m_SteerMemTelePst_Req_ = value;
        }

        bool operator == (const SteerMemPst_Req_struct& other_) const;
        bool operator != (const SteerMemPst_Req_struct& other_) const;

        void swap(SteerMemPst_Req_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_SteerMemPstPurpose_Req_;
        uint8_t m_SteerMemTiltPst_Req_;
        uint8_t m_SteerMemTelePst_Req_;

    };

    inline void swap(SteerMemPst_Req_struct& a, SteerMemPst_Req_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SteerMemPst_Req_struct& sample);

    class NDDSUSERDllExport LExMirMemLRPst_Req_struct {
      public:
        LExMirMemLRPst_Req_struct();

        LExMirMemLRPst_Req_struct(
            uint8_t LExMirMemUDPst_Req,
            uint8_t LExMirMemLRPst_Req,
            uint8_t LExMirMemLRPstPurpose_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        LExMirMemLRPst_Req_struct (LExMirMemLRPst_Req_struct&&) = default;
        LExMirMemLRPst_Req_struct& operator=(LExMirMemLRPst_Req_struct&&) = default;
        LExMirMemLRPst_Req_struct& operator=(const LExMirMemLRPst_Req_struct&) = default;
        LExMirMemLRPst_Req_struct(const LExMirMemLRPst_Req_struct&) = default;
        #else
        LExMirMemLRPst_Req_struct(LExMirMemLRPst_Req_struct&& other_) OMG_NOEXCEPT;  
        LExMirMemLRPst_Req_struct& operator=(LExMirMemLRPst_Req_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& LExMirMemUDPst_Req() OMG_NOEXCEPT {
            return m_LExMirMemUDPst_Req_;
        }

        const uint8_t& LExMirMemUDPst_Req() const OMG_NOEXCEPT {
            return m_LExMirMemUDPst_Req_;
        }

        void LExMirMemUDPst_Req(uint8_t value) {
            m_LExMirMemUDPst_Req_ = value;
        }

        uint8_t& LExMirMemLRPst_Req() OMG_NOEXCEPT {
            return m_LExMirMemLRPst_Req_;
        }

        const uint8_t& LExMirMemLRPst_Req() const OMG_NOEXCEPT {
            return m_LExMirMemLRPst_Req_;
        }

        void LExMirMemLRPst_Req(uint8_t value) {
            m_LExMirMemLRPst_Req_ = value;
        }

        uint8_t& LExMirMemLRPstPurpose_Req() OMG_NOEXCEPT {
            return m_LExMirMemLRPstPurpose_Req_;
        }

        const uint8_t& LExMirMemLRPstPurpose_Req() const OMG_NOEXCEPT {
            return m_LExMirMemLRPstPurpose_Req_;
        }

        void LExMirMemLRPstPurpose_Req(uint8_t value) {
            m_LExMirMemLRPstPurpose_Req_ = value;
        }

        bool operator == (const LExMirMemLRPst_Req_struct& other_) const;
        bool operator != (const LExMirMemLRPst_Req_struct& other_) const;

        void swap(LExMirMemLRPst_Req_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_LExMirMemUDPst_Req_;
        uint8_t m_LExMirMemLRPst_Req_;
        uint8_t m_LExMirMemLRPstPurpose_Req_;

    };

    inline void swap(LExMirMemLRPst_Req_struct& a, LExMirMemLRPst_Req_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const LExMirMemLRPst_Req_struct& sample);

    class NDDSUSERDllExport RExMirMemLRPst_Req_struct {
      public:
        RExMirMemLRPst_Req_struct();

        RExMirMemLRPst_Req_struct(
            uint8_t RExMirMemUDPst_Req,
            uint8_t RExMirMemLRPst_Req,
            uint8_t RExMirMemLRPstPurpose_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        RExMirMemLRPst_Req_struct (RExMirMemLRPst_Req_struct&&) = default;
        RExMirMemLRPst_Req_struct& operator=(RExMirMemLRPst_Req_struct&&) = default;
        RExMirMemLRPst_Req_struct& operator=(const RExMirMemLRPst_Req_struct&) = default;
        RExMirMemLRPst_Req_struct(const RExMirMemLRPst_Req_struct&) = default;
        #else
        RExMirMemLRPst_Req_struct(RExMirMemLRPst_Req_struct&& other_) OMG_NOEXCEPT;  
        RExMirMemLRPst_Req_struct& operator=(RExMirMemLRPst_Req_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& RExMirMemUDPst_Req() OMG_NOEXCEPT {
            return m_RExMirMemUDPst_Req_;
        }

        const uint8_t& RExMirMemUDPst_Req() const OMG_NOEXCEPT {
            return m_RExMirMemUDPst_Req_;
        }

        void RExMirMemUDPst_Req(uint8_t value) {
            m_RExMirMemUDPst_Req_ = value;
        }

        uint8_t& RExMirMemLRPst_Req() OMG_NOEXCEPT {
            return m_RExMirMemLRPst_Req_;
        }

        const uint8_t& RExMirMemLRPst_Req() const OMG_NOEXCEPT {
            return m_RExMirMemLRPst_Req_;
        }

        void RExMirMemLRPst_Req(uint8_t value) {
            m_RExMirMemLRPst_Req_ = value;
        }

        uint8_t& RExMirMemLRPstPurpose_Req() OMG_NOEXCEPT {
            return m_RExMirMemLRPstPurpose_Req_;
        }

        const uint8_t& RExMirMemLRPstPurpose_Req() const OMG_NOEXCEPT {
            return m_RExMirMemLRPstPurpose_Req_;
        }

        void RExMirMemLRPstPurpose_Req(uint8_t value) {
            m_RExMirMemLRPstPurpose_Req_ = value;
        }

        bool operator == (const RExMirMemLRPst_Req_struct& other_) const;
        bool operator != (const RExMirMemLRPst_Req_struct& other_) const;

        void swap(RExMirMemLRPst_Req_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_RExMirMemUDPst_Req_;
        uint8_t m_RExMirMemLRPst_Req_;
        uint8_t m_RExMirMemLRPstPurpose_Req_;

    };

    inline void swap(RExMirMemLRPst_Req_struct& a, RExMirMemLRPst_Req_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const RExMirMemLRPst_Req_struct& sample);

    class NDDSUSERDllExport BdMemPst_Set_struct {
      public:
        BdMemPst_Set_struct();

        BdMemPst_Set_struct(
            const ::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 5L>& FLSeatMemPst_Req,
            const ::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 4L>& FRSeatMemPst_Req,
            const ::dds::core::array< BodyDomain::SRLSeatMemPst_Req_struct, 2L>& SRLSeatMemPst_Req,
            const ::dds::core::array< BodyDomain::SRRSeatMemPst_Req_struct, 2L>& SRRSeatMemPst_Req,
            const ::dds::core::array< BodyDomain::SteerMemPst_Req_struct, 5L>& SteerMemPst_Req,
            const ::dds::core::array< BodyDomain::LExMirMemLRPst_Req_struct, 8L>& LExMirMemLRPst_Req,
            const ::dds::core::array< BodyDomain::RExMirMemLRPst_Req_struct, 8L>& RExMirMemLRPst_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdMemPst_Set_struct (BdMemPst_Set_struct&&) = default;
        BdMemPst_Set_struct& operator=(BdMemPst_Set_struct&&) = default;
        BdMemPst_Set_struct& operator=(const BdMemPst_Set_struct&) = default;
        BdMemPst_Set_struct(const BdMemPst_Set_struct&) = default;
        #else
        BdMemPst_Set_struct(BdMemPst_Set_struct&& other_) OMG_NOEXCEPT;  
        BdMemPst_Set_struct& operator=(BdMemPst_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 5L>& FLSeatMemPst_Req() OMG_NOEXCEPT {
            return m_FLSeatMemPst_Req_;
        }

        const ::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 5L>& FLSeatMemPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatMemPst_Req_;
        }

        void FLSeatMemPst_Req(const ::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 5L>& value) {
            m_FLSeatMemPst_Req_ = value;
        }

        void FLSeatMemPst_Req(::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 5L>&& value) {
            m_FLSeatMemPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 4L>& FRSeatMemPst_Req() OMG_NOEXCEPT {
            return m_FRSeatMemPst_Req_;
        }

        const ::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 4L>& FRSeatMemPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatMemPst_Req_;
        }

        void FRSeatMemPst_Req(const ::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 4L>& value) {
            m_FRSeatMemPst_Req_ = value;
        }

        void FRSeatMemPst_Req(::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 4L>&& value) {
            m_FRSeatMemPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::SRLSeatMemPst_Req_struct, 2L>& SRLSeatMemPst_Req() OMG_NOEXCEPT {
            return m_SRLSeatMemPst_Req_;
        }

        const ::dds::core::array< BodyDomain::SRLSeatMemPst_Req_struct, 2L>& SRLSeatMemPst_Req() const OMG_NOEXCEPT {
            return m_SRLSeatMemPst_Req_;
        }

        void SRLSeatMemPst_Req(const ::dds::core::array< BodyDomain::SRLSeatMemPst_Req_struct, 2L>& value) {
            m_SRLSeatMemPst_Req_ = value;
        }

        void SRLSeatMemPst_Req(::dds::core::array< BodyDomain::SRLSeatMemPst_Req_struct, 2L>&& value) {
            m_SRLSeatMemPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::SRRSeatMemPst_Req_struct, 2L>& SRRSeatMemPst_Req() OMG_NOEXCEPT {
            return m_SRRSeatMemPst_Req_;
        }

        const ::dds::core::array< BodyDomain::SRRSeatMemPst_Req_struct, 2L>& SRRSeatMemPst_Req() const OMG_NOEXCEPT {
            return m_SRRSeatMemPst_Req_;
        }

        void SRRSeatMemPst_Req(const ::dds::core::array< BodyDomain::SRRSeatMemPst_Req_struct, 2L>& value) {
            m_SRRSeatMemPst_Req_ = value;
        }

        void SRRSeatMemPst_Req(::dds::core::array< BodyDomain::SRRSeatMemPst_Req_struct, 2L>&& value) {
            m_SRRSeatMemPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::SteerMemPst_Req_struct, 5L>& SteerMemPst_Req() OMG_NOEXCEPT {
            return m_SteerMemPst_Req_;
        }

        const ::dds::core::array< BodyDomain::SteerMemPst_Req_struct, 5L>& SteerMemPst_Req() const OMG_NOEXCEPT {
            return m_SteerMemPst_Req_;
        }

        void SteerMemPst_Req(const ::dds::core::array< BodyDomain::SteerMemPst_Req_struct, 5L>& value) {
            m_SteerMemPst_Req_ = value;
        }

        void SteerMemPst_Req(::dds::core::array< BodyDomain::SteerMemPst_Req_struct, 5L>&& value) {
            m_SteerMemPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::LExMirMemLRPst_Req_struct, 8L>& LExMirMemLRPst_Req() OMG_NOEXCEPT {
            return m_LExMirMemLRPst_Req_;
        }

        const ::dds::core::array< BodyDomain::LExMirMemLRPst_Req_struct, 8L>& LExMirMemLRPst_Req() const OMG_NOEXCEPT {
            return m_LExMirMemLRPst_Req_;
        }

        void LExMirMemLRPst_Req(const ::dds::core::array< BodyDomain::LExMirMemLRPst_Req_struct, 8L>& value) {
            m_LExMirMemLRPst_Req_ = value;
        }

        void LExMirMemLRPst_Req(::dds::core::array< BodyDomain::LExMirMemLRPst_Req_struct, 8L>&& value) {
            m_LExMirMemLRPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::RExMirMemLRPst_Req_struct, 8L>& RExMirMemLRPst_Req() OMG_NOEXCEPT {
            return m_RExMirMemLRPst_Req_;
        }

        const ::dds::core::array< BodyDomain::RExMirMemLRPst_Req_struct, 8L>& RExMirMemLRPst_Req() const OMG_NOEXCEPT {
            return m_RExMirMemLRPst_Req_;
        }

        void RExMirMemLRPst_Req(const ::dds::core::array< BodyDomain::RExMirMemLRPst_Req_struct, 8L>& value) {
            m_RExMirMemLRPst_Req_ = value;
        }

        void RExMirMemLRPst_Req(::dds::core::array< BodyDomain::RExMirMemLRPst_Req_struct, 8L>&& value) {
            m_RExMirMemLRPst_Req_ = std::move(value);
        }

        bool operator == (const BdMemPst_Set_struct& other_) const;
        bool operator != (const BdMemPst_Set_struct& other_) const;

        void swap(BdMemPst_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        ::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 5L> m_FLSeatMemPst_Req_;
        ::dds::core::array< BodyDomain::FRSeatMemPst_Req_struct, 4L> m_FRSeatMemPst_Req_;
        ::dds::core::array< BodyDomain::SRLSeatMemPst_Req_struct, 2L> m_SRLSeatMemPst_Req_;
        ::dds::core::array< BodyDomain::SRRSeatMemPst_Req_struct, 2L> m_SRRSeatMemPst_Req_;
        ::dds::core::array< BodyDomain::SteerMemPst_Req_struct, 5L> m_SteerMemPst_Req_;
        ::dds::core::array< BodyDomain::LExMirMemLRPst_Req_struct, 8L> m_LExMirMemLRPst_Req_;
        ::dds::core::array< BodyDomain::RExMirMemLRPst_Req_struct, 8L> m_RExMirMemLRPst_Req_;

    };

    inline void swap(BdMemPst_Set_struct& a, BdMemPst_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdMemPst_Set_struct& sample);

    class NDDSUSERDllExport BdMemPst_Get_struct {
      public:
        BdMemPst_Get_struct();

        BdMemPst_Get_struct(
            uint8_t FLSeatMemPstGet_Req,
            uint8_t FRSeatMemPstGet_Req,
            uint8_t SRLSeatMemPstGet_Req,
            uint8_t SRRSeatMemPstGet_Req,
            uint8_t SteerMemPstGet_Req,
            uint8_t LExMirMemLRPstGet_Req,
            uint8_t RExMirMemLRPstGet_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdMemPst_Get_struct (BdMemPst_Get_struct&&) = default;
        BdMemPst_Get_struct& operator=(BdMemPst_Get_struct&&) = default;
        BdMemPst_Get_struct& operator=(const BdMemPst_Get_struct&) = default;
        BdMemPst_Get_struct(const BdMemPst_Get_struct&) = default;
        #else
        BdMemPst_Get_struct(BdMemPst_Get_struct&& other_) OMG_NOEXCEPT;  
        BdMemPst_Get_struct& operator=(BdMemPst_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLSeatMemPstGet_Req() OMG_NOEXCEPT {
            return m_FLSeatMemPstGet_Req_;
        }

        const uint8_t& FLSeatMemPstGet_Req() const OMG_NOEXCEPT {
            return m_FLSeatMemPstGet_Req_;
        }

        void FLSeatMemPstGet_Req(uint8_t value) {
            m_FLSeatMemPstGet_Req_ = value;
        }

        uint8_t& FRSeatMemPstGet_Req() OMG_NOEXCEPT {
            return m_FRSeatMemPstGet_Req_;
        }

        const uint8_t& FRSeatMemPstGet_Req() const OMG_NOEXCEPT {
            return m_FRSeatMemPstGet_Req_;
        }

        void FRSeatMemPstGet_Req(uint8_t value) {
            m_FRSeatMemPstGet_Req_ = value;
        }

        uint8_t& SRLSeatMemPstGet_Req() OMG_NOEXCEPT {
            return m_SRLSeatMemPstGet_Req_;
        }

        const uint8_t& SRLSeatMemPstGet_Req() const OMG_NOEXCEPT {
            return m_SRLSeatMemPstGet_Req_;
        }

        void SRLSeatMemPstGet_Req(uint8_t value) {
            m_SRLSeatMemPstGet_Req_ = value;
        }

        uint8_t& SRRSeatMemPstGet_Req() OMG_NOEXCEPT {
            return m_SRRSeatMemPstGet_Req_;
        }

        const uint8_t& SRRSeatMemPstGet_Req() const OMG_NOEXCEPT {
            return m_SRRSeatMemPstGet_Req_;
        }

        void SRRSeatMemPstGet_Req(uint8_t value) {
            m_SRRSeatMemPstGet_Req_ = value;
        }

        uint8_t& SteerMemPstGet_Req() OMG_NOEXCEPT {
            return m_SteerMemPstGet_Req_;
        }

        const uint8_t& SteerMemPstGet_Req() const OMG_NOEXCEPT {
            return m_SteerMemPstGet_Req_;
        }

        void SteerMemPstGet_Req(uint8_t value) {
            m_SteerMemPstGet_Req_ = value;
        }

        uint8_t& LExMirMemLRPstGet_Req() OMG_NOEXCEPT {
            return m_LExMirMemLRPstGet_Req_;
        }

        const uint8_t& LExMirMemLRPstGet_Req() const OMG_NOEXCEPT {
            return m_LExMirMemLRPstGet_Req_;
        }

        void LExMirMemLRPstGet_Req(uint8_t value) {
            m_LExMirMemLRPstGet_Req_ = value;
        }

        uint8_t& RExMirMemLRPstGet_Req() OMG_NOEXCEPT {
            return m_RExMirMemLRPstGet_Req_;
        }

        const uint8_t& RExMirMemLRPstGet_Req() const OMG_NOEXCEPT {
            return m_RExMirMemLRPstGet_Req_;
        }

        void RExMirMemLRPstGet_Req(uint8_t value) {
            m_RExMirMemLRPstGet_Req_ = value;
        }

        bool operator == (const BdMemPst_Get_struct& other_) const;
        bool operator != (const BdMemPst_Get_struct& other_) const;

        void swap(BdMemPst_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLSeatMemPstGet_Req_;
        uint8_t m_FRSeatMemPstGet_Req_;
        uint8_t m_SRLSeatMemPstGet_Req_;
        uint8_t m_SRRSeatMemPstGet_Req_;
        uint8_t m_SteerMemPstGet_Req_;
        uint8_t m_LExMirMemLRPstGet_Req_;
        uint8_t m_RExMirMemLRPstGet_Req_;

    };

    inline void swap(BdMemPst_Get_struct& a, BdMemPst_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdMemPst_Get_struct& sample);

    class NDDSUSERDllExport FLSeatMemPst_Rsp_struct {
      public:
        FLSeatMemPst_Rsp_struct();

        FLSeatMemPst_Rsp_struct(
            uint8_t FLSeatMemPstPurpose_Rsp,
            uint8_t FLSeatMemFBPst_Rsp,
            uint8_t FLSeatMemBackrestPst_Rsp,
            uint8_t FLSeatMemHgtPst_Rsp,
            uint8_t FLSeatMemCshnAngPst_Rsp,
            uint8_t FLSeatMemLegAngCshnExtPst_Rsp,
            uint8_t FLSeatMemLegLengthPst_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        FLSeatMemPst_Rsp_struct (FLSeatMemPst_Rsp_struct&&) = default;
        FLSeatMemPst_Rsp_struct& operator=(FLSeatMemPst_Rsp_struct&&) = default;
        FLSeatMemPst_Rsp_struct& operator=(const FLSeatMemPst_Rsp_struct&) = default;
        FLSeatMemPst_Rsp_struct(const FLSeatMemPst_Rsp_struct&) = default;
        #else
        FLSeatMemPst_Rsp_struct(FLSeatMemPst_Rsp_struct&& other_) OMG_NOEXCEPT;  
        FLSeatMemPst_Rsp_struct& operator=(FLSeatMemPst_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLSeatMemPstPurpose_Rsp() OMG_NOEXCEPT {
            return m_FLSeatMemPstPurpose_Rsp_;
        }

        const uint8_t& FLSeatMemPstPurpose_Rsp() const OMG_NOEXCEPT {
            return m_FLSeatMemPstPurpose_Rsp_;
        }

        void FLSeatMemPstPurpose_Rsp(uint8_t value) {
            m_FLSeatMemPstPurpose_Rsp_ = value;
        }

        uint8_t& FLSeatMemFBPst_Rsp() OMG_NOEXCEPT {
            return m_FLSeatMemFBPst_Rsp_;
        }

        const uint8_t& FLSeatMemFBPst_Rsp() const OMG_NOEXCEPT {
            return m_FLSeatMemFBPst_Rsp_;
        }

        void FLSeatMemFBPst_Rsp(uint8_t value) {
            m_FLSeatMemFBPst_Rsp_ = value;
        }

        uint8_t& FLSeatMemBackrestPst_Rsp() OMG_NOEXCEPT {
            return m_FLSeatMemBackrestPst_Rsp_;
        }

        const uint8_t& FLSeatMemBackrestPst_Rsp() const OMG_NOEXCEPT {
            return m_FLSeatMemBackrestPst_Rsp_;
        }

        void FLSeatMemBackrestPst_Rsp(uint8_t value) {
            m_FLSeatMemBackrestPst_Rsp_ = value;
        }

        uint8_t& FLSeatMemHgtPst_Rsp() OMG_NOEXCEPT {
            return m_FLSeatMemHgtPst_Rsp_;
        }

        const uint8_t& FLSeatMemHgtPst_Rsp() const OMG_NOEXCEPT {
            return m_FLSeatMemHgtPst_Rsp_;
        }

        void FLSeatMemHgtPst_Rsp(uint8_t value) {
            m_FLSeatMemHgtPst_Rsp_ = value;
        }

        uint8_t& FLSeatMemCshnAngPst_Rsp() OMG_NOEXCEPT {
            return m_FLSeatMemCshnAngPst_Rsp_;
        }

        const uint8_t& FLSeatMemCshnAngPst_Rsp() const OMG_NOEXCEPT {
            return m_FLSeatMemCshnAngPst_Rsp_;
        }

        void FLSeatMemCshnAngPst_Rsp(uint8_t value) {
            m_FLSeatMemCshnAngPst_Rsp_ = value;
        }

        uint8_t& FLSeatMemLegAngCshnExtPst_Rsp() OMG_NOEXCEPT {
            return m_FLSeatMemLegAngCshnExtPst_Rsp_;
        }

        const uint8_t& FLSeatMemLegAngCshnExtPst_Rsp() const OMG_NOEXCEPT {
            return m_FLSeatMemLegAngCshnExtPst_Rsp_;
        }

        void FLSeatMemLegAngCshnExtPst_Rsp(uint8_t value) {
            m_FLSeatMemLegAngCshnExtPst_Rsp_ = value;
        }

        uint8_t& FLSeatMemLegLengthPst_Rsp() OMG_NOEXCEPT {
            return m_FLSeatMemLegLengthPst_Rsp_;
        }

        const uint8_t& FLSeatMemLegLengthPst_Rsp() const OMG_NOEXCEPT {
            return m_FLSeatMemLegLengthPst_Rsp_;
        }

        void FLSeatMemLegLengthPst_Rsp(uint8_t value) {
            m_FLSeatMemLegLengthPst_Rsp_ = value;
        }

        bool operator == (const FLSeatMemPst_Rsp_struct& other_) const;
        bool operator != (const FLSeatMemPst_Rsp_struct& other_) const;

        void swap(FLSeatMemPst_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLSeatMemPstPurpose_Rsp_;
        uint8_t m_FLSeatMemFBPst_Rsp_;
        uint8_t m_FLSeatMemBackrestPst_Rsp_;
        uint8_t m_FLSeatMemHgtPst_Rsp_;
        uint8_t m_FLSeatMemCshnAngPst_Rsp_;
        uint8_t m_FLSeatMemLegAngCshnExtPst_Rsp_;
        uint8_t m_FLSeatMemLegLengthPst_Rsp_;

    };

    inline void swap(FLSeatMemPst_Rsp_struct& a, FLSeatMemPst_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const FLSeatMemPst_Rsp_struct& sample);

    class NDDSUSERDllExport FRSeatMemPst_Rsp_struct {
      public:
        FRSeatMemPst_Rsp_struct();

        FRSeatMemPst_Rsp_struct(
            uint8_t FRSeatMemPstPurpose_Rsp,
            uint8_t FRSeatMemFBPst_Rsp,
            uint8_t FRSeatMemBackrestPst_Rsp,
            uint8_t FRSeatMemHgtPst_Rsp,
            uint8_t FRSeatMemCshnAngPst_Rsp,
            uint8_t FRSeatMemLegAngCshnExtPst_Rsp,
            uint8_t FRSeatMemLegLengthPst_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        FRSeatMemPst_Rsp_struct (FRSeatMemPst_Rsp_struct&&) = default;
        FRSeatMemPst_Rsp_struct& operator=(FRSeatMemPst_Rsp_struct&&) = default;
        FRSeatMemPst_Rsp_struct& operator=(const FRSeatMemPst_Rsp_struct&) = default;
        FRSeatMemPst_Rsp_struct(const FRSeatMemPst_Rsp_struct&) = default;
        #else
        FRSeatMemPst_Rsp_struct(FRSeatMemPst_Rsp_struct&& other_) OMG_NOEXCEPT;  
        FRSeatMemPst_Rsp_struct& operator=(FRSeatMemPst_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FRSeatMemPstPurpose_Rsp() OMG_NOEXCEPT {
            return m_FRSeatMemPstPurpose_Rsp_;
        }

        const uint8_t& FRSeatMemPstPurpose_Rsp() const OMG_NOEXCEPT {
            return m_FRSeatMemPstPurpose_Rsp_;
        }

        void FRSeatMemPstPurpose_Rsp(uint8_t value) {
            m_FRSeatMemPstPurpose_Rsp_ = value;
        }

        uint8_t& FRSeatMemFBPst_Rsp() OMG_NOEXCEPT {
            return m_FRSeatMemFBPst_Rsp_;
        }

        const uint8_t& FRSeatMemFBPst_Rsp() const OMG_NOEXCEPT {
            return m_FRSeatMemFBPst_Rsp_;
        }

        void FRSeatMemFBPst_Rsp(uint8_t value) {
            m_FRSeatMemFBPst_Rsp_ = value;
        }

        uint8_t& FRSeatMemBackrestPst_Rsp() OMG_NOEXCEPT {
            return m_FRSeatMemBackrestPst_Rsp_;
        }

        const uint8_t& FRSeatMemBackrestPst_Rsp() const OMG_NOEXCEPT {
            return m_FRSeatMemBackrestPst_Rsp_;
        }

        void FRSeatMemBackrestPst_Rsp(uint8_t value) {
            m_FRSeatMemBackrestPst_Rsp_ = value;
        }

        uint8_t& FRSeatMemHgtPst_Rsp() OMG_NOEXCEPT {
            return m_FRSeatMemHgtPst_Rsp_;
        }

        const uint8_t& FRSeatMemHgtPst_Rsp() const OMG_NOEXCEPT {
            return m_FRSeatMemHgtPst_Rsp_;
        }

        void FRSeatMemHgtPst_Rsp(uint8_t value) {
            m_FRSeatMemHgtPst_Rsp_ = value;
        }

        uint8_t& FRSeatMemCshnAngPst_Rsp() OMG_NOEXCEPT {
            return m_FRSeatMemCshnAngPst_Rsp_;
        }

        const uint8_t& FRSeatMemCshnAngPst_Rsp() const OMG_NOEXCEPT {
            return m_FRSeatMemCshnAngPst_Rsp_;
        }

        void FRSeatMemCshnAngPst_Rsp(uint8_t value) {
            m_FRSeatMemCshnAngPst_Rsp_ = value;
        }

        uint8_t& FRSeatMemLegAngCshnExtPst_Rsp() OMG_NOEXCEPT {
            return m_FRSeatMemLegAngCshnExtPst_Rsp_;
        }

        const uint8_t& FRSeatMemLegAngCshnExtPst_Rsp() const OMG_NOEXCEPT {
            return m_FRSeatMemLegAngCshnExtPst_Rsp_;
        }

        void FRSeatMemLegAngCshnExtPst_Rsp(uint8_t value) {
            m_FRSeatMemLegAngCshnExtPst_Rsp_ = value;
        }

        uint8_t& FRSeatMemLegLengthPst_Rsp() OMG_NOEXCEPT {
            return m_FRSeatMemLegLengthPst_Rsp_;
        }

        const uint8_t& FRSeatMemLegLengthPst_Rsp() const OMG_NOEXCEPT {
            return m_FRSeatMemLegLengthPst_Rsp_;
        }

        void FRSeatMemLegLengthPst_Rsp(uint8_t value) {
            m_FRSeatMemLegLengthPst_Rsp_ = value;
        }

        bool operator == (const FRSeatMemPst_Rsp_struct& other_) const;
        bool operator != (const FRSeatMemPst_Rsp_struct& other_) const;

        void swap(FRSeatMemPst_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FRSeatMemPstPurpose_Rsp_;
        uint8_t m_FRSeatMemFBPst_Rsp_;
        uint8_t m_FRSeatMemBackrestPst_Rsp_;
        uint8_t m_FRSeatMemHgtPst_Rsp_;
        uint8_t m_FRSeatMemCshnAngPst_Rsp_;
        uint8_t m_FRSeatMemLegAngCshnExtPst_Rsp_;
        uint8_t m_FRSeatMemLegLengthPst_Rsp_;

    };

    inline void swap(FRSeatMemPst_Rsp_struct& a, FRSeatMemPst_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const FRSeatMemPst_Rsp_struct& sample);

    class NDDSUSERDllExport SRLSeatMemPst_Rsp_struct {
      public:
        SRLSeatMemPst_Rsp_struct();

        SRLSeatMemPst_Rsp_struct(
            uint8_t SRLSeatMemPstPurpose_Rsp,
            uint8_t SRLSeatMemFBPst_Rsp,
            uint8_t SRLSeatMemBackrestPst_Rsp,
            uint8_t SRLSeatMemHgtPst_Rsp,
            uint8_t SRLSeatMemCshnAngPst_Rsp,
            uint8_t SRLSeatMemLegAngCshnExtPst_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SRLSeatMemPst_Rsp_struct (SRLSeatMemPst_Rsp_struct&&) = default;
        SRLSeatMemPst_Rsp_struct& operator=(SRLSeatMemPst_Rsp_struct&&) = default;
        SRLSeatMemPst_Rsp_struct& operator=(const SRLSeatMemPst_Rsp_struct&) = default;
        SRLSeatMemPst_Rsp_struct(const SRLSeatMemPst_Rsp_struct&) = default;
        #else
        SRLSeatMemPst_Rsp_struct(SRLSeatMemPst_Rsp_struct&& other_) OMG_NOEXCEPT;  
        SRLSeatMemPst_Rsp_struct& operator=(SRLSeatMemPst_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& SRLSeatMemPstPurpose_Rsp() OMG_NOEXCEPT {
            return m_SRLSeatMemPstPurpose_Rsp_;
        }

        const uint8_t& SRLSeatMemPstPurpose_Rsp() const OMG_NOEXCEPT {
            return m_SRLSeatMemPstPurpose_Rsp_;
        }

        void SRLSeatMemPstPurpose_Rsp(uint8_t value) {
            m_SRLSeatMemPstPurpose_Rsp_ = value;
        }

        uint8_t& SRLSeatMemFBPst_Rsp() OMG_NOEXCEPT {
            return m_SRLSeatMemFBPst_Rsp_;
        }

        const uint8_t& SRLSeatMemFBPst_Rsp() const OMG_NOEXCEPT {
            return m_SRLSeatMemFBPst_Rsp_;
        }

        void SRLSeatMemFBPst_Rsp(uint8_t value) {
            m_SRLSeatMemFBPst_Rsp_ = value;
        }

        uint8_t& SRLSeatMemBackrestPst_Rsp() OMG_NOEXCEPT {
            return m_SRLSeatMemBackrestPst_Rsp_;
        }

        const uint8_t& SRLSeatMemBackrestPst_Rsp() const OMG_NOEXCEPT {
            return m_SRLSeatMemBackrestPst_Rsp_;
        }

        void SRLSeatMemBackrestPst_Rsp(uint8_t value) {
            m_SRLSeatMemBackrestPst_Rsp_ = value;
        }

        uint8_t& SRLSeatMemHgtPst_Rsp() OMG_NOEXCEPT {
            return m_SRLSeatMemHgtPst_Rsp_;
        }

        const uint8_t& SRLSeatMemHgtPst_Rsp() const OMG_NOEXCEPT {
            return m_SRLSeatMemHgtPst_Rsp_;
        }

        void SRLSeatMemHgtPst_Rsp(uint8_t value) {
            m_SRLSeatMemHgtPst_Rsp_ = value;
        }

        uint8_t& SRLSeatMemCshnAngPst_Rsp() OMG_NOEXCEPT {
            return m_SRLSeatMemCshnAngPst_Rsp_;
        }

        const uint8_t& SRLSeatMemCshnAngPst_Rsp() const OMG_NOEXCEPT {
            return m_SRLSeatMemCshnAngPst_Rsp_;
        }

        void SRLSeatMemCshnAngPst_Rsp(uint8_t value) {
            m_SRLSeatMemCshnAngPst_Rsp_ = value;
        }

        uint8_t& SRLSeatMemLegAngCshnExtPst_Rsp() OMG_NOEXCEPT {
            return m_SRLSeatMemLegAngCshnExtPst_Rsp_;
        }

        const uint8_t& SRLSeatMemLegAngCshnExtPst_Rsp() const OMG_NOEXCEPT {
            return m_SRLSeatMemLegAngCshnExtPst_Rsp_;
        }

        void SRLSeatMemLegAngCshnExtPst_Rsp(uint8_t value) {
            m_SRLSeatMemLegAngCshnExtPst_Rsp_ = value;
        }

        bool operator == (const SRLSeatMemPst_Rsp_struct& other_) const;
        bool operator != (const SRLSeatMemPst_Rsp_struct& other_) const;

        void swap(SRLSeatMemPst_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_SRLSeatMemPstPurpose_Rsp_;
        uint8_t m_SRLSeatMemFBPst_Rsp_;
        uint8_t m_SRLSeatMemBackrestPst_Rsp_;
        uint8_t m_SRLSeatMemHgtPst_Rsp_;
        uint8_t m_SRLSeatMemCshnAngPst_Rsp_;
        uint8_t m_SRLSeatMemLegAngCshnExtPst_Rsp_;

    };

    inline void swap(SRLSeatMemPst_Rsp_struct& a, SRLSeatMemPst_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SRLSeatMemPst_Rsp_struct& sample);

    class NDDSUSERDllExport SRRSeatMemPst_Rsp_struct {
      public:
        SRRSeatMemPst_Rsp_struct();

        SRRSeatMemPst_Rsp_struct(
            uint8_t SRRSeatMemPstPurpose_Rsp,
            uint8_t SRRSeatMemFBPst_Rsp,
            uint8_t SRRSeatMemBackrestPst_Rsp,
            uint8_t SRRSeatMemHgtPst_Rsp,
            uint8_t SRRSeatMemCshnAngPst_Rsp,
            uint8_t SRRSeatMemLegAngCshnExtPst_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SRRSeatMemPst_Rsp_struct (SRRSeatMemPst_Rsp_struct&&) = default;
        SRRSeatMemPst_Rsp_struct& operator=(SRRSeatMemPst_Rsp_struct&&) = default;
        SRRSeatMemPst_Rsp_struct& operator=(const SRRSeatMemPst_Rsp_struct&) = default;
        SRRSeatMemPst_Rsp_struct(const SRRSeatMemPst_Rsp_struct&) = default;
        #else
        SRRSeatMemPst_Rsp_struct(SRRSeatMemPst_Rsp_struct&& other_) OMG_NOEXCEPT;  
        SRRSeatMemPst_Rsp_struct& operator=(SRRSeatMemPst_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& SRRSeatMemPstPurpose_Rsp() OMG_NOEXCEPT {
            return m_SRRSeatMemPstPurpose_Rsp_;
        }

        const uint8_t& SRRSeatMemPstPurpose_Rsp() const OMG_NOEXCEPT {
            return m_SRRSeatMemPstPurpose_Rsp_;
        }

        void SRRSeatMemPstPurpose_Rsp(uint8_t value) {
            m_SRRSeatMemPstPurpose_Rsp_ = value;
        }

        uint8_t& SRRSeatMemFBPst_Rsp() OMG_NOEXCEPT {
            return m_SRRSeatMemFBPst_Rsp_;
        }

        const uint8_t& SRRSeatMemFBPst_Rsp() const OMG_NOEXCEPT {
            return m_SRRSeatMemFBPst_Rsp_;
        }

        void SRRSeatMemFBPst_Rsp(uint8_t value) {
            m_SRRSeatMemFBPst_Rsp_ = value;
        }

        uint8_t& SRRSeatMemBackrestPst_Rsp() OMG_NOEXCEPT {
            return m_SRRSeatMemBackrestPst_Rsp_;
        }

        const uint8_t& SRRSeatMemBackrestPst_Rsp() const OMG_NOEXCEPT {
            return m_SRRSeatMemBackrestPst_Rsp_;
        }

        void SRRSeatMemBackrestPst_Rsp(uint8_t value) {
            m_SRRSeatMemBackrestPst_Rsp_ = value;
        }

        uint8_t& SRRSeatMemHgtPst_Rsp() OMG_NOEXCEPT {
            return m_SRRSeatMemHgtPst_Rsp_;
        }

        const uint8_t& SRRSeatMemHgtPst_Rsp() const OMG_NOEXCEPT {
            return m_SRRSeatMemHgtPst_Rsp_;
        }

        void SRRSeatMemHgtPst_Rsp(uint8_t value) {
            m_SRRSeatMemHgtPst_Rsp_ = value;
        }

        uint8_t& SRRSeatMemCshnAngPst_Rsp() OMG_NOEXCEPT {
            return m_SRRSeatMemCshnAngPst_Rsp_;
        }

        const uint8_t& SRRSeatMemCshnAngPst_Rsp() const OMG_NOEXCEPT {
            return m_SRRSeatMemCshnAngPst_Rsp_;
        }

        void SRRSeatMemCshnAngPst_Rsp(uint8_t value) {
            m_SRRSeatMemCshnAngPst_Rsp_ = value;
        }

        uint8_t& SRRSeatMemLegAngCshnExtPst_Rsp() OMG_NOEXCEPT {
            return m_SRRSeatMemLegAngCshnExtPst_Rsp_;
        }

        const uint8_t& SRRSeatMemLegAngCshnExtPst_Rsp() const OMG_NOEXCEPT {
            return m_SRRSeatMemLegAngCshnExtPst_Rsp_;
        }

        void SRRSeatMemLegAngCshnExtPst_Rsp(uint8_t value) {
            m_SRRSeatMemLegAngCshnExtPst_Rsp_ = value;
        }

        bool operator == (const SRRSeatMemPst_Rsp_struct& other_) const;
        bool operator != (const SRRSeatMemPst_Rsp_struct& other_) const;

        void swap(SRRSeatMemPst_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_SRRSeatMemPstPurpose_Rsp_;
        uint8_t m_SRRSeatMemFBPst_Rsp_;
        uint8_t m_SRRSeatMemBackrestPst_Rsp_;
        uint8_t m_SRRSeatMemHgtPst_Rsp_;
        uint8_t m_SRRSeatMemCshnAngPst_Rsp_;
        uint8_t m_SRRSeatMemLegAngCshnExtPst_Rsp_;

    };

    inline void swap(SRRSeatMemPst_Rsp_struct& a, SRRSeatMemPst_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SRRSeatMemPst_Rsp_struct& sample);

    class NDDSUSERDllExport SteerSeatMemPst_Rsp_struct {
      public:
        SteerSeatMemPst_Rsp_struct();

        SteerSeatMemPst_Rsp_struct(
            uint8_t SteerMemPstPurpose_Rsp,
            uint8_t SteerMemTiltPst_Rsp,
            uint8_t SteerMemTelePst_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SteerSeatMemPst_Rsp_struct (SteerSeatMemPst_Rsp_struct&&) = default;
        SteerSeatMemPst_Rsp_struct& operator=(SteerSeatMemPst_Rsp_struct&&) = default;
        SteerSeatMemPst_Rsp_struct& operator=(const SteerSeatMemPst_Rsp_struct&) = default;
        SteerSeatMemPst_Rsp_struct(const SteerSeatMemPst_Rsp_struct&) = default;
        #else
        SteerSeatMemPst_Rsp_struct(SteerSeatMemPst_Rsp_struct&& other_) OMG_NOEXCEPT;  
        SteerSeatMemPst_Rsp_struct& operator=(SteerSeatMemPst_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& SteerMemPstPurpose_Rsp() OMG_NOEXCEPT {
            return m_SteerMemPstPurpose_Rsp_;
        }

        const uint8_t& SteerMemPstPurpose_Rsp() const OMG_NOEXCEPT {
            return m_SteerMemPstPurpose_Rsp_;
        }

        void SteerMemPstPurpose_Rsp(uint8_t value) {
            m_SteerMemPstPurpose_Rsp_ = value;
        }

        uint8_t& SteerMemTiltPst_Rsp() OMG_NOEXCEPT {
            return m_SteerMemTiltPst_Rsp_;
        }

        const uint8_t& SteerMemTiltPst_Rsp() const OMG_NOEXCEPT {
            return m_SteerMemTiltPst_Rsp_;
        }

        void SteerMemTiltPst_Rsp(uint8_t value) {
            m_SteerMemTiltPst_Rsp_ = value;
        }

        uint8_t& SteerMemTelePst_Rsp() OMG_NOEXCEPT {
            return m_SteerMemTelePst_Rsp_;
        }

        const uint8_t& SteerMemTelePst_Rsp() const OMG_NOEXCEPT {
            return m_SteerMemTelePst_Rsp_;
        }

        void SteerMemTelePst_Rsp(uint8_t value) {
            m_SteerMemTelePst_Rsp_ = value;
        }

        bool operator == (const SteerSeatMemPst_Rsp_struct& other_) const;
        bool operator != (const SteerSeatMemPst_Rsp_struct& other_) const;

        void swap(SteerSeatMemPst_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_SteerMemPstPurpose_Rsp_;
        uint8_t m_SteerMemTiltPst_Rsp_;
        uint8_t m_SteerMemTelePst_Rsp_;

    };

    inline void swap(SteerSeatMemPst_Rsp_struct& a, SteerSeatMemPst_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SteerSeatMemPst_Rsp_struct& sample);

    class NDDSUSERDllExport LExMirMemLRPst_Rsp_struct {
      public:
        LExMirMemLRPst_Rsp_struct();

        LExMirMemLRPst_Rsp_struct(
            uint8_t LExMirMemUDPst_Rsp,
            uint8_t LExMirMemLRPst_Rsp,
            uint8_t LExMirMemLRPstPurpose_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        LExMirMemLRPst_Rsp_struct (LExMirMemLRPst_Rsp_struct&&) = default;
        LExMirMemLRPst_Rsp_struct& operator=(LExMirMemLRPst_Rsp_struct&&) = default;
        LExMirMemLRPst_Rsp_struct& operator=(const LExMirMemLRPst_Rsp_struct&) = default;
        LExMirMemLRPst_Rsp_struct(const LExMirMemLRPst_Rsp_struct&) = default;
        #else
        LExMirMemLRPst_Rsp_struct(LExMirMemLRPst_Rsp_struct&& other_) OMG_NOEXCEPT;  
        LExMirMemLRPst_Rsp_struct& operator=(LExMirMemLRPst_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& LExMirMemUDPst_Rsp() OMG_NOEXCEPT {
            return m_LExMirMemUDPst_Rsp_;
        }

        const uint8_t& LExMirMemUDPst_Rsp() const OMG_NOEXCEPT {
            return m_LExMirMemUDPst_Rsp_;
        }

        void LExMirMemUDPst_Rsp(uint8_t value) {
            m_LExMirMemUDPst_Rsp_ = value;
        }

        uint8_t& LExMirMemLRPst_Rsp() OMG_NOEXCEPT {
            return m_LExMirMemLRPst_Rsp_;
        }

        const uint8_t& LExMirMemLRPst_Rsp() const OMG_NOEXCEPT {
            return m_LExMirMemLRPst_Rsp_;
        }

        void LExMirMemLRPst_Rsp(uint8_t value) {
            m_LExMirMemLRPst_Rsp_ = value;
        }

        uint8_t& LExMirMemLRPstPurpose_Rsp() OMG_NOEXCEPT {
            return m_LExMirMemLRPstPurpose_Rsp_;
        }

        const uint8_t& LExMirMemLRPstPurpose_Rsp() const OMG_NOEXCEPT {
            return m_LExMirMemLRPstPurpose_Rsp_;
        }

        void LExMirMemLRPstPurpose_Rsp(uint8_t value) {
            m_LExMirMemLRPstPurpose_Rsp_ = value;
        }

        bool operator == (const LExMirMemLRPst_Rsp_struct& other_) const;
        bool operator != (const LExMirMemLRPst_Rsp_struct& other_) const;

        void swap(LExMirMemLRPst_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_LExMirMemUDPst_Rsp_;
        uint8_t m_LExMirMemLRPst_Rsp_;
        uint8_t m_LExMirMemLRPstPurpose_Rsp_;

    };

    inline void swap(LExMirMemLRPst_Rsp_struct& a, LExMirMemLRPst_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const LExMirMemLRPst_Rsp_struct& sample);

    class NDDSUSERDllExport RExMirMemLRPst_Rsp_struct {
      public:
        RExMirMemLRPst_Rsp_struct();

        RExMirMemLRPst_Rsp_struct(
            uint8_t RExMirMemUDPst_Rsp,
            uint8_t RExMirMemLRPst_Rsp,
            uint8_t RExMirMemLRPstPurpose_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        RExMirMemLRPst_Rsp_struct (RExMirMemLRPst_Rsp_struct&&) = default;
        RExMirMemLRPst_Rsp_struct& operator=(RExMirMemLRPst_Rsp_struct&&) = default;
        RExMirMemLRPst_Rsp_struct& operator=(const RExMirMemLRPst_Rsp_struct&) = default;
        RExMirMemLRPst_Rsp_struct(const RExMirMemLRPst_Rsp_struct&) = default;
        #else
        RExMirMemLRPst_Rsp_struct(RExMirMemLRPst_Rsp_struct&& other_) OMG_NOEXCEPT;  
        RExMirMemLRPst_Rsp_struct& operator=(RExMirMemLRPst_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& RExMirMemUDPst_Rsp() OMG_NOEXCEPT {
            return m_RExMirMemUDPst_Rsp_;
        }

        const uint8_t& RExMirMemUDPst_Rsp() const OMG_NOEXCEPT {
            return m_RExMirMemUDPst_Rsp_;
        }

        void RExMirMemUDPst_Rsp(uint8_t value) {
            m_RExMirMemUDPst_Rsp_ = value;
        }

        uint8_t& RExMirMemLRPst_Rsp() OMG_NOEXCEPT {
            return m_RExMirMemLRPst_Rsp_;
        }

        const uint8_t& RExMirMemLRPst_Rsp() const OMG_NOEXCEPT {
            return m_RExMirMemLRPst_Rsp_;
        }

        void RExMirMemLRPst_Rsp(uint8_t value) {
            m_RExMirMemLRPst_Rsp_ = value;
        }

        uint8_t& RExMirMemLRPstPurpose_Rsp() OMG_NOEXCEPT {
            return m_RExMirMemLRPstPurpose_Rsp_;
        }

        const uint8_t& RExMirMemLRPstPurpose_Rsp() const OMG_NOEXCEPT {
            return m_RExMirMemLRPstPurpose_Rsp_;
        }

        void RExMirMemLRPstPurpose_Rsp(uint8_t value) {
            m_RExMirMemLRPstPurpose_Rsp_ = value;
        }

        bool operator == (const RExMirMemLRPst_Rsp_struct& other_) const;
        bool operator != (const RExMirMemLRPst_Rsp_struct& other_) const;

        void swap(RExMirMemLRPst_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_RExMirMemUDPst_Rsp_;
        uint8_t m_RExMirMemLRPst_Rsp_;
        uint8_t m_RExMirMemLRPstPurpose_Rsp_;

    };

    inline void swap(RExMirMemLRPst_Rsp_struct& a, RExMirMemLRPst_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const RExMirMemLRPst_Rsp_struct& sample);

    class NDDSUSERDllExport BdMemPst_Rsp_struct {
      public:
        BdMemPst_Rsp_struct();

        BdMemPst_Rsp_struct(
            const ::dds::core::array< BodyDomain::FLSeatMemPst_Rsp_struct, 5L>& FLSeatMemPst_Req,
            const ::dds::core::array< BodyDomain::FRSeatMemPst_Rsp_struct, 4L>& FRSeatMemPst_Req,
            const ::dds::core::array< BodyDomain::SRLSeatMemPst_Rsp_struct, 2L>& SRLSeatMemPst_Req,
            const ::dds::core::array< BodyDomain::SRRSeatMemPst_Rsp_struct, 2L>& SRRSeatMemPst_Req,
            const ::dds::core::array< BodyDomain::SteerSeatMemPst_Rsp_struct, 5L>& SteerMemPst_Req,
            const ::dds::core::array< BodyDomain::LExMirMemLRPst_Rsp_struct, 8L>& LExMirMemLRPst_Req,
            const ::dds::core::array< BodyDomain::RExMirMemLRPst_Rsp_struct, 8L>& RExMirMemLRPst_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdMemPst_Rsp_struct (BdMemPst_Rsp_struct&&) = default;
        BdMemPst_Rsp_struct& operator=(BdMemPst_Rsp_struct&&) = default;
        BdMemPst_Rsp_struct& operator=(const BdMemPst_Rsp_struct&) = default;
        BdMemPst_Rsp_struct(const BdMemPst_Rsp_struct&) = default;
        #else
        BdMemPst_Rsp_struct(BdMemPst_Rsp_struct&& other_) OMG_NOEXCEPT;  
        BdMemPst_Rsp_struct& operator=(BdMemPst_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::dds::core::array< BodyDomain::FLSeatMemPst_Rsp_struct, 5L>& FLSeatMemPst_Req() OMG_NOEXCEPT {
            return m_FLSeatMemPst_Req_;
        }

        const ::dds::core::array< BodyDomain::FLSeatMemPst_Rsp_struct, 5L>& FLSeatMemPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatMemPst_Req_;
        }

        void FLSeatMemPst_Req(const ::dds::core::array< BodyDomain::FLSeatMemPst_Rsp_struct, 5L>& value) {
            m_FLSeatMemPst_Req_ = value;
        }

        void FLSeatMemPst_Req(::dds::core::array< BodyDomain::FLSeatMemPst_Rsp_struct, 5L>&& value) {
            m_FLSeatMemPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::FRSeatMemPst_Rsp_struct, 4L>& FRSeatMemPst_Req() OMG_NOEXCEPT {
            return m_FRSeatMemPst_Req_;
        }

        const ::dds::core::array< BodyDomain::FRSeatMemPst_Rsp_struct, 4L>& FRSeatMemPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatMemPst_Req_;
        }

        void FRSeatMemPst_Req(const ::dds::core::array< BodyDomain::FRSeatMemPst_Rsp_struct, 4L>& value) {
            m_FRSeatMemPst_Req_ = value;
        }

        void FRSeatMemPst_Req(::dds::core::array< BodyDomain::FRSeatMemPst_Rsp_struct, 4L>&& value) {
            m_FRSeatMemPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::SRLSeatMemPst_Rsp_struct, 2L>& SRLSeatMemPst_Req() OMG_NOEXCEPT {
            return m_SRLSeatMemPst_Req_;
        }

        const ::dds::core::array< BodyDomain::SRLSeatMemPst_Rsp_struct, 2L>& SRLSeatMemPst_Req() const OMG_NOEXCEPT {
            return m_SRLSeatMemPst_Req_;
        }

        void SRLSeatMemPst_Req(const ::dds::core::array< BodyDomain::SRLSeatMemPst_Rsp_struct, 2L>& value) {
            m_SRLSeatMemPst_Req_ = value;
        }

        void SRLSeatMemPst_Req(::dds::core::array< BodyDomain::SRLSeatMemPst_Rsp_struct, 2L>&& value) {
            m_SRLSeatMemPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::SRRSeatMemPst_Rsp_struct, 2L>& SRRSeatMemPst_Req() OMG_NOEXCEPT {
            return m_SRRSeatMemPst_Req_;
        }

        const ::dds::core::array< BodyDomain::SRRSeatMemPst_Rsp_struct, 2L>& SRRSeatMemPst_Req() const OMG_NOEXCEPT {
            return m_SRRSeatMemPst_Req_;
        }

        void SRRSeatMemPst_Req(const ::dds::core::array< BodyDomain::SRRSeatMemPst_Rsp_struct, 2L>& value) {
            m_SRRSeatMemPst_Req_ = value;
        }

        void SRRSeatMemPst_Req(::dds::core::array< BodyDomain::SRRSeatMemPst_Rsp_struct, 2L>&& value) {
            m_SRRSeatMemPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::SteerSeatMemPst_Rsp_struct, 5L>& SteerMemPst_Req() OMG_NOEXCEPT {
            return m_SteerMemPst_Req_;
        }

        const ::dds::core::array< BodyDomain::SteerSeatMemPst_Rsp_struct, 5L>& SteerMemPst_Req() const OMG_NOEXCEPT {
            return m_SteerMemPst_Req_;
        }

        void SteerMemPst_Req(const ::dds::core::array< BodyDomain::SteerSeatMemPst_Rsp_struct, 5L>& value) {
            m_SteerMemPst_Req_ = value;
        }

        void SteerMemPst_Req(::dds::core::array< BodyDomain::SteerSeatMemPst_Rsp_struct, 5L>&& value) {
            m_SteerMemPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::LExMirMemLRPst_Rsp_struct, 8L>& LExMirMemLRPst_Req() OMG_NOEXCEPT {
            return m_LExMirMemLRPst_Req_;
        }

        const ::dds::core::array< BodyDomain::LExMirMemLRPst_Rsp_struct, 8L>& LExMirMemLRPst_Req() const OMG_NOEXCEPT {
            return m_LExMirMemLRPst_Req_;
        }

        void LExMirMemLRPst_Req(const ::dds::core::array< BodyDomain::LExMirMemLRPst_Rsp_struct, 8L>& value) {
            m_LExMirMemLRPst_Req_ = value;
        }

        void LExMirMemLRPst_Req(::dds::core::array< BodyDomain::LExMirMemLRPst_Rsp_struct, 8L>&& value) {
            m_LExMirMemLRPst_Req_ = std::move(value);
        }
        ::dds::core::array< BodyDomain::RExMirMemLRPst_Rsp_struct, 8L>& RExMirMemLRPst_Req() OMG_NOEXCEPT {
            return m_RExMirMemLRPst_Req_;
        }

        const ::dds::core::array< BodyDomain::RExMirMemLRPst_Rsp_struct, 8L>& RExMirMemLRPst_Req() const OMG_NOEXCEPT {
            return m_RExMirMemLRPst_Req_;
        }

        void RExMirMemLRPst_Req(const ::dds::core::array< BodyDomain::RExMirMemLRPst_Rsp_struct, 8L>& value) {
            m_RExMirMemLRPst_Req_ = value;
        }

        void RExMirMemLRPst_Req(::dds::core::array< BodyDomain::RExMirMemLRPst_Rsp_struct, 8L>&& value) {
            m_RExMirMemLRPst_Req_ = std::move(value);
        }

        bool operator == (const BdMemPst_Rsp_struct& other_) const;
        bool operator != (const BdMemPst_Rsp_struct& other_) const;

        void swap(BdMemPst_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        ::dds::core::array< BodyDomain::FLSeatMemPst_Rsp_struct, 5L> m_FLSeatMemPst_Req_;
        ::dds::core::array< BodyDomain::FRSeatMemPst_Rsp_struct, 4L> m_FRSeatMemPst_Req_;
        ::dds::core::array< BodyDomain::SRLSeatMemPst_Rsp_struct, 2L> m_SRLSeatMemPst_Req_;
        ::dds::core::array< BodyDomain::SRRSeatMemPst_Rsp_struct, 2L> m_SRRSeatMemPst_Req_;
        ::dds::core::array< BodyDomain::SteerSeatMemPst_Rsp_struct, 5L> m_SteerMemPst_Req_;
        ::dds::core::array< BodyDomain::LExMirMemLRPst_Rsp_struct, 8L> m_LExMirMemLRPst_Req_;
        ::dds::core::array< BodyDomain::RExMirMemLRPst_Rsp_struct, 8L> m_RExMirMemLRPst_Req_;

    };

    inline void swap(BdMemPst_Rsp_struct& a, BdMemPst_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdMemPst_Rsp_struct& sample);

    class NDDSUSERDllExport BdPst_Srv_Req_Union {
      public:
        BdPst_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdPst_Srv_Req_Union (BdPst_Srv_Req_Union&&) = default;
        BdPst_Srv_Req_Union& operator=(BdPst_Srv_Req_Union&&) = default;
        BdPst_Srv_Req_Union& operator=(const BdPst_Srv_Req_Union&) = default;
        BdPst_Srv_Req_Union(const BdPst_Srv_Req_Union&) = default;
        #else
        BdPst_Srv_Req_Union(BdPst_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        BdPst_Srv_Req_Union& operator=(BdPst_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::BdPst_Set_struct& BdPst_Set()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdPst_Set not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Set_;
        }

        const BodyDomain::BdPst_Set_struct& BdPst_Set() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdPst_Set not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Set_;
        }

        void BdPst_Set(const BodyDomain::BdPst_Set_struct& value) {
            m_u_.m_BdPst_Set_ = value;
            m_d_= 0;
        }

        void BdPst_Set(BodyDomain::BdPst_Set_struct&& value) {
            m_u_.m_BdPst_Set_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::BdPst_Get_struct& BdPst_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdPst_Get not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Get_;
        }

        const BodyDomain::BdPst_Get_struct& BdPst_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdPst_Get not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Get_;
        }

        void BdPst_Get(const BodyDomain::BdPst_Get_struct& value) {
            m_u_.m_BdPst_Get_ = value;
            m_d_= 1;
        }

        void BdPst_Get(BodyDomain::BdPst_Get_struct&& value) {
            m_u_.m_BdPst_Get_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::BdPst_Ctrl_struct& BdPst_Ctrl()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdPst_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Ctrl_;
        }

        const BodyDomain::BdPst_Ctrl_struct& BdPst_Ctrl() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdPst_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Ctrl_;
        }

        void BdPst_Ctrl(const BodyDomain::BdPst_Ctrl_struct& value) {
            m_u_.m_BdPst_Ctrl_ = value;
            m_d_= 2;
        }

        void BdPst_Ctrl(BodyDomain::BdPst_Ctrl_struct&& value) {
            m_u_.m_BdPst_Ctrl_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::BdPst_St_Get_struct& BdPst_St_Get()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdPst_St_Get not selected by the discriminator" );
            }
            return m_u_.m_BdPst_St_Get_;
        }

        const BodyDomain::BdPst_St_Get_struct& BdPst_St_Get() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdPst_St_Get not selected by the discriminator" );
            }
            return m_u_.m_BdPst_St_Get_;
        }

        void BdPst_St_Get(const BodyDomain::BdPst_St_Get_struct& value) {
            m_u_.m_BdPst_St_Get_ = value;
            m_d_= 3;
        }

        void BdPst_St_Get(BodyDomain::BdPst_St_Get_struct&& value) {
            m_u_.m_BdPst_St_Get_ = std::move(value);
            m_d_= 3;
        }
        BodyDomain::BdMemPst_Set_struct& BdMemPst_Set()  {
            if ( _d() != 4) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdMemPst_Set not selected by the discriminator" );
            }
            return m_u_.m_BdMemPst_Set_;
        }

        const BodyDomain::BdMemPst_Set_struct& BdMemPst_Set() const  {
            if ( _d() != 4) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdMemPst_Set not selected by the discriminator" );
            }
            return m_u_.m_BdMemPst_Set_;
        }

        void BdMemPst_Set(const BodyDomain::BdMemPst_Set_struct& value) {
            m_u_.m_BdMemPst_Set_ = value;
            m_d_= 4;
        }

        void BdMemPst_Set(BodyDomain::BdMemPst_Set_struct&& value) {
            m_u_.m_BdMemPst_Set_ = std::move(value);
            m_d_= 4;
        }
        BodyDomain::BdMemPst_Get_struct& BdMemPst_Get()  {
            if ( _d() != 5) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdMemPst_Get not selected by the discriminator" );
            }
            return m_u_.m_BdMemPst_Get_;
        }

        const BodyDomain::BdMemPst_Get_struct& BdMemPst_Get() const  {
            if ( _d() != 5) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Req_Union::BdMemPst_Get not selected by the discriminator" );
            }
            return m_u_.m_BdMemPst_Get_;
        }

        void BdMemPst_Get(const BodyDomain::BdMemPst_Get_struct& value) {
            m_u_.m_BdMemPst_Get_ = value;
            m_d_= 5;
        }

        void BdMemPst_Get(BodyDomain::BdMemPst_Get_struct&& value) {
            m_u_.m_BdMemPst_Get_ = std::move(value);
            m_d_= 5;
        }

        bool operator == (const BdPst_Srv_Req_Union& other_) const;
        bool operator != (const BdPst_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(BdPst_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::BdPst_Set_struct m_BdPst_Set_;
            BodyDomain::BdPst_Get_struct m_BdPst_Get_;
            BodyDomain::BdPst_Ctrl_struct m_BdPst_Ctrl_;
            BodyDomain::BdPst_St_Get_struct m_BdPst_St_Get_;
            BodyDomain::BdMemPst_Set_struct m_BdMemPst_Set_;
            BodyDomain::BdMemPst_Get_struct m_BdMemPst_Get_;
            Union_();
            Union_(
                const BodyDomain::BdPst_Set_struct& BdPst_Set,
                const BodyDomain::BdPst_Get_struct& BdPst_Get,
                const BodyDomain::BdPst_Ctrl_struct& BdPst_Ctrl,
                const BodyDomain::BdPst_St_Get_struct& BdPst_St_Get,
                const BodyDomain::BdMemPst_Set_struct& BdMemPst_Set,
                const BodyDomain::BdMemPst_Get_struct& BdMemPst_Get);
        };
        Union_ m_u_;

    };

    inline void swap(BdPst_Srv_Req_Union& a, BdPst_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdPst_Srv_Req_Union& sample);

    class NDDSUSERDllExport BdPst_Srv_Resp_Union {
      public:
        BdPst_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdPst_Srv_Resp_Union (BdPst_Srv_Resp_Union&&) = default;
        BdPst_Srv_Resp_Union& operator=(BdPst_Srv_Resp_Union&&) = default;
        BdPst_Srv_Resp_Union& operator=(const BdPst_Srv_Resp_Union&) = default;
        BdPst_Srv_Resp_Union(const BdPst_Srv_Resp_Union&) = default;
        #else
        BdPst_Srv_Resp_Union(BdPst_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        BdPst_Srv_Resp_Union& operator=(BdPst_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::BdPst_Rsp_struct& BdPst_Set_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdPst_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Set_SOA_;
        }

        const BodyDomain::BdPst_Rsp_struct& BdPst_Set_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdPst_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Set_SOA_;
        }

        void BdPst_Set_SOA(const BodyDomain::BdPst_Rsp_struct& value) {
            m_u_.m_BdPst_Set_SOA_ = value;
            m_d_= 0;
        }

        void BdPst_Set_SOA(BodyDomain::BdPst_Rsp_struct&& value) {
            m_u_.m_BdPst_Set_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::BdPst_Rsp_struct& BdPst_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdPst_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Get_SOA_;
        }

        const BodyDomain::BdPst_Rsp_struct& BdPst_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdPst_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Get_SOA_;
        }

        void BdPst_Get_SOA(const BodyDomain::BdPst_Rsp_struct& value) {
            m_u_.m_BdPst_Get_SOA_ = value;
            m_d_= 1;
        }

        void BdPst_Get_SOA(BodyDomain::BdPst_Rsp_struct&& value) {
            m_u_.m_BdPst_Get_SOA_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::BdPst_Ctrl_SOA_struct& BdPst_Ctrl_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdPst_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Ctrl_SOA_;
        }

        const BodyDomain::BdPst_Ctrl_SOA_struct& BdPst_Ctrl_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdPst_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdPst_Ctrl_SOA_;
        }

        void BdPst_Ctrl_SOA(const BodyDomain::BdPst_Ctrl_SOA_struct& value) {
            m_u_.m_BdPst_Ctrl_SOA_ = value;
            m_d_= 2;
        }

        void BdPst_Ctrl_SOA(BodyDomain::BdPst_Ctrl_SOA_struct&& value) {
            m_u_.m_BdPst_Ctrl_SOA_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::BdPst_St_struct& BdPst_St_Get_SOA()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdPst_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdPst_St_Get_SOA_;
        }

        const BodyDomain::BdPst_St_struct& BdPst_St_Get_SOA() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdPst_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdPst_St_Get_SOA_;
        }

        void BdPst_St_Get_SOA(const BodyDomain::BdPst_St_struct& value) {
            m_u_.m_BdPst_St_Get_SOA_ = value;
            m_d_= 3;
        }

        void BdPst_St_Get_SOA(BodyDomain::BdPst_St_struct&& value) {
            m_u_.m_BdPst_St_Get_SOA_ = std::move(value);
            m_d_= 3;
        }
        BodyDomain::BdMemPst_Rsp_struct& BdMemPst_Set_SOA()  {
            if ( _d() != 4) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdMemPst_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdMemPst_Set_SOA_;
        }

        const BodyDomain::BdMemPst_Rsp_struct& BdMemPst_Set_SOA() const  {
            if ( _d() != 4) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdMemPst_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdMemPst_Set_SOA_;
        }

        void BdMemPst_Set_SOA(const BodyDomain::BdMemPst_Rsp_struct& value) {
            m_u_.m_BdMemPst_Set_SOA_ = value;
            m_d_= 4;
        }

        void BdMemPst_Set_SOA(BodyDomain::BdMemPst_Rsp_struct&& value) {
            m_u_.m_BdMemPst_Set_SOA_ = std::move(value);
            m_d_= 4;
        }
        BodyDomain::BdMemPst_Rsp_struct& BdMemPst_Get_SOA()  {
            if ( _d() != 5) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdMemPst_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdMemPst_Get_SOA_;
        }

        const BodyDomain::BdMemPst_Rsp_struct& BdMemPst_Get_SOA() const  {
            if ( _d() != 5) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdPst_Srv_Resp_Union::BdMemPst_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdMemPst_Get_SOA_;
        }

        void BdMemPst_Get_SOA(const BodyDomain::BdMemPst_Rsp_struct& value) {
            m_u_.m_BdMemPst_Get_SOA_ = value;
            m_d_= 5;
        }

        void BdMemPst_Get_SOA(BodyDomain::BdMemPst_Rsp_struct&& value) {
            m_u_.m_BdMemPst_Get_SOA_ = std::move(value);
            m_d_= 5;
        }

        bool operator == (const BdPst_Srv_Resp_Union& other_) const;
        bool operator != (const BdPst_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(BdPst_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::BdPst_Rsp_struct m_BdPst_Set_SOA_;
            BodyDomain::BdPst_Rsp_struct m_BdPst_Get_SOA_;
            BodyDomain::BdPst_Ctrl_SOA_struct m_BdPst_Ctrl_SOA_;
            BodyDomain::BdPst_St_struct m_BdPst_St_Get_SOA_;
            BodyDomain::BdMemPst_Rsp_struct m_BdMemPst_Set_SOA_;
            BodyDomain::BdMemPst_Rsp_struct m_BdMemPst_Get_SOA_;
            Union_();
            Union_(
                const BodyDomain::BdPst_Rsp_struct& BdPst_Set_SOA,
                const BodyDomain::BdPst_Rsp_struct& BdPst_Get_SOA,
                const BodyDomain::BdPst_Ctrl_SOA_struct& BdPst_Ctrl_SOA,
                const BodyDomain::BdPst_St_struct& BdPst_St_Get_SOA,
                const BodyDomain::BdMemPst_Rsp_struct& BdMemPst_Set_SOA,
                const BodyDomain::BdMemPst_Rsp_struct& BdMemPst_Get_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(BdPst_Srv_Resp_Union& a, BdPst_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdPst_Srv_Resp_Union& sample);

    class NDDSUSERDllExport StAdj_Ctrl_struct {
      public:
        StAdj_Ctrl_struct();

        StAdj_Ctrl_struct(
            uint8_t FLSeatFBAdj_Act,
            uint8_t FLSeatBackrestAdj_Act,
            uint8_t FLSeatHgtAdj_Act,
            uint8_t FLSeatCshnAngAdj_Act,
            uint8_t FLLegAngCshnExtAdj_Act,
            uint8_t FLSeatLegLengthAdj_Act,
            uint8_t FRSeatFBAdj_Act,
            uint8_t FRSeatBackrestAdj_Act,
            uint8_t FRSeatHgtAdj_Act,
            uint8_t FRSeatCshnAngAdj_Act,
            uint8_t FRLegAngCshnExtAdj_Act,
            uint8_t FRSeatLegLengthAdj_Act,
            uint8_t FLSeatFBPst_Req,
            uint8_t FLSeatBackresPst_Req,
            uint8_t FLSeatHgtPst_Req,
            uint8_t FLSeatCshnAngPst_Req,
            uint8_t FLLegAngCshnExtPst_Req,
            uint8_t FLSeatLegLengthPst_Req,
            uint8_t FRSeatFBPst_Req,
            uint8_t FRSeatBackrestPst_Req,
            uint8_t FRSeatHgtPst_Req,
            uint8_t FRSeatCshnAngPst_Req,
            uint8_t FRLegAngCshnExtPst_Req,
            uint8_t FRSeatLegLengthPst_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        StAdj_Ctrl_struct (StAdj_Ctrl_struct&&) = default;
        StAdj_Ctrl_struct& operator=(StAdj_Ctrl_struct&&) = default;
        StAdj_Ctrl_struct& operator=(const StAdj_Ctrl_struct&) = default;
        StAdj_Ctrl_struct(const StAdj_Ctrl_struct&) = default;
        #else
        StAdj_Ctrl_struct(StAdj_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        StAdj_Ctrl_struct& operator=(StAdj_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLSeatFBAdj_Act() OMG_NOEXCEPT {
            return m_FLSeatFBAdj_Act_;
        }

        const uint8_t& FLSeatFBAdj_Act() const OMG_NOEXCEPT {
            return m_FLSeatFBAdj_Act_;
        }

        void FLSeatFBAdj_Act(uint8_t value) {
            m_FLSeatFBAdj_Act_ = value;
        }

        uint8_t& FLSeatBackrestAdj_Act() OMG_NOEXCEPT {
            return m_FLSeatBackrestAdj_Act_;
        }

        const uint8_t& FLSeatBackrestAdj_Act() const OMG_NOEXCEPT {
            return m_FLSeatBackrestAdj_Act_;
        }

        void FLSeatBackrestAdj_Act(uint8_t value) {
            m_FLSeatBackrestAdj_Act_ = value;
        }

        uint8_t& FLSeatHgtAdj_Act() OMG_NOEXCEPT {
            return m_FLSeatHgtAdj_Act_;
        }

        const uint8_t& FLSeatHgtAdj_Act() const OMG_NOEXCEPT {
            return m_FLSeatHgtAdj_Act_;
        }

        void FLSeatHgtAdj_Act(uint8_t value) {
            m_FLSeatHgtAdj_Act_ = value;
        }

        uint8_t& FLSeatCshnAngAdj_Act() OMG_NOEXCEPT {
            return m_FLSeatCshnAngAdj_Act_;
        }

        const uint8_t& FLSeatCshnAngAdj_Act() const OMG_NOEXCEPT {
            return m_FLSeatCshnAngAdj_Act_;
        }

        void FLSeatCshnAngAdj_Act(uint8_t value) {
            m_FLSeatCshnAngAdj_Act_ = value;
        }

        uint8_t& FLLegAngCshnExtAdj_Act() OMG_NOEXCEPT {
            return m_FLLegAngCshnExtAdj_Act_;
        }

        const uint8_t& FLLegAngCshnExtAdj_Act() const OMG_NOEXCEPT {
            return m_FLLegAngCshnExtAdj_Act_;
        }

        void FLLegAngCshnExtAdj_Act(uint8_t value) {
            m_FLLegAngCshnExtAdj_Act_ = value;
        }

        uint8_t& FLSeatLegLengthAdj_Act() OMG_NOEXCEPT {
            return m_FLSeatLegLengthAdj_Act_;
        }

        const uint8_t& FLSeatLegLengthAdj_Act() const OMG_NOEXCEPT {
            return m_FLSeatLegLengthAdj_Act_;
        }

        void FLSeatLegLengthAdj_Act(uint8_t value) {
            m_FLSeatLegLengthAdj_Act_ = value;
        }

        uint8_t& FRSeatFBAdj_Act() OMG_NOEXCEPT {
            return m_FRSeatFBAdj_Act_;
        }

        const uint8_t& FRSeatFBAdj_Act() const OMG_NOEXCEPT {
            return m_FRSeatFBAdj_Act_;
        }

        void FRSeatFBAdj_Act(uint8_t value) {
            m_FRSeatFBAdj_Act_ = value;
        }

        uint8_t& FRSeatBackrestAdj_Act() OMG_NOEXCEPT {
            return m_FRSeatBackrestAdj_Act_;
        }

        const uint8_t& FRSeatBackrestAdj_Act() const OMG_NOEXCEPT {
            return m_FRSeatBackrestAdj_Act_;
        }

        void FRSeatBackrestAdj_Act(uint8_t value) {
            m_FRSeatBackrestAdj_Act_ = value;
        }

        uint8_t& FRSeatHgtAdj_Act() OMG_NOEXCEPT {
            return m_FRSeatHgtAdj_Act_;
        }

        const uint8_t& FRSeatHgtAdj_Act() const OMG_NOEXCEPT {
            return m_FRSeatHgtAdj_Act_;
        }

        void FRSeatHgtAdj_Act(uint8_t value) {
            m_FRSeatHgtAdj_Act_ = value;
        }

        uint8_t& FRSeatCshnAngAdj_Act() OMG_NOEXCEPT {
            return m_FRSeatCshnAngAdj_Act_;
        }

        const uint8_t& FRSeatCshnAngAdj_Act() const OMG_NOEXCEPT {
            return m_FRSeatCshnAngAdj_Act_;
        }

        void FRSeatCshnAngAdj_Act(uint8_t value) {
            m_FRSeatCshnAngAdj_Act_ = value;
        }

        uint8_t& FRLegAngCshnExtAdj_Act() OMG_NOEXCEPT {
            return m_FRLegAngCshnExtAdj_Act_;
        }

        const uint8_t& FRLegAngCshnExtAdj_Act() const OMG_NOEXCEPT {
            return m_FRLegAngCshnExtAdj_Act_;
        }

        void FRLegAngCshnExtAdj_Act(uint8_t value) {
            m_FRLegAngCshnExtAdj_Act_ = value;
        }

        uint8_t& FRSeatLegLengthAdj_Act() OMG_NOEXCEPT {
            return m_FRSeatLegLengthAdj_Act_;
        }

        const uint8_t& FRSeatLegLengthAdj_Act() const OMG_NOEXCEPT {
            return m_FRSeatLegLengthAdj_Act_;
        }

        void FRSeatLegLengthAdj_Act(uint8_t value) {
            m_FRSeatLegLengthAdj_Act_ = value;
        }

        uint8_t& FLSeatFBPst_Req() OMG_NOEXCEPT {
            return m_FLSeatFBPst_Req_;
        }

        const uint8_t& FLSeatFBPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatFBPst_Req_;
        }

        void FLSeatFBPst_Req(uint8_t value) {
            m_FLSeatFBPst_Req_ = value;
        }

        uint8_t& FLSeatBackresPst_Req() OMG_NOEXCEPT {
            return m_FLSeatBackresPst_Req_;
        }

        const uint8_t& FLSeatBackresPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatBackresPst_Req_;
        }

        void FLSeatBackresPst_Req(uint8_t value) {
            m_FLSeatBackresPst_Req_ = value;
        }

        uint8_t& FLSeatHgtPst_Req() OMG_NOEXCEPT {
            return m_FLSeatHgtPst_Req_;
        }

        const uint8_t& FLSeatHgtPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatHgtPst_Req_;
        }

        void FLSeatHgtPst_Req(uint8_t value) {
            m_FLSeatHgtPst_Req_ = value;
        }

        uint8_t& FLSeatCshnAngPst_Req() OMG_NOEXCEPT {
            return m_FLSeatCshnAngPst_Req_;
        }

        const uint8_t& FLSeatCshnAngPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatCshnAngPst_Req_;
        }

        void FLSeatCshnAngPst_Req(uint8_t value) {
            m_FLSeatCshnAngPst_Req_ = value;
        }

        uint8_t& FLLegAngCshnExtPst_Req() OMG_NOEXCEPT {
            return m_FLLegAngCshnExtPst_Req_;
        }

        const uint8_t& FLLegAngCshnExtPst_Req() const OMG_NOEXCEPT {
            return m_FLLegAngCshnExtPst_Req_;
        }

        void FLLegAngCshnExtPst_Req(uint8_t value) {
            m_FLLegAngCshnExtPst_Req_ = value;
        }

        uint8_t& FLSeatLegLengthPst_Req() OMG_NOEXCEPT {
            return m_FLSeatLegLengthPst_Req_;
        }

        const uint8_t& FLSeatLegLengthPst_Req() const OMG_NOEXCEPT {
            return m_FLSeatLegLengthPst_Req_;
        }

        void FLSeatLegLengthPst_Req(uint8_t value) {
            m_FLSeatLegLengthPst_Req_ = value;
        }

        uint8_t& FRSeatFBPst_Req() OMG_NOEXCEPT {
            return m_FRSeatFBPst_Req_;
        }

        const uint8_t& FRSeatFBPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatFBPst_Req_;
        }

        void FRSeatFBPst_Req(uint8_t value) {
            m_FRSeatFBPst_Req_ = value;
        }

        uint8_t& FRSeatBackrestPst_Req() OMG_NOEXCEPT {
            return m_FRSeatBackrestPst_Req_;
        }

        const uint8_t& FRSeatBackrestPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatBackrestPst_Req_;
        }

        void FRSeatBackrestPst_Req(uint8_t value) {
            m_FRSeatBackrestPst_Req_ = value;
        }

        uint8_t& FRSeatHgtPst_Req() OMG_NOEXCEPT {
            return m_FRSeatHgtPst_Req_;
        }

        const uint8_t& FRSeatHgtPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatHgtPst_Req_;
        }

        void FRSeatHgtPst_Req(uint8_t value) {
            m_FRSeatHgtPst_Req_ = value;
        }

        uint8_t& FRSeatCshnAngPst_Req() OMG_NOEXCEPT {
            return m_FRSeatCshnAngPst_Req_;
        }

        const uint8_t& FRSeatCshnAngPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatCshnAngPst_Req_;
        }

        void FRSeatCshnAngPst_Req(uint8_t value) {
            m_FRSeatCshnAngPst_Req_ = value;
        }

        uint8_t& FRLegAngCshnExtPst_Req() OMG_NOEXCEPT {
            return m_FRLegAngCshnExtPst_Req_;
        }

        const uint8_t& FRLegAngCshnExtPst_Req() const OMG_NOEXCEPT {
            return m_FRLegAngCshnExtPst_Req_;
        }

        void FRLegAngCshnExtPst_Req(uint8_t value) {
            m_FRLegAngCshnExtPst_Req_ = value;
        }

        uint8_t& FRSeatLegLengthPst_Req() OMG_NOEXCEPT {
            return m_FRSeatLegLengthPst_Req_;
        }

        const uint8_t& FRSeatLegLengthPst_Req() const OMG_NOEXCEPT {
            return m_FRSeatLegLengthPst_Req_;
        }

        void FRSeatLegLengthPst_Req(uint8_t value) {
            m_FRSeatLegLengthPst_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const StAdj_Ctrl_struct& other_) const;
        bool operator != (const StAdj_Ctrl_struct& other_) const;

        void swap(StAdj_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLSeatFBAdj_Act_;
        uint8_t m_FLSeatBackrestAdj_Act_;
        uint8_t m_FLSeatHgtAdj_Act_;
        uint8_t m_FLSeatCshnAngAdj_Act_;
        uint8_t m_FLLegAngCshnExtAdj_Act_;
        uint8_t m_FLSeatLegLengthAdj_Act_;
        uint8_t m_FRSeatFBAdj_Act_;
        uint8_t m_FRSeatBackrestAdj_Act_;
        uint8_t m_FRSeatHgtAdj_Act_;
        uint8_t m_FRSeatCshnAngAdj_Act_;
        uint8_t m_FRLegAngCshnExtAdj_Act_;
        uint8_t m_FRSeatLegLengthAdj_Act_;
        uint8_t m_FLSeatFBPst_Req_;
        uint8_t m_FLSeatBackresPst_Req_;
        uint8_t m_FLSeatHgtPst_Req_;
        uint8_t m_FLSeatCshnAngPst_Req_;
        uint8_t m_FLLegAngCshnExtPst_Req_;
        uint8_t m_FLSeatLegLengthPst_Req_;
        uint8_t m_FRSeatFBPst_Req_;
        uint8_t m_FRSeatBackrestPst_Req_;
        uint8_t m_FRSeatHgtPst_Req_;
        uint8_t m_FRSeatCshnAngPst_Req_;
        uint8_t m_FRLegAngCshnExtPst_Req_;
        uint8_t m_FRSeatLegLengthPst_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(StAdj_Ctrl_struct& a, StAdj_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StAdj_Ctrl_struct& sample);

    class NDDSUSERDllExport StAdj_Ctrl_SOA_struct {
      public:
        StAdj_Ctrl_SOA_struct();

        explicit StAdj_Ctrl_SOA_struct(
            uint8_t StAdj_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        StAdj_Ctrl_SOA_struct (StAdj_Ctrl_SOA_struct&&) = default;
        StAdj_Ctrl_SOA_struct& operator=(StAdj_Ctrl_SOA_struct&&) = default;
        StAdj_Ctrl_SOA_struct& operator=(const StAdj_Ctrl_SOA_struct&) = default;
        StAdj_Ctrl_SOA_struct(const StAdj_Ctrl_SOA_struct&) = default;
        #else
        StAdj_Ctrl_SOA_struct(StAdj_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        StAdj_Ctrl_SOA_struct& operator=(StAdj_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& StAdj_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_StAdj_Ctrl_SOA_u8_;
        }

        const uint8_t& StAdj_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_StAdj_Ctrl_SOA_u8_;
        }

        void StAdj_Ctrl_SOA_u8(uint8_t value) {
            m_StAdj_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const StAdj_Ctrl_SOA_struct& other_) const;
        bool operator != (const StAdj_Ctrl_SOA_struct& other_) const;

        void swap(StAdj_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_StAdj_Ctrl_SOA_u8_;

    };

    inline void swap(StAdj_Ctrl_SOA_struct& a, StAdj_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StAdj_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport StAdj_St_struct {
      public:
        StAdj_St_struct();

        StAdj_St_struct(
            uint8_t FLSeatFBMv_St,
            uint8_t FLSeatBackrestMv_St,
            uint8_t FLSeatHgtMv_St,
            uint8_t FLSeatCshnAngMv_St,
            uint8_t FLLegAngCshnExtMv_St,
            uint8_t FLSeatLegLengthMv_St,
            uint8_t FRSeatFBMv_St,
            uint8_t FRSeatBackrestMv_St,
            uint8_t FRSeatHgtMv_St,
            uint8_t FRSeatCshnAngMv_St,
            uint8_t FRLegAngCshnExtMv_St,
            uint8_t FRSeatLegLengthMv_St,
            uint8_t FLSeatFBPst_Val,
            uint8_t FLSeatBackrestPst_Val,
            uint8_t FLSeatHgtPst_Val,
            uint8_t FLSeatCshnAngPst_Val,
            uint8_t FLLegAngCshnExtPst_Val,
            uint8_t FLSeatLegLengthPst_Val,
            uint8_t FRSeatFBPst_Val,
            uint8_t FRSeatBackrestPst_Val,
            uint8_t FRSeatHgtPst_Val,
            uint8_t FRSeatCshnAngPst_Val,
            uint8_t FRLegAngCshnExtPst_Val,
            uint8_t FRSeatLegLengthPst_Val);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        StAdj_St_struct (StAdj_St_struct&&) = default;
        StAdj_St_struct& operator=(StAdj_St_struct&&) = default;
        StAdj_St_struct& operator=(const StAdj_St_struct&) = default;
        StAdj_St_struct(const StAdj_St_struct&) = default;
        #else
        StAdj_St_struct(StAdj_St_struct&& other_) OMG_NOEXCEPT;  
        StAdj_St_struct& operator=(StAdj_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLSeatFBMv_St() OMG_NOEXCEPT {
            return m_FLSeatFBMv_St_;
        }

        const uint8_t& FLSeatFBMv_St() const OMG_NOEXCEPT {
            return m_FLSeatFBMv_St_;
        }

        void FLSeatFBMv_St(uint8_t value) {
            m_FLSeatFBMv_St_ = value;
        }

        uint8_t& FLSeatBackrestMv_St() OMG_NOEXCEPT {
            return m_FLSeatBackrestMv_St_;
        }

        const uint8_t& FLSeatBackrestMv_St() const OMG_NOEXCEPT {
            return m_FLSeatBackrestMv_St_;
        }

        void FLSeatBackrestMv_St(uint8_t value) {
            m_FLSeatBackrestMv_St_ = value;
        }

        uint8_t& FLSeatHgtMv_St() OMG_NOEXCEPT {
            return m_FLSeatHgtMv_St_;
        }

        const uint8_t& FLSeatHgtMv_St() const OMG_NOEXCEPT {
            return m_FLSeatHgtMv_St_;
        }

        void FLSeatHgtMv_St(uint8_t value) {
            m_FLSeatHgtMv_St_ = value;
        }

        uint8_t& FLSeatCshnAngMv_St() OMG_NOEXCEPT {
            return m_FLSeatCshnAngMv_St_;
        }

        const uint8_t& FLSeatCshnAngMv_St() const OMG_NOEXCEPT {
            return m_FLSeatCshnAngMv_St_;
        }

        void FLSeatCshnAngMv_St(uint8_t value) {
            m_FLSeatCshnAngMv_St_ = value;
        }

        uint8_t& FLLegAngCshnExtMv_St() OMG_NOEXCEPT {
            return m_FLLegAngCshnExtMv_St_;
        }

        const uint8_t& FLLegAngCshnExtMv_St() const OMG_NOEXCEPT {
            return m_FLLegAngCshnExtMv_St_;
        }

        void FLLegAngCshnExtMv_St(uint8_t value) {
            m_FLLegAngCshnExtMv_St_ = value;
        }

        uint8_t& FLSeatLegLengthMv_St() OMG_NOEXCEPT {
            return m_FLSeatLegLengthMv_St_;
        }

        const uint8_t& FLSeatLegLengthMv_St() const OMG_NOEXCEPT {
            return m_FLSeatLegLengthMv_St_;
        }

        void FLSeatLegLengthMv_St(uint8_t value) {
            m_FLSeatLegLengthMv_St_ = value;
        }

        uint8_t& FRSeatFBMv_St() OMG_NOEXCEPT {
            return m_FRSeatFBMv_St_;
        }

        const uint8_t& FRSeatFBMv_St() const OMG_NOEXCEPT {
            return m_FRSeatFBMv_St_;
        }

        void FRSeatFBMv_St(uint8_t value) {
            m_FRSeatFBMv_St_ = value;
        }

        uint8_t& FRSeatBackrestMv_St() OMG_NOEXCEPT {
            return m_FRSeatBackrestMv_St_;
        }

        const uint8_t& FRSeatBackrestMv_St() const OMG_NOEXCEPT {
            return m_FRSeatBackrestMv_St_;
        }

        void FRSeatBackrestMv_St(uint8_t value) {
            m_FRSeatBackrestMv_St_ = value;
        }

        uint8_t& FRSeatHgtMv_St() OMG_NOEXCEPT {
            return m_FRSeatHgtMv_St_;
        }

        const uint8_t& FRSeatHgtMv_St() const OMG_NOEXCEPT {
            return m_FRSeatHgtMv_St_;
        }

        void FRSeatHgtMv_St(uint8_t value) {
            m_FRSeatHgtMv_St_ = value;
        }

        uint8_t& FRSeatCshnAngMv_St() OMG_NOEXCEPT {
            return m_FRSeatCshnAngMv_St_;
        }

        const uint8_t& FRSeatCshnAngMv_St() const OMG_NOEXCEPT {
            return m_FRSeatCshnAngMv_St_;
        }

        void FRSeatCshnAngMv_St(uint8_t value) {
            m_FRSeatCshnAngMv_St_ = value;
        }

        uint8_t& FRLegAngCshnExtMv_St() OMG_NOEXCEPT {
            return m_FRLegAngCshnExtMv_St_;
        }

        const uint8_t& FRLegAngCshnExtMv_St() const OMG_NOEXCEPT {
            return m_FRLegAngCshnExtMv_St_;
        }

        void FRLegAngCshnExtMv_St(uint8_t value) {
            m_FRLegAngCshnExtMv_St_ = value;
        }

        uint8_t& FRSeatLegLengthMv_St() OMG_NOEXCEPT {
            return m_FRSeatLegLengthMv_St_;
        }

        const uint8_t& FRSeatLegLengthMv_St() const OMG_NOEXCEPT {
            return m_FRSeatLegLengthMv_St_;
        }

        void FRSeatLegLengthMv_St(uint8_t value) {
            m_FRSeatLegLengthMv_St_ = value;
        }

        uint8_t& FLSeatFBPst_Val() OMG_NOEXCEPT {
            return m_FLSeatFBPst_Val_;
        }

        const uint8_t& FLSeatFBPst_Val() const OMG_NOEXCEPT {
            return m_FLSeatFBPst_Val_;
        }

        void FLSeatFBPst_Val(uint8_t value) {
            m_FLSeatFBPst_Val_ = value;
        }

        uint8_t& FLSeatBackrestPst_Val() OMG_NOEXCEPT {
            return m_FLSeatBackrestPst_Val_;
        }

        const uint8_t& FLSeatBackrestPst_Val() const OMG_NOEXCEPT {
            return m_FLSeatBackrestPst_Val_;
        }

        void FLSeatBackrestPst_Val(uint8_t value) {
            m_FLSeatBackrestPst_Val_ = value;
        }

        uint8_t& FLSeatHgtPst_Val() OMG_NOEXCEPT {
            return m_FLSeatHgtPst_Val_;
        }

        const uint8_t& FLSeatHgtPst_Val() const OMG_NOEXCEPT {
            return m_FLSeatHgtPst_Val_;
        }

        void FLSeatHgtPst_Val(uint8_t value) {
            m_FLSeatHgtPst_Val_ = value;
        }

        uint8_t& FLSeatCshnAngPst_Val() OMG_NOEXCEPT {
            return m_FLSeatCshnAngPst_Val_;
        }

        const uint8_t& FLSeatCshnAngPst_Val() const OMG_NOEXCEPT {
            return m_FLSeatCshnAngPst_Val_;
        }

        void FLSeatCshnAngPst_Val(uint8_t value) {
            m_FLSeatCshnAngPst_Val_ = value;
        }

        uint8_t& FLLegAngCshnExtPst_Val() OMG_NOEXCEPT {
            return m_FLLegAngCshnExtPst_Val_;
        }

        const uint8_t& FLLegAngCshnExtPst_Val() const OMG_NOEXCEPT {
            return m_FLLegAngCshnExtPst_Val_;
        }

        void FLLegAngCshnExtPst_Val(uint8_t value) {
            m_FLLegAngCshnExtPst_Val_ = value;
        }

        uint8_t& FLSeatLegLengthPst_Val() OMG_NOEXCEPT {
            return m_FLSeatLegLengthPst_Val_;
        }

        const uint8_t& FLSeatLegLengthPst_Val() const OMG_NOEXCEPT {
            return m_FLSeatLegLengthPst_Val_;
        }

        void FLSeatLegLengthPst_Val(uint8_t value) {
            m_FLSeatLegLengthPst_Val_ = value;
        }

        uint8_t& FRSeatFBPst_Val() OMG_NOEXCEPT {
            return m_FRSeatFBPst_Val_;
        }

        const uint8_t& FRSeatFBPst_Val() const OMG_NOEXCEPT {
            return m_FRSeatFBPst_Val_;
        }

        void FRSeatFBPst_Val(uint8_t value) {
            m_FRSeatFBPst_Val_ = value;
        }

        uint8_t& FRSeatBackrestPst_Val() OMG_NOEXCEPT {
            return m_FRSeatBackrestPst_Val_;
        }

        const uint8_t& FRSeatBackrestPst_Val() const OMG_NOEXCEPT {
            return m_FRSeatBackrestPst_Val_;
        }

        void FRSeatBackrestPst_Val(uint8_t value) {
            m_FRSeatBackrestPst_Val_ = value;
        }

        uint8_t& FRSeatHgtPst_Val() OMG_NOEXCEPT {
            return m_FRSeatHgtPst_Val_;
        }

        const uint8_t& FRSeatHgtPst_Val() const OMG_NOEXCEPT {
            return m_FRSeatHgtPst_Val_;
        }

        void FRSeatHgtPst_Val(uint8_t value) {
            m_FRSeatHgtPst_Val_ = value;
        }

        uint8_t& FRSeatCshnAngPst_Val() OMG_NOEXCEPT {
            return m_FRSeatCshnAngPst_Val_;
        }

        const uint8_t& FRSeatCshnAngPst_Val() const OMG_NOEXCEPT {
            return m_FRSeatCshnAngPst_Val_;
        }

        void FRSeatCshnAngPst_Val(uint8_t value) {
            m_FRSeatCshnAngPst_Val_ = value;
        }

        uint8_t& FRLegAngCshnExtPst_Val() OMG_NOEXCEPT {
            return m_FRLegAngCshnExtPst_Val_;
        }

        const uint8_t& FRLegAngCshnExtPst_Val() const OMG_NOEXCEPT {
            return m_FRLegAngCshnExtPst_Val_;
        }

        void FRLegAngCshnExtPst_Val(uint8_t value) {
            m_FRLegAngCshnExtPst_Val_ = value;
        }

        uint8_t& FRSeatLegLengthPst_Val() OMG_NOEXCEPT {
            return m_FRSeatLegLengthPst_Val_;
        }

        const uint8_t& FRSeatLegLengthPst_Val() const OMG_NOEXCEPT {
            return m_FRSeatLegLengthPst_Val_;
        }

        void FRSeatLegLengthPst_Val(uint8_t value) {
            m_FRSeatLegLengthPst_Val_ = value;
        }

        bool operator == (const StAdj_St_struct& other_) const;
        bool operator != (const StAdj_St_struct& other_) const;

        void swap(StAdj_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLSeatFBMv_St_;
        uint8_t m_FLSeatBackrestMv_St_;
        uint8_t m_FLSeatHgtMv_St_;
        uint8_t m_FLSeatCshnAngMv_St_;
        uint8_t m_FLLegAngCshnExtMv_St_;
        uint8_t m_FLSeatLegLengthMv_St_;
        uint8_t m_FRSeatFBMv_St_;
        uint8_t m_FRSeatBackrestMv_St_;
        uint8_t m_FRSeatHgtMv_St_;
        uint8_t m_FRSeatCshnAngMv_St_;
        uint8_t m_FRLegAngCshnExtMv_St_;
        uint8_t m_FRSeatLegLengthMv_St_;
        uint8_t m_FLSeatFBPst_Val_;
        uint8_t m_FLSeatBackrestPst_Val_;
        uint8_t m_FLSeatHgtPst_Val_;
        uint8_t m_FLSeatCshnAngPst_Val_;
        uint8_t m_FLLegAngCshnExtPst_Val_;
        uint8_t m_FLSeatLegLengthPst_Val_;
        uint8_t m_FRSeatFBPst_Val_;
        uint8_t m_FRSeatBackrestPst_Val_;
        uint8_t m_FRSeatHgtPst_Val_;
        uint8_t m_FRSeatCshnAngPst_Val_;
        uint8_t m_FRLegAngCshnExtPst_Val_;
        uint8_t m_FRSeatLegLengthPst_Val_;

    };

    inline void swap(StAdj_St_struct& a, StAdj_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StAdj_St_struct& sample);

    class NDDSUSERDllExport StAdj_St_Get_struct {
      public:
        StAdj_St_Get_struct();

        StAdj_St_Get_struct(
            uint16_t StPstBit,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        StAdj_St_Get_struct (StAdj_St_Get_struct&&) = default;
        StAdj_St_Get_struct& operator=(StAdj_St_Get_struct&&) = default;
        StAdj_St_Get_struct& operator=(const StAdj_St_Get_struct&) = default;
        StAdj_St_Get_struct(const StAdj_St_Get_struct&) = default;
        #else
        StAdj_St_Get_struct(StAdj_St_Get_struct&& other_) OMG_NOEXCEPT;  
        StAdj_St_Get_struct& operator=(StAdj_St_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint16_t& StPstBit() OMG_NOEXCEPT {
            return m_StPstBit_;
        }

        const uint16_t& StPstBit() const OMG_NOEXCEPT {
            return m_StPstBit_;
        }

        void StPstBit(uint16_t value) {
            m_StPstBit_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const StAdj_St_Get_struct& other_) const;
        bool operator != (const StAdj_St_Get_struct& other_) const;

        void swap(StAdj_St_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint16_t m_StPstBit_;
        std::string m_CtrlSource_;

    };

    inline void swap(StAdj_St_Get_struct& a, StAdj_St_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StAdj_St_Get_struct& sample);

    class NDDSUSERDllExport StAdj_Srv_Req_Union {
      public:
        StAdj_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        StAdj_Srv_Req_Union (StAdj_Srv_Req_Union&&) = default;
        StAdj_Srv_Req_Union& operator=(StAdj_Srv_Req_Union&&) = default;
        StAdj_Srv_Req_Union& operator=(const StAdj_Srv_Req_Union&) = default;
        StAdj_Srv_Req_Union(const StAdj_Srv_Req_Union&) = default;
        #else
        StAdj_Srv_Req_Union(StAdj_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        StAdj_Srv_Req_Union& operator=(StAdj_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::StAdj_Ctrl_struct& StAdj_Ctrl()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::StAdj_Srv_Req_Union::StAdj_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_StAdj_Ctrl_;
        }

        const BodyDomain::StAdj_Ctrl_struct& StAdj_Ctrl() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::StAdj_Srv_Req_Union::StAdj_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_StAdj_Ctrl_;
        }

        void StAdj_Ctrl(const BodyDomain::StAdj_Ctrl_struct& value) {
            m_u_.m_StAdj_Ctrl_ = value;
            m_d_= 0;
        }

        void StAdj_Ctrl(BodyDomain::StAdj_Ctrl_struct&& value) {
            m_u_.m_StAdj_Ctrl_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::StAdj_St_Get_struct& StAdj_St_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::StAdj_Srv_Req_Union::StAdj_St_Get not selected by the discriminator" );
            }
            return m_u_.m_StAdj_St_Get_;
        }

        const BodyDomain::StAdj_St_Get_struct& StAdj_St_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::StAdj_Srv_Req_Union::StAdj_St_Get not selected by the discriminator" );
            }
            return m_u_.m_StAdj_St_Get_;
        }

        void StAdj_St_Get(const BodyDomain::StAdj_St_Get_struct& value) {
            m_u_.m_StAdj_St_Get_ = value;
            m_d_= 1;
        }

        void StAdj_St_Get(BodyDomain::StAdj_St_Get_struct&& value) {
            m_u_.m_StAdj_St_Get_ = std::move(value);
            m_d_= 1;
        }

        bool operator == (const StAdj_Srv_Req_Union& other_) const;
        bool operator != (const StAdj_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(StAdj_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::StAdj_Ctrl_struct m_StAdj_Ctrl_;
            BodyDomain::StAdj_St_Get_struct m_StAdj_St_Get_;
            Union_();
            Union_(
                const BodyDomain::StAdj_Ctrl_struct& StAdj_Ctrl,
                const BodyDomain::StAdj_St_Get_struct& StAdj_St_Get);
        };
        Union_ m_u_;

    };

    inline void swap(StAdj_Srv_Req_Union& a, StAdj_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StAdj_Srv_Req_Union& sample);

    class NDDSUSERDllExport StAdj_Srv_Resp_Union {
      public:
        StAdj_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        StAdj_Srv_Resp_Union (StAdj_Srv_Resp_Union&&) = default;
        StAdj_Srv_Resp_Union& operator=(StAdj_Srv_Resp_Union&&) = default;
        StAdj_Srv_Resp_Union& operator=(const StAdj_Srv_Resp_Union&) = default;
        StAdj_Srv_Resp_Union(const StAdj_Srv_Resp_Union&) = default;
        #else
        StAdj_Srv_Resp_Union(StAdj_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        StAdj_Srv_Resp_Union& operator=(StAdj_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::StAdj_Ctrl_SOA_struct& StAdj_Ctrl_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::StAdj_Srv_Resp_Union::StAdj_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_StAdj_Ctrl_SOA_;
        }

        const BodyDomain::StAdj_Ctrl_SOA_struct& StAdj_Ctrl_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::StAdj_Srv_Resp_Union::StAdj_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_StAdj_Ctrl_SOA_;
        }

        void StAdj_Ctrl_SOA(const BodyDomain::StAdj_Ctrl_SOA_struct& value) {
            m_u_.m_StAdj_Ctrl_SOA_ = value;
            m_d_= 0;
        }

        void StAdj_Ctrl_SOA(BodyDomain::StAdj_Ctrl_SOA_struct&& value) {
            m_u_.m_StAdj_Ctrl_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::StAdj_St_struct& StAdj_St_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::StAdj_Srv_Resp_Union::StAdj_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_StAdj_St_Get_SOA_;
        }

        const BodyDomain::StAdj_St_struct& StAdj_St_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::StAdj_Srv_Resp_Union::StAdj_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_StAdj_St_Get_SOA_;
        }

        void StAdj_St_Get_SOA(const BodyDomain::StAdj_St_struct& value) {
            m_u_.m_StAdj_St_Get_SOA_ = value;
            m_d_= 1;
        }

        void StAdj_St_Get_SOA(BodyDomain::StAdj_St_struct&& value) {
            m_u_.m_StAdj_St_Get_SOA_ = std::move(value);
            m_d_= 1;
        }

        bool operator == (const StAdj_Srv_Resp_Union& other_) const;
        bool operator != (const StAdj_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(StAdj_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::StAdj_Ctrl_SOA_struct m_StAdj_Ctrl_SOA_;
            BodyDomain::StAdj_St_struct m_StAdj_St_Get_SOA_;
            Union_();
            Union_(
                const BodyDomain::StAdj_Ctrl_SOA_struct& StAdj_Ctrl_SOA,
                const BodyDomain::StAdj_St_struct& StAdj_St_Get_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(StAdj_Srv_Resp_Union& a, StAdj_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StAdj_Srv_Resp_Union& sample);

    class NDDSUSERDllExport DrLth_Set_struct {
      public:
        DrLth_Set_struct();

        DrLth_Set_struct(
            uint8_t TDrOpenAngSet_Act,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrLth_Set_struct (DrLth_Set_struct&&) = default;
        DrLth_Set_struct& operator=(DrLth_Set_struct&&) = default;
        DrLth_Set_struct& operator=(const DrLth_Set_struct&) = default;
        DrLth_Set_struct(const DrLth_Set_struct&) = default;
        #else
        DrLth_Set_struct(DrLth_Set_struct&& other_) OMG_NOEXCEPT;  
        DrLth_Set_struct& operator=(DrLth_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& TDrOpenAngSet_Act() OMG_NOEXCEPT {
            return m_TDrOpenAngSet_Act_;
        }

        const uint8_t& TDrOpenAngSet_Act() const OMG_NOEXCEPT {
            return m_TDrOpenAngSet_Act_;
        }

        void TDrOpenAngSet_Act(uint8_t value) {
            m_TDrOpenAngSet_Act_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const DrLth_Set_struct& other_) const;
        bool operator != (const DrLth_Set_struct& other_) const;

        void swap(DrLth_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_TDrOpenAngSet_Act_;
        std::string m_CtrlSource_;

    };

    inline void swap(DrLth_Set_struct& a, DrLth_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrLth_Set_struct& sample);

    class NDDSUSERDllExport DrLth_Get_struct {
      public:
        DrLth_Get_struct();

        DrLth_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrLth_Get_struct (DrLth_Get_struct&&) = default;
        DrLth_Get_struct& operator=(DrLth_Get_struct&&) = default;
        DrLth_Get_struct& operator=(const DrLth_Get_struct&) = default;
        DrLth_Get_struct(const DrLth_Get_struct&) = default;
        #else
        DrLth_Get_struct(DrLth_Get_struct&& other_) OMG_NOEXCEPT;  
        DrLth_Get_struct& operator=(DrLth_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const DrLth_Get_struct& other_) const;
        bool operator != (const DrLth_Get_struct& other_) const;

        void swap(DrLth_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(DrLth_Get_struct& a, DrLth_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrLth_Get_struct& sample);

    class NDDSUSERDllExport DrLth_Rsp_struct {
      public:
        DrLth_Rsp_struct();

        explicit DrLth_Rsp_struct(
            uint8_t TDrOpenAngSet_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrLth_Rsp_struct (DrLth_Rsp_struct&&) = default;
        DrLth_Rsp_struct& operator=(DrLth_Rsp_struct&&) = default;
        DrLth_Rsp_struct& operator=(const DrLth_Rsp_struct&) = default;
        DrLth_Rsp_struct(const DrLth_Rsp_struct&) = default;
        #else
        DrLth_Rsp_struct(DrLth_Rsp_struct&& other_) OMG_NOEXCEPT;  
        DrLth_Rsp_struct& operator=(DrLth_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& TDrOpenAngSet_Rsp() OMG_NOEXCEPT {
            return m_TDrOpenAngSet_Rsp_;
        }

        const uint8_t& TDrOpenAngSet_Rsp() const OMG_NOEXCEPT {
            return m_TDrOpenAngSet_Rsp_;
        }

        void TDrOpenAngSet_Rsp(uint8_t value) {
            m_TDrOpenAngSet_Rsp_ = value;
        }

        bool operator == (const DrLth_Rsp_struct& other_) const;
        bool operator != (const DrLth_Rsp_struct& other_) const;

        void swap(DrLth_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_TDrOpenAngSet_Rsp_;

    };

    inline void swap(DrLth_Rsp_struct& a, DrLth_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrLth_Rsp_struct& sample);

    class NDDSUSERDllExport DrLth_St_Get_struct {
      public:
        DrLth_St_Get_struct();

        DrLth_St_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrLth_St_Get_struct (DrLth_St_Get_struct&&) = default;
        DrLth_St_Get_struct& operator=(DrLth_St_Get_struct&&) = default;
        DrLth_St_Get_struct& operator=(const DrLth_St_Get_struct&) = default;
        DrLth_St_Get_struct(const DrLth_St_Get_struct&) = default;
        #else
        DrLth_St_Get_struct(DrLth_St_Get_struct&& other_) OMG_NOEXCEPT;  
        DrLth_St_Get_struct& operator=(DrLth_St_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const DrLth_St_Get_struct& other_) const;
        bool operator != (const DrLth_St_Get_struct& other_) const;

        void swap(DrLth_St_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(DrLth_St_Get_struct& a, DrLth_St_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrLth_St_Get_struct& sample);

    class NDDSUSERDllExport DrLth_Ctrl_struct {
      public:
        DrLth_Ctrl_struct();

        DrLth_Ctrl_struct(
            uint8_t TDoorBtn_Act,
            uint8_t TDoorPos_Act,
            uint8_t FLDoorBtn_Act,
            uint8_t RLDoorBtn_Act,
            uint8_t FRDoorBtn_Act,
            uint8_t RRDoorBtn_Act,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrLth_Ctrl_struct (DrLth_Ctrl_struct&&) = default;
        DrLth_Ctrl_struct& operator=(DrLth_Ctrl_struct&&) = default;
        DrLth_Ctrl_struct& operator=(const DrLth_Ctrl_struct&) = default;
        DrLth_Ctrl_struct(const DrLth_Ctrl_struct&) = default;
        #else
        DrLth_Ctrl_struct(DrLth_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        DrLth_Ctrl_struct& operator=(DrLth_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& TDoorBtn_Act() OMG_NOEXCEPT {
            return m_TDoorBtn_Act_;
        }

        const uint8_t& TDoorBtn_Act() const OMG_NOEXCEPT {
            return m_TDoorBtn_Act_;
        }

        void TDoorBtn_Act(uint8_t value) {
            m_TDoorBtn_Act_ = value;
        }

        uint8_t& TDoorPos_Act() OMG_NOEXCEPT {
            return m_TDoorPos_Act_;
        }

        const uint8_t& TDoorPos_Act() const OMG_NOEXCEPT {
            return m_TDoorPos_Act_;
        }

        void TDoorPos_Act(uint8_t value) {
            m_TDoorPos_Act_ = value;
        }

        uint8_t& FLDoorBtn_Act() OMG_NOEXCEPT {
            return m_FLDoorBtn_Act_;
        }

        const uint8_t& FLDoorBtn_Act() const OMG_NOEXCEPT {
            return m_FLDoorBtn_Act_;
        }

        void FLDoorBtn_Act(uint8_t value) {
            m_FLDoorBtn_Act_ = value;
        }

        uint8_t& RLDoorBtn_Act() OMG_NOEXCEPT {
            return m_RLDoorBtn_Act_;
        }

        const uint8_t& RLDoorBtn_Act() const OMG_NOEXCEPT {
            return m_RLDoorBtn_Act_;
        }

        void RLDoorBtn_Act(uint8_t value) {
            m_RLDoorBtn_Act_ = value;
        }

        uint8_t& FRDoorBtn_Act() OMG_NOEXCEPT {
            return m_FRDoorBtn_Act_;
        }

        const uint8_t& FRDoorBtn_Act() const OMG_NOEXCEPT {
            return m_FRDoorBtn_Act_;
        }

        void FRDoorBtn_Act(uint8_t value) {
            m_FRDoorBtn_Act_ = value;
        }

        uint8_t& RRDoorBtn_Act() OMG_NOEXCEPT {
            return m_RRDoorBtn_Act_;
        }

        const uint8_t& RRDoorBtn_Act() const OMG_NOEXCEPT {
            return m_RRDoorBtn_Act_;
        }

        void RRDoorBtn_Act(uint8_t value) {
            m_RRDoorBtn_Act_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const DrLth_Ctrl_struct& other_) const;
        bool operator != (const DrLth_Ctrl_struct& other_) const;

        void swap(DrLth_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_TDoorBtn_Act_;
        uint8_t m_TDoorPos_Act_;
        uint8_t m_FLDoorBtn_Act_;
        uint8_t m_RLDoorBtn_Act_;
        uint8_t m_FRDoorBtn_Act_;
        uint8_t m_RRDoorBtn_Act_;
        std::string m_CtrlSource_;

    };

    inline void swap(DrLth_Ctrl_struct& a, DrLth_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrLth_Ctrl_struct& sample);

    class NDDSUSERDllExport DrLth_Ctrl_SOA_struct {
      public:
        DrLth_Ctrl_SOA_struct();

        explicit DrLth_Ctrl_SOA_struct(
            uint8_t DrLth_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrLth_Ctrl_SOA_struct (DrLth_Ctrl_SOA_struct&&) = default;
        DrLth_Ctrl_SOA_struct& operator=(DrLth_Ctrl_SOA_struct&&) = default;
        DrLth_Ctrl_SOA_struct& operator=(const DrLth_Ctrl_SOA_struct&) = default;
        DrLth_Ctrl_SOA_struct(const DrLth_Ctrl_SOA_struct&) = default;
        #else
        DrLth_Ctrl_SOA_struct(DrLth_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        DrLth_Ctrl_SOA_struct& operator=(DrLth_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& DrLth_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_DrLth_Ctrl_SOA_u8_;
        }

        const uint8_t& DrLth_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_DrLth_Ctrl_SOA_u8_;
        }

        void DrLth_Ctrl_SOA_u8(uint8_t value) {
            m_DrLth_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const DrLth_Ctrl_SOA_struct& other_) const;
        bool operator != (const DrLth_Ctrl_SOA_struct& other_) const;

        void swap(DrLth_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_DrLth_Ctrl_SOA_u8_;

    };

    inline void swap(DrLth_Ctrl_SOA_struct& a, DrLth_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrLth_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport DrLth_St_struct {
      public:
        DrLth_St_struct();

        DrLth_St_struct(
            uint8_t FLDoor_st,
            uint8_t RLDoor_st,
            uint8_t FRDoor_st,
            uint8_t RRDoor_st,
            uint8_t TDoor_st,
            uint8_t FLNomDoor_St,
            uint8_t RLNomDoor_St,
            uint8_t FRNomDoor_St,
            uint8_t RRNomDoor_St,
            uint8_t TDoorNominal_St,
            uint8_t TDrWrk_St,
            uint8_t TDrTripPst_Val,
            uint8_t FLDrStpRsn_st,
            uint8_t RLDrStpRsn_st,
            uint8_t FRDrStpRsn_st,
            uint8_t RRDrStpRsn_st,
            uint8_t TDrStpRsn_st,
            uint8_t TDoorTip_St,
            uint8_t HoodLatch_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrLth_St_struct (DrLth_St_struct&&) = default;
        DrLth_St_struct& operator=(DrLth_St_struct&&) = default;
        DrLth_St_struct& operator=(const DrLth_St_struct&) = default;
        DrLth_St_struct(const DrLth_St_struct&) = default;
        #else
        DrLth_St_struct(DrLth_St_struct&& other_) OMG_NOEXCEPT;  
        DrLth_St_struct& operator=(DrLth_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLDoor_st() OMG_NOEXCEPT {
            return m_FLDoor_st_;
        }

        const uint8_t& FLDoor_st() const OMG_NOEXCEPT {
            return m_FLDoor_st_;
        }

        void FLDoor_st(uint8_t value) {
            m_FLDoor_st_ = value;
        }

        uint8_t& RLDoor_st() OMG_NOEXCEPT {
            return m_RLDoor_st_;
        }

        const uint8_t& RLDoor_st() const OMG_NOEXCEPT {
            return m_RLDoor_st_;
        }

        void RLDoor_st(uint8_t value) {
            m_RLDoor_st_ = value;
        }

        uint8_t& FRDoor_st() OMG_NOEXCEPT {
            return m_FRDoor_st_;
        }

        const uint8_t& FRDoor_st() const OMG_NOEXCEPT {
            return m_FRDoor_st_;
        }

        void FRDoor_st(uint8_t value) {
            m_FRDoor_st_ = value;
        }

        uint8_t& RRDoor_st() OMG_NOEXCEPT {
            return m_RRDoor_st_;
        }

        const uint8_t& RRDoor_st() const OMG_NOEXCEPT {
            return m_RRDoor_st_;
        }

        void RRDoor_st(uint8_t value) {
            m_RRDoor_st_ = value;
        }

        uint8_t& TDoor_st() OMG_NOEXCEPT {
            return m_TDoor_st_;
        }

        const uint8_t& TDoor_st() const OMG_NOEXCEPT {
            return m_TDoor_st_;
        }

        void TDoor_st(uint8_t value) {
            m_TDoor_st_ = value;
        }

        uint8_t& FLNomDoor_St() OMG_NOEXCEPT {
            return m_FLNomDoor_St_;
        }

        const uint8_t& FLNomDoor_St() const OMG_NOEXCEPT {
            return m_FLNomDoor_St_;
        }

        void FLNomDoor_St(uint8_t value) {
            m_FLNomDoor_St_ = value;
        }

        uint8_t& RLNomDoor_St() OMG_NOEXCEPT {
            return m_RLNomDoor_St_;
        }

        const uint8_t& RLNomDoor_St() const OMG_NOEXCEPT {
            return m_RLNomDoor_St_;
        }

        void RLNomDoor_St(uint8_t value) {
            m_RLNomDoor_St_ = value;
        }

        uint8_t& FRNomDoor_St() OMG_NOEXCEPT {
            return m_FRNomDoor_St_;
        }

        const uint8_t& FRNomDoor_St() const OMG_NOEXCEPT {
            return m_FRNomDoor_St_;
        }

        void FRNomDoor_St(uint8_t value) {
            m_FRNomDoor_St_ = value;
        }

        uint8_t& RRNomDoor_St() OMG_NOEXCEPT {
            return m_RRNomDoor_St_;
        }

        const uint8_t& RRNomDoor_St() const OMG_NOEXCEPT {
            return m_RRNomDoor_St_;
        }

        void RRNomDoor_St(uint8_t value) {
            m_RRNomDoor_St_ = value;
        }

        uint8_t& TDoorNominal_St() OMG_NOEXCEPT {
            return m_TDoorNominal_St_;
        }

        const uint8_t& TDoorNominal_St() const OMG_NOEXCEPT {
            return m_TDoorNominal_St_;
        }

        void TDoorNominal_St(uint8_t value) {
            m_TDoorNominal_St_ = value;
        }

        uint8_t& TDrWrk_St() OMG_NOEXCEPT {
            return m_TDrWrk_St_;
        }

        const uint8_t& TDrWrk_St() const OMG_NOEXCEPT {
            return m_TDrWrk_St_;
        }

        void TDrWrk_St(uint8_t value) {
            m_TDrWrk_St_ = value;
        }

        uint8_t& TDrTripPst_Val() OMG_NOEXCEPT {
            return m_TDrTripPst_Val_;
        }

        const uint8_t& TDrTripPst_Val() const OMG_NOEXCEPT {
            return m_TDrTripPst_Val_;
        }

        void TDrTripPst_Val(uint8_t value) {
            m_TDrTripPst_Val_ = value;
        }

        uint8_t& FLDrStpRsn_st() OMG_NOEXCEPT {
            return m_FLDrStpRsn_st_;
        }

        const uint8_t& FLDrStpRsn_st() const OMG_NOEXCEPT {
            return m_FLDrStpRsn_st_;
        }

        void FLDrStpRsn_st(uint8_t value) {
            m_FLDrStpRsn_st_ = value;
        }

        uint8_t& RLDrStpRsn_st() OMG_NOEXCEPT {
            return m_RLDrStpRsn_st_;
        }

        const uint8_t& RLDrStpRsn_st() const OMG_NOEXCEPT {
            return m_RLDrStpRsn_st_;
        }

        void RLDrStpRsn_st(uint8_t value) {
            m_RLDrStpRsn_st_ = value;
        }

        uint8_t& FRDrStpRsn_st() OMG_NOEXCEPT {
            return m_FRDrStpRsn_st_;
        }

        const uint8_t& FRDrStpRsn_st() const OMG_NOEXCEPT {
            return m_FRDrStpRsn_st_;
        }

        void FRDrStpRsn_st(uint8_t value) {
            m_FRDrStpRsn_st_ = value;
        }

        uint8_t& RRDrStpRsn_st() OMG_NOEXCEPT {
            return m_RRDrStpRsn_st_;
        }

        const uint8_t& RRDrStpRsn_st() const OMG_NOEXCEPT {
            return m_RRDrStpRsn_st_;
        }

        void RRDrStpRsn_st(uint8_t value) {
            m_RRDrStpRsn_st_ = value;
        }

        uint8_t& TDrStpRsn_st() OMG_NOEXCEPT {
            return m_TDrStpRsn_st_;
        }

        const uint8_t& TDrStpRsn_st() const OMG_NOEXCEPT {
            return m_TDrStpRsn_st_;
        }

        void TDrStpRsn_st(uint8_t value) {
            m_TDrStpRsn_st_ = value;
        }

        uint8_t& TDoorTip_St() OMG_NOEXCEPT {
            return m_TDoorTip_St_;
        }

        const uint8_t& TDoorTip_St() const OMG_NOEXCEPT {
            return m_TDoorTip_St_;
        }

        void TDoorTip_St(uint8_t value) {
            m_TDoorTip_St_ = value;
        }

        uint8_t& HoodLatch_St() OMG_NOEXCEPT {
            return m_HoodLatch_St_;
        }

        const uint8_t& HoodLatch_St() const OMG_NOEXCEPT {
            return m_HoodLatch_St_;
        }

        void HoodLatch_St(uint8_t value) {
            m_HoodLatch_St_ = value;
        }

        bool operator == (const DrLth_St_struct& other_) const;
        bool operator != (const DrLth_St_struct& other_) const;

        void swap(DrLth_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLDoor_st_;
        uint8_t m_RLDoor_st_;
        uint8_t m_FRDoor_st_;
        uint8_t m_RRDoor_st_;
        uint8_t m_TDoor_st_;
        uint8_t m_FLNomDoor_St_;
        uint8_t m_RLNomDoor_St_;
        uint8_t m_FRNomDoor_St_;
        uint8_t m_RRNomDoor_St_;
        uint8_t m_TDoorNominal_St_;
        uint8_t m_TDrWrk_St_;
        uint8_t m_TDrTripPst_Val_;
        uint8_t m_FLDrStpRsn_st_;
        uint8_t m_RLDrStpRsn_st_;
        uint8_t m_FRDrStpRsn_st_;
        uint8_t m_RRDrStpRsn_st_;
        uint8_t m_TDrStpRsn_st_;
        uint8_t m_TDoorTip_St_;
        uint8_t m_HoodLatch_St_;

    };

    inline void swap(DrLth_St_struct& a, DrLth_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrLth_St_struct& sample);

    class NDDSUSERDllExport DrLth_Srv_Req_Union {
      public:
        DrLth_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrLth_Srv_Req_Union (DrLth_Srv_Req_Union&&) = default;
        DrLth_Srv_Req_Union& operator=(DrLth_Srv_Req_Union&&) = default;
        DrLth_Srv_Req_Union& operator=(const DrLth_Srv_Req_Union&) = default;
        DrLth_Srv_Req_Union(const DrLth_Srv_Req_Union&) = default;
        #else
        DrLth_Srv_Req_Union(DrLth_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        DrLth_Srv_Req_Union& operator=(DrLth_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::DrLth_Set_struct& DrLth_Set()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Req_Union::DrLth_Set not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Set_;
        }

        const BodyDomain::DrLth_Set_struct& DrLth_Set() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Req_Union::DrLth_Set not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Set_;
        }

        void DrLth_Set(const BodyDomain::DrLth_Set_struct& value) {
            m_u_.m_DrLth_Set_ = value;
            m_d_= 0;
        }

        void DrLth_Set(BodyDomain::DrLth_Set_struct&& value) {
            m_u_.m_DrLth_Set_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::DrLth_Get_struct& DrLth_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Req_Union::DrLth_Get not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Get_;
        }

        const BodyDomain::DrLth_Get_struct& DrLth_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Req_Union::DrLth_Get not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Get_;
        }

        void DrLth_Get(const BodyDomain::DrLth_Get_struct& value) {
            m_u_.m_DrLth_Get_ = value;
            m_d_= 1;
        }

        void DrLth_Get(BodyDomain::DrLth_Get_struct&& value) {
            m_u_.m_DrLth_Get_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::DrLth_Ctrl_struct& DrLth_Ctrl()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Req_Union::DrLth_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Ctrl_;
        }

        const BodyDomain::DrLth_Ctrl_struct& DrLth_Ctrl() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Req_Union::DrLth_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Ctrl_;
        }

        void DrLth_Ctrl(const BodyDomain::DrLth_Ctrl_struct& value) {
            m_u_.m_DrLth_Ctrl_ = value;
            m_d_= 2;
        }

        void DrLth_Ctrl(BodyDomain::DrLth_Ctrl_struct&& value) {
            m_u_.m_DrLth_Ctrl_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::DrLth_St_Get_struct& DrLth_St_Get()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Req_Union::DrLth_St_Get not selected by the discriminator" );
            }
            return m_u_.m_DrLth_St_Get_;
        }

        const BodyDomain::DrLth_St_Get_struct& DrLth_St_Get() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Req_Union::DrLth_St_Get not selected by the discriminator" );
            }
            return m_u_.m_DrLth_St_Get_;
        }

        void DrLth_St_Get(const BodyDomain::DrLth_St_Get_struct& value) {
            m_u_.m_DrLth_St_Get_ = value;
            m_d_= 3;
        }

        void DrLth_St_Get(BodyDomain::DrLth_St_Get_struct&& value) {
            m_u_.m_DrLth_St_Get_ = std::move(value);
            m_d_= 3;
        }

        bool operator == (const DrLth_Srv_Req_Union& other_) const;
        bool operator != (const DrLth_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(DrLth_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::DrLth_Set_struct m_DrLth_Set_;
            BodyDomain::DrLth_Get_struct m_DrLth_Get_;
            BodyDomain::DrLth_Ctrl_struct m_DrLth_Ctrl_;
            BodyDomain::DrLth_St_Get_struct m_DrLth_St_Get_;
            Union_();
            Union_(
                const BodyDomain::DrLth_Set_struct& DrLth_Set,
                const BodyDomain::DrLth_Get_struct& DrLth_Get,
                const BodyDomain::DrLth_Ctrl_struct& DrLth_Ctrl,
                const BodyDomain::DrLth_St_Get_struct& DrLth_St_Get);
        };
        Union_ m_u_;

    };

    inline void swap(DrLth_Srv_Req_Union& a, DrLth_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrLth_Srv_Req_Union& sample);

    class NDDSUSERDllExport DrLth_Srv_Resp_Union {
      public:
        DrLth_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrLth_Srv_Resp_Union (DrLth_Srv_Resp_Union&&) = default;
        DrLth_Srv_Resp_Union& operator=(DrLth_Srv_Resp_Union&&) = default;
        DrLth_Srv_Resp_Union& operator=(const DrLth_Srv_Resp_Union&) = default;
        DrLth_Srv_Resp_Union(const DrLth_Srv_Resp_Union&) = default;
        #else
        DrLth_Srv_Resp_Union(DrLth_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        DrLth_Srv_Resp_Union& operator=(DrLth_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::DrLth_Rsp_struct& DrLth_Set_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Resp_Union::DrLth_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Set_SOA_;
        }

        const BodyDomain::DrLth_Rsp_struct& DrLth_Set_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Resp_Union::DrLth_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Set_SOA_;
        }

        void DrLth_Set_SOA(const BodyDomain::DrLth_Rsp_struct& value) {
            m_u_.m_DrLth_Set_SOA_ = value;
            m_d_= 0;
        }

        void DrLth_Set_SOA(BodyDomain::DrLth_Rsp_struct&& value) {
            m_u_.m_DrLth_Set_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::DrLth_Rsp_struct& DrLth_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Resp_Union::DrLth_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Get_SOA_;
        }

        const BodyDomain::DrLth_Rsp_struct& DrLth_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Resp_Union::DrLth_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Get_SOA_;
        }

        void DrLth_Get_SOA(const BodyDomain::DrLth_Rsp_struct& value) {
            m_u_.m_DrLth_Get_SOA_ = value;
            m_d_= 1;
        }

        void DrLth_Get_SOA(BodyDomain::DrLth_Rsp_struct&& value) {
            m_u_.m_DrLth_Get_SOA_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::DrLth_Ctrl_SOA_struct& DrLth_Ctrl_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Resp_Union::DrLth_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Ctrl_SOA_;
        }

        const BodyDomain::DrLth_Ctrl_SOA_struct& DrLth_Ctrl_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Resp_Union::DrLth_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_DrLth_Ctrl_SOA_;
        }

        void DrLth_Ctrl_SOA(const BodyDomain::DrLth_Ctrl_SOA_struct& value) {
            m_u_.m_DrLth_Ctrl_SOA_ = value;
            m_d_= 2;
        }

        void DrLth_Ctrl_SOA(BodyDomain::DrLth_Ctrl_SOA_struct&& value) {
            m_u_.m_DrLth_Ctrl_SOA_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::DrLth_St_struct& DrLth_St_Get_SOA()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Resp_Union::DrLth_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_DrLth_St_Get_SOA_;
        }

        const BodyDomain::DrLth_St_struct& DrLth_St_Get_SOA() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::DrLth_Srv_Resp_Union::DrLth_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_DrLth_St_Get_SOA_;
        }

        void DrLth_St_Get_SOA(const BodyDomain::DrLth_St_struct& value) {
            m_u_.m_DrLth_St_Get_SOA_ = value;
            m_d_= 3;
        }

        void DrLth_St_Get_SOA(BodyDomain::DrLth_St_struct&& value) {
            m_u_.m_DrLth_St_Get_SOA_ = std::move(value);
            m_d_= 3;
        }

        bool operator == (const DrLth_Srv_Resp_Union& other_) const;
        bool operator != (const DrLth_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(DrLth_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::DrLth_Rsp_struct m_DrLth_Set_SOA_;
            BodyDomain::DrLth_Rsp_struct m_DrLth_Get_SOA_;
            BodyDomain::DrLth_Ctrl_SOA_struct m_DrLth_Ctrl_SOA_;
            BodyDomain::DrLth_St_struct m_DrLth_St_Get_SOA_;
            Union_();
            Union_(
                const BodyDomain::DrLth_Rsp_struct& DrLth_Set_SOA,
                const BodyDomain::DrLth_Rsp_struct& DrLth_Get_SOA,
                const BodyDomain::DrLth_Ctrl_SOA_struct& DrLth_Ctrl_SOA,
                const BodyDomain::DrLth_St_struct& DrLth_St_Get_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(DrLth_Srv_Resp_Union& a, DrLth_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrLth_Srv_Resp_Union& sample);

    class NDDSUSERDllExport Hdl_St_Get_struct {
      public:
        Hdl_St_Get_struct();

        Hdl_St_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Hdl_St_Get_struct (Hdl_St_Get_struct&&) = default;
        Hdl_St_Get_struct& operator=(Hdl_St_Get_struct&&) = default;
        Hdl_St_Get_struct& operator=(const Hdl_St_Get_struct&) = default;
        Hdl_St_Get_struct(const Hdl_St_Get_struct&) = default;
        #else
        Hdl_St_Get_struct(Hdl_St_Get_struct&& other_) OMG_NOEXCEPT;  
        Hdl_St_Get_struct& operator=(Hdl_St_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const Hdl_St_Get_struct& other_) const;
        bool operator != (const Hdl_St_Get_struct& other_) const;

        void swap(Hdl_St_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(Hdl_St_Get_struct& a, Hdl_St_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Hdl_St_Get_struct& sample);

    class NDDSUSERDllExport Hdl_St_struct {
      public:
        Hdl_St_struct();

        Hdl_St_struct(
            uint8_t FLHdlPst_St,
            uint8_t RLHdlPst_St,
            uint8_t FRHdlPst_St,
            uint8_t RRHdlPst_St,
            uint8_t FLHdlStpRsn_St,
            uint8_t RLHdlStpRsn_St,
            uint8_t FRHdlStpRsn_St,
            uint8_t RRHdlStpRsn_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Hdl_St_struct (Hdl_St_struct&&) = default;
        Hdl_St_struct& operator=(Hdl_St_struct&&) = default;
        Hdl_St_struct& operator=(const Hdl_St_struct&) = default;
        Hdl_St_struct(const Hdl_St_struct&) = default;
        #else
        Hdl_St_struct(Hdl_St_struct&& other_) OMG_NOEXCEPT;  
        Hdl_St_struct& operator=(Hdl_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLHdlPst_St() OMG_NOEXCEPT {
            return m_FLHdlPst_St_;
        }

        const uint8_t& FLHdlPst_St() const OMG_NOEXCEPT {
            return m_FLHdlPst_St_;
        }

        void FLHdlPst_St(uint8_t value) {
            m_FLHdlPst_St_ = value;
        }

        uint8_t& RLHdlPst_St() OMG_NOEXCEPT {
            return m_RLHdlPst_St_;
        }

        const uint8_t& RLHdlPst_St() const OMG_NOEXCEPT {
            return m_RLHdlPst_St_;
        }

        void RLHdlPst_St(uint8_t value) {
            m_RLHdlPst_St_ = value;
        }

        uint8_t& FRHdlPst_St() OMG_NOEXCEPT {
            return m_FRHdlPst_St_;
        }

        const uint8_t& FRHdlPst_St() const OMG_NOEXCEPT {
            return m_FRHdlPst_St_;
        }

        void FRHdlPst_St(uint8_t value) {
            m_FRHdlPst_St_ = value;
        }

        uint8_t& RRHdlPst_St() OMG_NOEXCEPT {
            return m_RRHdlPst_St_;
        }

        const uint8_t& RRHdlPst_St() const OMG_NOEXCEPT {
            return m_RRHdlPst_St_;
        }

        void RRHdlPst_St(uint8_t value) {
            m_RRHdlPst_St_ = value;
        }

        uint8_t& FLHdlStpRsn_St() OMG_NOEXCEPT {
            return m_FLHdlStpRsn_St_;
        }

        const uint8_t& FLHdlStpRsn_St() const OMG_NOEXCEPT {
            return m_FLHdlStpRsn_St_;
        }

        void FLHdlStpRsn_St(uint8_t value) {
            m_FLHdlStpRsn_St_ = value;
        }

        uint8_t& RLHdlStpRsn_St() OMG_NOEXCEPT {
            return m_RLHdlStpRsn_St_;
        }

        const uint8_t& RLHdlStpRsn_St() const OMG_NOEXCEPT {
            return m_RLHdlStpRsn_St_;
        }

        void RLHdlStpRsn_St(uint8_t value) {
            m_RLHdlStpRsn_St_ = value;
        }

        uint8_t& FRHdlStpRsn_St() OMG_NOEXCEPT {
            return m_FRHdlStpRsn_St_;
        }

        const uint8_t& FRHdlStpRsn_St() const OMG_NOEXCEPT {
            return m_FRHdlStpRsn_St_;
        }

        void FRHdlStpRsn_St(uint8_t value) {
            m_FRHdlStpRsn_St_ = value;
        }

        uint8_t& RRHdlStpRsn_St() OMG_NOEXCEPT {
            return m_RRHdlStpRsn_St_;
        }

        const uint8_t& RRHdlStpRsn_St() const OMG_NOEXCEPT {
            return m_RRHdlStpRsn_St_;
        }

        void RRHdlStpRsn_St(uint8_t value) {
            m_RRHdlStpRsn_St_ = value;
        }

        bool operator == (const Hdl_St_struct& other_) const;
        bool operator != (const Hdl_St_struct& other_) const;

        void swap(Hdl_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLHdlPst_St_;
        uint8_t m_RLHdlPst_St_;
        uint8_t m_FRHdlPst_St_;
        uint8_t m_RRHdlPst_St_;
        uint8_t m_FLHdlStpRsn_St_;
        uint8_t m_RLHdlStpRsn_St_;
        uint8_t m_FRHdlStpRsn_St_;
        uint8_t m_RRHdlStpRsn_St_;

    };

    inline void swap(Hdl_St_struct& a, Hdl_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Hdl_St_struct& sample);

    class NDDSUSERDllExport InLt_Set_struct {
      public:
        InLt_Set_struct();

        InLt_Set_struct(
            uint8_t TpLtAutoSet_Req,
            uint8_t TpLtClrSet_Req,
            uint8_t TpLtBrtSet_Req,
            uint8_t BckLtBrtSet_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        InLt_Set_struct (InLt_Set_struct&&) = default;
        InLt_Set_struct& operator=(InLt_Set_struct&&) = default;
        InLt_Set_struct& operator=(const InLt_Set_struct&) = default;
        InLt_Set_struct(const InLt_Set_struct&) = default;
        #else
        InLt_Set_struct(InLt_Set_struct&& other_) OMG_NOEXCEPT;  
        InLt_Set_struct& operator=(InLt_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& TpLtAutoSet_Req() OMG_NOEXCEPT {
            return m_TpLtAutoSet_Req_;
        }

        const uint8_t& TpLtAutoSet_Req() const OMG_NOEXCEPT {
            return m_TpLtAutoSet_Req_;
        }

        void TpLtAutoSet_Req(uint8_t value) {
            m_TpLtAutoSet_Req_ = value;
        }

        uint8_t& TpLtClrSet_Req() OMG_NOEXCEPT {
            return m_TpLtClrSet_Req_;
        }

        const uint8_t& TpLtClrSet_Req() const OMG_NOEXCEPT {
            return m_TpLtClrSet_Req_;
        }

        void TpLtClrSet_Req(uint8_t value) {
            m_TpLtClrSet_Req_ = value;
        }

        uint8_t& TpLtBrtSet_Req() OMG_NOEXCEPT {
            return m_TpLtBrtSet_Req_;
        }

        const uint8_t& TpLtBrtSet_Req() const OMG_NOEXCEPT {
            return m_TpLtBrtSet_Req_;
        }

        void TpLtBrtSet_Req(uint8_t value) {
            m_TpLtBrtSet_Req_ = value;
        }

        uint8_t& BckLtBrtSet_Req() OMG_NOEXCEPT {
            return m_BckLtBrtSet_Req_;
        }

        const uint8_t& BckLtBrtSet_Req() const OMG_NOEXCEPT {
            return m_BckLtBrtSet_Req_;
        }

        void BckLtBrtSet_Req(uint8_t value) {
            m_BckLtBrtSet_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const InLt_Set_struct& other_) const;
        bool operator != (const InLt_Set_struct& other_) const;

        void swap(InLt_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_TpLtAutoSet_Req_;
        uint8_t m_TpLtClrSet_Req_;
        uint8_t m_TpLtBrtSet_Req_;
        uint8_t m_BckLtBrtSet_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(InLt_Set_struct& a, InLt_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const InLt_Set_struct& sample);

    class NDDSUSERDllExport InLt_Get_struct {
      public:
        InLt_Get_struct();

        InLt_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        InLt_Get_struct (InLt_Get_struct&&) = default;
        InLt_Get_struct& operator=(InLt_Get_struct&&) = default;
        InLt_Get_struct& operator=(const InLt_Get_struct&) = default;
        InLt_Get_struct(const InLt_Get_struct&) = default;
        #else
        InLt_Get_struct(InLt_Get_struct&& other_) OMG_NOEXCEPT;  
        InLt_Get_struct& operator=(InLt_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const InLt_Get_struct& other_) const;
        bool operator != (const InLt_Get_struct& other_) const;

        void swap(InLt_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(InLt_Get_struct& a, InLt_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const InLt_Get_struct& sample);

    class NDDSUSERDllExport InLt_Rsp_struct {
      public:
        InLt_Rsp_struct();

        InLt_Rsp_struct(
            uint8_t TpLtAutoSet_Rsp,
            uint8_t TpLtClrSet_Rsp,
            uint8_t TpLtBrtSet_Rsp,
            uint8_t BckLtBrtSet_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        InLt_Rsp_struct (InLt_Rsp_struct&&) = default;
        InLt_Rsp_struct& operator=(InLt_Rsp_struct&&) = default;
        InLt_Rsp_struct& operator=(const InLt_Rsp_struct&) = default;
        InLt_Rsp_struct(const InLt_Rsp_struct&) = default;
        #else
        InLt_Rsp_struct(InLt_Rsp_struct&& other_) OMG_NOEXCEPT;  
        InLt_Rsp_struct& operator=(InLt_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& TpLtAutoSet_Rsp() OMG_NOEXCEPT {
            return m_TpLtAutoSet_Rsp_;
        }

        const uint8_t& TpLtAutoSet_Rsp() const OMG_NOEXCEPT {
            return m_TpLtAutoSet_Rsp_;
        }

        void TpLtAutoSet_Rsp(uint8_t value) {
            m_TpLtAutoSet_Rsp_ = value;
        }

        uint8_t& TpLtClrSet_Rsp() OMG_NOEXCEPT {
            return m_TpLtClrSet_Rsp_;
        }

        const uint8_t& TpLtClrSet_Rsp() const OMG_NOEXCEPT {
            return m_TpLtClrSet_Rsp_;
        }

        void TpLtClrSet_Rsp(uint8_t value) {
            m_TpLtClrSet_Rsp_ = value;
        }

        uint8_t& TpLtBrtSet_Rsp() OMG_NOEXCEPT {
            return m_TpLtBrtSet_Rsp_;
        }

        const uint8_t& TpLtBrtSet_Rsp() const OMG_NOEXCEPT {
            return m_TpLtBrtSet_Rsp_;
        }

        void TpLtBrtSet_Rsp(uint8_t value) {
            m_TpLtBrtSet_Rsp_ = value;
        }

        uint8_t& BckLtBrtSet_Rsp() OMG_NOEXCEPT {
            return m_BckLtBrtSet_Rsp_;
        }

        const uint8_t& BckLtBrtSet_Rsp() const OMG_NOEXCEPT {
            return m_BckLtBrtSet_Rsp_;
        }

        void BckLtBrtSet_Rsp(uint8_t value) {
            m_BckLtBrtSet_Rsp_ = value;
        }

        bool operator == (const InLt_Rsp_struct& other_) const;
        bool operator != (const InLt_Rsp_struct& other_) const;

        void swap(InLt_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_TpLtAutoSet_Rsp_;
        uint8_t m_TpLtClrSet_Rsp_;
        uint8_t m_TpLtBrtSet_Rsp_;
        uint8_t m_BckLtBrtSet_Rsp_;

    };

    inline void swap(InLt_Rsp_struct& a, InLt_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const InLt_Rsp_struct& sample);

    class NDDSUSERDllExport InLt_Ctrl_struct {
      public:
        InLt_Ctrl_struct();

        InLt_Ctrl_struct(
            uint8_t TpLtBtn_Act,
            uint8_t TpLtSearch_Act,
            uint8_t FLTpLtRead_Act,
            uint8_t RLTpLtRead_Act,
            uint8_t FRTpLtRead_Act,
            uint8_t RRTpLtRead_Act,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        InLt_Ctrl_struct (InLt_Ctrl_struct&&) = default;
        InLt_Ctrl_struct& operator=(InLt_Ctrl_struct&&) = default;
        InLt_Ctrl_struct& operator=(const InLt_Ctrl_struct&) = default;
        InLt_Ctrl_struct(const InLt_Ctrl_struct&) = default;
        #else
        InLt_Ctrl_struct(InLt_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        InLt_Ctrl_struct& operator=(InLt_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& TpLtBtn_Act() OMG_NOEXCEPT {
            return m_TpLtBtn_Act_;
        }

        const uint8_t& TpLtBtn_Act() const OMG_NOEXCEPT {
            return m_TpLtBtn_Act_;
        }

        void TpLtBtn_Act(uint8_t value) {
            m_TpLtBtn_Act_ = value;
        }

        uint8_t& TpLtSearch_Act() OMG_NOEXCEPT {
            return m_TpLtSearch_Act_;
        }

        const uint8_t& TpLtSearch_Act() const OMG_NOEXCEPT {
            return m_TpLtSearch_Act_;
        }

        void TpLtSearch_Act(uint8_t value) {
            m_TpLtSearch_Act_ = value;
        }

        uint8_t& FLTpLtRead_Act() OMG_NOEXCEPT {
            return m_FLTpLtRead_Act_;
        }

        const uint8_t& FLTpLtRead_Act() const OMG_NOEXCEPT {
            return m_FLTpLtRead_Act_;
        }

        void FLTpLtRead_Act(uint8_t value) {
            m_FLTpLtRead_Act_ = value;
        }

        uint8_t& RLTpLtRead_Act() OMG_NOEXCEPT {
            return m_RLTpLtRead_Act_;
        }

        const uint8_t& RLTpLtRead_Act() const OMG_NOEXCEPT {
            return m_RLTpLtRead_Act_;
        }

        void RLTpLtRead_Act(uint8_t value) {
            m_RLTpLtRead_Act_ = value;
        }

        uint8_t& FRTpLtRead_Act() OMG_NOEXCEPT {
            return m_FRTpLtRead_Act_;
        }

        const uint8_t& FRTpLtRead_Act() const OMG_NOEXCEPT {
            return m_FRTpLtRead_Act_;
        }

        void FRTpLtRead_Act(uint8_t value) {
            m_FRTpLtRead_Act_ = value;
        }

        uint8_t& RRTpLtRead_Act() OMG_NOEXCEPT {
            return m_RRTpLtRead_Act_;
        }

        const uint8_t& RRTpLtRead_Act() const OMG_NOEXCEPT {
            return m_RRTpLtRead_Act_;
        }

        void RRTpLtRead_Act(uint8_t value) {
            m_RRTpLtRead_Act_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const InLt_Ctrl_struct& other_) const;
        bool operator != (const InLt_Ctrl_struct& other_) const;

        void swap(InLt_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_TpLtBtn_Act_;
        uint8_t m_TpLtSearch_Act_;
        uint8_t m_FLTpLtRead_Act_;
        uint8_t m_RLTpLtRead_Act_;
        uint8_t m_FRTpLtRead_Act_;
        uint8_t m_RRTpLtRead_Act_;
        std::string m_CtrlSource_;

    };

    inline void swap(InLt_Ctrl_struct& a, InLt_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const InLt_Ctrl_struct& sample);

    class NDDSUSERDllExport InLt_Ctrl_SOA_struct {
      public:
        InLt_Ctrl_SOA_struct();

        explicit InLt_Ctrl_SOA_struct(
            uint8_t InLt_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        InLt_Ctrl_SOA_struct (InLt_Ctrl_SOA_struct&&) = default;
        InLt_Ctrl_SOA_struct& operator=(InLt_Ctrl_SOA_struct&&) = default;
        InLt_Ctrl_SOA_struct& operator=(const InLt_Ctrl_SOA_struct&) = default;
        InLt_Ctrl_SOA_struct(const InLt_Ctrl_SOA_struct&) = default;
        #else
        InLt_Ctrl_SOA_struct(InLt_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        InLt_Ctrl_SOA_struct& operator=(InLt_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& InLt_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_InLt_Ctrl_SOA_u8_;
        }

        const uint8_t& InLt_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_InLt_Ctrl_SOA_u8_;
        }

        void InLt_Ctrl_SOA_u8(uint8_t value) {
            m_InLt_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const InLt_Ctrl_SOA_struct& other_) const;
        bool operator != (const InLt_Ctrl_SOA_struct& other_) const;

        void swap(InLt_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_InLt_Ctrl_SOA_u8_;

    };

    inline void swap(InLt_Ctrl_SOA_struct& a, InLt_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const InLt_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport InLt_St_Get_struct {
      public:
        InLt_St_Get_struct();

        InLt_St_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        InLt_St_Get_struct (InLt_St_Get_struct&&) = default;
        InLt_St_Get_struct& operator=(InLt_St_Get_struct&&) = default;
        InLt_St_Get_struct& operator=(const InLt_St_Get_struct&) = default;
        InLt_St_Get_struct(const InLt_St_Get_struct&) = default;
        #else
        InLt_St_Get_struct(InLt_St_Get_struct&& other_) OMG_NOEXCEPT;  
        InLt_St_Get_struct& operator=(InLt_St_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const InLt_St_Get_struct& other_) const;
        bool operator != (const InLt_St_Get_struct& other_) const;

        void swap(InLt_St_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(InLt_St_Get_struct& a, InLt_St_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const InLt_St_Get_struct& sample);

    class NDDSUSERDllExport InLt_St_struct {
      public:
        InLt_St_struct();

        InLt_St_struct(
            uint8_t TpLtWrk_St,
            uint8_t TpLtSearch_St,
            uint8_t FLTpLtRead_St,
            uint8_t RLTpLtRead_St,
            uint8_t FRTpLtRead_St,
            uint8_t RRTpLtRead_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        InLt_St_struct (InLt_St_struct&&) = default;
        InLt_St_struct& operator=(InLt_St_struct&&) = default;
        InLt_St_struct& operator=(const InLt_St_struct&) = default;
        InLt_St_struct(const InLt_St_struct&) = default;
        #else
        InLt_St_struct(InLt_St_struct&& other_) OMG_NOEXCEPT;  
        InLt_St_struct& operator=(InLt_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& TpLtWrk_St() OMG_NOEXCEPT {
            return m_TpLtWrk_St_;
        }

        const uint8_t& TpLtWrk_St() const OMG_NOEXCEPT {
            return m_TpLtWrk_St_;
        }

        void TpLtWrk_St(uint8_t value) {
            m_TpLtWrk_St_ = value;
        }

        uint8_t& TpLtSearch_St() OMG_NOEXCEPT {
            return m_TpLtSearch_St_;
        }

        const uint8_t& TpLtSearch_St() const OMG_NOEXCEPT {
            return m_TpLtSearch_St_;
        }

        void TpLtSearch_St(uint8_t value) {
            m_TpLtSearch_St_ = value;
        }

        uint8_t& FLTpLtRead_St() OMG_NOEXCEPT {
            return m_FLTpLtRead_St_;
        }

        const uint8_t& FLTpLtRead_St() const OMG_NOEXCEPT {
            return m_FLTpLtRead_St_;
        }

        void FLTpLtRead_St(uint8_t value) {
            m_FLTpLtRead_St_ = value;
        }

        uint8_t& RLTpLtRead_St() OMG_NOEXCEPT {
            return m_RLTpLtRead_St_;
        }

        const uint8_t& RLTpLtRead_St() const OMG_NOEXCEPT {
            return m_RLTpLtRead_St_;
        }

        void RLTpLtRead_St(uint8_t value) {
            m_RLTpLtRead_St_ = value;
        }

        uint8_t& FRTpLtRead_St() OMG_NOEXCEPT {
            return m_FRTpLtRead_St_;
        }

        const uint8_t& FRTpLtRead_St() const OMG_NOEXCEPT {
            return m_FRTpLtRead_St_;
        }

        void FRTpLtRead_St(uint8_t value) {
            m_FRTpLtRead_St_ = value;
        }

        uint8_t& RRTpLtRead_St() OMG_NOEXCEPT {
            return m_RRTpLtRead_St_;
        }

        const uint8_t& RRTpLtRead_St() const OMG_NOEXCEPT {
            return m_RRTpLtRead_St_;
        }

        void RRTpLtRead_St(uint8_t value) {
            m_RRTpLtRead_St_ = value;
        }

        bool operator == (const InLt_St_struct& other_) const;
        bool operator != (const InLt_St_struct& other_) const;

        void swap(InLt_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_TpLtWrk_St_;
        uint8_t m_TpLtSearch_St_;
        uint8_t m_FLTpLtRead_St_;
        uint8_t m_RLTpLtRead_St_;
        uint8_t m_FRTpLtRead_St_;
        uint8_t m_RRTpLtRead_St_;

    };

    inline void swap(InLt_St_struct& a, InLt_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const InLt_St_struct& sample);

    class NDDSUSERDllExport InLt_Srv_Req_Union {
      public:
        InLt_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        InLt_Srv_Req_Union (InLt_Srv_Req_Union&&) = default;
        InLt_Srv_Req_Union& operator=(InLt_Srv_Req_Union&&) = default;
        InLt_Srv_Req_Union& operator=(const InLt_Srv_Req_Union&) = default;
        InLt_Srv_Req_Union(const InLt_Srv_Req_Union&) = default;
        #else
        InLt_Srv_Req_Union(InLt_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        InLt_Srv_Req_Union& operator=(InLt_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::InLt_Set_struct& InLt_Set()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Req_Union::InLt_Set not selected by the discriminator" );
            }
            return m_u_.m_InLt_Set_;
        }

        const BodyDomain::InLt_Set_struct& InLt_Set() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Req_Union::InLt_Set not selected by the discriminator" );
            }
            return m_u_.m_InLt_Set_;
        }

        void InLt_Set(const BodyDomain::InLt_Set_struct& value) {
            m_u_.m_InLt_Set_ = value;
            m_d_= 0;
        }

        void InLt_Set(BodyDomain::InLt_Set_struct&& value) {
            m_u_.m_InLt_Set_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::InLt_Get_struct& InLt_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Req_Union::InLt_Get not selected by the discriminator" );
            }
            return m_u_.m_InLt_Get_;
        }

        const BodyDomain::InLt_Get_struct& InLt_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Req_Union::InLt_Get not selected by the discriminator" );
            }
            return m_u_.m_InLt_Get_;
        }

        void InLt_Get(const BodyDomain::InLt_Get_struct& value) {
            m_u_.m_InLt_Get_ = value;
            m_d_= 1;
        }

        void InLt_Get(BodyDomain::InLt_Get_struct&& value) {
            m_u_.m_InLt_Get_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::InLt_Ctrl_struct& InLt_Ctrl()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Req_Union::InLt_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_InLt_Ctrl_;
        }

        const BodyDomain::InLt_Ctrl_struct& InLt_Ctrl() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Req_Union::InLt_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_InLt_Ctrl_;
        }

        void InLt_Ctrl(const BodyDomain::InLt_Ctrl_struct& value) {
            m_u_.m_InLt_Ctrl_ = value;
            m_d_= 2;
        }

        void InLt_Ctrl(BodyDomain::InLt_Ctrl_struct&& value) {
            m_u_.m_InLt_Ctrl_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::InLt_St_Get_struct& InLt_St_Get()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Req_Union::InLt_St_Get not selected by the discriminator" );
            }
            return m_u_.m_InLt_St_Get_;
        }

        const BodyDomain::InLt_St_Get_struct& InLt_St_Get() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Req_Union::InLt_St_Get not selected by the discriminator" );
            }
            return m_u_.m_InLt_St_Get_;
        }

        void InLt_St_Get(const BodyDomain::InLt_St_Get_struct& value) {
            m_u_.m_InLt_St_Get_ = value;
            m_d_= 3;
        }

        void InLt_St_Get(BodyDomain::InLt_St_Get_struct&& value) {
            m_u_.m_InLt_St_Get_ = std::move(value);
            m_d_= 3;
        }

        bool operator == (const InLt_Srv_Req_Union& other_) const;
        bool operator != (const InLt_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(InLt_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::InLt_Set_struct m_InLt_Set_;
            BodyDomain::InLt_Get_struct m_InLt_Get_;
            BodyDomain::InLt_Ctrl_struct m_InLt_Ctrl_;
            BodyDomain::InLt_St_Get_struct m_InLt_St_Get_;
            Union_();
            Union_(
                const BodyDomain::InLt_Set_struct& InLt_Set,
                const BodyDomain::InLt_Get_struct& InLt_Get,
                const BodyDomain::InLt_Ctrl_struct& InLt_Ctrl,
                const BodyDomain::InLt_St_Get_struct& InLt_St_Get);
        };
        Union_ m_u_;

    };

    inline void swap(InLt_Srv_Req_Union& a, InLt_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const InLt_Srv_Req_Union& sample);

    class NDDSUSERDllExport InLt_Srv_Resp_Union {
      public:
        InLt_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        InLt_Srv_Resp_Union (InLt_Srv_Resp_Union&&) = default;
        InLt_Srv_Resp_Union& operator=(InLt_Srv_Resp_Union&&) = default;
        InLt_Srv_Resp_Union& operator=(const InLt_Srv_Resp_Union&) = default;
        InLt_Srv_Resp_Union(const InLt_Srv_Resp_Union&) = default;
        #else
        InLt_Srv_Resp_Union(InLt_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        InLt_Srv_Resp_Union& operator=(InLt_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::InLt_Rsp_struct& InLt_Set_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Resp_Union::InLt_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_InLt_Set_SOA_;
        }

        const BodyDomain::InLt_Rsp_struct& InLt_Set_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Resp_Union::InLt_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_InLt_Set_SOA_;
        }

        void InLt_Set_SOA(const BodyDomain::InLt_Rsp_struct& value) {
            m_u_.m_InLt_Set_SOA_ = value;
            m_d_= 0;
        }

        void InLt_Set_SOA(BodyDomain::InLt_Rsp_struct&& value) {
            m_u_.m_InLt_Set_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::InLt_Rsp_struct& InLt_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Resp_Union::InLt_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_InLt_Get_SOA_;
        }

        const BodyDomain::InLt_Rsp_struct& InLt_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Resp_Union::InLt_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_InLt_Get_SOA_;
        }

        void InLt_Get_SOA(const BodyDomain::InLt_Rsp_struct& value) {
            m_u_.m_InLt_Get_SOA_ = value;
            m_d_= 1;
        }

        void InLt_Get_SOA(BodyDomain::InLt_Rsp_struct&& value) {
            m_u_.m_InLt_Get_SOA_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::InLt_Ctrl_SOA_struct& InLt_Ctrl_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Resp_Union::InLt_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_InLt_Ctrl_SOA_;
        }

        const BodyDomain::InLt_Ctrl_SOA_struct& InLt_Ctrl_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Resp_Union::InLt_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_InLt_Ctrl_SOA_;
        }

        void InLt_Ctrl_SOA(const BodyDomain::InLt_Ctrl_SOA_struct& value) {
            m_u_.m_InLt_Ctrl_SOA_ = value;
            m_d_= 2;
        }

        void InLt_Ctrl_SOA(BodyDomain::InLt_Ctrl_SOA_struct&& value) {
            m_u_.m_InLt_Ctrl_SOA_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::InLt_St_struct& InLt_St_Get_SOA()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Resp_Union::InLt_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_InLt_St_Get_SOA_;
        }

        const BodyDomain::InLt_St_struct& InLt_St_Get_SOA() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::InLt_Srv_Resp_Union::InLt_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_InLt_St_Get_SOA_;
        }

        void InLt_St_Get_SOA(const BodyDomain::InLt_St_struct& value) {
            m_u_.m_InLt_St_Get_SOA_ = value;
            m_d_= 3;
        }

        void InLt_St_Get_SOA(BodyDomain::InLt_St_struct&& value) {
            m_u_.m_InLt_St_Get_SOA_ = std::move(value);
            m_d_= 3;
        }

        bool operator == (const InLt_Srv_Resp_Union& other_) const;
        bool operator != (const InLt_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(InLt_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::InLt_Rsp_struct m_InLt_Set_SOA_;
            BodyDomain::InLt_Rsp_struct m_InLt_Get_SOA_;
            BodyDomain::InLt_Ctrl_SOA_struct m_InLt_Ctrl_SOA_;
            BodyDomain::InLt_St_struct m_InLt_St_Get_SOA_;
            Union_();
            Union_(
                const BodyDomain::InLt_Rsp_struct& InLt_Set_SOA,
                const BodyDomain::InLt_Rsp_struct& InLt_Get_SOA,
                const BodyDomain::InLt_Ctrl_SOA_struct& InLt_Ctrl_SOA,
                const BodyDomain::InLt_St_struct& InLt_St_Get_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(InLt_Srv_Resp_Union& a, InLt_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const InLt_Srv_Resp_Union& sample);

    class NDDSUSERDllExport AmLt_Set_struct {
      public:
        AmLt_Set_struct();

        AmLt_Set_struct(
            uint8_t AmLtBtn_Set,
            uint8_t AmLtBrt_Set,
            uint8_t AmLtMode_Set,
            uint16_t AmLtCustomClr_Set,
            uint8_t AmLtAutoBrt_Set,
            uint8_t AmLtBrtFollow_Set,
            uint8_t AmLtVoice_Set,
            uint8_t Welcome_Set,
            uint8_t AmLtMusic_Set,
            uint8_t AmLtTemp_Set,
            uint16_t AmLtMedRedVal_Set,
            uint16_t AmLtMedGreenVal_Set,
            uint16_t AmLtMedBlueVal_Set,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        AmLt_Set_struct (AmLt_Set_struct&&) = default;
        AmLt_Set_struct& operator=(AmLt_Set_struct&&) = default;
        AmLt_Set_struct& operator=(const AmLt_Set_struct&) = default;
        AmLt_Set_struct(const AmLt_Set_struct&) = default;
        #else
        AmLt_Set_struct(AmLt_Set_struct&& other_) OMG_NOEXCEPT;  
        AmLt_Set_struct& operator=(AmLt_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& AmLtBtn_Set() OMG_NOEXCEPT {
            return m_AmLtBtn_Set_;
        }

        const uint8_t& AmLtBtn_Set() const OMG_NOEXCEPT {
            return m_AmLtBtn_Set_;
        }

        void AmLtBtn_Set(uint8_t value) {
            m_AmLtBtn_Set_ = value;
        }

        uint8_t& AmLtBrt_Set() OMG_NOEXCEPT {
            return m_AmLtBrt_Set_;
        }

        const uint8_t& AmLtBrt_Set() const OMG_NOEXCEPT {
            return m_AmLtBrt_Set_;
        }

        void AmLtBrt_Set(uint8_t value) {
            m_AmLtBrt_Set_ = value;
        }

        uint8_t& AmLtMode_Set() OMG_NOEXCEPT {
            return m_AmLtMode_Set_;
        }

        const uint8_t& AmLtMode_Set() const OMG_NOEXCEPT {
            return m_AmLtMode_Set_;
        }

        void AmLtMode_Set(uint8_t value) {
            m_AmLtMode_Set_ = value;
        }

        uint16_t& AmLtCustomClr_Set() OMG_NOEXCEPT {
            return m_AmLtCustomClr_Set_;
        }

        const uint16_t& AmLtCustomClr_Set() const OMG_NOEXCEPT {
            return m_AmLtCustomClr_Set_;
        }

        void AmLtCustomClr_Set(uint16_t value) {
            m_AmLtCustomClr_Set_ = value;
        }

        uint8_t& AmLtAutoBrt_Set() OMG_NOEXCEPT {
            return m_AmLtAutoBrt_Set_;
        }

        const uint8_t& AmLtAutoBrt_Set() const OMG_NOEXCEPT {
            return m_AmLtAutoBrt_Set_;
        }

        void AmLtAutoBrt_Set(uint8_t value) {
            m_AmLtAutoBrt_Set_ = value;
        }

        uint8_t& AmLtBrtFollow_Set() OMG_NOEXCEPT {
            return m_AmLtBrtFollow_Set_;
        }

        const uint8_t& AmLtBrtFollow_Set() const OMG_NOEXCEPT {
            return m_AmLtBrtFollow_Set_;
        }

        void AmLtBrtFollow_Set(uint8_t value) {
            m_AmLtBrtFollow_Set_ = value;
        }

        uint8_t& AmLtVoice_Set() OMG_NOEXCEPT {
            return m_AmLtVoice_Set_;
        }

        const uint8_t& AmLtVoice_Set() const OMG_NOEXCEPT {
            return m_AmLtVoice_Set_;
        }

        void AmLtVoice_Set(uint8_t value) {
            m_AmLtVoice_Set_ = value;
        }

        uint8_t& Welcome_Set() OMG_NOEXCEPT {
            return m_Welcome_Set_;
        }

        const uint8_t& Welcome_Set() const OMG_NOEXCEPT {
            return m_Welcome_Set_;
        }

        void Welcome_Set(uint8_t value) {
            m_Welcome_Set_ = value;
        }

        uint8_t& AmLtMusic_Set() OMG_NOEXCEPT {
            return m_AmLtMusic_Set_;
        }

        const uint8_t& AmLtMusic_Set() const OMG_NOEXCEPT {
            return m_AmLtMusic_Set_;
        }

        void AmLtMusic_Set(uint8_t value) {
            m_AmLtMusic_Set_ = value;
        }

        uint8_t& AmLtTemp_Set() OMG_NOEXCEPT {
            return m_AmLtTemp_Set_;
        }

        const uint8_t& AmLtTemp_Set() const OMG_NOEXCEPT {
            return m_AmLtTemp_Set_;
        }

        void AmLtTemp_Set(uint8_t value) {
            m_AmLtTemp_Set_ = value;
        }

        uint16_t& AmLtMedRedVal_Set() OMG_NOEXCEPT {
            return m_AmLtMedRedVal_Set_;
        }

        const uint16_t& AmLtMedRedVal_Set() const OMG_NOEXCEPT {
            return m_AmLtMedRedVal_Set_;
        }

        void AmLtMedRedVal_Set(uint16_t value) {
            m_AmLtMedRedVal_Set_ = value;
        }

        uint16_t& AmLtMedGreenVal_Set() OMG_NOEXCEPT {
            return m_AmLtMedGreenVal_Set_;
        }

        const uint16_t& AmLtMedGreenVal_Set() const OMG_NOEXCEPT {
            return m_AmLtMedGreenVal_Set_;
        }

        void AmLtMedGreenVal_Set(uint16_t value) {
            m_AmLtMedGreenVal_Set_ = value;
        }

        uint16_t& AmLtMedBlueVal_Set() OMG_NOEXCEPT {
            return m_AmLtMedBlueVal_Set_;
        }

        const uint16_t& AmLtMedBlueVal_Set() const OMG_NOEXCEPT {
            return m_AmLtMedBlueVal_Set_;
        }

        void AmLtMedBlueVal_Set(uint16_t value) {
            m_AmLtMedBlueVal_Set_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const AmLt_Set_struct& other_) const;
        bool operator != (const AmLt_Set_struct& other_) const;

        void swap(AmLt_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_AmLtBtn_Set_;
        uint8_t m_AmLtBrt_Set_;
        uint8_t m_AmLtMode_Set_;
        uint16_t m_AmLtCustomClr_Set_;
        uint8_t m_AmLtAutoBrt_Set_;
        uint8_t m_AmLtBrtFollow_Set_;
        uint8_t m_AmLtVoice_Set_;
        uint8_t m_Welcome_Set_;
        uint8_t m_AmLtMusic_Set_;
        uint8_t m_AmLtTemp_Set_;
        uint16_t m_AmLtMedRedVal_Set_;
        uint16_t m_AmLtMedGreenVal_Set_;
        uint16_t m_AmLtMedBlueVal_Set_;
        std::string m_CtrlSource_;

    };

    inline void swap(AmLt_Set_struct& a, AmLt_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const AmLt_Set_struct& sample);

    class NDDSUSERDllExport AmLt_Get_struct {
      public:
        AmLt_Get_struct();

        AmLt_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        AmLt_Get_struct (AmLt_Get_struct&&) = default;
        AmLt_Get_struct& operator=(AmLt_Get_struct&&) = default;
        AmLt_Get_struct& operator=(const AmLt_Get_struct&) = default;
        AmLt_Get_struct(const AmLt_Get_struct&) = default;
        #else
        AmLt_Get_struct(AmLt_Get_struct&& other_) OMG_NOEXCEPT;  
        AmLt_Get_struct& operator=(AmLt_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const AmLt_Get_struct& other_) const;
        bool operator != (const AmLt_Get_struct& other_) const;

        void swap(AmLt_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(AmLt_Get_struct& a, AmLt_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const AmLt_Get_struct& sample);

    class NDDSUSERDllExport AmLt_Rsp_struct {
      public:
        AmLt_Rsp_struct();

        AmLt_Rsp_struct(
            uint8_t AmLtBtn_Rsp,
            uint8_t AmLtBrt_Rsp,
            uint8_t AmLtMode_Rsp,
            uint16_t AmLtCustomClr_Rsp,
            uint8_t AmLtAutoBrt_Rsp,
            uint8_t AmLtBrtFollow_Rsp,
            uint8_t AmLtVoice_Rsp,
            uint8_t AmLtWelcome_Rsp,
            uint8_t AmLtMusic_Rsp,
            uint8_t AmLtTemp_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        AmLt_Rsp_struct (AmLt_Rsp_struct&&) = default;
        AmLt_Rsp_struct& operator=(AmLt_Rsp_struct&&) = default;
        AmLt_Rsp_struct& operator=(const AmLt_Rsp_struct&) = default;
        AmLt_Rsp_struct(const AmLt_Rsp_struct&) = default;
        #else
        AmLt_Rsp_struct(AmLt_Rsp_struct&& other_) OMG_NOEXCEPT;  
        AmLt_Rsp_struct& operator=(AmLt_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& AmLtBtn_Rsp() OMG_NOEXCEPT {
            return m_AmLtBtn_Rsp_;
        }

        const uint8_t& AmLtBtn_Rsp() const OMG_NOEXCEPT {
            return m_AmLtBtn_Rsp_;
        }

        void AmLtBtn_Rsp(uint8_t value) {
            m_AmLtBtn_Rsp_ = value;
        }

        uint8_t& AmLtBrt_Rsp() OMG_NOEXCEPT {
            return m_AmLtBrt_Rsp_;
        }

        const uint8_t& AmLtBrt_Rsp() const OMG_NOEXCEPT {
            return m_AmLtBrt_Rsp_;
        }

        void AmLtBrt_Rsp(uint8_t value) {
            m_AmLtBrt_Rsp_ = value;
        }

        uint8_t& AmLtMode_Rsp() OMG_NOEXCEPT {
            return m_AmLtMode_Rsp_;
        }

        const uint8_t& AmLtMode_Rsp() const OMG_NOEXCEPT {
            return m_AmLtMode_Rsp_;
        }

        void AmLtMode_Rsp(uint8_t value) {
            m_AmLtMode_Rsp_ = value;
        }

        uint16_t& AmLtCustomClr_Rsp() OMG_NOEXCEPT {
            return m_AmLtCustomClr_Rsp_;
        }

        const uint16_t& AmLtCustomClr_Rsp() const OMG_NOEXCEPT {
            return m_AmLtCustomClr_Rsp_;
        }

        void AmLtCustomClr_Rsp(uint16_t value) {
            m_AmLtCustomClr_Rsp_ = value;
        }

        uint8_t& AmLtAutoBrt_Rsp() OMG_NOEXCEPT {
            return m_AmLtAutoBrt_Rsp_;
        }

        const uint8_t& AmLtAutoBrt_Rsp() const OMG_NOEXCEPT {
            return m_AmLtAutoBrt_Rsp_;
        }

        void AmLtAutoBrt_Rsp(uint8_t value) {
            m_AmLtAutoBrt_Rsp_ = value;
        }

        uint8_t& AmLtBrtFollow_Rsp() OMG_NOEXCEPT {
            return m_AmLtBrtFollow_Rsp_;
        }

        const uint8_t& AmLtBrtFollow_Rsp() const OMG_NOEXCEPT {
            return m_AmLtBrtFollow_Rsp_;
        }

        void AmLtBrtFollow_Rsp(uint8_t value) {
            m_AmLtBrtFollow_Rsp_ = value;
        }

        uint8_t& AmLtVoice_Rsp() OMG_NOEXCEPT {
            return m_AmLtVoice_Rsp_;
        }

        const uint8_t& AmLtVoice_Rsp() const OMG_NOEXCEPT {
            return m_AmLtVoice_Rsp_;
        }

        void AmLtVoice_Rsp(uint8_t value) {
            m_AmLtVoice_Rsp_ = value;
        }

        uint8_t& AmLtWelcome_Rsp() OMG_NOEXCEPT {
            return m_AmLtWelcome_Rsp_;
        }

        const uint8_t& AmLtWelcome_Rsp() const OMG_NOEXCEPT {
            return m_AmLtWelcome_Rsp_;
        }

        void AmLtWelcome_Rsp(uint8_t value) {
            m_AmLtWelcome_Rsp_ = value;
        }

        uint8_t& AmLtMusic_Rsp() OMG_NOEXCEPT {
            return m_AmLtMusic_Rsp_;
        }

        const uint8_t& AmLtMusic_Rsp() const OMG_NOEXCEPT {
            return m_AmLtMusic_Rsp_;
        }

        void AmLtMusic_Rsp(uint8_t value) {
            m_AmLtMusic_Rsp_ = value;
        }

        uint8_t& AmLtTemp_Rsp() OMG_NOEXCEPT {
            return m_AmLtTemp_Rsp_;
        }

        const uint8_t& AmLtTemp_Rsp() const OMG_NOEXCEPT {
            return m_AmLtTemp_Rsp_;
        }

        void AmLtTemp_Rsp(uint8_t value) {
            m_AmLtTemp_Rsp_ = value;
        }

        bool operator == (const AmLt_Rsp_struct& other_) const;
        bool operator != (const AmLt_Rsp_struct& other_) const;

        void swap(AmLt_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_AmLtBtn_Rsp_;
        uint8_t m_AmLtBrt_Rsp_;
        uint8_t m_AmLtMode_Rsp_;
        uint16_t m_AmLtCustomClr_Rsp_;
        uint8_t m_AmLtAutoBrt_Rsp_;
        uint8_t m_AmLtBrtFollow_Rsp_;
        uint8_t m_AmLtVoice_Rsp_;
        uint8_t m_AmLtWelcome_Rsp_;
        uint8_t m_AmLtMusic_Rsp_;
        uint8_t m_AmLtTemp_Rsp_;

    };

    inline void swap(AmLt_Rsp_struct& a, AmLt_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const AmLt_Rsp_struct& sample);

    class NDDSUSERDllExport AmLt_Srv_Req_Union {
      public:
        AmLt_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        AmLt_Srv_Req_Union (AmLt_Srv_Req_Union&&) = default;
        AmLt_Srv_Req_Union& operator=(AmLt_Srv_Req_Union&&) = default;
        AmLt_Srv_Req_Union& operator=(const AmLt_Srv_Req_Union&) = default;
        AmLt_Srv_Req_Union(const AmLt_Srv_Req_Union&) = default;
        #else
        AmLt_Srv_Req_Union(AmLt_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        AmLt_Srv_Req_Union& operator=(AmLt_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::AmLt_Set_struct& AmLt_Set()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::AmLt_Srv_Req_Union::AmLt_Set not selected by the discriminator" );
            }
            return m_u_.m_AmLt_Set_;
        }

        const BodyDomain::AmLt_Set_struct& AmLt_Set() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::AmLt_Srv_Req_Union::AmLt_Set not selected by the discriminator" );
            }
            return m_u_.m_AmLt_Set_;
        }

        void AmLt_Set(const BodyDomain::AmLt_Set_struct& value) {
            m_u_.m_AmLt_Set_ = value;
            m_d_= 0;
        }

        void AmLt_Set(BodyDomain::AmLt_Set_struct&& value) {
            m_u_.m_AmLt_Set_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::AmLt_Get_struct& AmLt_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::AmLt_Srv_Req_Union::AmLt_Get not selected by the discriminator" );
            }
            return m_u_.m_AmLt_Get_;
        }

        const BodyDomain::AmLt_Get_struct& AmLt_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::AmLt_Srv_Req_Union::AmLt_Get not selected by the discriminator" );
            }
            return m_u_.m_AmLt_Get_;
        }

        void AmLt_Get(const BodyDomain::AmLt_Get_struct& value) {
            m_u_.m_AmLt_Get_ = value;
            m_d_= 1;
        }

        void AmLt_Get(BodyDomain::AmLt_Get_struct&& value) {
            m_u_.m_AmLt_Get_ = std::move(value);
            m_d_= 1;
        }

        bool operator == (const AmLt_Srv_Req_Union& other_) const;
        bool operator != (const AmLt_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(AmLt_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::AmLt_Set_struct m_AmLt_Set_;
            BodyDomain::AmLt_Get_struct m_AmLt_Get_;
            Union_();
            Union_(
                const BodyDomain::AmLt_Set_struct& AmLt_Set,
                const BodyDomain::AmLt_Get_struct& AmLt_Get);
        };
        Union_ m_u_;

    };

    inline void swap(AmLt_Srv_Req_Union& a, AmLt_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const AmLt_Srv_Req_Union& sample);

    class NDDSUSERDllExport AmLt_Srv_Resp_Union {
      public:
        AmLt_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        AmLt_Srv_Resp_Union (AmLt_Srv_Resp_Union&&) = default;
        AmLt_Srv_Resp_Union& operator=(AmLt_Srv_Resp_Union&&) = default;
        AmLt_Srv_Resp_Union& operator=(const AmLt_Srv_Resp_Union&) = default;
        AmLt_Srv_Resp_Union(const AmLt_Srv_Resp_Union&) = default;
        #else
        AmLt_Srv_Resp_Union(AmLt_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        AmLt_Srv_Resp_Union& operator=(AmLt_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::AmLt_Rsp_struct& AmLt_Set_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::AmLt_Srv_Resp_Union::AmLt_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_AmLt_Set_SOA_;
        }

        const BodyDomain::AmLt_Rsp_struct& AmLt_Set_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::AmLt_Srv_Resp_Union::AmLt_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_AmLt_Set_SOA_;
        }

        void AmLt_Set_SOA(const BodyDomain::AmLt_Rsp_struct& value) {
            m_u_.m_AmLt_Set_SOA_ = value;
            m_d_= 0;
        }

        void AmLt_Set_SOA(BodyDomain::AmLt_Rsp_struct&& value) {
            m_u_.m_AmLt_Set_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::AmLt_Rsp_struct& AmLt_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::AmLt_Srv_Resp_Union::AmLt_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_AmLt_Get_SOA_;
        }

        const BodyDomain::AmLt_Rsp_struct& AmLt_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::AmLt_Srv_Resp_Union::AmLt_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_AmLt_Get_SOA_;
        }

        void AmLt_Get_SOA(const BodyDomain::AmLt_Rsp_struct& value) {
            m_u_.m_AmLt_Get_SOA_ = value;
            m_d_= 1;
        }

        void AmLt_Get_SOA(BodyDomain::AmLt_Rsp_struct&& value) {
            m_u_.m_AmLt_Get_SOA_ = std::move(value);
            m_d_= 1;
        }

        bool operator == (const AmLt_Srv_Resp_Union& other_) const;
        bool operator != (const AmLt_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(AmLt_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::AmLt_Rsp_struct m_AmLt_Set_SOA_;
            BodyDomain::AmLt_Rsp_struct m_AmLt_Get_SOA_;
            Union_();
            Union_(
                const BodyDomain::AmLt_Rsp_struct& AmLt_Set_SOA,
                const BodyDomain::AmLt_Rsp_struct& AmLt_Get_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(AmLt_Srv_Resp_Union& a, AmLt_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const AmLt_Srv_Resp_Union& sample);

    class NDDSUSERDllExport ExtLt_Ctrl_Struct {
      public:
        ExtLt_Ctrl_Struct();

        ExtLt_Ctrl_Struct(
            uint8_t TurnLight_Req,
            uint8_t EtnlLgt_Req,
            uint8_t HighBeam_Req,
            uint8_t HDBI_RearFogBm_Req,
            uint8_t FollowMeHome_Req,
            uint8_t LgtHeightAdjSet_Req,
            uint8_t AHB_Req,
            uint8_t HzrdSW_St,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        ExtLt_Ctrl_Struct (ExtLt_Ctrl_Struct&&) = default;
        ExtLt_Ctrl_Struct& operator=(ExtLt_Ctrl_Struct&&) = default;
        ExtLt_Ctrl_Struct& operator=(const ExtLt_Ctrl_Struct&) = default;
        ExtLt_Ctrl_Struct(const ExtLt_Ctrl_Struct&) = default;
        #else
        ExtLt_Ctrl_Struct(ExtLt_Ctrl_Struct&& other_) OMG_NOEXCEPT;  
        ExtLt_Ctrl_Struct& operator=(ExtLt_Ctrl_Struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& TurnLight_Req() OMG_NOEXCEPT {
            return m_TurnLight_Req_;
        }

        const uint8_t& TurnLight_Req() const OMG_NOEXCEPT {
            return m_TurnLight_Req_;
        }

        void TurnLight_Req(uint8_t value) {
            m_TurnLight_Req_ = value;
        }

        uint8_t& EtnlLgt_Req() OMG_NOEXCEPT {
            return m_EtnlLgt_Req_;
        }

        const uint8_t& EtnlLgt_Req() const OMG_NOEXCEPT {
            return m_EtnlLgt_Req_;
        }

        void EtnlLgt_Req(uint8_t value) {
            m_EtnlLgt_Req_ = value;
        }

        uint8_t& HighBeam_Req() OMG_NOEXCEPT {
            return m_HighBeam_Req_;
        }

        const uint8_t& HighBeam_Req() const OMG_NOEXCEPT {
            return m_HighBeam_Req_;
        }

        void HighBeam_Req(uint8_t value) {
            m_HighBeam_Req_ = value;
        }

        uint8_t& HDBI_RearFogBm_Req() OMG_NOEXCEPT {
            return m_HDBI_RearFogBm_Req_;
        }

        const uint8_t& HDBI_RearFogBm_Req() const OMG_NOEXCEPT {
            return m_HDBI_RearFogBm_Req_;
        }

        void HDBI_RearFogBm_Req(uint8_t value) {
            m_HDBI_RearFogBm_Req_ = value;
        }

        uint8_t& FollowMeHome_Req() OMG_NOEXCEPT {
            return m_FollowMeHome_Req_;
        }

        const uint8_t& FollowMeHome_Req() const OMG_NOEXCEPT {
            return m_FollowMeHome_Req_;
        }

        void FollowMeHome_Req(uint8_t value) {
            m_FollowMeHome_Req_ = value;
        }

        uint8_t& LgtHeightAdjSet_Req() OMG_NOEXCEPT {
            return m_LgtHeightAdjSet_Req_;
        }

        const uint8_t& LgtHeightAdjSet_Req() const OMG_NOEXCEPT {
            return m_LgtHeightAdjSet_Req_;
        }

        void LgtHeightAdjSet_Req(uint8_t value) {
            m_LgtHeightAdjSet_Req_ = value;
        }

        uint8_t& AHB_Req() OMG_NOEXCEPT {
            return m_AHB_Req_;
        }

        const uint8_t& AHB_Req() const OMG_NOEXCEPT {
            return m_AHB_Req_;
        }

        void AHB_Req(uint8_t value) {
            m_AHB_Req_ = value;
        }

        uint8_t& HzrdSW_St() OMG_NOEXCEPT {
            return m_HzrdSW_St_;
        }

        const uint8_t& HzrdSW_St() const OMG_NOEXCEPT {
            return m_HzrdSW_St_;
        }

        void HzrdSW_St(uint8_t value) {
            m_HzrdSW_St_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const ExtLt_Ctrl_Struct& other_) const;
        bool operator != (const ExtLt_Ctrl_Struct& other_) const;

        void swap(ExtLt_Ctrl_Struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_TurnLight_Req_;
        uint8_t m_EtnlLgt_Req_;
        uint8_t m_HighBeam_Req_;
        uint8_t m_HDBI_RearFogBm_Req_;
        uint8_t m_FollowMeHome_Req_;
        uint8_t m_LgtHeightAdjSet_Req_;
        uint8_t m_AHB_Req_;
        uint8_t m_HzrdSW_St_;
        std::string m_CtrlSource_;

    };

    inline void swap(ExtLt_Ctrl_Struct& a, ExtLt_Ctrl_Struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ExtLt_Ctrl_Struct& sample);

    class NDDSUSERDllExport ExtLt_Ctrl_SOA_struct {
      public:
        ExtLt_Ctrl_SOA_struct();

        explicit ExtLt_Ctrl_SOA_struct(
            uint8_t ExtLt_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        ExtLt_Ctrl_SOA_struct (ExtLt_Ctrl_SOA_struct&&) = default;
        ExtLt_Ctrl_SOA_struct& operator=(ExtLt_Ctrl_SOA_struct&&) = default;
        ExtLt_Ctrl_SOA_struct& operator=(const ExtLt_Ctrl_SOA_struct&) = default;
        ExtLt_Ctrl_SOA_struct(const ExtLt_Ctrl_SOA_struct&) = default;
        #else
        ExtLt_Ctrl_SOA_struct(ExtLt_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        ExtLt_Ctrl_SOA_struct& operator=(ExtLt_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& ExtLt_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_ExtLt_Ctrl_SOA_u8_;
        }

        const uint8_t& ExtLt_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_ExtLt_Ctrl_SOA_u8_;
        }

        void ExtLt_Ctrl_SOA_u8(uint8_t value) {
            m_ExtLt_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const ExtLt_Ctrl_SOA_struct& other_) const;
        bool operator != (const ExtLt_Ctrl_SOA_struct& other_) const;

        void swap(ExtLt_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_ExtLt_Ctrl_SOA_u8_;

    };

    inline void swap(ExtLt_Ctrl_SOA_struct& a, ExtLt_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ExtLt_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport ExtLt_St_Struct {
      public:
        ExtLt_St_Struct();

        ExtLt_St_Struct(
            uint8_t LeftTurnLgt_Req,
            uint8_t RgtTurnLgt_Req,
            uint8_t FLPstnLgt_Req,
            uint8_t FRPstnLgt_Req,
            uint8_t RLPstnLgt_Req,
            uint8_t RRPstnLgt_Req,
            uint8_t HighLgt_Req,
            uint8_t LwLgt_Req,
            uint8_t HDBM_RearFogBm_Req,
            uint8_t EtnlLgt_Rsp,
            uint8_t FollowMeHome_Rsp,
            uint8_t LgtHeightAdjSet_Rsp,
            uint8_t AHB_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        ExtLt_St_Struct (ExtLt_St_Struct&&) = default;
        ExtLt_St_Struct& operator=(ExtLt_St_Struct&&) = default;
        ExtLt_St_Struct& operator=(const ExtLt_St_Struct&) = default;
        ExtLt_St_Struct(const ExtLt_St_Struct&) = default;
        #else
        ExtLt_St_Struct(ExtLt_St_Struct&& other_) OMG_NOEXCEPT;  
        ExtLt_St_Struct& operator=(ExtLt_St_Struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& LeftTurnLgt_Req() OMG_NOEXCEPT {
            return m_LeftTurnLgt_Req_;
        }

        const uint8_t& LeftTurnLgt_Req() const OMG_NOEXCEPT {
            return m_LeftTurnLgt_Req_;
        }

        void LeftTurnLgt_Req(uint8_t value) {
            m_LeftTurnLgt_Req_ = value;
        }

        uint8_t& RgtTurnLgt_Req() OMG_NOEXCEPT {
            return m_RgtTurnLgt_Req_;
        }

        const uint8_t& RgtTurnLgt_Req() const OMG_NOEXCEPT {
            return m_RgtTurnLgt_Req_;
        }

        void RgtTurnLgt_Req(uint8_t value) {
            m_RgtTurnLgt_Req_ = value;
        }

        uint8_t& FLPstnLgt_Req() OMG_NOEXCEPT {
            return m_FLPstnLgt_Req_;
        }

        const uint8_t& FLPstnLgt_Req() const OMG_NOEXCEPT {
            return m_FLPstnLgt_Req_;
        }

        void FLPstnLgt_Req(uint8_t value) {
            m_FLPstnLgt_Req_ = value;
        }

        uint8_t& FRPstnLgt_Req() OMG_NOEXCEPT {
            return m_FRPstnLgt_Req_;
        }

        const uint8_t& FRPstnLgt_Req() const OMG_NOEXCEPT {
            return m_FRPstnLgt_Req_;
        }

        void FRPstnLgt_Req(uint8_t value) {
            m_FRPstnLgt_Req_ = value;
        }

        uint8_t& RLPstnLgt_Req() OMG_NOEXCEPT {
            return m_RLPstnLgt_Req_;
        }

        const uint8_t& RLPstnLgt_Req() const OMG_NOEXCEPT {
            return m_RLPstnLgt_Req_;
        }

        void RLPstnLgt_Req(uint8_t value) {
            m_RLPstnLgt_Req_ = value;
        }

        uint8_t& RRPstnLgt_Req() OMG_NOEXCEPT {
            return m_RRPstnLgt_Req_;
        }

        const uint8_t& RRPstnLgt_Req() const OMG_NOEXCEPT {
            return m_RRPstnLgt_Req_;
        }

        void RRPstnLgt_Req(uint8_t value) {
            m_RRPstnLgt_Req_ = value;
        }

        uint8_t& HighLgt_Req() OMG_NOEXCEPT {
            return m_HighLgt_Req_;
        }

        const uint8_t& HighLgt_Req() const OMG_NOEXCEPT {
            return m_HighLgt_Req_;
        }

        void HighLgt_Req(uint8_t value) {
            m_HighLgt_Req_ = value;
        }

        uint8_t& LwLgt_Req() OMG_NOEXCEPT {
            return m_LwLgt_Req_;
        }

        const uint8_t& LwLgt_Req() const OMG_NOEXCEPT {
            return m_LwLgt_Req_;
        }

        void LwLgt_Req(uint8_t value) {
            m_LwLgt_Req_ = value;
        }

        uint8_t& HDBM_RearFogBm_Req() OMG_NOEXCEPT {
            return m_HDBM_RearFogBm_Req_;
        }

        const uint8_t& HDBM_RearFogBm_Req() const OMG_NOEXCEPT {
            return m_HDBM_RearFogBm_Req_;
        }

        void HDBM_RearFogBm_Req(uint8_t value) {
            m_HDBM_RearFogBm_Req_ = value;
        }

        uint8_t& EtnlLgt_Rsp() OMG_NOEXCEPT {
            return m_EtnlLgt_Rsp_;
        }

        const uint8_t& EtnlLgt_Rsp() const OMG_NOEXCEPT {
            return m_EtnlLgt_Rsp_;
        }

        void EtnlLgt_Rsp(uint8_t value) {
            m_EtnlLgt_Rsp_ = value;
        }

        uint8_t& FollowMeHome_Rsp() OMG_NOEXCEPT {
            return m_FollowMeHome_Rsp_;
        }

        const uint8_t& FollowMeHome_Rsp() const OMG_NOEXCEPT {
            return m_FollowMeHome_Rsp_;
        }

        void FollowMeHome_Rsp(uint8_t value) {
            m_FollowMeHome_Rsp_ = value;
        }

        uint8_t& LgtHeightAdjSet_Rsp() OMG_NOEXCEPT {
            return m_LgtHeightAdjSet_Rsp_;
        }

        const uint8_t& LgtHeightAdjSet_Rsp() const OMG_NOEXCEPT {
            return m_LgtHeightAdjSet_Rsp_;
        }

        void LgtHeightAdjSet_Rsp(uint8_t value) {
            m_LgtHeightAdjSet_Rsp_ = value;
        }

        uint8_t& AHB_Rsp() OMG_NOEXCEPT {
            return m_AHB_Rsp_;
        }

        const uint8_t& AHB_Rsp() const OMG_NOEXCEPT {
            return m_AHB_Rsp_;
        }

        void AHB_Rsp(uint8_t value) {
            m_AHB_Rsp_ = value;
        }

        bool operator == (const ExtLt_St_Struct& other_) const;
        bool operator != (const ExtLt_St_Struct& other_) const;

        void swap(ExtLt_St_Struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_LeftTurnLgt_Req_;
        uint8_t m_RgtTurnLgt_Req_;
        uint8_t m_FLPstnLgt_Req_;
        uint8_t m_FRPstnLgt_Req_;
        uint8_t m_RLPstnLgt_Req_;
        uint8_t m_RRPstnLgt_Req_;
        uint8_t m_HighLgt_Req_;
        uint8_t m_LwLgt_Req_;
        uint8_t m_HDBM_RearFogBm_Req_;
        uint8_t m_EtnlLgt_Rsp_;
        uint8_t m_FollowMeHome_Rsp_;
        uint8_t m_LgtHeightAdjSet_Rsp_;
        uint8_t m_AHB_Rsp_;

    };

    inline void swap(ExtLt_St_Struct& a, ExtLt_St_Struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ExtLt_St_Struct& sample);

    class NDDSUSERDllExport BdSf_Ctrl_struct {
      public:
        BdSf_Ctrl_struct();

        BdSf_Ctrl_struct(
            uint8_t LChdlock_Req,
            uint8_t RChdlock_Req,
            uint8_t ChdLockMode_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdSf_Ctrl_struct (BdSf_Ctrl_struct&&) = default;
        BdSf_Ctrl_struct& operator=(BdSf_Ctrl_struct&&) = default;
        BdSf_Ctrl_struct& operator=(const BdSf_Ctrl_struct&) = default;
        BdSf_Ctrl_struct(const BdSf_Ctrl_struct&) = default;
        #else
        BdSf_Ctrl_struct(BdSf_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        BdSf_Ctrl_struct& operator=(BdSf_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& LChdlock_Req() OMG_NOEXCEPT {
            return m_LChdlock_Req_;
        }

        const uint8_t& LChdlock_Req() const OMG_NOEXCEPT {
            return m_LChdlock_Req_;
        }

        void LChdlock_Req(uint8_t value) {
            m_LChdlock_Req_ = value;
        }

        uint8_t& RChdlock_Req() OMG_NOEXCEPT {
            return m_RChdlock_Req_;
        }

        const uint8_t& RChdlock_Req() const OMG_NOEXCEPT {
            return m_RChdlock_Req_;
        }

        void RChdlock_Req(uint8_t value) {
            m_RChdlock_Req_ = value;
        }

        uint8_t& ChdLockMode_Req() OMG_NOEXCEPT {
            return m_ChdLockMode_Req_;
        }

        const uint8_t& ChdLockMode_Req() const OMG_NOEXCEPT {
            return m_ChdLockMode_Req_;
        }

        void ChdLockMode_Req(uint8_t value) {
            m_ChdLockMode_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdSf_Ctrl_struct& other_) const;
        bool operator != (const BdSf_Ctrl_struct& other_) const;

        void swap(BdSf_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_LChdlock_Req_;
        uint8_t m_RChdlock_Req_;
        uint8_t m_ChdLockMode_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdSf_Ctrl_struct& a, BdSf_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdSf_Ctrl_struct& sample);

    class NDDSUSERDllExport BdSf_Ctrl_SOA_struct {
      public:
        BdSf_Ctrl_SOA_struct();

        explicit BdSf_Ctrl_SOA_struct(
            uint8_t BdSf_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdSf_Ctrl_SOA_struct (BdSf_Ctrl_SOA_struct&&) = default;
        BdSf_Ctrl_SOA_struct& operator=(BdSf_Ctrl_SOA_struct&&) = default;
        BdSf_Ctrl_SOA_struct& operator=(const BdSf_Ctrl_SOA_struct&) = default;
        BdSf_Ctrl_SOA_struct(const BdSf_Ctrl_SOA_struct&) = default;
        #else
        BdSf_Ctrl_SOA_struct(BdSf_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        BdSf_Ctrl_SOA_struct& operator=(BdSf_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& BdSf_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_BdSf_Ctrl_SOA_u8_;
        }

        const uint8_t& BdSf_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_BdSf_Ctrl_SOA_u8_;
        }

        void BdSf_Ctrl_SOA_u8(uint8_t value) {
            m_BdSf_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const BdSf_Ctrl_SOA_struct& other_) const;
        bool operator != (const BdSf_Ctrl_SOA_struct& other_) const;

        void swap(BdSf_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_BdSf_Ctrl_SOA_u8_;

    };

    inline void swap(BdSf_Ctrl_SOA_struct& a, BdSf_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdSf_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport BdSf_St_struct {
      public:
        BdSf_St_struct();

        BdSf_St_struct(
            uint8_t LChdlock_st,
            uint8_t RChdlock_st,
            uint8_t ChdLockMode_st);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdSf_St_struct (BdSf_St_struct&&) = default;
        BdSf_St_struct& operator=(BdSf_St_struct&&) = default;
        BdSf_St_struct& operator=(const BdSf_St_struct&) = default;
        BdSf_St_struct(const BdSf_St_struct&) = default;
        #else
        BdSf_St_struct(BdSf_St_struct&& other_) OMG_NOEXCEPT;  
        BdSf_St_struct& operator=(BdSf_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& LChdlock_st() OMG_NOEXCEPT {
            return m_LChdlock_st_;
        }

        const uint8_t& LChdlock_st() const OMG_NOEXCEPT {
            return m_LChdlock_st_;
        }

        void LChdlock_st(uint8_t value) {
            m_LChdlock_st_ = value;
        }

        uint8_t& RChdlock_st() OMG_NOEXCEPT {
            return m_RChdlock_st_;
        }

        const uint8_t& RChdlock_st() const OMG_NOEXCEPT {
            return m_RChdlock_st_;
        }

        void RChdlock_st(uint8_t value) {
            m_RChdlock_st_ = value;
        }

        uint8_t& ChdLockMode_st() OMG_NOEXCEPT {
            return m_ChdLockMode_st_;
        }

        const uint8_t& ChdLockMode_st() const OMG_NOEXCEPT {
            return m_ChdLockMode_st_;
        }

        void ChdLockMode_st(uint8_t value) {
            m_ChdLockMode_st_ = value;
        }

        bool operator == (const BdSf_St_struct& other_) const;
        bool operator != (const BdSf_St_struct& other_) const;

        void swap(BdSf_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_LChdlock_st_;
        uint8_t m_RChdlock_st_;
        uint8_t m_ChdLockMode_st_;

    };

    inline void swap(BdSf_St_struct& a, BdSf_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdSf_St_struct& sample);

    class NDDSUSERDllExport CgC_Ctrl_struct {
      public:
        CgC_Ctrl_struct();

        CgC_Ctrl_struct(
            uint8_t ChrgCapCtrlSW_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        CgC_Ctrl_struct (CgC_Ctrl_struct&&) = default;
        CgC_Ctrl_struct& operator=(CgC_Ctrl_struct&&) = default;
        CgC_Ctrl_struct& operator=(const CgC_Ctrl_struct&) = default;
        CgC_Ctrl_struct(const CgC_Ctrl_struct&) = default;
        #else
        CgC_Ctrl_struct(CgC_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        CgC_Ctrl_struct& operator=(CgC_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& ChrgCapCtrlSW_Req() OMG_NOEXCEPT {
            return m_ChrgCapCtrlSW_Req_;
        }

        const uint8_t& ChrgCapCtrlSW_Req() const OMG_NOEXCEPT {
            return m_ChrgCapCtrlSW_Req_;
        }

        void ChrgCapCtrlSW_Req(uint8_t value) {
            m_ChrgCapCtrlSW_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const CgC_Ctrl_struct& other_) const;
        bool operator != (const CgC_Ctrl_struct& other_) const;

        void swap(CgC_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_ChrgCapCtrlSW_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(CgC_Ctrl_struct& a, CgC_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CgC_Ctrl_struct& sample);

    class NDDSUSERDllExport CgC_Ctrl_SOA_struct {
      public:
        CgC_Ctrl_SOA_struct();

        explicit CgC_Ctrl_SOA_struct(
            uint8_t CgC_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        CgC_Ctrl_SOA_struct (CgC_Ctrl_SOA_struct&&) = default;
        CgC_Ctrl_SOA_struct& operator=(CgC_Ctrl_SOA_struct&&) = default;
        CgC_Ctrl_SOA_struct& operator=(const CgC_Ctrl_SOA_struct&) = default;
        CgC_Ctrl_SOA_struct(const CgC_Ctrl_SOA_struct&) = default;
        #else
        CgC_Ctrl_SOA_struct(CgC_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        CgC_Ctrl_SOA_struct& operator=(CgC_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& CgC_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_CgC_Ctrl_SOA_u8_;
        }

        const uint8_t& CgC_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_CgC_Ctrl_SOA_u8_;
        }

        void CgC_Ctrl_SOA_u8(uint8_t value) {
            m_CgC_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const CgC_Ctrl_SOA_struct& other_) const;
        bool operator != (const CgC_Ctrl_SOA_struct& other_) const;

        void swap(CgC_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_CgC_Ctrl_SOA_u8_;

    };

    inline void swap(CgC_Ctrl_SOA_struct& a, CgC_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CgC_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport CgC_St_struct {
      public:
        CgC_St_struct();

        CgC_St_struct(
            uint8_t ChrgCap_St,
            uint8_t ChrgCapMv_St,
            uint8_t ChrgCapPst_St,
            uint8_t ChrgCapStpRsn_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        CgC_St_struct (CgC_St_struct&&) = default;
        CgC_St_struct& operator=(CgC_St_struct&&) = default;
        CgC_St_struct& operator=(const CgC_St_struct&) = default;
        CgC_St_struct(const CgC_St_struct&) = default;
        #else
        CgC_St_struct(CgC_St_struct&& other_) OMG_NOEXCEPT;  
        CgC_St_struct& operator=(CgC_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& ChrgCap_St() OMG_NOEXCEPT {
            return m_ChrgCap_St_;
        }

        const uint8_t& ChrgCap_St() const OMG_NOEXCEPT {
            return m_ChrgCap_St_;
        }

        void ChrgCap_St(uint8_t value) {
            m_ChrgCap_St_ = value;
        }

        uint8_t& ChrgCapMv_St() OMG_NOEXCEPT {
            return m_ChrgCapMv_St_;
        }

        const uint8_t& ChrgCapMv_St() const OMG_NOEXCEPT {
            return m_ChrgCapMv_St_;
        }

        void ChrgCapMv_St(uint8_t value) {
            m_ChrgCapMv_St_ = value;
        }

        uint8_t& ChrgCapPst_St() OMG_NOEXCEPT {
            return m_ChrgCapPst_St_;
        }

        const uint8_t& ChrgCapPst_St() const OMG_NOEXCEPT {
            return m_ChrgCapPst_St_;
        }

        void ChrgCapPst_St(uint8_t value) {
            m_ChrgCapPst_St_ = value;
        }

        uint8_t& ChrgCapStpRsn_St() OMG_NOEXCEPT {
            return m_ChrgCapStpRsn_St_;
        }

        const uint8_t& ChrgCapStpRsn_St() const OMG_NOEXCEPT {
            return m_ChrgCapStpRsn_St_;
        }

        void ChrgCapStpRsn_St(uint8_t value) {
            m_ChrgCapStpRsn_St_ = value;
        }

        bool operator == (const CgC_St_struct& other_) const;
        bool operator != (const CgC_St_struct& other_) const;

        void swap(CgC_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_ChrgCap_St_;
        uint8_t m_ChrgCapMv_St_;
        uint8_t m_ChrgCapPst_St_;
        uint8_t m_ChrgCapStpRsn_St_;

    };

    inline void swap(CgC_St_struct& a, CgC_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CgC_St_struct& sample);

    class NDDSUSERDllExport BdCft_Ctrl_struct {
      public:
        BdCft_Ctrl_struct();

        BdCft_Ctrl_struct(
            uint8_t FLLumbSuppUDAdj_Act,
            uint8_t FLLumbSuppFBAdj_Act,
            uint8_t FRLumbSuppUDAdj_Act,
            uint8_t FRLumbSuppFBAdj_Act,
            uint8_t FLSeatShoulderAdj_Act,
            uint8_t FRSeatShoulderAdj_Act,
            uint8_t FLSeatMsg_Act,
            uint8_t FLSeatMsgMode_Act,
            uint8_t FLSeatMsgStrth_Act,
            uint8_t FRSeatMsg_Act,
            uint8_t FRSeatMsgMode_Act,
            uint8_t FRSeatMsgStrth_Act,
            uint8_t FLSeatHt_Act,
            uint8_t FRSeatHt_Act,
            uint8_t SRLSeatHt_Act,
            uint8_t SRRSeatHt_Act,
            uint8_t FLSeatVtlt_Act,
            uint8_t FRSeatVtlt_Act,
            uint8_t SRLSeatVtlt_Act,
            uint8_t SRRSeatVtlt_Act,
            uint8_t SteerHt_Act,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdCft_Ctrl_struct (BdCft_Ctrl_struct&&) = default;
        BdCft_Ctrl_struct& operator=(BdCft_Ctrl_struct&&) = default;
        BdCft_Ctrl_struct& operator=(const BdCft_Ctrl_struct&) = default;
        BdCft_Ctrl_struct(const BdCft_Ctrl_struct&) = default;
        #else
        BdCft_Ctrl_struct(BdCft_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        BdCft_Ctrl_struct& operator=(BdCft_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLLumbSuppUDAdj_Act() OMG_NOEXCEPT {
            return m_FLLumbSuppUDAdj_Act_;
        }

        const uint8_t& FLLumbSuppUDAdj_Act() const OMG_NOEXCEPT {
            return m_FLLumbSuppUDAdj_Act_;
        }

        void FLLumbSuppUDAdj_Act(uint8_t value) {
            m_FLLumbSuppUDAdj_Act_ = value;
        }

        uint8_t& FLLumbSuppFBAdj_Act() OMG_NOEXCEPT {
            return m_FLLumbSuppFBAdj_Act_;
        }

        const uint8_t& FLLumbSuppFBAdj_Act() const OMG_NOEXCEPT {
            return m_FLLumbSuppFBAdj_Act_;
        }

        void FLLumbSuppFBAdj_Act(uint8_t value) {
            m_FLLumbSuppFBAdj_Act_ = value;
        }

        uint8_t& FRLumbSuppUDAdj_Act() OMG_NOEXCEPT {
            return m_FRLumbSuppUDAdj_Act_;
        }

        const uint8_t& FRLumbSuppUDAdj_Act() const OMG_NOEXCEPT {
            return m_FRLumbSuppUDAdj_Act_;
        }

        void FRLumbSuppUDAdj_Act(uint8_t value) {
            m_FRLumbSuppUDAdj_Act_ = value;
        }

        uint8_t& FRLumbSuppFBAdj_Act() OMG_NOEXCEPT {
            return m_FRLumbSuppFBAdj_Act_;
        }

        const uint8_t& FRLumbSuppFBAdj_Act() const OMG_NOEXCEPT {
            return m_FRLumbSuppFBAdj_Act_;
        }

        void FRLumbSuppFBAdj_Act(uint8_t value) {
            m_FRLumbSuppFBAdj_Act_ = value;
        }

        uint8_t& FLSeatShoulderAdj_Act() OMG_NOEXCEPT {
            return m_FLSeatShoulderAdj_Act_;
        }

        const uint8_t& FLSeatShoulderAdj_Act() const OMG_NOEXCEPT {
            return m_FLSeatShoulderAdj_Act_;
        }

        void FLSeatShoulderAdj_Act(uint8_t value) {
            m_FLSeatShoulderAdj_Act_ = value;
        }

        uint8_t& FRSeatShoulderAdj_Act() OMG_NOEXCEPT {
            return m_FRSeatShoulderAdj_Act_;
        }

        const uint8_t& FRSeatShoulderAdj_Act() const OMG_NOEXCEPT {
            return m_FRSeatShoulderAdj_Act_;
        }

        void FRSeatShoulderAdj_Act(uint8_t value) {
            m_FRSeatShoulderAdj_Act_ = value;
        }

        uint8_t& FLSeatMsg_Act() OMG_NOEXCEPT {
            return m_FLSeatMsg_Act_;
        }

        const uint8_t& FLSeatMsg_Act() const OMG_NOEXCEPT {
            return m_FLSeatMsg_Act_;
        }

        void FLSeatMsg_Act(uint8_t value) {
            m_FLSeatMsg_Act_ = value;
        }

        uint8_t& FLSeatMsgMode_Act() OMG_NOEXCEPT {
            return m_FLSeatMsgMode_Act_;
        }

        const uint8_t& FLSeatMsgMode_Act() const OMG_NOEXCEPT {
            return m_FLSeatMsgMode_Act_;
        }

        void FLSeatMsgMode_Act(uint8_t value) {
            m_FLSeatMsgMode_Act_ = value;
        }

        uint8_t& FLSeatMsgStrth_Act() OMG_NOEXCEPT {
            return m_FLSeatMsgStrth_Act_;
        }

        const uint8_t& FLSeatMsgStrth_Act() const OMG_NOEXCEPT {
            return m_FLSeatMsgStrth_Act_;
        }

        void FLSeatMsgStrth_Act(uint8_t value) {
            m_FLSeatMsgStrth_Act_ = value;
        }

        uint8_t& FRSeatMsg_Act() OMG_NOEXCEPT {
            return m_FRSeatMsg_Act_;
        }

        const uint8_t& FRSeatMsg_Act() const OMG_NOEXCEPT {
            return m_FRSeatMsg_Act_;
        }

        void FRSeatMsg_Act(uint8_t value) {
            m_FRSeatMsg_Act_ = value;
        }

        uint8_t& FRSeatMsgMode_Act() OMG_NOEXCEPT {
            return m_FRSeatMsgMode_Act_;
        }

        const uint8_t& FRSeatMsgMode_Act() const OMG_NOEXCEPT {
            return m_FRSeatMsgMode_Act_;
        }

        void FRSeatMsgMode_Act(uint8_t value) {
            m_FRSeatMsgMode_Act_ = value;
        }

        uint8_t& FRSeatMsgStrth_Act() OMG_NOEXCEPT {
            return m_FRSeatMsgStrth_Act_;
        }

        const uint8_t& FRSeatMsgStrth_Act() const OMG_NOEXCEPT {
            return m_FRSeatMsgStrth_Act_;
        }

        void FRSeatMsgStrth_Act(uint8_t value) {
            m_FRSeatMsgStrth_Act_ = value;
        }

        uint8_t& FLSeatHt_Act() OMG_NOEXCEPT {
            return m_FLSeatHt_Act_;
        }

        const uint8_t& FLSeatHt_Act() const OMG_NOEXCEPT {
            return m_FLSeatHt_Act_;
        }

        void FLSeatHt_Act(uint8_t value) {
            m_FLSeatHt_Act_ = value;
        }

        uint8_t& FRSeatHt_Act() OMG_NOEXCEPT {
            return m_FRSeatHt_Act_;
        }

        const uint8_t& FRSeatHt_Act() const OMG_NOEXCEPT {
            return m_FRSeatHt_Act_;
        }

        void FRSeatHt_Act(uint8_t value) {
            m_FRSeatHt_Act_ = value;
        }

        uint8_t& SRLSeatHt_Act() OMG_NOEXCEPT {
            return m_SRLSeatHt_Act_;
        }

        const uint8_t& SRLSeatHt_Act() const OMG_NOEXCEPT {
            return m_SRLSeatHt_Act_;
        }

        void SRLSeatHt_Act(uint8_t value) {
            m_SRLSeatHt_Act_ = value;
        }

        uint8_t& SRRSeatHt_Act() OMG_NOEXCEPT {
            return m_SRRSeatHt_Act_;
        }

        const uint8_t& SRRSeatHt_Act() const OMG_NOEXCEPT {
            return m_SRRSeatHt_Act_;
        }

        void SRRSeatHt_Act(uint8_t value) {
            m_SRRSeatHt_Act_ = value;
        }

        uint8_t& FLSeatVtlt_Act() OMG_NOEXCEPT {
            return m_FLSeatVtlt_Act_;
        }

        const uint8_t& FLSeatVtlt_Act() const OMG_NOEXCEPT {
            return m_FLSeatVtlt_Act_;
        }

        void FLSeatVtlt_Act(uint8_t value) {
            m_FLSeatVtlt_Act_ = value;
        }

        uint8_t& FRSeatVtlt_Act() OMG_NOEXCEPT {
            return m_FRSeatVtlt_Act_;
        }

        const uint8_t& FRSeatVtlt_Act() const OMG_NOEXCEPT {
            return m_FRSeatVtlt_Act_;
        }

        void FRSeatVtlt_Act(uint8_t value) {
            m_FRSeatVtlt_Act_ = value;
        }

        uint8_t& SRLSeatVtlt_Act() OMG_NOEXCEPT {
            return m_SRLSeatVtlt_Act_;
        }

        const uint8_t& SRLSeatVtlt_Act() const OMG_NOEXCEPT {
            return m_SRLSeatVtlt_Act_;
        }

        void SRLSeatVtlt_Act(uint8_t value) {
            m_SRLSeatVtlt_Act_ = value;
        }

        uint8_t& SRRSeatVtlt_Act() OMG_NOEXCEPT {
            return m_SRRSeatVtlt_Act_;
        }

        const uint8_t& SRRSeatVtlt_Act() const OMG_NOEXCEPT {
            return m_SRRSeatVtlt_Act_;
        }

        void SRRSeatVtlt_Act(uint8_t value) {
            m_SRRSeatVtlt_Act_ = value;
        }

        uint8_t& SteerHt_Act() OMG_NOEXCEPT {
            return m_SteerHt_Act_;
        }

        const uint8_t& SteerHt_Act() const OMG_NOEXCEPT {
            return m_SteerHt_Act_;
        }

        void SteerHt_Act(uint8_t value) {
            m_SteerHt_Act_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdCft_Ctrl_struct& other_) const;
        bool operator != (const BdCft_Ctrl_struct& other_) const;

        void swap(BdCft_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLLumbSuppUDAdj_Act_;
        uint8_t m_FLLumbSuppFBAdj_Act_;
        uint8_t m_FRLumbSuppUDAdj_Act_;
        uint8_t m_FRLumbSuppFBAdj_Act_;
        uint8_t m_FLSeatShoulderAdj_Act_;
        uint8_t m_FRSeatShoulderAdj_Act_;
        uint8_t m_FLSeatMsg_Act_;
        uint8_t m_FLSeatMsgMode_Act_;
        uint8_t m_FLSeatMsgStrth_Act_;
        uint8_t m_FRSeatMsg_Act_;
        uint8_t m_FRSeatMsgMode_Act_;
        uint8_t m_FRSeatMsgStrth_Act_;
        uint8_t m_FLSeatHt_Act_;
        uint8_t m_FRSeatHt_Act_;
        uint8_t m_SRLSeatHt_Act_;
        uint8_t m_SRRSeatHt_Act_;
        uint8_t m_FLSeatVtlt_Act_;
        uint8_t m_FRSeatVtlt_Act_;
        uint8_t m_SRLSeatVtlt_Act_;
        uint8_t m_SRRSeatVtlt_Act_;
        uint8_t m_SteerHt_Act_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdCft_Ctrl_struct& a, BdCft_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdCft_Ctrl_struct& sample);

    class NDDSUSERDllExport BdCft_Ctrl_SOA_struct {
      public:
        BdCft_Ctrl_SOA_struct();

        explicit BdCft_Ctrl_SOA_struct(
            uint8_t BdCft_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdCft_Ctrl_SOA_struct (BdCft_Ctrl_SOA_struct&&) = default;
        BdCft_Ctrl_SOA_struct& operator=(BdCft_Ctrl_SOA_struct&&) = default;
        BdCft_Ctrl_SOA_struct& operator=(const BdCft_Ctrl_SOA_struct&) = default;
        BdCft_Ctrl_SOA_struct(const BdCft_Ctrl_SOA_struct&) = default;
        #else
        BdCft_Ctrl_SOA_struct(BdCft_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        BdCft_Ctrl_SOA_struct& operator=(BdCft_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& BdCft_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_BdCft_Ctrl_SOA_u8_;
        }

        const uint8_t& BdCft_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_BdCft_Ctrl_SOA_u8_;
        }

        void BdCft_Ctrl_SOA_u8(uint8_t value) {
            m_BdCft_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const BdCft_Ctrl_SOA_struct& other_) const;
        bool operator != (const BdCft_Ctrl_SOA_struct& other_) const;

        void swap(BdCft_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_BdCft_Ctrl_SOA_u8_;

    };

    inline void swap(BdCft_Ctrl_SOA_struct& a, BdCft_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdCft_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport BdCft_St_Get_struct {
      public:
        BdCft_St_Get_struct();

        BdCft_St_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdCft_St_Get_struct (BdCft_St_Get_struct&&) = default;
        BdCft_St_Get_struct& operator=(BdCft_St_Get_struct&&) = default;
        BdCft_St_Get_struct& operator=(const BdCft_St_Get_struct&) = default;
        BdCft_St_Get_struct(const BdCft_St_Get_struct&) = default;
        #else
        BdCft_St_Get_struct(BdCft_St_Get_struct&& other_) OMG_NOEXCEPT;  
        BdCft_St_Get_struct& operator=(BdCft_St_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdCft_St_Get_struct& other_) const;
        bool operator != (const BdCft_St_Get_struct& other_) const;

        void swap(BdCft_St_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdCft_St_Get_struct& a, BdCft_St_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdCft_St_Get_struct& sample);

    class NDDSUSERDllExport BdCft_St_struct {
      public:
        BdCft_St_struct();

        BdCft_St_struct(
            uint8_t FLLumbSuppFBMv_St,
            uint8_t FLLumbSuppUDMv_St,
            uint8_t FRLumbSuppFBMv_St,
            uint8_t FRLumbSuppUDMv_St,
            uint8_t FLSeatShoulderAdj_St,
            uint8_t FRSeatShoulderAdj_St,
            uint8_t FLSeatMsg_St,
            uint8_t FLSeatMsgMode_St,
            uint8_t FLSeatMsgStrth_St,
            uint8_t FRSeatMsg_St,
            uint8_t FRSeatMsgMode_St,
            uint8_t FRSeatMsgStrth_St,
            uint8_t FLSeatHt_St,
            uint8_t FRSeatHt_St,
            uint8_t SRLSeatHt_St,
            uint8_t SRRSeatHt_St,
            uint8_t FLSeatVtlt_St,
            uint8_t FRSeatVtlt_St,
            uint8_t SRLSeatVtlt_St,
            uint8_t SRRSeatVtlt_St,
            uint8_t SteerHt_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdCft_St_struct (BdCft_St_struct&&) = default;
        BdCft_St_struct& operator=(BdCft_St_struct&&) = default;
        BdCft_St_struct& operator=(const BdCft_St_struct&) = default;
        BdCft_St_struct(const BdCft_St_struct&) = default;
        #else
        BdCft_St_struct(BdCft_St_struct&& other_) OMG_NOEXCEPT;  
        BdCft_St_struct& operator=(BdCft_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& FLLumbSuppFBMv_St() OMG_NOEXCEPT {
            return m_FLLumbSuppFBMv_St_;
        }

        const uint8_t& FLLumbSuppFBMv_St() const OMG_NOEXCEPT {
            return m_FLLumbSuppFBMv_St_;
        }

        void FLLumbSuppFBMv_St(uint8_t value) {
            m_FLLumbSuppFBMv_St_ = value;
        }

        uint8_t& FLLumbSuppUDMv_St() OMG_NOEXCEPT {
            return m_FLLumbSuppUDMv_St_;
        }

        const uint8_t& FLLumbSuppUDMv_St() const OMG_NOEXCEPT {
            return m_FLLumbSuppUDMv_St_;
        }

        void FLLumbSuppUDMv_St(uint8_t value) {
            m_FLLumbSuppUDMv_St_ = value;
        }

        uint8_t& FRLumbSuppFBMv_St() OMG_NOEXCEPT {
            return m_FRLumbSuppFBMv_St_;
        }

        const uint8_t& FRLumbSuppFBMv_St() const OMG_NOEXCEPT {
            return m_FRLumbSuppFBMv_St_;
        }

        void FRLumbSuppFBMv_St(uint8_t value) {
            m_FRLumbSuppFBMv_St_ = value;
        }

        uint8_t& FRLumbSuppUDMv_St() OMG_NOEXCEPT {
            return m_FRLumbSuppUDMv_St_;
        }

        const uint8_t& FRLumbSuppUDMv_St() const OMG_NOEXCEPT {
            return m_FRLumbSuppUDMv_St_;
        }

        void FRLumbSuppUDMv_St(uint8_t value) {
            m_FRLumbSuppUDMv_St_ = value;
        }

        uint8_t& FLSeatShoulderAdj_St() OMG_NOEXCEPT {
            return m_FLSeatShoulderAdj_St_;
        }

        const uint8_t& FLSeatShoulderAdj_St() const OMG_NOEXCEPT {
            return m_FLSeatShoulderAdj_St_;
        }

        void FLSeatShoulderAdj_St(uint8_t value) {
            m_FLSeatShoulderAdj_St_ = value;
        }

        uint8_t& FRSeatShoulderAdj_St() OMG_NOEXCEPT {
            return m_FRSeatShoulderAdj_St_;
        }

        const uint8_t& FRSeatShoulderAdj_St() const OMG_NOEXCEPT {
            return m_FRSeatShoulderAdj_St_;
        }

        void FRSeatShoulderAdj_St(uint8_t value) {
            m_FRSeatShoulderAdj_St_ = value;
        }

        uint8_t& FLSeatMsg_St() OMG_NOEXCEPT {
            return m_FLSeatMsg_St_;
        }

        const uint8_t& FLSeatMsg_St() const OMG_NOEXCEPT {
            return m_FLSeatMsg_St_;
        }

        void FLSeatMsg_St(uint8_t value) {
            m_FLSeatMsg_St_ = value;
        }

        uint8_t& FLSeatMsgMode_St() OMG_NOEXCEPT {
            return m_FLSeatMsgMode_St_;
        }

        const uint8_t& FLSeatMsgMode_St() const OMG_NOEXCEPT {
            return m_FLSeatMsgMode_St_;
        }

        void FLSeatMsgMode_St(uint8_t value) {
            m_FLSeatMsgMode_St_ = value;
        }

        uint8_t& FLSeatMsgStrth_St() OMG_NOEXCEPT {
            return m_FLSeatMsgStrth_St_;
        }

        const uint8_t& FLSeatMsgStrth_St() const OMG_NOEXCEPT {
            return m_FLSeatMsgStrth_St_;
        }

        void FLSeatMsgStrth_St(uint8_t value) {
            m_FLSeatMsgStrth_St_ = value;
        }

        uint8_t& FRSeatMsg_St() OMG_NOEXCEPT {
            return m_FRSeatMsg_St_;
        }

        const uint8_t& FRSeatMsg_St() const OMG_NOEXCEPT {
            return m_FRSeatMsg_St_;
        }

        void FRSeatMsg_St(uint8_t value) {
            m_FRSeatMsg_St_ = value;
        }

        uint8_t& FRSeatMsgMode_St() OMG_NOEXCEPT {
            return m_FRSeatMsgMode_St_;
        }

        const uint8_t& FRSeatMsgMode_St() const OMG_NOEXCEPT {
            return m_FRSeatMsgMode_St_;
        }

        void FRSeatMsgMode_St(uint8_t value) {
            m_FRSeatMsgMode_St_ = value;
        }

        uint8_t& FRSeatMsgStrth_St() OMG_NOEXCEPT {
            return m_FRSeatMsgStrth_St_;
        }

        const uint8_t& FRSeatMsgStrth_St() const OMG_NOEXCEPT {
            return m_FRSeatMsgStrth_St_;
        }

        void FRSeatMsgStrth_St(uint8_t value) {
            m_FRSeatMsgStrth_St_ = value;
        }

        uint8_t& FLSeatHt_St() OMG_NOEXCEPT {
            return m_FLSeatHt_St_;
        }

        const uint8_t& FLSeatHt_St() const OMG_NOEXCEPT {
            return m_FLSeatHt_St_;
        }

        void FLSeatHt_St(uint8_t value) {
            m_FLSeatHt_St_ = value;
        }

        uint8_t& FRSeatHt_St() OMG_NOEXCEPT {
            return m_FRSeatHt_St_;
        }

        const uint8_t& FRSeatHt_St() const OMG_NOEXCEPT {
            return m_FRSeatHt_St_;
        }

        void FRSeatHt_St(uint8_t value) {
            m_FRSeatHt_St_ = value;
        }

        uint8_t& SRLSeatHt_St() OMG_NOEXCEPT {
            return m_SRLSeatHt_St_;
        }

        const uint8_t& SRLSeatHt_St() const OMG_NOEXCEPT {
            return m_SRLSeatHt_St_;
        }

        void SRLSeatHt_St(uint8_t value) {
            m_SRLSeatHt_St_ = value;
        }

        uint8_t& SRRSeatHt_St() OMG_NOEXCEPT {
            return m_SRRSeatHt_St_;
        }

        const uint8_t& SRRSeatHt_St() const OMG_NOEXCEPT {
            return m_SRRSeatHt_St_;
        }

        void SRRSeatHt_St(uint8_t value) {
            m_SRRSeatHt_St_ = value;
        }

        uint8_t& FLSeatVtlt_St() OMG_NOEXCEPT {
            return m_FLSeatVtlt_St_;
        }

        const uint8_t& FLSeatVtlt_St() const OMG_NOEXCEPT {
            return m_FLSeatVtlt_St_;
        }

        void FLSeatVtlt_St(uint8_t value) {
            m_FLSeatVtlt_St_ = value;
        }

        uint8_t& FRSeatVtlt_St() OMG_NOEXCEPT {
            return m_FRSeatVtlt_St_;
        }

        const uint8_t& FRSeatVtlt_St() const OMG_NOEXCEPT {
            return m_FRSeatVtlt_St_;
        }

        void FRSeatVtlt_St(uint8_t value) {
            m_FRSeatVtlt_St_ = value;
        }

        uint8_t& SRLSeatVtlt_St() OMG_NOEXCEPT {
            return m_SRLSeatVtlt_St_;
        }

        const uint8_t& SRLSeatVtlt_St() const OMG_NOEXCEPT {
            return m_SRLSeatVtlt_St_;
        }

        void SRLSeatVtlt_St(uint8_t value) {
            m_SRLSeatVtlt_St_ = value;
        }

        uint8_t& SRRSeatVtlt_St() OMG_NOEXCEPT {
            return m_SRRSeatVtlt_St_;
        }

        const uint8_t& SRRSeatVtlt_St() const OMG_NOEXCEPT {
            return m_SRRSeatVtlt_St_;
        }

        void SRRSeatVtlt_St(uint8_t value) {
            m_SRRSeatVtlt_St_ = value;
        }

        uint8_t& SteerHt_St() OMG_NOEXCEPT {
            return m_SteerHt_St_;
        }

        const uint8_t& SteerHt_St() const OMG_NOEXCEPT {
            return m_SteerHt_St_;
        }

        void SteerHt_St(uint8_t value) {
            m_SteerHt_St_ = value;
        }

        bool operator == (const BdCft_St_struct& other_) const;
        bool operator != (const BdCft_St_struct& other_) const;

        void swap(BdCft_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_FLLumbSuppFBMv_St_;
        uint8_t m_FLLumbSuppUDMv_St_;
        uint8_t m_FRLumbSuppFBMv_St_;
        uint8_t m_FRLumbSuppUDMv_St_;
        uint8_t m_FLSeatShoulderAdj_St_;
        uint8_t m_FRSeatShoulderAdj_St_;
        uint8_t m_FLSeatMsg_St_;
        uint8_t m_FLSeatMsgMode_St_;
        uint8_t m_FLSeatMsgStrth_St_;
        uint8_t m_FRSeatMsg_St_;
        uint8_t m_FRSeatMsgMode_St_;
        uint8_t m_FRSeatMsgStrth_St_;
        uint8_t m_FLSeatHt_St_;
        uint8_t m_FRSeatHt_St_;
        uint8_t m_SRLSeatHt_St_;
        uint8_t m_SRRSeatHt_St_;
        uint8_t m_FLSeatVtlt_St_;
        uint8_t m_FRSeatVtlt_St_;
        uint8_t m_SRLSeatVtlt_St_;
        uint8_t m_SRRSeatVtlt_St_;
        uint8_t m_SteerHt_St_;

    };

    inline void swap(BdCft_St_struct& a, BdCft_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdCft_St_struct& sample);

    class NDDSUSERDllExport BdCft_Set_struct {
      public:
        BdCft_Set_struct();

        BdCft_Set_struct(
            uint8_t SeatAutoHeat_Set,
            uint8_t StreeAutoHeat_Set,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdCft_Set_struct (BdCft_Set_struct&&) = default;
        BdCft_Set_struct& operator=(BdCft_Set_struct&&) = default;
        BdCft_Set_struct& operator=(const BdCft_Set_struct&) = default;
        BdCft_Set_struct(const BdCft_Set_struct&) = default;
        #else
        BdCft_Set_struct(BdCft_Set_struct&& other_) OMG_NOEXCEPT;  
        BdCft_Set_struct& operator=(BdCft_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& SeatAutoHeat_Set() OMG_NOEXCEPT {
            return m_SeatAutoHeat_Set_;
        }

        const uint8_t& SeatAutoHeat_Set() const OMG_NOEXCEPT {
            return m_SeatAutoHeat_Set_;
        }

        void SeatAutoHeat_Set(uint8_t value) {
            m_SeatAutoHeat_Set_ = value;
        }

        uint8_t& StreeAutoHeat_Set() OMG_NOEXCEPT {
            return m_StreeAutoHeat_Set_;
        }

        const uint8_t& StreeAutoHeat_Set() const OMG_NOEXCEPT {
            return m_StreeAutoHeat_Set_;
        }

        void StreeAutoHeat_Set(uint8_t value) {
            m_StreeAutoHeat_Set_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BdCft_Set_struct& other_) const;
        bool operator != (const BdCft_Set_struct& other_) const;

        void swap(BdCft_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_SeatAutoHeat_Set_;
        uint8_t m_StreeAutoHeat_Set_;
        std::string m_CtrlSource_;

    };

    inline void swap(BdCft_Set_struct& a, BdCft_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdCft_Set_struct& sample);

    class NDDSUSERDllExport BdCft_Rsp_struct {
      public:
        BdCft_Rsp_struct();

        BdCft_Rsp_struct(
            uint8_t SeatAutoHeat_Rsp,
            uint8_t StreeAutoHeat_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdCft_Rsp_struct (BdCft_Rsp_struct&&) = default;
        BdCft_Rsp_struct& operator=(BdCft_Rsp_struct&&) = default;
        BdCft_Rsp_struct& operator=(const BdCft_Rsp_struct&) = default;
        BdCft_Rsp_struct(const BdCft_Rsp_struct&) = default;
        #else
        BdCft_Rsp_struct(BdCft_Rsp_struct&& other_) OMG_NOEXCEPT;  
        BdCft_Rsp_struct& operator=(BdCft_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& SeatAutoHeat_Rsp() OMG_NOEXCEPT {
            return m_SeatAutoHeat_Rsp_;
        }

        const uint8_t& SeatAutoHeat_Rsp() const OMG_NOEXCEPT {
            return m_SeatAutoHeat_Rsp_;
        }

        void SeatAutoHeat_Rsp(uint8_t value) {
            m_SeatAutoHeat_Rsp_ = value;
        }

        uint8_t& StreeAutoHeat_Rsp() OMG_NOEXCEPT {
            return m_StreeAutoHeat_Rsp_;
        }

        const uint8_t& StreeAutoHeat_Rsp() const OMG_NOEXCEPT {
            return m_StreeAutoHeat_Rsp_;
        }

        void StreeAutoHeat_Rsp(uint8_t value) {
            m_StreeAutoHeat_Rsp_ = value;
        }

        bool operator == (const BdCft_Rsp_struct& other_) const;
        bool operator != (const BdCft_Rsp_struct& other_) const;

        void swap(BdCft_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_SeatAutoHeat_Rsp_;
        uint8_t m_StreeAutoHeat_Rsp_;

    };

    inline void swap(BdCft_Rsp_struct& a, BdCft_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdCft_Rsp_struct& sample);

    class NDDSUSERDllExport BdCft_Srv_Req_Union {
      public:
        BdCft_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdCft_Srv_Req_Union (BdCft_Srv_Req_Union&&) = default;
        BdCft_Srv_Req_Union& operator=(BdCft_Srv_Req_Union&&) = default;
        BdCft_Srv_Req_Union& operator=(const BdCft_Srv_Req_Union&) = default;
        BdCft_Srv_Req_Union(const BdCft_Srv_Req_Union&) = default;
        #else
        BdCft_Srv_Req_Union(BdCft_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        BdCft_Srv_Req_Union& operator=(BdCft_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::BdCft_Ctrl_struct& BdCft_Ctrl()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Req_Union::BdCft_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_BdCft_Ctrl_;
        }

        const BodyDomain::BdCft_Ctrl_struct& BdCft_Ctrl() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Req_Union::BdCft_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_BdCft_Ctrl_;
        }

        void BdCft_Ctrl(const BodyDomain::BdCft_Ctrl_struct& value) {
            m_u_.m_BdCft_Ctrl_ = value;
            m_d_= 0;
        }

        void BdCft_Ctrl(BodyDomain::BdCft_Ctrl_struct&& value) {
            m_u_.m_BdCft_Ctrl_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::BdCft_St_Get_struct& BdCft_St_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Req_Union::BdCft_St_Get not selected by the discriminator" );
            }
            return m_u_.m_BdCft_St_Get_;
        }

        const BodyDomain::BdCft_St_Get_struct& BdCft_St_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Req_Union::BdCft_St_Get not selected by the discriminator" );
            }
            return m_u_.m_BdCft_St_Get_;
        }

        void BdCft_St_Get(const BodyDomain::BdCft_St_Get_struct& value) {
            m_u_.m_BdCft_St_Get_ = value;
            m_d_= 1;
        }

        void BdCft_St_Get(BodyDomain::BdCft_St_Get_struct&& value) {
            m_u_.m_BdCft_St_Get_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::BdCft_Set_struct& BdCft_Set()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Req_Union::BdCft_Set not selected by the discriminator" );
            }
            return m_u_.m_BdCft_Set_;
        }

        const BodyDomain::BdCft_Set_struct& BdCft_Set() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Req_Union::BdCft_Set not selected by the discriminator" );
            }
            return m_u_.m_BdCft_Set_;
        }

        void BdCft_Set(const BodyDomain::BdCft_Set_struct& value) {
            m_u_.m_BdCft_Set_ = value;
            m_d_= 2;
        }

        void BdCft_Set(BodyDomain::BdCft_Set_struct&& value) {
            m_u_.m_BdCft_Set_ = std::move(value);
            m_d_= 2;
        }

        bool operator == (const BdCft_Srv_Req_Union& other_) const;
        bool operator != (const BdCft_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(BdCft_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::BdCft_Ctrl_struct m_BdCft_Ctrl_;
            BodyDomain::BdCft_St_Get_struct m_BdCft_St_Get_;
            BodyDomain::BdCft_Set_struct m_BdCft_Set_;
            Union_();
            Union_(
                const BodyDomain::BdCft_Ctrl_struct& BdCft_Ctrl,
                const BodyDomain::BdCft_St_Get_struct& BdCft_St_Get,
                const BodyDomain::BdCft_Set_struct& BdCft_Set);
        };
        Union_ m_u_;

    };

    inline void swap(BdCft_Srv_Req_Union& a, BdCft_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdCft_Srv_Req_Union& sample);

    class NDDSUSERDllExport BdCft_Srv_Resp_Union {
      public:
        BdCft_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BdCft_Srv_Resp_Union (BdCft_Srv_Resp_Union&&) = default;
        BdCft_Srv_Resp_Union& operator=(BdCft_Srv_Resp_Union&&) = default;
        BdCft_Srv_Resp_Union& operator=(const BdCft_Srv_Resp_Union&) = default;
        BdCft_Srv_Resp_Union(const BdCft_Srv_Resp_Union&) = default;
        #else
        BdCft_Srv_Resp_Union(BdCft_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        BdCft_Srv_Resp_Union& operator=(BdCft_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::BdCft_Ctrl_SOA_struct& BdCft_Ctrl_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Resp_Union::BdCft_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdCft_Ctrl_SOA_;
        }

        const BodyDomain::BdCft_Ctrl_SOA_struct& BdCft_Ctrl_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Resp_Union::BdCft_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdCft_Ctrl_SOA_;
        }

        void BdCft_Ctrl_SOA(const BodyDomain::BdCft_Ctrl_SOA_struct& value) {
            m_u_.m_BdCft_Ctrl_SOA_ = value;
            m_d_= 0;
        }

        void BdCft_Ctrl_SOA(BodyDomain::BdCft_Ctrl_SOA_struct&& value) {
            m_u_.m_BdCft_Ctrl_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::BdCft_St_struct& BdCft_St_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Resp_Union::BdCft_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdCft_St_Get_SOA_;
        }

        const BodyDomain::BdCft_St_struct& BdCft_St_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Resp_Union::BdCft_St_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdCft_St_Get_SOA_;
        }

        void BdCft_St_Get_SOA(const BodyDomain::BdCft_St_struct& value) {
            m_u_.m_BdCft_St_Get_SOA_ = value;
            m_d_= 1;
        }

        void BdCft_St_Get_SOA(BodyDomain::BdCft_St_struct&& value) {
            m_u_.m_BdCft_St_Get_SOA_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::BdCft_Rsp_struct& BdCft_Set_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Resp_Union::BdCft_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdCft_Set_SOA_;
        }

        const BodyDomain::BdCft_Rsp_struct& BdCft_Set_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::BdCft_Srv_Resp_Union::BdCft_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_BdCft_Set_SOA_;
        }

        void BdCft_Set_SOA(const BodyDomain::BdCft_Rsp_struct& value) {
            m_u_.m_BdCft_Set_SOA_ = value;
            m_d_= 2;
        }

        void BdCft_Set_SOA(BodyDomain::BdCft_Rsp_struct&& value) {
            m_u_.m_BdCft_Set_SOA_ = std::move(value);
            m_d_= 2;
        }

        bool operator == (const BdCft_Srv_Resp_Union& other_) const;
        bool operator != (const BdCft_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(BdCft_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::BdCft_Ctrl_SOA_struct m_BdCft_Ctrl_SOA_;
            BodyDomain::BdCft_St_struct m_BdCft_St_Get_SOA_;
            BodyDomain::BdCft_Rsp_struct m_BdCft_Set_SOA_;
            Union_();
            Union_(
                const BodyDomain::BdCft_Ctrl_SOA_struct& BdCft_Ctrl_SOA,
                const BodyDomain::BdCft_St_struct& BdCft_St_Get_SOA,
                const BodyDomain::BdCft_Rsp_struct& BdCft_Set_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(BdCft_Srv_Resp_Union& a, BdCft_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BdCft_Srv_Resp_Union& sample);

    class NDDSUSERDllExport BotSeatSync_Set_struct {
      public:
        BotSeatSync_Set_struct();

        BotSeatSync_Set_struct(
            uint8_t SeatSync_Set,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BotSeatSync_Set_struct (BotSeatSync_Set_struct&&) = default;
        BotSeatSync_Set_struct& operator=(BotSeatSync_Set_struct&&) = default;
        BotSeatSync_Set_struct& operator=(const BotSeatSync_Set_struct&) = default;
        BotSeatSync_Set_struct(const BotSeatSync_Set_struct&) = default;
        #else
        BotSeatSync_Set_struct(BotSeatSync_Set_struct&& other_) OMG_NOEXCEPT;  
        BotSeatSync_Set_struct& operator=(BotSeatSync_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& SeatSync_Set() OMG_NOEXCEPT {
            return m_SeatSync_Set_;
        }

        const uint8_t& SeatSync_Set() const OMG_NOEXCEPT {
            return m_SeatSync_Set_;
        }

        void SeatSync_Set(uint8_t value) {
            m_SeatSync_Set_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BotSeatSync_Set_struct& other_) const;
        bool operator != (const BotSeatSync_Set_struct& other_) const;

        void swap(BotSeatSync_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_SeatSync_Set_;
        std::string m_CtrlSource_;

    };

    inline void swap(BotSeatSync_Set_struct& a, BotSeatSync_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BotSeatSync_Set_struct& sample);

    class NDDSUSERDllExport BotSeatSync_Get_struct {
      public:
        BotSeatSync_Get_struct();

        BotSeatSync_Get_struct(
            uint8_t constant,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BotSeatSync_Get_struct (BotSeatSync_Get_struct&&) = default;
        BotSeatSync_Get_struct& operator=(BotSeatSync_Get_struct&&) = default;
        BotSeatSync_Get_struct& operator=(const BotSeatSync_Get_struct&) = default;
        BotSeatSync_Get_struct(const BotSeatSync_Get_struct&) = default;
        #else
        BotSeatSync_Get_struct(BotSeatSync_Get_struct&& other_) OMG_NOEXCEPT;  
        BotSeatSync_Get_struct& operator=(BotSeatSync_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& constant() OMG_NOEXCEPT {
            return m_constant_;
        }

        const uint8_t& constant() const OMG_NOEXCEPT {
            return m_constant_;
        }

        void constant(uint8_t value) {
            m_constant_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BotSeatSync_Get_struct& other_) const;
        bool operator != (const BotSeatSync_Get_struct& other_) const;

        void swap(BotSeatSync_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_constant_;
        std::string m_CtrlSource_;

    };

    inline void swap(BotSeatSync_Get_struct& a, BotSeatSync_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BotSeatSync_Get_struct& sample);

    class NDDSUSERDllExport BotSeatSync_Rsp_struct {
      public:
        BotSeatSync_Rsp_struct();

        explicit BotSeatSync_Rsp_struct(
            uint8_t SeatSync_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BotSeatSync_Rsp_struct (BotSeatSync_Rsp_struct&&) = default;
        BotSeatSync_Rsp_struct& operator=(BotSeatSync_Rsp_struct&&) = default;
        BotSeatSync_Rsp_struct& operator=(const BotSeatSync_Rsp_struct&) = default;
        BotSeatSync_Rsp_struct(const BotSeatSync_Rsp_struct&) = default;
        #else
        BotSeatSync_Rsp_struct(BotSeatSync_Rsp_struct&& other_) OMG_NOEXCEPT;  
        BotSeatSync_Rsp_struct& operator=(BotSeatSync_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& SeatSync_Rsp() OMG_NOEXCEPT {
            return m_SeatSync_Rsp_;
        }

        const uint8_t& SeatSync_Rsp() const OMG_NOEXCEPT {
            return m_SeatSync_Rsp_;
        }

        void SeatSync_Rsp(uint8_t value) {
            m_SeatSync_Rsp_ = value;
        }

        bool operator == (const BotSeatSync_Rsp_struct& other_) const;
        bool operator != (const BotSeatSync_Rsp_struct& other_) const;

        void swap(BotSeatSync_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_SeatSync_Rsp_;

    };

    inline void swap(BotSeatSync_Rsp_struct& a, BotSeatSync_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BotSeatSync_Rsp_struct& sample);

    class NDDSUSERDllExport TargetPointSubstruct {
      public:
        TargetPointSubstruct();

        TargetPointSubstruct(
            uint8_t TargetPoint_Num,
            uint16_t MovePosition_Rz,
            uint16_t TargetPointTime_Increase);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        TargetPointSubstruct (TargetPointSubstruct&&) = default;
        TargetPointSubstruct& operator=(TargetPointSubstruct&&) = default;
        TargetPointSubstruct& operator=(const TargetPointSubstruct&) = default;
        TargetPointSubstruct(const TargetPointSubstruct&) = default;
        #else
        TargetPointSubstruct(TargetPointSubstruct&& other_) OMG_NOEXCEPT;  
        TargetPointSubstruct& operator=(TargetPointSubstruct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& TargetPoint_Num() OMG_NOEXCEPT {
            return m_TargetPoint_Num_;
        }

        const uint8_t& TargetPoint_Num() const OMG_NOEXCEPT {
            return m_TargetPoint_Num_;
        }

        void TargetPoint_Num(uint8_t value) {
            m_TargetPoint_Num_ = value;
        }

        uint16_t& MovePosition_Rz() OMG_NOEXCEPT {
            return m_MovePosition_Rz_;
        }

        const uint16_t& MovePosition_Rz() const OMG_NOEXCEPT {
            return m_MovePosition_Rz_;
        }

        void MovePosition_Rz(uint16_t value) {
            m_MovePosition_Rz_ = value;
        }

        uint16_t& TargetPointTime_Increase() OMG_NOEXCEPT {
            return m_TargetPointTime_Increase_;
        }

        const uint16_t& TargetPointTime_Increase() const OMG_NOEXCEPT {
            return m_TargetPointTime_Increase_;
        }

        void TargetPointTime_Increase(uint16_t value) {
            m_TargetPointTime_Increase_ = value;
        }

        bool operator == (const TargetPointSubstruct& other_) const;
        bool operator != (const TargetPointSubstruct& other_) const;

        void swap(TargetPointSubstruct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_TargetPoint_Num_;
        uint16_t m_MovePosition_Rz_;
        uint16_t m_TargetPointTime_Increase_;

    };

    inline void swap(TargetPointSubstruct& a, TargetPointSubstruct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TargetPointSubstruct& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< BodyDomain::TargetPointSubstruct >;
    template class NDDSUSERDllExport std::vector< BodyDomain::TargetPointSubstruct >;
    #endif
    class NDDSUSERDllExport BotScript_Ctrl_struct {
      public:
        BotScript_Ctrl_struct();

        BotScript_Ctrl_struct(
            uint8_t ScriptID,
            uint8_t MotionScript,
            const ::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L >& TargetPointSequence);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BotScript_Ctrl_struct (BotScript_Ctrl_struct&&) = default;
        BotScript_Ctrl_struct& operator=(BotScript_Ctrl_struct&&) = default;
        BotScript_Ctrl_struct& operator=(const BotScript_Ctrl_struct&) = default;
        BotScript_Ctrl_struct(const BotScript_Ctrl_struct&) = default;
        #else
        BotScript_Ctrl_struct(BotScript_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        BotScript_Ctrl_struct& operator=(BotScript_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& ScriptID() OMG_NOEXCEPT {
            return m_ScriptID_;
        }

        const uint8_t& ScriptID() const OMG_NOEXCEPT {
            return m_ScriptID_;
        }

        void ScriptID(uint8_t value) {
            m_ScriptID_ = value;
        }

        uint8_t& MotionScript() OMG_NOEXCEPT {
            return m_MotionScript_;
        }

        const uint8_t& MotionScript() const OMG_NOEXCEPT {
            return m_MotionScript_;
        }

        void MotionScript(uint8_t value) {
            m_MotionScript_ = value;
        }

        ::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L >& TargetPointSequence() OMG_NOEXCEPT {
            return m_TargetPointSequence_;
        }

        const ::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L >& TargetPointSequence() const OMG_NOEXCEPT {
            return m_TargetPointSequence_;
        }

        void TargetPointSequence(const ::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L >& value) {
            m_TargetPointSequence_ = value;
        }

        void TargetPointSequence(::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L >&& value) {
            m_TargetPointSequence_ = std::move(value);
        }

        bool operator == (const BotScript_Ctrl_struct& other_) const;
        bool operator != (const BotScript_Ctrl_struct& other_) const;

        void swap(BotScript_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_ScriptID_;
        uint8_t m_MotionScript_;
        ::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L > m_TargetPointSequence_;

    };

    inline void swap(BotScript_Ctrl_struct& a, BotScript_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BotScript_Ctrl_struct& sample);

    class NDDSUSERDllExport BotScript_St_struct {
      public:
        BotScript_St_struct();

        explicit BotScript_St_struct(
            uint8_t TransScript_st);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BotScript_St_struct (BotScript_St_struct&&) = default;
        BotScript_St_struct& operator=(BotScript_St_struct&&) = default;
        BotScript_St_struct& operator=(const BotScript_St_struct&) = default;
        BotScript_St_struct(const BotScript_St_struct&) = default;
        #else
        BotScript_St_struct(BotScript_St_struct&& other_) OMG_NOEXCEPT;  
        BotScript_St_struct& operator=(BotScript_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& TransScript_st() OMG_NOEXCEPT {
            return m_TransScript_st_;
        }

        const uint8_t& TransScript_st() const OMG_NOEXCEPT {
            return m_TransScript_st_;
        }

        void TransScript_st(uint8_t value) {
            m_TransScript_st_ = value;
        }

        bool operator == (const BotScript_St_struct& other_) const;
        bool operator != (const BotScript_St_struct& other_) const;

        void swap(BotScript_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_TransScript_st_;

    };

    inline void swap(BotScript_St_struct& a, BotScript_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BotScript_St_struct& sample);

    class NDDSUSERDllExport BotMotion_Ctrl_struct {
      public:
        BotMotion_Ctrl_struct();

        BotMotion_Ctrl_struct(
            uint8_t RelCallMotionScript_Ctrl,
            uint8_t AbsCallMotionScript_Ctrl,
            uint8_t JogRight_Ctrl,
            uint8_t JogLeft_Ctrl,
            uint8_t ComfortPosition_Ctrl,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BotMotion_Ctrl_struct (BotMotion_Ctrl_struct&&) = default;
        BotMotion_Ctrl_struct& operator=(BotMotion_Ctrl_struct&&) = default;
        BotMotion_Ctrl_struct& operator=(const BotMotion_Ctrl_struct&) = default;
        BotMotion_Ctrl_struct(const BotMotion_Ctrl_struct&) = default;
        #else
        BotMotion_Ctrl_struct(BotMotion_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        BotMotion_Ctrl_struct& operator=(BotMotion_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& RelCallMotionScript_Ctrl() OMG_NOEXCEPT {
            return m_RelCallMotionScript_Ctrl_;
        }

        const uint8_t& RelCallMotionScript_Ctrl() const OMG_NOEXCEPT {
            return m_RelCallMotionScript_Ctrl_;
        }

        void RelCallMotionScript_Ctrl(uint8_t value) {
            m_RelCallMotionScript_Ctrl_ = value;
        }

        uint8_t& AbsCallMotionScript_Ctrl() OMG_NOEXCEPT {
            return m_AbsCallMotionScript_Ctrl_;
        }

        const uint8_t& AbsCallMotionScript_Ctrl() const OMG_NOEXCEPT {
            return m_AbsCallMotionScript_Ctrl_;
        }

        void AbsCallMotionScript_Ctrl(uint8_t value) {
            m_AbsCallMotionScript_Ctrl_ = value;
        }

        uint8_t& JogRight_Ctrl() OMG_NOEXCEPT {
            return m_JogRight_Ctrl_;
        }

        const uint8_t& JogRight_Ctrl() const OMG_NOEXCEPT {
            return m_JogRight_Ctrl_;
        }

        void JogRight_Ctrl(uint8_t value) {
            m_JogRight_Ctrl_ = value;
        }

        uint8_t& JogLeft_Ctrl() OMG_NOEXCEPT {
            return m_JogLeft_Ctrl_;
        }

        const uint8_t& JogLeft_Ctrl() const OMG_NOEXCEPT {
            return m_JogLeft_Ctrl_;
        }

        void JogLeft_Ctrl(uint8_t value) {
            m_JogLeft_Ctrl_ = value;
        }

        uint8_t& ComfortPosition_Ctrl() OMG_NOEXCEPT {
            return m_ComfortPosition_Ctrl_;
        }

        const uint8_t& ComfortPosition_Ctrl() const OMG_NOEXCEPT {
            return m_ComfortPosition_Ctrl_;
        }

        void ComfortPosition_Ctrl(uint8_t value) {
            m_ComfortPosition_Ctrl_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const BotMotion_Ctrl_struct& other_) const;
        bool operator != (const BotMotion_Ctrl_struct& other_) const;

        void swap(BotMotion_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_RelCallMotionScript_Ctrl_;
        uint8_t m_AbsCallMotionScript_Ctrl_;
        uint8_t m_JogRight_Ctrl_;
        uint8_t m_JogLeft_Ctrl_;
        uint8_t m_ComfortPosition_Ctrl_;
        std::string m_CtrlSource_;

    };

    inline void swap(BotMotion_Ctrl_struct& a, BotMotion_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BotMotion_Ctrl_struct& sample);

    class NDDSUSERDllExport BotMotion_Ctrl_SOA_struct {
      public:
        BotMotion_Ctrl_SOA_struct();

        explicit BotMotion_Ctrl_SOA_struct(
            uint8_t BotMotion_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BotMotion_Ctrl_SOA_struct (BotMotion_Ctrl_SOA_struct&&) = default;
        BotMotion_Ctrl_SOA_struct& operator=(BotMotion_Ctrl_SOA_struct&&) = default;
        BotMotion_Ctrl_SOA_struct& operator=(const BotMotion_Ctrl_SOA_struct&) = default;
        BotMotion_Ctrl_SOA_struct(const BotMotion_Ctrl_SOA_struct&) = default;
        #else
        BotMotion_Ctrl_SOA_struct(BotMotion_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        BotMotion_Ctrl_SOA_struct& operator=(BotMotion_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& BotMotion_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_BotMotion_Ctrl_SOA_u8_;
        }

        const uint8_t& BotMotion_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_BotMotion_Ctrl_SOA_u8_;
        }

        void BotMotion_Ctrl_SOA_u8(uint8_t value) {
            m_BotMotion_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const BotMotion_Ctrl_SOA_struct& other_) const;
        bool operator != (const BotMotion_Ctrl_SOA_struct& other_) const;

        void swap(BotMotion_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_BotMotion_Ctrl_SOA_u8_;

    };

    inline void swap(BotMotion_Ctrl_SOA_struct& a, BotMotion_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BotMotion_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport BotMotion_St_struct {
      public:
        BotMotion_St_struct();

        BotMotion_St_struct(
            uint8_t Main_St,
            uint8_t Sub_St,
            uint8_t RotationAngle_Z_St,
            uint8_t MotionCommand_St,
            uint8_t ComfortPosition_St,
            uint8_t ScriptExeFinish_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BotMotion_St_struct (BotMotion_St_struct&&) = default;
        BotMotion_St_struct& operator=(BotMotion_St_struct&&) = default;
        BotMotion_St_struct& operator=(const BotMotion_St_struct&) = default;
        BotMotion_St_struct(const BotMotion_St_struct&) = default;
        #else
        BotMotion_St_struct(BotMotion_St_struct&& other_) OMG_NOEXCEPT;  
        BotMotion_St_struct& operator=(BotMotion_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& Main_St() OMG_NOEXCEPT {
            return m_Main_St_;
        }

        const uint8_t& Main_St() const OMG_NOEXCEPT {
            return m_Main_St_;
        }

        void Main_St(uint8_t value) {
            m_Main_St_ = value;
        }

        uint8_t& Sub_St() OMG_NOEXCEPT {
            return m_Sub_St_;
        }

        const uint8_t& Sub_St() const OMG_NOEXCEPT {
            return m_Sub_St_;
        }

        void Sub_St(uint8_t value) {
            m_Sub_St_ = value;
        }

        uint8_t& RotationAngle_Z_St() OMG_NOEXCEPT {
            return m_RotationAngle_Z_St_;
        }

        const uint8_t& RotationAngle_Z_St() const OMG_NOEXCEPT {
            return m_RotationAngle_Z_St_;
        }

        void RotationAngle_Z_St(uint8_t value) {
            m_RotationAngle_Z_St_ = value;
        }

        uint8_t& MotionCommand_St() OMG_NOEXCEPT {
            return m_MotionCommand_St_;
        }

        const uint8_t& MotionCommand_St() const OMG_NOEXCEPT {
            return m_MotionCommand_St_;
        }

        void MotionCommand_St(uint8_t value) {
            m_MotionCommand_St_ = value;
        }

        uint8_t& ComfortPosition_St() OMG_NOEXCEPT {
            return m_ComfortPosition_St_;
        }

        const uint8_t& ComfortPosition_St() const OMG_NOEXCEPT {
            return m_ComfortPosition_St_;
        }

        void ComfortPosition_St(uint8_t value) {
            m_ComfortPosition_St_ = value;
        }

        uint8_t& ScriptExeFinish_Rsp() OMG_NOEXCEPT {
            return m_ScriptExeFinish_Rsp_;
        }

        const uint8_t& ScriptExeFinish_Rsp() const OMG_NOEXCEPT {
            return m_ScriptExeFinish_Rsp_;
        }

        void ScriptExeFinish_Rsp(uint8_t value) {
            m_ScriptExeFinish_Rsp_ = value;
        }

        bool operator == (const BotMotion_St_struct& other_) const;
        bool operator != (const BotMotion_St_struct& other_) const;

        void swap(BotMotion_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_Main_St_;
        uint8_t m_Sub_St_;
        uint8_t m_RotationAngle_Z_St_;
        uint8_t m_MotionCommand_St_;
        uint8_t m_ComfortPosition_St_;
        uint8_t m_ScriptExeFinish_Rsp_;

    };

    inline void swap(BotMotion_St_struct& a, BotMotion_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BotMotion_St_struct& sample);

    class NDDSUSERDllExport Bot_Srv_Req_Union {
      public:
        Bot_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Bot_Srv_Req_Union (Bot_Srv_Req_Union&&) = default;
        Bot_Srv_Req_Union& operator=(Bot_Srv_Req_Union&&) = default;
        Bot_Srv_Req_Union& operator=(const Bot_Srv_Req_Union&) = default;
        Bot_Srv_Req_Union(const Bot_Srv_Req_Union&) = default;
        #else
        Bot_Srv_Req_Union(Bot_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        Bot_Srv_Req_Union& operator=(Bot_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::BotSeatSync_Set_struct& BotSeatSync_Set()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Req_Union::BotSeatSync_Set not selected by the discriminator" );
            }
            return m_u_.m_BotSeatSync_Set_;
        }

        const BodyDomain::BotSeatSync_Set_struct& BotSeatSync_Set() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Req_Union::BotSeatSync_Set not selected by the discriminator" );
            }
            return m_u_.m_BotSeatSync_Set_;
        }

        void BotSeatSync_Set(const BodyDomain::BotSeatSync_Set_struct& value) {
            m_u_.m_BotSeatSync_Set_ = value;
            m_d_= 0;
        }

        void BotSeatSync_Set(BodyDomain::BotSeatSync_Set_struct&& value) {
            m_u_.m_BotSeatSync_Set_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::BotSeatSync_Get_struct& BotSeatSync_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Req_Union::BotSeatSync_Get not selected by the discriminator" );
            }
            return m_u_.m_BotSeatSync_Get_;
        }

        const BodyDomain::BotSeatSync_Get_struct& BotSeatSync_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Req_Union::BotSeatSync_Get not selected by the discriminator" );
            }
            return m_u_.m_BotSeatSync_Get_;
        }

        void BotSeatSync_Get(const BodyDomain::BotSeatSync_Get_struct& value) {
            m_u_.m_BotSeatSync_Get_ = value;
            m_d_= 1;
        }

        void BotSeatSync_Get(BodyDomain::BotSeatSync_Get_struct&& value) {
            m_u_.m_BotSeatSync_Get_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::BotMotion_Ctrl_struct& BotMotion_Ctrl()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Req_Union::BotMotion_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_BotMotion_Ctrl_;
        }

        const BodyDomain::BotMotion_Ctrl_struct& BotMotion_Ctrl() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Req_Union::BotMotion_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_BotMotion_Ctrl_;
        }

        void BotMotion_Ctrl(const BodyDomain::BotMotion_Ctrl_struct& value) {
            m_u_.m_BotMotion_Ctrl_ = value;
            m_d_= 2;
        }

        void BotMotion_Ctrl(BodyDomain::BotMotion_Ctrl_struct&& value) {
            m_u_.m_BotMotion_Ctrl_ = std::move(value);
            m_d_= 2;
        }

        bool operator == (const Bot_Srv_Req_Union& other_) const;
        bool operator != (const Bot_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(Bot_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::BotSeatSync_Set_struct m_BotSeatSync_Set_;
            BodyDomain::BotSeatSync_Get_struct m_BotSeatSync_Get_;
            BodyDomain::BotMotion_Ctrl_struct m_BotMotion_Ctrl_;
            Union_();
            Union_(
                const BodyDomain::BotSeatSync_Set_struct& BotSeatSync_Set,
                const BodyDomain::BotSeatSync_Get_struct& BotSeatSync_Get,
                const BodyDomain::BotMotion_Ctrl_struct& BotMotion_Ctrl);
        };
        Union_ m_u_;

    };

    inline void swap(Bot_Srv_Req_Union& a, Bot_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Bot_Srv_Req_Union& sample);

    class NDDSUSERDllExport Bot_Srv_Resp_Union {
      public:
        Bot_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Bot_Srv_Resp_Union (Bot_Srv_Resp_Union&&) = default;
        Bot_Srv_Resp_Union& operator=(Bot_Srv_Resp_Union&&) = default;
        Bot_Srv_Resp_Union& operator=(const Bot_Srv_Resp_Union&) = default;
        Bot_Srv_Resp_Union(const Bot_Srv_Resp_Union&) = default;
        #else
        Bot_Srv_Resp_Union(Bot_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        Bot_Srv_Resp_Union& operator=(Bot_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::BotSeatSync_Rsp_struct& BotSeatSync_Set_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Resp_Union::BotSeatSync_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_BotSeatSync_Set_SOA_;
        }

        const BodyDomain::BotSeatSync_Rsp_struct& BotSeatSync_Set_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Resp_Union::BotSeatSync_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_BotSeatSync_Set_SOA_;
        }

        void BotSeatSync_Set_SOA(const BodyDomain::BotSeatSync_Rsp_struct& value) {
            m_u_.m_BotSeatSync_Set_SOA_ = value;
            m_d_= 0;
        }

        void BotSeatSync_Set_SOA(BodyDomain::BotSeatSync_Rsp_struct&& value) {
            m_u_.m_BotSeatSync_Set_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::BotSeatSync_Rsp_struct& BotSeatSync_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Resp_Union::BotSeatSync_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BotSeatSync_Get_SOA_;
        }

        const BodyDomain::BotSeatSync_Rsp_struct& BotSeatSync_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Resp_Union::BotSeatSync_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_BotSeatSync_Get_SOA_;
        }

        void BotSeatSync_Get_SOA(const BodyDomain::BotSeatSync_Rsp_struct& value) {
            m_u_.m_BotSeatSync_Get_SOA_ = value;
            m_d_= 1;
        }

        void BotSeatSync_Get_SOA(BodyDomain::BotSeatSync_Rsp_struct&& value) {
            m_u_.m_BotSeatSync_Get_SOA_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::BotMotion_Ctrl_SOA_struct& BotMotion_Ctrl_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Resp_Union::BotMotion_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_BotMotion_Ctrl_SOA_;
        }

        const BodyDomain::BotMotion_Ctrl_SOA_struct& BotMotion_Ctrl_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Bot_Srv_Resp_Union::BotMotion_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_BotMotion_Ctrl_SOA_;
        }

        void BotMotion_Ctrl_SOA(const BodyDomain::BotMotion_Ctrl_SOA_struct& value) {
            m_u_.m_BotMotion_Ctrl_SOA_ = value;
            m_d_= 2;
        }

        void BotMotion_Ctrl_SOA(BodyDomain::BotMotion_Ctrl_SOA_struct&& value) {
            m_u_.m_BotMotion_Ctrl_SOA_ = std::move(value);
            m_d_= 2;
        }

        bool operator == (const Bot_Srv_Resp_Union& other_) const;
        bool operator != (const Bot_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(Bot_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::BotSeatSync_Rsp_struct m_BotSeatSync_Set_SOA_;
            BodyDomain::BotSeatSync_Rsp_struct m_BotSeatSync_Get_SOA_;
            BodyDomain::BotMotion_Ctrl_SOA_struct m_BotMotion_Ctrl_SOA_;
            Union_();
            Union_(
                const BodyDomain::BotSeatSync_Rsp_struct& BotSeatSync_Set_SOA,
                const BodyDomain::BotSeatSync_Rsp_struct& BotSeatSync_Get_SOA,
                const BodyDomain::BotMotion_Ctrl_SOA_struct& BotMotion_Ctrl_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(Bot_Srv_Resp_Union& a, Bot_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Bot_Srv_Resp_Union& sample);

    class NDDSUSERDllExport DKLst_Get_struct {
      public:
        DKLst_Get_struct();

        DKLst_Get_struct(
            uint8_t DKLst_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DKLst_Get_struct (DKLst_Get_struct&&) = default;
        DKLst_Get_struct& operator=(DKLst_Get_struct&&) = default;
        DKLst_Get_struct& operator=(const DKLst_Get_struct&) = default;
        DKLst_Get_struct(const DKLst_Get_struct&) = default;
        #else
        DKLst_Get_struct(DKLst_Get_struct&& other_) OMG_NOEXCEPT;  
        DKLst_Get_struct& operator=(DKLst_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& DKLst_Req() OMG_NOEXCEPT {
            return m_DKLst_Req_;
        }

        const uint8_t& DKLst_Req() const OMG_NOEXCEPT {
            return m_DKLst_Req_;
        }

        void DKLst_Req(uint8_t value) {
            m_DKLst_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const DKLst_Get_struct& other_) const;
        bool operator != (const DKLst_Get_struct& other_) const;

        void swap(DKLst_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_DKLst_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(DKLst_Get_struct& a, DKLst_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DKLst_Get_struct& sample);

    class NDDSUSERDllExport DigitalKeyIDArray {
      public:
        DigitalKeyIDArray();

        explicit DigitalKeyIDArray(
            const ::dds::core::array< uint8_t, 16L>& DigitalKeyID);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DigitalKeyIDArray (DigitalKeyIDArray&&) = default;
        DigitalKeyIDArray& operator=(DigitalKeyIDArray&&) = default;
        DigitalKeyIDArray& operator=(const DigitalKeyIDArray&) = default;
        DigitalKeyIDArray(const DigitalKeyIDArray&) = default;
        #else
        DigitalKeyIDArray(DigitalKeyIDArray&& other_) OMG_NOEXCEPT;  
        DigitalKeyIDArray& operator=(DigitalKeyIDArray&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::dds::core::array< uint8_t, 16L>& DigitalKeyID() OMG_NOEXCEPT {
            return m_DigitalKeyID_;
        }

        const ::dds::core::array< uint8_t, 16L>& DigitalKeyID() const OMG_NOEXCEPT {
            return m_DigitalKeyID_;
        }

        void DigitalKeyID(const ::dds::core::array< uint8_t, 16L>& value) {
            m_DigitalKeyID_ = value;
        }

        void DigitalKeyID(::dds::core::array< uint8_t, 16L>&& value) {
            m_DigitalKeyID_ = std::move(value);
        }

        bool operator == (const DigitalKeyIDArray& other_) const;
        bool operator != (const DigitalKeyIDArray& other_) const;

        void swap(DigitalKeyIDArray& other_) OMG_NOEXCEPT ;

      private:

        ::dds::core::array< uint8_t, 16L> m_DigitalKeyID_;

    };

    inline void swap(DigitalKeyIDArray& a, DigitalKeyIDArray& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DigitalKeyIDArray& sample);

    class NDDSUSERDllExport DKLstSubstruct {
      public:
        DKLstSubstruct();

        DKLstSubstruct(
            const BodyDomain::DigitalKeyIDArray& DigitalKeyID,
            uint8_t DigitalKey_St,
            const std::string& DigitalKeyName,
            uint8_t DigitalKeyAuth_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DKLstSubstruct (DKLstSubstruct&&) = default;
        DKLstSubstruct& operator=(DKLstSubstruct&&) = default;
        DKLstSubstruct& operator=(const DKLstSubstruct&) = default;
        DKLstSubstruct(const DKLstSubstruct&) = default;
        #else
        DKLstSubstruct(DKLstSubstruct&& other_) OMG_NOEXCEPT;  
        DKLstSubstruct& operator=(DKLstSubstruct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        BodyDomain::DigitalKeyIDArray& DigitalKeyID() OMG_NOEXCEPT {
            return m_DigitalKeyID_;
        }

        const BodyDomain::DigitalKeyIDArray& DigitalKeyID() const OMG_NOEXCEPT {
            return m_DigitalKeyID_;
        }

        void DigitalKeyID(const BodyDomain::DigitalKeyIDArray& value) {
            m_DigitalKeyID_ = value;
        }

        void DigitalKeyID(BodyDomain::DigitalKeyIDArray&& value) {
            m_DigitalKeyID_ = std::move(value);
        }
        uint8_t& DigitalKey_St() OMG_NOEXCEPT {
            return m_DigitalKey_St_;
        }

        const uint8_t& DigitalKey_St() const OMG_NOEXCEPT {
            return m_DigitalKey_St_;
        }

        void DigitalKey_St(uint8_t value) {
            m_DigitalKey_St_ = value;
        }

        std::string& DigitalKeyName() OMG_NOEXCEPT {
            return m_DigitalKeyName_;
        }

        const std::string& DigitalKeyName() const OMG_NOEXCEPT {
            return m_DigitalKeyName_;
        }

        void DigitalKeyName(const std::string& value) {
            m_DigitalKeyName_ = value;
        }

        void DigitalKeyName(std::string&& value) {
            m_DigitalKeyName_ = std::move(value);
        }
        uint8_t& DigitalKeyAuth_St() OMG_NOEXCEPT {
            return m_DigitalKeyAuth_St_;
        }

        const uint8_t& DigitalKeyAuth_St() const OMG_NOEXCEPT {
            return m_DigitalKeyAuth_St_;
        }

        void DigitalKeyAuth_St(uint8_t value) {
            m_DigitalKeyAuth_St_ = value;
        }

        bool operator == (const DKLstSubstruct& other_) const;
        bool operator != (const DKLstSubstruct& other_) const;

        void swap(DKLstSubstruct& other_) OMG_NOEXCEPT ;

      private:

        BodyDomain::DigitalKeyIDArray m_DigitalKeyID_;
        uint8_t m_DigitalKey_St_;
        std::string m_DigitalKeyName_;
        uint8_t m_DigitalKeyAuth_St_;

    };

    inline void swap(DKLstSubstruct& a, DKLstSubstruct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DKLstSubstruct& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< BodyDomain::DKLstSubstruct >;
    template class NDDSUSERDllExport std::vector< BodyDomain::DKLstSubstruct >;
    #endif
    class NDDSUSERDllExport DKLst_Rsp_array {
      public:
        DKLst_Rsp_array();

        explicit DKLst_Rsp_array(
            const ::rti::core::bounded_sequence< BodyDomain::DKLstSubstruct, 16L >& DKLst);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DKLst_Rsp_array (DKLst_Rsp_array&&) = default;
        DKLst_Rsp_array& operator=(DKLst_Rsp_array&&) = default;
        DKLst_Rsp_array& operator=(const DKLst_Rsp_array&) = default;
        DKLst_Rsp_array(const DKLst_Rsp_array&) = default;
        #else
        DKLst_Rsp_array(DKLst_Rsp_array&& other_) OMG_NOEXCEPT;  
        DKLst_Rsp_array& operator=(DKLst_Rsp_array&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< BodyDomain::DKLstSubstruct, 16L >& DKLst() OMG_NOEXCEPT {
            return m_DKLst_;
        }

        const ::rti::core::bounded_sequence< BodyDomain::DKLstSubstruct, 16L >& DKLst() const OMG_NOEXCEPT {
            return m_DKLst_;
        }

        void DKLst(const ::rti::core::bounded_sequence< BodyDomain::DKLstSubstruct, 16L >& value) {
            m_DKLst_ = value;
        }

        void DKLst(::rti::core::bounded_sequence< BodyDomain::DKLstSubstruct, 16L >&& value) {
            m_DKLst_ = std::move(value);
        }

        bool operator == (const DKLst_Rsp_array& other_) const;
        bool operator != (const DKLst_Rsp_array& other_) const;

        void swap(DKLst_Rsp_array& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< BodyDomain::DKLstSubstruct, 16L > m_DKLst_;

    };

    inline void swap(DKLst_Rsp_array& a, DKLst_Rsp_array& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DKLst_Rsp_array& sample);

    class NDDSUSERDllExport NFCKeyLst_Get_struct {
      public:
        NFCKeyLst_Get_struct();

        NFCKeyLst_Get_struct(
            uint8_t NFCKeyLst_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NFCKeyLst_Get_struct (NFCKeyLst_Get_struct&&) = default;
        NFCKeyLst_Get_struct& operator=(NFCKeyLst_Get_struct&&) = default;
        NFCKeyLst_Get_struct& operator=(const NFCKeyLst_Get_struct&) = default;
        NFCKeyLst_Get_struct(const NFCKeyLst_Get_struct&) = default;
        #else
        NFCKeyLst_Get_struct(NFCKeyLst_Get_struct&& other_) OMG_NOEXCEPT;  
        NFCKeyLst_Get_struct& operator=(NFCKeyLst_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& NFCKeyLst_Req() OMG_NOEXCEPT {
            return m_NFCKeyLst_Req_;
        }

        const uint8_t& NFCKeyLst_Req() const OMG_NOEXCEPT {
            return m_NFCKeyLst_Req_;
        }

        void NFCKeyLst_Req(uint8_t value) {
            m_NFCKeyLst_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const NFCKeyLst_Get_struct& other_) const;
        bool operator != (const NFCKeyLst_Get_struct& other_) const;

        void swap(NFCKeyLst_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_NFCKeyLst_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(NFCKeyLst_Get_struct& a, NFCKeyLst_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NFCKeyLst_Get_struct& sample);

    class NDDSUSERDllExport NFCCardIDArray {
      public:
        NFCCardIDArray();

        explicit NFCCardIDArray(
            const ::dds::core::array< uint8_t, 16L>& NFCCardID);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NFCCardIDArray (NFCCardIDArray&&) = default;
        NFCCardIDArray& operator=(NFCCardIDArray&&) = default;
        NFCCardIDArray& operator=(const NFCCardIDArray&) = default;
        NFCCardIDArray(const NFCCardIDArray&) = default;
        #else
        NFCCardIDArray(NFCCardIDArray&& other_) OMG_NOEXCEPT;  
        NFCCardIDArray& operator=(NFCCardIDArray&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::dds::core::array< uint8_t, 16L>& NFCCardID() OMG_NOEXCEPT {
            return m_NFCCardID_;
        }

        const ::dds::core::array< uint8_t, 16L>& NFCCardID() const OMG_NOEXCEPT {
            return m_NFCCardID_;
        }

        void NFCCardID(const ::dds::core::array< uint8_t, 16L>& value) {
            m_NFCCardID_ = value;
        }

        void NFCCardID(::dds::core::array< uint8_t, 16L>&& value) {
            m_NFCCardID_ = std::move(value);
        }

        bool operator == (const NFCCardIDArray& other_) const;
        bool operator != (const NFCCardIDArray& other_) const;

        void swap(NFCCardIDArray& other_) OMG_NOEXCEPT ;

      private:

        ::dds::core::array< uint8_t, 16L> m_NFCCardID_;

    };

    inline void swap(NFCCardIDArray& a, NFCCardIDArray& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NFCCardIDArray& sample);

    class NDDSUSERDllExport NFCKeyLstSubstruct {
      public:
        NFCKeyLstSubstruct();

        NFCKeyLstSubstruct(
            const BodyDomain::NFCCardIDArray& NFCCardID,
            uint8_t NFCCard1_St,
            const std::string& NFCCardName,
            uint8_t NFCCardAuth_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NFCKeyLstSubstruct (NFCKeyLstSubstruct&&) = default;
        NFCKeyLstSubstruct& operator=(NFCKeyLstSubstruct&&) = default;
        NFCKeyLstSubstruct& operator=(const NFCKeyLstSubstruct&) = default;
        NFCKeyLstSubstruct(const NFCKeyLstSubstruct&) = default;
        #else
        NFCKeyLstSubstruct(NFCKeyLstSubstruct&& other_) OMG_NOEXCEPT;  
        NFCKeyLstSubstruct& operator=(NFCKeyLstSubstruct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        BodyDomain::NFCCardIDArray& NFCCardID() OMG_NOEXCEPT {
            return m_NFCCardID_;
        }

        const BodyDomain::NFCCardIDArray& NFCCardID() const OMG_NOEXCEPT {
            return m_NFCCardID_;
        }

        void NFCCardID(const BodyDomain::NFCCardIDArray& value) {
            m_NFCCardID_ = value;
        }

        void NFCCardID(BodyDomain::NFCCardIDArray&& value) {
            m_NFCCardID_ = std::move(value);
        }
        uint8_t& NFCCard1_St() OMG_NOEXCEPT {
            return m_NFCCard1_St_;
        }

        const uint8_t& NFCCard1_St() const OMG_NOEXCEPT {
            return m_NFCCard1_St_;
        }

        void NFCCard1_St(uint8_t value) {
            m_NFCCard1_St_ = value;
        }

        std::string& NFCCardName() OMG_NOEXCEPT {
            return m_NFCCardName_;
        }

        const std::string& NFCCardName() const OMG_NOEXCEPT {
            return m_NFCCardName_;
        }

        void NFCCardName(const std::string& value) {
            m_NFCCardName_ = value;
        }

        void NFCCardName(std::string&& value) {
            m_NFCCardName_ = std::move(value);
        }
        uint8_t& NFCCardAuth_St() OMG_NOEXCEPT {
            return m_NFCCardAuth_St_;
        }

        const uint8_t& NFCCardAuth_St() const OMG_NOEXCEPT {
            return m_NFCCardAuth_St_;
        }

        void NFCCardAuth_St(uint8_t value) {
            m_NFCCardAuth_St_ = value;
        }

        bool operator == (const NFCKeyLstSubstruct& other_) const;
        bool operator != (const NFCKeyLstSubstruct& other_) const;

        void swap(NFCKeyLstSubstruct& other_) OMG_NOEXCEPT ;

      private:

        BodyDomain::NFCCardIDArray m_NFCCardID_;
        uint8_t m_NFCCard1_St_;
        std::string m_NFCCardName_;
        uint8_t m_NFCCardAuth_St_;

    };

    inline void swap(NFCKeyLstSubstruct& a, NFCKeyLstSubstruct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NFCKeyLstSubstruct& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< BodyDomain::NFCKeyLstSubstruct >;
    template class NDDSUSERDllExport std::vector< BodyDomain::NFCKeyLstSubstruct >;
    #endif
    class NDDSUSERDllExport NFCKeyLst_Rsp_array {
      public:
        NFCKeyLst_Rsp_array();

        explicit NFCKeyLst_Rsp_array(
            const ::rti::core::bounded_sequence< BodyDomain::NFCKeyLstSubstruct, 10L >& NFCKeyLst);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NFCKeyLst_Rsp_array (NFCKeyLst_Rsp_array&&) = default;
        NFCKeyLst_Rsp_array& operator=(NFCKeyLst_Rsp_array&&) = default;
        NFCKeyLst_Rsp_array& operator=(const NFCKeyLst_Rsp_array&) = default;
        NFCKeyLst_Rsp_array(const NFCKeyLst_Rsp_array&) = default;
        #else
        NFCKeyLst_Rsp_array(NFCKeyLst_Rsp_array&& other_) OMG_NOEXCEPT;  
        NFCKeyLst_Rsp_array& operator=(NFCKeyLst_Rsp_array&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< BodyDomain::NFCKeyLstSubstruct, 10L >& NFCKeyLst() OMG_NOEXCEPT {
            return m_NFCKeyLst_;
        }

        const ::rti::core::bounded_sequence< BodyDomain::NFCKeyLstSubstruct, 10L >& NFCKeyLst() const OMG_NOEXCEPT {
            return m_NFCKeyLst_;
        }

        void NFCKeyLst(const ::rti::core::bounded_sequence< BodyDomain::NFCKeyLstSubstruct, 10L >& value) {
            m_NFCKeyLst_ = value;
        }

        void NFCKeyLst(::rti::core::bounded_sequence< BodyDomain::NFCKeyLstSubstruct, 10L >&& value) {
            m_NFCKeyLst_ = std::move(value);
        }

        bool operator == (const NFCKeyLst_Rsp_array& other_) const;
        bool operator != (const NFCKeyLst_Rsp_array& other_) const;

        void swap(NFCKeyLst_Rsp_array& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< BodyDomain::NFCKeyLstSubstruct, 10L > m_NFCKeyLst_;

    };

    inline void swap(NFCKeyLst_Rsp_array& a, NFCKeyLst_Rsp_array& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NFCKeyLst_Rsp_array& sample);

    class NDDSUSERDllExport NFCKeyRename_Set_struct {
      public:
        NFCKeyRename_Set_struct();

        NFCKeyRename_Set_struct(
            const BodyDomain::NFCCardIDArray& NFCCardID,
            const std::string& NFCCardName,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NFCKeyRename_Set_struct (NFCKeyRename_Set_struct&&) = default;
        NFCKeyRename_Set_struct& operator=(NFCKeyRename_Set_struct&&) = default;
        NFCKeyRename_Set_struct& operator=(const NFCKeyRename_Set_struct&) = default;
        NFCKeyRename_Set_struct(const NFCKeyRename_Set_struct&) = default;
        #else
        NFCKeyRename_Set_struct(NFCKeyRename_Set_struct&& other_) OMG_NOEXCEPT;  
        NFCKeyRename_Set_struct& operator=(NFCKeyRename_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        BodyDomain::NFCCardIDArray& NFCCardID() OMG_NOEXCEPT {
            return m_NFCCardID_;
        }

        const BodyDomain::NFCCardIDArray& NFCCardID() const OMG_NOEXCEPT {
            return m_NFCCardID_;
        }

        void NFCCardID(const BodyDomain::NFCCardIDArray& value) {
            m_NFCCardID_ = value;
        }

        void NFCCardID(BodyDomain::NFCCardIDArray&& value) {
            m_NFCCardID_ = std::move(value);
        }
        std::string& NFCCardName() OMG_NOEXCEPT {
            return m_NFCCardName_;
        }

        const std::string& NFCCardName() const OMG_NOEXCEPT {
            return m_NFCCardName_;
        }

        void NFCCardName(const std::string& value) {
            m_NFCCardName_ = value;
        }

        void NFCCardName(std::string&& value) {
            m_NFCCardName_ = std::move(value);
        }
        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const NFCKeyRename_Set_struct& other_) const;
        bool operator != (const NFCKeyRename_Set_struct& other_) const;

        void swap(NFCKeyRename_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        BodyDomain::NFCCardIDArray m_NFCCardID_;
        std::string m_NFCCardName_;
        std::string m_CtrlSource_;

    };

    inline void swap(NFCKeyRename_Set_struct& a, NFCKeyRename_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NFCKeyRename_Set_struct& sample);

    class NDDSUSERDllExport NFCKeyRename_Rsp_struct {
      public:
        NFCKeyRename_Rsp_struct();

        explicit NFCKeyRename_Rsp_struct(
            uint8_t NFCCardRenameRslt);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NFCKeyRename_Rsp_struct (NFCKeyRename_Rsp_struct&&) = default;
        NFCKeyRename_Rsp_struct& operator=(NFCKeyRename_Rsp_struct&&) = default;
        NFCKeyRename_Rsp_struct& operator=(const NFCKeyRename_Rsp_struct&) = default;
        NFCKeyRename_Rsp_struct(const NFCKeyRename_Rsp_struct&) = default;
        #else
        NFCKeyRename_Rsp_struct(NFCKeyRename_Rsp_struct&& other_) OMG_NOEXCEPT;  
        NFCKeyRename_Rsp_struct& operator=(NFCKeyRename_Rsp_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& NFCCardRenameRslt() OMG_NOEXCEPT {
            return m_NFCCardRenameRslt_;
        }

        const uint8_t& NFCCardRenameRslt() const OMG_NOEXCEPT {
            return m_NFCCardRenameRslt_;
        }

        void NFCCardRenameRslt(uint8_t value) {
            m_NFCCardRenameRslt_ = value;
        }

        bool operator == (const NFCKeyRename_Rsp_struct& other_) const;
        bool operator != (const NFCKeyRename_Rsp_struct& other_) const;

        void swap(NFCKeyRename_Rsp_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_NFCCardRenameRslt_;

    };

    inline void swap(NFCKeyRename_Rsp_struct& a, NFCKeyRename_Rsp_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NFCKeyRename_Rsp_struct& sample);

    class NDDSUSERDllExport PhysicalKeyLst_Get_struct {
      public:
        PhysicalKeyLst_Get_struct();

        explicit PhysicalKeyLst_Get_struct(
            uint8_t PhysicalKeyLst_Req);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        PhysicalKeyLst_Get_struct (PhysicalKeyLst_Get_struct&&) = default;
        PhysicalKeyLst_Get_struct& operator=(PhysicalKeyLst_Get_struct&&) = default;
        PhysicalKeyLst_Get_struct& operator=(const PhysicalKeyLst_Get_struct&) = default;
        PhysicalKeyLst_Get_struct(const PhysicalKeyLst_Get_struct&) = default;
        #else
        PhysicalKeyLst_Get_struct(PhysicalKeyLst_Get_struct&& other_) OMG_NOEXCEPT;  
        PhysicalKeyLst_Get_struct& operator=(PhysicalKeyLst_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& PhysicalKeyLst_Req() OMG_NOEXCEPT {
            return m_PhysicalKeyLst_Req_;
        }

        const uint8_t& PhysicalKeyLst_Req() const OMG_NOEXCEPT {
            return m_PhysicalKeyLst_Req_;
        }

        void PhysicalKeyLst_Req(uint8_t value) {
            m_PhysicalKeyLst_Req_ = value;
        }

        bool operator == (const PhysicalKeyLst_Get_struct& other_) const;
        bool operator != (const PhysicalKeyLst_Get_struct& other_) const;

        void swap(PhysicalKeyLst_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_PhysicalKeyLst_Req_;

    };

    inline void swap(PhysicalKeyLst_Get_struct& a, PhysicalKeyLst_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PhysicalKeyLst_Get_struct& sample);

    class NDDSUSERDllExport PhysicalKeyMACArray {
      public:
        PhysicalKeyMACArray();

        explicit PhysicalKeyMACArray(
            const ::dds::core::array< uint8_t, 6L>& PhysicalKeyMACAddr);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        PhysicalKeyMACArray (PhysicalKeyMACArray&&) = default;
        PhysicalKeyMACArray& operator=(PhysicalKeyMACArray&&) = default;
        PhysicalKeyMACArray& operator=(const PhysicalKeyMACArray&) = default;
        PhysicalKeyMACArray(const PhysicalKeyMACArray&) = default;
        #else
        PhysicalKeyMACArray(PhysicalKeyMACArray&& other_) OMG_NOEXCEPT;  
        PhysicalKeyMACArray& operator=(PhysicalKeyMACArray&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::dds::core::array< uint8_t, 6L>& PhysicalKeyMACAddr() OMG_NOEXCEPT {
            return m_PhysicalKeyMACAddr_;
        }

        const ::dds::core::array< uint8_t, 6L>& PhysicalKeyMACAddr() const OMG_NOEXCEPT {
            return m_PhysicalKeyMACAddr_;
        }

        void PhysicalKeyMACAddr(const ::dds::core::array< uint8_t, 6L>& value) {
            m_PhysicalKeyMACAddr_ = value;
        }

        void PhysicalKeyMACAddr(::dds::core::array< uint8_t, 6L>&& value) {
            m_PhysicalKeyMACAddr_ = std::move(value);
        }

        bool operator == (const PhysicalKeyMACArray& other_) const;
        bool operator != (const PhysicalKeyMACArray& other_) const;

        void swap(PhysicalKeyMACArray& other_) OMG_NOEXCEPT ;

      private:

        ::dds::core::array< uint8_t, 6L> m_PhysicalKeyMACAddr_;

    };

    inline void swap(PhysicalKeyMACArray& a, PhysicalKeyMACArray& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PhysicalKeyMACArray& sample);

    class NDDSUSERDllExport PhysicalKeyLstSubstruct {
      public:
        PhysicalKeyLstSubstruct();

        PhysicalKeyLstSubstruct(
            const BodyDomain::PhysicalKeyMACArray& PhysicalKeyMACAddr,
            uint8_t PhysicalKeyAuth_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        PhysicalKeyLstSubstruct (PhysicalKeyLstSubstruct&&) = default;
        PhysicalKeyLstSubstruct& operator=(PhysicalKeyLstSubstruct&&) = default;
        PhysicalKeyLstSubstruct& operator=(const PhysicalKeyLstSubstruct&) = default;
        PhysicalKeyLstSubstruct(const PhysicalKeyLstSubstruct&) = default;
        #else
        PhysicalKeyLstSubstruct(PhysicalKeyLstSubstruct&& other_) OMG_NOEXCEPT;  
        PhysicalKeyLstSubstruct& operator=(PhysicalKeyLstSubstruct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        BodyDomain::PhysicalKeyMACArray& PhysicalKeyMACAddr() OMG_NOEXCEPT {
            return m_PhysicalKeyMACAddr_;
        }

        const BodyDomain::PhysicalKeyMACArray& PhysicalKeyMACAddr() const OMG_NOEXCEPT {
            return m_PhysicalKeyMACAddr_;
        }

        void PhysicalKeyMACAddr(const BodyDomain::PhysicalKeyMACArray& value) {
            m_PhysicalKeyMACAddr_ = value;
        }

        void PhysicalKeyMACAddr(BodyDomain::PhysicalKeyMACArray&& value) {
            m_PhysicalKeyMACAddr_ = std::move(value);
        }
        uint8_t& PhysicalKeyAuth_St() OMG_NOEXCEPT {
            return m_PhysicalKeyAuth_St_;
        }

        const uint8_t& PhysicalKeyAuth_St() const OMG_NOEXCEPT {
            return m_PhysicalKeyAuth_St_;
        }

        void PhysicalKeyAuth_St(uint8_t value) {
            m_PhysicalKeyAuth_St_ = value;
        }

        bool operator == (const PhysicalKeyLstSubstruct& other_) const;
        bool operator != (const PhysicalKeyLstSubstruct& other_) const;

        void swap(PhysicalKeyLstSubstruct& other_) OMG_NOEXCEPT ;

      private:

        BodyDomain::PhysicalKeyMACArray m_PhysicalKeyMACAddr_;
        uint8_t m_PhysicalKeyAuth_St_;

    };

    inline void swap(PhysicalKeyLstSubstruct& a, PhysicalKeyLstSubstruct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PhysicalKeyLstSubstruct& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< BodyDomain::PhysicalKeyLstSubstruct >;
    template class NDDSUSERDllExport std::vector< BodyDomain::PhysicalKeyLstSubstruct >;
    #endif
    class NDDSUSERDllExport PhysicalKeyLst_Rsp_array {
      public:
        PhysicalKeyLst_Rsp_array();

        explicit PhysicalKeyLst_Rsp_array(
            const ::rti::core::bounded_sequence< BodyDomain::PhysicalKeyLstSubstruct, 2L >& PhysicalKeyLst);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        PhysicalKeyLst_Rsp_array (PhysicalKeyLst_Rsp_array&&) = default;
        PhysicalKeyLst_Rsp_array& operator=(PhysicalKeyLst_Rsp_array&&) = default;
        PhysicalKeyLst_Rsp_array& operator=(const PhysicalKeyLst_Rsp_array&) = default;
        PhysicalKeyLst_Rsp_array(const PhysicalKeyLst_Rsp_array&) = default;
        #else
        PhysicalKeyLst_Rsp_array(PhysicalKeyLst_Rsp_array&& other_) OMG_NOEXCEPT;  
        PhysicalKeyLst_Rsp_array& operator=(PhysicalKeyLst_Rsp_array&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< BodyDomain::PhysicalKeyLstSubstruct, 2L >& PhysicalKeyLst() OMG_NOEXCEPT {
            return m_PhysicalKeyLst_;
        }

        const ::rti::core::bounded_sequence< BodyDomain::PhysicalKeyLstSubstruct, 2L >& PhysicalKeyLst() const OMG_NOEXCEPT {
            return m_PhysicalKeyLst_;
        }

        void PhysicalKeyLst(const ::rti::core::bounded_sequence< BodyDomain::PhysicalKeyLstSubstruct, 2L >& value) {
            m_PhysicalKeyLst_ = value;
        }

        void PhysicalKeyLst(::rti::core::bounded_sequence< BodyDomain::PhysicalKeyLstSubstruct, 2L >&& value) {
            m_PhysicalKeyLst_ = std::move(value);
        }

        bool operator == (const PhysicalKeyLst_Rsp_array& other_) const;
        bool operator != (const PhysicalKeyLst_Rsp_array& other_) const;

        void swap(PhysicalKeyLst_Rsp_array& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< BodyDomain::PhysicalKeyLstSubstruct, 2L > m_PhysicalKeyLst_;

    };

    inline void swap(PhysicalKeyLst_Rsp_array& a, PhysicalKeyLst_Rsp_array& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PhysicalKeyLst_Rsp_array& sample);

    class NDDSUSERDllExport NFCKeyMag_Crtl_struct {
      public:
        NFCKeyMag_Crtl_struct();

        NFCKeyMag_Crtl_struct(
            uint8_t NFCSKeyAuth_Set,
            uint8_t NFCKeyBind_Set,
            uint8_t NFCKeyDel_Set,
            uint8_t NFCKeyFrz_Set,
            uint8_t NFCKeyUnfrzAuth_Set,
            const BodyDomain::NFCCardIDArray& NFCCardID,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NFCKeyMag_Crtl_struct (NFCKeyMag_Crtl_struct&&) = default;
        NFCKeyMag_Crtl_struct& operator=(NFCKeyMag_Crtl_struct&&) = default;
        NFCKeyMag_Crtl_struct& operator=(const NFCKeyMag_Crtl_struct&) = default;
        NFCKeyMag_Crtl_struct(const NFCKeyMag_Crtl_struct&) = default;
        #else
        NFCKeyMag_Crtl_struct(NFCKeyMag_Crtl_struct&& other_) OMG_NOEXCEPT;  
        NFCKeyMag_Crtl_struct& operator=(NFCKeyMag_Crtl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& NFCSKeyAuth_Set() OMG_NOEXCEPT {
            return m_NFCSKeyAuth_Set_;
        }

        const uint8_t& NFCSKeyAuth_Set() const OMG_NOEXCEPT {
            return m_NFCSKeyAuth_Set_;
        }

        void NFCSKeyAuth_Set(uint8_t value) {
            m_NFCSKeyAuth_Set_ = value;
        }

        uint8_t& NFCKeyBind_Set() OMG_NOEXCEPT {
            return m_NFCKeyBind_Set_;
        }

        const uint8_t& NFCKeyBind_Set() const OMG_NOEXCEPT {
            return m_NFCKeyBind_Set_;
        }

        void NFCKeyBind_Set(uint8_t value) {
            m_NFCKeyBind_Set_ = value;
        }

        uint8_t& NFCKeyDel_Set() OMG_NOEXCEPT {
            return m_NFCKeyDel_Set_;
        }

        const uint8_t& NFCKeyDel_Set() const OMG_NOEXCEPT {
            return m_NFCKeyDel_Set_;
        }

        void NFCKeyDel_Set(uint8_t value) {
            m_NFCKeyDel_Set_ = value;
        }

        uint8_t& NFCKeyFrz_Set() OMG_NOEXCEPT {
            return m_NFCKeyFrz_Set_;
        }

        const uint8_t& NFCKeyFrz_Set() const OMG_NOEXCEPT {
            return m_NFCKeyFrz_Set_;
        }

        void NFCKeyFrz_Set(uint8_t value) {
            m_NFCKeyFrz_Set_ = value;
        }

        uint8_t& NFCKeyUnfrzAuth_Set() OMG_NOEXCEPT {
            return m_NFCKeyUnfrzAuth_Set_;
        }

        const uint8_t& NFCKeyUnfrzAuth_Set() const OMG_NOEXCEPT {
            return m_NFCKeyUnfrzAuth_Set_;
        }

        void NFCKeyUnfrzAuth_Set(uint8_t value) {
            m_NFCKeyUnfrzAuth_Set_ = value;
        }

        BodyDomain::NFCCardIDArray& NFCCardID() OMG_NOEXCEPT {
            return m_NFCCardID_;
        }

        const BodyDomain::NFCCardIDArray& NFCCardID() const OMG_NOEXCEPT {
            return m_NFCCardID_;
        }

        void NFCCardID(const BodyDomain::NFCCardIDArray& value) {
            m_NFCCardID_ = value;
        }

        void NFCCardID(BodyDomain::NFCCardIDArray&& value) {
            m_NFCCardID_ = std::move(value);
        }
        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const NFCKeyMag_Crtl_struct& other_) const;
        bool operator != (const NFCKeyMag_Crtl_struct& other_) const;

        void swap(NFCKeyMag_Crtl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_NFCSKeyAuth_Set_;
        uint8_t m_NFCKeyBind_Set_;
        uint8_t m_NFCKeyDel_Set_;
        uint8_t m_NFCKeyFrz_Set_;
        uint8_t m_NFCKeyUnfrzAuth_Set_;
        BodyDomain::NFCCardIDArray m_NFCCardID_;
        std::string m_CtrlSource_;

    };

    inline void swap(NFCKeyMag_Crtl_struct& a, NFCKeyMag_Crtl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NFCKeyMag_Crtl_struct& sample);

    class NDDSUSERDllExport NFCKeyMag_Crtl_SOA_struct {
      public:
        NFCKeyMag_Crtl_SOA_struct();

        explicit NFCKeyMag_Crtl_SOA_struct(
            uint8_t NFCKeyMag_Crtl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NFCKeyMag_Crtl_SOA_struct (NFCKeyMag_Crtl_SOA_struct&&) = default;
        NFCKeyMag_Crtl_SOA_struct& operator=(NFCKeyMag_Crtl_SOA_struct&&) = default;
        NFCKeyMag_Crtl_SOA_struct& operator=(const NFCKeyMag_Crtl_SOA_struct&) = default;
        NFCKeyMag_Crtl_SOA_struct(const NFCKeyMag_Crtl_SOA_struct&) = default;
        #else
        NFCKeyMag_Crtl_SOA_struct(NFCKeyMag_Crtl_SOA_struct&& other_) OMG_NOEXCEPT;  
        NFCKeyMag_Crtl_SOA_struct& operator=(NFCKeyMag_Crtl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& NFCKeyMag_Crtl_SOA_u8() OMG_NOEXCEPT {
            return m_NFCKeyMag_Crtl_SOA_u8_;
        }

        const uint8_t& NFCKeyMag_Crtl_SOA_u8() const OMG_NOEXCEPT {
            return m_NFCKeyMag_Crtl_SOA_u8_;
        }

        void NFCKeyMag_Crtl_SOA_u8(uint8_t value) {
            m_NFCKeyMag_Crtl_SOA_u8_ = value;
        }

        bool operator == (const NFCKeyMag_Crtl_SOA_struct& other_) const;
        bool operator != (const NFCKeyMag_Crtl_SOA_struct& other_) const;

        void swap(NFCKeyMag_Crtl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_NFCKeyMag_Crtl_SOA_u8_;

    };

    inline void swap(NFCKeyMag_Crtl_SOA_struct& a, NFCKeyMag_Crtl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NFCKeyMag_Crtl_SOA_struct& sample);

    class NDDSUSERDllExport NFCKeyMag_St_struct {
      public:
        NFCKeyMag_St_struct();

        NFCKeyMag_St_struct(
            uint8_t NFCKeyBindRslt_St,
            uint8_t NFCKeyBindFailRsn_St,
            uint8_t NFCKeyDelRslt_St,
            uint8_t NFCKeyDelFailRsn_St,
            uint8_t NFCKeyFrzRslt_St,
            uint8_t NFCKeyFrzFailRsn_St,
            uint8_t NFCKeyUnfrzAuthRslt_St,
            uint8_t NFCKeyUnfrzAuthFailRsn_St,
            uint8_t NFCKeyUnfrzRslt_St,
            uint8_t NFCKeyUnfrzFailRsn_St,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NFCKeyMag_St_struct (NFCKeyMag_St_struct&&) = default;
        NFCKeyMag_St_struct& operator=(NFCKeyMag_St_struct&&) = default;
        NFCKeyMag_St_struct& operator=(const NFCKeyMag_St_struct&) = default;
        NFCKeyMag_St_struct(const NFCKeyMag_St_struct&) = default;
        #else
        NFCKeyMag_St_struct(NFCKeyMag_St_struct&& other_) OMG_NOEXCEPT;  
        NFCKeyMag_St_struct& operator=(NFCKeyMag_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& NFCKeyBindRslt_St() OMG_NOEXCEPT {
            return m_NFCKeyBindRslt_St_;
        }

        const uint8_t& NFCKeyBindRslt_St() const OMG_NOEXCEPT {
            return m_NFCKeyBindRslt_St_;
        }

        void NFCKeyBindRslt_St(uint8_t value) {
            m_NFCKeyBindRslt_St_ = value;
        }

        uint8_t& NFCKeyBindFailRsn_St() OMG_NOEXCEPT {
            return m_NFCKeyBindFailRsn_St_;
        }

        const uint8_t& NFCKeyBindFailRsn_St() const OMG_NOEXCEPT {
            return m_NFCKeyBindFailRsn_St_;
        }

        void NFCKeyBindFailRsn_St(uint8_t value) {
            m_NFCKeyBindFailRsn_St_ = value;
        }

        uint8_t& NFCKeyDelRslt_St() OMG_NOEXCEPT {
            return m_NFCKeyDelRslt_St_;
        }

        const uint8_t& NFCKeyDelRslt_St() const OMG_NOEXCEPT {
            return m_NFCKeyDelRslt_St_;
        }

        void NFCKeyDelRslt_St(uint8_t value) {
            m_NFCKeyDelRslt_St_ = value;
        }

        uint8_t& NFCKeyDelFailRsn_St() OMG_NOEXCEPT {
            return m_NFCKeyDelFailRsn_St_;
        }

        const uint8_t& NFCKeyDelFailRsn_St() const OMG_NOEXCEPT {
            return m_NFCKeyDelFailRsn_St_;
        }

        void NFCKeyDelFailRsn_St(uint8_t value) {
            m_NFCKeyDelFailRsn_St_ = value;
        }

        uint8_t& NFCKeyFrzRslt_St() OMG_NOEXCEPT {
            return m_NFCKeyFrzRslt_St_;
        }

        const uint8_t& NFCKeyFrzRslt_St() const OMG_NOEXCEPT {
            return m_NFCKeyFrzRslt_St_;
        }

        void NFCKeyFrzRslt_St(uint8_t value) {
            m_NFCKeyFrzRslt_St_ = value;
        }

        uint8_t& NFCKeyFrzFailRsn_St() OMG_NOEXCEPT {
            return m_NFCKeyFrzFailRsn_St_;
        }

        const uint8_t& NFCKeyFrzFailRsn_St() const OMG_NOEXCEPT {
            return m_NFCKeyFrzFailRsn_St_;
        }

        void NFCKeyFrzFailRsn_St(uint8_t value) {
            m_NFCKeyFrzFailRsn_St_ = value;
        }

        uint8_t& NFCKeyUnfrzAuthRslt_St() OMG_NOEXCEPT {
            return m_NFCKeyUnfrzAuthRslt_St_;
        }

        const uint8_t& NFCKeyUnfrzAuthRslt_St() const OMG_NOEXCEPT {
            return m_NFCKeyUnfrzAuthRslt_St_;
        }

        void NFCKeyUnfrzAuthRslt_St(uint8_t value) {
            m_NFCKeyUnfrzAuthRslt_St_ = value;
        }

        uint8_t& NFCKeyUnfrzAuthFailRsn_St() OMG_NOEXCEPT {
            return m_NFCKeyUnfrzAuthFailRsn_St_;
        }

        const uint8_t& NFCKeyUnfrzAuthFailRsn_St() const OMG_NOEXCEPT {
            return m_NFCKeyUnfrzAuthFailRsn_St_;
        }

        void NFCKeyUnfrzAuthFailRsn_St(uint8_t value) {
            m_NFCKeyUnfrzAuthFailRsn_St_ = value;
        }

        uint8_t& NFCKeyUnfrzRslt_St() OMG_NOEXCEPT {
            return m_NFCKeyUnfrzRslt_St_;
        }

        const uint8_t& NFCKeyUnfrzRslt_St() const OMG_NOEXCEPT {
            return m_NFCKeyUnfrzRslt_St_;
        }

        void NFCKeyUnfrzRslt_St(uint8_t value) {
            m_NFCKeyUnfrzRslt_St_ = value;
        }

        uint8_t& NFCKeyUnfrzFailRsn_St() OMG_NOEXCEPT {
            return m_NFCKeyUnfrzFailRsn_St_;
        }

        const uint8_t& NFCKeyUnfrzFailRsn_St() const OMG_NOEXCEPT {
            return m_NFCKeyUnfrzFailRsn_St_;
        }

        void NFCKeyUnfrzFailRsn_St(uint8_t value) {
            m_NFCKeyUnfrzFailRsn_St_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const NFCKeyMag_St_struct& other_) const;
        bool operator != (const NFCKeyMag_St_struct& other_) const;

        void swap(NFCKeyMag_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_NFCKeyBindRslt_St_;
        uint8_t m_NFCKeyBindFailRsn_St_;
        uint8_t m_NFCKeyDelRslt_St_;
        uint8_t m_NFCKeyDelFailRsn_St_;
        uint8_t m_NFCKeyFrzRslt_St_;
        uint8_t m_NFCKeyFrzFailRsn_St_;
        uint8_t m_NFCKeyUnfrzAuthRslt_St_;
        uint8_t m_NFCKeyUnfrzAuthFailRsn_St_;
        uint8_t m_NFCKeyUnfrzRslt_St_;
        uint8_t m_NFCKeyUnfrzFailRsn_St_;
        std::string m_CtrlSource_;

    };

    inline void swap(NFCKeyMag_St_struct& a, NFCKeyMag_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NFCKeyMag_St_struct& sample);

    class NDDSUSERDllExport TargetPointStruct_Array {
      public:
        TargetPointStruct_Array();

        explicit TargetPointStruct_Array(
            const ::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L >& TargetPoint);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        TargetPointStruct_Array (TargetPointStruct_Array&&) = default;
        TargetPointStruct_Array& operator=(TargetPointStruct_Array&&) = default;
        TargetPointStruct_Array& operator=(const TargetPointStruct_Array&) = default;
        TargetPointStruct_Array(const TargetPointStruct_Array&) = default;
        #else
        TargetPointStruct_Array(TargetPointStruct_Array&& other_) OMG_NOEXCEPT;  
        TargetPointStruct_Array& operator=(TargetPointStruct_Array&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L >& TargetPoint() OMG_NOEXCEPT {
            return m_TargetPoint_;
        }

        const ::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L >& TargetPoint() const OMG_NOEXCEPT {
            return m_TargetPoint_;
        }

        void TargetPoint(const ::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L >& value) {
            m_TargetPoint_ = value;
        }

        void TargetPoint(::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L >&& value) {
            m_TargetPoint_ = std::move(value);
        }

        bool operator == (const TargetPointStruct_Array& other_) const;
        bool operator != (const TargetPointStruct_Array& other_) const;

        void swap(TargetPointStruct_Array& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< BodyDomain::TargetPointSubstruct, 252L > m_TargetPoint_;

    };

    inline void swap(TargetPointStruct_Array& a, TargetPointStruct_Array& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TargetPointStruct_Array& sample);

    class NDDSUSERDllExport Key_Srv_Req_Union {
      public:
        Key_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Key_Srv_Req_Union (Key_Srv_Req_Union&&) = default;
        Key_Srv_Req_Union& operator=(Key_Srv_Req_Union&&) = default;
        Key_Srv_Req_Union& operator=(const Key_Srv_Req_Union&) = default;
        Key_Srv_Req_Union(const Key_Srv_Req_Union&) = default;
        #else
        Key_Srv_Req_Union(Key_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        Key_Srv_Req_Union& operator=(Key_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::DKLst_Get_struct& DKLst_Get()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Req_Union::DKLst_Get not selected by the discriminator" );
            }
            return m_u_.m_DKLst_Get_;
        }

        const BodyDomain::DKLst_Get_struct& DKLst_Get() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Req_Union::DKLst_Get not selected by the discriminator" );
            }
            return m_u_.m_DKLst_Get_;
        }

        void DKLst_Get(const BodyDomain::DKLst_Get_struct& value) {
            m_u_.m_DKLst_Get_ = value;
            m_d_= 0;
        }

        void DKLst_Get(BodyDomain::DKLst_Get_struct&& value) {
            m_u_.m_DKLst_Get_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::NFCKeyLst_Get_struct& NFCKeyLst_Get()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Req_Union::NFCKeyLst_Get not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyLst_Get_;
        }

        const BodyDomain::NFCKeyLst_Get_struct& NFCKeyLst_Get() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Req_Union::NFCKeyLst_Get not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyLst_Get_;
        }

        void NFCKeyLst_Get(const BodyDomain::NFCKeyLst_Get_struct& value) {
            m_u_.m_NFCKeyLst_Get_ = value;
            m_d_= 1;
        }

        void NFCKeyLst_Get(BodyDomain::NFCKeyLst_Get_struct&& value) {
            m_u_.m_NFCKeyLst_Get_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::NFCKeyRename_Set_struct& NFCKeyRename_Set()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Req_Union::NFCKeyRename_Set not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyRename_Set_;
        }

        const BodyDomain::NFCKeyRename_Set_struct& NFCKeyRename_Set() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Req_Union::NFCKeyRename_Set not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyRename_Set_;
        }

        void NFCKeyRename_Set(const BodyDomain::NFCKeyRename_Set_struct& value) {
            m_u_.m_NFCKeyRename_Set_ = value;
            m_d_= 2;
        }

        void NFCKeyRename_Set(BodyDomain::NFCKeyRename_Set_struct&& value) {
            m_u_.m_NFCKeyRename_Set_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::PhysicalKeyLst_Get_struct& PhysicalKeyLst_Get()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Req_Union::PhysicalKeyLst_Get not selected by the discriminator" );
            }
            return m_u_.m_PhysicalKeyLst_Get_;
        }

        const BodyDomain::PhysicalKeyLst_Get_struct& PhysicalKeyLst_Get() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Req_Union::PhysicalKeyLst_Get not selected by the discriminator" );
            }
            return m_u_.m_PhysicalKeyLst_Get_;
        }

        void PhysicalKeyLst_Get(const BodyDomain::PhysicalKeyLst_Get_struct& value) {
            m_u_.m_PhysicalKeyLst_Get_ = value;
            m_d_= 3;
        }

        void PhysicalKeyLst_Get(BodyDomain::PhysicalKeyLst_Get_struct&& value) {
            m_u_.m_PhysicalKeyLst_Get_ = std::move(value);
            m_d_= 3;
        }
        BodyDomain::NFCKeyMag_Crtl_struct& NFCKeyMag_Crtl()  {
            if ( _d() != 4) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Req_Union::NFCKeyMag_Crtl not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyMag_Crtl_;
        }

        const BodyDomain::NFCKeyMag_Crtl_struct& NFCKeyMag_Crtl() const  {
            if ( _d() != 4) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Req_Union::NFCKeyMag_Crtl not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyMag_Crtl_;
        }

        void NFCKeyMag_Crtl(const BodyDomain::NFCKeyMag_Crtl_struct& value) {
            m_u_.m_NFCKeyMag_Crtl_ = value;
            m_d_= 4;
        }

        void NFCKeyMag_Crtl(BodyDomain::NFCKeyMag_Crtl_struct&& value) {
            m_u_.m_NFCKeyMag_Crtl_ = std::move(value);
            m_d_= 4;
        }

        bool operator == (const Key_Srv_Req_Union& other_) const;
        bool operator != (const Key_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(Key_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::DKLst_Get_struct m_DKLst_Get_;
            BodyDomain::NFCKeyLst_Get_struct m_NFCKeyLst_Get_;
            BodyDomain::NFCKeyRename_Set_struct m_NFCKeyRename_Set_;
            BodyDomain::PhysicalKeyLst_Get_struct m_PhysicalKeyLst_Get_;
            BodyDomain::NFCKeyMag_Crtl_struct m_NFCKeyMag_Crtl_;
            Union_();
            Union_(
                const BodyDomain::DKLst_Get_struct& DKLst_Get,
                const BodyDomain::NFCKeyLst_Get_struct& NFCKeyLst_Get,
                const BodyDomain::NFCKeyRename_Set_struct& NFCKeyRename_Set,
                const BodyDomain::PhysicalKeyLst_Get_struct& PhysicalKeyLst_Get,
                const BodyDomain::NFCKeyMag_Crtl_struct& NFCKeyMag_Crtl);
        };
        Union_ m_u_;

    };

    inline void swap(Key_Srv_Req_Union& a, Key_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Key_Srv_Req_Union& sample);

    class NDDSUSERDllExport Key_Srv_Resp_Union {
      public:
        Key_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Key_Srv_Resp_Union (Key_Srv_Resp_Union&&) = default;
        Key_Srv_Resp_Union& operator=(Key_Srv_Resp_Union&&) = default;
        Key_Srv_Resp_Union& operator=(const Key_Srv_Resp_Union&) = default;
        Key_Srv_Resp_Union(const Key_Srv_Resp_Union&) = default;
        #else
        Key_Srv_Resp_Union(Key_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        Key_Srv_Resp_Union& operator=(Key_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        BodyDomain::DKLst_Rsp_array& DKLst_Get_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Resp_Union::DKLst_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_DKLst_Get_SOA_;
        }

        const BodyDomain::DKLst_Rsp_array& DKLst_Get_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Resp_Union::DKLst_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_DKLst_Get_SOA_;
        }

        void DKLst_Get_SOA(const BodyDomain::DKLst_Rsp_array& value) {
            m_u_.m_DKLst_Get_SOA_ = value;
            m_d_= 0;
        }

        void DKLst_Get_SOA(BodyDomain::DKLst_Rsp_array&& value) {
            m_u_.m_DKLst_Get_SOA_ = std::move(value);
            m_d_= 0;
        }
        BodyDomain::NFCKeyLst_Rsp_array& NFCKeyLst_Get_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Resp_Union::NFCKeyLst_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyLst_Get_SOA_;
        }

        const BodyDomain::NFCKeyLst_Rsp_array& NFCKeyLst_Get_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Resp_Union::NFCKeyLst_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyLst_Get_SOA_;
        }

        void NFCKeyLst_Get_SOA(const BodyDomain::NFCKeyLst_Rsp_array& value) {
            m_u_.m_NFCKeyLst_Get_SOA_ = value;
            m_d_= 1;
        }

        void NFCKeyLst_Get_SOA(BodyDomain::NFCKeyLst_Rsp_array&& value) {
            m_u_.m_NFCKeyLst_Get_SOA_ = std::move(value);
            m_d_= 1;
        }
        BodyDomain::NFCKeyRename_Rsp_struct& NFCKeyRename_Set_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Resp_Union::NFCKeyRename_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyRename_Set_SOA_;
        }

        const BodyDomain::NFCKeyRename_Rsp_struct& NFCKeyRename_Set_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Resp_Union::NFCKeyRename_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyRename_Set_SOA_;
        }

        void NFCKeyRename_Set_SOA(const BodyDomain::NFCKeyRename_Rsp_struct& value) {
            m_u_.m_NFCKeyRename_Set_SOA_ = value;
            m_d_= 2;
        }

        void NFCKeyRename_Set_SOA(BodyDomain::NFCKeyRename_Rsp_struct&& value) {
            m_u_.m_NFCKeyRename_Set_SOA_ = std::move(value);
            m_d_= 2;
        }
        BodyDomain::PhysicalKeyLst_Rsp_array& PhysicalKeyLst_Get_SOA()  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Resp_Union::PhysicalKeyLst_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_PhysicalKeyLst_Get_SOA_;
        }

        const BodyDomain::PhysicalKeyLst_Rsp_array& PhysicalKeyLst_Get_SOA() const  {
            if ( _d() != 3) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Resp_Union::PhysicalKeyLst_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_PhysicalKeyLst_Get_SOA_;
        }

        void PhysicalKeyLst_Get_SOA(const BodyDomain::PhysicalKeyLst_Rsp_array& value) {
            m_u_.m_PhysicalKeyLst_Get_SOA_ = value;
            m_d_= 3;
        }

        void PhysicalKeyLst_Get_SOA(BodyDomain::PhysicalKeyLst_Rsp_array&& value) {
            m_u_.m_PhysicalKeyLst_Get_SOA_ = std::move(value);
            m_d_= 3;
        }
        BodyDomain::NFCKeyMag_Crtl_SOA_struct& NFCKeyMag_Crtl_SOA()  {
            if ( _d() != 4) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Resp_Union::NFCKeyMag_Crtl_SOA not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyMag_Crtl_SOA_;
        }

        const BodyDomain::NFCKeyMag_Crtl_SOA_struct& NFCKeyMag_Crtl_SOA() const  {
            if ( _d() != 4) {
                throw ::dds::core::PreconditionNotMetError(
                    "BodyDomain::Key_Srv_Resp_Union::NFCKeyMag_Crtl_SOA not selected by the discriminator" );
            }
            return m_u_.m_NFCKeyMag_Crtl_SOA_;
        }

        void NFCKeyMag_Crtl_SOA(const BodyDomain::NFCKeyMag_Crtl_SOA_struct& value) {
            m_u_.m_NFCKeyMag_Crtl_SOA_ = value;
            m_d_= 4;
        }

        void NFCKeyMag_Crtl_SOA(BodyDomain::NFCKeyMag_Crtl_SOA_struct&& value) {
            m_u_.m_NFCKeyMag_Crtl_SOA_ = std::move(value);
            m_d_= 4;
        }

        bool operator == (const Key_Srv_Resp_Union& other_) const;
        bool operator != (const Key_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(Key_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            BodyDomain::DKLst_Rsp_array m_DKLst_Get_SOA_;
            BodyDomain::NFCKeyLst_Rsp_array m_NFCKeyLst_Get_SOA_;
            BodyDomain::NFCKeyRename_Rsp_struct m_NFCKeyRename_Set_SOA_;
            BodyDomain::PhysicalKeyLst_Rsp_array m_PhysicalKeyLst_Get_SOA_;
            BodyDomain::NFCKeyMag_Crtl_SOA_struct m_NFCKeyMag_Crtl_SOA_;
            Union_();
            Union_(
                const BodyDomain::DKLst_Rsp_array& DKLst_Get_SOA,
                const BodyDomain::NFCKeyLst_Rsp_array& NFCKeyLst_Get_SOA,
                const BodyDomain::NFCKeyRename_Rsp_struct& NFCKeyRename_Set_SOA,
                const BodyDomain::PhysicalKeyLst_Rsp_array& PhysicalKeyLst_Get_SOA,
                const BodyDomain::NFCKeyMag_Crtl_SOA_struct& NFCKeyMag_Crtl_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(Key_Srv_Resp_Union& a, Key_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Key_Srv_Resp_Union& sample);

    class NDDSUSERDllExport KeyInfo_Notify_struct {
      public:
        KeyInfo_Notify_struct();

        KeyInfo_Notify_struct(
            uint8_t NFCDetRmdrSet_Req,
            uint8_t BleKeyDiscnctRmdr_Req,
            uint8_t OwnerKey_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        KeyInfo_Notify_struct (KeyInfo_Notify_struct&&) = default;
        KeyInfo_Notify_struct& operator=(KeyInfo_Notify_struct&&) = default;
        KeyInfo_Notify_struct& operator=(const KeyInfo_Notify_struct&) = default;
        KeyInfo_Notify_struct(const KeyInfo_Notify_struct&) = default;
        #else
        KeyInfo_Notify_struct(KeyInfo_Notify_struct&& other_) OMG_NOEXCEPT;  
        KeyInfo_Notify_struct& operator=(KeyInfo_Notify_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& NFCDetRmdrSet_Req() OMG_NOEXCEPT {
            return m_NFCDetRmdrSet_Req_;
        }

        const uint8_t& NFCDetRmdrSet_Req() const OMG_NOEXCEPT {
            return m_NFCDetRmdrSet_Req_;
        }

        void NFCDetRmdrSet_Req(uint8_t value) {
            m_NFCDetRmdrSet_Req_ = value;
        }

        uint8_t& BleKeyDiscnctRmdr_Req() OMG_NOEXCEPT {
            return m_BleKeyDiscnctRmdr_Req_;
        }

        const uint8_t& BleKeyDiscnctRmdr_Req() const OMG_NOEXCEPT {
            return m_BleKeyDiscnctRmdr_Req_;
        }

        void BleKeyDiscnctRmdr_Req(uint8_t value) {
            m_BleKeyDiscnctRmdr_Req_ = value;
        }

        uint8_t& OwnerKey_St() OMG_NOEXCEPT {
            return m_OwnerKey_St_;
        }

        const uint8_t& OwnerKey_St() const OMG_NOEXCEPT {
            return m_OwnerKey_St_;
        }

        void OwnerKey_St(uint8_t value) {
            m_OwnerKey_St_ = value;
        }

        bool operator == (const KeyInfo_Notify_struct& other_) const;
        bool operator != (const KeyInfo_Notify_struct& other_) const;

        void swap(KeyInfo_Notify_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_NFCDetRmdrSet_Req_;
        uint8_t m_BleKeyDiscnctRmdr_Req_;
        uint8_t m_OwnerKey_St_;

    };

    inline void swap(KeyInfo_Notify_struct& a, KeyInfo_Notify_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const KeyInfo_Notify_struct& sample);

} // namespace BodyDomain  
namespace PTDomain {

    class NDDSUSERDllExport PowerMode_Ctrl_struct {
      public:
        PowerMode_Ctrl_struct();

        PowerMode_Ctrl_struct(
            uint8_t PowerMode_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        PowerMode_Ctrl_struct (PowerMode_Ctrl_struct&&) = default;
        PowerMode_Ctrl_struct& operator=(PowerMode_Ctrl_struct&&) = default;
        PowerMode_Ctrl_struct& operator=(const PowerMode_Ctrl_struct&) = default;
        PowerMode_Ctrl_struct(const PowerMode_Ctrl_struct&) = default;
        #else
        PowerMode_Ctrl_struct(PowerMode_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        PowerMode_Ctrl_struct& operator=(PowerMode_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& PowerMode_Req() OMG_NOEXCEPT {
            return m_PowerMode_Req_;
        }

        const uint8_t& PowerMode_Req() const OMG_NOEXCEPT {
            return m_PowerMode_Req_;
        }

        void PowerMode_Req(uint8_t value) {
            m_PowerMode_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const PowerMode_Ctrl_struct& other_) const;
        bool operator != (const PowerMode_Ctrl_struct& other_) const;

        void swap(PowerMode_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_PowerMode_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(PowerMode_Ctrl_struct& a, PowerMode_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PowerMode_Ctrl_struct& sample);

    class NDDSUSERDllExport PowerMode_Ctrl_SOA_struct {
      public:
        PowerMode_Ctrl_SOA_struct();

        PowerMode_Ctrl_SOA_struct(
            uint8_t PowerOn_Rsp,
            uint8_t PowerOff_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        PowerMode_Ctrl_SOA_struct (PowerMode_Ctrl_SOA_struct&&) = default;
        PowerMode_Ctrl_SOA_struct& operator=(PowerMode_Ctrl_SOA_struct&&) = default;
        PowerMode_Ctrl_SOA_struct& operator=(const PowerMode_Ctrl_SOA_struct&) = default;
        PowerMode_Ctrl_SOA_struct(const PowerMode_Ctrl_SOA_struct&) = default;
        #else
        PowerMode_Ctrl_SOA_struct(PowerMode_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        PowerMode_Ctrl_SOA_struct& operator=(PowerMode_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& PowerOn_Rsp() OMG_NOEXCEPT {
            return m_PowerOn_Rsp_;
        }

        const uint8_t& PowerOn_Rsp() const OMG_NOEXCEPT {
            return m_PowerOn_Rsp_;
        }

        void PowerOn_Rsp(uint8_t value) {
            m_PowerOn_Rsp_ = value;
        }

        uint8_t& PowerOff_Rsp() OMG_NOEXCEPT {
            return m_PowerOff_Rsp_;
        }

        const uint8_t& PowerOff_Rsp() const OMG_NOEXCEPT {
            return m_PowerOff_Rsp_;
        }

        void PowerOff_Rsp(uint8_t value) {
            m_PowerOff_Rsp_ = value;
        }

        bool operator == (const PowerMode_Ctrl_SOA_struct& other_) const;
        bool operator != (const PowerMode_Ctrl_SOA_struct& other_) const;

        void swap(PowerMode_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_PowerOn_Rsp_;
        uint8_t m_PowerOff_Rsp_;

    };

    inline void swap(PowerMode_Ctrl_SOA_struct& a, PowerMode_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PowerMode_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport PowerMode_St_struct {
      public:
        PowerMode_St_struct();

        PowerMode_St_struct(
            uint8_t PowerMode_St,
            uint8_t PowerGoOff_St,
            uint8_t PowerOffAvl_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        PowerMode_St_struct (PowerMode_St_struct&&) = default;
        PowerMode_St_struct& operator=(PowerMode_St_struct&&) = default;
        PowerMode_St_struct& operator=(const PowerMode_St_struct&) = default;
        PowerMode_St_struct(const PowerMode_St_struct&) = default;
        #else
        PowerMode_St_struct(PowerMode_St_struct&& other_) OMG_NOEXCEPT;  
        PowerMode_St_struct& operator=(PowerMode_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& PowerMode_St() OMG_NOEXCEPT {
            return m_PowerMode_St_;
        }

        const uint8_t& PowerMode_St() const OMG_NOEXCEPT {
            return m_PowerMode_St_;
        }

        void PowerMode_St(uint8_t value) {
            m_PowerMode_St_ = value;
        }

        uint8_t& PowerGoOff_St() OMG_NOEXCEPT {
            return m_PowerGoOff_St_;
        }

        const uint8_t& PowerGoOff_St() const OMG_NOEXCEPT {
            return m_PowerGoOff_St_;
        }

        void PowerGoOff_St(uint8_t value) {
            m_PowerGoOff_St_ = value;
        }

        uint8_t& PowerOffAvl_St() OMG_NOEXCEPT {
            return m_PowerOffAvl_St_;
        }

        const uint8_t& PowerOffAvl_St() const OMG_NOEXCEPT {
            return m_PowerOffAvl_St_;
        }

        void PowerOffAvl_St(uint8_t value) {
            m_PowerOffAvl_St_ = value;
        }

        bool operator == (const PowerMode_St_struct& other_) const;
        bool operator != (const PowerMode_St_struct& other_) const;

        void swap(PowerMode_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_PowerMode_St_;
        uint8_t m_PowerGoOff_St_;
        uint8_t m_PowerOffAvl_St_;

    };

    inline void swap(PowerMode_St_struct& a, PowerMode_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PowerMode_St_struct& sample);

    class NDDSUSERDllExport CarMode_Ctrl_struct {
      public:
        CarMode_Ctrl_struct();

        CarMode_Ctrl_struct(
            uint8_t CarMode_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        CarMode_Ctrl_struct (CarMode_Ctrl_struct&&) = default;
        CarMode_Ctrl_struct& operator=(CarMode_Ctrl_struct&&) = default;
        CarMode_Ctrl_struct& operator=(const CarMode_Ctrl_struct&) = default;
        CarMode_Ctrl_struct(const CarMode_Ctrl_struct&) = default;
        #else
        CarMode_Ctrl_struct(CarMode_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        CarMode_Ctrl_struct& operator=(CarMode_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& CarMode_Req() OMG_NOEXCEPT {
            return m_CarMode_Req_;
        }

        const uint8_t& CarMode_Req() const OMG_NOEXCEPT {
            return m_CarMode_Req_;
        }

        void CarMode_Req(uint8_t value) {
            m_CarMode_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const CarMode_Ctrl_struct& other_) const;
        bool operator != (const CarMode_Ctrl_struct& other_) const;

        void swap(CarMode_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_CarMode_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(CarMode_Ctrl_struct& a, CarMode_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CarMode_Ctrl_struct& sample);

    class NDDSUSERDllExport CarMode_Ctrl_SOA_struct {
      public:
        CarMode_Ctrl_SOA_struct();

        explicit CarMode_Ctrl_SOA_struct(
            uint8_t CarMode_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        CarMode_Ctrl_SOA_struct (CarMode_Ctrl_SOA_struct&&) = default;
        CarMode_Ctrl_SOA_struct& operator=(CarMode_Ctrl_SOA_struct&&) = default;
        CarMode_Ctrl_SOA_struct& operator=(const CarMode_Ctrl_SOA_struct&) = default;
        CarMode_Ctrl_SOA_struct(const CarMode_Ctrl_SOA_struct&) = default;
        #else
        CarMode_Ctrl_SOA_struct(CarMode_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        CarMode_Ctrl_SOA_struct& operator=(CarMode_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& CarMode_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_CarMode_Ctrl_SOA_u8_;
        }

        const uint8_t& CarMode_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_CarMode_Ctrl_SOA_u8_;
        }

        void CarMode_Ctrl_SOA_u8(uint8_t value) {
            m_CarMode_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const CarMode_Ctrl_SOA_struct& other_) const;
        bool operator != (const CarMode_Ctrl_SOA_struct& other_) const;

        void swap(CarMode_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_CarMode_Ctrl_SOA_u8_;

    };

    inline void swap(CarMode_Ctrl_SOA_struct& a, CarMode_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CarMode_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport CarMode_St_struct {
      public:
        CarMode_St_struct();

        explicit CarMode_St_struct(
            uint8_t CarMode_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        CarMode_St_struct (CarMode_St_struct&&) = default;
        CarMode_St_struct& operator=(CarMode_St_struct&&) = default;
        CarMode_St_struct& operator=(const CarMode_St_struct&) = default;
        CarMode_St_struct(const CarMode_St_struct&) = default;
        #else
        CarMode_St_struct(CarMode_St_struct&& other_) OMG_NOEXCEPT;  
        CarMode_St_struct& operator=(CarMode_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& CarMode_St() OMG_NOEXCEPT {
            return m_CarMode_St_;
        }

        const uint8_t& CarMode_St() const OMG_NOEXCEPT {
            return m_CarMode_St_;
        }

        void CarMode_St(uint8_t value) {
            m_CarMode_St_ = value;
        }

        bool operator == (const CarMode_St_struct& other_) const;
        bool operator != (const CarMode_St_struct& other_) const;

        void swap(CarMode_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_CarMode_St_;

    };

    inline void swap(CarMode_St_struct& a, CarMode_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CarMode_St_struct& sample);

    class NDDSUSERDllExport DrivingMode_Ctrl_struct {
      public:
        DrivingMode_Ctrl_struct();

        DrivingMode_Ctrl_struct(
            uint8_t EPSModeChange_Req,
            uint8_t TargVehicleMode_Req,
            uint8_t PTModeChange_Req,
            uint8_t LowConsumMode_Req,
            uint8_t ValetMode_Req,
            uint8_t OnePedalMode_Req,
            uint8_t CoastRegenStrg_Req,
            uint8_t SpdLimit_Req,
            uint8_t TrailMode_Req,
            uint8_t Salemode_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrivingMode_Ctrl_struct (DrivingMode_Ctrl_struct&&) = default;
        DrivingMode_Ctrl_struct& operator=(DrivingMode_Ctrl_struct&&) = default;
        DrivingMode_Ctrl_struct& operator=(const DrivingMode_Ctrl_struct&) = default;
        DrivingMode_Ctrl_struct(const DrivingMode_Ctrl_struct&) = default;
        #else
        DrivingMode_Ctrl_struct(DrivingMode_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        DrivingMode_Ctrl_struct& operator=(DrivingMode_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& EPSModeChange_Req() OMG_NOEXCEPT {
            return m_EPSModeChange_Req_;
        }

        const uint8_t& EPSModeChange_Req() const OMG_NOEXCEPT {
            return m_EPSModeChange_Req_;
        }

        void EPSModeChange_Req(uint8_t value) {
            m_EPSModeChange_Req_ = value;
        }

        uint8_t& TargVehicleMode_Req() OMG_NOEXCEPT {
            return m_TargVehicleMode_Req_;
        }

        const uint8_t& TargVehicleMode_Req() const OMG_NOEXCEPT {
            return m_TargVehicleMode_Req_;
        }

        void TargVehicleMode_Req(uint8_t value) {
            m_TargVehicleMode_Req_ = value;
        }

        uint8_t& PTModeChange_Req() OMG_NOEXCEPT {
            return m_PTModeChange_Req_;
        }

        const uint8_t& PTModeChange_Req() const OMG_NOEXCEPT {
            return m_PTModeChange_Req_;
        }

        void PTModeChange_Req(uint8_t value) {
            m_PTModeChange_Req_ = value;
        }

        uint8_t& LowConsumMode_Req() OMG_NOEXCEPT {
            return m_LowConsumMode_Req_;
        }

        const uint8_t& LowConsumMode_Req() const OMG_NOEXCEPT {
            return m_LowConsumMode_Req_;
        }

        void LowConsumMode_Req(uint8_t value) {
            m_LowConsumMode_Req_ = value;
        }

        uint8_t& ValetMode_Req() OMG_NOEXCEPT {
            return m_ValetMode_Req_;
        }

        const uint8_t& ValetMode_Req() const OMG_NOEXCEPT {
            return m_ValetMode_Req_;
        }

        void ValetMode_Req(uint8_t value) {
            m_ValetMode_Req_ = value;
        }

        uint8_t& OnePedalMode_Req() OMG_NOEXCEPT {
            return m_OnePedalMode_Req_;
        }

        const uint8_t& OnePedalMode_Req() const OMG_NOEXCEPT {
            return m_OnePedalMode_Req_;
        }

        void OnePedalMode_Req(uint8_t value) {
            m_OnePedalMode_Req_ = value;
        }

        uint8_t& CoastRegenStrg_Req() OMG_NOEXCEPT {
            return m_CoastRegenStrg_Req_;
        }

        const uint8_t& CoastRegenStrg_Req() const OMG_NOEXCEPT {
            return m_CoastRegenStrg_Req_;
        }

        void CoastRegenStrg_Req(uint8_t value) {
            m_CoastRegenStrg_Req_ = value;
        }

        uint8_t& SpdLimit_Req() OMG_NOEXCEPT {
            return m_SpdLimit_Req_;
        }

        const uint8_t& SpdLimit_Req() const OMG_NOEXCEPT {
            return m_SpdLimit_Req_;
        }

        void SpdLimit_Req(uint8_t value) {
            m_SpdLimit_Req_ = value;
        }

        uint8_t& TrailMode_Req() OMG_NOEXCEPT {
            return m_TrailMode_Req_;
        }

        const uint8_t& TrailMode_Req() const OMG_NOEXCEPT {
            return m_TrailMode_Req_;
        }

        void TrailMode_Req(uint8_t value) {
            m_TrailMode_Req_ = value;
        }

        uint8_t& Salemode_Req() OMG_NOEXCEPT {
            return m_Salemode_Req_;
        }

        const uint8_t& Salemode_Req() const OMG_NOEXCEPT {
            return m_Salemode_Req_;
        }

        void Salemode_Req(uint8_t value) {
            m_Salemode_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const DrivingMode_Ctrl_struct& other_) const;
        bool operator != (const DrivingMode_Ctrl_struct& other_) const;

        void swap(DrivingMode_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_EPSModeChange_Req_;
        uint8_t m_TargVehicleMode_Req_;
        uint8_t m_PTModeChange_Req_;
        uint8_t m_LowConsumMode_Req_;
        uint8_t m_ValetMode_Req_;
        uint8_t m_OnePedalMode_Req_;
        uint8_t m_CoastRegenStrg_Req_;
        uint8_t m_SpdLimit_Req_;
        uint8_t m_TrailMode_Req_;
        uint8_t m_Salemode_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(DrivingMode_Ctrl_struct& a, DrivingMode_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrivingMode_Ctrl_struct& sample);

    class NDDSUSERDllExport DrivingMode_Ctrl_SOA_struct {
      public:
        DrivingMode_Ctrl_SOA_struct();

        explicit DrivingMode_Ctrl_SOA_struct(
            uint8_t DrivingMode_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DrivingMode_Ctrl_SOA_struct (DrivingMode_Ctrl_SOA_struct&&) = default;
        DrivingMode_Ctrl_SOA_struct& operator=(DrivingMode_Ctrl_SOA_struct&&) = default;
        DrivingMode_Ctrl_SOA_struct& operator=(const DrivingMode_Ctrl_SOA_struct&) = default;
        DrivingMode_Ctrl_SOA_struct(const DrivingMode_Ctrl_SOA_struct&) = default;
        #else
        DrivingMode_Ctrl_SOA_struct(DrivingMode_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        DrivingMode_Ctrl_SOA_struct& operator=(DrivingMode_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& DrivingMode_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_DrivingMode_Ctrl_SOA_u8_;
        }

        const uint8_t& DrivingMode_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_DrivingMode_Ctrl_SOA_u8_;
        }

        void DrivingMode_Ctrl_SOA_u8(uint8_t value) {
            m_DrivingMode_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const DrivingMode_Ctrl_SOA_struct& other_) const;
        bool operator != (const DrivingMode_Ctrl_SOA_struct& other_) const;

        void swap(DrivingMode_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_DrivingMode_Ctrl_SOA_u8_;

    };

    inline void swap(DrivingMode_Ctrl_SOA_struct& a, DrivingMode_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DrivingMode_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport DringMode_St_Struct {
      public:
        DringMode_St_Struct();

        DringMode_St_Struct(
            uint8_t DMSEPSModeInfo_St,
            uint8_t DMSVehMode_St,
            uint8_t DMSModeChgEn_St,
            uint8_t DMSPTModeInfo_St,
            uint8_t DMSValetMode_St,
            uint8_t OnePedalMode_St,
            uint8_t OPMAvaliability_St,
            uint8_t RegenSetPct_Rsp,
            uint8_t RegenAvail_St,
            uint8_t RegenForDisp_UI,
            uint8_t DrvVehModAvaliability_St,
            uint8_t TrailMode_St,
            uint8_t TrailAvaliability_St,
            uint8_t TrailForDisp_UI,
            uint8_t SaleMode_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DringMode_St_Struct (DringMode_St_Struct&&) = default;
        DringMode_St_Struct& operator=(DringMode_St_Struct&&) = default;
        DringMode_St_Struct& operator=(const DringMode_St_Struct&) = default;
        DringMode_St_Struct(const DringMode_St_Struct&) = default;
        #else
        DringMode_St_Struct(DringMode_St_Struct&& other_) OMG_NOEXCEPT;  
        DringMode_St_Struct& operator=(DringMode_St_Struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& DMSEPSModeInfo_St() OMG_NOEXCEPT {
            return m_DMSEPSModeInfo_St_;
        }

        const uint8_t& DMSEPSModeInfo_St() const OMG_NOEXCEPT {
            return m_DMSEPSModeInfo_St_;
        }

        void DMSEPSModeInfo_St(uint8_t value) {
            m_DMSEPSModeInfo_St_ = value;
        }

        uint8_t& DMSVehMode_St() OMG_NOEXCEPT {
            return m_DMSVehMode_St_;
        }

        const uint8_t& DMSVehMode_St() const OMG_NOEXCEPT {
            return m_DMSVehMode_St_;
        }

        void DMSVehMode_St(uint8_t value) {
            m_DMSVehMode_St_ = value;
        }

        uint8_t& DMSModeChgEn_St() OMG_NOEXCEPT {
            return m_DMSModeChgEn_St_;
        }

        const uint8_t& DMSModeChgEn_St() const OMG_NOEXCEPT {
            return m_DMSModeChgEn_St_;
        }

        void DMSModeChgEn_St(uint8_t value) {
            m_DMSModeChgEn_St_ = value;
        }

        uint8_t& DMSPTModeInfo_St() OMG_NOEXCEPT {
            return m_DMSPTModeInfo_St_;
        }

        const uint8_t& DMSPTModeInfo_St() const OMG_NOEXCEPT {
            return m_DMSPTModeInfo_St_;
        }

        void DMSPTModeInfo_St(uint8_t value) {
            m_DMSPTModeInfo_St_ = value;
        }

        uint8_t& DMSValetMode_St() OMG_NOEXCEPT {
            return m_DMSValetMode_St_;
        }

        const uint8_t& DMSValetMode_St() const OMG_NOEXCEPT {
            return m_DMSValetMode_St_;
        }

        void DMSValetMode_St(uint8_t value) {
            m_DMSValetMode_St_ = value;
        }

        uint8_t& OnePedalMode_St() OMG_NOEXCEPT {
            return m_OnePedalMode_St_;
        }

        const uint8_t& OnePedalMode_St() const OMG_NOEXCEPT {
            return m_OnePedalMode_St_;
        }

        void OnePedalMode_St(uint8_t value) {
            m_OnePedalMode_St_ = value;
        }

        uint8_t& OPMAvaliability_St() OMG_NOEXCEPT {
            return m_OPMAvaliability_St_;
        }

        const uint8_t& OPMAvaliability_St() const OMG_NOEXCEPT {
            return m_OPMAvaliability_St_;
        }

        void OPMAvaliability_St(uint8_t value) {
            m_OPMAvaliability_St_ = value;
        }

        uint8_t& RegenSetPct_Rsp() OMG_NOEXCEPT {
            return m_RegenSetPct_Rsp_;
        }

        const uint8_t& RegenSetPct_Rsp() const OMG_NOEXCEPT {
            return m_RegenSetPct_Rsp_;
        }

        void RegenSetPct_Rsp(uint8_t value) {
            m_RegenSetPct_Rsp_ = value;
        }

        uint8_t& RegenAvail_St() OMG_NOEXCEPT {
            return m_RegenAvail_St_;
        }

        const uint8_t& RegenAvail_St() const OMG_NOEXCEPT {
            return m_RegenAvail_St_;
        }

        void RegenAvail_St(uint8_t value) {
            m_RegenAvail_St_ = value;
        }

        uint8_t& RegenForDisp_UI() OMG_NOEXCEPT {
            return m_RegenForDisp_UI_;
        }

        const uint8_t& RegenForDisp_UI() const OMG_NOEXCEPT {
            return m_RegenForDisp_UI_;
        }

        void RegenForDisp_UI(uint8_t value) {
            m_RegenForDisp_UI_ = value;
        }

        uint8_t& DrvVehModAvaliability_St() OMG_NOEXCEPT {
            return m_DrvVehModAvaliability_St_;
        }

        const uint8_t& DrvVehModAvaliability_St() const OMG_NOEXCEPT {
            return m_DrvVehModAvaliability_St_;
        }

        void DrvVehModAvaliability_St(uint8_t value) {
            m_DrvVehModAvaliability_St_ = value;
        }

        uint8_t& TrailMode_St() OMG_NOEXCEPT {
            return m_TrailMode_St_;
        }

        const uint8_t& TrailMode_St() const OMG_NOEXCEPT {
            return m_TrailMode_St_;
        }

        void TrailMode_St(uint8_t value) {
            m_TrailMode_St_ = value;
        }

        uint8_t& TrailAvaliability_St() OMG_NOEXCEPT {
            return m_TrailAvaliability_St_;
        }

        const uint8_t& TrailAvaliability_St() const OMG_NOEXCEPT {
            return m_TrailAvaliability_St_;
        }

        void TrailAvaliability_St(uint8_t value) {
            m_TrailAvaliability_St_ = value;
        }

        uint8_t& TrailForDisp_UI() OMG_NOEXCEPT {
            return m_TrailForDisp_UI_;
        }

        const uint8_t& TrailForDisp_UI() const OMG_NOEXCEPT {
            return m_TrailForDisp_UI_;
        }

        void TrailForDisp_UI(uint8_t value) {
            m_TrailForDisp_UI_ = value;
        }

        uint8_t& SaleMode_St() OMG_NOEXCEPT {
            return m_SaleMode_St_;
        }

        const uint8_t& SaleMode_St() const OMG_NOEXCEPT {
            return m_SaleMode_St_;
        }

        void SaleMode_St(uint8_t value) {
            m_SaleMode_St_ = value;
        }

        bool operator == (const DringMode_St_Struct& other_) const;
        bool operator != (const DringMode_St_Struct& other_) const;

        void swap(DringMode_St_Struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_DMSEPSModeInfo_St_;
        uint8_t m_DMSVehMode_St_;
        uint8_t m_DMSModeChgEn_St_;
        uint8_t m_DMSPTModeInfo_St_;
        uint8_t m_DMSValetMode_St_;
        uint8_t m_OnePedalMode_St_;
        uint8_t m_OPMAvaliability_St_;
        uint8_t m_RegenSetPct_Rsp_;
        uint8_t m_RegenAvail_St_;
        uint8_t m_RegenForDisp_UI_;
        uint8_t m_DrvVehModAvaliability_St_;
        uint8_t m_TrailMode_St_;
        uint8_t m_TrailAvaliability_St_;
        uint8_t m_TrailForDisp_UI_;
        uint8_t m_SaleMode_St_;

    };

    inline void swap(DringMode_St_Struct& a, DringMode_St_Struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DringMode_St_Struct& sample);

    class NDDSUSERDllExport VehicleMode_Srv_Req_Union {
      public:
        VehicleMode_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VehicleMode_Srv_Req_Union (VehicleMode_Srv_Req_Union&&) = default;
        VehicleMode_Srv_Req_Union& operator=(VehicleMode_Srv_Req_Union&&) = default;
        VehicleMode_Srv_Req_Union& operator=(const VehicleMode_Srv_Req_Union&) = default;
        VehicleMode_Srv_Req_Union(const VehicleMode_Srv_Req_Union&) = default;
        #else
        VehicleMode_Srv_Req_Union(VehicleMode_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        VehicleMode_Srv_Req_Union& operator=(VehicleMode_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        PTDomain::PowerMode_Ctrl_struct& PowerMode_Ctrl()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Req_Union::PowerMode_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_PowerMode_Ctrl_;
        }

        const PTDomain::PowerMode_Ctrl_struct& PowerMode_Ctrl() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Req_Union::PowerMode_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_PowerMode_Ctrl_;
        }

        void PowerMode_Ctrl(const PTDomain::PowerMode_Ctrl_struct& value) {
            m_u_.m_PowerMode_Ctrl_ = value;
            m_d_= 0;
        }

        void PowerMode_Ctrl(PTDomain::PowerMode_Ctrl_struct&& value) {
            m_u_.m_PowerMode_Ctrl_ = std::move(value);
            m_d_= 0;
        }
        PTDomain::CarMode_Ctrl_struct& CarMode_Ctrl()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Req_Union::CarMode_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_CarMode_Ctrl_;
        }

        const PTDomain::CarMode_Ctrl_struct& CarMode_Ctrl() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Req_Union::CarMode_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_CarMode_Ctrl_;
        }

        void CarMode_Ctrl(const PTDomain::CarMode_Ctrl_struct& value) {
            m_u_.m_CarMode_Ctrl_ = value;
            m_d_= 1;
        }

        void CarMode_Ctrl(PTDomain::CarMode_Ctrl_struct&& value) {
            m_u_.m_CarMode_Ctrl_ = std::move(value);
            m_d_= 1;
        }
        PTDomain::DrivingMode_Ctrl_struct& DrivingMode_Ctrl()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Req_Union::DrivingMode_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_DrivingMode_Ctrl_;
        }

        const PTDomain::DrivingMode_Ctrl_struct& DrivingMode_Ctrl() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Req_Union::DrivingMode_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_DrivingMode_Ctrl_;
        }

        void DrivingMode_Ctrl(const PTDomain::DrivingMode_Ctrl_struct& value) {
            m_u_.m_DrivingMode_Ctrl_ = value;
            m_d_= 2;
        }

        void DrivingMode_Ctrl(PTDomain::DrivingMode_Ctrl_struct&& value) {
            m_u_.m_DrivingMode_Ctrl_ = std::move(value);
            m_d_= 2;
        }

        bool operator == (const VehicleMode_Srv_Req_Union& other_) const;
        bool operator != (const VehicleMode_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(VehicleMode_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            PTDomain::PowerMode_Ctrl_struct m_PowerMode_Ctrl_;
            PTDomain::CarMode_Ctrl_struct m_CarMode_Ctrl_;
            PTDomain::DrivingMode_Ctrl_struct m_DrivingMode_Ctrl_;
            Union_();
            Union_(
                const PTDomain::PowerMode_Ctrl_struct& PowerMode_Ctrl,
                const PTDomain::CarMode_Ctrl_struct& CarMode_Ctrl,
                const PTDomain::DrivingMode_Ctrl_struct& DrivingMode_Ctrl);
        };
        Union_ m_u_;

    };

    inline void swap(VehicleMode_Srv_Req_Union& a, VehicleMode_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VehicleMode_Srv_Req_Union& sample);

    class NDDSUSERDllExport VehicleMode_Srv_Resp_Union {
      public:
        VehicleMode_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        VehicleMode_Srv_Resp_Union (VehicleMode_Srv_Resp_Union&&) = default;
        VehicleMode_Srv_Resp_Union& operator=(VehicleMode_Srv_Resp_Union&&) = default;
        VehicleMode_Srv_Resp_Union& operator=(const VehicleMode_Srv_Resp_Union&) = default;
        VehicleMode_Srv_Resp_Union(const VehicleMode_Srv_Resp_Union&) = default;
        #else
        VehicleMode_Srv_Resp_Union(VehicleMode_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        VehicleMode_Srv_Resp_Union& operator=(VehicleMode_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        PTDomain::PowerMode_Ctrl_SOA_struct& PowerMode_Ctrl_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Resp_Union::PowerMode_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_PowerMode_Ctrl_SOA_;
        }

        const PTDomain::PowerMode_Ctrl_SOA_struct& PowerMode_Ctrl_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Resp_Union::PowerMode_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_PowerMode_Ctrl_SOA_;
        }

        void PowerMode_Ctrl_SOA(const PTDomain::PowerMode_Ctrl_SOA_struct& value) {
            m_u_.m_PowerMode_Ctrl_SOA_ = value;
            m_d_= 0;
        }

        void PowerMode_Ctrl_SOA(PTDomain::PowerMode_Ctrl_SOA_struct&& value) {
            m_u_.m_PowerMode_Ctrl_SOA_ = std::move(value);
            m_d_= 0;
        }
        PTDomain::CarMode_Ctrl_SOA_struct& CarMode_Ctrl_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Resp_Union::CarMode_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_CarMode_Ctrl_SOA_;
        }

        const PTDomain::CarMode_Ctrl_SOA_struct& CarMode_Ctrl_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Resp_Union::CarMode_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_CarMode_Ctrl_SOA_;
        }

        void CarMode_Ctrl_SOA(const PTDomain::CarMode_Ctrl_SOA_struct& value) {
            m_u_.m_CarMode_Ctrl_SOA_ = value;
            m_d_= 1;
        }

        void CarMode_Ctrl_SOA(PTDomain::CarMode_Ctrl_SOA_struct&& value) {
            m_u_.m_CarMode_Ctrl_SOA_ = std::move(value);
            m_d_= 1;
        }
        PTDomain::DrivingMode_Ctrl_SOA_struct& DrivingMode_Ctrl_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Resp_Union::DrivingMode_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_DrivingMode_Ctrl_SOA_;
        }

        const PTDomain::DrivingMode_Ctrl_SOA_struct& DrivingMode_Ctrl_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "PTDomain::VehicleMode_Srv_Resp_Union::DrivingMode_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_DrivingMode_Ctrl_SOA_;
        }

        void DrivingMode_Ctrl_SOA(const PTDomain::DrivingMode_Ctrl_SOA_struct& value) {
            m_u_.m_DrivingMode_Ctrl_SOA_ = value;
            m_d_= 2;
        }

        void DrivingMode_Ctrl_SOA(PTDomain::DrivingMode_Ctrl_SOA_struct&& value) {
            m_u_.m_DrivingMode_Ctrl_SOA_ = std::move(value);
            m_d_= 2;
        }

        bool operator == (const VehicleMode_Srv_Resp_Union& other_) const;
        bool operator != (const VehicleMode_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(VehicleMode_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            PTDomain::PowerMode_Ctrl_SOA_struct m_PowerMode_Ctrl_SOA_;
            PTDomain::CarMode_Ctrl_SOA_struct m_CarMode_Ctrl_SOA_;
            PTDomain::DrivingMode_Ctrl_SOA_struct m_DrivingMode_Ctrl_SOA_;
            Union_();
            Union_(
                const PTDomain::PowerMode_Ctrl_SOA_struct& PowerMode_Ctrl_SOA,
                const PTDomain::CarMode_Ctrl_SOA_struct& CarMode_Ctrl_SOA,
                const PTDomain::DrivingMode_Ctrl_SOA_struct& DrivingMode_Ctrl_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(VehicleMode_Srv_Resp_Union& a, VehicleMode_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VehicleMode_Srv_Resp_Union& sample);

    class NDDSUSERDllExport CHS_Ctrl_struct {
      public:
        CHS_Ctrl_struct();

        CHS_Ctrl_struct(
            uint8_t HDCSw_Req,
            uint8_t EHBMBrkModeSet_Req,
            uint8_t CSTSw_Req,
            uint8_t TCSSw_Req,
            uint8_t AVHSw_Req,
            uint8_t ESCSw_Req,
            uint8_t ParkingSwitch_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        CHS_Ctrl_struct (CHS_Ctrl_struct&&) = default;
        CHS_Ctrl_struct& operator=(CHS_Ctrl_struct&&) = default;
        CHS_Ctrl_struct& operator=(const CHS_Ctrl_struct&) = default;
        CHS_Ctrl_struct(const CHS_Ctrl_struct&) = default;
        #else
        CHS_Ctrl_struct(CHS_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        CHS_Ctrl_struct& operator=(CHS_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& HDCSw_Req() OMG_NOEXCEPT {
            return m_HDCSw_Req_;
        }

        const uint8_t& HDCSw_Req() const OMG_NOEXCEPT {
            return m_HDCSw_Req_;
        }

        void HDCSw_Req(uint8_t value) {
            m_HDCSw_Req_ = value;
        }

        uint8_t& EHBMBrkModeSet_Req() OMG_NOEXCEPT {
            return m_EHBMBrkModeSet_Req_;
        }

        const uint8_t& EHBMBrkModeSet_Req() const OMG_NOEXCEPT {
            return m_EHBMBrkModeSet_Req_;
        }

        void EHBMBrkModeSet_Req(uint8_t value) {
            m_EHBMBrkModeSet_Req_ = value;
        }

        uint8_t& CSTSw_Req() OMG_NOEXCEPT {
            return m_CSTSw_Req_;
        }

        const uint8_t& CSTSw_Req() const OMG_NOEXCEPT {
            return m_CSTSw_Req_;
        }

        void CSTSw_Req(uint8_t value) {
            m_CSTSw_Req_ = value;
        }

        uint8_t& TCSSw_Req() OMG_NOEXCEPT {
            return m_TCSSw_Req_;
        }

        const uint8_t& TCSSw_Req() const OMG_NOEXCEPT {
            return m_TCSSw_Req_;
        }

        void TCSSw_Req(uint8_t value) {
            m_TCSSw_Req_ = value;
        }

        uint8_t& AVHSw_Req() OMG_NOEXCEPT {
            return m_AVHSw_Req_;
        }

        const uint8_t& AVHSw_Req() const OMG_NOEXCEPT {
            return m_AVHSw_Req_;
        }

        void AVHSw_Req(uint8_t value) {
            m_AVHSw_Req_ = value;
        }

        uint8_t& ESCSw_Req() OMG_NOEXCEPT {
            return m_ESCSw_Req_;
        }

        const uint8_t& ESCSw_Req() const OMG_NOEXCEPT {
            return m_ESCSw_Req_;
        }

        void ESCSw_Req(uint8_t value) {
            m_ESCSw_Req_ = value;
        }

        uint8_t& ParkingSwitch_Req() OMG_NOEXCEPT {
            return m_ParkingSwitch_Req_;
        }

        const uint8_t& ParkingSwitch_Req() const OMG_NOEXCEPT {
            return m_ParkingSwitch_Req_;
        }

        void ParkingSwitch_Req(uint8_t value) {
            m_ParkingSwitch_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const CHS_Ctrl_struct& other_) const;
        bool operator != (const CHS_Ctrl_struct& other_) const;

        void swap(CHS_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_HDCSw_Req_;
        uint8_t m_EHBMBrkModeSet_Req_;
        uint8_t m_CSTSw_Req_;
        uint8_t m_TCSSw_Req_;
        uint8_t m_AVHSw_Req_;
        uint8_t m_ESCSw_Req_;
        uint8_t m_ParkingSwitch_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(CHS_Ctrl_struct& a, CHS_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CHS_Ctrl_struct& sample);

    class NDDSUSERDllExport CHS_St_struct {
      public:
        CHS_St_struct();

        CHS_St_struct(
            uint8_t HDCAvail_St,
            uint8_t HDC_St,
            uint8_t BrakeModeEnable_St,
            uint8_t BrakeMode_St,
            uint8_t BoostDegrade_St,
            uint8_t CST_Rsp,
            uint8_t TCSSwAvail_St,
            uint8_t PataLamp_St,
            uint8_t AVHAvail_St,
            uint8_t AVH_St,
            uint8_t ESCSwAvail_St,
            uint8_t ESClamp_St,
            uint8_t EPB_St,
            uint8_t BU_EPB_St,
            uint8_t EPBSwAvail_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        CHS_St_struct (CHS_St_struct&&) = default;
        CHS_St_struct& operator=(CHS_St_struct&&) = default;
        CHS_St_struct& operator=(const CHS_St_struct&) = default;
        CHS_St_struct(const CHS_St_struct&) = default;
        #else
        CHS_St_struct(CHS_St_struct&& other_) OMG_NOEXCEPT;  
        CHS_St_struct& operator=(CHS_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& HDCAvail_St() OMG_NOEXCEPT {
            return m_HDCAvail_St_;
        }

        const uint8_t& HDCAvail_St() const OMG_NOEXCEPT {
            return m_HDCAvail_St_;
        }

        void HDCAvail_St(uint8_t value) {
            m_HDCAvail_St_ = value;
        }

        uint8_t& HDC_St() OMG_NOEXCEPT {
            return m_HDC_St_;
        }

        const uint8_t& HDC_St() const OMG_NOEXCEPT {
            return m_HDC_St_;
        }

        void HDC_St(uint8_t value) {
            m_HDC_St_ = value;
        }

        uint8_t& BrakeModeEnable_St() OMG_NOEXCEPT {
            return m_BrakeModeEnable_St_;
        }

        const uint8_t& BrakeModeEnable_St() const OMG_NOEXCEPT {
            return m_BrakeModeEnable_St_;
        }

        void BrakeModeEnable_St(uint8_t value) {
            m_BrakeModeEnable_St_ = value;
        }

        uint8_t& BrakeMode_St() OMG_NOEXCEPT {
            return m_BrakeMode_St_;
        }

        const uint8_t& BrakeMode_St() const OMG_NOEXCEPT {
            return m_BrakeMode_St_;
        }

        void BrakeMode_St(uint8_t value) {
            m_BrakeMode_St_ = value;
        }

        uint8_t& BoostDegrade_St() OMG_NOEXCEPT {
            return m_BoostDegrade_St_;
        }

        const uint8_t& BoostDegrade_St() const OMG_NOEXCEPT {
            return m_BoostDegrade_St_;
        }

        void BoostDegrade_St(uint8_t value) {
            m_BoostDegrade_St_ = value;
        }

        uint8_t& CST_Rsp() OMG_NOEXCEPT {
            return m_CST_Rsp_;
        }

        const uint8_t& CST_Rsp() const OMG_NOEXCEPT {
            return m_CST_Rsp_;
        }

        void CST_Rsp(uint8_t value) {
            m_CST_Rsp_ = value;
        }

        uint8_t& TCSSwAvail_St() OMG_NOEXCEPT {
            return m_TCSSwAvail_St_;
        }

        const uint8_t& TCSSwAvail_St() const OMG_NOEXCEPT {
            return m_TCSSwAvail_St_;
        }

        void TCSSwAvail_St(uint8_t value) {
            m_TCSSwAvail_St_ = value;
        }

        uint8_t& PataLamp_St() OMG_NOEXCEPT {
            return m_PataLamp_St_;
        }

        const uint8_t& PataLamp_St() const OMG_NOEXCEPT {
            return m_PataLamp_St_;
        }

        void PataLamp_St(uint8_t value) {
            m_PataLamp_St_ = value;
        }

        uint8_t& AVHAvail_St() OMG_NOEXCEPT {
            return m_AVHAvail_St_;
        }

        const uint8_t& AVHAvail_St() const OMG_NOEXCEPT {
            return m_AVHAvail_St_;
        }

        void AVHAvail_St(uint8_t value) {
            m_AVHAvail_St_ = value;
        }

        uint8_t& AVH_St() OMG_NOEXCEPT {
            return m_AVH_St_;
        }

        const uint8_t& AVH_St() const OMG_NOEXCEPT {
            return m_AVH_St_;
        }

        void AVH_St(uint8_t value) {
            m_AVH_St_ = value;
        }

        uint8_t& ESCSwAvail_St() OMG_NOEXCEPT {
            return m_ESCSwAvail_St_;
        }

        const uint8_t& ESCSwAvail_St() const OMG_NOEXCEPT {
            return m_ESCSwAvail_St_;
        }

        void ESCSwAvail_St(uint8_t value) {
            m_ESCSwAvail_St_ = value;
        }

        uint8_t& ESClamp_St() OMG_NOEXCEPT {
            return m_ESClamp_St_;
        }

        const uint8_t& ESClamp_St() const OMG_NOEXCEPT {
            return m_ESClamp_St_;
        }

        void ESClamp_St(uint8_t value) {
            m_ESClamp_St_ = value;
        }

        uint8_t& EPB_St() OMG_NOEXCEPT {
            return m_EPB_St_;
        }

        const uint8_t& EPB_St() const OMG_NOEXCEPT {
            return m_EPB_St_;
        }

        void EPB_St(uint8_t value) {
            m_EPB_St_ = value;
        }

        uint8_t& BU_EPB_St() OMG_NOEXCEPT {
            return m_BU_EPB_St_;
        }

        const uint8_t& BU_EPB_St() const OMG_NOEXCEPT {
            return m_BU_EPB_St_;
        }

        void BU_EPB_St(uint8_t value) {
            m_BU_EPB_St_ = value;
        }

        uint8_t& EPBSwAvail_St() OMG_NOEXCEPT {
            return m_EPBSwAvail_St_;
        }

        const uint8_t& EPBSwAvail_St() const OMG_NOEXCEPT {
            return m_EPBSwAvail_St_;
        }

        void EPBSwAvail_St(uint8_t value) {
            m_EPBSwAvail_St_ = value;
        }

        bool operator == (const CHS_St_struct& other_) const;
        bool operator != (const CHS_St_struct& other_) const;

        void swap(CHS_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_HDCAvail_St_;
        uint8_t m_HDC_St_;
        uint8_t m_BrakeModeEnable_St_;
        uint8_t m_BrakeMode_St_;
        uint8_t m_BoostDegrade_St_;
        uint8_t m_CST_Rsp_;
        uint8_t m_TCSSwAvail_St_;
        uint8_t m_PataLamp_St_;
        uint8_t m_AVHAvail_St_;
        uint8_t m_AVH_St_;
        uint8_t m_ESCSwAvail_St_;
        uint8_t m_ESClamp_St_;
        uint8_t m_EPB_St_;
        uint8_t m_BU_EPB_St_;
        uint8_t m_EPBSwAvail_St_;

    };

    inline void swap(CHS_St_struct& a, CHS_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CHS_St_struct& sample);

    class NDDSUSERDllExport CHS_Ctrl_SOA_struct {
      public:
        CHS_Ctrl_SOA_struct();

        explicit CHS_Ctrl_SOA_struct(
            uint8_t CHS_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        CHS_Ctrl_SOA_struct (CHS_Ctrl_SOA_struct&&) = default;
        CHS_Ctrl_SOA_struct& operator=(CHS_Ctrl_SOA_struct&&) = default;
        CHS_Ctrl_SOA_struct& operator=(const CHS_Ctrl_SOA_struct&) = default;
        CHS_Ctrl_SOA_struct(const CHS_Ctrl_SOA_struct&) = default;
        #else
        CHS_Ctrl_SOA_struct(CHS_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        CHS_Ctrl_SOA_struct& operator=(CHS_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& CHS_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_CHS_Ctrl_SOA_u8_;
        }

        const uint8_t& CHS_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_CHS_Ctrl_SOA_u8_;
        }

        void CHS_Ctrl_SOA_u8(uint8_t value) {
            m_CHS_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const CHS_Ctrl_SOA_struct& other_) const;
        bool operator != (const CHS_Ctrl_SOA_struct& other_) const;

        void swap(CHS_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_CHS_Ctrl_SOA_u8_;

    };

    inline void swap(CHS_Ctrl_SOA_struct& a, CHS_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CHS_Ctrl_SOA_struct& sample);

} // namespace PTDomain  
namespace EnergyDomain {

    class NDDSUSERDllExport AC_Ctrl_struct {
      public:
        AC_Ctrl_struct();

        AC_Ctrl_struct(
            uint8_t ACCycleMode_Req,
            uint8_t FACAirFlowLevel_Req,
            uint8_t FACMode_Req,
            uint8_t FACSwitch_Req,
            uint8_t FrontDeFrostFog_Req,
            uint8_t FLeftTempSet_Req,
            uint8_t FRightTempSet_Req,
            uint8_t FTempAreaSynd_Req,
            uint8_t FCoolOrHeatOrVent_Req,
            uint8_t ACOperationMode_Cmd,
            uint8_t FAutoAC_Req,
            uint8_t AirFragranceSwitchEnable,
            uint8_t FragranceConcentration_Req,
            uint8_t AirFragranceChannel1,
            uint8_t AirFragranceChannel2,
            uint8_t AirFragranceChannel3,
            uint8_t IONSet_Cmd,
            uint8_t PM25Set_Cmd,
            uint8_t AQSSet_Cmd,
            uint8_t FLeftAirOutletMode_Cmd,
            uint8_t FRightAirOutletMode_Cmd,
            uint8_t FLOutletSwitch_Cmd,
            uint8_t LCOutletSwitch_Cmd,
            uint8_t RCOutletSwitch_Cmd,
            uint8_t FROutletSwitch_Cmd,
            uint8_t FLOutletLeftRightAngle,
            uint8_t FLOutletUpDownAngle,
            uint8_t LCOutletUpDownAngle,
            uint8_t LCOutletLeftRightAngle,
            uint8_t RCOutletUpDownAngle,
            uint8_t RCOutletLeftRightAngle,
            uint8_t FROutletUpDownAngle,
            uint8_t FROutletLeftRightAngle,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        AC_Ctrl_struct (AC_Ctrl_struct&&) = default;
        AC_Ctrl_struct& operator=(AC_Ctrl_struct&&) = default;
        AC_Ctrl_struct& operator=(const AC_Ctrl_struct&) = default;
        AC_Ctrl_struct(const AC_Ctrl_struct&) = default;
        #else
        AC_Ctrl_struct(AC_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        AC_Ctrl_struct& operator=(AC_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& ACCycleMode_Req() OMG_NOEXCEPT {
            return m_ACCycleMode_Req_;
        }

        const uint8_t& ACCycleMode_Req() const OMG_NOEXCEPT {
            return m_ACCycleMode_Req_;
        }

        void ACCycleMode_Req(uint8_t value) {
            m_ACCycleMode_Req_ = value;
        }

        uint8_t& FACAirFlowLevel_Req() OMG_NOEXCEPT {
            return m_FACAirFlowLevel_Req_;
        }

        const uint8_t& FACAirFlowLevel_Req() const OMG_NOEXCEPT {
            return m_FACAirFlowLevel_Req_;
        }

        void FACAirFlowLevel_Req(uint8_t value) {
            m_FACAirFlowLevel_Req_ = value;
        }

        uint8_t& FACMode_Req() OMG_NOEXCEPT {
            return m_FACMode_Req_;
        }

        const uint8_t& FACMode_Req() const OMG_NOEXCEPT {
            return m_FACMode_Req_;
        }

        void FACMode_Req(uint8_t value) {
            m_FACMode_Req_ = value;
        }

        uint8_t& FACSwitch_Req() OMG_NOEXCEPT {
            return m_FACSwitch_Req_;
        }

        const uint8_t& FACSwitch_Req() const OMG_NOEXCEPT {
            return m_FACSwitch_Req_;
        }

        void FACSwitch_Req(uint8_t value) {
            m_FACSwitch_Req_ = value;
        }

        uint8_t& FrontDeFrostFog_Req() OMG_NOEXCEPT {
            return m_FrontDeFrostFog_Req_;
        }

        const uint8_t& FrontDeFrostFog_Req() const OMG_NOEXCEPT {
            return m_FrontDeFrostFog_Req_;
        }

        void FrontDeFrostFog_Req(uint8_t value) {
            m_FrontDeFrostFog_Req_ = value;
        }

        uint8_t& FLeftTempSet_Req() OMG_NOEXCEPT {
            return m_FLeftTempSet_Req_;
        }

        const uint8_t& FLeftTempSet_Req() const OMG_NOEXCEPT {
            return m_FLeftTempSet_Req_;
        }

        void FLeftTempSet_Req(uint8_t value) {
            m_FLeftTempSet_Req_ = value;
        }

        uint8_t& FRightTempSet_Req() OMG_NOEXCEPT {
            return m_FRightTempSet_Req_;
        }

        const uint8_t& FRightTempSet_Req() const OMG_NOEXCEPT {
            return m_FRightTempSet_Req_;
        }

        void FRightTempSet_Req(uint8_t value) {
            m_FRightTempSet_Req_ = value;
        }

        uint8_t& FTempAreaSynd_Req() OMG_NOEXCEPT {
            return m_FTempAreaSynd_Req_;
        }

        const uint8_t& FTempAreaSynd_Req() const OMG_NOEXCEPT {
            return m_FTempAreaSynd_Req_;
        }

        void FTempAreaSynd_Req(uint8_t value) {
            m_FTempAreaSynd_Req_ = value;
        }

        uint8_t& FCoolOrHeatOrVent_Req() OMG_NOEXCEPT {
            return m_FCoolOrHeatOrVent_Req_;
        }

        const uint8_t& FCoolOrHeatOrVent_Req() const OMG_NOEXCEPT {
            return m_FCoolOrHeatOrVent_Req_;
        }

        void FCoolOrHeatOrVent_Req(uint8_t value) {
            m_FCoolOrHeatOrVent_Req_ = value;
        }

        uint8_t& ACOperationMode_Cmd() OMG_NOEXCEPT {
            return m_ACOperationMode_Cmd_;
        }

        const uint8_t& ACOperationMode_Cmd() const OMG_NOEXCEPT {
            return m_ACOperationMode_Cmd_;
        }

        void ACOperationMode_Cmd(uint8_t value) {
            m_ACOperationMode_Cmd_ = value;
        }

        uint8_t& FAutoAC_Req() OMG_NOEXCEPT {
            return m_FAutoAC_Req_;
        }

        const uint8_t& FAutoAC_Req() const OMG_NOEXCEPT {
            return m_FAutoAC_Req_;
        }

        void FAutoAC_Req(uint8_t value) {
            m_FAutoAC_Req_ = value;
        }

        uint8_t& AirFragranceSwitchEnable() OMG_NOEXCEPT {
            return m_AirFragranceSwitchEnable_;
        }

        const uint8_t& AirFragranceSwitchEnable() const OMG_NOEXCEPT {
            return m_AirFragranceSwitchEnable_;
        }

        void AirFragranceSwitchEnable(uint8_t value) {
            m_AirFragranceSwitchEnable_ = value;
        }

        uint8_t& FragranceConcentration_Req() OMG_NOEXCEPT {
            return m_FragranceConcentration_Req_;
        }

        const uint8_t& FragranceConcentration_Req() const OMG_NOEXCEPT {
            return m_FragranceConcentration_Req_;
        }

        void FragranceConcentration_Req(uint8_t value) {
            m_FragranceConcentration_Req_ = value;
        }

        uint8_t& AirFragranceChannel1() OMG_NOEXCEPT {
            return m_AirFragranceChannel1_;
        }

        const uint8_t& AirFragranceChannel1() const OMG_NOEXCEPT {
            return m_AirFragranceChannel1_;
        }

        void AirFragranceChannel1(uint8_t value) {
            m_AirFragranceChannel1_ = value;
        }

        uint8_t& AirFragranceChannel2() OMG_NOEXCEPT {
            return m_AirFragranceChannel2_;
        }

        const uint8_t& AirFragranceChannel2() const OMG_NOEXCEPT {
            return m_AirFragranceChannel2_;
        }

        void AirFragranceChannel2(uint8_t value) {
            m_AirFragranceChannel2_ = value;
        }

        uint8_t& AirFragranceChannel3() OMG_NOEXCEPT {
            return m_AirFragranceChannel3_;
        }

        const uint8_t& AirFragranceChannel3() const OMG_NOEXCEPT {
            return m_AirFragranceChannel3_;
        }

        void AirFragranceChannel3(uint8_t value) {
            m_AirFragranceChannel3_ = value;
        }

        uint8_t& IONSet_Cmd() OMG_NOEXCEPT {
            return m_IONSet_Cmd_;
        }

        const uint8_t& IONSet_Cmd() const OMG_NOEXCEPT {
            return m_IONSet_Cmd_;
        }

        void IONSet_Cmd(uint8_t value) {
            m_IONSet_Cmd_ = value;
        }

        uint8_t& PM25Set_Cmd() OMG_NOEXCEPT {
            return m_PM25Set_Cmd_;
        }

        const uint8_t& PM25Set_Cmd() const OMG_NOEXCEPT {
            return m_PM25Set_Cmd_;
        }

        void PM25Set_Cmd(uint8_t value) {
            m_PM25Set_Cmd_ = value;
        }

        uint8_t& AQSSet_Cmd() OMG_NOEXCEPT {
            return m_AQSSet_Cmd_;
        }

        const uint8_t& AQSSet_Cmd() const OMG_NOEXCEPT {
            return m_AQSSet_Cmd_;
        }

        void AQSSet_Cmd(uint8_t value) {
            m_AQSSet_Cmd_ = value;
        }

        uint8_t& FLeftAirOutletMode_Cmd() OMG_NOEXCEPT {
            return m_FLeftAirOutletMode_Cmd_;
        }

        const uint8_t& FLeftAirOutletMode_Cmd() const OMG_NOEXCEPT {
            return m_FLeftAirOutletMode_Cmd_;
        }

        void FLeftAirOutletMode_Cmd(uint8_t value) {
            m_FLeftAirOutletMode_Cmd_ = value;
        }

        uint8_t& FRightAirOutletMode_Cmd() OMG_NOEXCEPT {
            return m_FRightAirOutletMode_Cmd_;
        }

        const uint8_t& FRightAirOutletMode_Cmd() const OMG_NOEXCEPT {
            return m_FRightAirOutletMode_Cmd_;
        }

        void FRightAirOutletMode_Cmd(uint8_t value) {
            m_FRightAirOutletMode_Cmd_ = value;
        }

        uint8_t& FLOutletSwitch_Cmd() OMG_NOEXCEPT {
            return m_FLOutletSwitch_Cmd_;
        }

        const uint8_t& FLOutletSwitch_Cmd() const OMG_NOEXCEPT {
            return m_FLOutletSwitch_Cmd_;
        }

        void FLOutletSwitch_Cmd(uint8_t value) {
            m_FLOutletSwitch_Cmd_ = value;
        }

        uint8_t& LCOutletSwitch_Cmd() OMG_NOEXCEPT {
            return m_LCOutletSwitch_Cmd_;
        }

        const uint8_t& LCOutletSwitch_Cmd() const OMG_NOEXCEPT {
            return m_LCOutletSwitch_Cmd_;
        }

        void LCOutletSwitch_Cmd(uint8_t value) {
            m_LCOutletSwitch_Cmd_ = value;
        }

        uint8_t& RCOutletSwitch_Cmd() OMG_NOEXCEPT {
            return m_RCOutletSwitch_Cmd_;
        }

        const uint8_t& RCOutletSwitch_Cmd() const OMG_NOEXCEPT {
            return m_RCOutletSwitch_Cmd_;
        }

        void RCOutletSwitch_Cmd(uint8_t value) {
            m_RCOutletSwitch_Cmd_ = value;
        }

        uint8_t& FROutletSwitch_Cmd() OMG_NOEXCEPT {
            return m_FROutletSwitch_Cmd_;
        }

        const uint8_t& FROutletSwitch_Cmd() const OMG_NOEXCEPT {
            return m_FROutletSwitch_Cmd_;
        }

        void FROutletSwitch_Cmd(uint8_t value) {
            m_FROutletSwitch_Cmd_ = value;
        }

        uint8_t& FLOutletLeftRightAngle() OMG_NOEXCEPT {
            return m_FLOutletLeftRightAngle_;
        }

        const uint8_t& FLOutletLeftRightAngle() const OMG_NOEXCEPT {
            return m_FLOutletLeftRightAngle_;
        }

        void FLOutletLeftRightAngle(uint8_t value) {
            m_FLOutletLeftRightAngle_ = value;
        }

        uint8_t& FLOutletUpDownAngle() OMG_NOEXCEPT {
            return m_FLOutletUpDownAngle_;
        }

        const uint8_t& FLOutletUpDownAngle() const OMG_NOEXCEPT {
            return m_FLOutletUpDownAngle_;
        }

        void FLOutletUpDownAngle(uint8_t value) {
            m_FLOutletUpDownAngle_ = value;
        }

        uint8_t& LCOutletUpDownAngle() OMG_NOEXCEPT {
            return m_LCOutletUpDownAngle_;
        }

        const uint8_t& LCOutletUpDownAngle() const OMG_NOEXCEPT {
            return m_LCOutletUpDownAngle_;
        }

        void LCOutletUpDownAngle(uint8_t value) {
            m_LCOutletUpDownAngle_ = value;
        }

        uint8_t& LCOutletLeftRightAngle() OMG_NOEXCEPT {
            return m_LCOutletLeftRightAngle_;
        }

        const uint8_t& LCOutletLeftRightAngle() const OMG_NOEXCEPT {
            return m_LCOutletLeftRightAngle_;
        }

        void LCOutletLeftRightAngle(uint8_t value) {
            m_LCOutletLeftRightAngle_ = value;
        }

        uint8_t& RCOutletUpDownAngle() OMG_NOEXCEPT {
            return m_RCOutletUpDownAngle_;
        }

        const uint8_t& RCOutletUpDownAngle() const OMG_NOEXCEPT {
            return m_RCOutletUpDownAngle_;
        }

        void RCOutletUpDownAngle(uint8_t value) {
            m_RCOutletUpDownAngle_ = value;
        }

        uint8_t& RCOutletLeftRightAngle() OMG_NOEXCEPT {
            return m_RCOutletLeftRightAngle_;
        }

        const uint8_t& RCOutletLeftRightAngle() const OMG_NOEXCEPT {
            return m_RCOutletLeftRightAngle_;
        }

        void RCOutletLeftRightAngle(uint8_t value) {
            m_RCOutletLeftRightAngle_ = value;
        }

        uint8_t& FROutletUpDownAngle() OMG_NOEXCEPT {
            return m_FROutletUpDownAngle_;
        }

        const uint8_t& FROutletUpDownAngle() const OMG_NOEXCEPT {
            return m_FROutletUpDownAngle_;
        }

        void FROutletUpDownAngle(uint8_t value) {
            m_FROutletUpDownAngle_ = value;
        }

        uint8_t& FROutletLeftRightAngle() OMG_NOEXCEPT {
            return m_FROutletLeftRightAngle_;
        }

        const uint8_t& FROutletLeftRightAngle() const OMG_NOEXCEPT {
            return m_FROutletLeftRightAngle_;
        }

        void FROutletLeftRightAngle(uint8_t value) {
            m_FROutletLeftRightAngle_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const AC_Ctrl_struct& other_) const;
        bool operator != (const AC_Ctrl_struct& other_) const;

        void swap(AC_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_ACCycleMode_Req_;
        uint8_t m_FACAirFlowLevel_Req_;
        uint8_t m_FACMode_Req_;
        uint8_t m_FACSwitch_Req_;
        uint8_t m_FrontDeFrostFog_Req_;
        uint8_t m_FLeftTempSet_Req_;
        uint8_t m_FRightTempSet_Req_;
        uint8_t m_FTempAreaSynd_Req_;
        uint8_t m_FCoolOrHeatOrVent_Req_;
        uint8_t m_ACOperationMode_Cmd_;
        uint8_t m_FAutoAC_Req_;
        uint8_t m_AirFragranceSwitchEnable_;
        uint8_t m_FragranceConcentration_Req_;
        uint8_t m_AirFragranceChannel1_;
        uint8_t m_AirFragranceChannel2_;
        uint8_t m_AirFragranceChannel3_;
        uint8_t m_IONSet_Cmd_;
        uint8_t m_PM25Set_Cmd_;
        uint8_t m_AQSSet_Cmd_;
        uint8_t m_FLeftAirOutletMode_Cmd_;
        uint8_t m_FRightAirOutletMode_Cmd_;
        uint8_t m_FLOutletSwitch_Cmd_;
        uint8_t m_LCOutletSwitch_Cmd_;
        uint8_t m_RCOutletSwitch_Cmd_;
        uint8_t m_FROutletSwitch_Cmd_;
        uint8_t m_FLOutletLeftRightAngle_;
        uint8_t m_FLOutletUpDownAngle_;
        uint8_t m_LCOutletUpDownAngle_;
        uint8_t m_LCOutletLeftRightAngle_;
        uint8_t m_RCOutletUpDownAngle_;
        uint8_t m_RCOutletLeftRightAngle_;
        uint8_t m_FROutletUpDownAngle_;
        uint8_t m_FROutletLeftRightAngle_;
        std::string m_CtrlSource_;

    };

    inline void swap(AC_Ctrl_struct& a, AC_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const AC_Ctrl_struct& sample);

    class NDDSUSERDllExport AC_St_struct {
      public:
        AC_St_struct();

        AC_St_struct(
            uint8_t ACCycleMode_St,
            uint8_t FACAirFlowLevel_St,
            uint8_t FACMode_St,
            uint8_t FACSwitch_Rsp,
            uint8_t FDeiceDefrost_Rsp,
            uint8_t FLeftTempSet_St,
            uint8_t FRightTempSet_St,
            uint8_t FTempAreaSync_St,
            uint8_t FAcCoolOrHeatOrVent_St,
            uint8_t ACOperateMode_St,
            uint8_t FACAuto_Rsp,
            uint8_t FACAirFlowLevelAuto_St,
            uint8_t FACAirFlowModeAuto_St,
            uint8_t FACCoolOrHeatOrVentAuto_St,
            uint8_t EnvirTemp_Val,
            uint8_t FragSwitchEN_Rsp,
            uint8_t FragConcLevel_Rsp,
            uint8_t FragChannel1Switch_St,
            uint8_t FragChannel2Switch_St,
            uint8_t FragChannel3Switch_St,
            uint8_t FragChannelType,
            uint8_t FragChannelIndex,
            uint16_t FragChannel1Life,
            uint16_t FragChannel2Life,
            uint16_t FragChannel3Life,
            uint8_t IONSet_St,
            uint8_t PM25Set_St,
            uint8_t PM25Trigger_St,
            uint16_t PM25CarConc,
            uint8_t AQSSet_St,
            uint8_t AQSTrigger_St,
            uint8_t AQSAirQuality_Val,
            uint8_t InFilterLifeRemind,
            uint8_t OutsideFilterLifeRemind,
            uint8_t FLeftAirOutletMode_St,
            uint8_t FRightAirOutletMode_St,
            uint8_t OLMFLAirOutletSwitch_Rsp,
            uint8_t OLMLCAirOutletSwitch_Rsp,
            uint8_t OLMRCAirOutletSwitch_Rsp,
            uint8_t OLMFRAirOutletSwitch_Rsp,
            uint8_t OLMFLMotorErrSt,
            uint8_t OLMLCMotorErrSt,
            uint8_t OLMRCMotorErrSt,
            uint8_t OLMFRMotorErrSt,
            uint8_t OLMFLAirOutletLeftRightAngle_Rsp,
            uint8_t OLMFLAirOutletUpDownAngle_Rsp,
            uint8_t OLMLCAirOutletUpDownAngle_Rsp,
            uint8_t OLMLCAirOutletLeftRightAngle_Rsp,
            uint8_t OLMRCAirOutletLeftRightAngle_Rsp,
            uint8_t OLMRCAirOutletUpDownAngle_Rsp,
            uint8_t OLMFRAirOutletUpDownAngle_Rsp,
            uint8_t OLMFRAirOutletLeftRightAngle_Rsp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        AC_St_struct (AC_St_struct&&) = default;
        AC_St_struct& operator=(AC_St_struct&&) = default;
        AC_St_struct& operator=(const AC_St_struct&) = default;
        AC_St_struct(const AC_St_struct&) = default;
        #else
        AC_St_struct(AC_St_struct&& other_) OMG_NOEXCEPT;  
        AC_St_struct& operator=(AC_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& ACCycleMode_St() OMG_NOEXCEPT {
            return m_ACCycleMode_St_;
        }

        const uint8_t& ACCycleMode_St() const OMG_NOEXCEPT {
            return m_ACCycleMode_St_;
        }

        void ACCycleMode_St(uint8_t value) {
            m_ACCycleMode_St_ = value;
        }

        uint8_t& FACAirFlowLevel_St() OMG_NOEXCEPT {
            return m_FACAirFlowLevel_St_;
        }

        const uint8_t& FACAirFlowLevel_St() const OMG_NOEXCEPT {
            return m_FACAirFlowLevel_St_;
        }

        void FACAirFlowLevel_St(uint8_t value) {
            m_FACAirFlowLevel_St_ = value;
        }

        uint8_t& FACMode_St() OMG_NOEXCEPT {
            return m_FACMode_St_;
        }

        const uint8_t& FACMode_St() const OMG_NOEXCEPT {
            return m_FACMode_St_;
        }

        void FACMode_St(uint8_t value) {
            m_FACMode_St_ = value;
        }

        uint8_t& FACSwitch_Rsp() OMG_NOEXCEPT {
            return m_FACSwitch_Rsp_;
        }

        const uint8_t& FACSwitch_Rsp() const OMG_NOEXCEPT {
            return m_FACSwitch_Rsp_;
        }

        void FACSwitch_Rsp(uint8_t value) {
            m_FACSwitch_Rsp_ = value;
        }

        uint8_t& FDeiceDefrost_Rsp() OMG_NOEXCEPT {
            return m_FDeiceDefrost_Rsp_;
        }

        const uint8_t& FDeiceDefrost_Rsp() const OMG_NOEXCEPT {
            return m_FDeiceDefrost_Rsp_;
        }

        void FDeiceDefrost_Rsp(uint8_t value) {
            m_FDeiceDefrost_Rsp_ = value;
        }

        uint8_t& FLeftTempSet_St() OMG_NOEXCEPT {
            return m_FLeftTempSet_St_;
        }

        const uint8_t& FLeftTempSet_St() const OMG_NOEXCEPT {
            return m_FLeftTempSet_St_;
        }

        void FLeftTempSet_St(uint8_t value) {
            m_FLeftTempSet_St_ = value;
        }

        uint8_t& FRightTempSet_St() OMG_NOEXCEPT {
            return m_FRightTempSet_St_;
        }

        const uint8_t& FRightTempSet_St() const OMG_NOEXCEPT {
            return m_FRightTempSet_St_;
        }

        void FRightTempSet_St(uint8_t value) {
            m_FRightTempSet_St_ = value;
        }

        uint8_t& FTempAreaSync_St() OMG_NOEXCEPT {
            return m_FTempAreaSync_St_;
        }

        const uint8_t& FTempAreaSync_St() const OMG_NOEXCEPT {
            return m_FTempAreaSync_St_;
        }

        void FTempAreaSync_St(uint8_t value) {
            m_FTempAreaSync_St_ = value;
        }

        uint8_t& FAcCoolOrHeatOrVent_St() OMG_NOEXCEPT {
            return m_FAcCoolOrHeatOrVent_St_;
        }

        const uint8_t& FAcCoolOrHeatOrVent_St() const OMG_NOEXCEPT {
            return m_FAcCoolOrHeatOrVent_St_;
        }

        void FAcCoolOrHeatOrVent_St(uint8_t value) {
            m_FAcCoolOrHeatOrVent_St_ = value;
        }

        uint8_t& ACOperateMode_St() OMG_NOEXCEPT {
            return m_ACOperateMode_St_;
        }

        const uint8_t& ACOperateMode_St() const OMG_NOEXCEPT {
            return m_ACOperateMode_St_;
        }

        void ACOperateMode_St(uint8_t value) {
            m_ACOperateMode_St_ = value;
        }

        uint8_t& FACAuto_Rsp() OMG_NOEXCEPT {
            return m_FACAuto_Rsp_;
        }

        const uint8_t& FACAuto_Rsp() const OMG_NOEXCEPT {
            return m_FACAuto_Rsp_;
        }

        void FACAuto_Rsp(uint8_t value) {
            m_FACAuto_Rsp_ = value;
        }

        uint8_t& FACAirFlowLevelAuto_St() OMG_NOEXCEPT {
            return m_FACAirFlowLevelAuto_St_;
        }

        const uint8_t& FACAirFlowLevelAuto_St() const OMG_NOEXCEPT {
            return m_FACAirFlowLevelAuto_St_;
        }

        void FACAirFlowLevelAuto_St(uint8_t value) {
            m_FACAirFlowLevelAuto_St_ = value;
        }

        uint8_t& FACAirFlowModeAuto_St() OMG_NOEXCEPT {
            return m_FACAirFlowModeAuto_St_;
        }

        const uint8_t& FACAirFlowModeAuto_St() const OMG_NOEXCEPT {
            return m_FACAirFlowModeAuto_St_;
        }

        void FACAirFlowModeAuto_St(uint8_t value) {
            m_FACAirFlowModeAuto_St_ = value;
        }

        uint8_t& FACCoolOrHeatOrVentAuto_St() OMG_NOEXCEPT {
            return m_FACCoolOrHeatOrVentAuto_St_;
        }

        const uint8_t& FACCoolOrHeatOrVentAuto_St() const OMG_NOEXCEPT {
            return m_FACCoolOrHeatOrVentAuto_St_;
        }

        void FACCoolOrHeatOrVentAuto_St(uint8_t value) {
            m_FACCoolOrHeatOrVentAuto_St_ = value;
        }

        uint8_t& EnvirTemp_Val() OMG_NOEXCEPT {
            return m_EnvirTemp_Val_;
        }

        const uint8_t& EnvirTemp_Val() const OMG_NOEXCEPT {
            return m_EnvirTemp_Val_;
        }

        void EnvirTemp_Val(uint8_t value) {
            m_EnvirTemp_Val_ = value;
        }

        uint8_t& FragSwitchEN_Rsp() OMG_NOEXCEPT {
            return m_FragSwitchEN_Rsp_;
        }

        const uint8_t& FragSwitchEN_Rsp() const OMG_NOEXCEPT {
            return m_FragSwitchEN_Rsp_;
        }

        void FragSwitchEN_Rsp(uint8_t value) {
            m_FragSwitchEN_Rsp_ = value;
        }

        uint8_t& FragConcLevel_Rsp() OMG_NOEXCEPT {
            return m_FragConcLevel_Rsp_;
        }

        const uint8_t& FragConcLevel_Rsp() const OMG_NOEXCEPT {
            return m_FragConcLevel_Rsp_;
        }

        void FragConcLevel_Rsp(uint8_t value) {
            m_FragConcLevel_Rsp_ = value;
        }

        uint8_t& FragChannel1Switch_St() OMG_NOEXCEPT {
            return m_FragChannel1Switch_St_;
        }

        const uint8_t& FragChannel1Switch_St() const OMG_NOEXCEPT {
            return m_FragChannel1Switch_St_;
        }

        void FragChannel1Switch_St(uint8_t value) {
            m_FragChannel1Switch_St_ = value;
        }

        uint8_t& FragChannel2Switch_St() OMG_NOEXCEPT {
            return m_FragChannel2Switch_St_;
        }

        const uint8_t& FragChannel2Switch_St() const OMG_NOEXCEPT {
            return m_FragChannel2Switch_St_;
        }

        void FragChannel2Switch_St(uint8_t value) {
            m_FragChannel2Switch_St_ = value;
        }

        uint8_t& FragChannel3Switch_St() OMG_NOEXCEPT {
            return m_FragChannel3Switch_St_;
        }

        const uint8_t& FragChannel3Switch_St() const OMG_NOEXCEPT {
            return m_FragChannel3Switch_St_;
        }

        void FragChannel3Switch_St(uint8_t value) {
            m_FragChannel3Switch_St_ = value;
        }

        uint8_t& FragChannelType() OMG_NOEXCEPT {
            return m_FragChannelType_;
        }

        const uint8_t& FragChannelType() const OMG_NOEXCEPT {
            return m_FragChannelType_;
        }

        void FragChannelType(uint8_t value) {
            m_FragChannelType_ = value;
        }

        uint8_t& FragChannelIndex() OMG_NOEXCEPT {
            return m_FragChannelIndex_;
        }

        const uint8_t& FragChannelIndex() const OMG_NOEXCEPT {
            return m_FragChannelIndex_;
        }

        void FragChannelIndex(uint8_t value) {
            m_FragChannelIndex_ = value;
        }

        uint16_t& FragChannel1Life() OMG_NOEXCEPT {
            return m_FragChannel1Life_;
        }

        const uint16_t& FragChannel1Life() const OMG_NOEXCEPT {
            return m_FragChannel1Life_;
        }

        void FragChannel1Life(uint16_t value) {
            m_FragChannel1Life_ = value;
        }

        uint16_t& FragChannel2Life() OMG_NOEXCEPT {
            return m_FragChannel2Life_;
        }

        const uint16_t& FragChannel2Life() const OMG_NOEXCEPT {
            return m_FragChannel2Life_;
        }

        void FragChannel2Life(uint16_t value) {
            m_FragChannel2Life_ = value;
        }

        uint16_t& FragChannel3Life() OMG_NOEXCEPT {
            return m_FragChannel3Life_;
        }

        const uint16_t& FragChannel3Life() const OMG_NOEXCEPT {
            return m_FragChannel3Life_;
        }

        void FragChannel3Life(uint16_t value) {
            m_FragChannel3Life_ = value;
        }

        uint8_t& IONSet_St() OMG_NOEXCEPT {
            return m_IONSet_St_;
        }

        const uint8_t& IONSet_St() const OMG_NOEXCEPT {
            return m_IONSet_St_;
        }

        void IONSet_St(uint8_t value) {
            m_IONSet_St_ = value;
        }

        uint8_t& PM25Set_St() OMG_NOEXCEPT {
            return m_PM25Set_St_;
        }

        const uint8_t& PM25Set_St() const OMG_NOEXCEPT {
            return m_PM25Set_St_;
        }

        void PM25Set_St(uint8_t value) {
            m_PM25Set_St_ = value;
        }

        uint8_t& PM25Trigger_St() OMG_NOEXCEPT {
            return m_PM25Trigger_St_;
        }

        const uint8_t& PM25Trigger_St() const OMG_NOEXCEPT {
            return m_PM25Trigger_St_;
        }

        void PM25Trigger_St(uint8_t value) {
            m_PM25Trigger_St_ = value;
        }

        uint16_t& PM25CarConc() OMG_NOEXCEPT {
            return m_PM25CarConc_;
        }

        const uint16_t& PM25CarConc() const OMG_NOEXCEPT {
            return m_PM25CarConc_;
        }

        void PM25CarConc(uint16_t value) {
            m_PM25CarConc_ = value;
        }

        uint8_t& AQSSet_St() OMG_NOEXCEPT {
            return m_AQSSet_St_;
        }

        const uint8_t& AQSSet_St() const OMG_NOEXCEPT {
            return m_AQSSet_St_;
        }

        void AQSSet_St(uint8_t value) {
            m_AQSSet_St_ = value;
        }

        uint8_t& AQSTrigger_St() OMG_NOEXCEPT {
            return m_AQSTrigger_St_;
        }

        const uint8_t& AQSTrigger_St() const OMG_NOEXCEPT {
            return m_AQSTrigger_St_;
        }

        void AQSTrigger_St(uint8_t value) {
            m_AQSTrigger_St_ = value;
        }

        uint8_t& AQSAirQuality_Val() OMG_NOEXCEPT {
            return m_AQSAirQuality_Val_;
        }

        const uint8_t& AQSAirQuality_Val() const OMG_NOEXCEPT {
            return m_AQSAirQuality_Val_;
        }

        void AQSAirQuality_Val(uint8_t value) {
            m_AQSAirQuality_Val_ = value;
        }

        uint8_t& InFilterLifeRemind() OMG_NOEXCEPT {
            return m_InFilterLifeRemind_;
        }

        const uint8_t& InFilterLifeRemind() const OMG_NOEXCEPT {
            return m_InFilterLifeRemind_;
        }

        void InFilterLifeRemind(uint8_t value) {
            m_InFilterLifeRemind_ = value;
        }

        uint8_t& OutsideFilterLifeRemind() OMG_NOEXCEPT {
            return m_OutsideFilterLifeRemind_;
        }

        const uint8_t& OutsideFilterLifeRemind() const OMG_NOEXCEPT {
            return m_OutsideFilterLifeRemind_;
        }

        void OutsideFilterLifeRemind(uint8_t value) {
            m_OutsideFilterLifeRemind_ = value;
        }

        uint8_t& FLeftAirOutletMode_St() OMG_NOEXCEPT {
            return m_FLeftAirOutletMode_St_;
        }

        const uint8_t& FLeftAirOutletMode_St() const OMG_NOEXCEPT {
            return m_FLeftAirOutletMode_St_;
        }

        void FLeftAirOutletMode_St(uint8_t value) {
            m_FLeftAirOutletMode_St_ = value;
        }

        uint8_t& FRightAirOutletMode_St() OMG_NOEXCEPT {
            return m_FRightAirOutletMode_St_;
        }

        const uint8_t& FRightAirOutletMode_St() const OMG_NOEXCEPT {
            return m_FRightAirOutletMode_St_;
        }

        void FRightAirOutletMode_St(uint8_t value) {
            m_FRightAirOutletMode_St_ = value;
        }

        uint8_t& OLMFLAirOutletSwitch_Rsp() OMG_NOEXCEPT {
            return m_OLMFLAirOutletSwitch_Rsp_;
        }

        const uint8_t& OLMFLAirOutletSwitch_Rsp() const OMG_NOEXCEPT {
            return m_OLMFLAirOutletSwitch_Rsp_;
        }

        void OLMFLAirOutletSwitch_Rsp(uint8_t value) {
            m_OLMFLAirOutletSwitch_Rsp_ = value;
        }

        uint8_t& OLMLCAirOutletSwitch_Rsp() OMG_NOEXCEPT {
            return m_OLMLCAirOutletSwitch_Rsp_;
        }

        const uint8_t& OLMLCAirOutletSwitch_Rsp() const OMG_NOEXCEPT {
            return m_OLMLCAirOutletSwitch_Rsp_;
        }

        void OLMLCAirOutletSwitch_Rsp(uint8_t value) {
            m_OLMLCAirOutletSwitch_Rsp_ = value;
        }

        uint8_t& OLMRCAirOutletSwitch_Rsp() OMG_NOEXCEPT {
            return m_OLMRCAirOutletSwitch_Rsp_;
        }

        const uint8_t& OLMRCAirOutletSwitch_Rsp() const OMG_NOEXCEPT {
            return m_OLMRCAirOutletSwitch_Rsp_;
        }

        void OLMRCAirOutletSwitch_Rsp(uint8_t value) {
            m_OLMRCAirOutletSwitch_Rsp_ = value;
        }

        uint8_t& OLMFRAirOutletSwitch_Rsp() OMG_NOEXCEPT {
            return m_OLMFRAirOutletSwitch_Rsp_;
        }

        const uint8_t& OLMFRAirOutletSwitch_Rsp() const OMG_NOEXCEPT {
            return m_OLMFRAirOutletSwitch_Rsp_;
        }

        void OLMFRAirOutletSwitch_Rsp(uint8_t value) {
            m_OLMFRAirOutletSwitch_Rsp_ = value;
        }

        uint8_t& OLMFLMotorErrSt() OMG_NOEXCEPT {
            return m_OLMFLMotorErrSt_;
        }

        const uint8_t& OLMFLMotorErrSt() const OMG_NOEXCEPT {
            return m_OLMFLMotorErrSt_;
        }

        void OLMFLMotorErrSt(uint8_t value) {
            m_OLMFLMotorErrSt_ = value;
        }

        uint8_t& OLMLCMotorErrSt() OMG_NOEXCEPT {
            return m_OLMLCMotorErrSt_;
        }

        const uint8_t& OLMLCMotorErrSt() const OMG_NOEXCEPT {
            return m_OLMLCMotorErrSt_;
        }

        void OLMLCMotorErrSt(uint8_t value) {
            m_OLMLCMotorErrSt_ = value;
        }

        uint8_t& OLMRCMotorErrSt() OMG_NOEXCEPT {
            return m_OLMRCMotorErrSt_;
        }

        const uint8_t& OLMRCMotorErrSt() const OMG_NOEXCEPT {
            return m_OLMRCMotorErrSt_;
        }

        void OLMRCMotorErrSt(uint8_t value) {
            m_OLMRCMotorErrSt_ = value;
        }

        uint8_t& OLMFRMotorErrSt() OMG_NOEXCEPT {
            return m_OLMFRMotorErrSt_;
        }

        const uint8_t& OLMFRMotorErrSt() const OMG_NOEXCEPT {
            return m_OLMFRMotorErrSt_;
        }

        void OLMFRMotorErrSt(uint8_t value) {
            m_OLMFRMotorErrSt_ = value;
        }

        uint8_t& OLMFLAirOutletLeftRightAngle_Rsp() OMG_NOEXCEPT {
            return m_OLMFLAirOutletLeftRightAngle_Rsp_;
        }

        const uint8_t& OLMFLAirOutletLeftRightAngle_Rsp() const OMG_NOEXCEPT {
            return m_OLMFLAirOutletLeftRightAngle_Rsp_;
        }

        void OLMFLAirOutletLeftRightAngle_Rsp(uint8_t value) {
            m_OLMFLAirOutletLeftRightAngle_Rsp_ = value;
        }

        uint8_t& OLMFLAirOutletUpDownAngle_Rsp() OMG_NOEXCEPT {
            return m_OLMFLAirOutletUpDownAngle_Rsp_;
        }

        const uint8_t& OLMFLAirOutletUpDownAngle_Rsp() const OMG_NOEXCEPT {
            return m_OLMFLAirOutletUpDownAngle_Rsp_;
        }

        void OLMFLAirOutletUpDownAngle_Rsp(uint8_t value) {
            m_OLMFLAirOutletUpDownAngle_Rsp_ = value;
        }

        uint8_t& OLMLCAirOutletUpDownAngle_Rsp() OMG_NOEXCEPT {
            return m_OLMLCAirOutletUpDownAngle_Rsp_;
        }

        const uint8_t& OLMLCAirOutletUpDownAngle_Rsp() const OMG_NOEXCEPT {
            return m_OLMLCAirOutletUpDownAngle_Rsp_;
        }

        void OLMLCAirOutletUpDownAngle_Rsp(uint8_t value) {
            m_OLMLCAirOutletUpDownAngle_Rsp_ = value;
        }

        uint8_t& OLMLCAirOutletLeftRightAngle_Rsp() OMG_NOEXCEPT {
            return m_OLMLCAirOutletLeftRightAngle_Rsp_;
        }

        const uint8_t& OLMLCAirOutletLeftRightAngle_Rsp() const OMG_NOEXCEPT {
            return m_OLMLCAirOutletLeftRightAngle_Rsp_;
        }

        void OLMLCAirOutletLeftRightAngle_Rsp(uint8_t value) {
            m_OLMLCAirOutletLeftRightAngle_Rsp_ = value;
        }

        uint8_t& OLMRCAirOutletLeftRightAngle_Rsp() OMG_NOEXCEPT {
            return m_OLMRCAirOutletLeftRightAngle_Rsp_;
        }

        const uint8_t& OLMRCAirOutletLeftRightAngle_Rsp() const OMG_NOEXCEPT {
            return m_OLMRCAirOutletLeftRightAngle_Rsp_;
        }

        void OLMRCAirOutletLeftRightAngle_Rsp(uint8_t value) {
            m_OLMRCAirOutletLeftRightAngle_Rsp_ = value;
        }

        uint8_t& OLMRCAirOutletUpDownAngle_Rsp() OMG_NOEXCEPT {
            return m_OLMRCAirOutletUpDownAngle_Rsp_;
        }

        const uint8_t& OLMRCAirOutletUpDownAngle_Rsp() const OMG_NOEXCEPT {
            return m_OLMRCAirOutletUpDownAngle_Rsp_;
        }

        void OLMRCAirOutletUpDownAngle_Rsp(uint8_t value) {
            m_OLMRCAirOutletUpDownAngle_Rsp_ = value;
        }

        uint8_t& OLMFRAirOutletUpDownAngle_Rsp() OMG_NOEXCEPT {
            return m_OLMFRAirOutletUpDownAngle_Rsp_;
        }

        const uint8_t& OLMFRAirOutletUpDownAngle_Rsp() const OMG_NOEXCEPT {
            return m_OLMFRAirOutletUpDownAngle_Rsp_;
        }

        void OLMFRAirOutletUpDownAngle_Rsp(uint8_t value) {
            m_OLMFRAirOutletUpDownAngle_Rsp_ = value;
        }

        uint8_t& OLMFRAirOutletLeftRightAngle_Rsp() OMG_NOEXCEPT {
            return m_OLMFRAirOutletLeftRightAngle_Rsp_;
        }

        const uint8_t& OLMFRAirOutletLeftRightAngle_Rsp() const OMG_NOEXCEPT {
            return m_OLMFRAirOutletLeftRightAngle_Rsp_;
        }

        void OLMFRAirOutletLeftRightAngle_Rsp(uint8_t value) {
            m_OLMFRAirOutletLeftRightAngle_Rsp_ = value;
        }

        bool operator == (const AC_St_struct& other_) const;
        bool operator != (const AC_St_struct& other_) const;

        void swap(AC_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_ACCycleMode_St_;
        uint8_t m_FACAirFlowLevel_St_;
        uint8_t m_FACMode_St_;
        uint8_t m_FACSwitch_Rsp_;
        uint8_t m_FDeiceDefrost_Rsp_;
        uint8_t m_FLeftTempSet_St_;
        uint8_t m_FRightTempSet_St_;
        uint8_t m_FTempAreaSync_St_;
        uint8_t m_FAcCoolOrHeatOrVent_St_;
        uint8_t m_ACOperateMode_St_;
        uint8_t m_FACAuto_Rsp_;
        uint8_t m_FACAirFlowLevelAuto_St_;
        uint8_t m_FACAirFlowModeAuto_St_;
        uint8_t m_FACCoolOrHeatOrVentAuto_St_;
        uint8_t m_EnvirTemp_Val_;
        uint8_t m_FragSwitchEN_Rsp_;
        uint8_t m_FragConcLevel_Rsp_;
        uint8_t m_FragChannel1Switch_St_;
        uint8_t m_FragChannel2Switch_St_;
        uint8_t m_FragChannel3Switch_St_;
        uint8_t m_FragChannelType_;
        uint8_t m_FragChannelIndex_;
        uint16_t m_FragChannel1Life_;
        uint16_t m_FragChannel2Life_;
        uint16_t m_FragChannel3Life_;
        uint8_t m_IONSet_St_;
        uint8_t m_PM25Set_St_;
        uint8_t m_PM25Trigger_St_;
        uint16_t m_PM25CarConc_;
        uint8_t m_AQSSet_St_;
        uint8_t m_AQSTrigger_St_;
        uint8_t m_AQSAirQuality_Val_;
        uint8_t m_InFilterLifeRemind_;
        uint8_t m_OutsideFilterLifeRemind_;
        uint8_t m_FLeftAirOutletMode_St_;
        uint8_t m_FRightAirOutletMode_St_;
        uint8_t m_OLMFLAirOutletSwitch_Rsp_;
        uint8_t m_OLMLCAirOutletSwitch_Rsp_;
        uint8_t m_OLMRCAirOutletSwitch_Rsp_;
        uint8_t m_OLMFRAirOutletSwitch_Rsp_;
        uint8_t m_OLMFLMotorErrSt_;
        uint8_t m_OLMLCMotorErrSt_;
        uint8_t m_OLMRCMotorErrSt_;
        uint8_t m_OLMFRMotorErrSt_;
        uint8_t m_OLMFLAirOutletLeftRightAngle_Rsp_;
        uint8_t m_OLMFLAirOutletUpDownAngle_Rsp_;
        uint8_t m_OLMLCAirOutletUpDownAngle_Rsp_;
        uint8_t m_OLMLCAirOutletLeftRightAngle_Rsp_;
        uint8_t m_OLMRCAirOutletLeftRightAngle_Rsp_;
        uint8_t m_OLMRCAirOutletUpDownAngle_Rsp_;
        uint8_t m_OLMFRAirOutletUpDownAngle_Rsp_;
        uint8_t m_OLMFRAirOutletLeftRightAngle_Rsp_;

    };

    inline void swap(AC_St_struct& a, AC_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const AC_St_struct& sample);

    class NDDSUSERDllExport Thermal_St_struct {
      public:
        Thermal_St_struct();

        Thermal_St_struct(
            uint8_t HeatLiquidtLackWarn_St,
            uint8_t ThermalLiquidLackWarn_St,
            uint8_t RefrigerantCheckRemind,
            uint8_t FACLimit_St,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Thermal_St_struct (Thermal_St_struct&&) = default;
        Thermal_St_struct& operator=(Thermal_St_struct&&) = default;
        Thermal_St_struct& operator=(const Thermal_St_struct&) = default;
        Thermal_St_struct(const Thermal_St_struct&) = default;
        #else
        Thermal_St_struct(Thermal_St_struct&& other_) OMG_NOEXCEPT;  
        Thermal_St_struct& operator=(Thermal_St_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& HeatLiquidtLackWarn_St() OMG_NOEXCEPT {
            return m_HeatLiquidtLackWarn_St_;
        }

        const uint8_t& HeatLiquidtLackWarn_St() const OMG_NOEXCEPT {
            return m_HeatLiquidtLackWarn_St_;
        }

        void HeatLiquidtLackWarn_St(uint8_t value) {
            m_HeatLiquidtLackWarn_St_ = value;
        }

        uint8_t& ThermalLiquidLackWarn_St() OMG_NOEXCEPT {
            return m_ThermalLiquidLackWarn_St_;
        }

        const uint8_t& ThermalLiquidLackWarn_St() const OMG_NOEXCEPT {
            return m_ThermalLiquidLackWarn_St_;
        }

        void ThermalLiquidLackWarn_St(uint8_t value) {
            m_ThermalLiquidLackWarn_St_ = value;
        }

        uint8_t& RefrigerantCheckRemind() OMG_NOEXCEPT {
            return m_RefrigerantCheckRemind_;
        }

        const uint8_t& RefrigerantCheckRemind() const OMG_NOEXCEPT {
            return m_RefrigerantCheckRemind_;
        }

        void RefrigerantCheckRemind(uint8_t value) {
            m_RefrigerantCheckRemind_ = value;
        }

        uint8_t& FACLimit_St() OMG_NOEXCEPT {
            return m_FACLimit_St_;
        }

        const uint8_t& FACLimit_St() const OMG_NOEXCEPT {
            return m_FACLimit_St_;
        }

        void FACLimit_St(uint8_t value) {
            m_FACLimit_St_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const Thermal_St_struct& other_) const;
        bool operator != (const Thermal_St_struct& other_) const;

        void swap(Thermal_St_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_HeatLiquidtLackWarn_St_;
        uint8_t m_ThermalLiquidLackWarn_St_;
        uint8_t m_RefrigerantCheckRemind_;
        uint8_t m_FACLimit_St_;
        std::string m_CtrlSource_;

    };

    inline void swap(Thermal_St_struct& a, Thermal_St_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Thermal_St_struct& sample);

    class NDDSUSERDllExport AC_Ctrl_SOA_struct {
      public:
        AC_Ctrl_SOA_struct();

        explicit AC_Ctrl_SOA_struct(
            uint8_t AC_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        AC_Ctrl_SOA_struct (AC_Ctrl_SOA_struct&&) = default;
        AC_Ctrl_SOA_struct& operator=(AC_Ctrl_SOA_struct&&) = default;
        AC_Ctrl_SOA_struct& operator=(const AC_Ctrl_SOA_struct&) = default;
        AC_Ctrl_SOA_struct(const AC_Ctrl_SOA_struct&) = default;
        #else
        AC_Ctrl_SOA_struct(AC_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        AC_Ctrl_SOA_struct& operator=(AC_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& AC_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_AC_Ctrl_SOA_u8_;
        }

        const uint8_t& AC_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_AC_Ctrl_SOA_u8_;
        }

        void AC_Ctrl_SOA_u8(uint8_t value) {
            m_AC_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const AC_Ctrl_SOA_struct& other_) const;
        bool operator != (const AC_Ctrl_SOA_struct& other_) const;

        void swap(AC_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_AC_Ctrl_SOA_u8_;

    };

    inline void swap(AC_Ctrl_SOA_struct& a, AC_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const AC_Ctrl_SOA_struct& sample);

} // namespace EnergyDomain  
namespace Temporary {

    class NDDSUSERDllExport GeneralVehSt_Struct {
      public:
        GeneralVehSt_Struct();

        GeneralVehSt_Struct(
            uint16_t SOCDisplay_Val,
            uint8_t DCCharge_St,
            uint8_t ACCharge_St,
            uint8_t FLSeatOcp_St,
            uint8_t ActlGear_St,
            uint8_t ActlGearVaild_St,
            uint8_t Ready_St,
            uint8_t DrvrSeatBeltValid_St,
            uint8_t DrvrSeatBelt_St,
            uint8_t VehSpdValid_St,
            uint16_t VehSpd_Val,
            uint8_t EPB_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        GeneralVehSt_Struct (GeneralVehSt_Struct&&) = default;
        GeneralVehSt_Struct& operator=(GeneralVehSt_Struct&&) = default;
        GeneralVehSt_Struct& operator=(const GeneralVehSt_Struct&) = default;
        GeneralVehSt_Struct(const GeneralVehSt_Struct&) = default;
        #else
        GeneralVehSt_Struct(GeneralVehSt_Struct&& other_) OMG_NOEXCEPT;  
        GeneralVehSt_Struct& operator=(GeneralVehSt_Struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint16_t& SOCDisplay_Val() OMG_NOEXCEPT {
            return m_SOCDisplay_Val_;
        }

        const uint16_t& SOCDisplay_Val() const OMG_NOEXCEPT {
            return m_SOCDisplay_Val_;
        }

        void SOCDisplay_Val(uint16_t value) {
            m_SOCDisplay_Val_ = value;
        }

        uint8_t& DCCharge_St() OMG_NOEXCEPT {
            return m_DCCharge_St_;
        }

        const uint8_t& DCCharge_St() const OMG_NOEXCEPT {
            return m_DCCharge_St_;
        }

        void DCCharge_St(uint8_t value) {
            m_DCCharge_St_ = value;
        }

        uint8_t& ACCharge_St() OMG_NOEXCEPT {
            return m_ACCharge_St_;
        }

        const uint8_t& ACCharge_St() const OMG_NOEXCEPT {
            return m_ACCharge_St_;
        }

        void ACCharge_St(uint8_t value) {
            m_ACCharge_St_ = value;
        }

        uint8_t& FLSeatOcp_St() OMG_NOEXCEPT {
            return m_FLSeatOcp_St_;
        }

        const uint8_t& FLSeatOcp_St() const OMG_NOEXCEPT {
            return m_FLSeatOcp_St_;
        }

        void FLSeatOcp_St(uint8_t value) {
            m_FLSeatOcp_St_ = value;
        }

        uint8_t& ActlGear_St() OMG_NOEXCEPT {
            return m_ActlGear_St_;
        }

        const uint8_t& ActlGear_St() const OMG_NOEXCEPT {
            return m_ActlGear_St_;
        }

        void ActlGear_St(uint8_t value) {
            m_ActlGear_St_ = value;
        }

        uint8_t& ActlGearVaild_St() OMG_NOEXCEPT {
            return m_ActlGearVaild_St_;
        }

        const uint8_t& ActlGearVaild_St() const OMG_NOEXCEPT {
            return m_ActlGearVaild_St_;
        }

        void ActlGearVaild_St(uint8_t value) {
            m_ActlGearVaild_St_ = value;
        }

        uint8_t& Ready_St() OMG_NOEXCEPT {
            return m_Ready_St_;
        }

        const uint8_t& Ready_St() const OMG_NOEXCEPT {
            return m_Ready_St_;
        }

        void Ready_St(uint8_t value) {
            m_Ready_St_ = value;
        }

        uint8_t& DrvrSeatBeltValid_St() OMG_NOEXCEPT {
            return m_DrvrSeatBeltValid_St_;
        }

        const uint8_t& DrvrSeatBeltValid_St() const OMG_NOEXCEPT {
            return m_DrvrSeatBeltValid_St_;
        }

        void DrvrSeatBeltValid_St(uint8_t value) {
            m_DrvrSeatBeltValid_St_ = value;
        }

        uint8_t& DrvrSeatBelt_St() OMG_NOEXCEPT {
            return m_DrvrSeatBelt_St_;
        }

        const uint8_t& DrvrSeatBelt_St() const OMG_NOEXCEPT {
            return m_DrvrSeatBelt_St_;
        }

        void DrvrSeatBelt_St(uint8_t value) {
            m_DrvrSeatBelt_St_ = value;
        }

        uint8_t& VehSpdValid_St() OMG_NOEXCEPT {
            return m_VehSpdValid_St_;
        }

        const uint8_t& VehSpdValid_St() const OMG_NOEXCEPT {
            return m_VehSpdValid_St_;
        }

        void VehSpdValid_St(uint8_t value) {
            m_VehSpdValid_St_ = value;
        }

        uint16_t& VehSpd_Val() OMG_NOEXCEPT {
            return m_VehSpd_Val_;
        }

        const uint16_t& VehSpd_Val() const OMG_NOEXCEPT {
            return m_VehSpd_Val_;
        }

        void VehSpd_Val(uint16_t value) {
            m_VehSpd_Val_ = value;
        }

        uint8_t& EPB_St() OMG_NOEXCEPT {
            return m_EPB_St_;
        }

        const uint8_t& EPB_St() const OMG_NOEXCEPT {
            return m_EPB_St_;
        }

        void EPB_St(uint8_t value) {
            m_EPB_St_ = value;
        }

        bool operator == (const GeneralVehSt_Struct& other_) const;
        bool operator != (const GeneralVehSt_Struct& other_) const;

        void swap(GeneralVehSt_Struct& other_) OMG_NOEXCEPT ;

      private:

        uint16_t m_SOCDisplay_Val_;
        uint8_t m_DCCharge_St_;
        uint8_t m_ACCharge_St_;
        uint8_t m_FLSeatOcp_St_;
        uint8_t m_ActlGear_St_;
        uint8_t m_ActlGearVaild_St_;
        uint8_t m_Ready_St_;
        uint8_t m_DrvrSeatBeltValid_St_;
        uint8_t m_DrvrSeatBelt_St_;
        uint8_t m_VehSpdValid_St_;
        uint16_t m_VehSpd_Val_;
        uint8_t m_EPB_St_;

    };

    inline void swap(GeneralVehSt_Struct& a, GeneralVehSt_Struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const GeneralVehSt_Struct& sample);

    class NDDSUSERDllExport PTHMI_struct {
      public:
        PTHMI_struct();

        PTHMI_struct(
            uint8_t OBCACChrgCnctor_St,
            uint8_t OBCACSocketLock_St,
            uint8_t AbnormalShiftInfo,
            uint8_t DriveConflictRemindInfo,
            uint8_t Shift_Err,
            uint8_t HVOffConfirm_Req,
            uint8_t LimpHomeRmnd_St,
            uint8_t LowVoltSys_Err,
            uint8_t LowVoltSysWarnStop_St,
            uint8_t Motorovertemp_St,
            uint8_t PTFaultLgtClr_St,
            uint32_t PTHMI_Req,
            uint8_t PTThmlLiquidLackWarn_St,
            uint8_t PullOver_St,
            uint8_t RegenAvail_St,
            uint8_t ServiceReminder_St,
            uint16_t StdSenarioMileage_Val,
            uint8_t ThmlRunawayWarn_St,
            uint8_t TractionModeAvail_St,
            uint8_t TractionModeRemaind_St,
            uint8_t TractionModeSet_Rsp,
            uint8_t ACCharge_St,
            uint8_t CellOverTemp_St,
            uint8_t ChrgDischrgCnct_St,
            uint8_t DCCharge_St,
            uint8_t FastChrgCnctor_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        PTHMI_struct (PTHMI_struct&&) = default;
        PTHMI_struct& operator=(PTHMI_struct&&) = default;
        PTHMI_struct& operator=(const PTHMI_struct&) = default;
        PTHMI_struct(const PTHMI_struct&) = default;
        #else
        PTHMI_struct(PTHMI_struct&& other_) OMG_NOEXCEPT;  
        PTHMI_struct& operator=(PTHMI_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& OBCACChrgCnctor_St() OMG_NOEXCEPT {
            return m_OBCACChrgCnctor_St_;
        }

        const uint8_t& OBCACChrgCnctor_St() const OMG_NOEXCEPT {
            return m_OBCACChrgCnctor_St_;
        }

        void OBCACChrgCnctor_St(uint8_t value) {
            m_OBCACChrgCnctor_St_ = value;
        }

        uint8_t& OBCACSocketLock_St() OMG_NOEXCEPT {
            return m_OBCACSocketLock_St_;
        }

        const uint8_t& OBCACSocketLock_St() const OMG_NOEXCEPT {
            return m_OBCACSocketLock_St_;
        }

        void OBCACSocketLock_St(uint8_t value) {
            m_OBCACSocketLock_St_ = value;
        }

        uint8_t& AbnormalShiftInfo() OMG_NOEXCEPT {
            return m_AbnormalShiftInfo_;
        }

        const uint8_t& AbnormalShiftInfo() const OMG_NOEXCEPT {
            return m_AbnormalShiftInfo_;
        }

        void AbnormalShiftInfo(uint8_t value) {
            m_AbnormalShiftInfo_ = value;
        }

        uint8_t& DriveConflictRemindInfo() OMG_NOEXCEPT {
            return m_DriveConflictRemindInfo_;
        }

        const uint8_t& DriveConflictRemindInfo() const OMG_NOEXCEPT {
            return m_DriveConflictRemindInfo_;
        }

        void DriveConflictRemindInfo(uint8_t value) {
            m_DriveConflictRemindInfo_ = value;
        }

        uint8_t& Shift_Err() OMG_NOEXCEPT {
            return m_Shift_Err_;
        }

        const uint8_t& Shift_Err() const OMG_NOEXCEPT {
            return m_Shift_Err_;
        }

        void Shift_Err(uint8_t value) {
            m_Shift_Err_ = value;
        }

        uint8_t& HVOffConfirm_Req() OMG_NOEXCEPT {
            return m_HVOffConfirm_Req_;
        }

        const uint8_t& HVOffConfirm_Req() const OMG_NOEXCEPT {
            return m_HVOffConfirm_Req_;
        }

        void HVOffConfirm_Req(uint8_t value) {
            m_HVOffConfirm_Req_ = value;
        }

        uint8_t& LimpHomeRmnd_St() OMG_NOEXCEPT {
            return m_LimpHomeRmnd_St_;
        }

        const uint8_t& LimpHomeRmnd_St() const OMG_NOEXCEPT {
            return m_LimpHomeRmnd_St_;
        }

        void LimpHomeRmnd_St(uint8_t value) {
            m_LimpHomeRmnd_St_ = value;
        }

        uint8_t& LowVoltSys_Err() OMG_NOEXCEPT {
            return m_LowVoltSys_Err_;
        }

        const uint8_t& LowVoltSys_Err() const OMG_NOEXCEPT {
            return m_LowVoltSys_Err_;
        }

        void LowVoltSys_Err(uint8_t value) {
            m_LowVoltSys_Err_ = value;
        }

        uint8_t& LowVoltSysWarnStop_St() OMG_NOEXCEPT {
            return m_LowVoltSysWarnStop_St_;
        }

        const uint8_t& LowVoltSysWarnStop_St() const OMG_NOEXCEPT {
            return m_LowVoltSysWarnStop_St_;
        }

        void LowVoltSysWarnStop_St(uint8_t value) {
            m_LowVoltSysWarnStop_St_ = value;
        }

        uint8_t& Motorovertemp_St() OMG_NOEXCEPT {
            return m_Motorovertemp_St_;
        }

        const uint8_t& Motorovertemp_St() const OMG_NOEXCEPT {
            return m_Motorovertemp_St_;
        }

        void Motorovertemp_St(uint8_t value) {
            m_Motorovertemp_St_ = value;
        }

        uint8_t& PTFaultLgtClr_St() OMG_NOEXCEPT {
            return m_PTFaultLgtClr_St_;
        }

        const uint8_t& PTFaultLgtClr_St() const OMG_NOEXCEPT {
            return m_PTFaultLgtClr_St_;
        }

        void PTFaultLgtClr_St(uint8_t value) {
            m_PTFaultLgtClr_St_ = value;
        }

        uint32_t& PTHMI_Req() OMG_NOEXCEPT {
            return m_PTHMI_Req_;
        }

        const uint32_t& PTHMI_Req() const OMG_NOEXCEPT {
            return m_PTHMI_Req_;
        }

        void PTHMI_Req(uint32_t value) {
            m_PTHMI_Req_ = value;
        }

        uint8_t& PTThmlLiquidLackWarn_St() OMG_NOEXCEPT {
            return m_PTThmlLiquidLackWarn_St_;
        }

        const uint8_t& PTThmlLiquidLackWarn_St() const OMG_NOEXCEPT {
            return m_PTThmlLiquidLackWarn_St_;
        }

        void PTThmlLiquidLackWarn_St(uint8_t value) {
            m_PTThmlLiquidLackWarn_St_ = value;
        }

        uint8_t& PullOver_St() OMG_NOEXCEPT {
            return m_PullOver_St_;
        }

        const uint8_t& PullOver_St() const OMG_NOEXCEPT {
            return m_PullOver_St_;
        }

        void PullOver_St(uint8_t value) {
            m_PullOver_St_ = value;
        }

        uint8_t& RegenAvail_St() OMG_NOEXCEPT {
            return m_RegenAvail_St_;
        }

        const uint8_t& RegenAvail_St() const OMG_NOEXCEPT {
            return m_RegenAvail_St_;
        }

        void RegenAvail_St(uint8_t value) {
            m_RegenAvail_St_ = value;
        }

        uint8_t& ServiceReminder_St() OMG_NOEXCEPT {
            return m_ServiceReminder_St_;
        }

        const uint8_t& ServiceReminder_St() const OMG_NOEXCEPT {
            return m_ServiceReminder_St_;
        }

        void ServiceReminder_St(uint8_t value) {
            m_ServiceReminder_St_ = value;
        }

        uint16_t& StdSenarioMileage_Val() OMG_NOEXCEPT {
            return m_StdSenarioMileage_Val_;
        }

        const uint16_t& StdSenarioMileage_Val() const OMG_NOEXCEPT {
            return m_StdSenarioMileage_Val_;
        }

        void StdSenarioMileage_Val(uint16_t value) {
            m_StdSenarioMileage_Val_ = value;
        }

        uint8_t& ThmlRunawayWarn_St() OMG_NOEXCEPT {
            return m_ThmlRunawayWarn_St_;
        }

        const uint8_t& ThmlRunawayWarn_St() const OMG_NOEXCEPT {
            return m_ThmlRunawayWarn_St_;
        }

        void ThmlRunawayWarn_St(uint8_t value) {
            m_ThmlRunawayWarn_St_ = value;
        }

        uint8_t& TractionModeAvail_St() OMG_NOEXCEPT {
            return m_TractionModeAvail_St_;
        }

        const uint8_t& TractionModeAvail_St() const OMG_NOEXCEPT {
            return m_TractionModeAvail_St_;
        }

        void TractionModeAvail_St(uint8_t value) {
            m_TractionModeAvail_St_ = value;
        }

        uint8_t& TractionModeRemaind_St() OMG_NOEXCEPT {
            return m_TractionModeRemaind_St_;
        }

        const uint8_t& TractionModeRemaind_St() const OMG_NOEXCEPT {
            return m_TractionModeRemaind_St_;
        }

        void TractionModeRemaind_St(uint8_t value) {
            m_TractionModeRemaind_St_ = value;
        }

        uint8_t& TractionModeSet_Rsp() OMG_NOEXCEPT {
            return m_TractionModeSet_Rsp_;
        }

        const uint8_t& TractionModeSet_Rsp() const OMG_NOEXCEPT {
            return m_TractionModeSet_Rsp_;
        }

        void TractionModeSet_Rsp(uint8_t value) {
            m_TractionModeSet_Rsp_ = value;
        }

        uint8_t& ACCharge_St() OMG_NOEXCEPT {
            return m_ACCharge_St_;
        }

        const uint8_t& ACCharge_St() const OMG_NOEXCEPT {
            return m_ACCharge_St_;
        }

        void ACCharge_St(uint8_t value) {
            m_ACCharge_St_ = value;
        }

        uint8_t& CellOverTemp_St() OMG_NOEXCEPT {
            return m_CellOverTemp_St_;
        }

        const uint8_t& CellOverTemp_St() const OMG_NOEXCEPT {
            return m_CellOverTemp_St_;
        }

        void CellOverTemp_St(uint8_t value) {
            m_CellOverTemp_St_ = value;
        }

        uint8_t& ChrgDischrgCnct_St() OMG_NOEXCEPT {
            return m_ChrgDischrgCnct_St_;
        }

        const uint8_t& ChrgDischrgCnct_St() const OMG_NOEXCEPT {
            return m_ChrgDischrgCnct_St_;
        }

        void ChrgDischrgCnct_St(uint8_t value) {
            m_ChrgDischrgCnct_St_ = value;
        }

        uint8_t& DCCharge_St() OMG_NOEXCEPT {
            return m_DCCharge_St_;
        }

        const uint8_t& DCCharge_St() const OMG_NOEXCEPT {
            return m_DCCharge_St_;
        }

        void DCCharge_St(uint8_t value) {
            m_DCCharge_St_ = value;
        }

        uint8_t& FastChrgCnctor_St() OMG_NOEXCEPT {
            return m_FastChrgCnctor_St_;
        }

        const uint8_t& FastChrgCnctor_St() const OMG_NOEXCEPT {
            return m_FastChrgCnctor_St_;
        }

        void FastChrgCnctor_St(uint8_t value) {
            m_FastChrgCnctor_St_ = value;
        }

        bool operator == (const PTHMI_struct& other_) const;
        bool operator != (const PTHMI_struct& other_) const;

        void swap(PTHMI_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_OBCACChrgCnctor_St_;
        uint8_t m_OBCACSocketLock_St_;
        uint8_t m_AbnormalShiftInfo_;
        uint8_t m_DriveConflictRemindInfo_;
        uint8_t m_Shift_Err_;
        uint8_t m_HVOffConfirm_Req_;
        uint8_t m_LimpHomeRmnd_St_;
        uint8_t m_LowVoltSys_Err_;
        uint8_t m_LowVoltSysWarnStop_St_;
        uint8_t m_Motorovertemp_St_;
        uint8_t m_PTFaultLgtClr_St_;
        uint32_t m_PTHMI_Req_;
        uint8_t m_PTThmlLiquidLackWarn_St_;
        uint8_t m_PullOver_St_;
        uint8_t m_RegenAvail_St_;
        uint8_t m_ServiceReminder_St_;
        uint16_t m_StdSenarioMileage_Val_;
        uint8_t m_ThmlRunawayWarn_St_;
        uint8_t m_TractionModeAvail_St_;
        uint8_t m_TractionModeRemaind_St_;
        uint8_t m_TractionModeSet_Rsp_;
        uint8_t m_ACCharge_St_;
        uint8_t m_CellOverTemp_St_;
        uint8_t m_ChrgDischrgCnct_St_;
        uint8_t m_DCCharge_St_;
        uint8_t m_FastChrgCnctor_St_;

    };

    inline void swap(PTHMI_struct& a, PTHMI_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PTHMI_struct& sample);

    class NDDSUSERDllExport CHSHMI_struct {
      public:
        CHSHMI_struct();

        CHSHMI_struct(
            uint8_t AirbagWarnLamp_St,
            uint8_t EPSSystem_Err,
            uint8_t ABSIntv_St,
            uint8_t ABS_Err,
            uint8_t EBDIntv_St,
            uint8_t EBD_Err,
            uint8_t BrakeFluidLvl_St,
            uint8_t BrakePedal_St,
            uint8_t InputRodStroke_St,
            uint16_t InputRodStroke_Val,
            uint8_t EPBFunctionLamp_St,
            uint8_t EPBFailLamp_St,
            uint8_t CapacityLimitWarn_UI,
            uint8_t OperationReminder_UI,
            uint8_t BU_CapacityLimitWarn_UI,
            uint8_t BU_OperationReminder_UI,
            uint8_t BU_EPBFunctionLamp_St,
            uint8_t BU_EPBFailLamp_St,
            uint8_t BU_EPBHardSwitch_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        CHSHMI_struct (CHSHMI_struct&&) = default;
        CHSHMI_struct& operator=(CHSHMI_struct&&) = default;
        CHSHMI_struct& operator=(const CHSHMI_struct&) = default;
        CHSHMI_struct(const CHSHMI_struct&) = default;
        #else
        CHSHMI_struct(CHSHMI_struct&& other_) OMG_NOEXCEPT;  
        CHSHMI_struct& operator=(CHSHMI_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& AirbagWarnLamp_St() OMG_NOEXCEPT {
            return m_AirbagWarnLamp_St_;
        }

        const uint8_t& AirbagWarnLamp_St() const OMG_NOEXCEPT {
            return m_AirbagWarnLamp_St_;
        }

        void AirbagWarnLamp_St(uint8_t value) {
            m_AirbagWarnLamp_St_ = value;
        }

        uint8_t& EPSSystem_Err() OMG_NOEXCEPT {
            return m_EPSSystem_Err_;
        }

        const uint8_t& EPSSystem_Err() const OMG_NOEXCEPT {
            return m_EPSSystem_Err_;
        }

        void EPSSystem_Err(uint8_t value) {
            m_EPSSystem_Err_ = value;
        }

        uint8_t& ABSIntv_St() OMG_NOEXCEPT {
            return m_ABSIntv_St_;
        }

        const uint8_t& ABSIntv_St() const OMG_NOEXCEPT {
            return m_ABSIntv_St_;
        }

        void ABSIntv_St(uint8_t value) {
            m_ABSIntv_St_ = value;
        }

        uint8_t& ABS_Err() OMG_NOEXCEPT {
            return m_ABS_Err_;
        }

        const uint8_t& ABS_Err() const OMG_NOEXCEPT {
            return m_ABS_Err_;
        }

        void ABS_Err(uint8_t value) {
            m_ABS_Err_ = value;
        }

        uint8_t& EBDIntv_St() OMG_NOEXCEPT {
            return m_EBDIntv_St_;
        }

        const uint8_t& EBDIntv_St() const OMG_NOEXCEPT {
            return m_EBDIntv_St_;
        }

        void EBDIntv_St(uint8_t value) {
            m_EBDIntv_St_ = value;
        }

        uint8_t& EBD_Err() OMG_NOEXCEPT {
            return m_EBD_Err_;
        }

        const uint8_t& EBD_Err() const OMG_NOEXCEPT {
            return m_EBD_Err_;
        }

        void EBD_Err(uint8_t value) {
            m_EBD_Err_ = value;
        }

        uint8_t& BrakeFluidLvl_St() OMG_NOEXCEPT {
            return m_BrakeFluidLvl_St_;
        }

        const uint8_t& BrakeFluidLvl_St() const OMG_NOEXCEPT {
            return m_BrakeFluidLvl_St_;
        }

        void BrakeFluidLvl_St(uint8_t value) {
            m_BrakeFluidLvl_St_ = value;
        }

        uint8_t& BrakePedal_St() OMG_NOEXCEPT {
            return m_BrakePedal_St_;
        }

        const uint8_t& BrakePedal_St() const OMG_NOEXCEPT {
            return m_BrakePedal_St_;
        }

        void BrakePedal_St(uint8_t value) {
            m_BrakePedal_St_ = value;
        }

        uint8_t& InputRodStroke_St() OMG_NOEXCEPT {
            return m_InputRodStroke_St_;
        }

        const uint8_t& InputRodStroke_St() const OMG_NOEXCEPT {
            return m_InputRodStroke_St_;
        }

        void InputRodStroke_St(uint8_t value) {
            m_InputRodStroke_St_ = value;
        }

        uint16_t& InputRodStroke_Val() OMG_NOEXCEPT {
            return m_InputRodStroke_Val_;
        }

        const uint16_t& InputRodStroke_Val() const OMG_NOEXCEPT {
            return m_InputRodStroke_Val_;
        }

        void InputRodStroke_Val(uint16_t value) {
            m_InputRodStroke_Val_ = value;
        }

        uint8_t& EPBFunctionLamp_St() OMG_NOEXCEPT {
            return m_EPBFunctionLamp_St_;
        }

        const uint8_t& EPBFunctionLamp_St() const OMG_NOEXCEPT {
            return m_EPBFunctionLamp_St_;
        }

        void EPBFunctionLamp_St(uint8_t value) {
            m_EPBFunctionLamp_St_ = value;
        }

        uint8_t& EPBFailLamp_St() OMG_NOEXCEPT {
            return m_EPBFailLamp_St_;
        }

        const uint8_t& EPBFailLamp_St() const OMG_NOEXCEPT {
            return m_EPBFailLamp_St_;
        }

        void EPBFailLamp_St(uint8_t value) {
            m_EPBFailLamp_St_ = value;
        }

        uint8_t& CapacityLimitWarn_UI() OMG_NOEXCEPT {
            return m_CapacityLimitWarn_UI_;
        }

        const uint8_t& CapacityLimitWarn_UI() const OMG_NOEXCEPT {
            return m_CapacityLimitWarn_UI_;
        }

        void CapacityLimitWarn_UI(uint8_t value) {
            m_CapacityLimitWarn_UI_ = value;
        }

        uint8_t& OperationReminder_UI() OMG_NOEXCEPT {
            return m_OperationReminder_UI_;
        }

        const uint8_t& OperationReminder_UI() const OMG_NOEXCEPT {
            return m_OperationReminder_UI_;
        }

        void OperationReminder_UI(uint8_t value) {
            m_OperationReminder_UI_ = value;
        }

        uint8_t& BU_CapacityLimitWarn_UI() OMG_NOEXCEPT {
            return m_BU_CapacityLimitWarn_UI_;
        }

        const uint8_t& BU_CapacityLimitWarn_UI() const OMG_NOEXCEPT {
            return m_BU_CapacityLimitWarn_UI_;
        }

        void BU_CapacityLimitWarn_UI(uint8_t value) {
            m_BU_CapacityLimitWarn_UI_ = value;
        }

        uint8_t& BU_OperationReminder_UI() OMG_NOEXCEPT {
            return m_BU_OperationReminder_UI_;
        }

        const uint8_t& BU_OperationReminder_UI() const OMG_NOEXCEPT {
            return m_BU_OperationReminder_UI_;
        }

        void BU_OperationReminder_UI(uint8_t value) {
            m_BU_OperationReminder_UI_ = value;
        }

        uint8_t& BU_EPBFunctionLamp_St() OMG_NOEXCEPT {
            return m_BU_EPBFunctionLamp_St_;
        }

        const uint8_t& BU_EPBFunctionLamp_St() const OMG_NOEXCEPT {
            return m_BU_EPBFunctionLamp_St_;
        }

        void BU_EPBFunctionLamp_St(uint8_t value) {
            m_BU_EPBFunctionLamp_St_ = value;
        }

        uint8_t& BU_EPBFailLamp_St() OMG_NOEXCEPT {
            return m_BU_EPBFailLamp_St_;
        }

        const uint8_t& BU_EPBFailLamp_St() const OMG_NOEXCEPT {
            return m_BU_EPBFailLamp_St_;
        }

        void BU_EPBFailLamp_St(uint8_t value) {
            m_BU_EPBFailLamp_St_ = value;
        }

        uint8_t& BU_EPBHardSwitch_St() OMG_NOEXCEPT {
            return m_BU_EPBHardSwitch_St_;
        }

        const uint8_t& BU_EPBHardSwitch_St() const OMG_NOEXCEPT {
            return m_BU_EPBHardSwitch_St_;
        }

        void BU_EPBHardSwitch_St(uint8_t value) {
            m_BU_EPBHardSwitch_St_ = value;
        }

        bool operator == (const CHSHMI_struct& other_) const;
        bool operator != (const CHSHMI_struct& other_) const;

        void swap(CHSHMI_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_AirbagWarnLamp_St_;
        uint8_t m_EPSSystem_Err_;
        uint8_t m_ABSIntv_St_;
        uint8_t m_ABS_Err_;
        uint8_t m_EBDIntv_St_;
        uint8_t m_EBD_Err_;
        uint8_t m_BrakeFluidLvl_St_;
        uint8_t m_BrakePedal_St_;
        uint8_t m_InputRodStroke_St_;
        uint16_t m_InputRodStroke_Val_;
        uint8_t m_EPBFunctionLamp_St_;
        uint8_t m_EPBFailLamp_St_;
        uint8_t m_CapacityLimitWarn_UI_;
        uint8_t m_OperationReminder_UI_;
        uint8_t m_BU_CapacityLimitWarn_UI_;
        uint8_t m_BU_OperationReminder_UI_;
        uint8_t m_BU_EPBFunctionLamp_St_;
        uint8_t m_BU_EPBFailLamp_St_;
        uint8_t m_BU_EPBHardSwitch_St_;

    };

    inline void swap(CHSHMI_struct& a, CHSHMI_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CHSHMI_struct& sample);

    class NDDSUSERDllExport WiperWash_Ctrl_Struct {
      public:
        WiperWash_Ctrl_Struct();

        WiperWash_Ctrl_Struct(
            uint8_t Fwiper_Req,
            uint8_t FMistWash_Req,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        WiperWash_Ctrl_Struct (WiperWash_Ctrl_Struct&&) = default;
        WiperWash_Ctrl_Struct& operator=(WiperWash_Ctrl_Struct&&) = default;
        WiperWash_Ctrl_Struct& operator=(const WiperWash_Ctrl_Struct&) = default;
        WiperWash_Ctrl_Struct(const WiperWash_Ctrl_Struct&) = default;
        #else
        WiperWash_Ctrl_Struct(WiperWash_Ctrl_Struct&& other_) OMG_NOEXCEPT;  
        WiperWash_Ctrl_Struct& operator=(WiperWash_Ctrl_Struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& Fwiper_Req() OMG_NOEXCEPT {
            return m_Fwiper_Req_;
        }

        const uint8_t& Fwiper_Req() const OMG_NOEXCEPT {
            return m_Fwiper_Req_;
        }

        void Fwiper_Req(uint8_t value) {
            m_Fwiper_Req_ = value;
        }

        uint8_t& FMistWash_Req() OMG_NOEXCEPT {
            return m_FMistWash_Req_;
        }

        const uint8_t& FMistWash_Req() const OMG_NOEXCEPT {
            return m_FMistWash_Req_;
        }

        void FMistWash_Req(uint8_t value) {
            m_FMistWash_Req_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const WiperWash_Ctrl_Struct& other_) const;
        bool operator != (const WiperWash_Ctrl_Struct& other_) const;

        void swap(WiperWash_Ctrl_Struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_Fwiper_Req_;
        uint8_t m_FMistWash_Req_;
        std::string m_CtrlSource_;

    };

    inline void swap(WiperWash_Ctrl_Struct& a, WiperWash_Ctrl_Struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const WiperWash_Ctrl_Struct& sample);

    class NDDSUSERDllExport SN_info_string {
      public:
        SN_info_string();

        explicit SN_info_string(
            const std::string& SN_info_String);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SN_info_string (SN_info_string&&) = default;
        SN_info_string& operator=(SN_info_string&&) = default;
        SN_info_string& operator=(const SN_info_string&) = default;
        SN_info_string(const SN_info_string&) = default;
        #else
        SN_info_string(SN_info_string&& other_) OMG_NOEXCEPT;  
        SN_info_string& operator=(SN_info_string&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        std::string& SN_info_String() OMG_NOEXCEPT {
            return m_SN_info_String_;
        }

        const std::string& SN_info_String() const OMG_NOEXCEPT {
            return m_SN_info_String_;
        }

        void SN_info_String(const std::string& value) {
            m_SN_info_String_ = value;
        }

        void SN_info_String(std::string&& value) {
            m_SN_info_String_ = std::move(value);
        }

        bool operator == (const SN_info_string& other_) const;
        bool operator != (const SN_info_string& other_) const;

        void swap(SN_info_string& other_) OMG_NOEXCEPT ;

      private:

        std::string m_SN_info_String_;

    };

    inline void swap(SN_info_string& a, SN_info_string& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SN_info_string& sample);

} // namespace Temporary  
namespace bottomtotop {

    class NDDSUSERDllExport NMService_Set_struct {
      public:
        NMService_Set_struct();

        NMService_Set_struct(
            uint16_t SceneID,
            uint8_t SceneStateReq,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NMService_Set_struct (NMService_Set_struct&&) = default;
        NMService_Set_struct& operator=(NMService_Set_struct&&) = default;
        NMService_Set_struct& operator=(const NMService_Set_struct&) = default;
        NMService_Set_struct(const NMService_Set_struct&) = default;
        #else
        NMService_Set_struct(NMService_Set_struct&& other_) OMG_NOEXCEPT;  
        NMService_Set_struct& operator=(NMService_Set_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint16_t& SceneID() OMG_NOEXCEPT {
            return m_SceneID_;
        }

        const uint16_t& SceneID() const OMG_NOEXCEPT {
            return m_SceneID_;
        }

        void SceneID(uint16_t value) {
            m_SceneID_ = value;
        }

        uint8_t& SceneStateReq() OMG_NOEXCEPT {
            return m_SceneStateReq_;
        }

        const uint8_t& SceneStateReq() const OMG_NOEXCEPT {
            return m_SceneStateReq_;
        }

        void SceneStateReq(uint8_t value) {
            m_SceneStateReq_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const NMService_Set_struct& other_) const;
        bool operator != (const NMService_Set_struct& other_) const;

        void swap(NMService_Set_struct& other_) OMG_NOEXCEPT ;

      private:

        uint16_t m_SceneID_;
        uint8_t m_SceneStateReq_;
        std::string m_CtrlSource_;

    };

    inline void swap(NMService_Set_struct& a, NMService_Set_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NMService_Set_struct& sample);

    class NDDSUSERDllExport NMService_Set_SOA_struct {
      public:
        NMService_Set_SOA_struct();

        explicit NMService_Set_SOA_struct(
            uint8_t NMService_Set_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NMService_Set_SOA_struct (NMService_Set_SOA_struct&&) = default;
        NMService_Set_SOA_struct& operator=(NMService_Set_SOA_struct&&) = default;
        NMService_Set_SOA_struct& operator=(const NMService_Set_SOA_struct&) = default;
        NMService_Set_SOA_struct(const NMService_Set_SOA_struct&) = default;
        #else
        NMService_Set_SOA_struct(NMService_Set_SOA_struct&& other_) OMG_NOEXCEPT;  
        NMService_Set_SOA_struct& operator=(NMService_Set_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& NMService_Set_SOA_u8() OMG_NOEXCEPT {
            return m_NMService_Set_SOA_u8_;
        }

        const uint8_t& NMService_Set_SOA_u8() const OMG_NOEXCEPT {
            return m_NMService_Set_SOA_u8_;
        }

        void NMService_Set_SOA_u8(uint8_t value) {
            m_NMService_Set_SOA_u8_ = value;
        }

        bool operator == (const NMService_Set_SOA_struct& other_) const;
        bool operator != (const NMService_Set_SOA_struct& other_) const;

        void swap(NMService_Set_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_NMService_Set_SOA_u8_;

    };

    inline void swap(NMService_Set_SOA_struct& a, NMService_Set_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NMService_Set_SOA_struct& sample);

    class NDDSUSERDllExport NmXService_Ctrl_struct {
      public:
        NmXService_Ctrl_struct();

        NmXService_Ctrl_struct(
            uint8_t NMStateReq,
            const std::string& ECUName);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NmXService_Ctrl_struct (NmXService_Ctrl_struct&&) = default;
        NmXService_Ctrl_struct& operator=(NmXService_Ctrl_struct&&) = default;
        NmXService_Ctrl_struct& operator=(const NmXService_Ctrl_struct&) = default;
        NmXService_Ctrl_struct(const NmXService_Ctrl_struct&) = default;
        #else
        NmXService_Ctrl_struct(NmXService_Ctrl_struct&& other_) OMG_NOEXCEPT;  
        NmXService_Ctrl_struct& operator=(NmXService_Ctrl_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& NMStateReq() OMG_NOEXCEPT {
            return m_NMStateReq_;
        }

        const uint8_t& NMStateReq() const OMG_NOEXCEPT {
            return m_NMStateReq_;
        }

        void NMStateReq(uint8_t value) {
            m_NMStateReq_ = value;
        }

        std::string& ECUName() OMG_NOEXCEPT {
            return m_ECUName_;
        }

        const std::string& ECUName() const OMG_NOEXCEPT {
            return m_ECUName_;
        }

        void ECUName(const std::string& value) {
            m_ECUName_ = value;
        }

        void ECUName(std::string&& value) {
            m_ECUName_ = std::move(value);
        }

        bool operator == (const NmXService_Ctrl_struct& other_) const;
        bool operator != (const NmXService_Ctrl_struct& other_) const;

        void swap(NmXService_Ctrl_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_NMStateReq_;
        std::string m_ECUName_;

    };

    inline void swap(NmXService_Ctrl_struct& a, NmXService_Ctrl_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NmXService_Ctrl_struct& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< bottomtotop::NmXService_Ctrl_struct >;
    template class NDDSUSERDllExport std::vector< bottomtotop::NmXService_Ctrl_struct >;
    #endif
    class NDDSUSERDllExport NmXService_Ctrl_Array {
      public:
        NmXService_Ctrl_Array();

        explicit NmXService_Ctrl_Array(
            const ::rti::core::bounded_sequence< bottomtotop::NmXService_Ctrl_struct, 50L >& NmXService_Ctrl);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NmXService_Ctrl_Array (NmXService_Ctrl_Array&&) = default;
        NmXService_Ctrl_Array& operator=(NmXService_Ctrl_Array&&) = default;
        NmXService_Ctrl_Array& operator=(const NmXService_Ctrl_Array&) = default;
        NmXService_Ctrl_Array(const NmXService_Ctrl_Array&) = default;
        #else
        NmXService_Ctrl_Array(NmXService_Ctrl_Array&& other_) OMG_NOEXCEPT;  
        NmXService_Ctrl_Array& operator=(NmXService_Ctrl_Array&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< bottomtotop::NmXService_Ctrl_struct, 50L >& NmXService_Ctrl() OMG_NOEXCEPT {
            return m_NmXService_Ctrl_;
        }

        const ::rti::core::bounded_sequence< bottomtotop::NmXService_Ctrl_struct, 50L >& NmXService_Ctrl() const OMG_NOEXCEPT {
            return m_NmXService_Ctrl_;
        }

        void NmXService_Ctrl(const ::rti::core::bounded_sequence< bottomtotop::NmXService_Ctrl_struct, 50L >& value) {
            m_NmXService_Ctrl_ = value;
        }

        void NmXService_Ctrl(::rti::core::bounded_sequence< bottomtotop::NmXService_Ctrl_struct, 50L >&& value) {
            m_NmXService_Ctrl_ = std::move(value);
        }

        bool operator == (const NmXService_Ctrl_Array& other_) const;
        bool operator != (const NmXService_Ctrl_Array& other_) const;

        void swap(NmXService_Ctrl_Array& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< bottomtotop::NmXService_Ctrl_struct, 50L > m_NmXService_Ctrl_;

    };

    inline void swap(NmXService_Ctrl_Array& a, NmXService_Ctrl_Array& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NmXService_Ctrl_Array& sample);

    class NDDSUSERDllExport NmXService_Ctrl_SOA_struct {
      public:
        NmXService_Ctrl_SOA_struct();

        explicit NmXService_Ctrl_SOA_struct(
            uint8_t NmXService_Ctrl_SOA_u8);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NmXService_Ctrl_SOA_struct (NmXService_Ctrl_SOA_struct&&) = default;
        NmXService_Ctrl_SOA_struct& operator=(NmXService_Ctrl_SOA_struct&&) = default;
        NmXService_Ctrl_SOA_struct& operator=(const NmXService_Ctrl_SOA_struct&) = default;
        NmXService_Ctrl_SOA_struct(const NmXService_Ctrl_SOA_struct&) = default;
        #else
        NmXService_Ctrl_SOA_struct(NmXService_Ctrl_SOA_struct&& other_) OMG_NOEXCEPT;  
        NmXService_Ctrl_SOA_struct& operator=(NmXService_Ctrl_SOA_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& NmXService_Ctrl_SOA_u8() OMG_NOEXCEPT {
            return m_NmXService_Ctrl_SOA_u8_;
        }

        const uint8_t& NmXService_Ctrl_SOA_u8() const OMG_NOEXCEPT {
            return m_NmXService_Ctrl_SOA_u8_;
        }

        void NmXService_Ctrl_SOA_u8(uint8_t value) {
            m_NmXService_Ctrl_SOA_u8_ = value;
        }

        bool operator == (const NmXService_Ctrl_SOA_struct& other_) const;
        bool operator != (const NmXService_Ctrl_SOA_struct& other_) const;

        void swap(NmXService_Ctrl_SOA_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_NmXService_Ctrl_SOA_u8_;

    };

    inline void swap(NmXService_Ctrl_SOA_struct& a, NmXService_Ctrl_SOA_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NmXService_Ctrl_SOA_struct& sample);

    class NDDSUSERDllExport NmService_Get_struct {
      public:
        NmService_Get_struct();

        NmService_Get_struct(
            uint8_t NMTypeReq,
            const std::string& CtrlSource);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NmService_Get_struct (NmService_Get_struct&&) = default;
        NmService_Get_struct& operator=(NmService_Get_struct&&) = default;
        NmService_Get_struct& operator=(const NmService_Get_struct&) = default;
        NmService_Get_struct(const NmService_Get_struct&) = default;
        #else
        NmService_Get_struct(NmService_Get_struct&& other_) OMG_NOEXCEPT;  
        NmService_Get_struct& operator=(NmService_Get_struct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& NMTypeReq() OMG_NOEXCEPT {
            return m_NMTypeReq_;
        }

        const uint8_t& NMTypeReq() const OMG_NOEXCEPT {
            return m_NMTypeReq_;
        }

        void NMTypeReq(uint8_t value) {
            m_NMTypeReq_ = value;
        }

        std::string& CtrlSource() OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        const std::string& CtrlSource() const OMG_NOEXCEPT {
            return m_CtrlSource_;
        }

        void CtrlSource(const std::string& value) {
            m_CtrlSource_ = value;
        }

        void CtrlSource(std::string&& value) {
            m_CtrlSource_ = std::move(value);
        }

        bool operator == (const NmService_Get_struct& other_) const;
        bool operator != (const NmService_Get_struct& other_) const;

        void swap(NmService_Get_struct& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_NMTypeReq_;
        std::string m_CtrlSource_;

    };

    inline void swap(NmService_Get_struct& a, NmService_Get_struct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NmService_Get_struct& sample);

    class NDDSUSERDllExport NMService_St_substruct {
      public:
        NMService_St_substruct();

        NMService_St_substruct(
            uint16_t SceneID,
            uint8_t SceneState);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NMService_St_substruct (NMService_St_substruct&&) = default;
        NMService_St_substruct& operator=(NMService_St_substruct&&) = default;
        NMService_St_substruct& operator=(const NMService_St_substruct&) = default;
        NMService_St_substruct(const NMService_St_substruct&) = default;
        #else
        NMService_St_substruct(NMService_St_substruct&& other_) OMG_NOEXCEPT;  
        NMService_St_substruct& operator=(NMService_St_substruct&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint16_t& SceneID() OMG_NOEXCEPT {
            return m_SceneID_;
        }

        const uint16_t& SceneID() const OMG_NOEXCEPT {
            return m_SceneID_;
        }

        void SceneID(uint16_t value) {
            m_SceneID_ = value;
        }

        uint8_t& SceneState() OMG_NOEXCEPT {
            return m_SceneState_;
        }

        const uint8_t& SceneState() const OMG_NOEXCEPT {
            return m_SceneState_;
        }

        void SceneState(uint8_t value) {
            m_SceneState_ = value;
        }

        bool operator == (const NMService_St_substruct& other_) const;
        bool operator != (const NMService_St_substruct& other_) const;

        void swap(NMService_St_substruct& other_) OMG_NOEXCEPT ;

      private:

        uint16_t m_SceneID_;
        uint8_t m_SceneState_;

    };

    inline void swap(NMService_St_substruct& a, NMService_St_substruct& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NMService_St_substruct& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< bottomtotop::NMService_St_substruct >;
    template class NDDSUSERDllExport std::vector< bottomtotop::NMService_St_substruct >;
    #endif
    class NDDSUSERDllExport NMService_St_array {
      public:
        NMService_St_array();

        explicit NMService_St_array(
            const ::rti::core::bounded_sequence< bottomtotop::NMService_St_substruct, 255L >& NMService_St);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NMService_St_array (NMService_St_array&&) = default;
        NMService_St_array& operator=(NMService_St_array&&) = default;
        NMService_St_array& operator=(const NMService_St_array&) = default;
        NMService_St_array(const NMService_St_array&) = default;
        #else
        NMService_St_array(NMService_St_array&& other_) OMG_NOEXCEPT;  
        NMService_St_array& operator=(NMService_St_array&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< bottomtotop::NMService_St_substruct, 255L >& NMService_St() OMG_NOEXCEPT {
            return m_NMService_St_;
        }

        const ::rti::core::bounded_sequence< bottomtotop::NMService_St_substruct, 255L >& NMService_St() const OMG_NOEXCEPT {
            return m_NMService_St_;
        }

        void NMService_St(const ::rti::core::bounded_sequence< bottomtotop::NMService_St_substruct, 255L >& value) {
            m_NMService_St_ = value;
        }

        void NMService_St(::rti::core::bounded_sequence< bottomtotop::NMService_St_substruct, 255L >&& value) {
            m_NMService_St_ = std::move(value);
        }

        bool operator == (const NMService_St_array& other_) const;
        bool operator != (const NMService_St_array& other_) const;

        void swap(NMService_St_array& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< bottomtotop::NMService_St_substruct, 255L > m_NMService_St_;

    };

    inline void swap(NMService_St_array& a, NMService_St_array& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NMService_St_array& sample);

    class NDDSUSERDllExport NMService_Srv_Req_Union {
      public:
        NMService_Srv_Req_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NMService_Srv_Req_Union (NMService_Srv_Req_Union&&) = default;
        NMService_Srv_Req_Union& operator=(NMService_Srv_Req_Union&&) = default;
        NMService_Srv_Req_Union& operator=(const NMService_Srv_Req_Union&) = default;
        NMService_Srv_Req_Union(const NMService_Srv_Req_Union&) = default;
        #else
        NMService_Srv_Req_Union(NMService_Srv_Req_Union&& other_) OMG_NOEXCEPT;  
        NMService_Srv_Req_Union& operator=(NMService_Srv_Req_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        bottomtotop::NMService_Set_struct& NMService_Set()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Req_Union::NMService_Set not selected by the discriminator" );
            }
            return m_u_.m_NMService_Set_;
        }

        const bottomtotop::NMService_Set_struct& NMService_Set() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Req_Union::NMService_Set not selected by the discriminator" );
            }
            return m_u_.m_NMService_Set_;
        }

        void NMService_Set(const bottomtotop::NMService_Set_struct& value) {
            m_u_.m_NMService_Set_ = value;
            m_d_= 0;
        }

        void NMService_Set(bottomtotop::NMService_Set_struct&& value) {
            m_u_.m_NMService_Set_ = std::move(value);
            m_d_= 0;
        }
        bottomtotop::NmXService_Ctrl_Array& NmXService_Ctrl()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Req_Union::NmXService_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_NmXService_Ctrl_;
        }

        const bottomtotop::NmXService_Ctrl_Array& NmXService_Ctrl() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Req_Union::NmXService_Ctrl not selected by the discriminator" );
            }
            return m_u_.m_NmXService_Ctrl_;
        }

        void NmXService_Ctrl(const bottomtotop::NmXService_Ctrl_Array& value) {
            m_u_.m_NmXService_Ctrl_ = value;
            m_d_= 1;
        }

        void NmXService_Ctrl(bottomtotop::NmXService_Ctrl_Array&& value) {
            m_u_.m_NmXService_Ctrl_ = std::move(value);
            m_d_= 1;
        }
        bottomtotop::NmService_Get_struct& NmService_Get()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Req_Union::NmService_Get not selected by the discriminator" );
            }
            return m_u_.m_NmService_Get_;
        }

        const bottomtotop::NmService_Get_struct& NmService_Get() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Req_Union::NmService_Get not selected by the discriminator" );
            }
            return m_u_.m_NmService_Get_;
        }

        void NmService_Get(const bottomtotop::NmService_Get_struct& value) {
            m_u_.m_NmService_Get_ = value;
            m_d_= 2;
        }

        void NmService_Get(bottomtotop::NmService_Get_struct&& value) {
            m_u_.m_NmService_Get_ = std::move(value);
            m_d_= 2;
        }

        bool operator == (const NMService_Srv_Req_Union& other_) const;
        bool operator != (const NMService_Srv_Req_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(NMService_Srv_Req_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            bottomtotop::NMService_Set_struct m_NMService_Set_;
            bottomtotop::NmXService_Ctrl_Array m_NmXService_Ctrl_;
            bottomtotop::NmService_Get_struct m_NmService_Get_;
            Union_();
            Union_(
                const bottomtotop::NMService_Set_struct& NMService_Set,
                const bottomtotop::NmXService_Ctrl_Array& NmXService_Ctrl,
                const bottomtotop::NmService_Get_struct& NmService_Get);
        };
        Union_ m_u_;

    };

    inline void swap(NMService_Srv_Req_Union& a, NMService_Srv_Req_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NMService_Srv_Req_Union& sample);

    class NDDSUSERDllExport NMService_Srv_Resp_Union {
      public:
        NMService_Srv_Resp_Union();

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        NMService_Srv_Resp_Union (NMService_Srv_Resp_Union&&) = default;
        NMService_Srv_Resp_Union& operator=(NMService_Srv_Resp_Union&&) = default;
        NMService_Srv_Resp_Union& operator=(const NMService_Srv_Resp_Union&) = default;
        NMService_Srv_Resp_Union(const NMService_Srv_Resp_Union&) = default;
        #else
        NMService_Srv_Resp_Union(NMService_Srv_Resp_Union&& other_) OMG_NOEXCEPT;  
        NMService_Srv_Resp_Union& operator=(NMService_Srv_Resp_Union&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& _d()  {
            return m_d_;
        }

        const uint8_t& _d() const  {
            return m_d_;
        }

        void _d(uint8_t value) {
            m_d_ = value;
        }

        bottomtotop::NMService_Set_SOA_struct& NMService_Set_SOA()  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Resp_Union::NMService_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_NMService_Set_SOA_;
        }

        const bottomtotop::NMService_Set_SOA_struct& NMService_Set_SOA() const  {
            if ( _d() != 0) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Resp_Union::NMService_Set_SOA not selected by the discriminator" );
            }
            return m_u_.m_NMService_Set_SOA_;
        }

        void NMService_Set_SOA(const bottomtotop::NMService_Set_SOA_struct& value) {
            m_u_.m_NMService_Set_SOA_ = value;
            m_d_= 0;
        }

        void NMService_Set_SOA(bottomtotop::NMService_Set_SOA_struct&& value) {
            m_u_.m_NMService_Set_SOA_ = std::move(value);
            m_d_= 0;
        }
        bottomtotop::NmXService_Ctrl_SOA_struct& NmXService_Ctrl_SOA()  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Resp_Union::NmXService_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_NmXService_Ctrl_SOA_;
        }

        const bottomtotop::NmXService_Ctrl_SOA_struct& NmXService_Ctrl_SOA() const  {
            if ( _d() != 1) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Resp_Union::NmXService_Ctrl_SOA not selected by the discriminator" );
            }
            return m_u_.m_NmXService_Ctrl_SOA_;
        }

        void NmXService_Ctrl_SOA(const bottomtotop::NmXService_Ctrl_SOA_struct& value) {
            m_u_.m_NmXService_Ctrl_SOA_ = value;
            m_d_= 1;
        }

        void NmXService_Ctrl_SOA(bottomtotop::NmXService_Ctrl_SOA_struct&& value) {
            m_u_.m_NmXService_Ctrl_SOA_ = std::move(value);
            m_d_= 1;
        }
        bottomtotop::NMService_St_array& NmService_Get_SOA()  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Resp_Union::NmService_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_NmService_Get_SOA_;
        }

        const bottomtotop::NMService_St_array& NmService_Get_SOA() const  {
            if ( _d() != 2) {
                throw ::dds::core::PreconditionNotMetError(
                    "bottomtotop::NMService_Srv_Resp_Union::NmService_Get_SOA not selected by the discriminator" );
            }
            return m_u_.m_NmService_Get_SOA_;
        }

        void NmService_Get_SOA(const bottomtotop::NMService_St_array& value) {
            m_u_.m_NmService_Get_SOA_ = value;
            m_d_= 2;
        }

        void NmService_Get_SOA(bottomtotop::NMService_St_array&& value) {
            m_u_.m_NmService_Get_SOA_ = std::move(value);
            m_d_= 2;
        }

        bool operator == (const NMService_Srv_Resp_Union& other_) const;
        bool operator != (const NMService_Srv_Resp_Union& other_) const;

        static uint8_t default_discriminator();  

        void swap(NMService_Srv_Resp_Union& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_d_;
        struct NDDSUSERDllExport Union_ {
            bottomtotop::NMService_Set_SOA_struct m_NMService_Set_SOA_;
            bottomtotop::NmXService_Ctrl_SOA_struct m_NmXService_Ctrl_SOA_;
            bottomtotop::NMService_St_array m_NmService_Get_SOA_;
            Union_();
            Union_(
                const bottomtotop::NMService_Set_SOA_struct& NMService_Set_SOA,
                const bottomtotop::NmXService_Ctrl_SOA_struct& NmXService_Ctrl_SOA,
                const bottomtotop::NMService_St_array& NmService_Get_SOA);
        };
        Union_ m_u_;

    };

    inline void swap(NMService_Srv_Resp_Union& a, NMService_Srv_Resp_Union& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NMService_Srv_Resp_Union& sample);

} // namespace bottomtotop  

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< BodyDomain::BdArm_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdArm_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdArm_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdArm_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdArm_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdArm_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdArm_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdArm_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdArm_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdArm_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdArm_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdArm_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdArm_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdArm_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdArm_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdArm_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdArm_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdArm_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdArm_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdArm_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdArm_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdArm_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdArm_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdArm_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdArm_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdArm_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdArm_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdArm_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdArm_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdArm_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdArm_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdArm_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdArm_St_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdArm_St_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdArm_St_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdArm_St_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdArm_St_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdArm_St_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdArm_St_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdArm_St_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdArm_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdArm_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdArm_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdArm_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdArm_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdArm_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdArm_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdArm_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdArm_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdArm_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdArm_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdArm_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdArm_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdArm_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdArm_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdArm_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdArm_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdArm_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdArm_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdArm_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdArm_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdArm_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdArm_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdArm_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdArm_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdArm_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdArm_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdArm_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdArm_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdArm_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdArm_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdArm_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::VsWsh_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::VsWsh_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::VsWsh_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::VsWsh_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::VsWsh_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::VsWsh_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::VsWsh_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::VsWsh_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::VsWsh_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::VsWsh_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::VsWsh_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::VsWsh_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::VsWsh_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::VsWsh_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::VsWsh_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::VsWsh_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::VsWsh_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::VsWsh_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::VsWsh_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::VsWsh_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::VsWsh_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::VsWsh_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::VsWsh_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::VsWsh_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::VsWsh_St_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::VsWsh_St_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::VsWsh_St_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::VsWsh_St_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::VsWsh_St_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::VsWsh_St_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::VsWsh_St_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::VsWsh_St_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::VsWsh_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::VsWsh_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::VsWsh_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::VsWsh_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::VsWsh_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::VsWsh_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::VsWsh_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::VsWsh_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::VsWsh_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::VsWsh_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::VsWsh_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::VsWsh_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::VsWsh_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::VsWsh_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::VsWsh_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::VsWsh_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::VsWsh_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::VsWsh_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::VsWsh_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::VsWsh_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::VsWsh_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::VsWsh_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::VsWsh_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::VsWsh_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::VsWsh_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::VsWsh_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::VsWsh_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::VsWsh_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::VsWsh_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::VsWsh_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::VsWsh_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::VsWsh_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::VsWsh_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::VsWsh_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::VsWsh_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::VsWsh_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::VsWsh_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::VsWsh_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::VsWsh_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::VsWsh_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SSd_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SSd_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SSd_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SSd_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SSd_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SSd_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SSd_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SSd_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SSd_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SSd_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SSd_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SSd_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SSd_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SSd_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SSd_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SSd_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SSd_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SSd_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SSd_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SSd_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SSd_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SSd_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SSd_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SSd_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SSd_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SSd_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SSd_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SSd_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SSd_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SSd_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SSd_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SSd_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SSd_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SSd_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SSd_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SSd_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SSd_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SSd_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SSd_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SSd_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Win_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Win_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Win_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Win_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Win_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Win_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Win_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Win_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Win_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Win_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Win_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Win_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Win_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Win_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Win_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Win_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Win_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Win_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Win_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Win_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Win_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Win_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Win_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Win_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::WinPct_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::WinPct_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::WinPct_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::WinPct_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::WinPct_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::WinPct_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::WinPct_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::WinPct_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::WinPct_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::WinPct_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::WinPct_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::WinPct_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::WinPct_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::WinPct_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::WinPct_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::WinPct_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Win_St_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Win_St_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Win_St_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Win_St_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Win_St_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Win_St_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Win_St_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Win_St_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Win_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Win_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Win_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Win_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Win_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Win_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Win_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Win_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Win_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Win_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Win_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Win_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Win_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Win_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Win_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Win_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Win_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Win_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Win_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Win_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Win_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Win_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Win_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Win_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdPst_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdPst_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdPst_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdPst_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdPst_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdPst_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdPst_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdPst_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdPst_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdPst_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdPst_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdPst_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdPst_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdPst_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdPst_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdPst_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdPst_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdPst_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdPst_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdPst_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdPst_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdPst_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdPst_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdPst_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdPst_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdPst_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdPst_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdPst_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdPst_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdPst_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdPst_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdPst_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdPst_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdPst_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdPst_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdPst_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdPst_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdPst_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdPst_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdPst_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdPst_St_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdPst_St_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdPst_St_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdPst_St_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdPst_St_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdPst_St_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdPst_St_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdPst_St_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::FLMemPstExportRsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::FLMemPstExportRsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::FLMemPstExportRsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::FLMemPstExportRsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::FLMemPstExportRsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::FLMemPstExportRsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::FLMemPstExportRsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::FLMemPstExportRsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::FRMemPstExportRsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::FRMemPstExportRsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::FRMemPstExportRsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::FRMemPstExportRsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::FRMemPstExportRsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::FRMemPstExportRsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::FRMemPstExportRsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::FRMemPstExportRsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdPst_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdPst_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdPst_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdPst_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdPst_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdPst_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdPst_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdPst_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::FLSeatMemPst_Req_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::FLSeatMemPst_Req_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::FLSeatMemPst_Req_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::FLSeatMemPst_Req_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::FLSeatMemPst_Req_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::FLSeatMemPst_Req_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::FLSeatMemPst_Req_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::FLSeatMemPst_Req_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::FRSeatMemPst_Req_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::FRSeatMemPst_Req_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::FRSeatMemPst_Req_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::FRSeatMemPst_Req_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::FRSeatMemPst_Req_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::FRSeatMemPst_Req_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::FRSeatMemPst_Req_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::FRSeatMemPst_Req_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SRLSeatMemPst_Req_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SRLSeatMemPst_Req_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SRLSeatMemPst_Req_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SRLSeatMemPst_Req_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SRLSeatMemPst_Req_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SRLSeatMemPst_Req_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SRLSeatMemPst_Req_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SRLSeatMemPst_Req_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SRRSeatMemPst_Req_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SRRSeatMemPst_Req_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SRRSeatMemPst_Req_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SRRSeatMemPst_Req_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SRRSeatMemPst_Req_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SRRSeatMemPst_Req_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SRRSeatMemPst_Req_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SRRSeatMemPst_Req_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SteerMemPst_Req_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SteerMemPst_Req_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SteerMemPst_Req_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SteerMemPst_Req_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SteerMemPst_Req_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SteerMemPst_Req_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SteerMemPst_Req_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SteerMemPst_Req_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::LExMirMemLRPst_Req_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::LExMirMemLRPst_Req_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::LExMirMemLRPst_Req_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::LExMirMemLRPst_Req_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::LExMirMemLRPst_Req_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::LExMirMemLRPst_Req_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::LExMirMemLRPst_Req_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::LExMirMemLRPst_Req_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::RExMirMemLRPst_Req_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::RExMirMemLRPst_Req_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::RExMirMemLRPst_Req_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::RExMirMemLRPst_Req_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::RExMirMemLRPst_Req_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::RExMirMemLRPst_Req_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::RExMirMemLRPst_Req_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::RExMirMemLRPst_Req_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdMemPst_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdMemPst_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdMemPst_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdMemPst_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdMemPst_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdMemPst_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdMemPst_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdMemPst_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdMemPst_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdMemPst_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdMemPst_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdMemPst_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdMemPst_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdMemPst_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdMemPst_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdMemPst_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::FLSeatMemPst_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::FLSeatMemPst_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::FLSeatMemPst_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::FLSeatMemPst_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::FLSeatMemPst_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::FLSeatMemPst_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::FLSeatMemPst_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::FLSeatMemPst_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::FRSeatMemPst_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::FRSeatMemPst_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::FRSeatMemPst_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::FRSeatMemPst_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::FRSeatMemPst_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::FRSeatMemPst_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::FRSeatMemPst_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::FRSeatMemPst_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SRLSeatMemPst_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SRLSeatMemPst_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SRLSeatMemPst_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SRLSeatMemPst_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SRLSeatMemPst_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SRLSeatMemPst_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SRLSeatMemPst_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SRLSeatMemPst_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SRRSeatMemPst_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SRRSeatMemPst_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SRRSeatMemPst_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SRRSeatMemPst_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SRRSeatMemPst_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SRRSeatMemPst_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SRRSeatMemPst_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SRRSeatMemPst_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::SteerSeatMemPst_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::SteerSeatMemPst_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::SteerSeatMemPst_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::SteerSeatMemPst_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::SteerSeatMemPst_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::SteerSeatMemPst_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::SteerSeatMemPst_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::SteerSeatMemPst_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::LExMirMemLRPst_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::LExMirMemLRPst_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::LExMirMemLRPst_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::LExMirMemLRPst_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::LExMirMemLRPst_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::LExMirMemLRPst_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::LExMirMemLRPst_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::LExMirMemLRPst_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::RExMirMemLRPst_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::RExMirMemLRPst_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::RExMirMemLRPst_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::RExMirMemLRPst_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::RExMirMemLRPst_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::RExMirMemLRPst_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::RExMirMemLRPst_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::RExMirMemLRPst_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdMemPst_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdMemPst_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdMemPst_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdMemPst_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdMemPst_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdMemPst_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdMemPst_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdMemPst_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdPst_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdPst_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdPst_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdPst_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdPst_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdPst_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdPst_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdPst_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdPst_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdPst_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdPst_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdPst_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdPst_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdPst_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdPst_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdPst_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::StAdj_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::StAdj_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::StAdj_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::StAdj_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::StAdj_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::StAdj_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::StAdj_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::StAdj_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::StAdj_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::StAdj_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::StAdj_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::StAdj_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::StAdj_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::StAdj_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::StAdj_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::StAdj_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::StAdj_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::StAdj_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::StAdj_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::StAdj_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::StAdj_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::StAdj_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::StAdj_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::StAdj_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::StAdj_St_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::StAdj_St_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::StAdj_St_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::StAdj_St_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::StAdj_St_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::StAdj_St_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::StAdj_St_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::StAdj_St_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::StAdj_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::StAdj_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::StAdj_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::StAdj_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::StAdj_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::StAdj_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::StAdj_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::StAdj_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::StAdj_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::StAdj_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::StAdj_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::StAdj_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::StAdj_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::StAdj_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::StAdj_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::StAdj_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DrLth_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DrLth_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DrLth_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DrLth_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DrLth_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DrLth_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DrLth_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DrLth_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DrLth_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DrLth_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DrLth_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DrLth_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DrLth_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DrLth_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DrLth_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DrLth_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DrLth_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DrLth_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DrLth_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DrLth_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DrLth_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DrLth_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DrLth_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DrLth_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DrLth_St_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DrLth_St_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DrLth_St_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DrLth_St_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DrLth_St_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DrLth_St_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DrLth_St_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DrLth_St_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DrLth_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DrLth_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DrLth_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DrLth_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DrLth_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DrLth_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DrLth_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DrLth_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DrLth_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DrLth_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DrLth_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DrLth_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DrLth_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DrLth_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DrLth_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DrLth_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DrLth_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DrLth_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DrLth_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DrLth_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DrLth_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DrLth_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DrLth_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DrLth_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DrLth_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DrLth_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DrLth_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DrLth_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DrLth_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DrLth_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DrLth_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DrLth_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DrLth_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DrLth_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DrLth_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DrLth_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DrLth_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DrLth_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DrLth_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DrLth_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Hdl_St_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Hdl_St_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Hdl_St_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Hdl_St_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Hdl_St_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Hdl_St_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Hdl_St_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Hdl_St_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Hdl_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Hdl_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Hdl_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Hdl_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Hdl_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Hdl_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Hdl_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Hdl_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::InLt_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::InLt_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::InLt_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::InLt_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::InLt_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::InLt_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::InLt_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::InLt_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::InLt_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::InLt_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::InLt_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::InLt_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::InLt_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::InLt_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::InLt_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::InLt_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::InLt_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::InLt_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::InLt_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::InLt_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::InLt_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::InLt_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::InLt_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::InLt_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::InLt_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::InLt_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::InLt_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::InLt_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::InLt_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::InLt_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::InLt_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::InLt_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::InLt_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::InLt_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::InLt_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::InLt_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::InLt_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::InLt_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::InLt_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::InLt_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::InLt_St_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::InLt_St_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::InLt_St_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::InLt_St_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::InLt_St_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::InLt_St_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::InLt_St_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::InLt_St_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::InLt_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::InLt_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::InLt_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::InLt_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::InLt_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::InLt_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::InLt_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::InLt_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::InLt_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::InLt_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::InLt_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::InLt_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::InLt_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::InLt_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::InLt_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::InLt_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::InLt_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::InLt_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::InLt_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::InLt_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::InLt_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::InLt_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::InLt_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::InLt_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::AmLt_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::AmLt_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::AmLt_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::AmLt_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::AmLt_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::AmLt_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::AmLt_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::AmLt_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::AmLt_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::AmLt_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::AmLt_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::AmLt_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::AmLt_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::AmLt_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::AmLt_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::AmLt_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::AmLt_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::AmLt_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::AmLt_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::AmLt_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::AmLt_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::AmLt_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::AmLt_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::AmLt_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::AmLt_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::AmLt_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::AmLt_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::AmLt_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::AmLt_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::AmLt_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::AmLt_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::AmLt_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::AmLt_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::AmLt_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::AmLt_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::AmLt_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::AmLt_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::AmLt_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::AmLt_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::AmLt_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::ExtLt_Ctrl_Struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::ExtLt_Ctrl_Struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::ExtLt_Ctrl_Struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::ExtLt_Ctrl_Struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::ExtLt_Ctrl_Struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::ExtLt_Ctrl_Struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::ExtLt_Ctrl_Struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::ExtLt_Ctrl_Struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::ExtLt_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::ExtLt_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::ExtLt_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::ExtLt_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::ExtLt_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::ExtLt_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::ExtLt_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::ExtLt_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::ExtLt_St_Struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::ExtLt_St_Struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::ExtLt_St_Struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::ExtLt_St_Struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::ExtLt_St_Struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::ExtLt_St_Struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::ExtLt_St_Struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::ExtLt_St_Struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdSf_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdSf_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdSf_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdSf_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdSf_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdSf_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdSf_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdSf_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdSf_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdSf_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdSf_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdSf_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdSf_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdSf_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdSf_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdSf_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdSf_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdSf_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdSf_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdSf_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdSf_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdSf_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdSf_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdSf_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::CgC_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::CgC_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::CgC_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::CgC_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::CgC_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::CgC_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::CgC_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::CgC_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::CgC_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::CgC_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::CgC_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::CgC_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::CgC_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::CgC_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::CgC_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::CgC_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::CgC_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::CgC_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::CgC_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::CgC_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::CgC_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::CgC_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::CgC_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::CgC_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdCft_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdCft_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdCft_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdCft_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdCft_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdCft_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdCft_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdCft_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdCft_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdCft_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdCft_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdCft_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdCft_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdCft_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdCft_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdCft_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdCft_St_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdCft_St_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdCft_St_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdCft_St_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdCft_St_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdCft_St_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdCft_St_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdCft_St_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdCft_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdCft_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdCft_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdCft_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdCft_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdCft_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdCft_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdCft_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdCft_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdCft_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdCft_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdCft_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdCft_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdCft_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdCft_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdCft_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdCft_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdCft_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdCft_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdCft_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdCft_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdCft_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdCft_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdCft_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdCft_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdCft_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdCft_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdCft_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdCft_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdCft_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdCft_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdCft_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BdCft_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BdCft_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BdCft_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BdCft_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BdCft_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BdCft_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BdCft_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BdCft_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BotSeatSync_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BotSeatSync_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BotSeatSync_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BotSeatSync_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BotSeatSync_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BotSeatSync_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BotSeatSync_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BotSeatSync_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BotSeatSync_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BotSeatSync_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BotSeatSync_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BotSeatSync_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BotSeatSync_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BotSeatSync_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BotSeatSync_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BotSeatSync_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BotSeatSync_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BotSeatSync_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BotSeatSync_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BotSeatSync_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BotSeatSync_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BotSeatSync_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BotSeatSync_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BotSeatSync_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::TargetPointSubstruct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::TargetPointSubstruct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::TargetPointSubstruct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::TargetPointSubstruct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::TargetPointSubstruct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::TargetPointSubstruct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::TargetPointSubstruct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::TargetPointSubstruct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BotScript_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BotScript_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BotScript_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BotScript_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BotScript_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BotScript_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BotScript_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BotScript_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BotScript_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BotScript_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BotScript_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BotScript_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BotScript_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BotScript_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BotScript_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BotScript_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BotMotion_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BotMotion_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BotMotion_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BotMotion_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BotMotion_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BotMotion_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BotMotion_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BotMotion_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BotMotion_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BotMotion_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BotMotion_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BotMotion_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BotMotion_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BotMotion_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BotMotion_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BotMotion_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::BotMotion_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::BotMotion_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::BotMotion_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::BotMotion_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::BotMotion_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::BotMotion_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::BotMotion_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::BotMotion_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Bot_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Bot_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Bot_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Bot_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Bot_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Bot_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Bot_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Bot_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Bot_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Bot_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Bot_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Bot_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Bot_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Bot_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Bot_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Bot_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DKLst_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DKLst_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DKLst_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DKLst_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DKLst_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DKLst_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DKLst_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DKLst_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DigitalKeyIDArray > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DigitalKeyIDArray";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DigitalKeyIDArray > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DigitalKeyIDArray > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DigitalKeyIDArray& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DigitalKeyIDArray& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DigitalKeyIDArray& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DigitalKeyIDArray& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DKLstSubstruct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DKLstSubstruct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DKLstSubstruct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DKLstSubstruct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DKLstSubstruct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DKLstSubstruct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DKLstSubstruct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DKLstSubstruct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::DKLst_Rsp_array > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::DKLst_Rsp_array";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::DKLst_Rsp_array > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::DKLst_Rsp_array > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::DKLst_Rsp_array& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::DKLst_Rsp_array& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::DKLst_Rsp_array& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::DKLst_Rsp_array& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::NFCKeyLst_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::NFCKeyLst_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::NFCKeyLst_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::NFCKeyLst_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::NFCKeyLst_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::NFCKeyLst_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::NFCKeyLst_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::NFCKeyLst_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::NFCCardIDArray > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::NFCCardIDArray";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::NFCCardIDArray > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::NFCCardIDArray > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::NFCCardIDArray& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::NFCCardIDArray& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::NFCCardIDArray& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::NFCCardIDArray& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::NFCKeyLstSubstruct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::NFCKeyLstSubstruct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::NFCKeyLstSubstruct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::NFCKeyLstSubstruct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::NFCKeyLstSubstruct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::NFCKeyLstSubstruct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::NFCKeyLstSubstruct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::NFCKeyLstSubstruct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::NFCKeyLst_Rsp_array > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::NFCKeyLst_Rsp_array";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::NFCKeyLst_Rsp_array > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::NFCKeyLst_Rsp_array > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::NFCKeyLst_Rsp_array& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::NFCKeyLst_Rsp_array& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::NFCKeyLst_Rsp_array& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::NFCKeyLst_Rsp_array& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::NFCKeyRename_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::NFCKeyRename_Set_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::NFCKeyRename_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::NFCKeyRename_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::NFCKeyRename_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::NFCKeyRename_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::NFCKeyRename_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::NFCKeyRename_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::NFCKeyRename_Rsp_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::NFCKeyRename_Rsp_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::NFCKeyRename_Rsp_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::NFCKeyRename_Rsp_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::NFCKeyRename_Rsp_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::NFCKeyRename_Rsp_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::NFCKeyRename_Rsp_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::NFCKeyRename_Rsp_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::PhysicalKeyLst_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::PhysicalKeyLst_Get_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::PhysicalKeyLst_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::PhysicalKeyLst_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::PhysicalKeyLst_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::PhysicalKeyLst_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::PhysicalKeyLst_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::PhysicalKeyLst_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::PhysicalKeyMACArray > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::PhysicalKeyMACArray";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::PhysicalKeyMACArray > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::PhysicalKeyMACArray > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::PhysicalKeyMACArray& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::PhysicalKeyMACArray& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::PhysicalKeyMACArray& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::PhysicalKeyMACArray& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::PhysicalKeyLstSubstruct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::PhysicalKeyLstSubstruct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::PhysicalKeyLstSubstruct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::PhysicalKeyLstSubstruct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::PhysicalKeyLstSubstruct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::PhysicalKeyLstSubstruct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::PhysicalKeyLstSubstruct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::PhysicalKeyLstSubstruct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::PhysicalKeyLst_Rsp_array > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::PhysicalKeyLst_Rsp_array";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::PhysicalKeyLst_Rsp_array > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::PhysicalKeyLst_Rsp_array > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::PhysicalKeyLst_Rsp_array& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::PhysicalKeyLst_Rsp_array& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::PhysicalKeyLst_Rsp_array& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::PhysicalKeyLst_Rsp_array& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::NFCKeyMag_Crtl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::NFCKeyMag_Crtl_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::NFCKeyMag_Crtl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::NFCKeyMag_Crtl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::NFCKeyMag_Crtl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::NFCKeyMag_Crtl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::NFCKeyMag_Crtl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::NFCKeyMag_Crtl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::NFCKeyMag_Crtl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::NFCKeyMag_Crtl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::NFCKeyMag_Crtl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::NFCKeyMag_Crtl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::NFCKeyMag_Crtl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::NFCKeyMag_Crtl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::NFCKeyMag_Crtl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::NFCKeyMag_Crtl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::NFCKeyMag_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::NFCKeyMag_St_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::NFCKeyMag_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::NFCKeyMag_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::NFCKeyMag_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::NFCKeyMag_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::NFCKeyMag_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::NFCKeyMag_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::TargetPointStruct_Array > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::TargetPointStruct_Array";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::TargetPointStruct_Array > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::TargetPointStruct_Array > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::TargetPointStruct_Array& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::TargetPointStruct_Array& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::TargetPointStruct_Array& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::TargetPointStruct_Array& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Key_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Key_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Key_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Key_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Key_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Key_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Key_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Key_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::Key_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::Key_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::Key_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::Key_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::Key_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::Key_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::Key_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::Key_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< BodyDomain::KeyInfo_Notify_struct > {
            NDDSUSERDllExport static std::string value() {
                return "BodyDomain::KeyInfo_Notify_struct";
            }
        };

        template<>
        struct is_topic_type< BodyDomain::KeyInfo_Notify_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< BodyDomain::KeyInfo_Notify_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const BodyDomain::KeyInfo_Notify_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(BodyDomain::KeyInfo_Notify_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(BodyDomain::KeyInfo_Notify_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(BodyDomain::KeyInfo_Notify_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::PowerMode_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::PowerMode_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::PowerMode_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::PowerMode_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::PowerMode_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::PowerMode_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::PowerMode_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::PowerMode_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::PowerMode_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::PowerMode_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::PowerMode_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::PowerMode_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::PowerMode_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::PowerMode_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::PowerMode_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::PowerMode_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::PowerMode_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::PowerMode_St_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::PowerMode_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::PowerMode_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::PowerMode_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::PowerMode_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::PowerMode_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::PowerMode_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::CarMode_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::CarMode_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::CarMode_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::CarMode_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::CarMode_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::CarMode_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::CarMode_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::CarMode_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::CarMode_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::CarMode_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::CarMode_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::CarMode_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::CarMode_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::CarMode_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::CarMode_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::CarMode_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::CarMode_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::CarMode_St_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::CarMode_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::CarMode_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::CarMode_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::CarMode_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::CarMode_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::CarMode_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::DrivingMode_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::DrivingMode_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::DrivingMode_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::DrivingMode_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::DrivingMode_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::DrivingMode_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::DrivingMode_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::DrivingMode_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::DrivingMode_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::DrivingMode_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::DrivingMode_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::DrivingMode_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::DrivingMode_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::DrivingMode_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::DrivingMode_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::DrivingMode_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::DringMode_St_Struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::DringMode_St_Struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::DringMode_St_Struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::DringMode_St_Struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::DringMode_St_Struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::DringMode_St_Struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::DringMode_St_Struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::DringMode_St_Struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::VehicleMode_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::VehicleMode_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< PTDomain::VehicleMode_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::VehicleMode_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::VehicleMode_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::VehicleMode_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::VehicleMode_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::VehicleMode_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::VehicleMode_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::VehicleMode_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< PTDomain::VehicleMode_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::VehicleMode_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::VehicleMode_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::VehicleMode_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::VehicleMode_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::VehicleMode_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::CHS_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::CHS_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::CHS_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::CHS_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::CHS_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::CHS_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::CHS_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::CHS_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::CHS_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::CHS_St_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::CHS_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::CHS_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::CHS_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::CHS_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::CHS_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::CHS_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< PTDomain::CHS_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "PTDomain::CHS_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< PTDomain::CHS_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PTDomain::CHS_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PTDomain::CHS_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PTDomain::CHS_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PTDomain::CHS_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PTDomain::CHS_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< EnergyDomain::AC_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "EnergyDomain::AC_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< EnergyDomain::AC_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< EnergyDomain::AC_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const EnergyDomain::AC_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(EnergyDomain::AC_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(EnergyDomain::AC_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(EnergyDomain::AC_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< EnergyDomain::AC_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "EnergyDomain::AC_St_struct";
            }
        };

        template<>
        struct is_topic_type< EnergyDomain::AC_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< EnergyDomain::AC_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const EnergyDomain::AC_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(EnergyDomain::AC_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(EnergyDomain::AC_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(EnergyDomain::AC_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< EnergyDomain::Thermal_St_struct > {
            NDDSUSERDllExport static std::string value() {
                return "EnergyDomain::Thermal_St_struct";
            }
        };

        template<>
        struct is_topic_type< EnergyDomain::Thermal_St_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< EnergyDomain::Thermal_St_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const EnergyDomain::Thermal_St_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(EnergyDomain::Thermal_St_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(EnergyDomain::Thermal_St_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(EnergyDomain::Thermal_St_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< EnergyDomain::AC_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "EnergyDomain::AC_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< EnergyDomain::AC_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< EnergyDomain::AC_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const EnergyDomain::AC_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(EnergyDomain::AC_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(EnergyDomain::AC_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(EnergyDomain::AC_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< Temporary::GeneralVehSt_Struct > {
            NDDSUSERDllExport static std::string value() {
                return "Temporary::GeneralVehSt_Struct";
            }
        };

        template<>
        struct is_topic_type< Temporary::GeneralVehSt_Struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Temporary::GeneralVehSt_Struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Temporary::GeneralVehSt_Struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Temporary::GeneralVehSt_Struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Temporary::GeneralVehSt_Struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Temporary::GeneralVehSt_Struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< Temporary::PTHMI_struct > {
            NDDSUSERDllExport static std::string value() {
                return "Temporary::PTHMI_struct";
            }
        };

        template<>
        struct is_topic_type< Temporary::PTHMI_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Temporary::PTHMI_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Temporary::PTHMI_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Temporary::PTHMI_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Temporary::PTHMI_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Temporary::PTHMI_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< Temporary::CHSHMI_struct > {
            NDDSUSERDllExport static std::string value() {
                return "Temporary::CHSHMI_struct";
            }
        };

        template<>
        struct is_topic_type< Temporary::CHSHMI_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Temporary::CHSHMI_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Temporary::CHSHMI_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Temporary::CHSHMI_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Temporary::CHSHMI_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Temporary::CHSHMI_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< Temporary::WiperWash_Ctrl_Struct > {
            NDDSUSERDllExport static std::string value() {
                return "Temporary::WiperWash_Ctrl_Struct";
            }
        };

        template<>
        struct is_topic_type< Temporary::WiperWash_Ctrl_Struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Temporary::WiperWash_Ctrl_Struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Temporary::WiperWash_Ctrl_Struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Temporary::WiperWash_Ctrl_Struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Temporary::WiperWash_Ctrl_Struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Temporary::WiperWash_Ctrl_Struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< Temporary::SN_info_string > {
            NDDSUSERDllExport static std::string value() {
                return "Temporary::SN_info_string";
            }
        };

        template<>
        struct is_topic_type< Temporary::SN_info_string > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Temporary::SN_info_string > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Temporary::SN_info_string& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Temporary::SN_info_string& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Temporary::SN_info_string& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Temporary::SN_info_string& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< bottomtotop::NMService_Set_struct > {
            NDDSUSERDllExport static std::string value() {
                return "bottomtotop::NMService_Set_struct";
            }
        };

        template<>
        struct is_topic_type< bottomtotop::NMService_Set_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< bottomtotop::NMService_Set_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const bottomtotop::NMService_Set_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(bottomtotop::NMService_Set_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(bottomtotop::NMService_Set_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(bottomtotop::NMService_Set_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< bottomtotop::NMService_Set_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "bottomtotop::NMService_Set_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< bottomtotop::NMService_Set_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< bottomtotop::NMService_Set_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const bottomtotop::NMService_Set_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(bottomtotop::NMService_Set_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(bottomtotop::NMService_Set_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(bottomtotop::NMService_Set_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< bottomtotop::NmXService_Ctrl_struct > {
            NDDSUSERDllExport static std::string value() {
                return "bottomtotop::NmXService_Ctrl_struct";
            }
        };

        template<>
        struct is_topic_type< bottomtotop::NmXService_Ctrl_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< bottomtotop::NmXService_Ctrl_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const bottomtotop::NmXService_Ctrl_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(bottomtotop::NmXService_Ctrl_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(bottomtotop::NmXService_Ctrl_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(bottomtotop::NmXService_Ctrl_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< bottomtotop::NmXService_Ctrl_Array > {
            NDDSUSERDllExport static std::string value() {
                return "bottomtotop::NmXService_Ctrl_Array";
            }
        };

        template<>
        struct is_topic_type< bottomtotop::NmXService_Ctrl_Array > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< bottomtotop::NmXService_Ctrl_Array > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const bottomtotop::NmXService_Ctrl_Array& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(bottomtotop::NmXService_Ctrl_Array& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(bottomtotop::NmXService_Ctrl_Array& sample);

            NDDSUSERDllExport 
            static void allocate_sample(bottomtotop::NmXService_Ctrl_Array& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< bottomtotop::NmXService_Ctrl_SOA_struct > {
            NDDSUSERDllExport static std::string value() {
                return "bottomtotop::NmXService_Ctrl_SOA_struct";
            }
        };

        template<>
        struct is_topic_type< bottomtotop::NmXService_Ctrl_SOA_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< bottomtotop::NmXService_Ctrl_SOA_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const bottomtotop::NmXService_Ctrl_SOA_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(bottomtotop::NmXService_Ctrl_SOA_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(bottomtotop::NmXService_Ctrl_SOA_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(bottomtotop::NmXService_Ctrl_SOA_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< bottomtotop::NmService_Get_struct > {
            NDDSUSERDllExport static std::string value() {
                return "bottomtotop::NmService_Get_struct";
            }
        };

        template<>
        struct is_topic_type< bottomtotop::NmService_Get_struct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< bottomtotop::NmService_Get_struct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const bottomtotop::NmService_Get_struct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(bottomtotop::NmService_Get_struct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(bottomtotop::NmService_Get_struct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(bottomtotop::NmService_Get_struct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< bottomtotop::NMService_St_substruct > {
            NDDSUSERDllExport static std::string value() {
                return "bottomtotop::NMService_St_substruct";
            }
        };

        template<>
        struct is_topic_type< bottomtotop::NMService_St_substruct > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< bottomtotop::NMService_St_substruct > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const bottomtotop::NMService_St_substruct& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(bottomtotop::NMService_St_substruct& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(bottomtotop::NMService_St_substruct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(bottomtotop::NMService_St_substruct& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< bottomtotop::NMService_St_array > {
            NDDSUSERDllExport static std::string value() {
                return "bottomtotop::NMService_St_array";
            }
        };

        template<>
        struct is_topic_type< bottomtotop::NMService_St_array > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< bottomtotop::NMService_St_array > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const bottomtotop::NMService_St_array& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(bottomtotop::NMService_St_array& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(bottomtotop::NMService_St_array& sample);

            NDDSUSERDllExport 
            static void allocate_sample(bottomtotop::NMService_St_array& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< bottomtotop::NMService_Srv_Req_Union > {
            NDDSUSERDllExport static std::string value() {
                return "bottomtotop::NMService_Srv_Req_Union";
            }
        };

        template<>
        struct is_topic_type< bottomtotop::NMService_Srv_Req_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< bottomtotop::NMService_Srv_Req_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const bottomtotop::NMService_Srv_Req_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(bottomtotop::NMService_Srv_Req_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(bottomtotop::NMService_Srv_Req_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(bottomtotop::NMService_Srv_Req_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< bottomtotop::NMService_Srv_Resp_Union > {
            NDDSUSERDllExport static std::string value() {
                return "bottomtotop::NMService_Srv_Resp_Union";
            }
        };

        template<>
        struct is_topic_type< bottomtotop::NMService_Srv_Resp_Union > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< bottomtotop::NMService_Srv_Resp_Union > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const bottomtotop::NMService_Srv_Resp_Union& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(bottomtotop::NMService_Srv_Resp_Union& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(bottomtotop::NMService_Srv_Resp_Union& sample);

            NDDSUSERDllExport 
            static void allocate_sample(bottomtotop::NMService_Srv_Resp_Union& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdArm_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdArm_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdArm_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdArm_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdArm_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdArm_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdArm_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdArm_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdArm_St_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdArm_St_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdArm_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdArm_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdArm_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdArm_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdArm_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdArm_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdArm_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdArm_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::VsWsh_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::VsWsh_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::VsWsh_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::VsWsh_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::VsWsh_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::VsWsh_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::VsWsh_St_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::VsWsh_St_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::VsWsh_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::VsWsh_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::VsWsh_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::VsWsh_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::VsWsh_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::VsWsh_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::VsWsh_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::VsWsh_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::VsWsh_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::VsWsh_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SSd_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SSd_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SSd_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SSd_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SSd_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SSd_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SSd_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SSd_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SSd_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SSd_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Win_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Win_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Win_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Win_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Win_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Win_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::WinPct_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::WinPct_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::WinPct_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::WinPct_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Win_St_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Win_St_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Win_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Win_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Win_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Win_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Win_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Win_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdPst_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdPst_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdPst_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdPst_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdPst_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdPst_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdPst_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdPst_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdPst_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdPst_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdPst_St_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdPst_St_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::FLMemPstExportRsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::FLMemPstExportRsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::FRMemPstExportRsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::FRMemPstExportRsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdPst_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdPst_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::FLSeatMemPst_Req_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::FLSeatMemPst_Req_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::FRSeatMemPst_Req_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::FRSeatMemPst_Req_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SRLSeatMemPst_Req_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SRLSeatMemPst_Req_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SRRSeatMemPst_Req_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SRRSeatMemPst_Req_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SteerMemPst_Req_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SteerMemPst_Req_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::LExMirMemLRPst_Req_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::LExMirMemLRPst_Req_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::RExMirMemLRPst_Req_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::RExMirMemLRPst_Req_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdMemPst_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdMemPst_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdMemPst_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdMemPst_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::FLSeatMemPst_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::FLSeatMemPst_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::FRSeatMemPst_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::FRSeatMemPst_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SRLSeatMemPst_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SRLSeatMemPst_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SRRSeatMemPst_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SRRSeatMemPst_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::SteerSeatMemPst_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::SteerSeatMemPst_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::LExMirMemLRPst_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::LExMirMemLRPst_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::RExMirMemLRPst_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::RExMirMemLRPst_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdMemPst_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdMemPst_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdPst_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdPst_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdPst_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdPst_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::StAdj_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::StAdj_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::StAdj_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::StAdj_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::StAdj_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::StAdj_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::StAdj_St_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::StAdj_St_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::StAdj_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::StAdj_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::StAdj_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::StAdj_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DrLth_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DrLth_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DrLth_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DrLth_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DrLth_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DrLth_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DrLth_St_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DrLth_St_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DrLth_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DrLth_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DrLth_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DrLth_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DrLth_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DrLth_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DrLth_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DrLth_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DrLth_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DrLth_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Hdl_St_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Hdl_St_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Hdl_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Hdl_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::InLt_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::InLt_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::InLt_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::InLt_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::InLt_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::InLt_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::InLt_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::InLt_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::InLt_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::InLt_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::InLt_St_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::InLt_St_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::InLt_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::InLt_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::InLt_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::InLt_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::InLt_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::InLt_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::AmLt_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::AmLt_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::AmLt_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::AmLt_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::AmLt_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::AmLt_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::AmLt_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::AmLt_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::AmLt_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::AmLt_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::ExtLt_Ctrl_Struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::ExtLt_Ctrl_Struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::ExtLt_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::ExtLt_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::ExtLt_St_Struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::ExtLt_St_Struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdSf_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdSf_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdSf_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdSf_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdSf_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdSf_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::CgC_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::CgC_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::CgC_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::CgC_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::CgC_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::CgC_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdCft_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdCft_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdCft_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdCft_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdCft_St_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdCft_St_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdCft_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdCft_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdCft_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdCft_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdCft_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdCft_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdCft_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdCft_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BdCft_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BdCft_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BotSeatSync_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BotSeatSync_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BotSeatSync_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BotSeatSync_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BotSeatSync_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BotSeatSync_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::TargetPointSubstruct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::TargetPointSubstruct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BotScript_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BotScript_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BotScript_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BotScript_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BotMotion_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BotMotion_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BotMotion_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BotMotion_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::BotMotion_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::BotMotion_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Bot_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Bot_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Bot_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Bot_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DKLst_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DKLst_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DigitalKeyIDArray > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DigitalKeyIDArray > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DKLstSubstruct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DKLstSubstruct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::DKLst_Rsp_array > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::DKLst_Rsp_array > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::NFCKeyLst_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::NFCKeyLst_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::NFCCardIDArray > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::NFCCardIDArray > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::NFCKeyLstSubstruct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::NFCKeyLstSubstruct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::NFCKeyLst_Rsp_array > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::NFCKeyLst_Rsp_array > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::NFCKeyRename_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::NFCKeyRename_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::NFCKeyRename_Rsp_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::NFCKeyRename_Rsp_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::PhysicalKeyLst_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::PhysicalKeyLst_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::PhysicalKeyMACArray > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::PhysicalKeyMACArray > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::PhysicalKeyLstSubstruct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::PhysicalKeyLstSubstruct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::PhysicalKeyLst_Rsp_array > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::PhysicalKeyLst_Rsp_array > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::NFCKeyMag_Crtl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::NFCKeyMag_Crtl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::NFCKeyMag_Crtl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::NFCKeyMag_Crtl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::NFCKeyMag_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::NFCKeyMag_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::TargetPointStruct_Array > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::TargetPointStruct_Array > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Key_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Key_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::Key_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::Key_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< BodyDomain::KeyInfo_Notify_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< BodyDomain::KeyInfo_Notify_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::PowerMode_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::PowerMode_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::PowerMode_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::PowerMode_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::PowerMode_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::PowerMode_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::CarMode_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::CarMode_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::CarMode_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::CarMode_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::CarMode_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::CarMode_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::DrivingMode_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::DrivingMode_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::DrivingMode_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::DrivingMode_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::DringMode_St_Struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::DringMode_St_Struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::VehicleMode_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::VehicleMode_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::VehicleMode_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::VehicleMode_Srv_Resp_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::CHS_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::CHS_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::CHS_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::CHS_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PTDomain::CHS_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PTDomain::CHS_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< EnergyDomain::AC_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< EnergyDomain::AC_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< EnergyDomain::AC_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< EnergyDomain::AC_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< EnergyDomain::Thermal_St_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< EnergyDomain::Thermal_St_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< EnergyDomain::AC_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< EnergyDomain::AC_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Temporary::GeneralVehSt_Struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Temporary::GeneralVehSt_Struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Temporary::PTHMI_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Temporary::PTHMI_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Temporary::CHSHMI_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Temporary::CHSHMI_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Temporary::WiperWash_Ctrl_Struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Temporary::WiperWash_Ctrl_Struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Temporary::SN_info_string > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Temporary::SN_info_string > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bottomtotop::NMService_Set_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< bottomtotop::NMService_Set_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bottomtotop::NMService_Set_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< bottomtotop::NMService_Set_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bottomtotop::NmXService_Ctrl_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< bottomtotop::NmXService_Ctrl_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bottomtotop::NmXService_Ctrl_Array > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< bottomtotop::NmXService_Ctrl_Array > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bottomtotop::NmXService_Ctrl_SOA_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< bottomtotop::NmXService_Ctrl_SOA_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bottomtotop::NmService_Get_struct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< bottomtotop::NmService_Get_struct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bottomtotop::NMService_St_substruct > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< bottomtotop::NMService_St_substruct > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bottomtotop::NMService_St_array > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< bottomtotop::NMService_St_array > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bottomtotop::NMService_Srv_Req_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< bottomtotop::NMService_Srv_Req_Union > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< bottomtotop::NMService_Srv_Resp_Union > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< bottomtotop::NMService_Srv_Resp_Union > {
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

#endif // DDSServiceInterfaceIV3_1314393390_hpp

