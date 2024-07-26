#include <iostream>
#include <dlfcn.h>
#include <string>
#include <vector>
#include <thread>
#include <unistd.h>
#include <sys/wait.h>

// std::string libPath = LIBNTPDATE_PATH;
std::string libPath = "./libntpdate.so";

int main(int argc, char **argv)
{
    std::cout << "libPath: " << libPath << std::endl;
    std::vector<std::string> server_list = {
        "106.55.184.199",   //ntp.tencent.com
        "203.107.6.88",     //ntp.aliyun.com
        "84.16.67.12",      //pool.ntp.org
        "pool.ntp.org",
        "ntp.tencent.com",
        "ntp1.tencent.com",
        "ntp2.tencent.com",
        "ntp3.tencent.com",
        "ntp4.tencent.com",
        "ntp5.tencent.com",
        "ntp.aliyun.com",
        "ntp1.aliyun.com",
        "ntp2.aliyun.com",
        "ntp3.aliyun.com",
        "ntp4.aliyun.com",
        "ntp5.aliyun.com",
        "ntp6.aliyun.com",
        "ntp7.aliyun.com",
        "time.edu.cn",
        "s2c.time.edu.cn",
        "s2f.time.edu.cn"
    };

    void *handle;
    int (*callfun)(int,char**);
    const char *error;
    bool ntpFlag = true; 

    while (ntpFlag) {
        for (const auto& server : server_list) {
            std::cout << "Trying server: " << server << std::endl;

            pid_t pid = fork();
            if (pid < 0) {
                std::cerr << "Fork failed" << std::endl;
                return 1;
            } else if (pid == 0) {
                // Child process
                handle = dlopen(libPath.c_str(), RTLD_LAZY);
                if (!handle) {
                    std::cerr << "Failed to load library: " << dlerror() << std::endl;
                    exit(1);
                }

                *(void**) (&callfun) = dlsym(handle, "ntpdatemain");
                if ((error = dlerror()) != NULL) {
                    std::cerr << "Failed to find function: " << error << std::endl;
                    exit(1);
                }

                char *str[] = {(char *)"", (char *)server.c_str()};
                int result = callfun(2, str);
                exit(result);
            } else {
                // Parent process
                int status;
                waitpid(pid, &status, 0);

                int exit_code = WEXITSTATUS(status);
                if (exit_code == 0) {
                    std::cout << "成功同步时间：" << server << std::endl;
                    break;
                } else {
                    std::cout << "无法与服务器同步时间：" << server << std::endl;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}