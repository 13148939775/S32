#ifndef OMG_DDS_CORE_DETAIL_QOS_PROVIDER_HPP_
#define OMG_DDS_CORE_DETAIL_QOS_PROVIDER_HPP_

/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/TQosProvider.hpp>
#include <rti/core/QosProviderImpl.hpp>

namespace dds { namespace core { namespace detail {

typedef dds::core::TQosProvider<rti::core::QosProviderImpl> QosProvider;

}}}  // namespace dds::core::detail

namespace rti { namespace core {

/**
 * @relates dds::core::QosProvider
 *
 * @brief @extension Creates a QosProvider with parameters
 *
 * @namespace_note rti::core
 *
 * A dds::core::QosProvider is usually created with one of its constructors, but
 * this extension function allows configuring certain parameters. By default a
 * QosProvider loads the profiles from certain standard locations; this function
 * allows, for example, disabling that behavior.
 */
inline dds::core::detail::QosProvider create_qos_provider_ex(
        const rti::core::QosProviderParams &params)
{
    return dds::core::detail::QosProvider(
            new rti::core::QosProviderImpl(params));
}

}} // namespace rti::core

#endif /* OMG_DDS_CORE_DETAIL_QOS_PROVIDER_HPP_ */
