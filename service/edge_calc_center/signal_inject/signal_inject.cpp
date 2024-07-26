/*
 * @file
 * @author 008196
 * @for signal simulator inject 
 * @version 0.1
 * @date 2023-02 ~ 2023-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "signal_inject.h"

#include <random>
#include <chrono>
#include <cstring>
#include <string>

#include <sys/prctl.h>
#include <node_log.h>

namespace HHT {
namespace DataManager {
uint64_t GetCurrentTimestamp() {
    timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return (uint64_t)time.tv_sec * 1000 + time.tv_nsec/1000000;
}

void SignalInject::Init()
{
   // std::random_device rd{};
   // std::mt19937 gen{rd()};
 
    // 值最可能接近平均
    // 标准差影响生成的值距离平均数的分散
    // std::normal_distribution<> d{5,2};
    HHT_LOG(INFO) << "SignalInject::Init()";
    data_ = bufPool_.MallocMetaBuf();
    
    simCreateT_ = std::thread([this]() {
        prctl(PR_SET_NAME, "sim signal inject");
        while (running_) {
            if (data_ == nullptr) {
                data_ = bufPool_.MallocMetaBuf();
            }
            uint32_t timestamp = GetCurrentTimestamp();
            // std::memcpy(data_, static_cast<void*>(&timestamp), sizeof(uint64_t));
            // just fill in data 
            std::memset(data_, 0x687898, bufPool_.MetaSize());
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    });

    // not to release the unit,
    simReleaseT_ = std::thread( [this]() {
        while (false) {
            if (data_ != nullptr) {
                bufPool_.ReleaseMetaBuf(data_);
                data_ = nullptr;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });
}
}
}