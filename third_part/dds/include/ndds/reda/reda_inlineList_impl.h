/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_inlineList_impl.h    generated by: makeheader    Wed Mar  9 22:30:00 2022
 *
 *		built from:	inlineList_impl.ifc
 */

#ifndef reda_inlineList_impl_h
#define reda_inlineList_impl_h



  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif

  #ifndef reda_weakReference_h
    #include "reda/reda_weakReference.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif



struct REDAInlineListNode {
    /*i back pointer to the head of the list. */
    struct REDAInlineList *inlineList;
    /*i next in this list. */
    struct REDAInlineListNode *next;
    /*i prev in this list. */
    struct REDAInlineListNode *prev;
};

struct REDAInlineListWRNode {
    /*i Node used to add this WRNode to an inline list. */
    struct REDAInlineListNode node;
    /*i Weak Reference */
    struct REDAWeakReference wr;
    /*i User data*/
    void * userData;
};

struct REDAInlineListUserDataNode {
    /*i Node used to add this UserDataNode to an inline list. */
    struct REDAInlineListNode node;
    /*i User data*/
    void * userData;
};

struct REDAInlineList {
    /*i Head. */
    struct REDAInlineListNode _dummyNode;
    /*i Tail. */
    struct REDAInlineListNode *_tail;
    /*i Current number of nodes.  Do not modify externally. */
    int _size;
    /*i User data */
    void * _userData;
};

  #define REDAInlineListNode_INITIALIZER {NULL, NULL, NULL}
  #define REDA_INLINE_LIST_EMPTY {REDAInlineListNode_INITIALIZER, NULL, 0, NULL}

  #define REDAInlineList_getFirstMacro(l) (l)->_dummyNode.next

  #define REDAInlineList_getLastMacro(l) (l)->_tail

  #define REDAInlineList_isNodeInListMacro(l, node) ((l)==(node)->inlineList)

  #define REDAInlineListNode_getNextMacro(n) (n)->next

  #define REDAInlineListNode_getPrevMacro(n) \
        (((n)->prev->prev != NULL) ? (n)->prev : NULL)

  #define REDAInlineListNode_initMacro(node) \
    (node)->next = NULL, \
    (node)->prev = NULL, \
    (node)->inlineList = NULL

  #define REDAInlineList_initMacro(l) \
    REDAInlineListNode_init(&((l)->_dummyNode)), \
    (l)->_tail = NULL, \
    (l)->_size = 0, \
    (l)->_userData = NULL

  #define REDAInlineList_setUserDataMacro(l, userData) \
    (l)->_userData = (userData)

  #define REDAInlineList_getUserDataMacro(l) \
    (l)->_userData

  #define REDAInlineList_addNodeToFrontMacro(l, node) \
  { \
    (node)->inlineList = (l); \
    (node)->next = (l)->_dummyNode.next; \
    (node)->prev = &((l)->_dummyNode); \
    if ((node)->next != NULL) { (node)->next->prev = (node); } \
    else { (l)->_tail = (node); } \
    (l)->_dummyNode.next = (node); \
    ++((l)->_size); \
  }

  #define REDAInlineList_assertNodeToFrontMacro(l, node) \
  { \
    if ((node)->inlineList == NULL) { \
        (node)->inlineList = (l); \
        (node)->next = (l)->_dummyNode.next; \
        (node)->prev = &((l)->_dummyNode); \
        if ((node)->next != NULL) { (node)->next->prev = (node); } \
        else { (l)->_tail = (node); } \
        (l)->_dummyNode.next = (node); \
        ++((l)->_size); \
    } \
  }

  #define  REDAInlineList_addNodeAfterMacro(l, existingNode, node) \
  { \
    (node)->inlineList = (existingNode)->inlineList; \
    (node)->next = (existingNode)->next; \
    (node)->prev = existingNode; \
    if ((node)->next != NULL) { (node)->next->prev = (node); } \
    else { (l)->_tail = (node); } \
    (existingNode)->next = (node); \
    ++((l)->_size); \
  }

  #define  REDAInlineList_addNodeBeforeMacro(l, existingNode, node) \
  { \
    (node)->inlineList = (existingNode)->inlineList; \
    (node)->next = existingNode; \
    (node)->prev = (existingNode)->prev; \
    (node)->prev->next = (node); \
    (existingNode)->prev = (node); \
    ++((l)->_size); \
  }

  #define REDAInlineList_addNodeToBackMacro(l, node) \
  { \
    if ((l)->_tail == NULL) { \
        REDAInlineList_addNodeToFrontMacro(l, node); \
    } else { \
        (node)->inlineList = (l); \
        (l)->_tail->next = (node); \
        (node)->prev = (l)->_tail; \
        (node)->next = NULL; \
        (l)->_tail = (node); \
        ++((l)->_size); \
    } \
  }

  #define REDAInlineList_assertNodeToBackMacro(l, node) \
  { \
    if ((node)->inlineList == NULL) { \
        if ((l)->_tail == NULL) { \
            REDAInlineList_addNodeToFrontMacro(l, node); \
        } else { \
            (node)->inlineList = (l); \
            (l)->_tail->next = (node); \
            (node)->prev = (l)->_tail; \
            (node)->next = NULL; \
            (l)->_tail = (node); \
            ++((l)->_size); \
        } \
    } \
  }

  #define REDAInlineList_removeNodeMacro(l, node) \
  { \
      if ((l)->_tail == (node)) { \
          (l)->_tail = (node)->prev; \
      } \
      if ((l)->_tail == &((l)->_dummyNode)) { \
        (l)->_tail = NULL; \
      } \
      if ((node)->prev != NULL) { \
          (node)->prev->next = (node)->next; \
      } \
      if ((node)->next != NULL) { \
	  (node)->next->prev = (node)->prev; \
      } \
      --((node)->inlineList->_size); \
      REDAInlineListNode_init((node)); \
  }

  #define REDAInlineList_removeAllNodesMacro(l) \
  { \
      struct REDAInlineListNode *lastNodePt = REDAInlineList_getLast(l); \
      while (lastNodePt != NULL) { \
          REDAInlineList_removeNodeEA(l, lastNodePt); \
          lastNodePt = REDAInlineList_getLast(l); \
      } \
      REDAInlineList_init(l); \
  }

  #define REDAInlineList_getSize(l) (l)->_size

  #ifdef RTI_PRECONDITION_TEST
    REDADllExport struct REDAInlineListNode *
    REDAInlineList_getFirst(const struct REDAInlineList *l);

    REDADllExport struct REDAInlineListNode *
    REDAInlineList_getLast(const struct REDAInlineList *l);

    REDADllExport RTIBool REDAInlineList_isNodeInList(
	struct REDAInlineList *l, struct REDAInlineListNode *node);

    REDADllExport void
    REDAInlineListNode_init(struct REDAInlineListNode *node);

    REDADllExport void REDAInlineList_init(struct REDAInlineList *l);

    REDADllExport void REDAInlineList_addNodeToFrontEA(
	struct REDAInlineList *l, struct REDAInlineListNode *node);

    REDADllExport void REDAInlineList_assertNodeToFrontEA(
	struct REDAInlineList *l, struct REDAInlineListNode *node);

    REDADllExport void REDAInlineList_addNodeAfterEA(
        struct REDAInlineList *l, struct REDAInlineListNode *existingNode,
	struct REDAInlineListNode *node);

    REDADllExport void REDAInlineList_addNodeBeforeEA(
        struct REDAInlineList *l, struct REDAInlineListNode *existingNode,
	struct REDAInlineListNode *node);

    REDADllExport void REDAInlineList_addNodeToBackEA(
	struct REDAInlineList *l, struct REDAInlineListNode *node);

    REDADllExport void REDAInlineList_assertNodeToBackEA(
	struct REDAInlineList *l, struct REDAInlineListNode *node);

    REDADllExport void REDAInlineList_removeNodeEA(
	struct REDAInlineList *l, struct REDAInlineListNode *node);

    REDADllExport void REDAInlineList_removeAllNodesEA(
            struct REDAInlineList *l);

    REDADllExport void REDAInlineList_setUserData(
        struct REDAInlineList *l, void * userData);

    REDADllExport void * REDAInlineList_getUserData(
        struct REDAInlineList *l);

    REDADllExport struct REDAInlineListNode *REDAInlineListNode_getNext(
            const struct REDAInlineListNode *node);

    REDADllExport struct REDAInlineListNode *REDAInlineListNode_getPrev(
            const struct REDAInlineListNode *node);
  #else
    #define REDAInlineList_getFirst         REDAInlineList_getFirstMacro
    #define REDAInlineList_getLast          REDAInlineList_getLastMacro
    #define REDAInlineList_isNodeInList     REDAInlineList_isNodeInListMacro
    #define REDAInlineListNode_init         REDAInlineListNode_initMacro
    #define REDAInlineList_init             REDAInlineList_initMacro
    #define REDAInlineList_addNodeToFrontEA REDAInlineList_addNodeToFrontMacro
    #define REDAInlineList_assertNodeToFrontEA REDAInlineList_assertNodeToFrontMacro
    #define REDAInlineList_addNodeAfterEA   REDAInlineList_addNodeAfterMacro
    #define REDAInlineList_addNodeBeforeEA   REDAInlineList_addNodeBeforeMacro
    #define REDAInlineList_addNodeToBackEA  REDAInlineList_addNodeToBackMacro
    #define REDAInlineList_assertNodeToBackEA  REDAInlineList_assertNodeToBackMacro
    #define REDAInlineList_removeNodeEA     REDAInlineList_removeNodeMacro
    #define REDAInlineList_removeAllNodesEA     REDAInlineList_removeAllNodesMacro
    #define REDAInlineList_setUserData      REDAInlineList_setUserDataMacro
    #define REDAInlineList_getUserData      REDAInlineList_getUserDataMacro
    #define REDAInlineListNode_getNext      REDAInlineListNode_getNextMacro
    #define REDAInlineListNode_getPrev      REDAInlineListNode_getPrevMacro
  #endif /* RTI_PRECONDITION_TEST */



#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* reda_inlineList_impl_h */
