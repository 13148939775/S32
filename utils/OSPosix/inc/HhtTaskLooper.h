#ifndef HHTTASKLOOPER_H
#define HHTTASKLOOPER_H

#include "HhtBasicDef.h"

namespace HHT {

class TaskLooper {
public:
    enum { LOOPER_DEFAULT_TIMEOUT_MS = 50 };
public:
    TaskLooper(int32_t timeoutMs=LOOPER_DEFAULT_TIMEOUT_MS);
    ~TaskLooper();

    void postTask(Task task, int32_t priority = Pri_Default);
    void postDelayTask(Task task, int32_t timeoutMs, int32_t priority = Pri_Default);

    void setIdleTask(Task task, int32_t intervalMs);

    void runOnce(int32_t timeoutMs);
    void runAll();

    void exit(bool waitRunAll=false);

    void setThreadId(ThreadId threadId);
    ThreadId threadId() const;

    static TaskLooper* getLooperFromThreadId(ThreadId threadId);
    static TaskLooper* curLooper();
private:
    struct Impl;
    Impl* mImpl;
};
}




#endif //HHTTASKLOOPER_H
