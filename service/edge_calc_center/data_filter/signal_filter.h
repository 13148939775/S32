#ifndef SIGNAL_FILTER_H
#define SIGNAL_FILTER_H

#include <cstdint>
#include <string>
#include <list>
#include <vector>

namespace CCC {

struct Pos {
    uint8_t offset;
    uint8_t length;
}

struct SignalProp {
    uint16_t ownerCanID;
    // std::string name; is for measure the struct size
    uint8_t length;
    uint8_t accuracy;
    uint8_t offset;
    uint8_t minValue;
    uint8_t maxValue;
    std::string unit;
    uint8_t interval;
    // compare instead of string cmp, is an internal var. not exist in pfe output
    uint16_t GUID;   // 第一阶段先用名称来map
    //bool enabled;
};

struct CanProp {
    //uint16_t canID;
    std::string name;
    std::vector<SignalProp> signalChild;
    //bool enabled;
    std::vector<Pos> validSignals;
};

class SignalFilter {  // valid signal to save
using CanPropPtr = std::shared_ptr<CanProp>;
public:
    bool BuildList(std::string& xlsFile);
    bool IsValid(uint16_t canID, Payload& data);
    void PickUpData(uint16_t canID, Payload& data);
private:
    std::list<SignalProp> validlist_;
    // canID && prop, just for prop building, not often changed
    std::unordered_map<uint16_t, CanPropPtr> validCan_; 
    memBuffer_;
    RingBuffer mm_;
    

   // std::unordered_map<uint16_t, bool> validCan_;
    // all the wanted canID indicated by same parent; 1 means wanted other means not

    // static std::unordered_map<>
};
}

#endif /* SIGNAL_FILTER_H */
