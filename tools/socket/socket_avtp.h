/*
 * @author 08555
 * @for signal ipcf someip pfe receive
 * @version 0.1
 * @date 2023-10
 * @copyright Copyright (c) 2023
 */

#ifndef SOCKET_AVTP_H
#define SOCKET_AVTP_H

#include <cstring>
#include <iostream>

#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <netinet/ether.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <net/if.h>

#include "node_log.h"

class SocketAVTP {
public:
    SocketAVTP() { }

    ~SocketAVTP()
    {
        close(sockFd_);
    }

    bool Init()
    {
        sockFd_ = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
        if (sockFd_ < 0) {
            HHT_LOG(ERROR) << "Failed to create socket." << std::endl;
            return false;
        }

        return true;
    }

    bool Bind(const char* NI)
    {
        struct sockaddr_ll sockAddr_;
        memset(&sockAddr_, 0, sizeof(sockAddr_));
        sockAddr_.sll_family = AF_PACKET;
        sockAddr_.sll_protocol = htons(ETH_P_ALL);
        sockAddr_.sll_ifindex = if_nametoindex(NI);
        if (bind(sockFd_, (struct sockaddr *)&sockAddr_, sizeof(sockAddr_)) < 0) {
            HHT_LOG(ERROR) << "Failed to bind interface " << NI << std::endl;
            close(sockFd_);
            return false;
        }
        return true;
    }

    bool ReceivePackage(char* buf, const size_t& len)
    {
        ssize_t length = recv(sockFd_, buf, len, 0);
        if (length < 0) {
            HHT_LOG(ERROR) << "Failed to receive data." << std::endl;
            close(sockFd_);
            return false;
        }
        return true;
    }

private:
    int sockFd_;
};
#endif