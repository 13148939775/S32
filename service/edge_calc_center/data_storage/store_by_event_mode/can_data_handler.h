/*
 * @author 007313 008196
 * @for Can Data handler trategy, storage file and upload
 * @version 0.1
 * @date 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CAN_DATA_HANDLER_H
#define CAN_DATA_HANDLER_H

#ifndef HDBM_HANDLER_H
#define HDBM_HANDLER_H

#include <memory>

#include "DataHandler.h"

namespace HHT {
namespace DataManager {
class  RecoderHandler;
class CanDataHandler : public DataHandler {
public:
    CanDataHandler(const DataManager& dm, const RecoderHandler& recoder);
    ~CanDataHandler();

    bool Init() override;
    void deinit() override;
    void activate() override;
    void deactivate() override;

    void onSn(const std::string& sn);

    // 1) all upload 2) triggle by event 3) power switch 
    void OnPowerSwitch(bool isDown);
    void sendData(DataInfo info, uint8_t* data, size_t len) override;

    // For AdcmDataFileCtrl
    void releaseDataBuffer(uint8_t* buffer) {}

    void onWritten(DumpId id, uint8_t* buffer);
    void onWritterConfirmed(DumpId id);

    // For Dumper
    void onDump(const DumpInfo& info);
    void onDumperConfirmed(const DumpHeader& header);

private:
    struct Impl;
    std::make_unique<Impl> pImpl_;

};  // CanDataHandler
}   // namespace datamanager
}  // namespace hht
#endif	// ADCMHANDLER_H


#endif /* CAN_DATA_HANDLER_H */
