#include "GenerateNoReq.h"
#include <iomanip>
#include <chrono>

BdArm_Set_struct GenerateNoReq::BdArm_Set;
BdArm_Act_struct GenerateNoReq::BdArm_Act;
VsWsh_Set_struct GenerateNoReq::VsWsh_Set;
VsWsh_Act_struct GenerateNoReq:: VsWsh_Act;
Win_Set_struct GenerateNoReq:: Win_Set;
WinPct_Act_struct GenerateNoReq:: WinPct_Act;
BdPst_Set_struct GenerateNoReq:: BdPst_Set;
StAdj_Act_struct GenerateNoReq:: StAdj_Act;
BdPst_Act_struct GenerateNoReq:: BdPst_Act;
SSd_Set_struct GenerateNoReq:: SSd_Set;
DrLth_Set_struct GenerateNoReq:: DrLth_Set;
DrLth_Act_struct GenerateNoReq:: DrLth_Act;
InLt_Set_struct GenerateNoReq:: InLt_Set;
InLt_Act_struct GenerateNoReq:: InLt_Act;
AmLt_Set_struct GenerateNoReq:: AmLt_Set;
BdSf_Act_struct GenerateNoReq:: BdSf_Act;
CgC_Act_struct GenerateNoReq:: CgC_Act;
PowerModeReq_Struct GenerateNoReq:: PowerModeReq;
DrivingModeReq_Struct GenerateNoReq:: DrivingModeReq;
AC_Ctrl_struct GenerateNoReq:: AC_Ctrl;
CHSSetting_Struct GenerateNoReq:: CHSSetting;
ExtLt_Ctrl_Struct GenerateNoReq:: ExtLt_Ctrl;
BdCft_Act_struct GenerateNoReq:: BdCft_Act;

bool GenerateNoReq::GenerateNoReqComm(const unsigned char* buf) {
    uint8_t bigID = static_cast<int>(buf[8]);
    uint8_t smallID = static_cast<int>(buf[9]); 
    uint8_t signal = static_cast<int>(buf[10]);
     //time stamp
    std::cout << "enter the generate func" << std::endl;
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S") << std::endl;

    if (noReqSignalMap.find(std::make_pair(bigID, smallID)) != noReqSignalMap.end()) {
        char *pChar = static_cast<char*>(noReqSignalMap[std::make_pair(bigID, smallID)]);
        pChar[0] = buf[10];
        std::cout <<"send buf to ipcf" <<std::endl;
        std::cout << "Command: " << std::dec << static_cast<int>(buf[8]) << "-" << std::dec << static_cast<int>(buf[9]) << std::endl;
        for (int i = 0; i <= sizeof(buf); ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << (static_cast<int>(buf[i]) & 0xff) << " ";
        }
        std::cout << std::endl;
    }
}