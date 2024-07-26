#include "VideoZmqReceiver.h"

#include <iostream>
#include <fstream>


VideoZmqReceiver::VideoZmqReceiver()
    : mThreadQuit(true) {
}

VideoZmqReceiver::~VideoZmqReceiver() {
    deinit();
}

void VideoZmqReceiver::init(std::string ip, uint16_t port, std::string filePath) {

    mReceiver = std::make_shared<zmq::socket_t>(mCtx, zmq::socket_type::sub);
    mReceiver->setsockopt(ZMQ_SUBSCRIBE, "", 0);
    std::string proco = std::string("tcp://") + ip + ":" + std::to_string(port);
    std::cout << "init," << proco << std::endl;
    mReceiver->connect(proco);

    mThreadQuit.store(false);
    mRecvThread = std::thread(&VideoZmqReceiver::runRecv, this, filePath);
}

void VideoZmqReceiver::deinit() {
    mThreadQuit.store(true);
    if(mRecvThread.joinable()) {
        mRecvThread.join();
    }
}

void VideoZmqReceiver::runRecv(std::string filePath) {
    std::ofstream out, out_ts;
    out.open(filePath.c_str(), std::ios::out | std::ios::binary);
    out_ts.open((filePath + ".txt").c_str(), std::ios::out);
    uint64_t frameSize = 0;
    while(!mThreadQuit) {
        zmq::message_t msg;
        mReceiver->recv(msg, zmq::recv_flags::none);
        out.write((char*)msg.data() + 16, msg.size());
        ++frameSize;
        if(0 == frameSize % 24) {
            std::cout << "video, " << frameSize << std::endl;
        }

        uint64_t frame_index = 0, timestamp = 0;
        memcpy(&frame_index, msg.data(), sizeof(frame_index));
        memcpy(&timestamp, (uint8_t*)msg.data() + sizeof(frame_index), sizeof(timestamp));
        std::string txt = std::string("frameindex,") + std::to_string(frame_index) + ",timestamp," + std::to_string(timestamp) + "\n";
        out_ts.write(txt.c_str(), txt.size());
    }
    out.close();
    out_ts.close();
}
