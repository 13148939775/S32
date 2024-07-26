/*
 * @author 008196
 * @for application log file entry
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MSG_QUE_H
#define MSG_QUE_H

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

//namespace Hdf_platform {

template <typename T>
class MsgQue {
public:
    MsgQue(int capacity = 1000, int threshold = 100)
      : capacity_(capacity),
        threshold_(threshold),
        exit_(false)     
    { }

    ~MsgQue() { }

    bool TryPush(const T& data)
    {
        if (localQue_.size() >= capacity_) {
            return false;
        }
        {
            std::unique_lock<std::mutex> lk(mtx_);
            localQue_.push(data);
        }

        if (localQue_.size() >= threshold_) {
            cvPush_.notify_all();
        }
    };

    bool Pop(T& msg)
    {
        std::unique_lock<std::mutex> lk(mtx_);
        cvPush_.wait(lk, [=]() {
            return !IsEmpty() || exit_; 
        });
        if (!IsEmpty()) {
            msg = localQue_.front();
            localQue_.pop();
            return true;
        }
        return false;
    };

    bool IsEmpty()
    {
        return localQue_.size() == 0;
    }

    const uint32_t size() const
    {
        return localQue_.size();
    }

    T& front()
    {
        return localQue_.front();
    }
private:
    int capacity_;
    int threshold_;
    volatile bool exit_;
    std::queue<T> localQue_;  // deque is the dual queue, implement by
    std::mutex mtx_;
    std::condition_variable cvPush_;
};
//}

#endif /* MSG_QUE_H */
