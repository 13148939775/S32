#include "SocketMng.h"
#include "structureddata.h"
#include "VideoZmqReceiver.h"

#include <string>
#include <vector>


int main(int argc, char* argv[]) {
    if(2 != argc) {
        std::cout << "usage:" << argv[0] << " [camera count]" << std::endl;
        return 0;
    }

    const std::string dmIp = "172.20.1.30";
    const uint16_t videoDataPortBase = 20000;
    const uint16_t tcpHeartPort = 10040;
    const uint16_t structuredDataPort = 30505;

    int video_count = std::stoi(std::string(argv[1]));
    system("mkdir recv_data");
    std::vector<std::string> videoNames;
    for(int i = 0; i < video_count; ++i) {
        videoNames.push_back(std::string("recv_data/v") + std::to_string(i) + ".zmq.h264");
    }

    std::vector<ParkVideo::SocketMng*> tcpHeartSockets;
    std::vector<VideoZmqReceiver*> zmqReceivers;

    for(int j = 0; j < videoNames.size(); ++j) {
        auto sm = new ParkVideo::SocketMng(videoNames.at(j) + ".txt");
        tcpHeartSockets.emplace_back(sm);
        sm->Init(dmIp, std::to_string(tcpHeartPort + 1 * j), 0x08, 0);
        break;
    }

    StructuredData sd("recv_data/structured.bin.txt");
    sd.Init(dmIp, structuredDataPort);

    for(int i = 0;i < videoNames.size(); ++i) {
        auto videoRece = new VideoZmqReceiver();
        zmqReceivers.emplace_back(videoRece);
        videoRece->init(dmIp, videoDataPortBase + i * 1, videoNames.at(i));
    }

    while (true)     {
        std::cout << "sleep." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    sd.Deinit();

    for(auto videoRece : zmqReceivers) {
        videoRece->deinit();
    }

    for(auto sock : tcpHeartSockets) {
        sock->Deinit();
    }
    return 0;
}