#ifndef OMG_TDDS_CORE_WAIT_SET_HPP_
#define OMG_TDDS_CORE_WAIT_SET_HPP_

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

#include <vector>

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/types.hpp>
#include <dds/core/cond/Condition.hpp>
#include <dds/core/Duration.hpp>

namespace dds {
  namespace core {
    namespace cond {
      template <typename DELEGATE>
      class TWaitSet;
    }
  }
}


/**
 * @ingroup DDSConditionsModule
 * @RTI_class_definition class dds::core::cond::WaitSet
 * @headerfile dds/core/cond/WaitSet.hpp
 *
 * @brief @st_ref_type Allows an application to wait until one or more of the attached
 * Condition objects have a trigger_value of true or else until the timeout expires.
 *
 * @note A WaitSet provides all the functions of a @st_ref_type except
 * close() and retain().
 *
 * @details \dref_details_WaitSet
 *
 * @see \ref DDSWaitsetExampleModule
 */
template <typename DELEGATE>
class dds::core::cond::TWaitSet : public dds::core::Reference<DELEGATE> {
public:
  /**
   * @brief A vector of Conditions
   */
  typedef std::vector<dds::core::cond::Condition> ConditionSeq;

public:
  // Spec issue CPPPSM-166: using OMG_DDS_REF_TYPE_DELEGATE to provide a
  // public default constructor
  OMG_DDS_REF_TYPE_DELEGATE(TWaitSet, dds::core::Reference, DELEGATE)

  /**
   * @brief Creates a WaitSet with no conditions attached.
   */
  TWaitSet() : Reference<DELEGATE>(new DELEGATE())
  {
  }

  // Create a WaitSet using an extension argument unknown in the standard header
  template <typename ARG>
  explicit TWaitSet(const ARG& arg) : Reference<DELEGATE>(new DELEGATE(arg))
  {
  }

#ifdef DOXYGEN_DOCUMENTATION_ONLY
  /**
   * @brief @extension Creates a WaitSet with a WaitSetProperty
   */
  WaitSetImpl(const rti::core::cond::WaitSetProperty& property);
#endif

  ~TWaitSet()
  {
  }

  TWaitSet(const dds::core::null_type&)
      : dds::core::Reference<DELEGATE>(static_cast<DELEGATE*>(NULL))
  {
  }

  TWaitSet& operator=(const dds::core::null_type&)
  {
      dds::core::Reference<DELEGATE>::operator=(dds::core::null);
      return *this;
  }

public:
    /**
     * @brief Allows an application thread to wait for the occurrence
     * of certain conditions.
     *
     * If none of the conditions attached to the dds::core::cond::WaitSet have a
     * trigger_value of true, the wait operation will block, suspending the
     * calling thread.
     *
     * The result of the wait operation is the list of all the attached
     * conditions that have a trigger_value of true (i.e., the conditions that
     * unblocked the wait).
     *
     * The wait operation takes a timeout argument that specifies the maximum
     * duration for the wait. If this duration is exceeded and none of the
     * attached dds::core::cond::Condition objects are true, wait will return an
     * empty condition sequence.
     *
     * Note: The resolution of the timeout period is constrained by the
     * resolution of the system clock.
     *
     * It is not allowable for more than one application thread to be waiting on
     * the same WaitSet. If the wait operation is invoked on a
     * WaitSet that already has a thread blocking on it, the
     * operation will return immediately with the value
     * dds::core::PreconditionNotMetError.
     *
     * @param timeout The maximum time to wait
     *
     * @return A vector containing the active conditions or an empty vector if
     * the operation times out.
     *
     * @throw dds::core::PreconditionNotMetError or one of the other \ref
     * DDSReturnTypesModule_std_retcodes. Note however that this operation *does
     * not* throw dds::core::TimeoutError.
     */
    const ConditionSeq wait(const dds::core::Duration& timeout)
    {
        return this->delegate()->wait(timeout);
  }

  /**
   * @brief Allows an application thread to wait for the occurrence
   * of certain conditions.
   *
   * This function is equivalent to `wait(dds::core::Duration::infinite())`.
   *
   * @see wait(const dds::core::Duration&)
   */
  const ConditionSeq wait()
  {
      return this->delegate()->wait();
  }

  /**
   * @brief Allows an application thread to wait for the occurrence
   * of certain conditions.
   *
   * This function is equivalent to `wait(const dds::core::Duration&)` but
   * reuses an existing vector instead of returning a new one.
   *
   * @param triggered A vector where the active conditions will be added. Any
   * element already present in the vector will be removed. If the operation
   * times out, this vector will be empty.
   * @param timeout The wait timeout
   *
   * @return A reference to \p triggered for convenience.
   *
   * @see wait(const dds::core::Duration&)
   */
  ConditionSeq& wait(ConditionSeq& triggered,
      const dds::core::Duration& timeout)
  {
      return this->delegate()->wait(triggered, timeout);
  }

  /**
   * @brief Allows an application thread to wait for the occurrence
   * of certain conditions.
   *
   * This application is equivalent to wait(triggered, dds::core::Duration::infinite());
   *
   * @see wait(ConditionSeq&, const dds::core::Duration&)
   */
  ConditionSeq& wait(ConditionSeq& triggered)
  {
      return this->delegate()->wait(triggered);
  }


  /**
   * @brief Waits for at least one of the attached conditions to  trigger and
   * then dispatches the events.
   *
   * This is an alternative, simpler pattern to the use of wait(). Instead of
   * receiving the list of active conditions, the application associates a
   * handler (functor) to each conditions before attaching it to the WaitSet.
   * Whenever this function wakes up it will call--in the current
   * thread context--the handler of each triggered condition before returning.
   *
   * Note that each condition can only have one handler, so if you want to
   * attach it to multiple WaitSets you may need to use wait() instead of
   * dispatch().
   *
   * @param timeout The maximum time to wait. If that time elapses dispatch()
   * will return without having called any of the condition handlers.
   *
   * @mtsafety It is not thread-safe to reset or replace a condition's handler
   * while dispatch() is running. It should be detached first. Detaching a
   * condition from a WaitSet while dispatch() is running is safe even if the
   * condition is active, but whether the condition handler will be executed or
   * not is undefined.
   *
   * @see \ref DDSWaitsetExampleModule_trigger "WaitSet wait and dispatch examples"
   */
  void dispatch(const dds::core::Duration& timeout)
  {
      this->delegate()->dispatch(timeout);
  }

  /**
   * @brief Waits for at least one of the attached conditions to trigger and then
   * dispatches the events.
   *
   * This function is equivalent to dispatch(dds::core::Duration::infinite());
   *
   * @see dispatch(const dds::core::Duration&)
   */
  void dispatch()
  {
      this->delegate()->dispatch();
  }

  /**
   * @brief Same as attach_condition()
   */
  TWaitSet& operator +=(dds::core::cond::Condition cond)
  {
      this->delegate()->attach_condition(cond);
      return *this;
  }

  /**
   * @brief Same as detach_condition().
   */
  TWaitSet& operator -=(dds::core::cond::Condition cond)
  {
      this->delegate()->detach_condition(cond);
      return *this;
  }

  /**
   * @brief Attaches a Condition to the WaitSet.
   *
   * @details \dref_details_WaitSet_attach_condition
   */
  TWaitSet& attach_condition(dds::core::cond::Condition cond)
  {
      this->delegate()->attach_condition(cond);
      return *this;
  }

  /**
   * @brief Detaches a Condition from the WaitSet.
   *
   * @details \dref_details_WaitSet_detach_condition
   */
  bool detach_condition(dds::core::cond::Condition cond)
  {
      return this->delegate()->detach_condition(cond);
  }

  /**
   * @brief Retrieves the list of attached conditions.
   *
   * @return the list of attached conditions.
   */
  ConditionSeq conditions() const
  {
      return this->delegate()->conditions();
  }

  /**
   * @brief Retrieves the list of attached conditions.
   *
   * @param conds A vector where the conditions will be aded
   * @return A reference to \p conds.
   */
  ConditionSeq& conditions(ConditionSeq& conds) const
  {
      return this->delegate()->conditions(conds);
  }
};

#endif /* OMG_TDDS_CORE_WAIT_SET_HPP_ */

