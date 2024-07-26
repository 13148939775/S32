#ifndef HHTMUTEX_EXT_H
#define HHTMUTEX_EXT_H

#include <pthread.h>
#include <stdint.h>

namespace HHT {

class Mutex {
public:

    Mutex(bool recursive=false);
    ~Mutex();

    void lock();
    void tryLock();

    void unlock();

private:
    friend class Condition;

    pthread_mutex_t mMutex;
};

class Condition {
public:
    Condition();

    bool wait(Mutex& mutex);
    bool waitFor(Mutex& mutex, int32_t timeoutMs);

    void signal();
    void broadcast();
private:
    pthread_cond_t mCond;
};

class AutoLock {
public:
    AutoLock(Mutex& mutex): mMutex(mutex) {
        mMutex.lock();
    }
    ~AutoLock() {
        mMutex.unlock();
    }

private:
    Mutex& mMutex;
};

class TryAutoLock {
public:
    TryAutoLock(Mutex* mutex): mMutex(mutex) {
        if (mMutex) {
            mMutex->lock();
        }
    }
    ~TryAutoLock() {
        if (mMutex) {
            mMutex->unlock();
        }
    }

private:
    Mutex* mMutex;
};

} // namespace HHT

#endif // HHTMUTEX_EXT_H
