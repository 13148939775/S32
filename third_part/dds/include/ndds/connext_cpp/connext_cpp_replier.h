/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)connext_cpp_replier.h    generated by: makeheader    Wed Mar  9 22:41:54 2022
 *
 *		built from:	replier.ifcxx
 */

#ifndef connext_cpp_replier_h
#define connext_cpp_replier_h



#include <string>
#include <algorithm>
#include <iterator>

#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif

#ifndef xmq_cpp_dll_h
  #include "connext_cpp/connext_cpp_dll.h"
#endif

#ifndef xmq_cpp_general_replier_details_h
  #include "connext_cpp/connext_cpp_general_replier_details.h"
#endif

#ifndef xmq_cpp_infrastructure_h
  #include "connext_cpp/connext_cpp_infrastructure.h"
#endif

namespace connext {

typedef ::DDS_SampleInfo ReplyInfo;

template <class TReq, class TRep>
class ReplierListener;

template <class TReq, class TRep>
class ReplierParams;

// --- General Replier: -------------------------------------------------------------

/*e \dref_Replier
 */
template <typename TReq, typename TRep>
class XMQCPPDllExport Replier {
public:

    // --- types: -------------------------------------------------------------

    /**
     * @brief The request type
     */
    typedef TReq Request;

    /**
     * @brief The reply type
     */
    typedef TRep Reply;

    /**
     * @brief The typed DataWriter for type \p TRep
     */
    typedef typename dds_type_traits<TRep>::DataWriter ReplyDataWriter;

    /**
     * @brief The typed DataReader for type \p TReq
     */
    typedef typename dds_type_traits<TReq>::DataReader RequestDataReader;

    typedef ReplierParams<TReq, TRep> Params;
    typedef typename dds_type_traits<TReq>::LoanedSamplesType LoanedSamplesType;

    /**
     * \dref_Replier_new
     */
    Replier(DDSDomainParticipant * participant,
            const std::string& service_name);

    /**
     * \dref_Replier_new_w_params
     */
    explicit Replier(const ReplierParams<TReq, TRep> & params);

    void swap(Replier & other);

    /**
     * \dref_Replier_finalize
     */
    virtual ~Replier();

    /**
     * \dref_Replier_send_reply
     */
    template <typename URep>
    void send_reply(
        const URep & reply,
        const SampleIdentity_t& related_request_id);

    /**
     * \dref_Replier_send_reply_w_writesample
     */
    template<typename URep>
    void send_reply(
        WriteSample<URep> & reply,
        const SampleIdentity_t& related_request_id);

    /**
     * \dref_Replier_send_reply_w_writesampleref
     */
    template<typename URep>
    void send_reply(
        WriteSampleRef<URep> & reply,
        const SampleIdentity_t& related_request_id);


    /**
     * \dref_Replier_receive_request
     */
    bool receive_request(connext::Sample<TReq> & request,
                         const DDS_Duration_t & max_wait);

    /**
     * \dref_Replier_receive_request_sampleref
     */
    bool receive_request(connext::SampleRef<TReq> request,
                         const DDS_Duration_t & max_wait);

    /**
     * \dref_Replier_receive_requests_simple
     */
    LoanedSamplesType receive_requests(const DDS_Duration_t & max_wait);

    /**
     * \dref_Replier_receive_requests
     */
    LoanedSamplesType receive_requests(int min_request_count,
                                        int max_request_count,
                                        const DDS_Duration_t& max_wait);

    /**
     * \dref_Replier_wait_for_requests_simple
     */
    bool wait_for_requests(const DDS_Duration_t & max_wait);

    /**
     * \dref_Replier_wait_for_requests
     */
    bool wait_for_requests(int min_count, const DDS_Duration_t & max_wait);

    /**
     * \dref_Replier_take_request
     */
    bool take_request(connext::Sample<TReq> & request);

    /**
     * \dref_Replier_take_request_sampleref
     */
    bool take_request(connext::SampleRef<TReq> request);

    /**
     * \dref_Replier_take_requests
     */
    LoanedSamplesType take_requests(int max_samples = DDS_LENGTH_UNLIMITED);

    /**
     * \dref_Replier_read_request
     */
    bool read_request(connext::Sample<TReq> & request);

    /**
     * \dref_Replier_read_request_sampleref
     */
    bool read_request(connext::SampleRef<TReq> request);

    /**
     * \dref_Replier_read_requests
     */
    LoanedSamplesType read_requests(int max_samples = DDS_LENGTH_UNLIMITED);


    /**
     * \dref_Replier_get_request_datareader
     */
    inline RequestDataReader * get_request_datareader() const;

    /**
     * \dref_Replier_get_reply_datawriter
     */
    inline ReplyDataWriter * get_reply_datawriter() const;

private:

    // Don't remove these function declarations.
    // This function is deliberately private to prevent user from calling send_reply with 
    // const WriteSample and const WriteSampleRef. Without this declaration, the call 
    // will go to the catch-all send_reply<URep> function and it will fail at run-time.
    template <typename URep>
    void send_reply(
        const WriteSample<TRep> & reply,
        const SampleIdentity_t& related_request_id);

    template <typename URep>
    void send_reply(
        const WriteSampleRef<TRep> & reply,
        const SampleIdentity_t& related_request_id);

    connext::details::GeneralReplierImpl<TReq, TRep> * _pImpl;

    Replier(const Replier & other);
    Replier & operator = (const Replier & other);
};

template <class TReq, class TRep>
void swap(Replier<TReq, TRep> & cr1,  
          Replier<TReq, TRep> & cr2)
{
    cr1.swap(cr2);
}

} // namespace connext

// --- Implementation: -------------------------------------------------------

namespace connext {

template <typename TReq, typename TRep>
Replier<TReq, TRep>::Replier(DDS::DomainParticipant * participant,
                             const std::string& service_name) 
    : _pImpl(new details::GeneralReplierImpl<TReq, TRep>(
                    participant, service_name))
{
    _pImpl->set_replier(this);
}

template <typename TReq, typename TRep>
Replier<TReq, TRep>::Replier(const ReplierParams<TReq, TRep> & params) 
    : _pImpl(new details::GeneralReplierImpl<TReq, TRep>(params))
{
    _pImpl->set_replier(this);
}

template <typename TReq, typename TRep>
void Replier<TReq, TRep>::swap(Replier & other)
{
    // Swapping two pointers is automic on most platfroms 
    // so I hope there is no race condition here. 
    // However, swapping two repliers do not swap their listeners. 
    // For example, consider SR=SimpleReplier and L=Listener
    // if SR1 had L1 and SR2 had L2. After swapping,
    // SR1 will callback L2 and SR2 will callback L1.
    // This is anologous to how std::vector iterators get swapped.
    std::swap(_pImpl, other._pImpl);
}

template <typename TReq, typename TRep>
Replier<TReq, TRep>::~Replier() 
{
    delete _pImpl;
}

template<typename TReq, typename TRep>
typename Replier<TReq, TRep>::ReplyDataWriter * 
Replier<TReq, TRep>::get_reply_datawriter() const
{
    const char * METHOD_NAME = "get_reply_datawriter";
    try {
        return _pImpl->get_reply_datawriter();
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return NULL; // unreachable
}

template<typename TReq, typename TRep>
typename Replier<TReq, TRep>::RequestDataReader *
Replier<TReq, TRep>::get_request_datareader() const
{
    const char * METHOD_NAME = "get_request_datareader";
    try {
        return _pImpl->get_request_datareader();
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return NULL; // unreachable
}

template<typename TReq, typename TRep>
bool Replier<TReq, TRep>::take_request(
    connext::Sample<TReq> & request)
{
    const char * METHOD_NAME = "take_requests";
    try {
        return _pImpl->get_request(request, true);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return false; // unreachable
}

template<typename TReq, typename TRep>
bool Replier<TReq, TRep>::take_request(
    connext::SampleRef<TReq> request)
{
    const char * METHOD_NAME = "take_requests";
    try {
        return _pImpl->get_request(request, true);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return false; // unreachable
}

template<typename TReq, typename TRep>
typename Replier<TReq, TRep>::LoanedSamplesType
Replier<TReq, TRep>::take_requests(int max_samples)
{
    const char * METHOD_NAME = "take_requests";
    try {
        return _pImpl->get_requests(max_samples, true);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return LoanedSamplesType(); // unreachable
}


template<typename TReq, typename TRep>
bool Replier<TReq, TRep>::read_request(
    connext::Sample<TReq> & request)
{
    const char * METHOD_NAME = "read_requests";
    try {
        return _pImpl->get_request(request, false);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return false; // unreachable
}

template<typename TReq, typename TRep>
bool Replier<TReq, TRep>::read_request(
    connext::SampleRef<TReq> request)
{
    const char * METHOD_NAME = "read_requests";
    try {
        return _pImpl->get_request(request, false);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return false; // unreachable
}

template<typename TReq, typename TRep>
typename Replier<TReq, TRep>::LoanedSamplesType
Replier<TReq, TRep>::read_requests(int max_samples)
{
    const char * METHOD_NAME = "read_requests";
    try {
        return _pImpl->get_requests(max_samples, false);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return LoanedSamplesType(); // unreachable
}

template<typename TReq, typename TRep>
bool Replier<TReq, TRep>::wait_for_requests(const DDS_Duration_t & max_wait)
{
    const char * METHOD_NAME = "wait_for_requests";
    try {
        return _pImpl->wait_for_requests(max_wait);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return false; // unreachable
}

template<typename TReq, typename TRep>
bool Replier<TReq, TRep>::wait_for_requests(
    int min_count, const DDS_Duration_t & max_wait)
{
    const char * METHOD_NAME = "wait_for_requests";
    try {
        return _pImpl->wait_for_requests(min_count, max_wait);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return false; // unreachable
}

template<typename TReq, typename TRep>
bool Replier<TReq, TRep>::receive_request(
    connext::Sample<TReq> & request,
    const DDS_Duration_t & max_wait)
{
    const char * METHOD_NAME = "receive_request";
    try {
        return _pImpl->receive_request(request, max_wait);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return false; // unreachable
}

template<typename TReq, typename TRep>
bool Replier<TReq, TRep>::receive_request(
    connext::SampleRef<TReq> request,
    const DDS_Duration_t & max_wait)
{
    const char * METHOD_NAME = "receive_request";
    try {
        return _pImpl->receive_request(request, max_wait);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return false; // unreachable
}

template<typename TReq, typename TRep>
typename Replier<TReq, TRep>::LoanedSamplesType 
Replier<TReq, TRep>::receive_requests(
    const DDS_Duration_t & max_wait)
{
    const char * METHOD_NAME = "receive_requests";
    try {
        return _pImpl->receive_requests(max_wait);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return LoanedSamplesType(); // unreachable
}

template<typename TReq, typename TRep>
typename Replier<TReq, TRep>::LoanedSamplesType
Replier<TReq, TRep>::receive_requests(
    int min_request_count, int max_request_count,
    const DDS_Duration_t& max_wait)
{
    const char * METHOD_NAME = "receive_requests";
    try {
        return _pImpl->receive_requests(min_request_count, max_request_count,
            max_wait);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }

    return LoanedSamplesType(); // unreachable
}

template<typename TReq, typename TRep>
template<typename URep>
void Replier<TReq, TRep>::send_reply(
    const URep & reply,
    const SampleIdentity_t& related_request_id)
{
    const char * METHOD_NAME = "send_reply";
    try {
        _pImpl->send_reply_impl(reply, related_request_id);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }
}

template<typename TReq, typename TRep>
template<typename URep>
void Replier<TReq, TRep>::send_reply(
    WriteSample<URep> & reply,
    const SampleIdentity_t& related_request_id)
{
    const char * METHOD_NAME = "send_reply";

    try {
        _pImpl->send_reply_impl(reply, related_request_id);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }
}

template<typename TReq, typename TRep>
template<typename URep>
void Replier<TReq, TRep>::send_reply(
    WriteSampleRef<URep> & reply,
    const SampleIdentity_t& related_request_id)
{
    const char * METHOD_NAME = "send_reply";

    try {
        _pImpl->send_reply_impl(reply, related_request_id);
    } catch (Rethrowable& ex) {
        _pImpl->log_and_rethrow(ex, METHOD_NAME);
    }
}


} // namespace connext



#endif /* connext_cpp_replier_h */
