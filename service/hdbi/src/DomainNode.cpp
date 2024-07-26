#include "DomainNode.h"

DomainNode::DomainNode() :
    async_waitset_(rti::core::cond::AsyncWaitSetProperty().thread_pool_size(10)),
    BdArm_Srv_Requester_("BdArm_Srv"),
    BdArm_Rsp_Subscriber_("BdArm_Rsp_Srv", async_waitset_),
    BdArm_St_Subscriber_("BdArm_St_Srv", async_waitset_),
    VsWsh_Srv_Requester_("VsWsh_Srv"),
    VsWsh_Rsp_Subscriber_("VsWsh_Rsp_Srv", async_waitset_),
    VsWsh_St_Subscriber_("VsWsh_St_Srv", async_waitset_),
    SSd_Srv_Requester_("SSd_Srv"),
    SSd_Rsp_Subscriber_("SSd_Rsp_Srv", async_waitset_),
    Win_Srv_Requester_("Win_Srv"),
    Win_Rsp_Subscriber_("Win_Rsp_Srv", async_waitset_),
    Win_St_Subscriber_("Win_St_Srv", async_waitset_),
    BdPst_Srv_Requester_("BdPst_Srv"),
    BdPst_Rsp_Subscriber_("BdPst_Rsp_Srv", async_waitset_),
    BdPst_St_Subscriber_("BdPst_St_Srv", async_waitset_),
    StAdj_Srv_Requester_("StAdj_Srv"),
    StAdj_St_Subscriber_("StAdj_St_Srv", async_waitset_),
    DrLth_Srv_Requester_("DrLth_Srv"),
    DrLth_Rsp_Subscriber_("DrLth_Rsp_Srv", async_waitset_),
    DrLth_St_Subscriber_("DrLth_St_Srv", async_waitset_),
    Hdl_St_Requester_("Hdl_St_Get_Srv"),
    Hdl_St_Subscriber_("Hdl_St_Srv", async_waitset_),
    InLt_Srv_Requester_("InLt_Srv"),
    InLt_Rsp_Subscriber_("InLt_Rsp_Srv", async_waitset_),
    InLt_St_Subscriber_("InLt_St_Srv", async_waitset_),
    AmLt_Srv_Requester_("AmLt_Srv"),
    AmLt_Rsp_Subscriber_("AmLt_Rsp_Srv", async_waitset_),
    BdSf_Ctrl_Requester_("BdSf_Ctrl_Srv"),
    BdSf_St_Subscriber_("BdSf_St_Srv", async_waitset_),
    CgC_Ctrl_Requester_("CgC_Ctrl_Srv"),
    CgC_St_Subscriber_("CgC_St_Srv", async_waitset_),
    VehicleMode_Srv_Requester_("VehicleMode_Srv"),
    CarMode_St_Subscriber_("CarMode_St_Srv", async_waitset_),
    PowerMode_St_Subscriber_("PowerMode_St_Srv", async_waitset_),
    DringMode_St_Subscriber_("DringMode_St_Srv", async_waitset_),
    AC_Ctrl_Requester_("AC_Ctrl_Srv"),
    AC_St_Subscriber_("AC_St_Srv", async_waitset_),
    Thermal_St_Subscriber_("Thermal_St_Srv", async_waitset_),
    CHS_Ctrl_Requester_("CHS_Ctrl_Srv"),
    CHS_St_Subscriber_("CHS_St_Srv", async_waitset_),
    GeneralVehSt_Subscriber_("GeneralVehSt_Srv", async_waitset_),
    PHHMI_Subscriber_("PTHMI_Srv", async_waitset_),
    CHSHMI_Subscriber_("CHSHMI_Srv", async_waitset_),
    WiperWash_Ctrl_Subscriber_("WiperWash_Ctrl_Srv", async_waitset_),
    ExtLt_Ctrl_Requester_("ExtLt_Ctrl_Srv"),
    ExtLt_St_Subscriber_("ExtLt_St_Srv", async_waitset_),
    BdCft_Srv_Requester_("BdCft_Srv"),
    BdCft_St_Subscriber_("BdCft_St_Srv", async_waitset_),
    Bot_Srv_Requester_("Bot_Srv"),
    BotSeatSync_Subscriber_("BotSeatSync_Rsp_Srv", async_waitset_),
    BotMotion_St_Subscriber_("BotMotion_St_Srv", async_waitset_),
    BotScript_St_Requester_("BotScript_Srv"),
    Key_Srv_Requester_("Key_Srv"),
    NFCKeyMag_St_Subscriber_("NFCKeyMag_St_Srv", async_waitset_),
    KeyInfo_Notify_Subscriber_("KeyInfo_Notify_Srv", async_waitset_) {
    HHT_LOG(INFO) << "Start waitset";
    async_waitset_.start();
}

Status DomainNode::ParseCMDLine() {
    std::vector<std::string> cmd_str;
    while (!is_shutdown) {
        std::string cmd_line;
        std::getline(std::cin, cmd_line);
        cmd_str.clear();
        cmd_str = common::util::split(cmd_line, ",");
        if (cmd_str.size() < 2 || cmd_str.size() > 3) {
            HHT_LOG(INFO) << "错误指令";
            continue;
        }
        int code = std::stoi(cmd_str.front());
        int sub_code = std::stoi(cmd_str.back());
        if (code < 0 || code > UCHAR_MAX || sub_code < 0 || sub_code > UCHAR_MAX) {
            HHT_LOG(INFO) << "错误指令";
            continue;
        }
    }
    RETURN_STATUS_OK();
}

Status DomainNode::Init() {
    InitSignalMap();
    if (!InitSocket()) {
        RETURN_STATUS(Status("Failed to init socket"));
    }
    RETURN_STATUS_OK();
}

Status DomainNode::ReadModuleConf() {
    // todo
    RETURN_STATUS_OK();
}

Status DomainNode::Step() {
    Init();
    ReadModuleConf();

    // ProcBdArmPS();
    // ProcVsWshPS();
    // ProcSSdPS();
    // ProcWinPS();
    // ProcBdPstPS();

    RETURN_STATUS_OK();
}

bool DomainNode::InitSocket() {
    unsigned short port = static_cast<unsigned short>(PORT);
    if (hdbi_udp_server_.Init(port) && hdbi_udp_server_.Bind()) {
        return true;
    } else {
        return false;
    }
}

Status DomainNode::RecvPadSignalViaSocket() {
    char buff[BUFFSIZE]{'0'};
    size_t recv_len = sizeof(buff);
    while (recv_len) {
        if (hdbi_udp_server_.ReceivePackage(buff, recv_len)) {
            ParsePadSignal(buff);
        } else {
            RETURN_STATUS(Status("Failed to Receive Package via socket"));
        }
    }
    RETURN_STATUS_OK();
}

Status DomainNode::ParsePadSignal(const char *buff) {
    uint8_t big_id = static_cast<uint8_t>(buff[8]);
    uint8_t small_id = static_cast<uint8_t>(buff[9]);
    uint8_t signal_value = static_cast<uint8_t>(buff[10]);
    // debug
    // HHT_LOG(INFO) << std::to_string(big_id) << "," << std::to_string(small_id) << "," << std::to_string(signal_value);
    auto it = signal2service_map_.find(big_id);
    if (it != signal2service_map_.end()) {
        auto type_iter = case_data_type_map_.find(big_id);
        if (type_iter != case_data_type_map_.end()) {
            // 根据发送过来的大小id，直接给struct的变量赋值好，然后调用发送函数
            // 解析大小id，赋值结构体的变量值
            if (ParseIdAndSetData(big_id, small_id, signal_value)) {
                (this->*it->second)(type_iter->second, small_id, signal_value);
                RETURN_STATUS_OK();
            } else {
                RETURN_STATUS(Status("parser ID error"));
            }
        } else {
            RETURN_STATUS(Status("can not find data type"));
        }
    } else {
        RETURN_STATUS(Status("can not find big id"));
    }
}

bool DomainNode::ParseIdAndSetData(const uint8_t big_id, const uint8_t small_id, const uint8_t value) {
    auto iter = struct_map_.find(pair<uint8_t, uint8_t>(big_id, small_id));
    if (iter != struct_map_.end()) {
        uint8_t *data = static_cast<uint8_t *>(iter->second);
        *data = value;
        return true;
    } else {
        return false;
    }
}

Status DomainNode::SendSignal2PadViaSocket() {
    RETURN_STATUS_OK();
}

Status DomainNode::StartThread() {
    // workThread_.looper().postTask(std::bind(&DomainNode::onProcRR, this));
    // workThread_.start();
    RETURN_STATUS_OK();
}

void DomainNode::WaitForShutdown() {
    while (!is_shutdown) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    HHT_LOG(INFO) << "app_hdbi will close in 2 seconds";
    sleep(2);
    exit(0);
}

template <class T>
void DomainNode::Subscribe(T &subscriber, const uint32_t loop_rate) {
    while (!is_shutdown) {
        auto samples = subscriber.Get();
        for (const auto &sample : samples) {
            if (sample.info().valid()) {
                HHT_LOG(INFO) << sample.data();
            }
        }
        rti::util::sleep(dds::core::Duration::from_millisecs(loop_rate));
    }
}

template <class ReqDataType, class RepDataType>
void DomainNode::SendAndRecv(const DDSRequesterEntity<ReqDataType, RepDataType> &requester, const ReqDataType &send_data) {
    requester.SendRequest(send_data);
    auto recv_reply = requester.RecvReply();
    if (0 < recv_reply.length()) {
        for (const auto &reply : recv_reply) {
            if (!reply.info().valid()) {
                continue;
            }
            // debug
            HHT_LOG(INFO) << reply.data();
        }
    } else {
        HHT_LOG(INFO) << "recv NO data";
    }
}

void DomainNode::onProcDrLthRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcDrLthRR...";
    DrLth_Srv_Req_Union DrLth_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::DrLth_Set_struct__:
        DrLth_Srv_Req._d(0);
        DrLth_Srv_Req.DrLth_Set(DrLth_Set_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::DrLth_Ctrl_struct__:
        DrLth_Srv_Req._d(1);
        DrLth_Srv_Req.DrLth_Get(DrLth_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::BdArm_Set_struct__:
        DrLth_Srv_Req._d(2);
        DrLth_Srv_Req.DrLth_Ctrl(DrLth_Ctrl_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::BdArm_Ctrl_struct__:
        DrLth_Srv_Req._d(3);
        DrLth_Srv_Req.DrLth_St_Get(DrLth_St_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    }

    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<DrLth_Srv_Req_Union, DrLth_Srv_Resp_Union>(DrLth_Srv_Requester_, DrLth_Srv_Req);
    }
}

#if 0

void DomainNode::onProcBdArmRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcBdArmRR...";
    BdArm_Srv_Req_Union BdArm_Srv_req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::BdArm_Set_struct:
        BdArm_Srv_req._d(0);
        BdArm_Srv_req.BdArm_Set(tmp);
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        BdArm_Srv_req._d(1);
        BdArm_Srv_req.BdArm_Get(BdArm_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE2:
        BdArm_Srv_req._d(2);
        BdArm_Srv_req.BdArm_Get(BdArm_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE3:
        BdArm_Srv_req._d(3);
        BdArm_Srv_req.BdArm_Get(BdArm_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<BdArm_Srv_Req_Union, BdArm_Srv_Resp_Union>(BdArm_Srv_Requester_, BdArm_Srv_req);
    }
}



void DomainNode::onProcVsWshRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcVsWshRR...";
    VsWsh_Srv_Req_Union VsWsh_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        VsWsh_Srv_Req._d(0);
        VsWsh_Srv_Req.VsWsh_Set(VsWsh_Set_struct(0x2, 0x2, "0x2"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        VsWsh_Srv_Req._d(1);
        VsWsh_Srv_Req.VsWsh_Get(VsWsh_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE2:
        VsWsh_Srv_Req._d(2);
        VsWsh_Srv_Req.VsWsh_Ctrl(VsWsh_Ctrl_struct(0x2, 0x2, 0x2, "0x2"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE3:
        VsWsh_Srv_Req._d(3);
        VsWsh_Srv_Req.VsWsh_St_Get(VsWsh_St_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    }

    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<VsWsh_Srv_Req_Union, VsWsh_Srv_Resp_Union>(VsWsh_Srv_Requester_, VsWsh_Srv_Req);
    }
}

void DomainNode::onProcSSdRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcSSdRR...";
    SSd_Srv_Req_Union SSd_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        SSd_Srv_Req._d(0);
        SSd_Srv_Req.SSd_Set(SSd_Set_struct(0x2, 0x2, "0x2"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        SSd_Srv_Req._d(1);
        SSd_Srv_Req.SSd_Get(SSd_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<SSd_Srv_Req_Union, SSd_Srv_Resp_Union>(SSd_Srv_Requester_, SSd_Srv_Req);
    }
}

void DomainNode::onProcWinRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcWinRR...";
    Win_Srv_Req_Union Win_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        Win_Srv_Req._d(0);
        Win_Srv_Req.Win_Set(Win_Set_struct(0x2, 0x2, "0x2"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        Win_Srv_Req._d(1);
        Win_Srv_Req.Win_Get(Win_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE2:
        Win_Srv_Req._d(2);
        Win_Srv_Req.WinPct_Ctrl(WinPct_Ctrl_struct(0xFE, 0xFE, 0xFE, 0xFE, 0xFE, "0xFE"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE3:
        Win_Srv_Req._d(3);
        Win_Srv_Req.Win_St_Get(Win_St_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<Win_Srv_Req_Union, Win_Srv_Resp_Union>(Win_Srv_Requester_, Win_Srv_Req);
    }
}

void DomainNode::onProcBdPstRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcBdPstRR...";
    BdPst_Srv_Req_Union BdPst_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        BdPst_Srv_Req._d(0);
        BdPst_Srv_Req.BdPst_Set(BdPst_Set_struct(0x2, 0x2, 0x2, 0x2, 0x1, "0x1"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        BdPst_Srv_Req._d(1);
        BdPst_Srv_Req.BdPst_Get(BdPst_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE2:
        BdPst_Srv_Req._d(2);
        BdPst_Srv_Req.BdPst_Ctrl(BdPst_Ctrl_struct(2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, "2"));

        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE3:
        BdPst_Srv_Req._d(3);
        BdPst_Srv_Req.BdPst_St_Get(BdPst_St_Get_struct(3, "3"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE4:
        BdPst_Srv_Req._d(4);
        dds::core::array<BodyDomain::FRSeatMemPst_Req_struct, 5L> fl_seat{FRSeatMemPst_Req_struct(0x0, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x1)};
        dds::core::array<BodyDomain::FRSeatMemPst_Req_struct, 4L> fr_seat{FRSeatMemPst_Req_struct(0x0, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x1)};
        dds::core::array<BodyDomain::SRLSeatMemPst_Req_struct, 2L> srl_seat{SRLSeatMemPst_Req_struct(0x0, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE)};
        dds::core::array<BodyDomain::SRRSeatMemPst_Req_struct, 2L> srr_seat{SRRSeatMemPst_Req_struct(0x0, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE)};
        dds::core::array<BodyDomain::SteerMemPst_Req_struct, 5L> steer{SteerMemPst_Req_struct(0x0, 0xFE, 0xFE)};
        dds::core::array<BodyDomain::LExMirMemLRPst_Req_struct, 8L> lexmir{LExMirMemLRPst_Req_struct(0x0, 0xFE, 0xFE)};
        dds::core::array<BodyDomain::RExMirMemLRPst_Req_struct, 8L> rexmir{RExMirMemLRPst_Req_struct(0x0, 0xFE, 0xFE)};
        BdPst_Srv_Req.BdMemPst_Set(BdMemPst_Set_struct(fl_seat, fr_seat, srl_seat, srr_seat, steer, lexmir, rexmir));
        is_set_data = true;
        break;
        // todo
        // case CASE_DATA_TYPE::CASE_DATA_TYPE5:
        //     BdPst_Srv_Req._d(5);
        //     BdPst_Srv_Req.BdMemPst_Get(BdMemPst_Get_struct(0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1));
        //     is_set_data = true;
        //     break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<BdPst_Srv_Req_Union, BdPst_Srv_Resp_Union>(BdPst_Srv_Requester_, BdPst_Srv_Req);
    }
}

void DomainNode::onProcStAdjRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcStAdjRR...";
    StAdj_Srv_Req_Union StAdj_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        StAdj_Srv_Req._d(0);
        StAdj_Srv_Req.StAdj_Ctrl(StAdj_Ctrl_struct(0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2,
                                                   0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, "0x2"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        StAdj_Srv_Req._d(1);
        StAdj_Srv_Req.StAdj_St_Get(StAdj_St_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<StAdj_Srv_Req_Union, StAdj_Srv_Resp_Union>(StAdj_Srv_Requester_, StAdj_Srv_Req);
    }
}



void DomainNode::onProcHdlRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcHdlRR...";
    Hdl_St_Get_struct DrLth_Srv_Req;
    bool is_set_data = true;

    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<Hdl_St_Get_struct, Hdl_St_struct>(DrLth_Srv_Requester_, DrLth_Srv_Req);
    }
}

void DomainNode::onProcInLtRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcInLtRR...";
    InLt_Srv_Req_Union InLt_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        InLt_Srv_Req._d(0);
        InLt_Srv_Req.DrLth_Set(InLt_Set_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        InLt_Srv_Req._d(1);
        InLt_Srv_Req.DrLth_Get(InLt_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE2:
        InLt_Srv_Req._d(2);
        InLt_Srv_Req.DrLth_Ctrl(InLt_Ctrl_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE3:
        InLt_Srv_Req._d(3);
        InLt_Srv_Req.DrLth_St_Get(InLt_St_Get_struct(0xFF, "0xFF"));
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<InLt_Srv_Req_Union, InLt_Srv_Resp_Union>(InLt_Srv_Requester_, InLt_Srv_Req);
    }
}

void DomainNode::onProcAmLtRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcAmLtRR...";
    AmLt_Srv_Req_Union AmLt_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        AmLt_Srv_Req._d(0);
        AmLt_Srv_Req.AmLt_Set(AmLt_Set_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        AmLt_Srv_Req._d(1);
        AmLt_Srv_Req.AmLt_Get(AmLt_Get_struct());
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<AmLt_Srv_Req_Union, AmLt_Srv_Resp_Union>(AmLt_Srv_Requester_, AmLt_Srv_Req);
    }
}

void DomainNode::onProcBdSfRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcBdSfRR...";
    BdSf_Ctrl_struct BdSf_Ctrl_Req;
    bool is_set_data = true;

    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<BdSf_Ctrl_struct, BdSf_Ctrl_SOA_struct>(BdSf_Ctrl_Requester_, BdSf_Ctrl_Req);
    }
}

void DomainNode::onProcCgCRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcCgCRR...";
    CgC_Ctrl_struct CgC_Ctrl_Req;
    bool is_set_data = true;

    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<CgC_Ctrl_struct, CgC_Ctrl_SOA_struct>(CgC_Ctrl_Requester_, CgC_Ctrl_Req);
    }
}

void DomainNode::onProcVehicleModeRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcVehicleModeRR...";
    VehicleMode_Srv_Req_Union VehicleMode_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        VehicleMode_Srv_Req._d(0);
        VehicleMode_Srv_Req.PowerMode_Ctrl(PowerMode_Ctrl_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        VehicleMode_Srv_Req._d(1);
        VehicleMode_Srv_Req.CarMode_Ctrl(CarMode_Ctrl_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE2:
        VehicleMode_Srv_Req._d(2);
        VehicleMode_Srv_Req.DrivingMode_Ctrl(DrivingMode_Ctrl_struct());
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<VehicleMode_Srv_Req_Union, VehicleMode_Srv_Resp_Union>(VehicleMode_Srv_Requester_, VehicleMode_Srv_Req);
    }
}

void DomainNode::onProcACRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcACRR...";
    AC_Ctrl_struct AC_Ctrl_Req;
    bool is_set_data = true;

    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<AC_Ctrl_struct, AC_Ctrl_SOA_struct>(AC_Ctrl_Requester_, AC_Ctrl_Req);
    }
}

void DomainNode::onProcCHSRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcCHSRR...";
    CHS_Ctrl_struct CHS_Ctrl_Req;
    bool is_set_data = true;

    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<CHS_Ctrl_struct, CHS_Ctrl_SOA_struct>(CHS_Ctrl_Requester_, CHS_Ctrl_Req);
    }
}

void DomainNode::onProcExtLtRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcExtLtRR...";
    ExtLt_Ctrl_Struct ExtLt_Ctrl_Req;
    bool is_set_data = true;

    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<VehicleMode_Srv_Req_Union, VehicleMode_Srv_Resp_Union>(VehicleMode_Srv_Requester_, ExtLt_Ctrl_Req);
    }
}

void DomainNode::onProcBdCftRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcBdCftRR...";
    BdCft_Srv_Req_Union BdCft_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        BdCft_Srv_Req._d(0);
        BdCft_Srv_Req.BdCft_Ctrl(BdCft_Ctrl_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        BdCft_Srv_Req._d(1);
        BdCft_Srv_Req.BdCft_St_Get(BdCft_St_Get_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE2:
        BdCft_Srv_Req._d(2);
        BdCft_Srv_Req.BdCft_Set(BdCft_Set_struct());
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<BdCft_Srv_Req_Union, BdCft_Srv_Resp_Union>(BdCft_Srv_Requester_, BdCft_Srv_Req);
    }
}

void DomainNode::onProcBotRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcBotRR...";
    Bot_Srv_Req_Union Bot_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        Bot_Srv_Req._d(0);
        Bot_Srv_Req.BotSeatSync_Set(BotSeatSync_Set_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        Bot_Srv_Req._d(1);
        Bot_Srv_Req.BotSeatSync_Get(BotSeatSync_Get_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE2:
        Bot_Srv_Req._d(2);
        Bot_Srv_Req.BotMotion_Ctrl(BotMotion_Ctrl_struct());
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<Bot_Srv_Req_Union, Bot_Srv_Resp_Union>(Bot_Srv_Requester_, Bot_Srv_Req);
    }
}

void DomainNode::onProcBotScriptRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcBotScriptRR...";
    BotScript_Ctrl_struct BotScript_Ctrl_Req;
    bool is_set_data = true;

    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<BotScript_Ctrl_struct, BotScript_St_struct>(BotScript_St_Requester_, BotScript_Ctrl_Req);
    }
}

void DomainNode::onProcKeyRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcBotRR...";
    Key_Srv_Req_Union Key_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        Key_Srv_Req._d(0);
        Key_Srv_Req.DKLst_Get(DKLst_Get_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        Key_Srv_Req._d(1);
        Key_Srv_Req.NFCKeyLst_Get(NFCKeyLst_Get_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE2:
        Key_Srv_Req._d(2);
        Key_Srv_Req.NFCKeyRename_Set(NFCKeyRename_Set_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE3:
        Key_Srv_Req._d(3);
        Key_Srv_Req.PhysicalKeyLst_Get(PhysicalKeyLst_Get_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE4:
        Key_Srv_Req._d(4);
        Key_Srv_Req.NFCKeyMag_Crtl(NFCKeyMag_Crtl_struct());
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<Key_Srv_Req_Union, Key_Srv_Resp_Union>(Key_Srv_Requester_, Bot_Srv_Req);
    }
}

void DomainNode::onProcNMServiceRR(const CASE_DATA_TYPE data_type, const uint8_t small_id, const uint8_t signal) {
    HHT_LOG(INFO) << "onProcNMServiceRR...";
    NMService_Srv_Req_Union NMService_Srv_Req;
    bool is_set_data = false;
    switch (data_type) {
    case CASE_DATA_TYPE::CASE_DATA_TYPE0:
        NMService_Srv_Req._d(0);
        NMService_Srv_Req.NMService_Set(NMService_Set_struct());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE1:
        NMService_Srv_Req._d(1);
        NMService_Srv_Req.NmXService_Ctrl(NmXService_Ctrl_Array());
        is_set_data = true;
        break;
    case CASE_DATA_TYPE::CASE_DATA_TYPE2:
        NMService_Srv_Req._d(2);
        NMService_Srv_Req.NmService_Get(NmService_Get_struct());
        is_set_data = true;
        break;
    }
    if (!is_set_data) {
        return;
    } else {
        SendAndRecv<NMService_Srv_Req_Union, NMService_Srv_Resp_Union>(NMService_Srv_Requester_, Bot_Srv_Req);
    }
}

void DomainNode::ProcBdArmPS() {
    std::thread proc_BdArm_Rsp([this]() {
        Subscribe<DDSSubscriberEntity<BdArm_Rsp_struct>>(BdArm_Rsp_Subscriber_, LOOP_RATE);
    });
    proc_BdArm_Rsp.detach();
    ps_task_threads_.push_back(std::move(proc_BdArm_Rsp));

    std::thread proc_BdArm_St([this]() {
        Subscribe<DDSSubscriberEntity<BdArm_St_struct>>(BdArm_St_Subscriber_, LOOP_RATE);
    });
    proc_BdArm_St.detach();
    ps_task_threads_.push_back(std::move(proc_BdArm_St));
}

void DomainNode::ProcVsWshPS() {
    std::thread proc_VsWsh_Rsp([this]() {
        Subscribe<DDSSubscriberEntity<VsWsh_Rsp_struct>>(VsWsh_Rsp_Subscriber_, LOOP_RATE);
    });
    proc_VsWsh_Rsp.detach();
    ps_task_threads_.push_back(std::move(proc_VsWsh_Rsp));

    std::thread proc_VsWsh_St([this]() {
        Subscribe<DDSSubscriberEntity<VsWsh_St_struct>>(VsWsh_St_Subscriber_, LOOP_RATE);
    });
    proc_VsWsh_St.detach();
    ps_task_threads_.push_back(std::move(proc_VsWsh_St));
}

void DomainNode::ProcSSdPS() {
    std::thread proc_SSd_Rsp([this]() {
        Subscribe<DDSSubscriberEntity<SSd_Rsp_struct>>(SSd_Rsp_Subscriber_, LOOP_RATE);
    });
    proc_SSd_Rsp.detach();
    ps_task_threads_.push_back(std::move(proc_SSd_Rsp));
}

void DomainNode::ProcWinPS() {
    std::thread proc_Win_Rsp([this]() {
        Subscribe<DDSSubscriberEntity<Win_Rsp_struct>>(Win_Rsp_Subscriber_, LOOP_RATE);
    });
    proc_Win_Rsp.detach();
    ps_task_threads_.push_back(std::move(proc_Win_Rsp));

    std::thread proc_Win_St([this]() {
        Subscribe<DDSSubscriberEntity<Win_St_struct>>(Win_St_Subscriber_, LOOP_RATE);
    });
    proc_Win_St.detach();
    ps_task_threads_.push_back(std::move(proc_Win_St));
}

void DomainNode::ProcBdPstPS() {
    std::thread proc_BdPst_Rsp([this]() {
        Subscribe<DDSSubscriberEntity<BdPst_Rsp_struct>>(BdPst_Rsp_Subscriber_, LOOP_RATE);
    });
    proc_BdPst_Rsp.detach();
    ps_task_threads_.push_back(std::move(proc_BdPst_Rsp));

    std::thread proc_BdPst_St([this]() {
        Subscribe<DDSSubscriberEntity<BdPst_St_struct>>(BdPst_St_Subscriber_, LOOP_RATE);
    });
    proc_BdPst_St.detach();
    ps_task_threads_.push_back(std::move(proc_BdPst_St));
}

void DomainNode::ProcStAdjPS() {
    std::thread proc_StAdj_St([this]() {
        Subscribe<DDSSubscriberEntity<StAdj_St_struct>>(StAdj_St_Subscriber_, LOOP_RATE);
    });
    proc_StAdj_St.detach();
    ps_task_threads_.push_back(std::move(proc_StAdj_St));
}

void DomainNode::ProcDrLthPS() {
    std::thread proc_DrLth_Rsp([this]() {
        Subscribe<DDSSubscriberEntity<DrLth_Rsp_struct>>(DrLth_Rsp_Subscriber_, LOOP_RATE);
    });
    proc_DrLth_Rsp.detach();
    ps_task_threads_.push_back(std::move(proc_DrLth_Rsp));

    std::thread proc_DrLth_St([this]() {
        Subscribe<DDSSubscriberEntity<DrLth_St_struct>>(DrLth_St_Subscriber_, LOOP_RATE);
    });
    proc_DrLth_St.detach();
    ps_task_threads_.push_back(std::move(proc_DrLth_St));
}

void DomainNode::ProcHdlPS() {
    std::thread proc_Hdl_St([this]() {
        Subscribe<DDSSubscriberEntity<Hdl_St_struct>>(Hdl_St_Subscriber_, LOOP_RATE);
    });
    proc_Hdl_St.detach();
    ps_task_threads_.push_back(std::move(proc_Hdl_St));
}

void DomainNode::ProcInLtPS() {
    std::thread proc_InLt_Rsp([this]() {
        Subscribe<DDSSubscriberEntity<InLt_Rsp_struct>>(InLt_Rsp_Subscriber_, LOOP_RATE);
    });
    proc_InLt_Rsp.detach();
    ps_task_threads_.push_back(std::move(proc_InLt_Rsp));

    std::thread proc_InLt_St([this]() {
        Subscribe<DDSSubscriberEntity<InLt_St_struct>>(InLt_St_Subscriber_, LOOP_RATE);
    });
    proc_InLt_St.detach();
    ps_task_threads_.push_back(std::move(proc_InLt_St));
}

void DomainNode::ProcAmLtPS() {
    std::thread proc_AmLt_Rsp([this]() {
        Subscribe<DDSSubscriberEntity<AmLt_Rsp_struct>>(AmLt_Rsp_Subscriber_, LOOP_RATE);
    });
    proc_AmLt_Rsp.detach();
    ps_task_threads_.push_back(std::move(proc_AmLt_Rsp));
}

void DomainNode::ProcBdSfPS() {
    std::thread proc_BdSf_St([this]() {
        Subscribe<DDSSubscriberEntity<BdSf_St_struct>>(BdSf_St_Subscriber_, LOOP_RATE);
    });
    proc_BdSf_St.detach();
    ps_task_threads_.push_back(std::move(proc_BdSf_St));
}

void DomainNode::ProcCgCPS() {
    std::thread proc_CgC_St([this]() {
        Subscribe<DDSSubscriberEntity<CgC_St_struct>>(CgC_St_Subscriber_, LOOP_RATE);
    });
    proc_CgC_St.detach();
    ps_task_threads_.push_back(std::move(proc_CgC_St));
}

void DomainNode::ProcCarModePS() {
    std::thread proc_CarMode_St([this]() {
        Subscribe<DDSSubscriberEntity<CarMode_St_struct>>(CarMode_St_Subscriber_, LOOP_RATE);
    });
    proc_CarMode_St.detach();
    ps_task_threads_.push_back(std::move(proc_CarMode_St));

    std::thread proc_PowerMode_St([this]() {
        Subscribe<DDSSubscriberEntity<PowerMode_St_struct>>(PowerMode_St_Subscriber_, LOOP_RATE);
    });
    proc_PowerMode_St.detach();
    ps_task_threads_.push_back(std::move(proc_PowerMode_St));

    std::thread proc_DringMode_St([this]() {
        Subscribe<DDSSubscriberEntity<DringMode_St_Struct>>(DringMode_St_Subscriber_, LOOP_RATE);
    });
    proc_DringMode_St.detach();
    ps_task_threads_.push_back(std::move(proc_DringMode_St));
}

void DomainNode::ProcACPS() {
    std::thread proc_AC_St([this]() {
        Subscribe<DDSSubscriberEntity<AC_St_struct>>(AC_St_Subscriber_, LOOP_RATE);
    });
    proc_AC_St.detach();
    ps_task_threads_.push_back(std::move(proc_AC_St));

    std::thread proc_Thermal_St([this]() {
        Subscribe<DDSSubscriberEntity<Thermal_St_struct>>(Thermal_St_Subscriber_, LOOP_RATE);
    });
    proc_Thermal_St.detach();
    ps_task_threads_.push_back(std::move(proc_Thermal_St));
}

void DomainNode::ProcCHSPS() {
    std::thread proc_CHS_St([this]() {
        Subscribe<DDSSubscriberEntity<CHS_St_struct>>(CHS_St_Subscriber_, LOOP_RATE);
    });
    proc_CHS_St.detach();
    ps_task_threads_.push_back(std::move(proc_CHS_St));

    std::thread proc_GeneralVehSt([this]() {
        Subscribe<DDSSubscriberEntity<GeneralVehSt_Struct>>(GeneralVehSt_Subscriber_, LOOP_RATE);
    });
    proc_GeneralVehSt.detach();
    ps_task_threads_.push_back(std::move(proc_GeneralVehSt));

    std::thread proc_PTHMI([this]() {
        Subscribe<DDSSubscriberEntity<PTHMI_struct>>(PHHMI_Subscriber_, LOOP_RATE);
    });
    proc_PTHMI.detach();
    ps_task_threads_.push_back(std::move(proc_PTHMI));

    std::thread proc_CHSHMI([this]() {
        Subscribe<DDSSubscriberEntity<CHSHMI_struct>>(CHSHMI_Subscriber_, LOOP_RATE);
    });
    proc_CHSHMI.detach();
    ps_task_threads_.push_back(std::move(proc_CHSHMI));

    std::thread proc_WiperWash([this]() {
        Subscribe<DDSSubscriberEntity<WiperWash_Ctrl_Struct>>(WiperWash_Ctrl_Subscriber_, LOOP_RATE);
    });
    proc_WiperWash.detach();
    ps_task_threads_.push_back(std::move(proc_WiperWash));
}

void DomainNode::ProcExtLtPS() {
    std::thread proc_ExtLt_St([this]() {
        Subscribe<DDSSubscriberEntity<ExtLt_St_Struct>>(ExtLt_St_Subscriber_, LOOP_RATE);
    });
    proc_ExtLt_St.detach();
    ps_task_threads_.push_back(std::move(proc_ExtLt_St));
}

void DomainNode::ProcBdCftPS() {
    std::thread proc_BdCft_St([this]() {
        Subscribe<DDSSubscriberEntity<BdCft_St_struct>>(BdCft_St_Subscriber_, LOOP_RATE);
    });
    proc_BdCft_St.detach();
    ps_task_threads_.push_back(std::move(proc_BdCft_St));
}

void DomainNode::ProcBotSeatPS() {
    std::thread proc_BotSeatSync_Rsp([this]() {
        Subscribe<DDSSubscriberEntity<BotSeatSync_Rsp_struct>>(BotSeatSync_Subscriber_, LOOP_RATE);
    });
    proc_BotSeatSync_Rsp.detach();
    ps_task_threads_.push_back(std::move(proc_BotSeatSync_Rsp));

    std::thread proc_BotMotion_St([this]() {
        Subscribe<DDSSubscriberEntity<BotMotion_St_struct>>(BotMotion_St_Subscriber_, LOOP_RATE);
    });
    proc_BotMotion_St.detach();
    ps_task_threads_.push_back(std::move(proc_BotMotion_St));
}

void DomainNode::ProcKeyPS() {
    std::thread proc_NFCKeyMag_St([this]() {
        Subscribe<DDSSubscriberEntity<NFCKeyMag_St_struct>>(NFCKeyMag_St_Subscriber_, LOOP_RATE);
    });
    proc_NFCKeyMag_St.detach();
    ps_task_threads_.push_back(std::move(proc_NFCKeyMag_St));

    std::thread proc_KeyInfo_Notify([this]() {
        Subscribe<DDSSubscriberEntity<KeyInfo_Notify_struct>>(KeyInfo_Notify_Subscriber_, LOOP_RATE);
    });
    proc_KeyInfo_Notify.detach();
    ps_task_threads_.push_back(std::move(proc_KeyInfo_Notify));
}
#endif

void DomainNode::InitSignalMap() {
    signal2service_map_.insert(pair<uint8_t, RRFUN>(1, &DomainNode::onProcDrLthRR));
    signal2service_map_.insert(pair<uint8_t, RRFUN>(2, &DomainNode::onProcDrLthRR));
    // signal2service_map_.insert(pair<uint8_t, RRFUN>(5, &DomainNode::onProcBdArmRR));
    // signal2service_map_.insert(pair<uint8_t, RRFUN>(6, &DomainNode::onProcBdArmRR));

    struct_map_.insert(pair(pair<uint8_t, uint8_t>(5, 0), &strBdArm_Set_.VehicleUnlock_Set));
    // struct_map_.insert(std::make_pair<uint8_t, uint8_t>(5, 1), &BdArm_Set_struct_.ReturnPUnlock_Set);
    // struct_map_.insert(std::make_pair<uint8_t, uint8_t>(2, 0), &DrLth_Ctrl_struct.TDoorBtn_Act);
    // struct_map_.insert(std::make_pair<uint8_t, uint8_t>(2, 1), &DrLth_Ctrl_struct.TDoorPos_Act);
    // struct_map_.insert(std::make_pair<uint8_t, uint8_t>(2, 2), &DrLth_Ctrl_struct.FLDoorBtn_Act);
    // struct_map_.insert(std::make_pair<uint8_t, uint8_t>(2, 3), &DrLth_Ctrl_struct.RLDoorBtn_Act);
    // struct_map_.insert(std::make_pair<uint8_t, uint8_t>(2, 4), &DrLth_Ctrl_struct.FRDoorBtn_Act);
    // struct_map_.insert(std::make_pair<uint8_t, uint8_t>(2, 5), &DrLth_Ctrl_struct.RRDoorBtn_Act);
}
