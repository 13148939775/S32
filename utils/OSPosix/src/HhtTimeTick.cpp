#include "HhtTimeTick.h"

#include <time.h>

namespace HHT {

int64_t timeTickMs() {
    timespec time;

    clock_gettime(CLOCK_MONOTONIC, &time);
    return (int64_t)time.tv_sec * 1000 + time.tv_nsec/1000000;
}

int64_t timeStampNs() {
    timespec time;

    clock_gettime(CLOCK_MONOTONIC, &time);
    return (int64_t)time.tv_sec * 1000000000L + time.tv_nsec;
}

} //namespace hht
