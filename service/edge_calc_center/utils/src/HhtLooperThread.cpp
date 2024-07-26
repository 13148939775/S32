#include "HhtLooperThread.h"
#include "HhtTaskLooper.h"

namespace hht{

LooperThread::LooperThread()
    : mLooper(new TaskLooper){
}

LooperThread::~LooperThread() {


    delete mLooper;
    mLooper = nullptr;
}

void LooperThread::stop() {
    mLooper->exit();
}

TaskLooper& LooperThread::looper() {
    return *mLooper;
}

void LooperThread::run() {
    mLooper->setThreadId(currentId());
    mLooper->runAll();
}
}
