/*
 * @author 008555
 * @for application vechicleControl to MCU
 * @version 0.1
 * @date 2023-04 ~ 2023-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MCUINTERFACE_H
#define MCUINTERFACE_H

#include <vector>

class MCUInterface {
public:
    virtual ~MCUInterface() {}
    virtual int SendToMCU(const std::vector<int>& data) = 0;
};

#endif