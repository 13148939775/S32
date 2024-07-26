/* @author T001285
 * @for app_example file
 * @version 0.1
 * @date 2023-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "app_example.h"
#include <thread>
#include "node_log.h"

bool HHT::AppExample::DoInit() 
{
    HHT_LOG(INFO)<<"DoInit";
    return true;
}
bool HHT::AppExample::DoSuspend() 
{
    HHT_LOG(INFO)<<"DoSuspend";
    return true;
}
void HHT::AppExample::Run() 
{
    HHT_LOG(INFO)<<"Run";
    // 这里可以放一些实际工作的代码
    std::thread work([](){
    // 在这里定义线程的工作内容
    for (int i = 0; i < 6; ++i) {
        HHT_LOG(INFO)<<"Running";
        std::this_thread::sleep_for(std::chrono::seconds(6));
        }    
    });
    work.join();
    return;
}
bool HHT::AppExample::DoShutdown() 
{
    HHT_LOG(INFO)<<"DoShutdown";
    return true;
}

 
