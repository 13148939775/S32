/*
 * @author 008555
 * @for dds request and reply module
 * @version 1.0
 * @date 2023-06 ~ 2023-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DDSSERVICE_H
#define DDSSERVICE_H

#include <string>
#include <string.h>
#include <memory>

#include <rti/request/rtirequest.hpp>

namespace DDSservice
{
    static dds::core::QosProvider g_qos_provider("./USER1_QOS_PROFILES.xml");

    static std::string replier_Qos = "RequestReplyExampleProfiles::ReplierExampleProfile";
    static std::string request_Qos = "RequestReplyExampleProfiles::RequesterExampleProfile";
    // 域参与者，建议只用一个或少用
    static dds::domain::DomainParticipant g_domain_participant(0, g_qos_provider.participant_qos("RequestReplyExampleProfiles::default"));
    
    
    
    /**
     * @brief 请求方
     *
     * @tparam requesterDataType
     * @tparam replierDataType
     */
    template <typename requesterDataType, typename replierDataType>
    class DDSrequester
    {
    public:
        /**
         * @brief Construct a new DDSrequester object
         *
         */
        DDSrequester()
            : m_is_requester_created(false),
              m_requester_params(g_domain_participant)
        {
            // TODO
        }
        virtual ~DDSrequester() = default;

        void InitRequester(const std::string &request_topic_name,
                           const std::string &reply_topic_name)
        {
            SetDataReaderQoS(request_Qos);
            SetDataWriterQoS(request_Qos);
            SetRequestTopicName(request_topic_name);
            SetReplyTopicName(reply_topic_name);
        }
        /**
         *
         * @brief Set the Data Reader Qo S object
         *
         * @param data_reader_qos
         */
        void SetDataReaderQoS(const std::string &data_reader_qos)
        {
            m_requester_params.datareader_qos(g_qos_provider.datareader_qos(data_reader_qos));
        }

        /**
         * @brief Set the Data Writer Qo S object
         *
         * @param data_writer_qos
         */
        void SetDataWriterQoS(const std::string &data_writer_qos)
        {
            m_requester_params.datawriter_qos(g_qos_provider.datawriter_qos(data_writer_qos));
        }

        /**
         * @brief Set the Request Topic Name object
         *
         * @param request_topic_name
         */
        void SetRequestTopicName(const std::string &request_topic_name)
        {
            m_requester_params.request_topic_name(request_topic_name);
        }

        /**
         * @brief Get the Request Topic Name object
         *
         * @return const char*
         */
        const char *GetRequestTopicName() const
        {
            return m_requester_params.request_topic_name().c_str();
        }

        /**
         * @brief Set the Reply Topic Name object
         *
         * @param reply_topic_name
         */
        void SetReplyTopicName(const std::string &reply_topic_name)
        {
            m_requester_params.reply_topic_name(reply_topic_name);
        }

        /**
         * @brief Get the Reply Topic Name object
         *
         * @return const char*
         */
        const char *GetReplyTopicName() const
        {
            return m_requester_params.reply_topic_name().c_str();
        }

        /**
         * @brief Set the Max Wait Time object
         *
         * @param seconds
         */
        void SetMaxWaitTime(const double &seconds)
        {
            m_max_wait_time = dds::core::Duration::from_secs(seconds);
        }

        /**
         * @brief Get the Max Wait Time object
         *
         * @return int
         */
        int GetMaxWaitTime() const
        {
            return m_max_wait_time.sec();
        }

        /**
         * @brief Create a Requester object
         *
         */
        void CreateRequester()
        {
            m_requester_ptr = std::make_shared<rti::request::Requester<requesterDataType, replierDataType>>(m_requester_params);

            m_is_requester_created = true;
        }

        /**
         * @brief 发送请求
         *
         * @param data
         */
        void SendRequests(const requesterDataType &data)
        {
            if (m_is_requester_created)
            {
                (*m_requester_ptr).send_request(data);
            }
            else
            {
                std::cout << "[Requester not created !!!]" << std::endl;
            }
        }

        /**
         * @brief 接收应答
         *
         * @return dds::sub::LoanedSamples<replierDataType>
         */
        dds::sub::LoanedSamples<replierDataType> ReceiveReplies()
        {
            if ((*m_requester_ptr).wait_for_replies(m_max_wait_time))
            {
                return (*m_requester_ptr).take_replies();
            }
            else
            {
                dds::sub::LoanedSamples<replierDataType> empty_data;
                std::cout << "[等待 " << this->GetReplyTopicName() << " 超时]" << std::endl;
                return empty_data;
            }
        }

    private:
        // 请求者创建
        bool m_is_requester_created;
        // 请求者参数
        rti::request::RequesterParams m_requester_params;
        // 最大等待时间
        dds::core::Duration m_max_wait_time;
        // 请求者
        std::shared_ptr<rti::request::Requester<requesterDataType, replierDataType>> m_requester_ptr;
    };

    /*---------------------------------------------------------------*/
    /**
     * @brief 应答方
     *
     * @tparam requesterDataType
     * @tparam replierDataType
     */
    template <typename requesterDataType, typename replierDataType>
    class DDSreplier
    {
    public:
        /**
         * @brief Construct a new DDSreplier object
         *
         */
        DDSreplier()
            : m_is_replier_created(false),
              m_replier_params(g_domain_participant)
        {
            // TODO
        }
        virtual ~DDSreplier() = default;

        void InitReplier(const std::string &request_topic_name,
                         const std::string &reply_topic_name)
        {
            SetDataReaderQoS(replier_Qos);
            SetDataWriterQoS(replier_Qos);
            SetRequestTopicName(request_topic_name);
            SetReplyTopicName(reply_topic_name);
        }

        /**
         * @brief Set the Data Reader Qo S object
         *
         * @param data_reader_qos
         */
        void SetDataReaderQoS(const std::string &data_reader_qos)
        {
            m_replier_params.datareader_qos(g_qos_provider.datareader_qos(data_reader_qos));
        }

        /**
         * @brief Set the Data Writer Qo S object
         *
         * @param data_writer_qos
         */
        void SetDataWriterQoS(const std::string &data_writer_qos)
        {
            m_replier_params.datawriter_qos(g_qos_provider.datawriter_qos(data_writer_qos));
        }

        /**
         * @brief Set the Reply Topic Name object
         *
         * @param request_topic_name
         */
        void SetRequestTopicName(const std::string &request_topic_name)
        {
            m_replier_params.request_topic_name(request_topic_name);
        }

        /**
         * @brief Get the Reply Topic Name object
         *
         * @return const char*
         */
        const char *GetRequestTopicName() const
        {
            return m_replier_params.request_topic_name().c_str();
        }

        /**
         * @brief Set the Reply Topic Name object
         *
         * @param reply_topic_name
         */
        void SetReplyTopicName(const std::string &reply_topic_name)
        {
            m_replier_params.reply_topic_name(reply_topic_name);
        }

        /**
         * @brief Get the Reply Topic Name object
         *
         * @return const char*
         */
        const char *GetReplyTopicName()
        {
            return m_replier_params.reply_topic_name().c_str();
        }

        /**
         * @brief Set the Max Wait Time object
         *
         * @param seconds
         */
        void SetMaxWaitTime(const double &seconds)
        {
            m_max_wait_time = dds::core::Duration::from_secs(seconds);
        }

        /**
         * @brief Get the Max Wait Time object
         *
         * @return int
         */
        int GetMaxWaitTime() const
        {
            return m_max_wait_time.sec();
        }

        /**
         * @brief Create a Replier object
         *
         */
        void CreateReplier(std::shared_ptr<rti::request::ReplierListener<requesterDataType, replierDataType>> the_listener)
        {
            m_replier_ptr = std::make_shared<rti::request::Replier<requesterDataType, replierDataType>>(m_replier_params, the_listener);
            m_is_replier_created = true;
        }

        /**
         * @brief 接收请求
         *
         * @return dds::sub::LoanedSamples<requesterDataType>
         */
        dds::sub::LoanedSamples<requesterDataType> ReceiveRequests()
        {
            return (*m_replier_ptr).receive_requests(m_max_wait_time);
        }

    private:
        // 应答者创建
        bool m_is_replier_created;
        // 应答者参数
        rti::request::ReplierParams m_replier_params;
        // 最大等待时间
        dds::core::Duration m_max_wait_time;
        // 应答者
        std::shared_ptr<rti::request::Replier<requesterDataType, replierDataType>> m_replier_ptr;
    };
} // namespace DDSservice

#endif
