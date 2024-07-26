#include <ppscontrol.h>
#include <unistd.h>

#include <iostream>

#include "glog/logging.h"

#include "DsvPpsIfStruct.h"

static DESY::PPS_CFG_EXX_STRU ppscfg[] = {
    DESY::PPS_CFG_EXX_STRU{Dsvpps::E_PowerMgmtMsgIpc_Array, "PowerMgmtMsgIpc_Array ", 32, 1, 0, 1,
                           sizeof(Dsvpps::PowerMgmtMsg_Array), 0, 0, MSG_BLOCKWAIT},
};

static DESY::ppscontrol* sPpsCtrl = nullptr;

int main(int argc, char** argv) {
    sPpsCtrl = DESY::ppscontrol::Instance(ppscfg, sizeof(ppscfg) / sizeof(DESY::PPS_CFG_EXX_STRU));
    uint8_t* data = new uint8_t[128];
    data[0] = 0x00;
    data[1] = 0x00;
    for (int i = 0;; i++) {
        data[4] = 0x01 + !(i % 2);
        sPpsCtrl->send(Dsvpps::E_PowerMgmtMsgIpc_Array, 0, sizeof(Dsvpps::PowerMgmtMsg_Array), data);
        LOG(INFO) << "Power State: " << ((i % 2) ? "On" : "Off");
        sleep(5);
    }
    delete[] data;

    return 0;
}
