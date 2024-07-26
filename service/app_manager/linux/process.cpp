/*
 * @author 008196
 * @for application start and exit manager
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "process.h"

#include <array>
#include <string>
#include <unistd.h>
#include <node_log.h>

namespace OSAbstraction {

ProcessId OsProcess::CreateProcess(const std::string& executable_path)
{
  char const* const* const argv{ };
  int pos  = executable_path.rfind('/');
  std::string tmpName = executable_path;
  std::string exeName = tmpName.substr(pos+1); 
   char* executableName= const_cast<char*>(exeName.c_str());
   char *const args[] = { executableName, NULL };
   #ifdef __x86_64__
    // do x64 stuff
    char const* const* const envp{ };
   #else
    // do arm stuff
    char *envp[] = {"LD_LIBRARY_PATH=/home/root/sysbin/lib", NULL};
   #endif

  ProcessId pid{-1};

  std::array<char, 100> absolute_binary_path{};
  if (::realpath(executable_path.c_str(), absolute_binary_path.data()) == nullptr) {
    // Image path does not exist.
    HHT_LOG(ERROR) << "Error path";
  } else {
     // 在调用fork之前设置SIGCHLD信号处理,是一种防止子进程成为僵尸进程的方法之一,开销较小。
    // 这会告诉内核，在子进程终止后，由系统自动回收子进程的资源，而不需要父进程显式调用wait或waitpid来等待子进程退出。
    signal(SIGCHLD, SIG_IGN);
    pid = ::fork();
    if (pid < 0) {
      // Creating a child process failed.
      return pid;

    } else if (pid > 0) {
      // Creating a child process succeeded - path for parent process.
      HHT_LOG(INFO) << "Parent path";
      // result = ara::core::Result<ProcessId>::FromValue(pid);
    } else {
      // Creating a child process succeeded - path for child process.

      /* HHT_LOG(INFO) << "child Path";
       * 注释此行，因为本分支是由子进程执行，假如一开始就调用HHT_LOG接口，
       * 那么会额外创建AppManagerLog_HDBM_20180309-204636_子进程PID.log，类似这种空日志文件
       */

      int res=1;

   #ifdef __x86_64__
    // do x64 stuff
      //  res = execve(absolute_binary_path.data(), const_cast<char* const*>(argv), const_cast<char* const*>(envp));
        res = execve(absolute_binary_path.data(), args, const_cast<char* const*>(envp));
   #else
    // do arm stuff
        res = execve(absolute_binary_path.data(), args, envp);
   #endif

      HHT_LOG(ERROR) << "result is :" << res << " unexcept path executed:"<< absolute_binary_path.data();
      exit(1);
    }
  }

  return pid;
}

}
