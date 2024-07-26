#include <iostream>
#include "SocketMng.h"
#include <string.h>

#ifdef __linux__
#include <unistd.h>
#endif

#define RECEIVEBUF 10*1024*1024
#define GETBIT(x, y)   ((x>>y) & 1)

using ParkVideo::SocketMng;

SocketMng::SocketMng(std::string file)
:socketFd(-1),m_buf(nullptr),m_stat(false),m_run(true),time_stramp_file(file)
{
    //std::string log_frame_name =  "Time.txt";
    m_pOutFile = nullptr;
}


bool SocketMng::Init(const std::string ip,const std::string port,const int flag,const int iCameraIndex)
{
    std::cout<<" SocketMng ip :"<<ip<<" port "<<port<<std::endl;
    m_close_flag = flag;
    m_FileIndex = iCameraIndex;
  #if 0
    struct tm *locatime = NULL;
    time_t timedata;
    time(&timedata);
    locatime = localtime(&timedata);
    if(locatime == NULL){
        return false;
    }
    char data[64];
    memset(data,0,64);
    sprintf(data,"_%04d%02d%02d%02d%02d%02d",locatime->tm_year+1900,locatime->tm_mon+1,locatime->tm_mday,locatime->tm_hour,locatime->tm_min,locatime->tm_sec);
    std::string datatmp(data);
     std::string strtime = time_stramp_file;
    strtime.insert(strtime.find_last_of('.'),"_");
    strtime.insert(strtime.find_last_of('.'),port);
    strtime.insert(strtime.find_last_of('.'),datatmp);
    strtime.insert(strtime.find_last_of('.'),"_");
    strtime.insert(strtime.find_last_of('.'),std::to_string(iCameraIndex));
   // std::cout<<"time_stramp_file : "<<time_stramp_file<<std::endl;
  #endif
    if(GETBIT(m_close_flag,3) == 1)
    {
//        m_pOutFile = fopen(time_stramp_file.c_str(), "wb");
#ifdef _WIN32
        // 支持中文路径.
        m_pOutFile = _wfopen(time_stramp_file.toStdWString().data(), QString("wb").toStdWString().data());
#else
        // m_pOutFile = fopen(time_stramp_file.data(), "wb");
#endif
        // if (!m_pOutFile) {
        //     // std::cout<<"file is empty!!!!"<<std::endl;
        //     return false;
        // }
    }

   //m_recvthread.reset(new std::thread(&SocketMng::ReceiveMsg, this));
     m_recvthread = std::thread(&SocketMng::ReceiveMsg,this,ip,port,iCameraIndex);
     //m_recvthread.detach();
    return true;
}

void SocketMng::ReceiveMsg(const std::string ip,const std::string port,const int iCameraIndex)
{



    struct sockaddr_in servAddr;

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(atoi(port.c_str()));
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd == -1)
    {
       // std::cout << "Can't create client socket" << std::endl;
        return ;
    }

    servAddr.sin_addr.s_addr = inet_addr(ip.c_str());//10.19.197.16 xiaweiji
    Start();
    bool bflag = false;
    while(m_run)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        if (connect(socketFd, (struct sockaddr *)&servAddr, sizeof(servAddr)) != 0)
        {
            //std::cout << "Can't connect to the listener socket" << std::endl;
            //std::cout<<strerror(errno)<<std::endl;
            if(!bflag)
            {
               bflag = true;
            }

            continue;
        }else{
            break;
        }

    }
    // int Timeout = 1000;
    // setsockopt(socketFd,SOL_SOCKET,SO_RCVTIMEO,(char*)&Timeout,sizeof(int));

    m_buf = new char [RECEIVEBUF];
    if (nullptr == m_buf)
    {
       // ERROR_LOG<<"recieve buffer malloc failed !";
       //std::cout<<"recieve buffer malloc fail !"<<std::endl;
        return ;
    }

    int size = 0;
    // m_run.store(true,std::memory_order::memory_order_seq_cst);
     //m_stat = true;
     //int ii = 0;
    H264TimeStamp oH264TimeStamp;

    //std::cout<<"TimeStramp ReceiveMsg start!!!!!\n"<<std::endl;
    //while(m_run.load(std::memory_order::memory_order_seq_cst))
    while(m_run)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
       // std::cout<<"ReceiveMsg1 !"<<std::endl;
        //{
        //    std::unique_lock<std::mutex> lck(m_lckstat);
        //    m_convar_stat.wait(lck);
        //}

       // while (m_stat.load())
        while (m_stat)
        {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
            memset(m_buf,0,RECEIVEBUF);
            size = recv (socketFd, m_buf, RECEIVEBUF, 0);//it is block recive
            if(0 == size) {
                continue;
            }
            std::string data(m_buf,size);

            std::cout << "-->receive_size::" << size << std::endl;
            memcpy(&oH264TimeStamp,data.c_str(),sizeof(H264TimeStamp));

            std::string time_stamp = std::to_string(oH264TimeStamp.iFrameIndex) + ", " + std::to_string(oH264TimeStamp.TimeStamp) + "\n";


            // if (fwrite(time_stamp.c_str(), time_stamp.size(), 1, m_pOutFile) == 0u) {
            //     //std::cout<<"File write failed\n"<<std::endl;
            // }
            // fflush(m_pOutFile);
            continue;



//            std::cout << "--->timestamps::" << data << std::endl;
            //std::cout<<"recv = "<<size<<std::endl;
            if(size >0 && size <= sizeof(H264TimeStamp)){

                //std::cout<<"recv = "<<size<<std::endl;

                memcpy(&oH264TimeStamp,data.c_str(),sizeof(H264TimeStamp));

               std::string time_stamp = std::to_string(oH264TimeStamp.iFrameIndex) + "  TimeStamp:" + std::to_string(oH264TimeStamp.TimeStamp) + "\n";
                // std::string time_stamp = data;
                std::cout << "timestamp:" << time_stamp << std::endl;
                if(GETBIT(m_close_flag,3) == 1)
                {
                    if (fwrite(time_stamp.c_str(), time_stamp.size(), 1, m_pOutFile) == 0u) {
                        //std::cout<<"File write failed\n"<<std::endl;
                    }
                    fflush(m_pOutFile);
                }

                m_total_count++;
                if(m_total_count % 1000 == 0){
                    //std::cout<<"Camera_"<<m_FileIndex<<" Timestamp  receiving !!! receive Num =  " << m_total_count<<std::endl;

                    // m_FileIndex++;
                    // if (m_pOutFile != nullptr) {
                    //     fflush(m_pOutFile);
                    //     fclose(m_pOutFile);
                    // }
                    // time_stramp_file = time_stramp_file.substr(0,time_stramp_file.find_last_of("_"));
                    // time_stramp_file +="_";
                    // time_stramp_file +=std::to_string(m_FileIndex);
                    // time_stramp_file +=".txt";
                    // m_pOutFile = fopen(time_stramp_file.c_str(), "wb");

                    // //m_pOutFile = fopen("./recv_neu.264","wb");
                    // if(m_pOutFile == NULL)
                    // {
                    //     printf("File open fail!\n");
                    //     return;
                    // }


                }

               // ii++;
            }else if(size > sizeof(H264TimeStamp)){
                //std::cout<<"recv = "<<size<<std::endl;
                int k=0,l=0;
                k = size / sizeof(H264TimeStamp);
                l = size % sizeof(H264TimeStamp);
                int t=0;
                while( t < k || ( t==k && l>0 ) )
		        {
			        if( (0 == t ) || ( t<k && 0!=t ) )
			        {
                        H264TimeStamp oH264TimeStamp;
                        memcpy(&oH264TimeStamp,&data.c_str()[t*sizeof(H264TimeStamp)],sizeof(H264TimeStamp));
//                        std::string time_stamp = std::to_string(oH264TimeStamp.iFrameIndex) + "  TimeStamp:" + std::to_string(oH264TimeStamp.TimeStamp) + "\n";
                        std::string time_stamp = data;
                        //std::cout<<time_stamp<<std::endl;
                        if(GETBIT(m_close_flag,3) == 1)
                        {
                            if (fwrite(time_stamp.c_str(), 1,time_stamp.size(), m_pOutFile) == 0u) {
                                //std::cout<<"File write failed\n"<<std::endl;
                            }
                             fflush(m_pOutFile);
                        }

                         m_total_count++;
                        if(m_total_count % 1000 == 0){
                              //std::cout<<"Camera_"<<m_FileIndex<<" Timestamp  receiving !!! receive Num =  " << m_total_count<<std::endl;

                            // m_FileIndex++;
                            // if (m_pOutFile != nullptr) {
                            //     fflush(m_pOutFile);
                            //     fclose(m_pOutFile);
                            // }
                            // time_stramp_file = time_stramp_file.substr(0,time_stramp_file.find_last_of("_"));
                            // time_stramp_file +="_";
                            // time_stramp_file +=std::to_string(m_FileIndex);
                            // time_stramp_file +=".txt";
                            // m_pOutFile = fopen(time_stramp_file.c_str(), "wb");

                            // //m_pOutFile = fopen("./recv_neu.264","wb");
                            // if(m_pOutFile == NULL)
                            // {
                            //     printf("File open fail!\n");
                            //     return ;
                            // }
                        }

                        //i++;
                        t++;
                    }
                    else if( ( k==t && l>0 ) || ( t== (k-1) && l==0 ))
			        {
                        int iSendLen;
                        if ( l > 0)
                        {
                            iSendLen = size - t*sizeof(H264TimeStamp);
                        }
                        else
                        {
                            iSendLen = sizeof(H264TimeStamp);
                        }
                        H264TimeStamp oH264TimeStamp;
                        memcpy(&oH264TimeStamp,&data.c_str()[t*sizeof(H264TimeStamp)],iSendLen);
//                        std::string time_stamp = std::to_string(oH264TimeStamp.iFrameIndex) + "  TimeStamp:" + std::to_string(oH264TimeStamp.TimeStamp) + "\n";
                        std::string time_stamp = data;
                        //std::cout<<time_stamp<<std::endl;
                        if(GETBIT(m_close_flag,3) == 1)
                        {
                            if (fwrite(time_stamp.c_str(), 1,time_stamp.size(), m_pOutFile) == 0u) {
                                //std::cout<<"File write failed\n"<<std::endl;
                            }
                            fflush(m_pOutFile);
                        }

                         m_total_count++;
                        if(m_total_count % 1000 == 0){
                             //std::cout<<"Camera_"<<m_FileIndex<<" Timestamp  receiving !!! receive Num =  " << m_total_count<<std::endl;
                            // m_FileIndex++;
                            // if (m_pOutFile != nullptr) {
                            //     fflush(m_pOutFile);
                            //     fclose(m_pOutFile);
                            // }
                            // time_stramp_file = time_stramp_file.substr(0,time_stramp_file.find_last_of("_"));
                            // time_stramp_file +="_";
                            // time_stramp_file +=std::to_string(m_FileIndex);
                            // time_stramp_file +=".txt";
                            // m_pOutFile = fopen(time_stramp_file.c_str(), "wb");

                            // //m_pOutFile = fopen("./recv_neu.264","wb");
                            // if(m_pOutFile == NULL)
                            // {
                            //     printf("File open fail!\n");
                            //     return ;
                            // }
                        }

                        //ii++;
                        t++;
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

    }
    if (nullptr != m_buf)
    {
        delete m_buf;
    }
//    time_stramp_file.clear();
   // INFO_LOG<<"SocketMng ReceiveMsg Thread exit !";
    //std::cout<<"TimeStramp ReceiveMsg Thread exit !!!!!!\n"<<std::endl;
    return ;
}

void SocketMng::Start()
{
    //std::unique_lock<std::mutex> lck(m_lckstat);
    // m_run.store(true,std::memory_order::memory_order_seq_cst);
    // m_stat.store(true,std::memory_order::memory_order_seq_cst);
     m_run = true;
     m_stat = true;

   // m_convar_stat.notify_one();
    //INFO_LOG<<"SocketMng Start Receive Msg !";
}

void SocketMng::Stop()
{
    //std::unique_lock<std::mutex> lck(m_lckstat);
    //m_stat.store(false,std::memory_order::memory_order_seq_cst);
    m_stat = false;
    m_run = false;
    //INFO_LOG<<"SocketMng Stop Receive Msg !";
}

void SocketMng::Deinit()
{
    if(!m_run)
    {
        return;
    }
    Stop();
    m_recvthread.join();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //m_run.store(false,std::memory_order::memory_order_seq_cst);
    m_run = false;
    //Stop();
    //cancel thread
    if(GETBIT(m_close_flag,3) == 1)
    {
        if (m_pOutFile != nullptr) {
            //std::cout<<"SocketMng::Deinit() 1 " <<std::endl;
          fflush(m_pOutFile);
          fclose(m_pOutFile);
        }
    }

    // if (m_recvthread != nullptr) {
    //     std::cout<<"SocketMng::Deinit() 1 " <<std::endl;
	// 	//m_recvthread->join();
    //     std::cout<<"SocketMng::Deinit() 2 " <<std::endl;
	// 	//m_recvthread.reset();
	// }
    std::cout<<"SocketMng::Deinit() 3 " <<std::endl;
#ifdef _WIN32
    closesocket(socketFd);
#elif __linux__
	close(socketFd);
#endif

    m_total_count = 0;
    //std::cout<<"Time count = "<<m_total_count<<std::endl;
}
 SocketMng::~SocketMng()
 {
      //Deinit();
 }

 //int size = zmq_send(publisher,res.c_str(), res.size(), 0);
