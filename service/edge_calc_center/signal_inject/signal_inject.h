/*
 * @file
 * @author 008196
 * @for signal simulator inject 
 * @version 0.1
 * @date 2023-08 ~ 2023-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SIGNAL_INJECT_H
#define SIGNAL_INJECT_H

#include <unordered_map>
#include <vector>
#include <thread>

#include <buffer_manager/buf_pool.h>

namespace HHT {
namespace DataManager {
class SignalInject {
public:
    SignalInject()
      : running_(true),
        bufPool_(10 * 1024, 10, true)
    { }
    ~SignalInject() { }
    SignalInject& GetInstance()
    {
        static SignalInject sl;
        return sl;
    }
    void Init();
    uint8_t* GetData() const
    {
        return data_;
    }
private:
    std::thread simCreateT_;
    std::thread simReleaseT_;
    bool running_;
    BufPool bufPool_;
    uint8_t* data_;
};
}
}
#endif /* SIGNAL_INJECT_H */
