/*
 * @author 007313 008196
 * @for Can Data handler trategy
 * @version 0.1
 * @date 2023-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DATA_DUMPER_H
#define DATA_DUMPER_H

#include <memory>
#include <mutex>
#include <atomic>
#include <unordered_map>

#include "HhtLooperThread.h"
#include "HhtTaskLooper.h"
#include "HhtBufPool.h"

#include "DMDefine.h"
#include "buffer_manager/UntypedRingBuffer.h"

static constexpr int DEFAULT_RINGBUFFER_SIZE  = 80 * 1024 * 1024;
static constexpr int DEFAULT_RINGBUFFER_COUNT = 10;

static constexpr int DEFAULT_CONFIRM_DELAY = 5000;

#ifdef ENABLE_MD5_CHECKSUM
#include <openssl/md5.h>
#endif

namespace HHT {
namespace DataManager {

/*
calling sendData(TopidId, Payload, PayloadSize)

+=============================================================================+
|                               Data Segment                                  |
+===================================+=========================================+
|              Header               |                 Payload                 |
| int32_t | uint32_t    | uint64_t  |                                         |
| TopicId | PayloadSize | TimeStamp |                                         |
+===================================+=========================================+
*/

class DataDumper {
public:
using RingBuffer = UntypedRingBuffer<DEFAULT_RINGBUFFER_SIZE>;
using Header = RingBuffer::Header;
using DataDumperWorkerIFPtr = std::shared_ptr<DataDumperWorkerIF>;

enum DataDumperStatus {
    ReadyToDump = 0,
    DumpInProgress,
    BufferPoolEmptyWhileDumpInProgress,
    BufferPoolEmptyAfterFinalDump,
};

public:
    DataDumper();

    void Start();
    void Stop();

    void RegisterDumperWorkerIF(const DataDumperWorkerIFPtr worker);

    // from Dsv
    void sendData(int32_t topicId, uint8_t* data, size_t size);
    bool releaseBuffer(DumpId id, uint8_t* buffer);

    // for trigger
    void OnTrigger(TriggerInfo info);
    void TriggerDump(TriggerInfo info);
    void tryDump();

    TriggerInfoList divideCurrentTriggerList(uint64_t time_point);
    void PrepareDumpContext(bool is_final);

    void confirm(DumpId id, DumpHeader info);

    uint64_t getCurrentTimestamp();

private:
    DataDumperWorkerIFPtr dumpWorker_;
    DataDumperStatus status_;
    std::unique_ptr<RingBuffer> buffer_;
    BufPool buffPool_;
    std::mutex mtx_;

    LooperThread workThread_;
    std::atomic_int dumpCountDown_;

    DumpId dumpId_;
    std::unordered_map<DumpId, TriggerInfoList> triggerList_;
    TriggerInfoList currentTriggerList_;
};

}  // namespace datamanager
}  // namespace hht

#endif