#include <unistd.h>

#include <thread>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <chrono>

#include "DMDefine.h"
#include "dumper/DataDumper.h"

using namespace hht::datamanager;

#define DEFAULT_TIME_BIN_SIZE 200

using Header = StHeader;

class DumperWorkerIF : public DataDumperWorkerIF{
public:
    DumperWorkerIF(DataDumper* dumper, uint64_t test_begin) : mDumper(dumper), mBegin(test_begin) {
        mBuffer = new uint8_t[DEFAULT_RINGBUFFER_SIZE];
    }
    ~DumperWorkerIF(){
        delete mBuffer;
    }

    virtual void onRequestDump(DumpInfo info) override {
        dump_timeline_printer(info);
        mDumper->releaseBuffer(info.header.id, info.buffer.buffer);
    }

    virtual void onRequestConfirm(DumpHeader header) override {
        trigger_timeline_printer(header);
    }

    void dump_timeline_printer(DumpInfo info) {

        auto buffer = info.buffer.buffer;
        auto buffer_size = info.buffer.bufferSize;
        auto data_length = info.buffer.dataLength;
        auto offset = info.buffer.offset;

        if(offset + data_length > buffer_size) {
            size_t former = buffer_size - offset;
            memcpy(mBuffer, buffer + offset, former);
            memcpy(mBuffer + former, buffer, data_length - former);
        }
        else{
            memcpy(mBuffer, buffer + offset, data_length);
        }


        size_t read_idx = 0;
        uint64_t begin_time = std::numeric_limits<uint64_t>::max();
        uint64_t end_time = std::numeric_limits<uint64_t>::min();

        while(read_idx < data_length){
            auto header = *reinterpret_cast<Header*>(mBuffer + read_idx);
            auto topic_id = header.topicId;
            auto payload_size = header.dataLength;
            auto time_stamp = header.timeStamp;
            begin_time = std::min(begin_time, time_stamp);
            end_time = std::max(end_time, time_stamp);
            read_idx += sizeof(Header) + payload_size;
        }

        std::string str;
        if(begin_time > mBegin){
            str += std::string((begin_time-mBegin)/DEFAULT_TIME_BIN_SIZE, ' ');
        }
        str += std::string((end_time-begin_time)/DEFAULT_TIME_BIN_SIZE, '=');
        std::cout << std::left << std::setw(100) << str << std::string(20, ' ') << "(total: " << end_time-begin_time << " MS, DumpId: " << info.header.id << " )" << std::endl;
    }

    void trigger_timeline_printer(DumpHeader header) {
        for(auto&& info : header.triInfos){
            auto id = info.triggerId;
            auto begin = info.beginMs;
            auto trigger = info.triggerMs;
            auto end = info.endMs;

            std::string str;
            if(begin > mBegin){
                str += std::string((begin-mBegin)/DEFAULT_TIME_BIN_SIZE, ' ');
            }

            str += "<";
            str += std::string(end>begin? (end-begin)/DEFAULT_TIME_BIN_SIZE -2 : 0 , '-');
            str += ">";
            std::cout << std::left << std::setw(100) << str << std::string(20, ' ') << "(DumpId: " << header.id << ", TriggerId: " << id << ")" << std::endl;
        }

    }

private:
    uint64_t mBegin;
    uint8_t* mBuffer;
    DataDumper* mDumper;
};


uint64_t getCurrentTimestamp() {
    timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return (uint64_t)time.tv_sec * 1000 + time.tv_nsec/1000000;
}

struct TestData {
    uint8_t test_int[1024];
};

int main() {
    DataDumper dumper;
    dumper.start();

    DumperWorkerIF worker(&dumper, getCurrentTimestamp());
    dumper.registerDumperWorkerIF(&worker);


    bool running = true;
    std::thread t(
        [&dumper, &running](){
            uint64_t counter = 0;
            while(running){
                TestData data;
                for(int i=0; i<1000; i++)
                    dumper.sendData(9999, (uint8_t*)&data, sizeof(TestData));
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }
    );

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    {
        TriggerInfo info1;
        info1.triggerId = 1;
        info1.triggerMs = getCurrentTimestamp();
        info1.beginMs = info1.triggerMs - 1000;
        info1.endMs = info1.triggerMs + 1000;
        dumper.onTrigger(info1);
    }

    for(int i=0; i<30; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        {
            TriggerInfo info2;
            info2.triggerId = 2;
            info2.triggerMs = getCurrentTimestamp();
            info2.beginMs = info2.triggerMs - 1000;
            info2.endMs = info2.triggerMs + 1000;
            dumper.onTrigger(info2);
        }

    }



    while(1){
        sleep(1);
    }
    running = false;
    t.join();
    dumper.stop();

    return 0;
}