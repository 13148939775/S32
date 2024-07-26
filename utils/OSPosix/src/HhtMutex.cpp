#include "HhtMutex.h"

namespace HHT {

Mutex::Mutex(bool recursive) {
    if (recursive) {
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&mMutex, &attr);
    } else {
        pthread_mutex_init(&mMutex, NULL);
    }
}

Mutex::~Mutex() {
    pthread_mutex_destroy(&mMutex);
}

void Mutex::lock() {
    pthread_mutex_lock(&mMutex);
}

void Mutex::tryLock() {
    pthread_mutex_trylock(&mMutex);
}

void Mutex::unlock() {
    pthread_mutex_unlock(&mMutex);
}


Condition::Condition() {
    pthread_condattr_t attr;
    pthread_condattr_init(&attr);
    pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);
    pthread_cond_init(&mCond, &attr);
}

bool Condition::wait(Mutex& mutex) {
    int ret = pthread_cond_wait(&mCond, &(mutex.mMutex));
    return (ret == 0);
}

bool Condition::waitFor(Mutex& mutex, int32_t timeoutMs) {
    if (timeoutMs <= 0) {
        return false;
    }

    timespec tv;
    clock_gettime(CLOCK_MONOTONIC, &tv);

    tv.tv_sec += timeoutMs/1000;
    tv.tv_nsec += ((long)(timeoutMs%1000)) * 1000000;
    if (tv.tv_nsec >= 1000000000L) {
        tv.tv_sec += 1;
        tv.tv_nsec -= 1000000000L;
    }

    int ret = pthread_cond_timedwait(&mCond, &(mutex.mMutex), &tv);
    return (ret == 0);
}

void Condition::signal() {
    pthread_cond_signal(&mCond);
}

void Condition::broadcast() {
    pthread_cond_broadcast(&mCond);
}

}  // namespace hht
