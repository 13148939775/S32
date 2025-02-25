/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_cpp_topic.h    generated by: makeheader    Wed Mar  9 22:40:05 2022
 *
 *		built from:	topic.ifcxx
 */

#ifndef dds_cpp_topic_h
#define dds_cpp_topic_h


  #ifndef dds_cpp_dll_h
    #include "dds_cpp/dds_cpp_dll.h"
  #endif
  #ifndef dds_cpp_infrastructure_h
    #include "dds_cpp/dds_cpp_infrastructure.h"
  #endif
  #ifndef dds_c_topic_h
    #include "dds_c/dds_c_topic.h"
  #endif

class DDSTopicDescription_impl;

class DDSDomainParticipant;

class DDSTopic;

class DDSCPPDllExport DDSTopicDescription {
  public: 

    /*i
      @brief Get the underlying implementation class object.	  
     */
    virtual DDSTopicDescription_impl* get_impl_TopicDescriptionI() 
        = 0;

  public: 

    /*e \dref_TopicDescription_get_type_name
     */
    virtual const char* get_type_name() 
        = 0;

    /*e \dref_TopicDescription_get_name
     */
    virtual const char* get_name() 
	= 0;

    /*e \dref_TopicDescription_get_participant
     */
    virtual DDSDomainParticipant* get_participant()
        = 0;
   
  protected: 
    virtual ~DDSTopicDescription();
};

class DDSCPPDllExport DDSContentFilteredTopic : 
    public DDSTopicDescription 
{
  public: 

    /*e \dref_ContentFilteredTopic_narrow
     */
    static DDSContentFilteredTopic* narrow(
	DDSTopicDescription* topic_description);

    /*e \dref_ContentFilteredTopic_get_filter_expression
     */
    virtual const char* get_filter_expression() 
        = 0; 

    /*e \dref_ContentFilteredTopic_get_expression_parameters
     */
    virtual DDS_ReturnCode_t get_expression_parameters(
        DDS_StringSeq& parameters)
        = 0;

    /*e \dref_ContentFilteredTopic_set_expression_parameters
     */
    virtual DDS_ReturnCode_t set_expression_parameters(
	const DDS_StringSeq& parameters)
        = 0;
    
    /*e \dref_ContentFilteredTopic_set_expression
     */
    virtual DDS_ReturnCode_t set_expression(
        const char * expression,
        const DDS_StringSeq& parameters)
        = 0;

    /*e \dref_ContentFilteredTopic_append_to_expression_parameter
     */
    virtual DDS_ReturnCode_t append_to_expression_parameter(
        const DDS_Long index, const char* val) = 0;

    /*e \dref_ContentFilteredTopic_remove_from_expression_parameter
     */
    virtual DDS_ReturnCode_t remove_from_expression_parameter(
        const DDS_Long index, const char* val) = 0;

    /*e \dref_ContentFilteredTopic_get_related_topic
     */
    virtual DDSTopic* get_related_topic() 
        = 0;
    
    virtual DDS_TopicDescription* get_c_topicDescriptionI() 
        = 0;

  protected:

    virtual ~DDSContentFilteredTopic();
};

class DDSCPPDllExport DDSMultiTopic : public DDSTopicDescription {
  // --- <<interface>> DDSMultiTopic: ----------------------------------
  public:

    /*e \dref_MultiTopic_narrow
     */
    static DDSMultiTopic* narrow(DDSTopicDescription* topic_description);

    /*e \dref_MultiTopic_get_subscription_expression
     */
    virtual const char* get_subscription_expression()
        = 0;

    /*e \dref_MultiTopic_get_expression_parameters
     */
    virtual DDS_ReturnCode_t get_expression_parameters(
        DDS_StringSeq& parameters)
        = 0;

    /*e \dref_MultiTopic_set_expression_parameters
     */
    virtual DDS_ReturnCode_t set_expression_parameters(
	const DDS_StringSeq& parameters)
        = 0;

  // --- <<lifecycle>>: ------------------------------------------------
  protected:

    virtual ~DDSMultiTopic();
};

class DDSTopic;

typedef DDSTopic* DDSTopic_ptr;


DDS_SEQUENCE(DDSTopicSeq, DDSTopic_ptr);

class DDSTopicListener;

class DDSCPPDllExport DDSTopic : 
    public DDSDomainEntity, public DDSTopicDescription 
{
  public: 
    /*e \dref_Topic_narrow
     */
    static DDSTopic* narrow(DDSTopicDescription* topic_description);

    /*e \dref_Topic_get_inconsistent_topic_status
     */
    virtual DDS_ReturnCode_t get_inconsistent_topic_status(
        DDS_InconsistentTopicStatus& status)
        = 0;

    /*e \dref_Topic_set_qos
     */
    virtual DDS_ReturnCode_t set_qos(const DDS_TopicQos& qos)
        = 0;

    /*e \dref_Topic_set_qos_with_profile
     */
    virtual DDS_ReturnCode_t set_qos_with_profile(
	const char * library_name,
	const char * profile_name)
        = 0;

    /*e \dref_Topic_get_qos
     */
    virtual DDS_ReturnCode_t get_qos(DDS_TopicQos& qos)
        = 0;

    /*e \dref_Topic_set_listener
     */
    virtual DDS_ReturnCode_t set_listener(DDSTopicListener* l, 
        DDS_StatusMask mask = DDS_STATUS_MASK_ALL)
        = 0;

    /*e \dref_Topic_get_listener
     */
    virtual DDSTopicListener* get_listener()
        = 0;
    
  // --- <<impl>> eXtensions: ------------------------------------------
  public:
      virtual DDS_Topic* get_c_topicI() 
        = 0;

  protected:

    virtual ~DDSTopic();
};

class DDSCPPDllExport DDSTopicListener : public virtual DDSListener {
  public: 

    /*e \dref_TopicListener_on_inconsistent_topic
     */
    virtual void on_inconsistent_topic(DDSTopic* topic, 
        const DDS_InconsistentTopicStatus& status);

  public:

    virtual ~DDSTopicListener();

};

class DDSCPPDllExport DDSContentFilter {

  public:
    virtual ~DDSContentFilter() { };
    
    /*e \dref_ContentFilter_compile
     */
    virtual DDS_ReturnCode_t compile(
	void** new_compile_data, const char *expression,
	const DDS_StringSeq& parameters,const DDS_TypeCode* type_code,
	const char* type_class_name,
	void *old_compile_data) = 0;

    /*e \dref_ContentFilter_evaluate
     */
    virtual DDS_Boolean evaluate(
	void* compile_data,const void* sample,const struct DDS_FilterSampleInfo * meta_data) = 0;

    /*e \dref_ContentFilter_finalize
     */
    virtual void finalize(
	void* compile_data) = 0;

    /*i \dref_ContentFilter_intialize_c_filterI
     */
    virtual void initialize_c_filterI(
       struct DDS_ContentFilter *c_filter,
	void* filter_data);
};

class DDSCPPDllExport DDSWriterContentFilter: public  DDSContentFilter { 

  public:
    virtual ~DDSWriterContentFilter() { };
    
    /*e \dref_WriterContentFilter_writer_compile
     */
    virtual DDS_ReturnCode_t writer_compile(
        void *writer_filter_data,DDS_ExpressionProperty *prop,
        const char *expression,const DDS_StringSeq *parameters,
        const DDS_TypeCode* type_code,const char* type_class_name,
        const DDS_Cookie_t *cookie) = 0;

    /*e \dref_WriterContentFilter_writer_evaluate
     */
    virtual struct DDS_CookieSeq *  writer_evaluate(
       void* writer_filter_data, 
       const void* sample,const DDS_FilterSampleInfo * meta_data) = 0;

    /*e \dref_WriterContentFilter_writer_finalize
     */
    virtual void writer_finalize(
	void* writer_filter_data,const DDS_Cookie_t *cookie) = 0;

    /*e \dref_WriterContentFilter_writer_attach
     */
    virtual DDS_ReturnCode_t writer_attach(
	void ** writer_filter_data) = 0;

    /*e \dref_WriterContentFilter_writer_detach
     */
    virtual void writer_detach(void *writer_filter_data) = 0;

    /*e \dref_WriterContentFilter_writer_return_loan
     */
    virtual void writer_return_loan(
	void* writer_filter_data, DDS_CookieSeq * cookies) = 0;

    /*i \dref_WriterContentFilter_intialize_c_filterI
     */
    void initialize_c_filterI(
       struct DDS_ContentFilter *c_filter,
	void* filter_data);
};

class DDSDataReader;

class DDSDataWriter;

class DDSCPPDllExport DDSTypeSupport {
  public: 
    virtual DDSDataReader*  create_datareaderI(DDSDataReader* dataReader)
	= 0;

    virtual DDS_ReturnCode_t  destroy_datareaderI(DDSDataReader* dataReader)
	= 0;

    virtual DDSDataWriter*  create_datawriterI(DDSDataWriter* dataWriter)
	= 0;

    virtual DDS_ReturnCode_t  destroy_datawriterI(DDSDataWriter* dataWriter)
	= 0;

    virtual ~DDSTypeSupport();

  protected:
    DDSTypeSupport() {
	}
};

#endif /* dds_cpp_topic_h */
