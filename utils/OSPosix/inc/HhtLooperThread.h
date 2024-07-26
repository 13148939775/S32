#ifndef HHTLOOPERTHREAD_H
#define HHTLOOPERTHREAD_H

#include "HhtThread.h"

namespace HHT {

class TaskLooper;
class LooperThread : public Thread{
public:
    LooperThread();
    ~LooperThread();

    void stop();
    TaskLooper& looper();

private:
    virtual void run() override;

private:
    TaskLooper* mLooper;
};
}
#endif // HHTLOOPERTHREAD_H
