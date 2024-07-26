#ifndef SOCKETMNG_H
#define  SOCKETMNG_H
//#include "zmq.h"
#include <iostream>
#include <thread>
#include <string>
#include <atomic>
#ifndef WIN32
#include <netinet/in.h>
#include <arpa/inet.h>
#else
#include <WinSock2.h>
#include <windows.h>
#endif // WIN32

//#include <sys/socket.h>
//#include <unistd.h>
#include <time.h>
#include <string.h>

typedef struct {
    uint64_t iFrameIndex;
    uint64_t TimeStamp;
}H264TimeStamp;
//#define MAX_PKT_LENGTH 16 //1360

namespace ParkVideo {

class SocketMng 
{
    private:
        int socketFd; 
        char* m_buf;
        std::thread m_recvthread;
        //std::unique_ptr<std::thread> m_recvthread = nullptr;
        //std::atomic<bool> m_stat;

        //stop receive msg
        //std::atomic<bool> m_run;

        FILE *m_pOutFile = nullptr;
        std::string time_stramp_file;
        int m_total_count =0;
        int m_FileIndex = 0;
        int m_close_flag = 0;

        bool m_stat = false;
        bool m_run = false;

    public:
        SocketMng(std::string file);
        ~SocketMng();    
        SocketMng(SocketMng&& rv) = default;
        // s
        // {
        //     std::cout<<"SocketMng(SocketMng&& rv) invoke "<<std::endl;
        //     this->socketFd = rv.socketFd;
        //     this->m_buf = rv.m_buf;
        //     this->m_recvthread = std::move(rv.m_recvthread);
        //     this->m_stat = rv.m_stat;
        //     this->m_run = rv.m_run;
        //     this->m_pOutFile = rv.m_pOutFile;
        //     this->time_stramp_file = rv.time_stramp_file;
        //     this->m_total_count = rv.m_total_count;
        //     rv.m_buf = nullptr;
        //     rv.m_pOutFile = nullptr;
        // }
        // SocketMng(const SocketMng&sockmng)
        // {
        //     socketFd = sockmng.socketFd;
        //     m_buf = new char[strlen(sockmng.m_buf)+1];
        //     strncpy(m_buf,sockmng.m_buf,strlen(sockmng.m_buf)+1);
        //     m_pOutFile = sockmng.m_pOutFile;
        //     m_recvthread.swap(sockmng.m_recvthread);
        // } 
        bool Init(const std::string ip,const std::string port,const int flag,const int iCameraIndex);
        void Deinit();

private:
        void ReceiveMsg(const std::string ip,const std::string port,const int iCameraIndex);
        //void ReceiveMsg(void* local);
        //void join() {m_recvthread.join();}
        void Start();     
        void Stop();   

        
};

}   // ParkVideo

#endif
