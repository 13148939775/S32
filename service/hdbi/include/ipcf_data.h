#ifndef IPCF_DATA_H
#define IPCF_DATA_H

typedef struct DrLth_Set {
    DrLth_Set(uint8_t TDrOpenAngSet) :
        TDrOpenAngSet_Act(TDrOpenAngSet) {
    }
    uint8_t TDrOpenAngSet_Act;
} strDrLth_Set;

typedef struct DrLth_Rsp {
    DrLth_Rsp(uint8_t TDrOpenAngSet) :
        TDrOpenAngSet_Rsp(TDrOpenAngSet) {
    }
    uint8_t TDrOpenAngSet_Rsp;
} strDrLth_Rsp;

typedef struct DrLth_Act {
    DrLth_Act(uint8_t TDoorBtn, uint8_t TDoorPos, uint8_t FLDoorBtn,
              uint8_t RLDoorBtn, uint8_t FRDoorBtn, uint8_t RRDoorBtn) :
        TDoorBtn_Act(TDoorBtn),
        TDoorPos_Act(TDoorPos),
        FLDoorBtn_Act(FLDoorBtn),
        RLDoorBtn_Act(RLDoorBtn),
        FRDoorBtn_Act(FRDoorBtn),
        RRDoorBtn_Act(RRDoorBtn) {
    }
    uint8_t TDoorBtn_Act;
    uint8_t TDoorPos_Act;
    uint8_t FLDoorBtn_Act;
    uint8_t RLDoorBtn_Act;
    uint8_t FRDoorBtn_Act;
    uint8_t RRDoorBtn_Act;

} strDrLth_Act;

typedef struct DrLth_St {
    DrLth_St(uint8_t FLDoor, uint8_t RLDoor, uint8_t FRDoor,
             uint8_t RRDoor, uint8_t TDoor, uint8_t FLNomDoor, uint8_t RLNomDoor, uint8_t FRNomDoor,
             uint8_t RRNomDoor, uint8_t TDoorNominal, uint8_t TDrWrk, uint8_t TDrTripPst, uint8_t FLDrStpRsn,
             uint8_t RLDrStpRsn, uint8_t FRDrStpRsn, uint8_t RRDrStpRsn, uint8_t TDrStpRsn, uint8_t FLDrAbuse,
             uint8_t RLDrAbuse, uint8_t FRDrAbuse, uint8_t RRDrAbuse, uint8_t TDrAbuse, uint8_t HoodLatch) :
        FLDoor_st(FLDoor),
        RLDoor_st(RLDoor), FRDoor_st(FRDoor), RRDoor_st(RRDoor), TDoor_st(TDoor),
        FLNomDoor_St(FLNomDoor), RLNomDoor_St(RLNomDoor), FRNomDoor_St(FRNomDoor), RRNomDoor_St(RRNomDoor),
        TDoorNominal_St(TDoorNominal), TDrWrk_St(TDrWrk), TDrTripPst_Val(TDrTripPst), FLDrStpRsn_st(FLDrStpRsn),
        RLDrStpRsn_st(RLDrStpRsn), FRDrStpRsn_st(FRDrStpRsn), RRDrStpRsn_st(RRDrStpRsn), TDrStpRsn_st(TDrStpRsn),
        FLDrAbuse_St(FLDrAbuse), RLDrAbuse_St(RLDrAbuse), FRDrAbuse_St(FRDrAbuse), RRDrAbuse_St(RRDrAbuse),
        TDrAbuse_St(TDrAbuse), HoodLatch_St(HoodLatch) {
    }
    uint8_t FLDoor_st;
    uint8_t RLDoor_st;
    uint8_t FRDoor_st;
    uint8_t RRDoor_st;
    uint8_t TDoor_st;
    uint8_t FLNomDoor_St;
    uint8_t RLNomDoor_St;
    uint8_t FRNomDoor_St;
    uint8_t RRNomDoor_St;
    uint8_t TDoorNominal_St;
    uint8_t TDrWrk_St;
    uint8_t TDrTripPst_Val;
    uint8_t FLDrStpRsn_st;
    uint8_t RLDrStpRsn_st;
    uint8_t FRDrStpRsn_st;
    uint8_t RRDrStpRsn_st;
    uint8_t TDrStpRsn_st;
    uint8_t FLDrAbuse_St;
    uint8_t RLDrAbuse_St;
    uint8_t FRDrAbuse_St;
    uint8_t RRDrAbuse_St;
    uint8_t TDrAbuse_St;
    uint8_t HoodLatch_St;
} strDrLth_St;

typedef struct Hdl_St {
    uint8_t FLHdlPst_St;
    uint8_t RLHdlPst_St;
    uint8_t FRHdlPst_St;
    uint8_t RRHdlPst_St;
    uint8_t FLHdlStpRsn_St;
    uint8_t RLHdlStpRsn_St;
    uint8_t FRHdlStpRsn_St;
    uint8_t RRHdlStpRsn_St;
    uint8_t FLHdlBrkCnt_Val;
    uint8_t RLHdlBrkCnt_Val;
    uint8_t FRHdlBrkCnt_Val;
    uint8_t RRHdlBrkCnt_Val;
    uint8_t FLHdlAbuse_St;
    uint8_t RLHdlAbuse_St;
    uint8_t FRHdlAbuse_St;
    uint8_t RRHdlAbuse_St;
} strHdl_St;

typedef struct InLt_Set {
    uint8_t TpLtAutoSet_Req;
    uint8_t TpLtClrSet_Req;
    uint8_t TpLtBrtSet_Req;
    uint8_t BckLtBrtSet_Req;
} strInLt_Set;

typedef struct InLt_Rsp {
    uint8_t TpLtAutoSet_Rsp;
    uint8_t TpLtClrSet_Rsp;
    uint8_t TpLtBrtSet_Rsp;
    uint8_t BckLtBrtSet_Rsp;
} strInLt_Rsp;

typedef struct InLt_Act {
    uint8_t TpLtBtn_Act;
    uint8_t TpLtSearch_Act;
    uint8_t FLTpLtRead_Act;
    uint8_t RLTpLtRead_Act;
    uint8_t FRTpLtRead_Act;
    uint8_t RRTpLtRead_Act;
} strInLt_Act;

typedef struct InLt_St {
    uint8_t TpLtWrk_St;
    uint8_t TpLtSearch_St;
    uint8_t FLTpLtRead_St;
    uint8_t RLTpLtRead_St;
    uint8_t FRTpLtRead_St;
    uint8_t RRTpLtRead_St;
} strInLt_St;

typedef struct BdSf_Act {
    uint8_t LChdlock_Req;
    uint8_t RChdlock_Req;
    uint8_t ChdLockMode_Req;
} strBdSf_Act;

typedef struct BdSf_St {
    uint8_t LChdlock_st;
    uint8_t RChdlock_st;
    uint8_t ChdLockMode_st;
} strBdSf_St;

typedef struct SSd_Set {
    uint8_t LockVoiWarn_Req;
    uint8_t LowSpdVoi_Set;
} strSSd_Set;

typedef struct SSd_Rsp {
    uint8_t LockVoiWarn_Rsp;
    uint8_t LowSpdVoi_Rsp;
} strSSd_Rsp;

typedef struct BdArm_Set {
    BdArm_Set(uint8_t VehicleUnlock, uint8_t ReturnPUnlock, uint8_t AwayVclLck, uint8_t CloseVclUnlck) :
        VehicleUnlock_Set(VehicleUnlock),
        ReturnPUnlock_Set(ReturnPUnlock),
        AwayVclLck_Set(AwayVclLck),
        CloseVclUnlck_Set(CloseVclUnlck) {
    }
    uint8_t VehicleUnlock_Set;
    uint8_t ReturnPUnlock_Set;
    uint8_t AwayVclLck_Set;
    uint8_t CloseVclUnlck_Set;
} strBdArm_Set;

typedef struct BdArm_Rsp {
    uint8_t VehicleUnlock_Rsp;
    uint8_t ReturnPUnlock_Rsp;
    uint8_t AwayVclLck_Rsp;
    uint8_t CloseVclUnlck_Rsp;
} strBdArm_Rsp;

typedef struct BdArm_Act {
    BdArm_Act(uint8_t CenterLck) :
        CenterLck_Act(CenterLck) {
    }
    uint8_t CenterLck_Act;
} strBdArm_Act;

typedef struct BdArm_Ctrl_SOA {
    BdArm_Ctrl_SOA(uint8_t BdArm_Ctrl) :
        BdArm_Ctrl_SOA_u8(BdArm_Ctrl) {
    }
    uint8_t BdArm_Ctrl_SOA_u8;
} strBdArm_Ctrl_SOA;

typedef struct BdArm_St {
    BdArm_St(uint8_t CenterLck, uint8_t BodyBglAlarm, uint8_t ExLckReq) :
        CenterLck_St(CenterLck), BodyBglAlarm_St(BodyBglAlarm), ExLckReq_St(ExLckReq) {
    }
    uint8_t CenterLck_St;
    uint8_t BodyBglAlarm_St;
    uint8_t ExLckReq_St;
} strBdArm_St;

typedef struct VsWsh_Act {
    VsWsh_Act(uint8_t FWiperSvcSW, uint8_t ExMirHt, uint8_t RWndShldHt) :
        FWiperSvcSW_Req(FWiperSvcSW),
        ExMirHt_Req(ExMirHt),
        RWndShldHt_Req(RWndShldHt) {
    }
    uint8_t FWiperSvcSW_Req;
    uint8_t ExMirHt_Req;
    uint8_t RWndShldHt_Req;
} strVsWsh_Act;

typedef struct VsWsh_st {
    VsWsh_st(uint8_t Fwiper, uint8_t WashLqdHgtWarn, uint8_t ExMirHt,
             uint8_t FwiperSWDisplay, uint8_t RWndShldHt) :
        Fwiper_St(Fwiper),
        WashLqdHgtWarn_St(WashLqdHgtWarn),
        ExMirHt_Rsp(ExMirHt),
        FwiperSWDisplay_st(FwiperSWDisplay),
        RWndShldHt_Rsp(RWndShldHt) {
    }
    uint8_t Fwiper_St;
    uint8_t WashLqdHgtWarn_St;
    uint8_t ExMirHt_Rsp;
    uint8_t FwiperSWDisplay_st;
    uint8_t RWndShldHt_Rsp;
} strVsWsh_st;

typedef struct VsWsh_Ctrl_SOA {
    VsWsh_Ctrl_SOA(uint8_t vsWsh_Ctrl) :
        VsWsh_Ctrl_SOA_u8(vsWsh_Ctrl) {
    }
    uint8_t VsWsh_Ctrl_SOA_u8;
} strVsWsh_Ctrl_SOA;

typedef struct Win_Set {
    uint8_t LckCloseWin_Set;
    uint8_t RainCloseWin_Set;
} strWin_Set_struct;

typedef struct Win_Rsp {
    uint8_t LckCloseWin_Rsp;
    uint8_t RainCloseWin_Rsp;
} strWin_Rsp;

typedef struct WinPct_Ctrl_SOA {
    WinPct_Ctrl_SOA(uint8_t WinPct_Ctrl_SOA) :
        WinPct_Ctrl_SOA_u8(WinPct_Ctrl_SOA) {
    }
    uint8_t WinPct_Ctrl_SOA_u8;
} strWinPct_Ctrl_SOA;

typedef struct WinPct_Act {
    uint8_t FLWinPst_Act;
    uint8_t FRWinPst_Act;
    uint8_t RLWinPst_Act;
    uint8_t RRWinPst_Act;
    uint8_t WinFastCtl_Req;
} strWinPct_Act;

typedef struct Win_Status {
    uint8_t FLWinPst_St;
    uint8_t FRWinPst_St;
    uint8_t RLWinPst_St;
    uint8_t RRWinPst_St;
    uint8_t FLWdwMov_St;
    uint8_t FRWdwMov_St;
    uint8_t RLWdwMov_St;
    uint8_t RRWdwMov_St;
    uint8_t FLWinStpRsn_St;
    uint8_t FRWinStpRsn_St;
    uint8_t RLWinStpRsn_St;
    uint8_t RRWinStpRsn_St;
    uint8_t AllWinClose_St;
    uint8_t AllWinOpen_St;
    uint8_t AllWinFrshAir_St;
    uint8_t WinVent_St;
} strWin_Status;

typedef struct BdPst_Set {
    uint8_t ExMirAutoTurnOver_Set;
    uint8_t ExMirFoldEn_Set;
    uint8_t ExMirUnfoldAlt_Set;
} strBdPst_Set;

typedef struct BdPst_Rsp {
    uint8_t ExMirAutoTurnOverSet_Rsp;
    uint8_t ExMirFoldEn_Rsp;
    uint8_t ExMirUnfoldAlt_Rsp;
} strBdPst_Rsp;

typedef struct StAdj_Act {
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
    uint8_t FLSeatLegLengthAdj_Act;
    uint8_t FRSeatLegLengthAdj_Act;
} strStAdj_Act;

typedef struct StAdj_St {
    uint8_t FLSeatFBMv_St;
    uint8_t FLSeatBackrestMv_St;
    uint8_t FLSeatCshnAngMv_St;
    uint8_t FLSeatHgtMv_St;
    uint8_t FLLegAngCshnExtMv_St;
    uint8_t FRSeatFBMv_St;
    uint8_t FRSeatBackrestMv_St;
    uint8_t FRSeatCshnAngMv_St;
    uint8_t FRSeatHgtMv_St;
    uint8_t FRLegAngCshnExtMv_St;
    uint8_t FLSeatFBPst_Val;
    uint8_t FLSeatBackrestPst_Val;
    uint8_t FLSeatHgtPst_Val;
    uint8_t FLSeatCshnAngPst_Val;
    uint8_t FLLegAngCshnExtPst_Val;
    uint8_t FRSeatFBPst_Val;
    uint8_t FRSeatBackrestPst_Val;
    uint8_t FRSeatHgtPst_Val;
    uint8_t FRSeatCshnAngPst_Val;
    uint8_t FRLegAngCshnExtPst_Val;
    uint8_t FLSeatLegLengthMv_St;
    uint8_t FRSeatLegLengthMv_St;
    uint8_t FLSeatLegLengthPst_Val;
    uint8_t FRSeatLegLengthPst_Val;
} strStAdj_St;

typedef struct BdPst_Act {
    uint8_t ExMirCtrl_Act;
    uint8_t LExMirUDAdj_Act;
    uint8_t LExMirLRAdj_Act;
    uint8_t RExMirUDAdj_Act;
    uint8_t RExMirLRAdj_Act;
    uint8_t SteerTiltAdj_Act;
    uint8_t SteerTeleAdj_Act;
    uint8_t SteerLongStroke_Req;
    uint8_t FLMemPstExport_req;
    uint8_t FRMemPstExPort_req;
} strBdPst_Act;

typedef struct BdPst_St {
    uint8_t ExMirCtrl_St;
    uint8_t LExMirUDMv_St;
    uint8_t LExMirLRMv_St;
    uint8_t RExMirUDMv_St;
    uint8_t RExMirLRMv_St;
    uint8_t SteerTiltMv_St;
    uint8_t SteerTeleMv_St;
    uint8_t LExMirCtrlMv_St;
    uint8_t RExMirCtrlMv_St;
    uint8_t SteerLongStroke_Rsp;
    uint8_t FLMemPst1Export_Rsp;
    uint8_t FLMemPst2Export_Rsp;
    uint8_t FLMemPst3Export_Rsp;
    uint8_t FLMemPst4Export_Rsp;
    uint8_t FRMemPst1ExPort_Rsp;
    uint8_t FRMemPst2ExPort_Rsp;
    uint8_t FRMemPst3ExPort_Rsp;
    uint8_t FRMemPst4ExPort_Rsp;
} strBdPst_St; //BdPst_Ctrl_struct

typedef struct PowerModeReq {
    uint8_t PowerMode_Req;
} strPowerModeReq;

typedef struct PowerModeRsp {
    uint8_t PowerOn_Rsp;
    uint8_t PowerOff_Rsp;
} strPowerModeRsp;

typedef struct PowerModeSt {
    uint8_t PowerMode_St;
    uint8_t PowerGoOff_St;
    uint8_t PowerOffAvl_St;
} strPowerModeSt;

typedef struct AC_Ctrl {
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
    uint8_t AirFragranceSwitchEnable;
    uint8_t FragranceConcentration_Req;
    uint8_t AirFragranceChannel1;
    uint8_t AirFragranceChannel2;
    uint8_t AirFragranceChannel3;
    uint8_t IONSet_Cmd;
    uint8_t PM25Set_Cmd;
    uint8_t AQSSet_Cmd;
    uint8_t FLeftAirOutletMode_Cmd;
    uint8_t FRightAirOutletMode_Cmd;
    uint8_t FLOutletSwitch_Cmd;
    uint8_t LCOutletSwitch_Cmd;
    uint8_t RCOutletSwitch_Cmd;
    uint8_t FROutletSwitch_Cmd;
    uint8_t FLOutletLeftRightAngle;
    uint8_t FLOutletUpDownAngle;
    uint8_t LCOutletUpDownAngle;
    uint8_t LCOutletLeftRightAngle;
    uint8_t RCOutletUpDownAngle;
    uint8_t RCOutletLeftRightAngle;
    uint8_t FROutletUpDownAngle;
    uint8_t FROutletLeftRightAngle;

} strAC_Ctrl;

typedef struct ACStatus {
    uint8_t ACCycleMode_St;
    uint8_t FACAirFlowLevel_St;
    uint8_t FACMode_St;
    uint8_t FACSwitch_Rsp;
    uint8_t FDeiceDefrost_Rsp;
    uint8_t FLeftTempSet_St;
    uint8_t FRightTempSet_St;
    uint8_t FTempAreaSync_St;
    uint8_t FAcCoolOrHeatOrVent_St;
    uint8_t ACOperateMode_St;
    uint8_t FACAuto_Rsp;
    uint8_t FACAirFlowLevelAuto_St;
    uint8_t FACAirFlowModeAuto_St;
    uint8_t FACCoolOrHeatOrVentAuto_St;
    uint8_t EnvirTemp_Val;
    uint8_t FragSwitchEN_Rsp;
    uint8_t FragConcLevel_Rsp;
    uint8_t FragChannel1Switch_St;
    uint8_t FragChannel2Switch_St;
    uint8_t FragChannel3Switch_St;
    uint8_t FragChannelType;
    uint8_t FragChannelIndex;
    uint16_t FragChannel1Life;
    uint16_t FragChannel2Life;
    uint16_t FragChannel3Life;
    uint8_t IONSet_St;
    uint8_t PM25Set_St;
    uint8_t PM25Trigger_St;
    uint16_t PM25CarConc;
    uint8_t AQSSet_St;
    uint8_t AQSTrigger_St;
    uint8_t AQSAirQuality_Val;
    uint8_t InFilterLifeRemind;
    uint8_t OutsideFilterLifeRemind;
    uint8_t FLeftAirOutletMode_St;
    uint8_t FRightAirOutletMode_St;
    uint8_t OLMFLAirOutletSwitch_Rsp;
    uint8_t OLMLCAirOutletSwitch_Rsp;
    uint8_t OLMRCAirOutletSwitch_Rsp;
    uint8_t OLMFRAirOutletSwitch_Rsp;
    uint8_t OLMFLMotorErrSt;
    uint8_t OLMLCMotorErrSt;
    uint8_t OLMRCMotorErrSt;
    uint8_t OLMFRMotorErrSt;
    uint8_t OLMFLAirOutletLeftRightAngle_Rsp;
    uint8_t OLMFLAirOutletUpDownAngle_Rsp;
    uint8_t OLMLCAirOutletUpDownAngle_Rsp;
    uint8_t OLMLCAirOutletLeftRightAngle_Rsp;
    uint8_t OLMRCAirOutletLeftRightAngle_Rsp;
    uint8_t OLMRCAirOutletUpDownAngle_Rsp;
    uint8_t OLMFRAirOutletUpDownAngle_Rsp;
    uint8_t OLMFRAirOutletLeftRightAngle_Rsp;
} strACStatus;

typedef struct DrivingModeReq {
    uint8_t EPSModeChange_Req;
    uint8_t TargVehicleMode_Req;
    uint8_t PTModeChange_Req;
    uint8_t LowConsumMode_Req;
    uint8_t ValetMode_Req;
    uint8_t OnePedalMode_Req;
    uint8_t CoastRegenStrg_Req;
    uint8_t SpdLimit_Req;
    uint8_t TrailMode_Req;
    uint8_t Salemode_Req;
} strDrivingModeReq;

typedef struct DringMode_St {
    uint8_t DMSEPSModeInfo_St;
    uint8_t DMSVehMode_St;
    uint8_t DMSModeChgEn_St;
    uint8_t DMSPTModeInfo_St;
    uint8_t DMSValetMode_St;
    uint8_t OnePedalMode_St;
    uint8_t OPMAvaliability_St;
    uint8_t RegenSetPct_Rsp;
    uint8_t RegenAvail_St;
    uint8_t RegenForDisp_UI;
    uint8_t DrvVehModAvaliability_St;
    uint8_t TrailMode_St;
    uint8_t TrailAvaliability_St;
    uint8_t TrailForDisp_UI;
    uint8_t SaleMode_St;
} strDringMode_St;

typedef struct ThermalStatus {
    uint8_t HeatLiquidtLackWarn_St;
    uint8_t ThermalLiquidLackWarn_St;
    uint8_t RefrigerantCheckRemind;
    uint8_t FACLimit_St;
} strThermalStatus;

typedef struct GeneralVehSt {
    uint16_t SOCDisplay_Val;
    uint8_t DCCharge_St;
    uint8_t ACCharge_St;
    uint8_t FLSeatOcp_St;
    uint8_t ActlGear_St;
    uint8_t ActlGearVaild_St;
    uint8_t Ready_St;
    uint8_t DrvrSeatBeltValid_St;
    uint8_t DrvrSeatBelt_St;
    uint8_t EPB_St;
    uint8_t VehSpdValid_St;
    uint16_t VehSpd_Val;
} strGeneralVehSt;

typedef struct CgC_St {
    uint8_t ChrgCap_St;
    uint8_t ChrgCapMv_St;
    uint8_t ChrgCapPst_St;
    uint8_t ChrgCapStpRsn_St;
} strCgC_St;

typedef struct CgC_Act {
    uint8_t ChrgCapCtrlSW_Req;
} strCgC_Act;

typedef struct CHSSetting {
    uint8_t HDCSw_Req;
    uint8_t EHBMBrkModeSet_Req;
    uint8_t CSTSw_Req;
    uint8_t TCSSw_Req;
    uint8_t AVHSw_Req;
    uint8_t ESCSw_Req;
    uint8_t ParkingSwitch_Req;
} strCHSSetting;

typedef struct CHSSetting_St {
    uint8_t HDCAvail_St;
    uint8_t HDC_St;
    uint8_t BrakeModeEnable_St;
    uint8_t BrakeMode_St;
    uint8_t BoostDegrade_St;
    uint8_t CST_Rsp;
    uint8_t TCSSwAvail_St;
    uint8_t PataLamp_St;
    uint8_t AVHAvail_St;
    uint8_t AVH_St;
    uint8_t ESCSwAvail_St;
    uint8_t ESClamp_St;
    uint8_t EPB_St;
    uint8_t BU_EPB_St;
    uint8_t EPBSwAvail_St;
} strCHSSetting_St;

typedef struct PTHMI {
    uint8_t OBCACChrgCnctor_St;
    uint8_t OBCACSocketLock_St;
    uint8_t AbnormalShiftInfo;
    uint8_t DriveConflictRemindInfo;
    uint8_t Shift_Err;
    uint8_t HVOffConfirm_Req;
    uint8_t LimpHomeRmnd_St;
    uint8_t LowVoltSys_Err;
    uint8_t LowVoltSysWarnStop_St;
    uint8_t Motorovertemp_St;
    uint8_t PTFaultLgtClr_St;
    uint8_t PTThmlLiquidLackWarn_St;
    uint32_t PTHMI_Req;
    uint8_t PullOver_St;
    uint8_t RegenAvail_St;
    uint16_t StdSenarioMileage_Val;
    uint8_t ServiceReminder_St;
    uint8_t ThmlRunawayWarn_St;
    uint8_t TractionModeAvail_St;
    uint8_t TractionModeRemaind_St;
    uint8_t TractionModeSet_Rsp;
    uint8_t ACCharge_St;
    uint8_t CellOverTemp_St;
    uint8_t ChrgDischrgCnct_St;
    uint8_t DCCharge_St;
    uint8_t FastChrgCnctor_St;
} strPTHMI;

typedef struct CHSHMI {
    uint8_t AirbagWarnLamp_St;
    uint8_t EPSSystem_Err;
    uint8_t ABSIntv_St;
    uint8_t ABS_Err;
    uint8_t EBDIntv_St;
    uint8_t EBD_Err;
    uint8_t BrakeFluidLvl_St;
    uint8_t BrakePedal_St;
    uint8_t InputRodStroke_St;
    uint8_t EPBFunctionLamp_St;
    uint16_t InputRodStroke_Val;
    uint8_t EPBFailLamp_St;
    uint8_t CapacityLimitWarn_UI;
    uint8_t OperationReminder_UI;
    uint8_t BU_CapacityLimitWarn_UI;
    uint8_t BU_OperationReminder_UI;
    uint8_t BU_EPBFunctionLamp_St;
    uint8_t BU_EPBFailLamp_St;
    uint8_t BU_EPBHardSwitch_St;
} strCHSHMI;

typedef struct ExtLt_Ctrl {
    uint8_t TurnLight_Req;
    uint8_t EtnlLgt_Req;
    uint8_t HighBeam_Req;
    uint8_t HDBI_RearFogBm_Req;
    uint8_t HzrdSW_St;
    uint8_t FollowMeHome_Req;
    uint8_t LgtHeightAdjSet_Req;
    uint8_t AHB_Req;
} strExtLt_Ctrl;

typedef struct ExtLt_St {
    uint8_t LeftTurnLgt_Req;
    uint8_t RgtTurnLgt_Req;
    uint8_t FLPstnLgt_Req;
    uint8_t FRPstnLgt_Req;
    uint8_t RLPstnLgt_Req;
    uint8_t RRPstnLgt_Req;
    uint8_t HighLgt_Req;
    uint8_t LwLgt_Req;
    uint8_t HDBM_RearFogBm_Req;
    uint8_t EtnlLgt_Rsp;
    uint8_t FollowMeHome_Rsp;
    uint8_t LgtHeightAdjSet_Rsp;
    uint8_t AHB_Rsp;
} strExtLt_St;

typedef struct WiperWash_Ctrl {
    uint8_t Fwiper_Req;
    uint8_t FMistWash_Req;
} strWiperWash_Ctrl;

typedef struct VsWsh_Set {
    VsWsh_Set(uint8_t FwiperSW, uint8_t FwiperAutoSenst) :
        FwiperSW_Set(FwiperSW),
        FwiperAutoSenst_Set(FwiperAutoSenst) {
    }
    uint8_t FwiperSW_Set;
    uint8_t FwiperAutoSenst_Set;
} strVsWsh_Set;

typedef struct VsWsh_Rsp {
    uint8_t FwiperSW_Rsp;
    uint8_t FwiperAutoSenst_Rsp;
} strVsWsh_Rsp;

typedef struct AmLt_Set {
    uint8_t AmLtBtn_Set;
    uint8_t AmLtBrt_Set;
    uint8_t AmLtMode_Set;
    uint16_t AmLtCustomClr_Set;
    uint8_t AmLtAutoBrt_Set;
    uint8_t AmLtBrtFollow_Set;
    uint8_t AmLtVoice_Set;
    uint8_t Welcome_Set;
    uint8_t AmLtMusic_Set;
    uint8_t AmLtTemp_Set;
    uint16_t AmLtMedRedVal_Set;
    uint16_t AmLtMedGreenVal_Set;
    uint16_t AmLtMedBlueVal_Set;

} strAmLt_Set;

typedef struct AmLt_Rsp {
    uint8_t AmLtBtn_Rsp;
    uint8_t AmLtBrt_Rsp;
    uint8_t AmLtMode_Rsp;
    uint16_t AmLtCustomClr_Rsp;
    uint8_t AmLtAutoBrt_Rsp;
    uint8_t AmLtBrtFollow_Rsp;
    uint8_t AmLtVoice_Rsp;
    uint8_t AmLtWelcome_Rsp;
    uint8_t AmLtMusic_Rsp;
    uint8_t AmLtTemp_Rsp;
} strAmLt_Rsp;

typedef struct BdCft_Act {
    uint8_t FLLumbSuppUDAdj_Act;
    uint8_t FLLumbSuppFBAdj_Act;
    uint8_t FRLumbSuppUDAdj_Act;
    uint8_t FRLumbSuppFBAdj_Act;
    uint8_t FLSeatShoulderAdj_Act;
    uint8_t FRSeatShoulderAdj_Act;
    uint8_t FLSeatMsg_Act;
    uint8_t FLSeatMsgMode_Act;
    uint8_t FLSeatMsgStrth_Act;
    uint8_t FRSeatMsg_Act;
    uint8_t FRSeatMsgMode_Act;
    uint8_t FRSeatMsgStrth_Act;
    uint8_t FLSeatHt_Act;
    uint8_t FRSeatHt_Act;
    uint8_t SRLSeatHt_Act;
    uint8_t SRRSeatHt_Act;
    uint8_t FLSeatVtlt_Act;
    uint8_t FRSeatVtlt_Act;
    uint8_t SRLSeatVtlt_Act;
    uint8_t SRRSeatVtlt_Act;
    uint8_t SteerHt_Act;
} strBdCft_Act;

typedef struct BdCft_St {
    uint8_t FLLumbSuppFBMv_St;
    uint8_t FLLumbSuppUDMv_St;
    uint8_t FRLumbSuppFBMv_St;
    uint8_t FRLumbSuppUDMv_St;
    uint8_t FLSeatShoulderAdj_St;
    uint8_t FRSeatShoulderAdj_St;
    uint8_t FLSeatMsg_St;
    uint8_t FLSeatMsgMode_St;
    uint8_t FLSeatMsgStrth_St;
    uint8_t FRSeatMsg_St;
    uint8_t FRSeatMsgMode_St;
    uint8_t FRSeatMsgStrth_St;
    uint8_t FLSeatHt_St;
    uint8_t FRSeatHt_St;
    uint8_t SRLSeatHt_St;
    uint8_t SRRSeatHt_St;
    uint8_t FLSeatVtlt_St;
    uint8_t FRSeatVtlt_St;
    uint8_t SRLSeatVtlt_St;
    uint8_t SRRSeatVtlt_St;
    uint8_t SteerHt_St;
} strBdCft_St;

typedef struct NMService_Req {
    uint8_t WakeupSceneID;
    uint8_t WakeupSceneState;
    uint8_t WakeupSceneXHDBMCom_St;
    uint8_t WakeupSceneXCAN1PN_St;
    uint8_t WakeupSceneXFD1PN_St;
    uint8_t WakeupSceneXVB1PN_St;
    uint8_t WakeupSceneXHDBI_St;
    uint64_t WakeupSceneXZCUL_St;
    uint64_t WakeupSceneXZCUR_St;
    uint64_t WakeupSceneXZCUF_St;
    uint64_t WakeupSceneXZCUT_St;
    uint8_t WakeupSceneXHDBT_St;
    uint8_t WakeupSceneXHDBA_St;
} strNMService_Req;

typedef struct NMService_St {
    uint8_t WakeupSceneIDAct[50];
} strNMService_St;

typedef struct BdMemPst_Set {
    uint8_t FLSeatMemFBPst_Req;
    uint8_t FLSeatMemBackrestPst_Req;
    uint8_t FLSeatMemHgtPst_Req;
    uint8_t FLSeatMemCshnAngPst_Req;
    uint8_t FLMemLegAngCshnExtPst_Req;
    uint8_t FLSeatMemLegLengthPst_Req;
    uint8_t FLSeatMemPstPurpose_Req;
    uint8_t FRSeatMemFBPst_Req;
    uint8_t FRSeatMemBackrestPst_Req;
    uint8_t FRSeatMemHgtPst_Req;
    uint8_t FRSeatMemCshnAngPst_Req;
    uint8_t FRSeatMemLegAngCshnExtPst_Req;
    uint8_t FRSeatMemLegLengthPst_Req;
    uint8_t FRSeatPstPurpose_Req;
    uint8_t SRLSeatMemFBPst_Req;
    uint8_t SRLSeatMemBackrestPst_Req;
    uint8_t SRLSeatMemHgtPst_Req;
    uint8_t SRLSeatMemCshnAngPst_Req;
    uint8_t SRLSeatMemLegAngCshnExtPst_Req;
    uint8_t SRLSeatMemPstPurpose_Req;
    uint8_t SRRSeatMemFBPst_Req;
    uint8_t SRRSeatMemBackrestPst_Req;
    uint8_t SRRSeatMemHgtPst_Req;
    uint8_t SRRSeatMemCshnAngPst_Req;
    uint8_t SRRSeatMemLegAngCshnExtPst_Req;
    uint8_t SRRSeatMemPstPurpose_Req;
    uint8_t SteerMemTiltPst_Req;
    uint8_t SteerMemTelePst_Req;
    uint8_t SteerMemPstPurpose_Req;
    uint8_t LExMirMemUDPst_Req;
    uint8_t LExMirMemLRPst_Req;
    uint8_t LExMirMemLRPstPurpose_Req;
    uint8_t RExMirMemUDPst_Req;
    uint8_t RExMirMemLRPst_Req;
    uint8_t RExMirMemLRPstPurpose_Req;
    uint8_t FLSeatMemPstGet_Req;
    uint8_t FRSeatMemPstGet_Req;
    uint8_t SRLSeatMemPstGet_Req;
    uint8_t SRRSeatMemPstGet_Req;
    uint8_t SteerMemPstGet_Req;
    uint8_t LExMirMemLRPstGet_Req;
    uint8_t RExMirMemLRPstGet_Req;
} strBdMemPst_Set;

typedef struct BdPst_Mem_Rsp {
    uint8_t FLSeatMemFBPst_Rsp;
    uint8_t FLSeatMemBackrestPst_Rsp;
    uint8_t FLSeatMemHgtPst_Rsp;
    uint8_t FLSeatMemCshnAngPst_Rsp;
    uint8_t FLSeatMemLegAngCshnExtPst_Rsp;
    uint8_t FLSeatMemLegLengthPst_Rsp;
    uint8_t FLSeatMemPstPurpose_Rsp;
    uint8_t FRSeatMemFBPst_Rsp;
    uint8_t FRSeatMemBackrestPst_Rsp;
    uint8_t FRSeatMemHgtPst_Rsp;
    uint8_t FRSeatMemCshnAngPst_Rsp;
    uint8_t FRSeatMemLegAngCshnExtPst_Rsp;
    uint8_t FRSeatMemLegLengthPst_Rsp;
    uint8_t FRSeatMemPstPurpose_Rsp;
    uint8_t SRLSeatMemFBPst_Rsp;
    uint8_t SRLSeatMemBackrestPst_Rsp;
    uint8_t SRLSeatMemHgtPst_Rsp;
    uint8_t SRLSeatMemCshnAngPst_Rsp;
    uint8_t SRLSeatMemLegAngCshnExtPst_Rsp;
    uint8_t SRLSeatMemPstPurpose_Rsp;
    uint8_t SRRSeatMemFBPst_Rsp;
    uint8_t SRRSeatMemBackrestPst_Rsp;
    uint8_t SRRSeatMemHgtPst_Rsp;
    uint8_t SRRSeatMemCshnAngPst_Rsp;
    uint8_t SRRSeatMemLegAngCshnExtPst_Rsp;
    uint8_t SRRSeatMemPstPurpose_Rsp;
    uint8_t SteerMemTiltPst_Rsp;
    uint8_t SteerMemTelePst_Rsp;
    uint8_t SteerMemPstPurpose_Rsp;
    uint8_t LExMirMemUDPst_Rsp;
    uint8_t LExMirMemLRPst_Rsp;
    uint8_t LExMirMemLRPstPurpose_Rsp;
    uint8_t RExMirMemUDPst_Rsp;
    uint8_t RExMirMemLRPst_Rsp;
    uint8_t RExMirMemLRPstPurpose_Rsp;
} strBdPst_Mem_Rsp;

typedef struct BdCft_Set {
    uint8_t FLSeatWelcome_Set;
    uint8_t SeatAutoHeat_Set;
    uint8_t StreeAutoHeat_Set;
    uint8_t ExitVehicleMemory_Set;
} strBdCft_Set;

typedef struct BdCft_Rsp {
    uint8_t FLSeatWelcome_Rsp;
    uint8_t SeatAutoHeat_Rsp;
    uint8_t StreeAutoHeat_Rsp;
    uint8_t ExitVehicleMemory_Rsp;
} strBdCft_Rsp;

typedef struct CarMode_Ctrl {
    uint8_t CarMode_Req;
} strCarMode_Ctrl;

typedef struct CarMode_St {
    uint8_t CarMode_St;
} strCarMode_St;

typedef struct OBDLineRequest {
    uint8_t OBD_Active_Req;
} strOBDLineRequest;

typedef struct BaseData_St {
    uint8_t Skey_ValidKey_St;
} strBaseData_St;

typedef struct HDBM_BaseData_Act {
    uint8_t OBD_Active_Act;
} strHDBM_BaseData_Act;

#endif