/*
 * @author 007313 008196
 * @for Can Data written into compressed file before upload
 * @incase of discotinue network
 * @version 0.1
 * @date 2023-05
 * 
 * @Copyrigh (c) HIPHI Co., LTD 2023 8/23
 * 
 */

#include "buf_pool.h"

#include <cstring>

namespace HHT {

BufPool::BufPool(size_t bufSize, size_t bufCount, bool threadSafe)
    : bufPoolHeader_(new uint8_t[bufSize * bufCount]),  // use the c++ stl memory alloc
      metaBufSize_(bufSize),
      cnt_(bufCount),
      mtx_(threadSafe? new Mutex : nullptr)
{   
    for (size_t i = 0; i < cnt_; ++i) {
        freeIDs_.insert(i);
    }
    // fill in some data
    std::memset(bufPoolHeader_, 0x8787, bufSize * bufCount);
}

BufPool::~BufPool() {
    if (mtx_) {
        delete mtx_;
    }

    delete[] bufPoolHeader_;
}

size_t BufPool::MetaSize() const {
    return metaBufSize_;
}

size_t BufPool::Count() const {
    return cnt_;
}

size_t BufPool::FreeCount() const 
{
    TryAutoLock tryautolock(mtx_);
    return freeIDs_.size();
}

uint8_t* BufPool::MallocMetaBuf() 
{
    TryAutoLock tryautolock(mtx_);
    if (0 == freeIDs_.size()) {
        fprintf(stderr, "malloc buf failed!\n");
        return nullptr;
    }

    auto it = freeIDs_.begin();
    size_t index = *it;
    freeIDs_.erase(it);
    return bufPoolHeader_ + (metaBufSize_ * index);
}

bool BufPool::ReleaseMetaBuf(uint8_t* buf) 
{
    TryAutoLock tryautolock(mtx_);
    if (buf < bufPoolHeader_ || buf >= (bufPoolHeader_ + (metaBufSize_ * cnt_))) {
        // not in buffer pool
        fprintf(stderr, "release buf:0x%p failed: buf ptr is not in buffer pool\n", buf);
        return false;
    }

    if ((buf - bufPoolHeader_) % metaBufSize_) {
        // not buf head addr
        fprintf(stderr, "release buf:0x%p failed: buf ptr is not head addr\n", buf);
        return false;
    }

    size_t id = (buf - bufPoolHeader_) / metaBufSize_;
    if (0 != freeIDs_.count(id)) {
        // has released
        fprintf(stderr, "release buf:0x%p failed: buf ptr has released\n", buf);
        return false;
    }

    freeIDs_.insert(id);
    return true;
}

}  //namespace hh
