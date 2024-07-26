#ifndef SOCKET_UDP_CLIENT_H
#define SOCKET_UDP_CLIENT_H

#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstring>
#include <unistd.h>
#include <string>
#include <iostream>
 
#include "node_log.h"
 
class SocketUDPClient {
public:
    SocketUDPClient()
    {

    }

    bool Init(const unsigned short& port, const char* ip)
    {
        // 创建UDP套接字
        client_socket_ = socket(AF_INET, SOCK_DGRAM, 0);
        if (client_socket_ == -1) {
            HHT_LOG(ERROR)<< "Failed to create socket.";
        }
        port_ = port;

        socklen_t len = sizeof(struct sockaddr_in);
        
        memset(&clientaddr_, 0, len);
    
        clientaddr_.sin_family = AF_INET;
        clientaddr_.sin_port = htons(port);
        clientaddr_.sin_addr.s_addr = INADDR_ANY;
        return true;
    }


    ~SocketUDPClient() 
    {
        close(client_socket_);
    }
 
    bool SendPackage(const char* data, size_t len, const char* ip, unsigned short port) 
    {
        struct sockaddr_in addr;
        std::memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip);
        addr.sin_port = htons(port);
        ssize_t n = sendto(client_socket_, data, len, 0, (struct sockaddr*) &addr, sizeof(addr));
        if (n < 0) {
            HHT_LOG(ERROR) << "Failed to send data." << std::endl;
            return false;
        }
        return true;
    }

    bool ReceivePackage(char* buf, size_t& len, const unsigned short& port) 
    {
        socklen_t addrlen = sizeof(clientaddr_);
        memset(buf, 0, sizeof(len));
        ssize_t recvLen = recvfrom(client_socket_, buf, len, 0, (struct sockaddr*)&clientaddr_, &addrlen);
        len = recvLen;
        if (recvLen < 0) {
            HHT_LOG(ERROR) << "Client Failed to receive data." << std::endl;
            return false;
        }
        return true;
    }

private:
    int client_socket_;
    unsigned int port_;
    struct sockaddr_in clientaddr_;
};

#endif