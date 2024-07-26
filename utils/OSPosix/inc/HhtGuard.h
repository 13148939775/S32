#ifndef HHTGUARD_H
#define HHTGUARD_H

#include <memory>

#include "HhtMutex.h"

namespace HHT {

struct Guard {
    Guard() : Guard(true) {}
    Guard(bool isMaster)
        : mMaster(isMaster ? (new char) : nullptr)
        , mSlave()
        , mMutex(isMaster ? new Mutex(true) : nullptr) {}
    Guard(const Guard& other)
        : mMaster(nullptr)
        , mSlave(other.mMaster ? other.mMaster : other.mSlave)
        , mMutex(other.mMutex) {}
    Guard(Guard&& other)
        : mMaster(other.mMaster), mSlave(other.mSlave), mMutex(other.mMutex) {
        other.mMaster.reset();
        other.mSlave.reset();
        other.mMutex.reset();
    }

    Guard& operator=(const Guard& other) {
        mMaster.reset();
        mSlave = other.mMaster ? other.mMaster : other.mSlave;
        mMutex = other.mMutex;

        return *this;
    }

    Guard& operator=(Guard&& other) {
        mMaster = other.mMaster;
        mSlave = other.mSlave;
        mMutex = other.mMutex;

        other.mMaster.reset();
        other.mSlave.reset();
        other.mMutex.reset();

        return *this;
    }

    Guard& swap(Guard& other) {
        auto tmpMaster = mMaster;
        auto tmpSlave = mSlave;
        auto tmpMutex = mMutex;

        mMaster = other.mMaster;
        mSlave = other.mSlave;
        mMutex = other.mMutex;

        other.mMaster = tmpMaster;
        other.mSlave = tmpSlave;
        other.mMutex = tmpMutex;

        return *this;
    }

    operator bool() const { return mMaster || mSlave.lock(); }

    void lock() {
        if (mMutex) {
            mMutex->lock();
        }
    }

    void unlock() {
        if (mMutex) {
            mMutex->unlock();
        }
    }

    std::shared_ptr<Mutex> mutex() const { return mMutex; }

    std::shared_ptr<char> mMaster;
    std::weak_ptr<char> mSlave;
    std::shared_ptr<Mutex> mMutex;
};

struct GuardAutoLock {
    GuardAutoLock(const Guard& guard): mMutex(guard.mutex()) {
        if (mMutex) {
            mMutex->lock();
        }
    }

    ~GuardAutoLock() {
        if (mMutex) {
            mMutex->unlock();
        }
    }

    std::shared_ptr<Mutex> mMutex;
};

template <typename T>
class GuardPtr {
public:
    GuardPtr() : mObject(nullptr), mGuard(false) {}

    explicit GuardPtr(T* object)
        : mObject(object), mGuard(object ? object->guard() : Guard(false)) {}
    template <typename U>
    explicit GuardPtr(U* object)
        : mObject(object), mGuard(object ? object->guard() : Guard(false)) {}

    GuardPtr(const GuardPtr& other)
        : mObject(other.mObject), mGuard(other.mGuard) {}
    template <typename U>
    explicit GuardPtr(const GuardPtr<U>& other)
        : mObject(other.mObject), mGuard(other.mGuard) {}

    GuardPtr& operator=(const GuardPtr& other) {
        mObject = other.mObject;
        mGuard = other.mGuard;

        return *this;
    }
    template <typename U>
    GuardPtr& operator=(const GuardPtr<U>& other) {
        mObject = other.mObject;
        mGuard = other.mGuard;

        return *this;
    }

    void reset(T* object) {
        mObject = object;
        mGuard = object->guard();
    }
    template <typename U>
    void reset(U* object) {
        mObject = object;
        mGuard = object->guard();
    }

    T* get() const { return mObject; }
    T* operator->() const { return mObject; }

    typename std::add_lvalue_reference<T>::type operator*() const {
        return (*get());
    }

    bool operator<(const GuardPtr& other) const {
        return get() < other.get();
    }
    template <typename U>
    bool operator<(const GuardPtr<U>& other) const {
        return get() < other.get();
    }

    Guard guard() const { return mGuard; }
    operator bool() const { return mObject != nullptr && mGuard; }

private:
    T* mObject;
    Guard mGuard;
};
}
#endif  // HHTGUARD_H
