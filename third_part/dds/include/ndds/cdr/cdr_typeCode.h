/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)cdr_typeCode.h    generated by: makeheader    Wed Mar  9 22:30:06 2022
 *
 *		built from:	typeCode.ifc
 */

#ifndef cdr_typeCode_h
#define cdr_typeCode_h


 #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
 #endif
 #ifndef cdr_dll_h
    #include "cdr/cdr_dll.h"
 #endif
 #ifndef cdr_type_h
    #include "cdr/cdr_type.h"
 #endif
#ifndef cdr_stream_h
    #include "cdr/cdr_stream.h"
#endif
#include "xcdr/xcdr_typeCode.h"

#include "xcdr/xcdr_interpreter.h"

#ifndef reda_fastBuffer_h
    #include "reda/reda_fastBuffer.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif


/* Value assigned to the label DEFAULT in a union.
 * This value should not be used to determine if a label is the default label
 * or not. Use the function RTICdrTypeCode_get_default_index instead.
 */
 
#define RTI_CDR_TYPE_CODE_UNION_DEFAULT_LABEL \
        RTI_XCDR_TYPE_CODE_UNION_DEFAULT_LABEL

typedef RTIXCdrTCKind RTICdrTCKind;

typedef enum 
{ 
    RTI_CDR_FINAL_EXTENSIBILITY, 
    RTI_CDR_EXTENSIBLE_EXTENSIBILITY, 
    RTI_CDR_MUTABLE_EXTENSIBILITY
} RTICdrExtensibilityKind;

typedef short RTICdrValueModifier;


#define RTI_CDR_VM_NONE 0
#define RTI_CDR_VM_CUSTOM 1
#define RTI_CDR_VM_ABSTRACT 2
#define RTI_CDR_VM_TRUNCATABLE 3
#define RTI_CDR_VM_MUTABLE 4

typedef short RTICdrVisibility;


#define RTI_CDR_PRIVATE_MEMBER 0
#define RTI_CDR_PUBLIC_MEMBER 1

typedef RTICdrOctet RTICdrMemberFlags;


#define RTI_CDR_NONKEY_MEMBER 0
#define RTI_CDR_KEY_MEMBER 1
#define RTI_CDR_REQUIRED_MEMBER 2 /* for TK_SPARSE, STRUCT AND VALUE */

/* bit flags: [... required | key ] */
#define RTI_CDR_FLAG_KEY_MEMBER 1
#define RTI_CDR_FLAG_REQUIRED_MEMBER 2

struct RTICdrTypeCode;

typedef struct RTICdrTypeCodeRepresentation {
    RTICdrUnsignedLong _pid; /* sparse */
    RTICdrBoolean _isPointer; /* struct, union, value, sparse */
    RTICdrShort _bits; /* struct, value, sparse */
    struct RTICdrTypeCode * _typeCode; /* struct, union, value, sparse */
} RTICdrTypeCodeRepresentation;

typedef struct RTICdrTypeCodePrintFormat {
    RTICdrUnsignedLong indent;
    RTICdrBoolean print_ordinals;
} RTICdrTypeCodePrintFormat;



#define RTI_CDR_XCDR RTI_XCDR_XCDR
#define RTI_CDR_XCDR2 RTI_XCDR_XCDR2
#define RTI_CDR_XML RTI_XCDR_XML

#define RTICdrDataRepresentationMaskBits RTIXCdrDataRepresentationMaskBits
#define RTICdrDataRepresentationMask RTIXCdrDataRepresentationMask
#define RTI_CDR_DATA_REPRESENTATION_MASK_DEFAULT \
    RTI_XCDR_DATA_REPRESENTATION_MASK_DEFAULT
#define RTICdrAnnotationParameterValue RTIXCdrAnnotationParameterValue
#define RTICdrTypeCodeAnnotations RTIXCdrTypeCodeAnnotations
#define RTICdrTypeCodeAnnotations_INITIALIZER \
    RTIXCdrTypeCodeAnnotations_INITIALIZER
#define RTICdrTypeCodeAnnotations_initialize \
    RTIXCdrTypeCodeAnnotations_initialize
#define RTICdrTypeCodeAnnotations_copy \
    RTIXCdrTypeCodeAnnotations_copy
#define RTICdrTypeCodeAnnotations_equals \
    RTIXCdrTypeCodeAnnotations_equals
#define RTICdrTypeCodeAnnotations_isDefaultAndRangeConsistent \
    RTIXCdrTypeCodeAnnotations_isDefaultAndRangeConsistent
#define RTICdrTypeCodeAnnotations_finalize \
    RTIXCdrTypeCodeAnnotations_finalize

typedef struct RTICdrTypeCodeMember {
    char * _name; /* struct, union, enum, value, sparse */
    struct RTICdrTypeCodeRepresentation _representation; /* struct, union, value, sparse */
    RTICdrLong _ordinal; /* enum */
    RTICdrUnsignedLong _labelsCount; /* union */
    RTICdrLong _label; /* union */
    RTICdrLong * _labels; /* union */
    RTICdrMemberFlags _memberFlags; /* struct, value, sparse */
    RTICdrVisibility _visibility; /* value, sparse */
    RTICdrUnsignedShort _representationCount; /* sparse */        
    struct RTICdrTypeCodeRepresentation * _representations; /* sparse */
    struct RTICdrTypeCodeAnnotations _annotations;
} RTICdrTypeCodeMember;

typedef struct RTICdrTypeCode {
    RTICdrLong _kind;  /* All types */
    RTICdrBoolean _isPointer; /* alias */
    RTICdrLong _default_index; /* unions */              
    char * _name; /* struct, union, enum, alias, value, sparse */
    struct RTICdrTypeCode * _typeCode; /* alias, sequence, array, union, value, sparse, struct */
    RTICdrUnsignedLong _maximumLength; /* string, wstring, sequence */
    RTICdrUnsignedLong _dimensionsCount; /* array */    
    RTICdrUnsignedLong * _dimensions; /* array */       
    RTICdrUnsignedLong _memberCount; /* struct, union, enum, value, sparse */
    struct RTICdrTypeCodeMember * _members; /* struct, union, enum, value, sparse */
    RTICdrValueModifier _typeModifier; /* value, sparse */
    struct RTICdrTypeCodeAnnotations _annotations; /* default, min, max */
    RTICdrBoolean _isCopyable;
    
    /* Information used by the interpreter */
    /* This information is specific to a language binding */
    RTIXCdrSampleAccessInfo * _sampleAccessInfo;
    RTIXCdrTypePlugin *_typePlugin;
} RTICdrTypeCode;


#define RTICdrTypeCode_initialize(self) \
    {\
        struct RTICdrTypeCodeAnnotations annotationsInitialValue\
            = RTICdrTypeCodeAnnotations_INITIALIZER;\
        (self)->_kind = RTI_XCDR_TK_NULL;\
        (self)->_isPointer = RTI_FALSE;\
        (self)->_default_index = -1;\
        (self)->_name = NULL;\
        (self)->_typeCode = NULL;\
        (self)->_maximumLength = 0;\
        (self)->_dimensionsCount = 0;\
        (self)->_dimensions = NULL;\
        (self)->_memberCount = 0;\
        (self)->_members = NULL;\
        (self)->_typeModifier = RTI_CDR_VM_NONE; \
        (self)->_annotations = annotationsInitialValue;\
        (self)->_isCopyable = RTI_TRUE; \
        (self)->_sampleAccessInfo = NULL; \
        (self)->_typePlugin = NULL; \
    }


#define RTICdrTypeCodeMember_initialize(self) \
    {\
        struct RTICdrTypeCodeAnnotations annotationsInitialValue\
            = RTICdrTypeCodeAnnotations_INITIALIZER;\
        (self)->_name = NULL;\
        (self)->_representation._pid = 0;\
        (self)->_representation._isPointer = RTI_FALSE;\
        (self)->_representation._bits = -1;\
        (self)->_representation._typeCode = NULL;\
        (self)->_ordinal = 0;\
        (self)->_labelsCount = 0;\
        (self)->_label = 0;\
        (self)->_labels = NULL;\
        (self)->_memberFlags = RTI_FALSE;\
        (self)->_visibility = (short)0;\
        (self)->_representationCount = 0;\
        (self)->_representations = NULL; \
        (self)->_annotations = annotationsInitialValue;\
    }

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_kindFunc(RTICdrTypeCode * self,RTICdrTCKind * kind);


/*i
 */
#define RTICdrTypeCode_CDR_REPRESENTATION(kind) ((kind) & (0x80000000|0x00000080))

#define RTICdrTypeCode_STRIP_FLAGS(kind) ((kind) & ~RTI_XCDR_TK_FLAGS_ALL)

#define RTICdrTypeCode_get_kindMacro(self, kind) \
    (RTICdrTypeCode_CDR_REPRESENTATION((self)->_kind) ? \
        RTICdrTypeCode_get_kindFunc(self, kind) : \
        ((*(kind)=RTICdrTypeCode_STRIP_FLAGS((self)->_kind)), RTI_TRUE))

#ifndef RTI_PRECONDITION_TEST
  #define RTICdrTypeCode_get_kind RTICdrTypeCode_get_kindMacro
#else
  #define RTICdrTypeCode_get_kind RTICdrTypeCode_get_kindFunc
#endif /* RTI_PRECONDITION_TEST */

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_kind_ex(RTICdrTypeCode * self,RTICdrTCKind * kind, RTIBool stripFlags);

extern RTICdrDllExport RTIBool RTICdrTypeCode_is_indexed(RTICdrTypeCode * self, RTIBool * isIndexed);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_extensibility_kind(
        RTICdrTypeCode * self, RTICdrExtensibilityKind * extKind);

extern RTICdrDllExport RTIBool RTICdrTypeCode_equal(RTICdrTypeCode * self,
                                                    RTICdrTypeCode * typeCode,
                                                    RTICdrBoolean * equal);

extern RTICdrDllExport const char * RTICdrTypeCode_get_name(RTICdrTypeCode * self);

extern RTICdrDllExport 
const struct RTICdrTypeCodeAnnotations *RTICdrTypeCode_get_annotations(
        RTICdrTypeCode * self);

extern RTICdrDllExport 
const struct RTICdrTypeCodeAnnotations *RTICdrTypeCode_get_memberAnnotations(
        RTICdrTypeCode *self,
        RTICdrUnsignedLong index);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_member_countFunc(RTICdrTypeCode * self,
                                                                   RTICdrUnsignedLong * count);


#define RTICdrTypeCode_get_member_countMacro(self, count) \
    (RTICdrTypeCode_CDR_REPRESENTATION((self)->_kind) ? \
        RTICdrTypeCode_get_member_countFunc(self, count) : \
        ((*(count)=(self)->_memberCount), RTI_TRUE))

#ifndef RTI_PRECONDITION_TEST
  #define RTICdrTypeCode_get_member_count RTICdrTypeCode_get_member_countMacro
#else
  #define RTICdrTypeCode_get_member_count RTICdrTypeCode_get_member_countFunc
#endif /* RTI_PRECONDITION_TEST */

extern RTICdrDllExport const char * RTICdrTypeCode_get_member_nameFunc(RTICdrTypeCode * self,
                                                                       RTICdrUnsignedLong index);


#define RTICdrTypeCode_get_member_nameMacro(self, index) \
    (RTICdrTypeCode_CDR_REPRESENTATION((self)->_kind) ? \
        RTICdrTypeCode_get_member_nameFunc(self, index) : \
        ((self)->_members[(index)]._name))

#ifndef RTI_PRECONDITION_TEST
  #define RTICdrTypeCode_get_member_name RTICdrTypeCode_get_member_nameMacro
#else
  #define RTICdrTypeCode_get_member_name RTICdrTypeCode_get_member_nameFunc
#endif /* RTI_PRECONDITION_TEST */

extern RTICdrDllExport RTICdrTypeCode * RTICdrTypeCode_get_member_typeFunc(RTICdrTypeCode * self,
                                                                           RTICdrUnsignedLong index);


#define RTICdrTypeCode_get_member_typeMacro(self, index) \
    (RTICdrTypeCode_CDR_REPRESENTATION((self)->_kind) ? \
        RTICdrTypeCode_get_member_typeFunc(self, index) : \
        ((self)->_members[(index)]._representation._typeCode))

#ifndef RTI_PRECONDITION_TEST
  #define RTICdrTypeCode_get_member_type RTICdrTypeCode_get_member_typeMacro
#else
  #define RTICdrTypeCode_get_member_type RTICdrTypeCode_get_member_typeFunc
#endif /* RTI_PRECONDITION_TEST */

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_member_label_count(RTICdrTypeCode * self,
                                                                     RTICdrUnsignedLong index,
                                                                     RTICdrUnsignedLong * labelCount);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_member_label(RTICdrTypeCode * self,
                                                               RTICdrUnsignedLong memberIndex,
                                                               RTICdrUnsignedLong labelIndex,
                                                               RTICdrLong * label);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_member_ordinal(RTICdrTypeCode * self,
                                                                 RTICdrUnsignedLong index,
                                                                 RTICdrLong * ordinal);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_member_flags(RTICdrTypeCode * self,
                                                               RTICdrUnsignedLong index,
                                                               RTICdrMemberFlags * memberFlags);

extern RTICdrDllExport RTIBool RTICdrTypeCode_is_member_key(RTICdrTypeCode * self,
                                                            RTICdrUnsignedLong index,
                                                            RTICdrBoolean * isKey);

extern RTICdrDllExport RTIBool RTICdrTypeCode_is_member_required(RTICdrTypeCode * self,
                                                            RTICdrUnsignedLong index,
                                                            RTICdrBoolean * isRequired);

extern RTICdrDllExport RTIBool RTICdrTypeCode_is_member_pointer(RTICdrTypeCode * self,
                                                                RTICdrUnsignedLong index,
                                                                RTICdrBoolean * isPointer);

extern RTICdrDllExport RTIBool RTICdrTypeCode_is_member_bitfield(RTICdrTypeCode * self,
                                                                 RTICdrUnsignedLong index,
                                                                 RTICdrBoolean * isBitField);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_member_bitfield_bits(RTICdrTypeCode * self,
                                                                       RTICdrUnsignedLong index,
                                                                       RTICdrShort * bits);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_member_visibility(RTICdrTypeCode * self,
                                                                    RTICdrUnsignedLong index,
                                                                    RTICdrVisibility * visibility);

extern RTICdrDllExport RTICdrTypeCode * RTICdrTypeCode_get_discriminator_type(RTICdrTypeCode * self);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_length(RTICdrTypeCode * self,
                                                         RTICdrUnsignedLong * length);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_array_dimension_count(RTICdrTypeCode * self,
                                                                        RTICdrUnsignedLong * dimensionCount);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_array_dimension(RTICdrTypeCode * self,
                                                                  RTICdrUnsignedLong index,                                        
                                                                  RTICdrUnsignedLong * dimension);

extern RTICdrDllExport RTICdrTypeCode * RTICdrTypeCode_get_content_type(RTICdrTypeCode * self);

extern RTICdrDllExport RTIBool RTICdrTypeCode_is_alias_pointer(RTICdrTypeCode * self,
                                                               RTICdrBoolean * isPointer);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_default_index(RTICdrTypeCode * self,
                                                                RTICdrLong * index);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_representation_count(
    RTICdrTypeCode * self,
    RTICdrUnsignedLong index,
    RTICdrUnsignedShort * representationCount);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_representation_id(
    RTICdrTypeCode * self,
    RTICdrUnsignedLong memberIndex,
    RTICdrUnsignedShort repIndex,
    RTICdrLong * fieldId);

extern RTICdrDllExport RTIBool RTICdrTypeCode_is_representation_pointer(
    RTICdrTypeCode * self,
    RTICdrUnsignedLong memberIndex,
    RTICdrUnsignedShort repIndex,
    RTICdrBoolean * isPointer);

extern RTICdrDllExport RTIBool RTICdrTypeCode_is_representation_bitfield(
    RTICdrTypeCode * self,
    RTICdrUnsignedLong memberIndex,
    RTICdrUnsignedShort repIndex,
    RTICdrBoolean * isBitField);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_representation_bitfield_bits(
    RTICdrTypeCode * self,
    RTICdrUnsignedLong memberIndex,
    RTICdrUnsignedShort repIndex,
    RTICdrShort * bits);

extern RTICdrDllExport RTICdrTypeCode * RTICdrTypeCode_get_representation_type(
    RTICdrTypeCode * self,
    RTICdrUnsignedLong memberIndex,
    RTICdrUnsignedShort repIndex);

extern RTICdrDllExport RTICdrTypeCode * RTICdrTypeCode_get_concrete_base_type(RTICdrTypeCode * self);

extern RTICdrDllExport RTIBool RTICdrTypeCode_get_type_modifier(RTICdrTypeCode * self,
                                                                RTICdrValueModifier * typeModifier);

extern RTICdrDllExport RTIBool RTICdrTypeCode_is_keyed(RTICdrTypeCode * self,
                                                                                             RTICdrBoolean * isKeyed);

extern RTICdrDllExport RTIBool RTICdrTypeCode_is_valuetype(
        RTICdrTypeCode *self,
        RTICdrBoolean *isValueType);

extern RTICdrDllExport RTIBool RTICdrTypeCodePrint_to_string_w_format(
        RTICdrTypeCode * self,
        char *str,
        RTICdrUnsignedLong *str_size,
        RTICdrTypeCodePrintFormat *format);

extern RTICdrDllExport RTICdrUnsignedLong RTICdrTypeCode_get_serialized_size(
    unsigned int currentPos,
    const struct RTICdrTypeCode * typeCode);

extern RTICdrDllExport RTICdrLong RTICdrTypeCode_get_stream_length(RTICdrTypeCode * self);

extern RTICdrDllExport RTICdrTypeCode * RTICdrTypeCode_create_stream(RTICdrUnsignedShort length);

extern RTICdrDllExport RTIBool RTICdrTypeCode_initialize_stream(RTICdrTypeCode * typeCode,
                                                                RTICdrUnsignedShort length);

extern RTICdrDllExport RTIBool RTICdrTypeCode_copy_stream(RTICdrTypeCode * dst,RTICdrTypeCode * src);

extern RTICdrDllExport RTIBool RTICdrTypeCode_serialize(
    void *endpointData,
    const struct RTICdrTypeCode * typeCode,
    struct RTICdrStream *stream,
    RTIBool serializeEncapsulation, 
    RTIEncapsulationId encapsulationId,
    RTIBool serializeSample,
    void *endpointPluginQos);

extern RTICdrDllExport RTIBool 
RTICdrTypeCode_selectDefaultDiscriminator(
    struct RTICdrTypeCode *typeCode,
    struct RTICdrTypeCode **discType,
    RTICdrLong *discValue, 
    RTICdrLong *representationId);

extern RTICdrDllExport RTIBool 
RTICdrTypeCode_initSerializedSample(
    struct RTICdrTypeCode *typeCode,
    RTIBool considerMemberHeader,
    RTICdrUnsignedLong *cdrSize,
    struct RTICdrStream *stream);

extern RTICdrDllExport RTIBool 
RTICdrTypeCode_deserialize(
    struct RTICdrTypeCode ** typeCode,
    struct RTICdrStream *stream,
    struct REDAFastBufferPool * pool);

extern RTICdrDllExport
RTIBool RTICdrTypeCode_is_serializable(
        RTICdrTypeCode * self,
        RTIBool * serializable);

extern RTICdrDllExport void
RTICdrTypeCode_destroyTypeCode(RTICdrTypeCode *self);

extern RTICdrDllExport
const RTICdrTypeCodeMember * RTICdrTypeCode_get_member(
    const RTICdrTypeCode * self, RTICdrUnsignedLong index);

extern RTICdrDllExport
const char * RTICdrTypeCodeMember_get_name(const RTICdrTypeCodeMember * self);

extern RTICdrDllExport
RTICdrTypeCode * RTICdrTypeCodeMember_get_type(const RTICdrTypeCodeMember * self);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_get_label_count(
    const RTICdrTypeCodeMember * self, RTICdrUnsignedLong * labelCountOut);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_get_label(
    const RTICdrTypeCodeMember * self,
    RTICdrLong * labelOut,
    RTICdrUnsignedLong labelIndex);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_get_ordinal(
    const RTICdrTypeCodeMember * self, RTICdrLong * ordinalOut);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_is_pointer(
    const RTICdrTypeCodeMember * self, RTICdrBoolean * isPointerOut);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_is_bitfield(
    const RTICdrTypeCodeMember * self, RTICdrBoolean * isBitFieldOut);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_get_bitfield_bits(
    const RTICdrTypeCodeMember * self, RTICdrShort * bitsOut);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_get_visibility(
    const RTICdrTypeCodeMember * self, RTICdrVisibility * visibilityOut);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_get_flags(
    const RTICdrTypeCodeMember * self, RTICdrMemberFlags * memberFlagsOut);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_is_key(
    const RTICdrTypeCodeMember * self, RTICdrBoolean * isKeyOut);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_is_required(
    const RTICdrTypeCodeMember * self, RTICdrBoolean * isRequiredOut);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_get_id(
    const RTICdrTypeCodeMember * self,
    RTICdrUnsignedShort repIndex,
    RTICdrUnsignedLong * idOut);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_set_labels(
    RTICdrTypeCodeMember * self,
    const RTICdrLong * labels,
    RTICdrUnsignedLong labelCount,
    RTIBool cloneMemory);

extern RTICdrDllExport
RTIBool RTICdrTypeCode_initializeAnnotations(RTICdrTypeCode *self);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeMember_initializeAnnotations(RTICdrTypeCodeMember *self);

extern RTICdrDllExport
RTIBool RTICdrTypeCode_copyMemberAnnotations(
        RTICdrTypeCode *dstType, 
        const RTICdrTypeCode *srcType, 
        RTICdrUnsignedLong index);

/*e \ingroup RTICdrTypeCodeModule 
 * 
 * @brief Copy the annotations for a typecode
 * 
 * If srcType is serialized then we initialize the annotations, otherwise we
 * copy. If dstType is serialized then we just return
 */
extern RTICdrDllExport
RTIBool RTICdrTypeCode_copyAnnotations(
        RTICdrTypeCode *dstType, 
        const RTICdrTypeCode *srcType);

/*e \ingroup RTICdrTypeCodeModule
 * @brief Determines if a type or any of its member types uses inheritance
 * @param tc The type
 * @param answer Output parameter with the result
 * @return True on success and false on error
 */
extern RTICdrDllExport
RTIBool RTICdrTypeCodeUtils_type_uses_inheritance(
    RTICdrTypeCode * tc,
    RTIBool * answer);

extern RTICdrDllExport
RTIBool RTICdrTypeCodeUtils_type_has_external_members(
    RTICdrTypeCode *tc,
    RTIBool *answer);


#define RTI_CDR_INITIALIZE_PRIMITIVE_TYPECODE(kind, copyable)\
    {kind,RTI_FALSE,-1,NULL,NULL,0,0,NULL,0,NULL,RTI_CDR_VM_NONE,\
    RTICdrTypeCodeAnnotations_INITIALIZER,copyable,NULL,NULL}

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_null;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_boolean;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_octet;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_short;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_ushort;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_long;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_ulong;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_longlong;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_ulonglong;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_float;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_double;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_longdouble;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_char;

extern RTICdrDllVariable const RTICdrTypeCode RTICdr_g_tc_wchar;


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* cdr_typeCode_h */
