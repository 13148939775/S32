#include "trigger/Evaluator.h"
#include <assert.h>
#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>

using namespace hht::datamanager;

uint64_t get_current_timestamp() {
    timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return (int64_t)time.tv_sec * 1000 + time.tv_nsec/1000000;
}

int main(){

    // EqualTo
    {
        auto eval = Evaluator<EqualTo>(Variant(1), 0);
        assert(eval.status() == 0);

        eval.eval(0);
        assert(eval.status() == 0);
        eval.eval(1);
        assert(eval.status() == 1);
        eval.eval(2);
        assert(eval.status() == 0);
    }

    // EqualTo duration = 1000
    {
        auto eval = Evaluator<EqualTo>(Variant(1), 1000);
        assert(eval.status() == 0);

        for(int i=0; i<10; i++) {
            eval.eval(1);
            assert(eval.status() == 0);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        eval.eval(1);
        assert(eval.status() == 1);
        eval.eval(0);
        assert(eval.status() == 0);
    }

    // GreaterThan
    {
        auto eval = Evaluator<GreaterThan>(Variant(1), 0);
        assert(eval.status() == 0);

        eval.eval(0);
        assert(eval.status() == 0);
        eval.eval(1);
        assert(eval.status() == 0);
        eval.eval(2);
        assert(eval.status() == 1);
        eval.eval(3);
        assert(eval.status() == 1);
        eval.eval(0);
        assert(eval.status() == 0);
    }

    // GreaterThan duration = 1000
    {
        auto eval = Evaluator<GreaterThan>(Variant(1), 1000);
        assert(eval.status() == 0);

        for(int i=0; i<10; i++) {
            eval.eval(2);
            assert(eval.status() == 0);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        eval.eval(2);
        assert(eval.status() == 1);
        eval.eval(1);
        assert(eval.status() == 0);
    }

    // LessThan
    {
        auto eval = Evaluator<LessThan>(Variant(1), 0);
        assert(eval.status() == 0);

        eval.eval(0);
        assert(eval.status() == 1);
        eval.eval(1);
        assert(eval.status() == 0);
    }

    // DiffEqualTo
    {
        auto eval = Evaluator<DiffEqualTo>(Variant(1), 0);
        assert(eval.status() == 0);

        eval.eval(0);
        assert(eval.status() == 0);
        eval.eval(1);
        assert(eval.status() == 1);
        eval.eval(2);
        assert(eval.status() == 1);
    }

    // DiffGreaterThan
    {
        auto eval = Evaluator<DiffGreaterThan>(Variant(1), 0);
        assert(eval.status() == 0);

        eval.eval(0);
        assert(eval.status() == 0);
        eval.eval(1);
        assert(eval.status() == 0);
        eval.eval(3);
        assert(eval.status() == 1);
        eval.eval(2);
        assert(eval.status() == 0);
    }

    // DiffLessThan
    {
        auto eval = Evaluator<DiffLessThan>(Variant(1), 0);
        assert(eval.status() == 0);

        eval.eval(0);
        assert(eval.status() == 0);
        eval.eval(1);
        assert(eval.status() == 0);
        eval.eval(1);
        assert(eval.status() == 1);
        eval.eval(2);
        assert(eval.status() == 0);
    }

    std::cout << "Success." << std::endl;

    return 0;
}