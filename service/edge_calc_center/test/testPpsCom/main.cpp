#include <iostream>

#include <unistd.h>

#include <DsvPpsIfStruct.h>
#include <ppscontrol.h>

static DESY::ppscontrol *m_ppsctrl = nullptr;

static DESY::PPS_CFG_EXX_STRU g_ppscfg[] = {
    DESY::PPS_CFG_EXX_STRU { Dsvpps::E_AMPObstacle_Site_Array, "AMPObstacle_Site_Array", 32, 1, 0, 1, sizeof(Dsvpps::AMPObstacle_Site_Array), 0, 0, MSG_BLOCKWAIT},
};

class Dispatcher : public DESY::HalSubInterface {
public:
    Dispatcher() {
    }

    ~Dispatcher() = default;
    void onHalSubInterface(int topicid, int cmdid, int size, char *paload) {
        std::cout << "onHalSubInterface," << topicid << "," << cmdid << "," << size << std::endl;
    }

    void init() {
            m_ppsctrl = DESY::ppscontrol::Instance(g_ppscfg, sizeof(g_ppscfg) / sizeof(DESY::PPS_CFG_EXX_STRU));
            m_ppsctrl->registerCallback(this);
    }

    void sendE_AMPObstacle_Site_Array() {
        if(!m_ppsctrl) {
            return;
        }

        Dsvpps::AMPObstacle_Site_Array data;
        int64_t status = m_ppsctrl->send(Dsvpps::E_AMPObstacle_Site_Array, 0, sizeof(data), &data);
        std::cout << "sendE_AMPObstacle_Site_Array," << Dsvpps::E_AMPObstacle_Site_Array << ",status=" << status << std::endl;
    }

    void deinit() {
        SubscribeAll(0);
    }

private:
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
    disPathch.sendE_AMPObstacle_Site_Array();

    while(1) {
        sleep(1);
    }

    disPathch.deinit();

    return 0;
}
