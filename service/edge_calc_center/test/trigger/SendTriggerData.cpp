#include <iostream>

#include <unistd.h>
#include <vector>

#include <ppscontrol.h>

#include "DsvPpsIfStruct.h"


struct TriggerTest {
    int test_int;
    // int test_int2;
    // int test_int3;
};

constexpr int E_TriggerTest = 9999;

static DESY::ppscontrol *m_ppsctrl = nullptr;

static DESY::PPS_CFG_EXX_STRU g_ppscfg[] = {
    DESY::PPS_CFG_EXX_STRU { E_TriggerTest, "TriggerTest", 32, 0, 1, 1, sizeof(TriggerTest), 0, 0, MSG_BLOCKWAIT},
    DESY::PPS_CFG_EXX_STRU { Dsvpps::E_DataLogging4, "DataLogging4", 32, 0, 1, 1, sizeof(Dsvpps::DataLogging4), 0, 0, MSG_BLOCKWAIT},

};

class Dispatcher : public DESY::HalSubInterface {
public:
    Dispatcher() {
        int counter = 0;
    }

    ~Dispatcher() = default;
    void onHalSubInterface(int topicid, int cmdid, int size, char *paload) {
        std::cout << "onHalSubInterface," << topicid << "," << cmdid << "," << size << std::endl;
    }

    void init() {
            m_ppsctrl = DESY::ppscontrol::Instance(g_ppscfg, sizeof(g_ppscfg) / sizeof(DESY::PPS_CFG_EXX_STRU));
            m_ppsctrl->registerCallback(this);
    }

    void sendTriggerData() {
        if(!m_ppsctrl) {
            return;
        }

        {
            Dsvpps::DataLogging4 data;
            data.longControlOutput.unavailableReason = static_cast<Dsvpps::LongControlOutput::eUnavailablereason>(0xA);
            int64_t status = m_ppsctrl->send(Dsvpps::E_DataLogging4, 0, sizeof(Dsvpps::DataLogging4), &data);
        }

        TriggerTest data;
        data.test_int = counter % 10;
        // data.test_int2 = counter % 5;
        // data.test_int3 = counter % 2;
        int64_t status = m_ppsctrl->send(E_TriggerTest, 0, sizeof(TriggerTest), &data);
        std::cout << "sendTriggerData," << E_TriggerTest << ",status=" << status << std::endl;
        std::cout << "sendTriggerData," << E_TriggerTest << ",data[" << data.test_int << "]" << std::endl;
        // std::cout << "sendTriggerData," << E_TriggerTest << ",data[" << data.test_int << "] data2[" << data.test_int2
        //           << "] data3[" << data.test_int3 << "]" << std::endl;
        counter ++;
    }

    void deinit() {
        SubscribeAll(0);
    }

private:
    int counter;
    void SubscribeAll(int sub) {
        for(int i = 0; i < (sizeof(g_ppscfg) / sizeof(DESY::PPS_CFG_EXX_STRU)); ++i) {
            m_ppsctrl->subscribe(g_ppscfg[i].topicid, sub);
        }
    }
};


int main(int argc, char** argv) {
    Dispatcher disPathch;
    disPathch.init();
    std::cout << "init," << std::endl;

    while(1) {
        disPathch.sendTriggerData();
        sleep(1);
    }

    disPathch.deinit();

    return 0;
}
