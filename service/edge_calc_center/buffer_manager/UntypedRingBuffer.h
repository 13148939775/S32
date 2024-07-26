#ifndef UNTYPEDRINGBUFFER_H
#define UNTYPEDRINGBUFFER_H

#include <assert.h>

#include <cstring>
#include <functional>
#include <chrono>

#include "DMDefine.h"
#include "glog/logging.h"

namespace hht {
namespace datamanager {

template <size_t Base>
class UntypedRingBufferIndex {
    static_assert(Base > 0, "Base Error.");

public:
    UntypedRingBufferIndex() : cycle(0), index(0) {}
    UntypedRingBufferIndex(size_t c, size_t i) : cycle(c), index(i) {}

    void forward(size_t step) {
        index += step;
        cycle += index / Base;
        index %= Base;
    }

    size_t cycle{0};
    size_t index{0};
};

template <size_t Capacity>
class UntypedRingBuffer {
    static_assert(Capacity > 0, "Capacity Error.");
    friend class DataDumper;
public:
    using Index = UntypedRingBufferIndex<Capacity>;
    using Header = StHeader;

private:
    static constexpr size_t headerSize = sizeof(Header);
    static constexpr size_t dataLengthSize = sizeof(Header::dataLength);
    static constexpr size_t dataLengthOffset = offsetof(Header, dataLength);
    static constexpr size_t timeStampSize = sizeof(Header::timeStamp);
    static constexpr size_t timeStampOffset = offsetof(Header, timeStamp);

private:
    struct UntypedRingBufferStatus {
        Index CursorWrite;
        Index CursorRead;
    };

public:
    explicit UntypedRingBuffer(uint8_t* buffer) : mStatus(UntypedRingBufferStatus()) { mDataPtr = buffer; }

    bool isValid() { return mDataPtr != nullptr; }

    bool tryWrite(const Header& header, uint8_t* payload, bool enable_override = true) {
        if(header.dataLength > Capacity) {
            LOG(ERROR) << "[UntypedRingBuffer::tryWrite] payload size is bigger than buffer capacity." << header.dataLength << "/" << Capacity<< "\n";
            return false;
        }

        auto&& CursorRead = mStatus.CursorRead;
        auto&& CursorWrite = mStatus.CursorWrite;
        auto CursorWritten = mStatus.CursorWrite;
        CursorWritten.forward(headerSize + header.dataLength);

        if (!enable_override) {
            if (isFull(CursorWrite, CursorWritten, CursorRead)) {
                return false;
            }
            write(CursorWrite, (uint8_t*) &header, headerSize);
            write(CursorWrite, payload, header.dataLength);
        } else {
            tryDiscardData(CursorWrite, CursorWritten, CursorRead);
            write(CursorWrite, (uint8_t*) &header, headerSize);
            write(CursorWrite, payload, header.dataLength);
        }

        return true;
    }


    void write(Index& cursor_write, uint8_t* payload, size_t size) {
        if (cursor_write.index + size >= Capacity) {
            size_t former = Capacity - cursor_write.index;
            size_t latter = size - former;
            memcpy(mDataPtr + cursor_write.index, payload, former);
            memcpy(mDataPtr, payload + former, latter);
            cursor_write.forward(size);
        } else {
            memcpy(mDataPtr + cursor_write.index, payload, size);
            cursor_write.forward(size);
        }
    }

    uint32_t readDataSize(const Index& CursorRead) {
        auto CursorCopy = CursorRead;
        CursorCopy.forward(dataLengthOffset);

        if(Capacity - CursorCopy.index < dataLengthSize) {
            size_t former = Capacity - CursorCopy.index;
            size_t latter = dataLengthSize - former;
            uint32_t result;
            memcpy((uint8_t*) &result, mDataPtr + CursorCopy.index, former);
            memcpy((uint8_t*) &result + former, mDataPtr, latter);
            return result;
        }
        else {
            return *reinterpret_cast<uint32_t*>(mDataPtr + CursorCopy.index);
        }
    }

    uint64_t readTimeStampFromCursorRead() {
        return readTimeStamp(mStatus.CursorRead);
    }

    uint64_t readTimeStamp(const Index& CursorRead) {
        auto CursorCopy = CursorRead;
        CursorCopy.forward(timeStampOffset);

        if(Capacity - CursorCopy.index < timeStampSize) {
            size_t former = Capacity - CursorCopy.index;
            size_t latter = timeStampSize - former;
            uint64_t result;
            memcpy((uint8_t*) &result, mDataPtr + CursorCopy.index, former);
            memcpy((uint8_t*) &result + former, mDataPtr, latter);
            return result;
        }
        else {
            return *reinterpret_cast<uint64_t*>(mDataPtr + CursorCopy.index);
        }
    }

    Header readHeader(const Index& CursorRead) {
        auto CursorDataSize = CursorRead;

        if(Capacity - CursorDataSize.index < headerSize) {
            size_t former = Capacity - CursorDataSize.index;
            size_t latter = headerSize - former;
            Header header;
            memcpy((uint8_t*) &header, mDataPtr + CursorDataSize.index, former);
            memcpy((uint8_t*) &header + former, mDataPtr, latter);
            return header;
        }
        else {
            return *reinterpret_cast<Header*>(mDataPtr + CursorDataSize.index);
        }
    }

    void tryDiscardData(Index& CursorWrite, Index& CursorWritten, Index& CursorRead) {
        while (isFull(CursorWrite, CursorWritten, CursorRead)) {

            size_t step = (size_t) readDataSize(CursorRead);
            CursorRead.forward(headerSize + step);
            if(step == 0) {
                LOG(ERROR) << "[UntypedRingBuffer::tryDiscardData] step equals 0.\n";
                assert(0);
            }
        }
    }

    void discardData(std::function<bool(uint64_t)> discard_while_true) {
        while (isAhead(mStatus.CursorRead, mStatus.CursorWrite) &&
        discard_while_true(readTimeStamp(mStatus.CursorRead))){
            size_t step = (size_t) readDataSize(mStatus.CursorRead);
            mStatus.CursorRead.forward(headerSize + step);
            if(step == 0) {
                LOG(ERROR) << "[UntypedRingBuffer::tryDiscardData] step equals 0.\n";
                assert(0);
            }
        }
    }

    bool isFull(Index& CursorWrite, Index& CursorWritten, Index& CursorRead) {
        return !isOneCycleAhead(CursorRead, CursorWrite) && isOneCycleAhead(CursorRead, CursorWritten);
    }

    bool isAhead(Index left, Index right) {
        return (right.cycle - left.cycle) * Capacity + right.index - left.index > 0;
    }

    bool isOneCycleAhead(Index left, Index right) {
        return (right.cycle - left.cycle) * Capacity + right.index - left.index > Capacity;
    }

    uint8_t* getBuffer() { return mDataPtr; }

    size_t getBufferSize() { return Capacity; }

    size_t getReadOffset() { return mStatus.CursorRead.index; }

    size_t getDataSize() {
        return (mStatus.CursorWrite.cycle - mStatus.CursorRead.cycle) * Capacity + mStatus.CursorWrite.index -
               mStatus.CursorRead.index;
    }

public:
    uint8_t* mDataPtr{nullptr};
    UntypedRingBufferStatus mStatus;
};

}  // namespace datamanager
}  // namespace hht
#endif