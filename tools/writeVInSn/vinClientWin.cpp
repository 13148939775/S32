#include <iostream>
#include <winsock2.h>
#include <fstream>
#include <chrono>
#include <iomanip>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char* argv[])
{
    //写日志的文件流
    std::ofstream logfile;
    logfile.open("log.txt",std::ios_base::app);
    if (!logfile.is_open()) {
        std::cerr << "Failed to open log file" << std::endl;
        return 1;
    }
    logfile<<"---------------------------------"<<std::endl;


    // 获取当前时间
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    // 格式化时间戳为字符串
    std::tm* tm = std::localtime(&time);
    char timeBuffer[80];
    std::strftime(timeBuffer, sizeof(timeBuffer), "[%Y-%m-%d %H:%M:%S] ", tm);

    // 初始化 Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock" << std::endl;
         logfile<<timeBuffer<<"client Failed to initialize Winsock"<<std::endl;
         system("pause");
        return 1;
    }
    logfile<<timeBuffer<<"client init Winsock succeed"<<std::endl;


    // 创建套接字
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket" << std::endl;
        logfile<<timeBuffer<<"client Failed to create socket"<<std::endl;
        WSACleanup();
         system("pause");
        return 1;
    }
    logfile<<timeBuffer<<"client create socket succeed"<<std::endl;

    // 设置服务器地址和端口
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8888);
    const char* serverIp= argv[1];
    serverAddress.sin_addr.s_addr = inet_addr(serverIp);

    // 连接到服务器
    if (connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Failed to connect to server "<<argv[1] << std::endl;
        logfile<<timeBuffer<<"client failed to connect to server "<<std::endl;
        closesocket(clientSocket);
        WSACleanup();
         system("pause");
        return 1;
    }
    logfile<<timeBuffer<<"client succeed to connect to server "<<std::endl;

    std::ifstream ifile;
    ifile.open("VinSn.txt",std::ios_base::in);
    std::string buff;
    while ( getline(ifile,buff) ){

        // 获取当前时间
        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);

        // 格式化时间戳为字符串
        std::tm* tm = std::localtime(&time);
        char timeBuffer2[80];
        std::strftime(timeBuffer2, sizeof(timeBuffer), "[%Y-%m-%d %H:%M:%S] ", tm);

        if (send(clientSocket, buff.c_str(), buff.size(), 0) == SOCKET_ERROR) {
        std::cerr << "Failed to send data" << std::endl;
        logfile <<timeBuffer2<< "Failed to send data" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
         system("pause");
        return 1;
        }
       std::cout << "Data sent to server: " << buff << std::endl;
       logfile<< timeBuffer2 << "Data sent to server: " << buff << std::endl;

    }

    // 关闭套接字和清理 Winsock
    ifile.close();
    logfile.close();
    closesocket(clientSocket);
    WSACleanup();

    system("pause");

    return 0;
}
