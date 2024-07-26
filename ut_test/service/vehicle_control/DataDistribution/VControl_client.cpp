/*
 * @author 008196
 * @for application log interface
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <fstream>
#include <string>

#include "McuImplementation.h"
#include "McuInterface.h"
#include "McuControl.hpp"

TEST(VehicleControl, mytest)
{
     std::vector<int> data;
    data.push_back(1);
    // 实例化MCUInterface具体实现类
    std::unique_ptr<MCUInterface> mcuInterface(new MCUImplementation());
    MCUController::GetInstance().SetMCUInterface(std::move(mcuInterface)); // 设置MCUInterface对象
    bool result  = MCUController::GetInstance().SendDataToMCU(data); // 使用单例MCUController发送数据给MCU
    
    EXPECT_EQ(result, true);
}

