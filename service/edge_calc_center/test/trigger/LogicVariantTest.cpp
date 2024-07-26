#include "trigger/LogicVariant.h"
#include <iostream>

#include <limits>

using namespace hht::datamanager;


__extension__ using int128_t = __int128;

std::ostream& operator<<(std::ostream& os, int128_t num) noexcept {
    bool isNeg = num < 0;
    num = isNeg? -num : num;

    char str[128];
    // int128_t num;

    for(size_t i=0; i<128; i++){
        str[127 - i] = '0' + num % 10;
        num /= 10;
    }


    if(isNeg) {
        os << '-';
    }

    for(size_t i=0; i<128; i++){
        os << str[i];
    }

    return os;

}


enum test {
    ZERO = 0,
    ONE = 1,
    THREE = 3,
};

int main() {

    assert(Variant((bool) 1) > Variant((bool) 0));
    assert(Variant((bool) 0) == Variant((bool) 0));
    assert(Variant((bool) 1) == Variant((bool) 1));

    assert(Variant((int) 2) > Variant((double) 1));
    assert(Variant((int) 1) == Variant((double) 1));

    assert(Variant((double) 1e6 + 1e-6) > Variant((double) 1e6));

    assert(Variant((double) 1e6 + 1e-7) == Variant((double) 1e6));

    assert(Variant((int) ONE) > Variant((int) ZERO));
    assert(Variant((int) THREE) > Variant((int) ONE));
    assert(Variant((int) THREE) == Variant((int) THREE));

    assert(Variant( std::numeric_limits<uint64_t>::max()) + Variant(1) == Variant( (int128_t) std::numeric_limits<uint64_t>::max() + 1));
    assert(Variant( std::numeric_limits<uint64_t>::max()) + Variant(1) > Variant( (int128_t) std::numeric_limits<uint64_t>::max()));
    assert(Variant( std::numeric_limits<uint64_t>::max()) + Variant(1) >= Variant( (int128_t) std::numeric_limits<uint64_t>::max() + 1));

    assert(Variant( std::numeric_limits<int64_t>::min()) - Variant(1) == Variant( (int128_t) std::numeric_limits<int64_t>::min() - 1));
    assert(Variant( std::numeric_limits<int64_t>::min()) - Variant(1) < Variant( (int128_t) std::numeric_limits<int64_t>::min()));
    assert(Variant( std::numeric_limits<int64_t>::min()) - Variant(1) <= Variant( (int128_t) std::numeric_limits<int64_t>::min()));

    std::cout << "Success" << std::endl;

    return 0;
}