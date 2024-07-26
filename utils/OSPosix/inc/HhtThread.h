#ifndef HHTTHREAD_H
#define HHTTHREAD_H

#include "HhtBasicDef.h"

namespace HHT {

class Thread {
public:
    static constexpr int INVALID_PRIORITY = -1;

public:
    explicit Thread(const std::string& name="", int priority=INVALID_PRIORITY);

    virtual ~Thread();

    void start();

    bool join();
    bool isRunning() const;

    ThreadId id() const;
    static ThreadId currentId();

protected:
    virtual void run() = 0;

private:

    static void* runWrap(void* param);

private:
    DISABLE_CLASS_COPY(Thread)
    struct Impl;

    Impl* mImpl;
};
} // namespace hht
#endif // HHTTHREAD_H
