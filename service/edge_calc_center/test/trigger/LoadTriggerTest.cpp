#include <assert.h>
#include <thread>

#include "DsvPpsIfStruct.h"
#include "DMDefine.h"
#include "trigger/Trigger.h"
#include "trigger/TriggerManager.h"




int main() {
    hht::datamanager::TriggerManager mgr;
    mgr.start();
    mgr.loadYaml();

    bool success = false;

    std::function<void(hht::datamanager::TriggerInfo)> f = [&success](const hht::datamanager::TriggerInfo& info) {
        success = true;
        std::cout << "info.triggerId: " << info.triggerId << std::endl;
        std::cout << "info.triggerMs: " << info.triggerMs << std::endl;
        std::cout << "info.beginMs: " << info.beginMs << std::endl;
        std::cout << "info.endMs: " << info.endMs << std::endl;
    };

    mgr.setNotifier(f);

    Dsvpps::DataLogging4 data;
    data.longControlOutput.unavailableReason = static_cast<Dsvpps::LongControlOutput::eUnavailablereason>(0xA);

    mgr.triggerUpdateHandler(Dsvpps::E_DataLogging4, (uint8_t*)&data, sizeof(Dsvpps::DataLogging4));

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    assert(success == true);

    std::cout << "Success" << std::endl;
    mgr.stop();
    return 0;
}