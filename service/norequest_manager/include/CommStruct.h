/*** 
 * @Author: T001291
 * @Date: 2023-11-15 13:29:30
 * @Mailbox: zuren_yuan@human-horizons.com
 * @LastEditors: T001291
 * @Description: 
 * @FilePath: /s32-Apps/service/norequest_manager/include/CommStruct.h
 */

#ifndef COMM_STRUCT_H
#define COMM_STRUCT_H

#include <iostream>

typedef struct BdArm_Set //5
{
    uint8_t VehicleUnlock_Set;
    uint8_t ReturnPUnlock_Set; 
}BdArm_Set_struct;

typedef struct BdArm_Act //6
{
    uint8_t CenterLck_Act;
}BdArm_Act_struct;

typedef struct VsWsh_Set //
{
    uint8_t FwiperSW_Set;
    uint8_t FwiperAutoSenst_Set;
}VsWsh_Set_struct;

typedef struct VsWsh_Act //
{
    uint8_t FWiperSvcSW_Req;
    uint8_t ExMirHt_Req;
}VsWsh_Act_struct;

typedef struct Win_Set //
{
    uint8_t LckCloseWin_Set;
    uint8_t RainCloseWin_Set;
}Win_Set_struct;

typedef struct WinPct_Act //
{
    uint8_t FLWinPst_Act;
    uint8_t FRWinPst_Act;
    uint8_t RLWinPst_Act;
    uint8_t RRWinPst_Act;
}WinPct_Act_struct;

typedef struct BdPst_Set //
{
    uint8_t ExMirAutoTurnOver_Set;
    uint8_t ExMirFoldEn_Set;
    uint8_t ExMirUnfoldAlt_Set;
}BdPst_Set_struct;

typedef struct StAdj_Act //
{
    uint8_t FLSeatFBAdj_Act;
    uint8_t FLSeatBackrestAdj_Act;
    uint8_t FLSeatHgtAdj_Act;
    uint8_t FLSeatCshnAngAdj_Act;
    uint8_t FLLegAngCshnExtAdj_Act;
    uint8_t FRSeatFBAdj_Act;
    uint8_t FRSeatBackrestAdj_Act;
    uint8_t FRSeatHgtAdj_Act;
    uint8_t FRSeatCshnAngAdj_Act;
    uint8_t FRLegAngCshnExtAdj_Act;
}StAdj_Act_struct;

typedef struct BdPst_Act //
{
    uint8_t ExMirCtrl_Act;
    uint8_t LExMirUDAdj_Act;
    uint8_t LExMirLRAdj_Act;
    uint8_t RExMirUDAdj_Act;
    uint8_t RExMirLRAdj_Act;
    uint8_t SteerTiltAdj_Act;
    uint8_t SteerTeleAdj_Act;
}BdPst_Act_struct;

typedef struct SSd_Set //
{
    uint8_t LockVoiWarn_Req;
    uint8_t LowSpdVoi_Set;
}SSd_Set_struct;

typedef struct DrLth_Set //
{
    uint8_t TDrOpenAngSet_Act;
}DrLth_Set_struct;

typedef struct DrLth_Act//
{
    uint8_t TDoorBtn_Act;
    uint8_t TDoorPos_Act;
    uint8_t FLDoorBtn_Act;
    uint8_t RLDoorBtn_Act;
    uint8_t FRDoorBtn_Act;
    uint8_t RRDoorBtn_Act;
}DrLth_Act_struct;

typedef struct InLt_Set//
{
    uint8_t TpLtAutoSet_Req;
    uint8_t TpLtClrSet_Req;
    uint8_t TpLtBrtSet_Req;
    uint8_t BckLtBrtSet_Req;
}InLt_Set_struct;

typedef struct InLt_Act//
{
    uint8_t TpLtBtn_Act;
    uint8_t TpLtSearch_Act;
    uint8_t FLTpLtRead_Act;
    uint8_t RLTpLtRead_Act;
    uint8_t FRTpLtRead_Act;
    uint8_t RRTpLtRead_Act;
}InLt_Act_struct;


typedef struct AmLt_Set//
{
    uint8_t AmLtBtn_Set;
    uint8_t AmLtBrt_Set;
    uint8_t AmLtMode_Set;
    uint8_t AmLtCustomClr_Set;
    uint8_t AmLtAutoBrt_Set;
    uint8_t AmLtBrtFollow_Set;
    uint8_t AmLtVoice_Set;
    uint8_t AmLtWelcome_Set;
    uint8_t AmLtMusic_Set;
    uint8_t AmLtTemp_Set;
    uint8_t AmLtMedRedVal_Set;
    uint8_t AmLtMedGreenVal_Set;
    uint8_t AmLtMedBlueVal_Set;
}AmLt_Set_struct;

typedef struct BdSf_Act//
{
    uint8_t LChdlock_Req;
    uint8_t RChdlock_Req;
    uint8_t ChdLockMode_Req;
}BdSf_Act_struct;

typedef struct CgC_Act//
{
    uint8_t ChrgCapCtrlSW_Req;
}CgC_Act_struct;

typedef struct PowerModeReq//
{
    uint8_t PowerMode_Req;
}PowerModeReq_Struct;

typedef struct DrivingModeReq//
{
    uint8_t EPSModeChange_Req;
    uint8_t TargVehicleMode_Req;
    uint8_t PTModeChange_Req;
    uint8_t LowConsumMode_Req;
    uint8_t ValetMode_Req;
    uint8_t OnePedalMode_Req;
    uint8_t CoastRegenStrg_Req;
}DrivingModeReq_Struct;

typedef struct AC_Ctrl//
{
    uint8_t ACCycleMode_Req;
    uint8_t FACAirFlowLevel_Req;
    uint8_t FACMode_Req;
    uint8_t FACSwitch_Req;
    uint8_t FrontDeFrostFog_Req;
    uint8_t FLeftTempSet_Req;
    uint8_t FRightTempSet_Req;
    uint8_t FTempAreaSynd_Req;
    uint8_t FCoolOrHeatOrVent_Req;
    uint8_t ACOperationMode_Cmd;
    uint8_t FAutoAC_Req;
}AC_Ctrl_struct;

typedef struct CHSSetting//
{
    uint8_t HDCSw_Req;
    uint8_t EHBMBrkModeSet_Req;
    uint8_t CSTSw_Req;
    uint8_t TCSSw_Req;
    uint8_t AVHSw_Req;
    uint8_t ESCSw_Req;
    uint8_t ParkingSwitch_Req;
}CHSSetting_Struct;

typedef struct ExtLt_Ctrl//
{
    uint8_t TurnLight_Req;
    uint8_t EtnlLgt_Req;
    uint8_t HighBeam_Req;
    uint8_t HDBI_RearFogBm_Req;
}ExtLt_Ctrl_Struct;

typedef struct BdCft_Act//
{
    uint8_t FLLumbSuppUDAdj_Act;
    uint8_t FLLumbSuppFBAdj_Act;
    uint8_t FRLumbSuppUDAdj_Act;
    uint8_t FRLumbSuppFBAdj_Act;
}BdCft_Act_struct;

#endif