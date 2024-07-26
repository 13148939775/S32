#include "trigger/Evaluator.h"
#include "trigger/Trigger.h"
#include "trigger/TriggerManager.h"

#include <assert.h>
#include <memory>
#include <functional>

using namespace hht::datamanager;


int main(){

    // logical AND test
    {
        auto eval1 = std::make_shared<Evaluator<EqualTo>>(Variant(1.0), 0);
        auto eval2 = std::make_shared<Evaluator<EqualTo>>(Variant(2.0), 0);

        bool triggered = false;
        auto notifier = std::make_shared<std::function<void(TriggerInfo)>>(
            [&triggered](TriggerInfo info) {
                triggered = true;
            }
        );

        auto trigger = std::make_shared<Trigger>(0);
        trigger->setMaxTriggerTimes(10);
        trigger->setNotifier(notifier);

        trigger->addEvaluator("E1", eval1);
        trigger->addEvaluator("E2", eval2);
        trigger->setLogic("(E1&E2)");

        triggered=false;
        eval1->eval(1.0);
        eval2->eval(2.0);
        assert(eval1->status() == true);
        assert(eval2->status() == true);
        trigger->update(0);
        assert(triggered == true);

        triggered=false;
        eval1->eval(1.0);
        eval2->eval(1.0);
        assert(eval1->status() == true);
        assert(eval2->status() == false);
        trigger->update(0);
        assert(triggered == false);
    }



    // logical OR test
    {
        auto eval1 = std::make_shared<Evaluator<EqualTo>>(Variant(1.0), 0);
        auto eval2 = std::make_shared<Evaluator<EqualTo>>(Variant(2.0), 0);

        bool triggerd = false;
        auto notifier = std::make_shared<std::function<void(TriggerInfo)>>(
            [&triggerd](TriggerInfo info) {
                triggerd = true;
            }
        );

        auto trigger = std::make_shared<Trigger>(1);
        trigger->setMaxTriggerTimes(10);
        trigger->setNotifier(notifier);

        trigger->addEvaluator("E1", eval1);
        trigger->addEvaluator("E2", eval2);
        trigger->setLogic("(E1|E2)");

        triggerd = false;
        eval1->eval(1.0);
        eval2->eval(1.0);
        assert(eval1->status() == true);
        assert(eval2->status() == false);
        trigger->update(0);
        assert(triggerd == true);

        triggerd = false;
        eval1->eval(2.0);
        eval2->eval(2.0);
        assert(eval1->status() == false);
        assert(eval2->status() == true);
        trigger->update(0);
        assert(triggerd == false);

        triggerd = false;
        eval1->eval(2.0);
        eval2->eval(1.0);
        assert(eval1->status() == false);
        assert(eval2->status() == false);
        trigger->update(0);
        assert(triggerd == false);


        triggerd = false;
        eval1->eval(2.0);
        eval2->eval(2.0);
        assert(eval1->status() == false);
        assert(eval2->status() == true);
        trigger->update(0);
        assert(triggerd == true);
    }

    // complex logic test
    {
        auto eval1 = std::make_shared<Evaluator<EqualTo>>(Variant(1.0), 0);
        auto eval2 = std::make_shared<Evaluator<EqualTo>>(Variant(2.0), 0);
        auto eval3 = std::make_shared<Evaluator<EqualTo>>(Variant(3.0), 0);


        bool triggerd = false;
        auto notifier = std::make_shared<std::function<void(TriggerInfo)>>(
            [&triggerd](TriggerInfo info) {
                triggerd = true;
            }
        );

        auto trigger = std::make_shared<Trigger>(2);
        trigger->setMaxTriggerTimes(10);
        trigger->setNotifier(notifier);

        trigger->addEvaluator("E1", eval1);
        trigger->addEvaluator("E2", eval2);
        trigger->addEvaluator("E3", eval3);

        trigger->setLogic("((E1&E2)|E3)");

        triggerd = false;
        eval1->eval(1.0);
        eval2->eval(1.0);
        eval2->eval(1.0);
        assert(eval1->status() == true);
        assert(eval2->status() == false);
        assert(eval3->status() == false);
        trigger->update(0);
        assert(triggerd == false);

        triggerd = false;
        eval1->eval(1.0);
        eval2->eval(2.0);
        eval3->eval(2.0);
        assert(eval1->status() == true);
        assert(eval2->status() == true);
        assert(eval3->status() == false);
        trigger->update(0);
        assert(triggerd == true);

        triggerd = false;
        eval1->eval(1.0);
        eval2->eval(1.0);
        eval3->eval(1.0);
        assert(eval1->status() == true);
        assert(eval2->status() == false);
        assert(eval3->status() == false);
        trigger->update(0);
        assert(triggerd == false);

        triggerd = false;
        eval1->eval(1.0);
        eval2->eval(1.0);
        eval3->eval(3.0);
        assert(eval1->status() == true);
        assert(eval2->status() == false);
        assert(eval3->status() == true);
        trigger->update(0);
        assert(triggerd == true);
    }




    std::cout << "Success" << std::endl;
    return 0;
}