/*** 
 * @Author: T001291
 * @Date: 2023-10-29 22:27:05
 * @Mailbox: zuren_yuan@human-horizons.com
 * @Version: 
 * @Description: 
 * @FilePath: /s32-Apps/service/norequest_manager/include/NoReqManager.h
 * @LastEditors: T001291
 */

#ifndef NO_REQ_MANAGER_H
#define NO_REQ_MANAGER_H

#include <map>
#include <mutex>
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "nlohmann/json.hpp"
    
/*定义时钟类型 Clock*/
typedef std::chrono::steady_clock Clock;
typedef std::chrono::time_point<Clock> TimePoint;

class NoReqManager {
public:
    NoReqManager() {}
    NoReqManager(std::string filename);
    bool Init(std::string filename);
    bool SetData(std::string filename);
    bool SetValueMap(nlohmann::json& data);
    bool IsSendNoReq(const unsigned char* buf,int len,std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>>& valueMap);
    
    nlohmann::json GetData() {
        return mData;
    }

   std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>> GetValueMap() {
        return mValueMap;
    }
    
private:
    std::unordered_map<uint8_t, std::unordered_map<uint8_t, std::tuple<int, int, std::string>>> mValueMap;
    nlohmann::json mData;
    std::string mFileName;
};

#endif