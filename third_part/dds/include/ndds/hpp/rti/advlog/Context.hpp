/*
 (c) Copyright, Real-Time Innovations, 2017-
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
*/

#ifndef HPP_SERVICE_LOG_ADVLOG_CONTEXT_CONTEXT_HPP_
#define HPP_SERVICE_LOG_ADVLOG_CONTEXT_CONTEXT_HPP_

#include <cstdio>
#include <cstdarg>

#include "osapi/osapi_utility.h"
#include "advlog/advlog_context.h"

namespace rti { namespace advlog {

/*
 * Default max length for the list of entries and for the list of params.
 * It is only used in Routing Service.
 */
#define ADVLOG_CONTEXT_ENTRY_SIZE_DEFAULT 4
#define ADVLOG_CONTEXT_LIST_PARAMS_SIZE_DEFAULT 5

/*
 * This class is used to enter and leave resource/activity entries into
 * the context. It keeps track of the context entries we have entered and left.
 *
 * It is called scope because all the entries entered from the creation of the
 * class will be left in the destructor.
 */
class ContextScope {
public:

    /*
     * @brief Begin the contextScope.
     * Initialize the variables of the class.
     */
    ContextScope()
    {
        __entryIndex = 0;
        __maxEntryCount = ADVLOG_CONTEXT_ENTRY_SIZE_DEFAULT;
        __maxParamCount = ADVLOG_CONTEXT_LIST_PARAMS_SIZE_DEFAULT;
        __paramIndex = 0;
    }

    /*
     * @brief Close the contextScope.
     * All the entries entered from the creation of the class will be left now.
     */
    virtual ~ContextScope()
    {
        ADVLOGContext_leaveGroup(
                NULL, /* activityContext */
                __entryIndex);
    }

    /*
     * @brief Enter an resource entry in the context.
     * In order to leave this entry from the context, you can call leave.
     *
     * @param resource \b In. The resource of the entry.
     */
    void enter(const char *resource)
    {
        ADVLOGContextScope_enterResource(resource);
    }

    /*
     * @brief Enter an activity entry in the context.
     *  In order to leave this entry from the context, you can call leave.
     *
     * @param formatTemplate \b In. The format of the entry.
     * @param param \b In. List of params.
     */
    void enter(
            const ADVLOGContextTemplate *template_format,
            const char *param = NULL)
    {
        if (param != NULL) {
            ADVLOGContextScope_enterActivityWithParams(
                    template_format,
                    param);
        } else {
            ADVLOGContextScope_enterActivity(template_format);
        }
    }

    /*
     * @brief Leave the last N entries of the context.
     *
     * @param number_entries \b In. The number of entries to leave from the
     * context.
     *
     */
    void leave(unsigned int number_entries = 1)
    {
        ADVLOGContext_leaveGroup(
                NULL, /* activityContext */
                number_entries);
        if (__entryIndex - number_entries <= 0) {
            __entryIndex = 0;
            __paramIndex = 0;
        } else {
            __entryIndex -= number_entries;
        }
    }

private:

    /*
     * The private members of the class have those names because they are used
     * by the ADVLOGContextScope macros.
     */
    RTI_UINT32 __entryIndex;
    RTI_UINT32 __maxEntryCount;
    struct RTIOsapiActivityContextStackEntry __entry[ADVLOG_CONTEXT_ENTRY_SIZE_DEFAULT];
    void *__paramsList[ADVLOG_CONTEXT_LIST_PARAMS_SIZE_DEFAULT];
    RTI_UINT32 __paramIndex;
    RTI_UINT32 __maxParamCount;
};

/*
 * This structure is used to enter and leave a resource and an activity entry
 * into the context it is used by the entityListener in Recording and CDS.
 */
struct Entries
{
    /*
     * @brief Initialize the variables of the class.
     */
    Entries()
    {
        entries = NULL;
        param_index = NULL;
    }

    /*
     * @brief Translate the structure from C to C++.
     *
     * @param entries_native \b In. It is the C structure for the entries
     * @param param_native \b In. It is the C structure for the params.
     */
    void from_native(
            struct RTIOsapiActivityContextStackEntry *entries_native,
            const void **params_native)
    {
        entries = entries_native;
        param_index = params_native;
    }

    /*
     * @brief Enter an resource entry and an activity entry in the context.
     *  In order to leave these entries from the context, you can call leave.
     *
     * @param resource \b In. The resource of the entry.
     * @param formatTemplate \b In. The format of the activity entry.
     * @param activity_param \b In. The param of the activity.
     */
    void enter(
            const char *resource,
            const ADVLOGContextTemplate *template_format,
            const char *activity_param = NULL)
    {
        /* Resource entry */
        entries[0].kind = RTI_OSAPI_ACTIVITY_CONTEXT_ENTRY_KIND_RESOURCE;
        entries[0].format = RTI_ADVLOG_CONTEXT_TEMPLATE_RESOURCE_s.format;
        entries[0].params = (char *) (resource);
        RTIOsapiActivityContext_enter(&entries[0]);
        /* Activity entry */
        entries[1].format = (template_format)->format;
        if (activity_param == NULL) {
            entries[1].kind = RTI_OSAPI_ACTIVITY_CONTEXT_ENTRY_KIND_ACTIVITY;
        } else {
            entries[1].kind =
                    RTI_OSAPI_ACTIVITY_CONTEXT_ENTRY_KIND_ACTIVITY_WITH_PARAMS;
            *param_index = (char *) (activity_param);
            entries[1].params = param_index;
        }
        RTIOsapiActivityContext_enter(&entries[1]);
    }

    /*
     * @brief Leave the last N entries of the context.
     *
     * @param number_entries \b In. The number of entries to leave from the context.
     *
     */
    void leave(unsigned int number_entries = 1)
    {
        RTIOsapiActivityContext_leaveGroup(
                NULL, /* activityContext */
                number_entries);
    }

private:
    struct RTIOsapiActivityContextStackEntry *entries;
    const void **param_index;
};


} } // rti::advlog

#endif /* HPP_SERVICE_LOG_ADVLOG_CONTEXT_CONTEXT_HPP_ */
