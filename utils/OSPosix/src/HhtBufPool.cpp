#include "HhtBufPool.h"

namespace HHT {

BufPool::BufPool(size_t bufSize, size_t bufCount, bool threadSafe)
    : mBufPool(new uint8_t[bufSize * bufCount])
    , mSize(bufSize)
    , mCount(bufCount)
    , mMutex(threadSafe? new Mutex: nullptr)
    , mFreeIds() {
        for (size_t i = 0; i < mCount; ++i) {
            mFreeIds.insert(i);
        }
    }

BufPool::~BufPool() {
    if (mMutex) {
        delete mMutex;
    }

    delete[] mBufPool;
}

size_t BufPool::size() const {
    return mSize;
}

size_t BufPool::count() const {
    return mCount;
}

size_t BufPool::freeCount() const {
    TryAutoLock tryautolock(mMutex);
    return mFreeIds.size();
}

uint8_t* BufPool::mallocBuf() {
    TryAutoLock tryautolock(mMutex);
    if (0 == mFreeIds.size()) {
        fprintf(stderr, "malloc buf failed!\n");
        return nullptr;
    }

    auto it = mFreeIds.begin();;
    size_t id = *it;
    mFreeIds.erase(it);
    return mBufPool + (mSize * id);
}

bool BufPool::releaseBuf(uint8_t* buf) {
    TryAutoLock tryautolock(mMutex);
    if (buf < mBufPool || buf >= (mBufPool + (mSize * mCount))) {
        // not in buffer pool
        fprintf(stderr, "release buf:0x%p failed: buf ptr is not in buffer pool\n", buf);
        return false;
    }

    if ((buf - mBufPool) % mSize) {
        // not buf head addr
        fprintf(stderr, "release buf:0x%p failed: buf ptr is not head addr\n", buf);
        return false;
    }

    size_t id = (buf - mBufPool) / mSize;
    if (0 != mFreeIds.count(id)) {
        // has released
        fprintf(stderr, "release buf:0x%p failed: buf ptr has released\n", buf);
        return false;
    }

    mFreeIds.insert(id);
    return true;
}

}  //namespace hh
