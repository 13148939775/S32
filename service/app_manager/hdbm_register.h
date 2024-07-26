/*
 * @author 008196
 * @for App Registry
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HDBM_REGISTER_H
#define HDBM_REGISTER_H

#include <vector>
#include <shared_mutex>
#include <mutex>
#include <algorithm>

namespace HHT {

template<class T>
class HDBMRegister {
public:
    static HDBMRegister& GetInstance()
    {
        static HDBMRegister hdb;
        return hdb;
    }

    void GetList(std::vector<T>& instances, bool isService = false)
    {
        std::unique_lock<std::shared_timed_mutex> lk(mtx_);
        if (isService) {
            instances = instancesService_;
            return;
        }
        instances = instances_;
    }

    void Register(T app, bool isService = false)
    {
        std::unique_lock<std::shared_timed_mutex> lk(mtx_);
        std::vector<T>& instancesCheck = (isService == false) ? instances_ : instancesService_;
        auto ret = std::find_if(instancesCheck.begin(), instancesCheck.end(), [&](T app2) {
            return app == app2;
        });

        if (ret != instancesCheck.end()) {
            return;
        }
        instancesCheck.push_back(app);
    }

    void UnRegister(T app, bool isService = false)
    {
        std::unique_lock<std::shared_timed_mutex> lk(mtx_);
        std::vector<T>& instancesCheck = (isService == false) ? instances_ : instancesService_;

        auto ret = std::find_if(instancesCheck.begin(), instancesCheck.end(), [&](T app2) {
            return app == app2;
        });

        if (ret == instancesCheck.end()) {
            return;
        }
        instancesCheck.erase(ret);
    }

    bool IsValid(T app, bool isService = false)
    {
        std::unique_lock<std::shared_timed_mutex> lk(mtx_);
        std::vector<T>& instancesCheck = instances_;
        if (isService) {
            instancesCheck = instancesService_;
        }
        auto ret = std::find_if(instancesCheck.begin(), instancesCheck.end(), [&](T app2) {
            return app == app2;
        });
        return ret != instancesCheck.end();
    }
private:
    std::vector<T> instances_;
    std::vector<T> instancesService_;
    mutable std::shared_timed_mutex mtx_;
    static bool alive_;
};

template<class T>
bool HDBMRegister<T>::alive_ = true;
}
#endif
