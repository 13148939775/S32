/**
 * @file DomainNode.h
 * @brief hdbi domainnode 1
 * @author T001294
 * @version 1.0
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023  HRYT
 * 
 */

#ifndef DOMAINNODE_H
#define DOMAINNODE_H

#include <iostream>
#include <csignal>
#include <vector>
#include <thread>
#include <functional>
#include <climits>
#include <map>
#include <string>
#include <type_traits>
#include <unistd.h>

#include "HhtLooperThread.h"
#include "HhtTaskLooper.h"
#include "status.h"
#include "ini_config.h"
#include "s2s_config.h"
#include "ipcf_data.h"
#include <node_log.h>
#include "socket_udp_server.h"
#include "DDS_comm.h"
#include "DDSServiceInterfaceIV3.hpp"

using namespace common;
using namespace HHT;
using namespace DDSComm;
using namespace BodyDomain;
using namespace PTDomain;
using namespace EnergyDomain;
using namespace Temporary;
using namespace bottomtotop;

constexpr uint32_t DOMAIN_ID = 1;
constexpr uint32_t LOOP_RATE = 100;

constexpr uint32_t PORT = 19996;
constexpr uint32_t BUFFSIZE = 32;

enum CASE_DATA_TYPE : uint8_t {
    DrLth_Set_struct__ = 1,
    DrLth_Ctrl_struct__ = 2,
    BdArm_Set_struct__ = 5,
    BdArm_Ctrl_struct__ = 6
};

class DomainNode {
public:
    typedef void (DomainNode::*RRFUN)(const CASE_DATA_TYPE, const uint8_t, const uint8_t);
    DomainNode();
    virtual ~DomainNode() {
    }

    Status Init();
    void InitSignalMap();
    bool InitSocket();
    Status ReadModuleConf();
    Status Step();

    static void stop_handler(int) noexcept {
        is_shutdown = true;
    }
    void setup_signal_handlers() noexcept {
        signal(SIGINT, stop_handler);
        signal(SIGTERM, stop_handler);
    }
    Status ParseCMDLine();
    Status RecvPadSignalViaSocket();
    Status ParsePadSignal(const char *buff);
    bool ParseIdAndSetData(const uint8_t big_id, const uint8_t small_id, const uint8_t value);

    Status DDS2Signal();
    Status SendSignal2PadViaSocket();

    void FindCaseType();

    // 处理RR
    void onProcBdArmRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcVsWshRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcSSdRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcWinRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcBdPstRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcStAdjRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcDrLthRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcHdlRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcInLtRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcAmLtRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcBdSfRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcCgCRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcVehicleModeRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcACRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcCHSRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcExtLtRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcBdCftRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcBotRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcBotScriptRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcKeyRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    void onProcNMServiceRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal);
    // 处理pubsub
    void ProcBdArmPS();
    void ProcVsWshPS();
    void ProcSSdPS();
    void ProcWinPS();
    void ProcBdPstPS();
    void ProcStAdjPS();
    void ProcDrLthPS();
    void ProcHdlPS();
    void ProcInLtPS();
    void ProcAmLtPS();
    void ProcBdSfPS();
    void ProcCgCPS();
    void ProcCarModePS();
    void ProcACPS();
    void ProcCHSPS();
    void ProcExtLtPS();
    void ProcBdCftPS();
    void ProcBotSeatPS();
    void ProcKeyPS();

    Status StartThread();
    void WaitForShutdown();

    template <class T>
    void Subscribe(T &subscriber, const uint32_t loop_rate);

    template <class ReqDataType, class RepDataType>
    void SendAndRecv(const DDSRequesterEntity<ReqDataType, RepDataType> &requester, const ReqDataType &send_data);

private:
    static inline bool is_shutdown{false};
    std::vector<std::thread> ps_task_threads_;
    std::vector<std::thread> rr_task_threads_;
    LooperThread workThread_;

private:
    rti::core::cond::AsyncWaitSet async_waitset_;

private:
    SocketUDPServer hdbi_udp_server_;
    std::map<uint8_t, RRFUN> signal2service_map_;
    std::map<uint8_t, CASE_DATA_TYPE> case_data_type_map_;
    std::map<pair<uint8_t, uint8_t>, void *> struct_map_;

private:
    // 车身防盗
    DDSRequesterEntity<BdArm_Srv_Req_Union, BdArm_Srv_Resp_Union> BdArm_Srv_Requester_;
    DDSSubscriberEntity<BdArm_Rsp_struct> BdArm_Rsp_Subscriber_;
    DDSSubscriberEntity<BdArm_St_struct> BdArm_St_Subscriber_;
    // 视野及洗涤
    DDSRequesterEntity<VsWsh_Srv_Req_Union, VsWsh_Srv_Resp_Union> VsWsh_Srv_Requester_;
    DDSSubscriberEntity<VsWsh_Rsp_struct> VsWsh_Rsp_Subscriber_;
    DDSSubscriberEntity<VsWsh_St_struct> VsWsh_St_Subscriber_;
    // 外部声音
    DDSRequesterEntity<SSd_Srv_Req_Union, SSd_Srv_Resp_Union> SSd_Srv_Requester_;
    DDSSubscriberEntity<SSd_Rsp_struct> SSd_Rsp_Subscriber_;
    // 车窗
    DDSRequesterEntity<Win_Srv_Req_Union, Win_Srv_Resp_Union> Win_Srv_Requester_;
    DDSSubscriberEntity<Win_Rsp_struct> Win_Rsp_Subscriber_;
    DDSSubscriberEntity<Win_St_struct> Win_St_Subscriber_;
    // 车身
    DDSRequesterEntity<BdPst_Srv_Req_Union, BdPst_Srv_Resp_Union> BdPst_Srv_Requester_;
    DDSSubscriberEntity<BdPst_Rsp_struct> BdPst_Rsp_Subscriber_;
    DDSSubscriberEntity<BdPst_St_struct> BdPst_St_Subscriber_;
    // 座椅位置
    DDSRequesterEntity<StAdj_Srv_Req_Union, StAdj_Srv_Resp_Union> StAdj_Srv_Requester_;
    DDSSubscriberEntity<StAdj_St_struct> StAdj_St_Subscriber_;
    // 2.车门
    DDSRequesterEntity<DrLth_Srv_Req_Union, DrLth_Srv_Resp_Union> DrLth_Srv_Requester_;
    DDSSubscriberEntity<DrLth_Rsp_struct> DrLth_Rsp_Subscriber_;
    DDSSubscriberEntity<DrLth_St_struct> DrLth_St_Subscriber_;
    // 把手
    DDSRequesterEntity<Hdl_St_Get_struct, Hdl_St_struct> Hdl_St_Requester_;
    DDSSubscriberEntity<Hdl_St_struct> Hdl_St_Subscriber_;
    // 内灯
    DDSRequesterEntity<InLt_Srv_Req_Union, InLt_Srv_Resp_Union> InLt_Srv_Requester_;
    DDSSubscriberEntity<InLt_Rsp_struct> InLt_Rsp_Subscriber_;
    DDSSubscriberEntity<InLt_St_struct> InLt_St_Subscriber_;
    // 氛围灯
    DDSRequesterEntity<AmLt_Srv_Req_Union, AmLt_Srv_Resp_Union> AmLt_Srv_Requester_;
    DDSSubscriberEntity<AmLt_Rsp_struct> AmLt_Rsp_Subscriber_;
    // 车身安全
    DDSRequesterEntity<BdSf_Ctrl_struct, BdSf_Ctrl_SOA_struct> BdSf_Ctrl_Requester_;
    DDSSubscriberEntity<BdSf_St_struct> BdSf_St_Subscriber_;
    // 充电口
    DDSRequesterEntity<CgC_Ctrl_struct, CgC_Ctrl_SOA_struct> CgC_Ctrl_Requester_;
    DDSSubscriberEntity<CgC_St_struct> CgC_St_Subscriber_;
    // 上下电、车辆模式
    DDSRequesterEntity<VehicleMode_Srv_Req_Union, VehicleMode_Srv_Resp_Union> VehicleMode_Srv_Requester_;
    DDSSubscriberEntity<CarMode_St_struct> CarMode_St_Subscriber_;
    DDSSubscriberEntity<PowerMode_St_struct> PowerMode_St_Subscriber_;
    DDSSubscriberEntity<DringMode_St_Struct> DringMode_St_Subscriber_;
    // 空调、热管理
    DDSRequesterEntity<AC_Ctrl_struct, AC_Ctrl_SOA_struct> AC_Ctrl_Requester_;
    DDSSubscriberEntity<AC_St_struct> AC_St_Subscriber_;
    DDSSubscriberEntity<Thermal_St_struct> Thermal_St_Subscriber_;
    // 底盘、雨刮
    DDSRequesterEntity<CHS_Ctrl_struct, CHS_Ctrl_SOA_struct> CHS_Ctrl_Requester_;
    DDSSubscriberEntity<CHS_St_struct> CHS_St_Subscriber_;
    DDSSubscriberEntity<GeneralVehSt_Struct> GeneralVehSt_Subscriber_;
    DDSSubscriberEntity<PTHMI_struct> PHHMI_Subscriber_;
    DDSSubscriberEntity<CHSHMI_struct> CHSHMI_Subscriber_;
    DDSSubscriberEntity<WiperWash_Ctrl_Struct> WiperWash_Ctrl_Subscriber_;
    // 外灯
    DDSRequesterEntity<ExtLt_Ctrl_Struct, ExtLt_Ctrl_SOA_struct> ExtLt_Ctrl_Requester_;
    DDSSubscriberEntity<ExtLt_St_Struct> ExtLt_St_Subscriber_;
    // 车身舒适
    DDSRequesterEntity<BdCft_Srv_Req_Union, BdCft_Srv_Resp_Union> BdCft_Srv_Requester_;
    DDSSubscriberEntity<BdCft_St_struct> BdCft_St_Subscriber_;
    // 座椅机械臂
    DDSRequesterEntity<Bot_Srv_Req_Union, Bot_Srv_Resp_Union> Bot_Srv_Requester_;
    DDSSubscriberEntity<BotSeatSync_Rsp_struct> BotSeatSync_Subscriber_;
    DDSSubscriberEntity<BotMotion_St_struct> BotMotion_St_Subscriber_;
    // 机械臂脚本
    DDSRequesterEntity<BotScript_Ctrl_struct, BotScript_St_struct> BotScript_St_Requester_;
    // 钥匙
    DDSRequesterEntity<Key_Srv_Req_Union, Key_Srv_Resp_Union> Key_Srv_Requester_;
    DDSSubscriberEntity<NFCKeyMag_St_struct> NFCKeyMag_St_Subscriber_;
    DDSSubscriberEntity<KeyInfo_Notify_struct> KeyInfo_Notify_Subscriber_;
    // NMService
    DDSRequesterEntity<NMService_Srv_Req_Union, NMService_Srv_Resp_Union> NMService_Srv_Requester_;

private:
    strBdArm_Set strBdArm_Set_;
    strDrLth_Act strDrLth_Act_;
    // todo
};

#endif
