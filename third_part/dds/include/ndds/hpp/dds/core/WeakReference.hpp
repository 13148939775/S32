#ifndef OMG_DDS_CORE_WEAK_REFERENCE_HPP_
#define OMG_DDS_CORE_WEAK_REFERENCE_HPP_

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

#include <dds/core/Reference.hpp>

namespace dds {
  namespace core {
    template <typename T>
    class WeakReference;
  }
}
/**
 * Unsupported - WeakReference is not currently supported.
 */
template <typename T>
class dds::core::WeakReference {
public:
  typedef T ReferenceType;

public:

  WeakReference(const T& t);

  ~WeakReference();


  bool expired();


  T lock();

private:
  typename T::DELEGATE_WEAK_REF_T impl_;
};

#endif /* OMG_DDS_CORE_WEAK_REFERENCE_HPP_ */
