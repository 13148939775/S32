/*
 * @author 008196
 * @for application start and exit manager
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef APP_MANAGER_CONFIG_H
#define APP_MANAGER_CONFIG_H

#include <unordered_map>
#include <string>

namespace HHT {
class AppManagerConfig {
public:
    static AppManagerConfig GetInstance()
    {
        static AppManagerConfig am;
        return am;
    }
    static std::string& GetCfg(int val) 
    {
        return cfg_[val];
    }
private:
    static std::unordered_map<int, std::string> cfg_;
};
}

#endif /* APP_CONFIG_H */
