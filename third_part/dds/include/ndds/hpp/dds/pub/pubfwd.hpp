#ifndef OMG_DDS_PUB_PUB_FWD_HPP_
#define OMG_DDS_PUB_PUB_FWD_HPP_

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

#include <dds/pub/detail/pubfwd.hpp>

namespace dds { namespace pub {

class AnyDataWriter;
class AnyDataWriterListener;

template <typename T,
          template <typename Q> class DELEGATE = dds::pub::detail::DataWriterImpl>
class DataWriter;

template <typename T>
class DataWriterListener;

class NoOpAnyDataWriterListener;

template <typename T>
class NoOpDataWriterListener;

class NoOpPublisherListener;

typedef dds::pub::detail::Publisher Publisher;

class PublisherListener;

namespace qos {
    typedef ::dds::pub::qos::detail::DataWriterQos DataWriterQos;
    typedef ::dds::pub::qos::detail::PublisherQos PublisherQos;
}

} }

#endif /* OMG_DDS_PUB_PUB_FWD_HPP_ */

