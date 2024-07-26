#ifndef HHTBASICDEF_H
#define HHTBASICDEF_H

#include <memory>
#include <functional>
#include <sstream>

#include <stdint.h>
#include <pthread.h>

#define DISABLE_CLASS_COPY(ClassName) \
    ClassName(const ClassName& other) = delete; \
    ClassName& operator=(const ClassName& other) = delete;

#define HHT_EXT_OPERATORS(ClassName)                                            \
    bool operator> (const ClassName& o) const { return o < *this; }               \
    bool operator!=(const ClassName& o) const { return *this < o || *this > o; }  \
    bool operator==(const ClassName& o) const { return !(*this != o); }           \
    bool operator<=(const ClassName& o) const { return *this < o || *this == o; } \
    bool operator>=(const ClassName& o) const { return *this > o || *this == o; }

namespace hht {

// The value is larger, the priority is higher
enum Priority {
    Pri_High = 10,
    Pri_Low = -10,

    Pri_Default = 0
};

using Task = std::function<void()> Task;
typedef pthread_t ThreadId;

} // namespace hht

#define ARRAY_LEN(x) sizeof(x)/sizeof(x[0])

#endif //HHTBASICDEF_H
