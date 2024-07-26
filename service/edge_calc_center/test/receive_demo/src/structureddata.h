#ifndef STRUCTURED_DATA_H
#define STRUCTURED_DATA_H

#include <zmq.hpp>
#include <zmq_addon.hpp>
#include <zmq_utils.h>

#include <thread>
#include <atomic>
#include <string>

class StructuredData {
public:
    explicit StructuredData(std::string fileName);
    ~StructuredData();
    void Init(const std::string& ip, uint16_t port);
    void Deinit();

private:
    void ReadWait();

private:
    zmq::context_t context_;
    zmq::socket_t sock_sub_;
    std::thread read_thread_;
    std::atomic_bool read_thread_quit_;
    std::string mFileName;
};


#endif // STRUCTURED_DATA_H
