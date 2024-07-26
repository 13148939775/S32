#include "dumper/UntypedRingBuffer.h"
#include "HhtBufPool.h"
#include <iostream>
#include <time.h>
#include <assert.h>
#include <openssl/md5.h>

#define bufpool_capacity 2000
#define bufpool_count 2
using namespace hht::datamanager;

using Header = UntypedRingBuffer<bufpool_capacity>::Header;

struct Payload1 {
    int payload;
};

struct Payload2 {
    double payload1;
    double payload2;
};


struct PayloadWithCheckSum1 {
    Payload1 payload;
    uint32_t checksum;
};

struct PayloadWithCheckSum2 {
    Payload2 payload;
    uint32_t checksum;
};

uint32_t CheckSumGenerator(void* payload) {
    return *reinterpret_cast<uint32_t*>(payload);
}

bool CheckSumChecker(void* payload, uint32_t check_sum) {
    return check_sum == CheckSumGenerator(payload);
}

uint64_t getCurrentTimestamp() {
    timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return (uint64_t)time.tv_sec * 1000 + time.tv_nsec/1000000;
}


int main() {

    auto pool = hht::BufPool(bufpool_capacity, bufpool_count);
    auto buffer = std::make_unique<UntypedRingBuffer<bufpool_capacity>>(pool.mallocBuf());

    for(int i=0; i<100000000; i++){
        if(i%3 == 0){
            PayloadWithCheckSum1 p;
            p.payload.payload = i;
            p.checksum = CheckSumGenerator(&p.payload);

            Header header;
            header.topicId = 1;
            header.dataLength = sizeof(p);
            header.timeStamp = getCurrentTimestamp();

            auto res = buffer->tryWrite(header, (uint8_t*)&p);
        }
        else{
            PayloadWithCheckSum2 p;
            p.payload.payload1 = i;
            p.payload.payload2 = i;
            p.checksum = CheckSumGenerator(&p.payload);

            Header header;
            header.topicId = 2;
            header.dataLength = sizeof(p);
            header.timeStamp = getCurrentTimestamp();

            auto res = buffer->tryWrite(header, (uint8_t*)&p);
        }

        if(i % 10000 == 0) {

            unsigned char digest[16];
            MD5_CTX context;
            MD5_Init(&context);

            auto ptr = buffer.release();

            auto data_pointer = ptr->getBuffer();
            auto capacity = ptr->getBufferSize();
            auto offset = ptr->getReadOffset();
            auto data_size = ptr->getDataSize();


            uint8_t buffer_copy[bufpool_capacity];

            if(offset + data_size > capacity) {
                auto former = capacity - offset;
                auto latter = data_size - former;
                memcpy(buffer_copy, data_pointer + offset, former);
                memcpy(buffer_copy + former, data_pointer, latter);
            }
            else{
                memcpy(buffer_copy, data_pointer + offset, data_size);
            }


            MD5_Update(&context, buffer_copy, data_size);
            size_t count = 0;
            while(count < data_size){
                uint8_t* header_ptr = buffer_copy + count;
                uint8_t* payload_ptr = buffer_copy + count + sizeof(Header);
                if(reinterpret_cast<Header*>(header_ptr)->topicId == 1) {
                    auto checksum = reinterpret_cast<PayloadWithCheckSum1*>(payload_ptr)->checksum;
                    assert(CheckSumChecker(&reinterpret_cast<PayloadWithCheckSum1*>(payload_ptr)->payload, checksum));
                    count += sizeof(Header) + sizeof(PayloadWithCheckSum1);
                }
                else if(reinterpret_cast<Header*>(header_ptr)->topicId == 2) {
                    auto checksum = reinterpret_cast<PayloadWithCheckSum2*>(payload_ptr)->checksum;
                    assert(CheckSumChecker(&reinterpret_cast<PayloadWithCheckSum2*>(payload_ptr)->payload, checksum));
                    count += sizeof(Header) + sizeof(PayloadWithCheckSum2);
                }
                else{
                    assert(0);
                }
            }
            pool.releaseBuf(ptr->mDataPtr);
            buffer = std::make_unique<UntypedRingBuffer<bufpool_capacity>>(pool.mallocBuf());

            MD5_Final(digest, &context);

            std::string result;
            for(int i=0; i<16; i++){
                result += "0123456789abcdef"[digest[i] / 16];
                result += "0123456789abcdef"[digest[i] % 16];
            }

            // std::cout << "MD5Checksum: " << std::string(digest) << std::endl;
        }

    }


    std::cout << "RingBuffer Write Test Success." << std::endl;
    std::cout << "RingBuffer Write CheckSum Test Success." << std::endl;
    pool.releaseBuf(buffer->mDataPtr);

    return 0;
}