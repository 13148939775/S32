#include <iostream>
#include <thread>
#include <chrono>

inline void WaitForShutdown() {
  while (!false) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

// entry for start as an services
int main(int argc, char * argv[])
{
    std::cout << "entry B" << std::endl;
    WaitForShutdown();

    return 0;
}