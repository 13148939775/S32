#ifndef SOCKET_UDP_H
#define SOCKET_UDP_H

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "node_log.h"

class SocketUDPServer {
public:
    SocketUDPServer() {}

    ~SocketUDPServer() 
    {
        close(sock_);
    }

    bool Init(unsigned short& port)
    {
        sock_ = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock_ < 0) {
            HHT_LOG(ERROR) << "Failed to create socket." << std::endl;
            std::exit(EXIT_FAILURE);
            return false;
        }
        src_port_ = port;
        return true;
    }

    bool Bind() 
    {
        struct sockaddr_in serverAddr;
        socklen_t len = sizeof(struct sockaddr_in);
        memset(&serverAddr, 0, len); 
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(src_port_);
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        if (bind(sock_, (struct sockaddr*)&serverAddr, len) < 0) {
            HHT_LOG(ERROR) << "Failed to bind socket" << std::endl;
            return false;
        }
        return true;
    }

    bool SendPackage(const char* data, size_t len, const char* ip, unsigned short port) 
    {
        ssize_t n = sendto(sock_, data, len, 0, (struct sockaddr*) &clientAddr, clientAddrLen);
        if (n < 0) {
            HHT_LOG(ERROR) << "Server Failed to send data." << std::endl;
            return false;
        }
        return true;
    }

    bool ReceivePackage(char* buf, size_t& len) 
    {
        // 接收客户端数据
        clientAddrLen = sizeof(clientAddr);
        ssize_t recvLen = recvfrom(sock_, buf, len, 0,
                                (struct sockaddr*)&clientAddr, &clientAddrLen);
        len = recvLen;
        if (recvLen < 0) {
            HHT_LOG(ERROR) << "Failed to receive data" << std::endl;
            return false;
        }
        return true;
    }

private:
    int sock_;
    unsigned short src_port_;
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen;
};
#endif