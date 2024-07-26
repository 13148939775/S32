/*
 * @author 008196
 * @for custom scene scheduler
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <thread>
#include <atomic>

#include <utils/msg_que.h>
#include <node_log.h>
#include <service/scene_engine/custom_scene.h>
// namespace Hdf_platform {
template <typename T, typename M>
class Scheduler {
public:
    Scheduler()
      : exit_(false),
        inited_(false)  // temp by cuke
    { }

    ~Scheduler()
    {
        exit_ = true;
    }

    Scheduler(Scheduler&) = delete;
    Scheduler& operator=(Scheduler&) = delete;

    static Scheduler& GetInstance()
    {
        static Scheduler<T, M> sc;
        return sc;
    }

    void Add2Exec(T& sc)
    {
        //add waitingque ,for later use
        waitingQue_.push_back(sc);
        // 打断低优先级的执行
        //remove conflict sceneCard
        runningQue_.Remove(sc.Adj());
        //add runningque
        runningQue_.TryPush(sc);
    }

    // 每次只能有一个场景执行，所以单线程
    void Start()
    {
        if (inited_ == true) {
            return;
        } 
        inited_ = true;
        // workers, 10ms scheduler period
        worker_ = std::thread(
            [this]() {
                while (!exit_) {
                    T sc;
                    if (!runningQue_.Pop(sc)) {
                        // entry wait status
                        HHT_LOG(ERROR)<<"will get data from waiting Queue";
                        if (!waitingQue_.IsEmpty()) {
                            waitingQue_.Pop(sc);
                        } else {
                            HHT_LOG(INFO)<<"will exit";
                            exit_.store(true);
                        }
                    }
                }
            }
        );
    }

    void AddtoWaitingQue(T& data)
    {
        waitingQue_.TryPush(data);
    }

    void AddtoRunningQue(T& data)
    {
        runningQue_.TryPush(data);
    }

    bool AddtoSuspendQue(T& msg)
    {
        return suspendQue_.TryPush(msg);
    }
    void AddtoAlwaysQue(T& msg)
    {
        alwaysOnScene_.TryPush(msg);
    }

    bool PoptoWaitingQue(T& msg)
    {
        
        return waitingQue_.Pop(msg);
    }

    bool PoptoRunningQue(T& msg)
    {
        return runningQue_.Pop(msg);
    }

    bool PoptoSuspendQue(T& msg)
    {
        return suspendQue_.Pop(msg);
    }

    bool PoptoAlwaysQue(T& msg)
    {
        return alwaysOnScene_.Pop(msg);
    }

    bool IsRunningQueEmpty()
    {
        return runningQue_.IsEmpty();
    }

    bool isSuspendQueEmpty()
    {
        return suspendQue_.IsEmpty();
    }

    //
    const int GetRunningQueSize()
    {
        return runningQue_.size();
    }

    const int GetWaitingQueSize()
    {
        return waitingQue_.size();
    }

    const int GetSuspendQueSize()
    {
        return suspendQue_.size();
    }

    T& GetRunnningQueFront()
    {
        return runningQue_.front();
    }

    T& GetSuspendQueFront()
    {
        return suspendQue_.front();
    }


protected:

    MsgQue<T> waitingQue_;
    MsgQue<T> runningQue_;
    MsgQue<T> suspendQue_;
    MsgQue<T> alwaysOnScene_;

    std::thread worker_;
    std::atomic<bool> exit_{false};
    std::mutex mtx_;
    bool inited_;
};
//}
#endif /* SCHEDULER_H */
