#include "structureddata.h"

#include <fstream>
#include <iostream>
#include <map>

uint64_t TOPIC_SCHEDULER_PORT_BEGIN = 0x00030000;
const uint64_t TOPICID_BEGIN = TOPIC_SCHEDULER_PORT_BEGIN;

const uint64_t TOPICID_DSVPPS_ESAINFO       = TOPICID_BEGIN + 0;
const uint64_t TOPICID_HHT_FUSIONROADINFO   = TOPICID_BEGIN + 1;
const uint64_t TOPICID_HHT_FUSIONROADINFO_1 = TOPICID_BEGIN + 2;
const uint64_t TOPICID_HHT_MAPEHRMAP        = TOPICID_BEGIN + 3;
const uint64_t TOPICID_HHT_FUSIONROADINFO_2 = TOPICID_BEGIN + 4;
const uint64_t TOPICID_HHT_FUSIONROADINFO_3 = TOPICID_BEGIN + 5;
const uint64_t TOPICID_HHT_FUSIONROADINFO_4 = TOPICID_BEGIN + 6;
const uint64_t TOPICID_HHT_FUSIONROADINFO_5 = TOPICID_BEGIN + 7;
const uint64_t TOPICID_HHT_FUSIONROADINFO_6 = TOPICID_BEGIN + 8;
const uint64_t TOPICID_HHT_FUSIONROADINFO_7 = TOPICID_BEGIN + 9;
const uint64_t TOPICID_HHT_FUSIONROADINFO_8 = TOPICID_BEGIN + 10;


StructuredData::StructuredData(std::string fileName)
    : mFileName(fileName) {
    read_thread_quit_.store(false);
    sock_sub_ = zmq::socket_t(context_, zmq::socket_type::sub);
    // sock_sub_.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    sock_sub_.set(zmq::sockopt::subscribe, "");
}

StructuredData::~StructuredData() {
    Deinit();
}

void StructuredData::Init(const std::string& ip, uint16_t port) {
    std::string addr = "tcp://" + ip + ":" + std::to_string(port);
    sock_sub_.connect(addr);
    read_thread_ = std::thread(&StructuredData::ReadWait, this);
    std::cout << "structureddata.init," << addr << std::endl;
    read_thread_quit_.store(false);
}

void StructuredData::Deinit() {
    sock_sub_.close();
    read_thread_quit_.store(true);
    if(read_thread_.joinable()) {
        read_thread_.join();
    }
    std::cout << "structureddata.deinit." << std::endl;
}

void StructuredData::ReadWait() {
    const std::map<uint64_t, uint64_t> nohIdTs {
        { TOPICID_DSVPPS_ESAINFO       , 0 },
        { TOPICID_HHT_FUSIONROADINFO   , 0 },
        { TOPICID_HHT_FUSIONROADINFO_1 , 0 },
        { TOPICID_HHT_MAPEHRMAP        , 0 },
        { TOPICID_HHT_FUSIONROADINFO_2 , 0 },
        { TOPICID_HHT_FUSIONROADINFO_3 , 0 },
        { TOPICID_HHT_FUSIONROADINFO_4 , 0 },
        { TOPICID_HHT_FUSIONROADINFO_5 , 0 },
        { TOPICID_HHT_FUSIONROADINFO_6 , 0 },
        { TOPICID_HHT_FUSIONROADINFO_7 , 0 },
        { TOPICID_HHT_FUSIONROADINFO_8 , 0 },
    };

    std::ofstream o_f;
    o_f.open(mFileName, std::ios::out);
    if(!o_f.is_open()) {
        std::cerr << "file not open," << mFileName << std::endl;
        return;
    }

    const std::string fileHeader = "zmq_multipart_index,topicIdCount,topicId,topicDataSize,comment";
    o_f.write(fileHeader.c_str(), fileHeader.size());

    std::uint64_t i = 0;
    uint64_t dataSize = 0;
    uint32_t curDataSize = 0;
    const uint64_t partSize = 50 * 1024 * 1024;

    while (!read_thread_quit_) {
        ++i;
        std::vector<zmq::message_t> recv_msgs;
        zmq::recv_multipart(sock_sub_, std::back_inserter(recv_msgs));
        // auto ts = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        for(const auto& one : recv_msgs) {
            int32_t topicCount = 0, topicId = 0;
            memcpy(&topicCount, one.data(), sizeof(topicCount));
            memcpy(&topicId, (uint8_t*)one.data() + sizeof(topicCount), sizeof(topicId));
            std::string txt = std::to_string(i) + "," + std::to_string(topicCount) + ","
                            + std::to_string(topicId)+ "," + std::to_string(one.size());

            dataSize += one.size();
            curDataSize += one.size();

            if(1 == curDataSize / partSize) {
                const double sizeMB = (dataSize / double(1024 * 1024.0));
                std::cout << "------------------------------ recv_size, " << sizeMB << " MB" << std::endl;
                curDataSize = 0;
                txt += "," + std::to_string(sizeMB) + "MB";
            }
            txt += "\n";
            o_f.write(txt.c_str(), txt.size());
        }

        std::cout << "zmq_recvMulti, " << i << ", size, " << recv_msgs.size() << std::endl;
    }
    std::cout << "break." << std::endl;
    o_f.close();
}
