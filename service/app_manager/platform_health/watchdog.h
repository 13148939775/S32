#ifndef WATCHDOG_INTERFACE_H
#define WATCHDOG_INTERFACE_H

#include <unordered_set>

namespace HHT {
class Watchdog {  // abstract class
public:
    class TaskIF {
    public:
        virtual void Run() = 0;   // pure virtual function
    };

    static std::shared_ptr<Watchdog>& GetInstance()
    {
        static std::shared_ptr<Watchdog> watch_dog_instance(new Watchdog());
        return watch_dog_instance;
    }

    /**
     * Add a new task to the tasks list
     * @param task Pointer to a singleton task
     */
    void AddTask(TaskIF* task)
    {
        std::lock_guard<std::mutex> lk(running_tasks_mutex_);
        tasks_.insert(task);
    }

    /**
     * Remove a task from the list
     * @param task Pointer to a singleton task
     */
    void RemoveTask(TaskIF* task)
    {
        std::lock_guard<std::mutex> lk(running_tasks_mutex_);

        auto it = tasks_.find(task);
        if (it != tasks_.end()) {
            tasks_.erase(it);
        }
    }

    static constexpr std::chrono::milliseconds Period()
    {
        return std::chrono::milliseconds(20000);
    }

    ~Watchdog()
    {
        exit_thread_ = true;
        wake_up();
        thread_run_.join();
    }


private:
    Watchdog()
        : wake_run_(false),
          exit_thread_(false)
    {
        thread_run_ = std::thread(&Watchdog::Start, this);
    }

    /**
     * Forces Wake-up of the checking thread
     */
    void wake_up()
    {
        {
            std::lock_guard<std::mutex> lk(wake_run_mutex_);
            wake_run_ = true;
        }

        wake_run_cv_.notify_one();
    }

    void Start()
    {
        while (!exit_thread_) {
            {
                std::unique_lock<std::mutex> lk(wake_run_mutex_);

                // run while timeout at interval 1s
                wake_run_cv_.wait_for(
                    lk,
                    Period(),
                    [&]
                    {
                        return wake_run_;
                    });
                wake_run_ = false;
            }
            std::lock_guard<std::mutex> lk(running_tasks_mutex_);
            for (auto task : tasks_) {
                task->Run();
            }
        }
    }

private:
    std::unordered_set<TaskIF*> tasks_;
    std::thread thread_run_;

    std::mutex running_tasks_mutex_;
    std::condition_variable wake_run_cv_;
    std::mutex wake_run_mutex_;
    bool wake_run_;

    bool exit_thread_;
};
}

#endif /* WATCHDOG_INTERFACE_H */
