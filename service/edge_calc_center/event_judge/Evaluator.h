#ifndef HHT_DATAMANAGER_EVALUATOR_H
#define HHT_DATAMANAGER_EVALUATOR_H

#include <chrono>
#include <iostream>
#include <string>

#include "trigger/LogicVariant.h"

namespace hht {
namespace datamanager {

enum Policy {
    EqualTo,
    NotEqualTo,
    GreaterThan,
    GreaterThanOrEqualTo,
    LessThan,
    LessThanOrEqualTo,
    DiffEqualTo,
    DiffNotEqualTo,
    DiffGreaterThan,
    DiffGreaterThanOrEqualTo,
    DiffLessThan,
    DiffLessThanOrEqualTo,
};

class BaseEvaluator {
public:
    BaseEvaluator() : mLatestStatus(false){};
    virtual void eval(const Variant& value) = 0;
    bool status() { return mLatestStatus; };

protected:
    bool mLatestStatus{false};
    std::string mSignal;
};

template <Policy P, typename = void>
class Evaluator : public BaseEvaluator {};

template <Policy P>
class Evaluator<P, typename std::enable_if<P == Policy::EqualTo || P == Policy::NotEqualTo ||
                                           P == Policy::GreaterThan || P == Policy::GreaterThanOrEqualTo ||
                                           P == Policy::LessThan || P == Policy::LessThanOrEqualTo>::type>
    : public BaseEvaluator {
private:
    struct OptionalTimePoint {
        bool hasValue{false};
        std::chrono::steady_clock::time_point timepoint;
        bool has_value() { return hasValue; }
        std::chrono::steady_clock::time_point value() { return timepoint; }
        void reset() { hasValue = false; }
    };

public:
    Evaluator(const Variant& expected, const uint32_t& ms) : mExpected(expected), mDuration(ms) { mTrueSince.reset(); };
    virtual void eval(const Variant& value) override {
        auto timestamp = std::chrono::steady_clock::now();
        bool status = false;

        switch (P) {
            case EqualTo:
                status = (value == mExpected);
                break;
            case NotEqualTo:
                status = (value != mExpected);
                break;
            case GreaterThan:
                status = (value > mExpected);
                break;
            case GreaterThanOrEqualTo:
                status = (value >= mExpected);
                break;
            case LessThan:
                status = (value < mExpected);
                break;
            case LessThanOrEqualTo:
                status = (value <= mExpected);
                break;
            default:
                break;
        }

        if (!status) {
            mLatestStatus = false;
            mTrueSince.reset();
            return;
        } else {
            if (mDuration == 0) {
                mLatestStatus = true;
            } else if (mTrueSince.has_value()) {
                if (std::chrono::duration_cast<std::chrono::milliseconds>(timestamp - mTrueSince.value()).count() >
                    mDuration) {
                    mLatestStatus = true;
                }
            } else {
                mTrueSince.timepoint = timestamp;
                mTrueSince.hasValue = true;
            }
        }
    };

private:
    OptionalTimePoint mTrueSince;
    Variant mExpected;
    uint32_t mDuration;
};


template <Policy P>
class Evaluator<P, typename std::enable_if<P == Policy::DiffEqualTo || P == Policy::DiffNotEqualTo ||
                                           P == Policy::DiffGreaterThan || P == Policy::DiffGreaterThanOrEqualTo ||
                                           P == Policy::DiffLessThan || P == Policy::DiffLessThanOrEqualTo>::type>
    : public BaseEvaluator {
private:
    struct OptionalTimePoint {
        bool hasValue{false};
        std::chrono::steady_clock::time_point timepoint;
        bool has_value() { return hasValue; }
        std::chrono::steady_clock::time_point value() { return timepoint; }
        void reset() { hasValue = false; }
    };

     struct OptionalVariant {
        bool hasValue{false};
        Variant mVariant{0};
        bool has_value() { return hasValue; }
        Variant value() { return mVariant; }
        void reset() { hasValue = false; }
    };

public:
    Evaluator(const Variant& expected, const uint32_t& ms) : mExpected(expected), mDuration(ms) { mTrueSince.reset(); };
    virtual void eval(const Variant& value) override {
        auto timestamp = std::chrono::steady_clock::now();
        bool status = false;

        if(!mLast.has_value()) {
            mLast.mVariant = value;
            mLast.hasValue = true;
            return;
        }

        switch (P) {
            case DiffEqualTo:
                status = ((value - mLast.mVariant) == mExpected);
                mLast.mVariant = value;
                break;
            case DiffNotEqualTo:
                status = ((value - mLast.mVariant) != mExpected);
                mLast.mVariant = value;
                break;
            case DiffGreaterThan:
                status = ((value - mLast.mVariant) > mExpected);
                mLast.mVariant = value;
                break;
            case DiffGreaterThanOrEqualTo:
                status = ((value - mLast.mVariant) >= mExpected);
                mLast.mVariant = value;
                break;
            case DiffLessThan:
                status = ((value - mLast.mVariant) < mExpected);
                mLast.mVariant = value;
                break;
            case DiffLessThanOrEqualTo:
                status = ((value - mLast.mVariant) <= mExpected);
                mLast.mVariant = value;
                break;
            default:
                break;
        }

        if (!status) {
            mLatestStatus = false;
            mTrueSince.reset();
            return;
        } else {
            if (mDuration == 0) {
                mLatestStatus = true;
            } else if (mTrueSince.has_value()) {
                if (std::chrono::duration_cast<std::chrono::milliseconds>(timestamp - mTrueSince.value()).count() >
                    mDuration) {
                    mLatestStatus = true;
                }
            } else {
                mTrueSince.timepoint = timestamp;
                mTrueSince.hasValue = true;
            }
        }
    };

private:
    OptionalTimePoint mTrueSince;
    OptionalVariant mLast;
    Variant mExpected;
    uint32_t mDuration;
};



}  // namespace datamanager
}  // namespace hht
#endif
