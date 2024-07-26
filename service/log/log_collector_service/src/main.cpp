/*
 * @author 008584
 * @for log_collector_service
 * @version 1.0
 * @date 2023.11.28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "macros.h"
#include "udp_socket.h"

int main() {
    char buf[BUFFER_LENGTH];
    HHT::UDPSocket udp_socket(UDP_PORT);

    char source_ip[16];
    int source_port;


    while (true) {
        int len = udp_socket.RecvFrom(buf, BUFFER_LENGTH, source_ip, source_port);
        if (len < 0)
        {
            memset(buf, 0, sizeof(buf) - 1);
            continue;
        }
        udp_socket.SendTo(buf, sizeof(buf)/sizeof(buf[0]), source_ip, source_port);
    }

    return 0;
}