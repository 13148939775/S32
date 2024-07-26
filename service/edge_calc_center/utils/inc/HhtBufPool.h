#ifndef HHTBUFPOOL_H
#define HHTBUFPOOL_H

#include <stdio.h>
#include <stdint.h>

#include <set>

#include "HhtMutex.h"

namespace hht {
class BufPool {
public:
    BufPool(size_t bufSize, size_t bufCount, bool threadSafe=true);
    ~BufPool();

    size_t size() const;
    size_t count() const;
    size_t freeCount() const;

    uint8_t* mallocBuf();
    bool releaseBuf(uint8_t* buf);

private:
    uint8_t* mBufPool;
    const size_t mSize;
    const size_t mCount;
    Mutex* mMutex;
    std::set<size_t> mFreeIds;
};  // BufPool
}  //namespace hh
#endif	// HHTBUFPOOL_H
