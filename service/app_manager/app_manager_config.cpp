/*
 * @author 008196
 * @for application start and exit manager
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "app_manager_config.h"

namespace HHT {
std::unordered_map<int, std::string> AppManagerConfig::cfg_ = {
        {0, "app_config_normal.json"},
        {1, "app_config_ota.json"},
        {99, "test.json"}
};
}