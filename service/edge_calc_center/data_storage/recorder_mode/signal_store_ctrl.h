/*
 * @file signal_store_ctrl.h
 * @author 008196
 * @for store vehicle signal to file
 * @version 0.1
 * @date 2023-02 ~ 2023-02
 * @copyright Copyright (c) 2023
 */

#ifndef SIGNAL_STORE_CTRL_H
#define SIGNAL_STORE_CTRL_H

#include <string>
#include <list>
#include <vector>
#include <map>

namespace HHT {
namespace DataManager {
class SignalStoreCtrl {
public:
    SignalStoreCtrl();
    ~SignalStoreCtrl();
public:
    void start(const std::string& sn);

    void storeData(const std::string& pkgName, const std::string& filepath, char* buffer,
                   const size_t len);

    void stop();

    void preventIoAccess(bool prevent);

private:
    class Impl;
    Impl* mImpl;

};  // SignalStoreCtrl
}  // namespace datamanager
}  // namespace hht
#endif	// SIGNAL_STORE_CTRL_H
