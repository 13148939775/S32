/*
 * @author 007313 008196
 * @for task control, idle Delay & running
 * @version 0.1
 * @date 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "HhtTaskLooper.h"

#include <chrono>
#include <queue>
#include <map>

#include "HhtMutex.h"
#include "HhtPriorityQueue.h"
#include "HhtThread.h"

namespace hht {

static constexpr std::chrono::milliseconds MIN_RANGE(10);

struct TaskLooper::Impl {
    typedef std::chrono::milliseconds Milliseconds;
    typedef std::chrono::steady_clock Clock;
    typedef Clock::time_point TimePoint;

    struct DealyTask {
        Task task;
        int32_t priority;
        TimePoint actTime;

        bool operator>(const DealyTask &other) const {
            return actTime > other.actTime;
        }
    };

    struct IdleTask {
        Task task;
        int32_t intervalMs;
        TimePoint actTime;

        operator bool() const {
            return (bool)task;
        }
    };

    using DelayTaskQueue = std::priority_queue<DealyTask, std::vector<DealyTask>,
                                               std::greater<DealyTask>>;
    using ActionTaskQueue = PriorityQueue<Task> ActionTaskQueue;

    DelayTaskQueue mDelayTasks;
    ActionTaskQueue mActionTasks;
    IdleTask mIdleTask;

    Mutex mMutex;
    Condition mCondition;
    bool mExiting = false;
    int32_t mTimeoutMs = LOOPER_DEFAULT_TIMEOUT_MS;

    Mutex mRunAllMutex;
    Condition mRunAllCondition;
    bool mInRunAll = false;

    ThreadId mThreadId = Thread::currentId();
    static Mutex sGlobalMutex;
    static std::map<ThreadId, TaskLooper *> sLoopers;
};

Mutex TaskLooper::Impl::sGlobalMutex;
std::map<ThreadId, TaskLooper *> TaskLooper::Impl::sLoopers;
/////////////////////////////

TaskLooper::TaskLooper(int32_t timeoutMs) :
    mImpl(new Impl()) {
    mImpl->mTimeoutMs = timeoutMs;
}

TaskLooper::~TaskLooper() {
    exit(true);

    AutoLock autolock(Impl::sGlobalMutex);
    auto it = Impl::sLoopers.find(mImpl->mThreadId);
    if (it != Impl::sLoopers.end()) {
        Impl::sLoopers.erase(it);
    }

    delete mImpl;
}

void TaskLooper::postTask(Task task, int32_t priority) {
    AutoLock autolock(mImpl->mMutex);

    mImpl->mActionTasks.push(task, priority);
    mImpl->mCondition.signal();
}

void TaskLooper::setIdleTask(Task task, int32_t intervalMs) {
    if (intervalMs < 0) {
        intervalMs = 0;
    }

    AutoLock autolock(mImpl->mMutex);

    mImpl->mIdleTask.task = task;
    mImpl->mIdleTask.intervalMs = intervalMs;
    mImpl->mIdleTask.actTime = Impl::Clock::now();
}

void TaskLooper::postDelayTask(Task task, int32_t timeoutMs, int32_t priority) {
    Impl::Milliseconds timeout(timeoutMs);
    Impl::TimePoint actTime = Impl::Clock::now() + timeout;
    Impl::DealyTask dealyTask{task, priority, actTime};

    AutoLock autolock(mImpl->mMutex);

    mImpl->mDelayTasks.push(dealyTask);
    mImpl->mCondition.signal();
}

void TaskLooper::runOnce(int32_t timeoutMs) {
    Task task;
    Impl::TimePoint now = Impl::Clock::now();
    {
        AutoLock autolock(mImpl->mMutex);

        // try move delaytask to actiontask
        while (!mImpl->mDelayTasks.empty() && mImpl->mDelayTasks.top().actTime < now + MIN_RANGE) { // Get overdate task
            Impl::DealyTask dtask = mImpl->mDelayTasks.top();
            mImpl->mDelayTasks.pop();

            mImpl->mActionTasks.push(dtask.task, dtask.priority);
        }

        if (mImpl->mActionTasks.isEmpty()) {
            // check and update timeout
            if (!mImpl->mDelayTasks.empty()) {
                Impl::Clock::duration timeout((int64_t)timeoutMs * 1000000);
                Impl::Clock::duration duration =
                    mImpl->mDelayTasks.top().actTime - now;

                if (duration < timeout) {
                    timeoutMs = (int32_t)(duration.count() / 1000000);
                }
            }

            mImpl->mCondition.waitFor(mImpl->mMutex, timeoutMs);
        }

        if (mImpl->mExiting) {
            // exit, just return
            return;
        }

        if (!mImpl->mActionTasks.isEmpty()) {
            // Normal Task
            task = mImpl->mActionTasks.pop();
        }
    }

    // run task
    if (task) {
        task();
    }

    // then now idle task in turn
    if (mImpl->mIdleTask) {
        int32_t durationMs = (int32_t)(
            (now - mImpl->mIdleTask.actTime).count() / 1000000);
        if (durationMs >= mImpl->mIdleTask.intervalMs) {
            mImpl->mIdleTask.actTime = now;
            mImpl->mIdleTask.task();
        }
    }
}

void TaskLooper::runAll() {
    mImpl->mInRunAll = true;

    while (!mImpl->mExiting) {
        runOnce(mImpl->mTimeoutMs);
    }

    mImpl->mExiting = false;

    mImpl->mInRunAll = false;
    mImpl->mRunAllCondition.broadcast();
}

void TaskLooper::exit(bool waitRunAll) {
    postTask([this]() { mImpl->mExiting = true; }, Pri_High);

    if (waitRunAll && mImpl->mInRunAll) {
        AutoLock autolock(mImpl->mRunAllMutex);
        if (mImpl->mInRunAll) {
            mImpl->mRunAllCondition.wait(mImpl->mRunAllMutex);
        }
    }
}

void TaskLooper::setThreadId(ThreadId threadId) {
    mImpl->mThreadId = threadId;

    AutoLock autolock(Impl::sGlobalMutex);
    Impl::sLoopers[threadId] = this;
}

ThreadId TaskLooper::threadId() const {
    return mImpl->mThreadId;
}

TaskLooper *TaskLooper::getLooperFromThreadId(ThreadId threadId) {
    AutoLock autolock(Impl::sGlobalMutex);
    auto it = Impl::sLoopers.find(threadId);

    return it == Impl::sLoopers.end() ? nullptr : it->second;
}

TaskLooper *TaskLooper::curLooper() {
    return getLooperFromThreadId(Thread::currentId());
}
} // namespace hht
