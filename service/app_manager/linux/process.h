/*
 * @author 008196
 * @for application start and exit manager
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <signal.h>
#include <sched.h>
#include <sys/types.h>
#include <cstdint>

namespace OSAbstraction {

using UserId = uid_t;
using ProcessId = pid_t;
using GroupId = gid_t;

class OsProcess final {
public:
  static ProcessId CreateProcess(const std::string& executable_path);
  //explicit OsProcess(ProcessHandle process_handle) : pid_(process_handle) {}
  ~OsProcess() noexcept { Kill(); }

  OsProcess(const OsProcess& other) = delete;
  OsProcess& operator=(const OsProcess& other) = delete;
  OsProcess(OsProcess&& other) = delete;
  OsProcess& operator=(OsProcess&& other) = delete;

    void Kill() noexcept { };
 private:
  /*!
   * \brief   Process ID (also process handle).
   */
  pid_t pid_;

  /*!
   * \brief   True if the process is running. Otherwise false.
   */
  bool is_running_{true};
};

}

#endif /* PROCESS_H */
