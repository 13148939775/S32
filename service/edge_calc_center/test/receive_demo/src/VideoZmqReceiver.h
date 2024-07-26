#include <atomic>
#include <thread>
#include <memory>

#include <zmq.h>
#include <zmq.hpp>


class VideoZmqReceiver {
private:
    /* data */
public:
    VideoZmqReceiver(/* args */);
    ~VideoZmqReceiver();

    void init(std::string ip, uint16_t port, std::string filePath);
    void deinit();

private:
    void runRecv(std::string filePath);

private:
    std::atomic_bool mThreadQuit;
    std::thread mRecvThread;
    zmq::context_t mCtx;
    std::shared_ptr<zmq::socket_t> mReceiver;
};
