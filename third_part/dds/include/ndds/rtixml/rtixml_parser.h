/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)rtixml_parser.h    generated by: makeheader    Wed Mar  9 22:30:03 2022
 *
 *		built from:	parser.ifc
 */

#ifndef rtixml_parser_h
#define rtixml_parser_h


  #include "rtixml/rtixml_dll.h"
  #include "rtixml/rtixml_extension.h"

  #ifdef __cplusplus
      extern "C" {
  #endif


struct RTIXMLParser;


extern	RTIXMLDllExport struct RTIXMLParser * RTIXMLParser_new(void);


extern	RTIXMLDllExport void RTIXMLParser_delete(struct RTIXMLParser * self);


extern	RTIXMLDllExport RTIBool RTIXMLParser_initialize(
                           struct RTIXMLParser * self);


extern	RTIXMLDllExport void RTIXMLParser_finalize(struct RTIXMLParser * self);


extern	RTIXMLDllExport struct RTIXMLObject * RTIXMLParser_parseFromFile_ex(
                                                struct RTIXMLParser * self,
                                                const char * dtdStr[],
                                                unsigned int dtdStrLength,
                                                RTIBool dtdIgnoreUnexpectedElements,
                                                const char * fileName,
                                                struct RTIXMLObject * root,
                                                void * contextUserData);


extern	RTIXMLDllExport struct RTIXMLObject * RTIXMLParser_parseFromFile(
                                                struct RTIXMLParser * self,
                                                const char * dtdStr[],
                                                unsigned int dtdStrLength,
                                                const char * fileName,
                                                struct RTIXMLObject * root,
                                                void * contextUserData);


extern	RTIXMLDllExport struct RTIXMLObject * RTIXMLParser_parseFromString_ex(
                                                struct RTIXMLParser * self,
                                                const char * dtdStr[],
                                                unsigned int dtdStrLength,
                                                RTIBool dtdIgnoreUnexpectedTags,
                                                const char * xmlStr[],
                                                unsigned int xmlStrLength,
                                                struct RTIXMLObject * root,
                                                void * contextUserData);


extern	RTIXMLDllExport struct RTIXMLObject * RTIXMLParser_parseFromString(
                                                struct RTIXMLParser * self,
                                                const char * dtdStr[],
                                                unsigned int dtdStrLength,
                                                const char * xmlStr[],
                                                unsigned int xmlStrLength,
                                                struct RTIXMLObject * root,
                                                void * contextUserData);


extern	RTIXMLDllExport RTIBool RTIXMLParser_registerExtensionClass(
                                                struct RTIXMLParser * self,
                                                struct RTIXMLExtensionClass * extension);

extern RTIXMLDllExport
struct RTIXMLExtensionClass * RTIXMLParser_unregisterExtensionClass(
                                                struct RTIXMLParser * self,
                                                const char * tagName);

extern RTIXMLDllExport
struct RTIXMLExtensionClass * RTIXMLParser_findExtensionClass(
        struct RTIXMLParser * self,
        const char * tagName);
/*e \ingroup RTIXMLParserClass

  @brief Releases all the resources associated to the input DOM object

  @pre self is not NULL
  @pre dom is not NULL

  @param self \b In. A pointer to the parser.
  @param dom \b In. A pointer to the DOM object.
*/

extern	RTIXMLDllExport void RTIXMLParser_freeDOM(struct RTIXMLParser * self, struct RTIXMLObject * dom);


extern	RTIXMLDllExport const char * RTIXMLParser_getLastXmlVersion(struct RTIXMLParser * self);

extern RTIXMLDllExport
RTIBool RTIXMLParser_addUserEnvironmentVariable(
        struct RTIXMLParser *self,
        const char *name,
        const char *value);


  #ifdef __cplusplus
    }	/* extern "C" */
  #endif
  #include "rtixml/rtixml_parser_impl.h"

#endif /* rtixml_parser_h */
