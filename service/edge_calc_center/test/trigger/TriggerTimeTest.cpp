#include "trigger/Evaluator.h"
#include "trigger/Trigger.h"
#include "trigger/TriggerManager.h"

#include <assert.h>
#include <memory>
#include <functional>
#include <string>
#include <iomanip>
#include <thread>

using namespace hht::datamanager;

#define INTERVAL_BIN_SIZE 100

uint64_t get_current_timestamp() {
    timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return (int64_t)time.tv_sec * 1000 + time.tv_nsec/1000000;
}

void trigger_info_print(const TriggerInfo& info, uint64_t test_begin) {
    auto trigger_begin = info.beginMs;
    auto trigger_end = info.endMs;
    auto trigger = info.triggerMs;

    std::string str = "||";
    str += std::string((trigger_begin-test_begin > 0 ? trigger_begin-test_begin : 0)/INTERVAL_BIN_SIZE, ' ');
    str += "<";
    str += std::string((trigger - trigger_begin)/INTERVAL_BIN_SIZE -1, '=');
    str += "+";
    str += std::string((trigger_end - trigger)/INTERVAL_BIN_SIZE -1, '=');
    str += ">";

    std::cout << std::left << std::setw(80) << str << "(id: " << info.triggerId << ")" << std::endl;

}


int main(){

    auto begin = get_current_timestamp();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));



    auto eval1 = std::make_shared<Evaluator<EqualTo>>(Variant(1.0), 0);
    auto eval2 = std::make_shared<Evaluator<EqualTo>>(Variant(2.0), 0);

    bool triggered = false;
    auto notifier = std::make_shared<std::function<void(TriggerInfo)>>(
        [&triggered, &begin](TriggerInfo info) {
            triggered = true;
            trigger_info_print(info, begin);
        }
    );

    auto trigger = std::make_shared<Trigger>(0);
    trigger->setMaxTriggerTimes(10);
    trigger->setNotifier(notifier);
    trigger->setAction({500, 500});

    trigger->addEvaluator("E1", eval1);
    trigger->addEvaluator("E2", eval2);
    trigger->setLogic("(E1&E2)");

    triggered=false;
    eval1->eval(1.0);
    eval2->eval(2.0);
    assert(eval1->status() == true);
    assert(eval2->status() == true);
    trigger->update(get_current_timestamp());
    assert(triggered == true);

    triggered=false;
    eval1->eval(1.0);
    eval2->eval(1.0);
    assert(eval1->status() == true);
    assert(eval2->status() == false);
    trigger->update(get_current_timestamp());
    assert(triggered == false);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    triggered=false;
    eval1->eval(1.0);
    eval2->eval(2.0);
    assert(eval1->status() == true);
    assert(eval2->status() == true);
    trigger->update(get_current_timestamp());
    assert(triggered == true);


    std::cout << "Success" << std::endl;
    return 0;
}