#include "SocketMng.h"
#include "ReceiveRTPMsg.h"
#include "structureddata.h"
#include "VideoZmqReceiver.h"

#include <string>
#include <vector>

using ParkVideo::ReceiveRTPMsg;
using ParkVideo::SocketMng;

int main(int argc, char* argv[]) {
    if(2 != argc) {
        std::cout << "usage:" << argv[0] << " [camera count]" << std::endl;
        return 0;
    }

    const std::string lower_ip = "172.20.1.30";
    const uint16_t videoDataPortBase = 20000;
    const uint16_t ts_port_base = 10040;
    const uint16_t structuredDataPort = 30505;

    int video_count = std::stoi(std::string(argv[1]));
    system("mkdir recv_data");
    std::vector<std::string> video_names;
    for(int i = 0; i < video_count; ++i) {
        video_names.push_back(std::string("recv_data/v") + std::to_string(i) + ".rtp.h264");
    }


    std::vector<ParkVideo::ReceiveRTPMsg*> all_rtp;
    std::vector<SocketMng*> all_ts_socket;


    for(int j = 0; j < video_names.size(); ++j) {
        auto sm = new ParkVideo::SocketMng(video_names.at(j)+ ".txt");
        all_ts_socket.emplace_back(sm);
        sm->Init(lower_ip, std::to_string(ts_port_base + 10 * j), 0x08, 0);
    }

    StructuredData sd("recv_data/structured.bin.txt");
    sd.Init(lower_ip, structuredDataPort);

    for(int i = 0; i < video_names.size(); ++i) {
        auto rtp = new ParkVideo::ReceiveRTPMsg(video_names.at(i), 0);
        all_rtp.emplace_back(rtp);
        rtp->Init(lower_ip, std::to_string(videoDataPortBase + 10 * i), true, 0);
    }


    while (true)     {
        std::cout << "sleep." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    sd.Deinit();

    for(auto rtp : all_rtp) {
        rtp->Deinit();
    }

    for(auto ts_socket : all_ts_socket) {
        ts_socket->Deinit();
    }
    return 0;
}