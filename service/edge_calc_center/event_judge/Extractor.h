#ifndef DATAMANAGER_EXTRACTOR_H
#define DATAMANAGER_EXTRACTOR_H

#include "trigger/LogicVariant.h"

#include <iostream>


namespace hht {
namespace datamanager {

class BaseExtractor {
public:
    virtual Variant extract(uint8_t* ptr)  = 0;
};

template <typename M>
class Extractor : public BaseExtractor{
public:

    Extractor(size_t offset) : mOffset(offset) {}

    virtual Variant extract(uint8_t* ptr) override {
        return Variant(*reinterpret_cast<M*>(ptr + mOffset));
    }

private:
    size_t mOffset;
};


}  // namespace datamanager
}  // namespace hht

#endif

