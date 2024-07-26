/*
 * @author 008196
 * @for meta ability define
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef META_ABILITY_H
#define META_ABILITY_H

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include "nlohmann/json.hpp"

#include "utils/dbc/data_block_center.h"

class MetaAbility : public DataBlockCenter::Observer {
public:
public:
    MetaAbility(const std::string& functionCode, std::string& value, const uint8_t& count, const uint8_t& compose);
    
    virtual void OnNotify(const DataBlockCenter& dbc);

    void Enable();
    
    void RegistryTime(int time, const std::function<void()>& cb = nullptr);
    
    const std::string& GetFunctionCode() const
    {
        return functionCode_;
    }

    const std::string& GetfunctionValue() const
    {
        return functionValue_;
    }

    const uint8_t& GetCycleCount() const
    {
        return cycleCount_;
    }

    static void ReadMeta2Topic(const nlohmann::json& data);

private:
    std::string topic_;
    std::string functionCode_;
    std::string functionValue_;
    uint8_t cycleCount_;
    uint8_t compose_;

    static std::unordered_map<std::string, std::string> function2Topic_;
};

#endif /* META_ABILITY_H */
