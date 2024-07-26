/*
 * @author 008196
 * @for application start and exit manager
 * @version 0.1
 * @date 2023-07 ~ 2023-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CAN_MATRIX_H
#define CAN_MATRIX_H

#include <unordered_map>

struct HDBM_MCAN1_RT_3 {  // 56bits
    msgID = 0x130;  // extra add
    uint8_t checkSum5;
    RollingCounter5; // 8~11
    MCNA1_RT_3_EHBMAvailable;  // 12 ~ 13
    MCAN1_RT_3_ZCUFAvailable; // 14~15
    VehSpdValid_st; // 29
    ActlGeat_st  // 49 ~ 51
    ActlGrarValid_st // 52
    SHIFT_ERR; //53 ~ 55
};

strcut MCAN2_RT_2 {
    msgID = 0x2B5;
    hsdpoweroff1_req; // 0 ~ 23
    ZCUR_HSBPoweroff1_req; // 24 ~ 47 
    mcan1_rt_2_zcufavailable_st // 48 ~ 49
    mcan1_rt_2_zcuravailable_st // 50 ~ 51
};

std::unordered_map<uint8_t, func> map = {
    {0x130, GetStructA(), GetLen()},
    {0x2B5, GetStructB()}
};

#endif /* CAN_MATRIX_H */
