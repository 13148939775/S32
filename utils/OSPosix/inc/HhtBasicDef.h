#ifndef HHTBASICDEF_H
#define HHTBASICDEF_H

#include <stdint.h>
#include <pthread.h>

#include <memory>
#include <functional>
#include <sstream>

#define DISABLE_CLASS_COPY(ClassName) \
    ClassName(const ClassName& other) = delete; \
    ClassName& operator=(const ClassName& other) = delete;

#define HHT_EXT_OPERATORS(ClassName)                                            \
    bool operator> (const ClassName& o) const { return o < *this; }               \
    bool operator!=(const ClassName& o) const { return *this < o || *this > o; }  \
    bool operator==(const ClassName& o) const { return !(*this != o); }           \
    bool operator<=(const ClassName& o) const { return *this < o || *this == o; } \
    bool operator>=(const ClassName& o) const { return *this > o || *this == o; }

namespace HHT {

// The value is larger, the priority is higher
enum Priority {
    Pri_High = 10,
    Pri_Low = -10,

    Pri_Default = 0
};

using Task = std::function<void()>;
using ThreadId = pthread_t;

} // namespace hht

#define ARRAY_LEN(x) sizeof(x)/sizeof(x[0])

#endif //HHTBASICDEF_H
