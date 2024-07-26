/*
 * @author 007313 008196
 * @for Can Data written into file
 * @version 0.1
 * @date 2023-05
 * 
 * @Copyrigh (c) HIPHI Co., LTD 2023
 * 
 */

#include "data_storage/data_dumper.h"

#include <node_log.h>
#include <time.h>
#include "data_dumper_worker.h"

namespace HHT {
namespace DataManager {

uint64_t DataDumper::getCurrentTimestamp() {
    timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return (uint64_t)time.tv_sec * 1000 + time.tv_nsec/1000000;
}

DataDumper::DataDumper()
    : dumpWorker_(nullptr), 
      status_(ReadyToDump), 
      buffPool_(DEFAULT_RINGBUFFER_SIZE, DEFAULT_RINGBUFFER_COUNT, true), 
      mDumpCountDown(0), 
      mDumpId(0) 
{
    buffer_ = std::make_unique<RingBuffer>(buffPool_.mallocBuf());
}

void DataDumper::start() {
    workThread_.start();
}

void DataDumper::stop() {
    workThread_.stop();
    workThread_.join();
}


// extra special worker
void DataDumper::RegisterDumperWorkerIF(DataDumperWorkerIFPtr worker)
{
    dumpWorker_ = worker;
}

bool DataDumper::releaseBuffer(DumpId id, uint8_t* buffer) {
    buffPool_.releaseBuf(buffer);
    return true;
}

/**
  * @brief Get data from provider, allocate memory buffer 
  */
void DataDumper::SendData(int32_t topicId, uint8_t* data, size_t size) 
{
    std::lock_guard<std::mutex> lk(mMtx);

    auto current_time_point = getCurrentTimestamp();
    Header header{topicId, (uint32_t) size, (uint64_t) current_time_point};

    if (status_ == BufferPoolEmptyWhileDumpInProgress || status_ ==  BufferPoolEmptyAfterFinalDump) {
        buffer_ = std::make_unique<RingBuffer>(buffPool_.mallocBuf());
        if (!buffer_->isValid()) {
            HHT_LOG(ERROR) << "[DataDumper::sendData] Failed: BuffPool Empty.\n";
            return;
        } else {
            HHT_LOG(ERROR) << "[DataDumper::sendData] Recover From State: BuffPool Empty.\n";
            status_ = (status_ == BufferPoolEmptyWhileDumpInProgress)? DumpInProgress : ReadyToDump;
            buffer_->tryWrite(header, data, status_ == ReadyToDump);  // 只是放入内存中 ？
        }
    } else if (status_ == DumpInProgress) {
        if (!buffer_->tryWrite(header, data, false)) {
            auto nextTriggerList = divideCurrentTriggerList(current_time_point);

            if(nextTriggerList.empty()) {
                PrepareDumpContext(true);
            } else{
                PrepareDumpContext(false);
            }

            mCurrentTriggerList = nextTriggerList;
            if (buffer_->isValid()) {
                buffer_->tryWrite(header, data, true);
            } else {
                // HHT_LOG(ERROR) << "[DataDumper::sendData] Failed: BuffPool Empty.\n";
            }
        }
    } else {
        buffer_->tryWrite(header, data, true);  // save to ring buffer
    }
}

// run the dump work in extra thread
void DataDumper::OnTrigger(TriggerInfo info) 
{
    workThread_.looper().postTask(std::bind(&DataDumper::TriggerDump, this, info));
}

void DataDumper::TriggerDump(TriggerInfo info) 
{
    std::lock_guard<std::mutex> lk(mMtx);

    mDumpCountDown.fetch_add(1);

    mCurrentTriggerList.push_back(info);

    for (auto&& pair : triggerList_) {
        pair.second.push_back(info);
    }

    if (status_ == ReadyToDump) {
        buffer_->DiscardData([&info](uint64_t timeStamp) {
            return timeStamp < info.beginMs;   // 老于起始时间的则不保存
        });
        status_ = DumpInProgress;
    }

    workThread_.looper().postDelayTask(std::bind(&DataDumper::tryDump, this), info.endMs - info.triggerMs);
}

// 如何实现所有数据都落盘？ 而不是触发式
void DataDumper::TryDump() 
{
    std::lock_guard<std::mutex> lk(mMtx);

    auto count_down = mDumpCountDown.fetch_sub(1);
    if (count_down == 1) {  // ??? 
        if (status_ == DumpInProgress) {
            PrepareDumpContext(true);
        } else if (status_ == ReadyToDump) {
            HHT_LOG(ERROR) << "[DataDumper::tryDump] status_ error.\n";
        } else {
            // status_ == BufferPoolEmptyWhileDumpInProgress
            // status_ == BufferPoolEmptyAfterFinalDump
            mCurrentTriggerList.clear();
            status_ = BufferPoolEmptyAfterFinalDump;
            HHT_LOG(ERROR) << "[DataDumper::tryDump] status_ error. Trigger info lost.\n";
        }
    }
}

/**
  * @brief Prepare dump context
  */
void DataDumper::PrepareDumpContext(bool is_final) 
{
    if (mCurrentTriggerList.size() == 0) {
        HHT_LOG(ERROR) << "[DataDumper::PrepareDumpContext] current trigger list size equals 0.\n";
        assert(0);
    }

    DumpInfo info;
    info.header.id = mDumpId;
    info.header.beginMs = buffer_->readTimeStampFromCursorRead();
    info.header.endMs = getCurrentTimestamp();
    info.header.triInfos = mCurrentTriggerList;

    auto buffer = buffer_.release();  //  TBC 

    info.buffer.buffer = buffer->getBuffer();
    info.buffer.bufferSize = buffer->getBufferSize();
    info.buffer.offset = buffer->getReadOffset();
    info.buffer.dataLength = buffer->getDataSize();

    #ifdef ENABLE_MD5_CHECKSUM
    {
        auto && ptr = info.buffer.buffer;
        auto && offset = info.buffer.offset;
        auto && size = info.buffer.dataLength;
        auto && capacity = info.buffer.bufferSize;

        MD5_CTX context;
        MD5_Init(&context);

        if(offset + size > capacity){
            MD5_Update(&context, ptr + offset, capacity - offset);
            MD5_Update(&context, ptr, size - capacity + offset);
        }
        else{
            MD5_Update(&context, ptr + offset, size);
        }

        MD5_Final(info.header.digest, &context);
    }
    #endif

    buffer_ = std::make_unique<RingBuffer>(buffPool_.mallocBuf());

    if (!buffer_->isValid()) {
        HHT_LOG(ERROR) << "[DataDumper::sendData] Enter State: BuffPool Empty.\n";
        status_ = is_final? BufferPoolEmptyAfterFinalDump : BufferPoolEmptyWhileDumpInProgress;
    } else {
        status_ = is_final? ReadyToDump : DumpInProgress;
    }

    if (!dumpWorker_) {
        HHT_LOG(ERROR) << "[DataDumper::PrepareDumpContext] Failed: worker not set.\n";
        return;
    }
    dumpWorker_->OnRequestDump(info);

    triggerList_[mDumpId] = mCurrentTriggerList;
    mCurrentTriggerList.clear();

    workThread_.looper().postDelayTask(std::bind(&DataDumper::confirm, this, mDumpId, info.header), DEFAULT_CONFIRM_DELAY);

    dumpId_++;
}

TriggerInfoList DataDumper::divideCurrentTriggerList(uint64_t time_point) {
    TriggerInfoList res;
    for (auto&& info : mCurrentTriggerList) {
        if (info.endMs > time_point) {
            res.push_back(info);
        }
    }
    return res;
}

void DataDumper::confirm(DumpId id, DumpHeader header) {
    DumpHeader h = header;
    h.triInfos = triggerList_[id];

    for (auto it = h.triInfos.begin(); it != h.triInfos.end(); ) {
        if (it->beginMs > h.endMs) {
            it = h.triInfos.erase(it);
        } else {
            it++;
        }
    }

    if(!dumpWorker_) {
        HHT_LOG(ERROR) << "[DataDumper::confirm] Failed: worker not set.\n";
        return;
    }

    dumpWorker_->onRequestConfirm(h);
    triggerList_.erase(id);
}

}  // namespace datamanager
}  // namespace hht