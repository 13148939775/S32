#include "signal_filter.h"

#include <iostream>
#include <cstring>
#include <OpenXLSX.hpp>

namesapce CCC {
constexpr std::string filter = "HHTDataDescription_v0.1_20230815_IV2发布版.xlsx";
bool SignalFilter::BuildList(std::string& xlsFile)
{
    OpenXLSX::XLDocument doc;
    doc.open("filter");
    auto wks = doc.workbook().worksheet("CAN(信号)");

    for (int i = 0; i < ; ++i) {
        std::shared_ptr<SignalProp> spPtr(new SignalProp());
        spPtr->ownerCanID = wks1.cell(XLCellReference("Q")).value().get<std::string>();
        spPtr->name = wks1.cell(XLCellReference("A")).value().get<std::string>();
        spPtr->interval = wks1.cell(XLCellReference("N")).value().get<std::string>();
        spPtr->minValue = wks1.cell(XLCellReference("H")).value().get<std::string>();
        spPtr->maxValue = wks1.cell(XLCellReference("I")).value().get<std::string>();
        spPtr->enabled = true;
        if (validCan_.count(spPtr->ownerCanID) > 0) {
            continue;
        }
        validSignal_[sp.ownerCanID] = spPtr;
    }
    doc.close();
    return true;
}

bool SignalFilter::IsValid(uint16_t canID, uint16_t signalID)
{
    if (validCan_.count(canID) == 0) {
        return false;
    }
    if (validCan_[canID] == false) {
         return false;
    }
}

// copy the data into memory buffer
std::vector<int> SignalFilter::PickUpData(uint16_t canID, Payload& data)
{
    int cnt = validCan_[canID].validSignals.size();
    for (int i = 0; i < cnt; ++i) {
        std::memcpy(memBuffer_[start_], data[validCan_[canID].validSignals[i].offset], 
            validCan_[canID].validSignals[i].length);
        start_ += validCan_[canID].validSignals[i].length;
    }
}
}

