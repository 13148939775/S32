#ifndef HHT_DATAMANAGER_VARIANT_H
#define HHT_DATAMANAGER_VARIANT_H

#include <stdint.h>

#include <cmath>

#define PRECISION_INVERSE 1000000

namespace hht {
namespace datamanager {

__extension__ using int128_t = __int128;

class Variant {
public:
    Variant(double value) {
        mNum = (int128_t) PRECISION_INVERSE * value;
    };

    Variant(float value) {
        mNum = (int128_t) PRECISION_INVERSE * value;
    };

    Variant(bool value) : mNum(PRECISION_INVERSE * value){};

    Variant(uint8_t value) : mNum((int128_t) PRECISION_INVERSE * value){};
    Variant(uint16_t value) : mNum((int128_t) PRECISION_INVERSE * value){};
    Variant(uint32_t value) : mNum((int128_t) PRECISION_INVERSE * value){};
    Variant(uint64_t value) : mNum((int128_t) PRECISION_INVERSE * value){};

    Variant(int8_t value) : mNum((int128_t) PRECISION_INVERSE * value){};
    Variant(int16_t value) : mNum((int128_t) PRECISION_INVERSE * value){};
    Variant(int32_t value) : mNum((int128_t) PRECISION_INVERSE * value){};
    Variant(int64_t value) : mNum((int128_t) PRECISION_INVERSE * value){};
    Variant(int128_t value) : mNum((int128_t) PRECISION_INVERSE * value){};

    bool operator==(const Variant& other) const { return mNum == other.mNum; };

    bool operator<(const Variant& other) const {
        return mNum < other.mNum;
    };

    bool operator>(const Variant& other) const { return other.operator<(*this); };

    bool operator!=(const Variant& other) const { return !this->operator==(other); };

    bool operator<=(const Variant& other) const { return this->operator<(other) || this->operator==(other); };

    bool operator>=(const Variant& other) const { return this->operator>(other) || this->operator==(other); };

    Variant operator-(const Variant& other) const {
        Variant res(0);
        res.mNum = this->mNum - other.mNum;
        return res;
    };

    Variant operator+(const Variant& other) const {
        Variant res(0);
        res.mNum = this->mNum + other.mNum;
        return res;
    };

private:
    int128_t mNum;
};

}  // namespace datamanager
}  // namespace hht

#endif