/*
 * @author 008555
 * @for DDS DataStructure define
 * @version 1.0
 * @date 2023-06 ~ 2023-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DDS_REPLY_DATA_DEF_H
#define DDS_REPLY_DATA_DEF_H

  struct DrLth_Set_struct {
    uint8_t DoorBit;
    uint64_t OpenAngSet_Req;
    
  };

  struct DrLth_Get_struct {
    uint8_t DoorBit;
    
  };

  struct DrLth_Rsp_struct {
    uint8_t DoorBit;
    uint64_t OpenAngSet_Rsp;
  };

  struct DrLth_Act_struct {
    uint8_t DoorBit;
    uint32_t DoorBtnCtrl;
    uint64_t DoorPosCtrl;
    
  };

  struct DrLth_St_struct {
    uint8_t DoorBit;
    uint32_t Door_st;
    uint32_t DrWrk_St;
    uint32_t NomDoor_St;
    uint64_t TripPst_Val;
    uint32_t StpRsn_st;
    uint32_t DrAbuse_St;
  };

  struct Hdl_St_struct {
    uint8_t HdlBit;
    uint32_t HdlPst_St;
    uint32_t HdlStpRsn_St;
    uint32_t HdlBrkCnt_Val;
    uint32_t HdlAbuse_St;
  };

  struct DrLth_St_Get_struct {
    uint8_t DoorBit;
    
  };

  struct Hdl_St_Get_struct {
    uint8_t HdlBit;
    
  };

  struct DrLth_Act_SOA_u8 {
    uint8_t DrLth_Act_SOAu8;
  };

  struct Win_Set_struct {
    uint8_t WinSetBit;
    uint32_t WinSetCmd;
    
  };

  struct Win_Get_struct {
    uint8_t WinSetBit;
    
  };

  struct Win_Rsp_struct {
    uint8_t WinSetBit;
    uint32_t WinSetRsp;
  };

  struct Win_PerAct_struct {
    uint8_t WinBit;
    uint32_t WinPerActCmd;
    
  };

  struct WinPct_Act_SOA_u8 {
    uint8_t WinPct_Act_SOAu8;
  };

  struct Win_St_Get_struct {
    uint8_t WinBit;
    
  };

  struct Win_St_struct {
    uint8_t WinBit;
    uint32_t WinPst_St;
    uint32_t WinMov_St;
    uint32_t WinStpRsn_St;
  };

  struct BdPst_Set_struct {
    uint8_t BdPstSetBit;
    uint32_t BdPstSetCmd;
    
  };

  struct BdPst_Get_struct {
    uint8_t BdPstSetBit;
    
  };

  struct BdPst_Rsp_struct {
    uint8_t BdPstSetBit;
    uint32_t BdPstRespCmd;
  };

  struct BdPst_Act_struct {
    uint16_t BdPstBit;
    uint64_t BdPstCmd;
    
  };

  struct BdPst_Act_SOA_u8 {
    uint8_t BdPst_Act_SOAu8;
  };

  struct BdPst_St_Get_struct {
    uint16_t BdPstBit;
    
  };

  struct BdPst_St_struct {
    uint16_t BdPstBit;
    uint64_t SyBdPstSt;
  };

  struct StAdj_Act_struct {
    uint16_t StPstBit;
    uint64_t StAdjCmd;
    
  };

  struct StAdj_Act_SOA_u8 {
    uint8_t StAdj_Act_SOAu8;
  };

  struct StAdj_St_Get_struct {
    uint16_t StPstBit;
    
  };

  struct StAdj_St_struct {
    uint16_t StPstBit;
    uint64_t StAdj_St;
  };

  struct InLt_Set_struct {
    uint8_t InLtBit;
    uint32_t InLtSetCmd;
    
  };

  struct InLt_Get_struct {
    uint8_t InLtBit;
    
  };

  struct InLt_Rsp_struct {
    uint8_t InLtBit;
    uint32_t InLtSetRsp;
  };

  struct InLt_Act_struct {
    uint8_t InLtBit;
    uint32_t InLtCmd;
  };

  struct InLt_Act_SOA_u8 {
    uint8_t InLt_Act_SOAu8;
  };

  struct InLt_St_Get_struct {
    uint8_t InLtBit;
  };

  struct InLt_St_struct {
    uint8_t InLtBit;
    uint32_t InLtSt;
  };

  struct BdArm_Set_struct {
    uint8_t BdArmSetBit;
    uint32_t BdArmSetCmd;
  };

  struct BdArm_Get_struct {
    uint8_t BdArmSetBit;
  };

  struct BdArm_Rsp_struct {
    uint8_t BdArmSetBit;
    uint32_t BdArmRsp;
  };

  struct BdArm_Act_struct {
    uint8_t BdArmActBit;
    uint32_t BdArmActCmd;
  };

  struct BdArm_Act_SOA_u8 {
    uint8_t BdArm_Act_SOAu8;
  };

  struct BdArm_St_Get_struct {
    uint8_t BdArmActBit;
  };

  struct BdArm_st_struct {
    uint8_t BdArmActBit;
    uint32_t BdArm_st;
  };

  struct VsWsh_Act_struct {
    uint8_t VsWshActBit;
    uint32_t VsWshActCmd;
  };

  struct VsWsh_Act_SOA_u8 {
    uint8_t VsWsh_Act_SOAu8;
  };

  struct VsWsh_St_Get_struct {
    uint8_t VsWshActBit;
  };

  struct VsWsh_st_struct {
    uint8_t VsWshActBit;
    uint32_t VsWshSt;
  };

  struct SSd_Set_struct {
    uint8_t SSdSetBit;
    uint32_t SSdSetCmd;
  };

  struct SSd_Get_struct {
    uint8_t SSdSetBit;
  };

  struct SSd_Rsp_struct {
    uint8_t SSdSetBit;
    uint32_t SSdSetRsp;
  };

  struct BdSf_Act_struct {
    uint8_t BdSfBit;
    uint32_t BdSfCmd;
    
  };

  struct BdSf_Act_SOA_u8 {
    uint8_t BdSf_Act_SOAu8;
  };

  struct BdSf_St_struct {
    uint8_t BdSfBit;
    uint32_t BdSfSt;
  };

  struct CgC_Act_struct {
    uint8_t ChgCapCtrlSW_Req;
    
  };

  struct CgC_Act_SOA_u8 {
    uint8_t CgC_Act_SOAu8;
  };

  struct CgC_St_struct {
    uint8_t ChrgCap_St;
    uint8_t ChrgCapMv_St;
    uint8_t ChrgCapPst_St;
    uint8_t ChrgCapStpRsn_St;
  };

  struct PowermodeReq_Struct {
    uint8_t PwrMdBit;
    uint32_t PwrMdCtrlCmd;
  };

  struct PowerModeRsp_Struct {
    uint8_t PwrMdBit;
    uint32_t PwrMdCtrlRsp;
  };

  struct PowerModeSt_Struct {
    uint8_t PowerModeStBit;
    uint32_t PowerModeSt;
  };

  struct DringMode_St_Struct {
    uint16_t DrMd1Bit;
    uint8_t DrMd2Bit;
    uint64_t DrMd1St;
    uint64_t DrMd2St;
    uint64_t DrMdAvl1St;
    uint32_t DrMdAvl2St;
    uint32_t DrMdDsp1St;
    uint32_t DrMdDsp2St;
    uint64_t DrMdInfo1St;
    uint32_t DrMdInfo2St;
    uint64_t DrMdIf1St;
    uint32_t DrMdIf2St;
    uint64_t DrMdNotused1St;
    uint32_t DrMdNotused2St;
  };

  struct CHSSetting_St_Struct {
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
  };

  struct ACStatus_struct {
    uint16_t ACMSt1Bit;
    uint64_t ACMSt1;
    uint8_t ACMSt2Bit;
    uint64_t ACMSt2;
  };

  struct ThermalStatus_struct {
    uint8_t WarnTypeBit;
    uint32_t Warn_St;
  };

  struct GeneralVehSt_Struct {
    uint16_t SOCDisplay_Val;
    uint8_t DCCharge_St;
    uint8_t ACCharge_St;
    uint8_t FLSeatOcp_St;
    uint8_t ActlGear_St;
    uint8_t ActlGearVaild_St;
    uint8_t Ready_St;
    uint8_t DrvrSeatBeltValid_St;
    uint8_t DrvrSeatBelt_St;
    uint8_t VehSpdValid_St;
    uint16_t VehSpd_Val;
    uint8_t EPB_St;
  };

  struct PTHMI_struct {
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
    uint32_t PTHMI_Req;
    uint8_t PTThmlLiquidLackWarn_St;
    uint8_t PullOver_St;
    uint8_t RegenAvail_St;
    uint8_t ServiceReminder_St;
    uint16_t StdSenarioMileage_Val;
    uint8_t ThmlRunawayWarn_St;
    uint8_t TractionModeAvail_St;
    uint8_t TractionModeRemaind_St;
    uint8_t TractionModeSet_Rsp;
    uint8_t ACCharge_St;
    uint8_t CellOverTemp_St;
    uint8_t ChrgDischrgCnct_St;
    uint8_t DCCharge_St;
    uint8_t FastChrgCnctor_St;
  };

  struct CHSHMI_struct {
    uint8_t AirbagWarnLamp_St;
    uint8_t EPSSystem_Err;
    uint8_t ABSIntv_St;
    uint8_t ABS_Err;
    uint8_t EBDIntv_St;
    uint8_t EBD_Err;
    uint8_t BrakeFluidLvl_St;
    uint8_t BrakePedal_St;
    uint8_t InputRodStroke_St;
    uint16_t InputRodStroke_Val;
    uint8_t EPBFunctionLamp_St;
    uint8_t EPBFailLamp_St;
    uint8_t CapacityLimitWarn_UI;
    uint8_t OperationReminder_UI;
    uint8_t BU_CapacityLimitWarn_UI;
    uint8_t BU_OperationReminder_UI;
    uint8_t BU_EPBFunctionLamp_St;
    uint8_t BU_EPBFailLamp_St;
    uint8_t BU_EPBHardSwitch_St;
  };

  struct ExtLt_Ctrl_Struct {
    uint8_t TurnLight_Req;
    uint8_t EtnlLgt_Req;
    uint8_t HighBeam_Req;
    uint8_t HDBI_RearFogBm_Req;
  };


  struct ExtLt_St_Struct {
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
  };

  struct WiperWash_Ctrl_Struct {
    uint8_t Fwiper_Req;
    uint8_t FMistWash_Req;
  };




#endif