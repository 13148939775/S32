#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

const int PORT = 8888;
const int BUFFER_SIZE = 1024;

int main() {
    // 创建socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error: Failed to create socket." << std::endl;
        return 1;
    }

    // 绑定地址和端口
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error: Failed to bind address." << std::endl;
        close(serverSocket);
        return 1;
    }

    // 监听连接
    if (listen(serverSocket, 1) == -1) {
        std::cerr << "Error: Failed to listen for connections." << std::endl;
        close(serverSocket);
        return 1;
    }

    std::cout << "Server started. Listening on port " << PORT << std::endl;

    // 接受连接
    sockaddr_in clientAddress;
    socklen_t clientAddressLength = sizeof(clientAddress);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);
    if (clientSocket == -1) {
        std::cerr << "Error: Failed to accept connection." << std::endl;
        close(serverSocket);
        return 1;
    }

    // 读取客户端发送的数据
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    std::stringstream receivedData;
    while ((bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0)) > 0) {
        receivedData.write(buffer, bytesRead);
    }

    // 将接收到的数据写入文件
    std::ofstream outputFile("/home/root/log/received_data.txt");
    if (!outputFile) {
        std::cerr << "Error: Failed to open output file." << std::endl;
        close(clientSocket);
        close(serverSocket);
        return 1;
    }

    outputFile << receivedData.str();

    // 关闭文件和连接
    outputFile.close();
    close(clientSocket);
    close(serverSocket);

    return 0;
}
