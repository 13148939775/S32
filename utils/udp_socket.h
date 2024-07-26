/*
 * @author 008584
 * @for UDPSocket
 * @version 1.0
 * @date 2023.11.28
 *
 * @copyright Copyright (c) 2023
 *
 */


#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


namespace HHT
{

// socket类
class UDPSocket {
public:
    UDPSocket(int port)
    {
        port_ = port;
        sock_ = socket(PF_INET, SOCK_DGRAM, 0);
        if (sock_ == -1)
        {
            perror("socket() error");
            exit(1);
        }
        memset(&addr_, 0, sizeof(addr_));
        addr_.sin_family = AF_INET;
        addr_.sin_addr.s_addr = htonl(INADDR_ANY);
        addr_.sin_port = htons(port_);
        if (bind(sock_, (struct sockaddr *)&addr_, sizeof(addr_)) == -1)
        {
            perror("bind() error");
            exit(1);
        }
    }

    ~UDPSocket()
    {
        close(sock_);
    }

    bool SendTo(const char *data, int len, const char *ip, int port)
    {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip);
        addr.sin_port = htons(port);
        if (::sendto(sock_, data, len, 0, (struct sockaddr *)&addr, sizeof(addr)) == -1)
        {
            perror("sendto() error");
            return false;
        }
        return true;
    }

    int RecvFrom(char *buf, int len, char *ip, int &port)
    {
        struct sockaddr_in addr;
        socklen_t addrlen = sizeof(addr);
        int n = ::recvfrom(sock_, buf, len, 0, (struct sockaddr *)&addr, &addrlen);
        if (n > 0)
        {
            strcpy(ip, inet_ntoa(addr.sin_addr));
            port = ntohs(addr.sin_port);
        }
        return n;
    }

private:
    int port_;
    int sock_;
    struct sockaddr_in addr_;
};

}