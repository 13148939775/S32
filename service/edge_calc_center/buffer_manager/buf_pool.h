/*
 * @author 007313 008196
 * @for Can Data written into compressed file before upload
 * @incase of discotinue network
 * @version 0.1
 * @date 2023-05
 * 
 * @Copyrigh (c) HIPHI Co., LTD 2023
 * 
 */

#ifndef HHTBUFPOOL_H
#define HHTBUFPOOL_H

#include <cstdio>
#include <cstdint>
#include <memory>
#include <list>
#include <set>
#include <mutex>

#include "HhtMutex.h"

namespace HHT {
class BufPool {
using Index = size_t;
public:
    BufPool(size_t metaBufSize, size_t bufCount, bool threadSafe = true);
    ~BufPool();

    size_t MetaSize() const;
    size_t Count() const;
    size_t FreeCount() const;

    uint8_t* MallocMetaBuf();
    bool ReleaseMetaBuf(uint8_t* buf);

private:
    uint8_t* bufPoolHeader_;
    const size_t metaBufSize_;
    const size_t cnt_;
    Mutex* mtx_;
    std::set<Index> freeIDs_;  // back in, front out
};  // BufPool
}  //namespace hh
#endif	// HHTBUFPOOL_H


