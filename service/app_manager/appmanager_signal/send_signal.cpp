#include <iostream>
#include <csignal>
#include <unistd.h>

int main(int argc,char* argv[]) {
    pid_t targetProcessId =2029430 ; // 替换为您要发送信号的目标进程的PID

    int result = kill(targetProcessId,SIGUSR1);
    if (result == 0) {
        std::cout << " signal sent to process " << targetProcessId << std::endl;
    } else {
        std::cerr << "Failed to send  signal to process " << targetProcessId << std::endl;
    }

    return 0;
}

