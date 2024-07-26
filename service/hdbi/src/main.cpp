#include "DomainNode.h"
#include <exception>

int main() {
    DomainNode Hdbi_node;
    Hdbi_node.setup_signal_handlers();
    // std::thread run_parse_cmd(std::bind(&DomainNode::ParseCMDLine, &Hdbi_node));
    // run_parse_cmd.detach();
    try {
        Hdbi_node.Step();
        std::thread recv_package_socket(std::bind(&DomainNode::RecvPadSignalViaSocket, &Hdbi_node));
        recv_package_socket.detach();
        Hdbi_node.StartThread();
        Hdbi_node.WaitForShutdown();
    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return -1;
    }
    return 0;
}