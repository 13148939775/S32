#ifndef HHTVARIENT_H
#define HHTVARIENT_H

#include <assert.h>

#include <string>
#include <vector>
#include <map>


namespace Json {
class Value;
}

namespace HHT {
class Variant {
public:
    enum Type {
        Int,
        Real,
        String,
        Bool,
        Array,
        Map,

        None
    };

    using IntT = int32_t;
    using RealT = double;
    using StringT = std::string;
    using CStringT = const char*;
    using ArrayT = std::vector<Variant>;
    using BoolT = bool;
    using KeyT = std::string;
    using MapT = std::map<KeyT, Variant>;

public:
    Variant() : mType(None) {}
    Variant(IntT value): mType(Int), mIntValue(value) {}
    Variant(RealT value): mType(Real), mRealValue(value) {}
    Variant(StringT value): mType(String), mStringValue(value) {}
    Variant(CStringT value): mType(String), mStringValue(value) {}
    Variant(BoolT value): mType(Bool), mBoolValue(value) {}
    Variant(ArrayT value): mType(Array), mArrayValue(value) {}
    Variant(MapT value): mType(Map), mMapValue(value) {}
    ~Variant() {}

    inline Type type() const {return mType;}

    inline IntT intValue() const {
        assert(Int == mType);
        return Int == mType ? mIntValue : IntT();
    }
    inline RealT realValue() const {
        assert(Real == mType);
        return Real == mType ? mRealValue : RealT();
    }
    inline StringT stringValue() const {
        assert(String == mType);
        return String == mType ? mStringValue : StringT();
    }
    inline BoolT boolValue() const {
        assert(Bool == mType);
        return Bool == mType ? mBoolValue : false;
    }
    inline ArrayT arrayValue() const {
        assert(Array == mType);
        return Array == mType ? mArrayValue : ArrayT();
    }
    inline MapT mapValue() const {
        assert(Map == mType);
        return Map == mType ? mMapValue : MapT();
    }

    ////////////////////////////////////////////
    // High performance but unsafe functions
    inline IntT&        intValueRef() { return mIntValue; }
    inline RealT&      realValueRef() { return mRealValue; }
    inline StringT&  stringValueRef() { return mStringValue; }
    inline BoolT&      boolValueRef() { return mBoolValue; }
    inline ArrayT& arrayValueRefRef() { return mArrayValue; }
    inline MapT&     mapValueRefRef() { return mMapValue; }

    inline const IntT&        intValueRef() const { return mIntValue; }
    inline const RealT&      realValueRef() const { return mRealValue; }
    inline const StringT&  stringValueRef() const { return mStringValue; }
    inline const BoolT&      boolValueRef() const { return mBoolValue; }
    inline const ArrayT& arrayValueRefRef() const { return mArrayValue; }
    inline const MapT&     mapValueRefRef() const { return mMapValue; }

    inline Variant operator[](size_t index) const {
        assert(Array == mType);
        assert(mArrayValue.size() > index);
        return (Array == mType && mArrayValue.size() > index)? mArrayValue[index]: Variant();
    }

    inline Variant operator[](KeyT key) const {
        assert(Map == mType);
        if (Map != mType) {
            return Variant();
        }
        auto it = mMapValue.find(key);
        return it != mMapValue.end()? it->second: Variant();
    }

    bool operator< (const Variant& other) const {
        if (mType != other.mType) {
            return mType < other.mType;
        }

        switch (mType) {
        case Int:    return mIntValue    < other.mIntValue;
        case Real:   return mRealValue   < other.mRealValue;
        case String: return mStringValue < other.mStringValue;
        case Array:  return mArrayValue  < other.mArrayValue;
        case Map:    return mMapValue    < other.mMapValue;
        default:
            break;
        }
        return false;
    }

    static Variant fromJson(const std::string& jsonStr);
    std::string toJson() const;
    std::string toStyledJson() const;

private:
    class JsonHelper;

private:
    Type mType;

    IntT mIntValue;
    RealT mRealValue;
    StringT mStringValue;
    BoolT mBoolValue;
    ArrayT mArrayValue;
    MapT mMapValue;
};  // Variant
}  //namespace hh
#endif	// HHTVARIENT_H
