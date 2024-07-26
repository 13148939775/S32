/*
 * @file app_manager.h
 * @author 008196
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef HDB_APP_INTERFACE_H
#define HDB_APP_INTERFACE_H

namespace HHT {
class HDBMAppIF {
public:
    virtual bool DoInit() = 0;
    virtual bool DoSuspend() = 0;  // to release the IO resource
    // virtual bool DoResume() = 0; 
    virtual void Run() = 0;
    virtual bool DoShutdown() = 0;  // to release its resource include IO
    void ReportEvent(int& st);
 
};
}

#endif /* APP_BASE_H */
