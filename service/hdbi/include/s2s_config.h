/**
 * @file s2s_config.h
 * @brief 
 * @author T001294
 * @version 1.0
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023  HRYT
 * 
 */

#ifndef DOMAINNODE_H
#define DOMAINNODE_H

#include <cstdint>

enum REQ_SRV_NAME : uint8_t {
    BdArm_Srv = 1,
    VsWsh_Srv = 2,
    SSd_Srv = 3,
    Win_Srv = 4,
    BdPst_Srv = 5,
    StAdj_Srv = 6,
    DrLth_Srv = 7,
    Hdl_St_Get_Srv = 8,
    InLt_Srv = 9,
    AmLt_Srv = 10,
    BdSf_Ctrl_Srv = 11,
    CgC_Ctrl_Srv = 12,
    VehicleMode_Srv = 13,
    AC_Ctrl_Srv = 14,
    CHS_Ctrl_Srv = 15,
    ExtLt_Ctrl_Srv = 16,
    BdCft_Srv = 17,
    Bot_Srv = 18,
    BotScript_Srv = 19,
    Key_Srv = 20
};







#endif //DOMAINNODE_H