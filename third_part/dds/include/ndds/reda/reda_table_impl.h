/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_table_impl.h    generated by: makeheader    Wed Mar  9 22:30:01 2022
 *
 *		built from:	table_impl.ifc
 */

#ifndef reda_table_impl_h
#define reda_table_impl_h


  #ifndef reda_epoch_h
    #include "reda/reda_epoch.h"
  #endif
  #ifndef reda_inlineList_h
    #include "reda/reda_inlineList.h"
  #endif
  #ifndef reda_skiplist_h
    #include "reda/reda_skiplist.h"
  #endif
  #ifndef reda_recordAdminArea_h
    #include "reda/reda_recordAdminArea.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif


struct REDARecordAllocatorInfo {
    void *_pool;
    int   _offsetToKey;
    int   _offsetToAdminArea;
    int   _offsetToReadOnlyArea;
    int   _offsetToReadWriteArea;
};


struct REDATable {
    /*i The info for the allocators */
    struct REDARecordAllocatorInfo _recordAllocatorInfo;

    /*i Table uses a HashedSkiplist */
    struct REDAHashedSkiplist *_list;

    /*i The EA used for short, internal locking.  The table 
        implementation assumes that it is allowed to enter this EA 
	at any time BUT that it cannot enter any other EA while 
	in the adminEA.  
	The table cannot return control to the user while in 
        the adminEA.  */
    struct REDAExclusiveArea *_adminEA;
    
    /*i The EA used for table-level locking.  Certain calls
        can return to the user while staying in this EA.
        The logic is maintained through the cursor-states. */
    struct REDAExclusiveArea *_tableEA;

    /* Used to issue new weak references. */
    struct REDAWeakReferenceManager *_weakReferenceManager;

    /*i Key type */
    struct REDAOrderedDataType *_keyType;

    /*i ROArea type */
    struct REDAOrderedDataType *_readOnlyAreaType;

    /*i RWArea type */
    struct REDAOrderedDataType *_readWriteAreaType;

    /*i Function that is called by REDATable_cleanup after the table
	is removed, when it is finally possible to delete it.
	This function is called inside the tableEA. 
    */
    REDATableFinalizeFunction _tableFinalizeFnc;
    /*i Parameter passed to _tableFinalizeFnc */
    void *_tableFinalizeParam;

    /*i Indicates the _tableFinalizeFnc has already been called. Protects
	the table so that the _tableFinalizeFnc is only called once
    */
    RTIBool _tableIsFinalized;

    /*i Function called after the record is removed when it is ready to
	be deleted. */
    REDATableRecordFinalizeFunction _recordFinalizeFnc;
    /*i Parameter passed to _recordFinalizeFnc */
    void *_recordFinalizeParam;

    /*i A pointer to the allocators */
    struct REDARecordAllocator *_recordAllocator;

    /* ============= START PART MANAGED BY REDATableEpoch =============== */
    /* the following fields are managed by the TableEpoch module: they are 
       to be modified/used through the methods in REDATableEpoch
     */
    REDAEpoch _te_tableEpoch;
    /* =============== END PART MANAGED BY REDATableEpoch =============== */

    /*i 
      the table itself must remember the cursors.
      Any access to this list is must be protected with the adminEA. This 
      includes iteration aside from additions/removals.
    */
    struct REDAInlineList _cursorList;
    
    /*i All removed records that await deletion are put in a 
        linked list.  The first element of this list is the
	firstRemovedSkiplistNode of the table (this can be NULL
	if there is nothing to delete).
	A next element on this list can be reached by following
	the pointer nextRemovedSkiplistNode of the RecordAdmin.
	Modifying this is protected with the tableEA
    */
    const struct REDASkiplistNode *_firstRemovedSkiplistNode;

    /*i
	User data: user can store one pointer in table on creation */
    void *_tableUserData;

    /*i
      Optional table name.
    */
    char _tableName[REDA_TABLE_NAME_MAX_LENGTH+1];
};



#define REDARecordAllocator_getKeyFromRecord(offsets, record) \
    ( ((char*)(record)) + ((offsets)->_offsetToKey) )

#define REDARecordAllocator_getAdminAreaFromRecord(offsets, record) \
    ( ((char*)(record)) + ((offsets)->_offsetToAdminArea) )

#define REDARecordAllocator_getReadOnlyAreaFromRecord(offsets, record) \
    ( ((char*)(record)) + ((offsets)->_offsetToReadOnlyArea) )

#define REDARecordAllocator_getReadWriteAreaFromRecord(offsets, record) \
    ( ((char*)(record)) + ((offsets)->_offsetToReadWriteArea) )

#define REDATable_getName(table) ((const char *) (table)->_tableName)

#define REDATable_getKeyFromRecordMacro(table, record) \
    REDARecordAllocator_getKeyFromRecord(&((table)->_recordAllocatorInfo), record)

#define REDATable_getAdminAreaFromRecordMacro(table, record) \
    (struct REDARecordAdminArea *) \
      REDARecordAllocator_getAdminAreaFromRecord(&((table)->_recordAllocatorInfo), record)

#define REDATable_getReadOnlyAreaFromRecordMacro(table, record) \
    REDARecordAllocator_getReadOnlyAreaFromRecord(&((table)->_recordAllocatorInfo), record)

#define REDATable_getReadWriteAreaFromRecordMacro(table, record) \
    REDARecordAllocator_getReadWriteAreaFromRecord(&((table)->_recordAllocatorInfo), record)

#define REDATable_getKeyFromNodeMacro(table, node) \
    REDATable_getKeyFromRecordMacro((table), REDASkiplistNode_getUserData(node))

#define REDATable_getAdminAreaFromNodeMacro(table, node) \
    REDATable_getAdminAreaFromRecordMacro((table), REDASkiplistNode_getUserData(node))

#define REDATable_getReadOnlyAreaFromNodeMacro(table, node) \
    REDATable_getReadOnlyAreaFromRecordMacro((table), REDASkiplistNode_getUserData(node))

#define REDATable_getReadWriteAreaSizeMacro(table) \
        (((table)->_readWriteAreaType != NULL) ? \
        REDAOrderedDataType_getInstanceSize((table)->_readWriteAreaType) : 0)

#define REDATable_getReadWriteAreaFromNodeMacro(table, node) \
    REDATable_getReadWriteAreaFromRecordMacro((table), REDASkiplistNode_getUserData(node))

#define REDATable_getTableUserDataMacro(table) ((table)->_tableUserData)

#define REDATable_getTableEAMacro(table) ((table)->_tableEA)

#define REDATable_getRecordCountMacro(table) \
    (REDAHashedSkiplist_getNodeCountMacro((table)->_list))

#define REDATable_tableHasReadOnlyAreaMacro(table) \
    (((table)->_readOnlyAreaType != NULL) ? RTI_TRUE : RTI_FALSE)

#define REDATable_tableHasReadWriteAreaMacro(table) \
    (((table)->_readWriteAreaType  != NULL) ? RTI_TRUE : RTI_FALSE)

#define REDATable_unfreezeReadWriteAreaMacro(table, node, c) \
    (((REDATable_getAdminAreaFromNodeMacro((table), (node)))->_cursor == NULL ||\
     (REDATable_getAdminAreaFromNodeMacro((table), (node)))->_cursor == (c)) ? \
     ((REDATable_getAdminAreaFromNodeMacro((table), (node)))->_cursor = NULL,  \
      RTI_TRUE) : RTI_TRUE)

/* ========================================================== */
#define REDATableProperty_init(me, \
                               initialVal, maximalVal, growthIncrement, \
                               hashBucketNum) \
{ \
    (me)->growth.initial = (initialVal); \
    (me)->growth.maximal = (maximalVal); \
    (me)->growth.increment = (growthIncrement); \
    (me)->hashBucketCount = (hashBucketNum); \
}

#define REDATableProperty_unpack(me, \
                               initialVal, maximalVal, growthIncrement, \
                               hashBucketNum) \
{ \
    *(initialVal) = (me)->growth.initial; \
    *(maximalVal) = (me)->growth.maximal; \
    *(growthIncrement) = (me)->growth.increment; \
    *(hashBucketNum) = (me)->hashBucketCount; \
}


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* reda_table_impl_h */
