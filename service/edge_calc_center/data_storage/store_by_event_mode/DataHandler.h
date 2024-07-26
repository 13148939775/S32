/*
 * @author 007313 008196
 * @for Can Data handler trategy
 * @version 0.1
 * @date 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "DMDefine.h"
#include "DMBaseModule.h"

namespace HHT {
namespace DataManager {
class DataHandler : public DMBaseModule {
public:
    DataHandler(ModuleId id, DataManager& dm) : DMBaseModule(id, dm) { }
    virtual ~DataHandler() = default;

    // Async send data command, will be block calling.
    // Can be called in any time, even if not inited.
    virtual void SendData(DataInfo info, uint8_t* data, size_t len) = 0;
};  // DataHandler
}  // namespace datamanager
}  // namespace hht
#endif	// DATAHANDLER_H
