/*** 
 * @Author: T001291
 * @Date: 2023-11-15 15:53:07
 * @Mailbox: zuren_yuan@human-horizons.com
 * @LastEditors: T001291
 * @Description: 
 * @FilePath: /s32-Apps/service/norequest_manager/include/GenerateNoReq.h
 */

#ifndef GENERATE_NO_REQ_H
#define GENERATE_NO_REQ_H

#include "CommStruct.h"
#include <iostream>
#include <unordered_map>
#include <map>

class GenerateNoReq {
public:
    struct pairHash{
    public:
        template <typename T, typename U>
        size_t operator() (const std::pair<T, U>&x) const {
            return std::hash<T>()(x.first)^std::hash<U>()(x.second);
        }
    };

    static BdArm_Set_struct BdArm_Set;//5
    static BdArm_Act_struct BdArm_Act;//6
    static VsWsh_Set_struct VsWsh_Set;//
    static VsWsh_Act_struct VsWsh_Act;
    static Win_Set_struct Win_Set;
    static WinPct_Act_struct WinPct_Act;
    static BdPst_Set_struct BdPst_Set;
    static StAdj_Act_struct StAdj_Act;
    static BdPst_Act_struct BdPst_Act;
    static SSd_Set_struct SSd_Set;
    static DrLth_Set_struct DrLth_Set;
    static DrLth_Act_struct DrLth_Act;
    static InLt_Set_struct InLt_Set;
    static InLt_Act_struct InLt_Act;
    static AmLt_Set_struct AmLt_Set;
    static BdSf_Act_struct BdSf_Act;
    static CgC_Act_struct CgC_Act;
    static PowerModeReq_Struct PowerModeReq;
    static DrivingModeReq_Struct DrivingModeReq;
    static AC_Ctrl_struct AC_Ctrl;
    static CHSSetting_Struct CHSSetting;
    static ExtLt_Ctrl_Struct ExtLt_Ctrl;
    static BdCft_Act_struct BdCft_Act;

    std::unordered_map<std::pair<uint8_t,uint8_t>, void*,pairHash> noReqSignalMap = {
        {std::make_pair(5, 0),  (void*)&BdArm_Set.ReturnPUnlock_Set},
        {std::make_pair(5, 1), (void*)&BdArm_Set.VehicleUnlock_Set},
        {std::make_pair(6, 0),  (void*)&BdArm_Act.CenterLck_Act},
        {std::make_pair(48, 0), (void*)&VsWsh_Set.FwiperSW_Set},
        {std::make_pair(48, 1), (void*)&VsWsh_Set.FwiperAutoSenst_Set},
        {std::make_pair(9, 0), (void*)&VsWsh_Act.FWiperSvcSW_Req},
        {std::make_pair(9, 1), (void*)&VsWsh_Act.ExMirHt_Req},
        {std::make_pair(11, 0), (void*)&Win_Set.LckCloseWin_Set},
        {std::make_pair(11, 1), (void*)&Win_Set.RainCloseWin_Set},
        {std::make_pair(12, 0), (void*)&WinPct_Act.FLWinPst_Act},
        {std::make_pair(12, 1), (void*)&WinPct_Act.FRWinPst_Act},
        {std::make_pair(12, 2), (void*)&WinPct_Act.RLWinPst_Act},
        {std::make_pair(12, 3), (void*)&WinPct_Act.RRWinPst_Act},
        {std::make_pair(19, 0), (void*)&BdPst_Set.ExMirAutoTurnOver_Set},
        {std::make_pair(19, 1), (void*)&BdPst_Set.ExMirFoldEn_Set},
        {std::make_pair(19, 2), (void*)&BdPst_Set.ExMirUnfoldAlt_Set},
        {std::make_pair(21, 0), (void*)&BdPst_Act.ExMirCtrl_Act},
        {std::make_pair(21, 1), (void*)&BdPst_Act.LExMirUDAdj_Act},
        {std::make_pair(21, 2), (void*)&BdPst_Act.RExMirLRAdj_Act},
        {std::make_pair(21, 3), (void*)&BdPst_Act.RExMirUDAdj_Act},
        {std::make_pair(21, 4), (void*)&BdPst_Act.RExMirLRAdj_Act},
        {std::make_pair(21, 5), (void*)&BdPst_Act.SteerTiltAdj_Act},
        {std::make_pair(21, 6), (void*)&BdPst_Act.SteerTeleAdj_Act},
        {std::make_pair(23, 0), (void*)&StAdj_Act.FLSeatFBAdj_Act},
        {std::make_pair(23, 1), (void*)&StAdj_Act.FLSeatBackrestAdj_Act},
        {std::make_pair(23, 2), (void*)&StAdj_Act.FLSeatHgtAdj_Act},
        {std::make_pair(23, 3), (void*)&StAdj_Act.FLSeatCshnAngAdj_Act},
        {std::make_pair(23, 4), (void*)&StAdj_Act.FLLegAngCshnExtAdj_Act},
        {std::make_pair(23, 5), (void*)&StAdj_Act.FRSeatFBAdj_Act},
        {std::make_pair(23, 6), (void*)&StAdj_Act.FRSeatBackrestAdj_Act},
        {std::make_pair(23, 7), (void*)&StAdj_Act.FRSeatHgtAdj_Act},
        {std::make_pair(23, 8), (void*)&StAdj_Act.FRSeatCshnAngAdj_Act},
        {std::make_pair(23, 9), (void*)&StAdj_Act.FRLegAngCshnExtAdj_Act},
        {std::make_pair(15,0), (void*)&SSd_Set.LockVoiWarn_Req},
        {std::make_pair(15,1), (void*)&SSd_Set.LowSpdVoi_Set},
        {std::make_pair(1,0), (void*)&DrLth_Set.TDrOpenAngSet_Act},
        {std::make_pair(2,0), (void*)&DrLth_Act.TDoorBtn_Act},
        {std::make_pair(2,1), (void*)&DrLth_Act.TDoorPos_Act},
        {std::make_pair(2,2), (void*)&DrLth_Act.FLDoorBtn_Act},
        {std::make_pair(2,3), (void*)&DrLth_Act.RLDoorBtn_Act},
        {std::make_pair(2,4), (void*)&DrLth_Act.FRDoorBtn_Act},
        {std::make_pair(2,5), (void*)&DrLth_Act.RRDoorBtn_Act},
        {std::make_pair(25,0), (void*)&InLt_Set.TpLtAutoSet_Req},
        {std::make_pair(25,1), (void*)&InLt_Set.TpLtClrSet_Req},
        {std::make_pair(25,2), (void*)&InLt_Set.TpLtBrtSet_Req},
        {std::make_pair(25,3), (void*)&InLt_Set.BckLtBrtSet_Req},
        {std::make_pair(27,0), (void*)&InLt_Act.TpLtBtn_Act},
        {std::make_pair(27,1), (void*)&InLt_Act.TpLtSearch_Act},
        {std::make_pair(27,2), (void*)&InLt_Act.FLTpLtRead_Act},
        {std::make_pair(27,3), (void*)&InLt_Act.RLTpLtRead_Act},
        {std::make_pair(27,4), (void*)&InLt_Act.FRTpLtRead_Act},
        {std::make_pair(27,5), (void*)&InLt_Act.RRTpLtRead_Act},
        {std::make_pair(50,0), (void*)&AmLt_Set.AmLtBtn_Set},
        {std::make_pair(50,1), (void*)&AmLt_Set.AmLtBrt_Set},
        {std::make_pair(50,2), (void*)&AmLt_Set.AmLtMode_Set},
        {std::make_pair(50,3), (void*)&AmLt_Set.AmLtAutoBrt_Set},
        {std::make_pair(50,4), (void*)&AmLt_Set.AmLtBrtFollow_Set},
        {std::make_pair(50,5), (void*)&AmLt_Set.AmLtVoice_Set},
        {std::make_pair(50,6), (void*)&AmLt_Set.AmLtWelcome_Set},
        {std::make_pair(50,7), (void*)&AmLt_Set.AmLtMusic_Set},
        {std::make_pair(50,8), (void*)&AmLt_Set.AmLtCustomClr_Set},
        {std::make_pair(50,10), (void*)&AmLt_Set.AmLtMedRedVal_Set},
        {std::make_pair(50,12), (void*)&AmLt_Set.AmLtMedGreenVal_Set},
        {std::make_pair(50,14), (void*)&AmLt_Set.AmLtMedBlueVal_Set},
        {std::make_pair(50,16), (void*)&AmLt_Set.AmLtTemp_Set},
        {std::make_pair(17,0), (void*)&BdSf_Act.LChdlock_Req},
        {std::make_pair(17,1), (void*)&BdSf_Act.RChdlock_Req},
        {std::make_pair(17,2), (void*)&BdSf_Act.ChdLockMode_Req},
        {std::make_pair(38,0), (void*)&CgC_Act.ChrgCapCtrlSW_Req},
        {std::make_pair(29,0), (void*)&PowerModeReq.PowerMode_Req},
        {std::make_pair(34,1), (void*)&DrivingModeReq.TargVehicleMode_Req},
        {std::make_pair(34,3), (void*)&DrivingModeReq.LowConsumMode_Req},
        {std::make_pair(34,4), (void*)&DrivingModeReq.ValetMode_Req},
        {std::make_pair(34,5), (void*)&DrivingModeReq.OnePedalMode_Req},
        {std::make_pair(34,6), (void*)&DrivingModeReq.CoastRegenStrg_Req},
        {std::make_pair(32,0), (void*)&AC_Ctrl.ACCycleMode_Req},
        {std::make_pair(32,1), (void*)&AC_Ctrl.FACAirFlowLevel_Req},
        {std::make_pair(32,2), (void*)&AC_Ctrl.FACMode_Req},
        {std::make_pair(32,3), (void*)&AC_Ctrl.FACSwitch_Req},
        {std::make_pair(32,4), (void*)&AC_Ctrl.FrontDeFrostFog_Req},
        {std::make_pair(32,5), (void*)&AC_Ctrl.FLeftTempSet_Req},
        {std::make_pair(32,6), (void*)&AC_Ctrl.FRightTempSet_Req},
        {std::make_pair(32,7), (void*)&AC_Ctrl.FTempAreaSynd_Req},
        {std::make_pair(32,8), (void*)&AC_Ctrl.FCoolOrHeatOrVent_Req},
        {std::make_pair(32,9), (void*)&AC_Ctrl.ACOperationMode_Cmd},
        {std::make_pair(32,10), (void*)&AC_Ctrl.FAutoAC_Req},
        {std::make_pair(41,0), (void*)&CHSSetting.HDCSw_Req},
        {std::make_pair(41,2), (void*)&CHSSetting.CSTSw_Req},
        {std::make_pair(41,3), (void*)&CHSSetting.TCSSw_Req},
        {std::make_pair(41,4), (void*)&CHSSetting.AVHSw_Req},
        {std::make_pair(41,5), (void*)&CHSSetting.ESCSw_Req},
        {std::make_pair(41,6), (void*)&CHSSetting.ParkingSwitch_Req},
        {std::make_pair(45,1), (void*)&ExtLt_Ctrl.EtnlLgt_Req},
        {std::make_pair(45,3), (void*)&ExtLt_Ctrl.HDBI_RearFogBm_Req},
        {std::make_pair(52,0), (void*)&BdCft_Act.FLLumbSuppUDAdj_Act},
        {std::make_pair(52,1), (void*)&BdCft_Act.FLLumbSuppFBAdj_Act},
        {std::make_pair(52,2), (void*)&BdCft_Act.FRLumbSuppUDAdj_Act},
        {std::make_pair(52,3), (void*)&BdCft_Act.FRLumbSuppFBAdj_Act}
        //{47, (void*)&WiperWash_Ctrl},
        };
         bool GenerateNoReqComm(const unsigned char* buf);
};

#endif