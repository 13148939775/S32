/*
 * @author 008555
 * @for application vechicleControl to MCU
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MCUIMPLEMENTATION_H
#define MCUIMPLEMENTATION_H

#include <iostream>
#include "McuInterface.h"

class MCUImplementation : public MCUInterface {
public:
    int SendToMCU(const std::vector<int>& data) override 
    {
        // 在这里实现向MCU发送数据的具体操作
        // 可以使用串口、网络等方式将数据发送给MCU
        // ...
        std::cout << __FILE__<<__LINE__<<std::endl;
        return true;
    }
};

#endif
