#include "HhtThread.h"
#include "HhtMutex.h"

namespace HHT {
struct Thread::Impl {
    ThreadId mId;
    std::string mName;
    int mPriority;
    Mutex mMutext;

    Impl(std::string name, int priority)
        : mId(0), mName(name), mPriority(priority) {}
};

Thread::Thread(const std::string& name, int priority) : mImpl(new Impl(name, priority)) {}
Thread::~Thread() { delete mImpl; }

void Thread::start() {
    AutoLock autolock(mImpl->mMutext);
    if (mImpl->mId) {
        // Thread has been already started
        return;
    }

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    if (mImpl->mPriority != INVALID_PRIORITY) {
        int spolicy;
        pthread_attr_getschedpolicy(&attr, &spolicy);

        int prioMin = sched_get_priority_min(spolicy);
        int prioMax = sched_get_priority_max(spolicy);

        if (mImpl->mPriority < prioMin) {
            mImpl->mPriority = prioMin;
        } else if (mImpl->mPriority > prioMax) {
            mImpl->mPriority = prioMax;
        }

        sched_param param;
        pthread_attr_getschedparam(&attr, &param);
        param.sched_priority = mImpl->mPriority;

        pthread_attr_setschedparam(&attr, &param);
    }

    pthread_create(&mImpl->mId, &attr, Thread::runWrap, this);
}

bool Thread::join() {
    if (!mImpl->mId) {
        return false;
    }

    int ret = pthread_join(mImpl->mId, NULL);
    return 0 == ret;
}

bool Thread::isRunning() const {
    return mImpl->mId;
}

void* Thread::runWrap(void* param) {

    Thread* thiz = (Thread*)param;
    if (!thiz) {
        return NULL;
    }

    if (thiz->mImpl->mName.size() != 0) {
        pthread_setname_np(thiz->mImpl->mId, thiz->mImpl->mName.c_str());
    }

    thiz->run();
    thiz->mImpl->mId = 0;
    return NULL;
}

ThreadId Thread::id() const {
    return mImpl->mId;
}

ThreadId Thread::currentId() {
    return pthread_self();
}

} // namespace hht
