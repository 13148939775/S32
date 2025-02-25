/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_cpp_dynamicdata.h    generated by: makeheader    Wed Mar  9 22:40:04 2022
 *
 *		built from:	dynamicdata.ifcxx
 */

#ifndef dds_cpp_dynamicdata_h
#define dds_cpp_dynamicdata_h


  #ifndef dds_cpp_dll_h
    #include "dds_cpp/dds_cpp_dll.h"
  #endif
  #ifndef dds_c_dynamicdata_h
    #include "dds_c/dds_c_dynamicdata.h"
  #endif
  #ifndef dds_cpp_data_h
    #include "dds_cpp/dds_cpp_data.h"
  #endif
  #ifndef dds_cpp_topic_h
    #include "dds_cpp/dds_cpp_topic.h"
  #endif


class NDDSUSERDllExport DDSCPPDllExport DDSDynamicDataTypeSupport :
        public DDSTypeSupport {
public:
        /*e \dref_DynamicDataTypeSupport_is_valid
         */
    DDS_Boolean is_valid();

	/*e \dref_DynamicDataTypeSupport_register_type
	 */
    DDS_ReturnCode_t register_type(
        DDSDomainParticipant* participant,
        const char* type_name);
	/*e \dref_DynamicDataTypeSupport_unregister_type
	 */
    DDS_ReturnCode_t unregister_type(
        DDSDomainParticipant* participant,
        const char* type_name);

	/*e \dref_DynamicDataTypeSupport_get_type_name
	 */
    const char* get_type_name() const;

    /*e \dref_DynamicDataTypeSupport_get_data_type
	 */
    const DDS_TypeCode *get_data_type() const;

    /*e \dref_DynamicDataTypeSupport_create_data
	 */
    DDS_DynamicData* create_data();
    DDS_DynamicData* create_data_ex(DDS_Boolean allocatePointers);

    /*e \dref_DynamicDataTypeSupport_delete_data
	 */
    DDS_ReturnCode_t delete_data(DDS_DynamicData* a_data);
    DDS_ReturnCode_t delete_data_ex(DDS_DynamicData* a_data,
                                    DDS_Boolean deletePointers);

    /*e \dref_DynamicDataTypeSupport_print_data
	 */
    void print_data(const DDS_DynamicData* a_data) const;

    /*e \dref_DynamicDataTypeSupport_copy_data
	 */
    DDS_ReturnCode_t copy_data(DDS_DynamicData* dest,
                               const DDS_DynamicData* source) const;

    /*i \dref_DynamicDataTypeSupport_initialize_data
	 */
    DDS_ReturnCode_t initialize_data(DDS_DynamicData* a_data) const;
    DDS_ReturnCode_t initialize_data_ex(DDS_DynamicData* a_data,
                                        DDS_Boolean allocatePointers) const;

    /*i \dref_DynamicDataTypeSupport_finalize_data
	 */
    DDS_ReturnCode_t finalize_data(DDS_DynamicData* a_data) const;
    DDS_ReturnCode_t finalize_data_ex(DDS_DynamicData* a_data,
                                      DDS_Boolean deletePointers) const;

public:
    DDSDataReader* create_datareaderI(DDSDataReader* dataReader);
    DDS_ReturnCode_t destroy_datareaderI(DDSDataReader* dataReader);
    DDSDataWriter* create_datawriterI(DDSDataWriter* dataWriter);
    DDS_ReturnCode_t destroy_datawriterI(DDSDataWriter* dataWriter);

public:
    /*e \dref_DynamicDataTypeSupport_new
	 */
    DDSDynamicDataTypeSupport(
        const DDS_TypeCode * type,
        const struct DDS_DynamicDataTypeProperty_t & props);

    /*i \dref_DynamicDataTypeSupport_new_raw
     */
    DDSDynamicDataTypeSupport(
        DDS_UnsignedLong max_serialized_size,
        DDS_Boolean is_keyed,
        const struct DDS_DynamicDataTypeProperty_t & props);
    
    /*e \dref_DynamicDataTypeSupport_delete
	 */
    virtual ~DDSDynamicDataTypeSupport();

private:
    struct DDS_DynamicDataTypeSupport *_impl;
};



class NDDSUSERDllExport DDSCPPDllExport DDSDynamicDataReader :                    
        public DDSDataReader {                                           
                                                                         
  public:                                                                
  DDS_DATAREADER_CPP_PUBLIC_UNTYPED_METHODS();                           
                                                                         
  public:                                                                
                                                                         
  virtual DDS_ReturnCode_t read(DDS_DynamicDataSeq& received_data,                 
        DDS_SampleInfoSeq& info_seq,                                         
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,                     
        DDS_SampleStateMask sample_states = DDS_ANY_SAMPLE_STATE,        
        DDS_ViewStateMask view_states = DDS_ANY_VIEW_STATE,              
        DDS_InstanceStateMask instance_states = DDS_ANY_INSTANCE_STATE); 
                                                                         
  virtual DDS_ReturnCode_t take(DDS_DynamicDataSeq& received_data,                 
        DDS_SampleInfoSeq& info_seq,                                     
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,                     
        DDS_SampleStateMask sample_states = DDS_ANY_SAMPLE_STATE,        
        DDS_ViewStateMask view_states = DDS_ANY_VIEW_STATE,              
        DDS_InstanceStateMask instance_states = DDS_ANY_INSTANCE_STATE); 
                                                                         
  virtual DDS_ReturnCode_t read_w_condition(DDS_DynamicDataSeq& received_data,     
                                      DDS_SampleInfoSeq& info_seq,       
                                      DDS_Long max_samples,              
                                      DDSReadCondition* condition);      
                                                                         
  virtual DDS_ReturnCode_t take_w_condition(DDS_DynamicDataSeq& received_data,     
                                      DDS_SampleInfoSeq& info_seq,       
                                      DDS_Long max_samples,              
                                      DDSReadCondition* condition);      
                                                                         
  virtual DDS_ReturnCode_t read_next_sample(DDS_DynamicData& received_data,        
                          DDS_SampleInfo& sample_info);                  
                                                                         
  virtual DDS_ReturnCode_t take_next_sample(DDS_DynamicData& received_data,        
                          DDS_SampleInfo& sample_info);                  
                                                                         
  virtual DDS_ReturnCode_t read_instance(DDS_DynamicDataSeq& received_data,        
        DDS_SampleInfoSeq& info_seq,                                     
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,                     
        const DDS_InstanceHandle_t& a_handle = DDS_HANDLE_NIL,           
        DDS_SampleStateMask sample_states = DDS_ANY_SAMPLE_STATE,        
        DDS_ViewStateMask view_states = DDS_ANY_VIEW_STATE,              
        DDS_InstanceStateMask instance_states = DDS_ANY_INSTANCE_STATE); 
                                                                         
  virtual DDS_ReturnCode_t read_instance(DDS_DynamicDataSeq& received_data,
        DDS_SampleInfoSeq& info_seq,
        const DDS_GUID_t& topic_query_guid,
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,
        const DDS_InstanceHandle_t& a_handle = DDS_HANDLE_NIL,
        DDS_SampleStateMask sample_states = DDS_ANY_SAMPLE_STATE,
        DDS_ViewStateMask view_states = DDS_ANY_VIEW_STATE,
        DDS_InstanceStateMask instance_states = DDS_ANY_INSTANCE_STATE);

  virtual DDS_ReturnCode_t take_instance(DDS_DynamicDataSeq& received_data,        
        DDS_SampleInfoSeq& info_seq,                                     
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,                     
        const DDS_InstanceHandle_t& a_handle = DDS_HANDLE_NIL,           
        DDS_SampleStateMask sample_states = DDS_ANY_SAMPLE_STATE,        
        DDS_ViewStateMask view_states = DDS_ANY_VIEW_STATE,              
        DDS_InstanceStateMask instance_states = DDS_ANY_INSTANCE_STATE); 
                                                                         
  virtual DDS_ReturnCode_t take_instance(DDS_DynamicDataSeq& received_data,
        DDS_SampleInfoSeq& info_seq,
        const DDS_GUID_t& topic_query_guid,
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,
        const DDS_InstanceHandle_t& a_handle = DDS_HANDLE_NIL,
        DDS_SampleStateMask sample_states = DDS_ANY_SAMPLE_STATE,
        DDS_ViewStateMask view_states = DDS_ANY_VIEW_STATE,
        DDS_InstanceStateMask instance_states = DDS_ANY_INSTANCE_STATE);

  virtual DDS_ReturnCode_t read_instance_w_condition(                    
        DDS_DynamicDataSeq& received_data,                                         
        DDS_SampleInfoSeq& info_seq,                                     
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,                     
        const DDS_InstanceHandle_t& a_handle = DDS_HANDLE_NIL,           
        DDSReadCondition* condition = NULL);                             
                                                                         
  virtual DDS_ReturnCode_t take_instance_w_condition(                    
        DDS_DynamicDataSeq& received_data,                                         
        DDS_SampleInfoSeq& info_seq,                                     
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,                     
        const DDS_InstanceHandle_t& a_handle = DDS_HANDLE_NIL,           
        DDSReadCondition* condition = NULL);                             
                                                                         
  virtual DDS_ReturnCode_t read_next_instance(DDS_DynamicDataSeq& received_data,   
        DDS_SampleInfoSeq& info_seq,                                     
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,                     
        const DDS_InstanceHandle_t& previous_handle = DDS_HANDLE_NIL,    
        DDS_SampleStateMask sample_states = DDS_ANY_SAMPLE_STATE,        
        DDS_ViewStateMask view_states = DDS_ANY_VIEW_STATE,              
        DDS_InstanceStateMask instance_states = DDS_ANY_INSTANCE_STATE); 
                                                                         
  virtual DDS_ReturnCode_t take_next_instance(DDS_DynamicDataSeq& received_data,   
        DDS_SampleInfoSeq& info_seq,                                     
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,                     
        const DDS_InstanceHandle_t& previous_handle = DDS_HANDLE_NIL,    
        DDS_SampleStateMask sample_states = DDS_ANY_SAMPLE_STATE,        
        DDS_ViewStateMask view_states = DDS_ANY_VIEW_STATE,              
        DDS_InstanceStateMask instance_states = DDS_ANY_INSTANCE_STATE); 
                                                                         
  virtual DDS_ReturnCode_t read_next_instance_w_condition(               
        DDS_DynamicDataSeq& received_data,                                         
        DDS_SampleInfoSeq& info_seq,                                     
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,                     
        const DDS_InstanceHandle_t& previous_handle = DDS_HANDLE_NIL,    
        DDSReadCondition* condition = NULL);                             
                                                                         
  virtual DDS_ReturnCode_t take_next_instance_w_condition(               
        DDS_DynamicDataSeq& received_data,                                         
        DDS_SampleInfoSeq& info_seq,                                     
        DDS_Long max_samples = DDS_LENGTH_UNLIMITED,                     
        const DDS_InstanceHandle_t& previous_handle = DDS_HANDLE_NIL,    
        DDSReadCondition* condition = NULL);                             
                                                                         
  virtual DDS_ReturnCode_t return_loan(DDS_DynamicDataSeq& received_data,          
                          DDS_SampleInfoSeq& info_seq);                  
                                                                         
  virtual DDS_ReturnCode_t get_key_value(DDS_DynamicData& key_holder,              
                                    const DDS_InstanceHandle_t& handle); 
                                                                         
  virtual DDS_InstanceHandle_t lookup_instance(                          
                                const DDS_DynamicData& key_holder);
  
  virtual DDS_DynamicData* create_data(const struct DDS_DynamicDataProperty_t & property);
  virtual void delete_data(DDS_DynamicData*data);
                                                                         
  public:                                                                
                                                                         
    static DDSDynamicDataReader* createI(DDSDataReader* dataReader);              
    static DDS_ReturnCode_t destroyI(DDSDynamicDataReader* dataReader);           
                                                                         
    static DDSDynamicDataReader* narrow(DDSDataReader *reader);    
                                                                         
  private:                                                               
    virtual DDS_ReturnCode_t read_or_takeI(DDS_DynamicDataSeq& received_data,      
                                  DDS_SampleInfoSeq& info_seq,           
                                  DDS_Long max_samples,                  
                                  DDS_SampleStateMask sample_states,     
                                  DDS_ViewStateMask view_states,         
                                  DDS_InstanceStateMask instance_states, 
                                  bool take);                            
                                                                         
    virtual DDS_ReturnCode_t read_or_take_w_conditionI(                  
                                  DDS_DynamicDataSeq& received_data,               
                                  DDS_SampleInfoSeq& info_seq,           
                                  DDS_Long max_samples,                  
                                  DDSReadCondition* condition,           
                                  bool take);                            
                                                                         
    virtual DDS_ReturnCode_t read_or_take_next_sampleI(                  
                                  DDS_DynamicData& received_data,                  
                                  DDS_SampleInfo& sample_info,           
                                  bool take);                            
                                                                         
    virtual DDS_ReturnCode_t read_or_take_instanceI(                     
                                  DDS_DynamicDataSeq& received_data,               
                                  DDS_SampleInfoSeq& info_seq,           
                                  DDS_Long max_samples,                  
                                  const DDS_InstanceHandle_t& a_handle,
                                  const DDS_GUID_t *topic_query_guid,
                                  DDS_SampleStateMask sample_states,     
                                  DDS_ViewStateMask view_states,         
                                  DDS_InstanceStateMask instance_states, 
                                  bool take);                            
                                                                         
    virtual DDS_ReturnCode_t read_or_take_instance_w_conditionI(    
                                  DDS_DynamicDataSeq& received_data,               
                                  DDS_SampleInfoSeq& info_seq,           
                                  DDS_Long max_samples,                  
                          const DDS_InstanceHandle_t& previous_handle,    
                                  DDSReadCondition* condition,           
                                  bool take);                         
                                                                        
     virtual DDS_ReturnCode_t read_or_take_next_instanceI(                
                                  DDS_DynamicDataSeq& received_data,               
                                  DDS_SampleInfoSeq& info_seq,           
                                  DDS_Long max_samples,                  
                          const DDS_InstanceHandle_t& previous_handle,    
                                  DDS_SampleStateMask sample_states,     
                                  DDS_ViewStateMask view_states,         
                                  DDS_InstanceStateMask instance_states, 
                                  bool take);                            
                                                                         
    virtual DDS_ReturnCode_t read_or_take_next_instance_w_conditionI(    
                                  DDS_DynamicDataSeq& received_data,               
                                  DDS_SampleInfoSeq& info_seq,           
                                  DDS_Long max_samples,                  
                          const DDS_InstanceHandle_t& previous_handle,    
                                  DDSReadCondition* condition,           
                                  bool take);                             
  
  protected:                                                             
                                                                         
    DDSDynamicDataReader(DDSDataReader* impl);                                    
                                                                         
  protected:                                                             
  virtual ~DDSDynamicDataReader();                                                
};



class NDDSUSERDllExport DDSCPPDllExport DDSDynamicDataWriter : public DDSDataWriter 
{
public:
DDS_DATAWRITER_CPP_PUBLIC_UNTYPED_METHODS();
DDS_DATAWRITER_CPP_PUBLIC_METHODS(DDSDynamicDataWriter, DDS_DynamicData);
    virtual DDS_DynamicData * create_data(const struct DDS_DynamicDataProperty_t & property);
    virtual void delete_data(DDS_DynamicData * data);
protected:
    DDSDynamicDataWriter(DDSDataWriter* impl);
    virtual ~DDSDynamicDataWriter();
};

#endif /* dds_cpp_dynamicdata_h */
