#ifndef RECEIVERTPMSG_H
#define  RECEIVERTPMSG_H

#ifdef _WIN32
#include <WinSock2.h>
#include <windows.h>
#endif

#include <time.h>
#include <string>
#include <thread>
#include <string>
#include <atomic>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <iostream>

#include "rtppacket.h"
#include "rtperrors.h"
#include "rtpsession.h"
#include "rtptcpaddress.h"
#include "rtpsourcedata.h"
#include "rtpipv4address.h"
#include "rtpsessionparams.h"
#include "rtptcptransmitter.h"
#include "rtpudpv4transmitter.h"

#include <queue>
#include <mutex>
#include <condition_variable>

#ifdef _WIN32
#include <QImage>
#include <QDebug>
#include <QString>
#include <QThread>
#include <QMutex>
#include "qwidget.h"
#endif

using namespace jrtplib;
using namespace std;
extern "C"{

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}

//typedef struct CodecCtx_ {
//       AVPacket pkt;
//       AVCodec *pCodec;
//       AVCodecContext *pCodecContext;
//       AVCodecParserContext *pCodecParserCtx;
//       AVFrame *frame;

//   }CodecCtx;

namespace ParkVideo {

//重新封装一个类
class MyRTPSession : public RTPSession
{
public:
    MyRTPSession() : RTPSession() { }
    ~MyRTPSession() { }
protected:
    void OnNewSource(RTPSourceData *dat)
    {
        uint32_t ip;
        uint16_t port;
        if (dat->IsOwnSSRC())
        {
            return;
        }
        if (dat->GetRTPDataAddress() != 0)
        {
            const RTPIPv4Address *addr = (const RTPIPv4Address *)(dat->GetRTPDataAddress());
            ip = addr->GetIP();
            port = addr->GetPort();
            std::cout << "Adding destination GetRTPDataAddress "  << std::endl;
        }
        else if (dat->GetRTCPDataAddress() != 0)
        {
            const RTPIPv4Address *addr = (const RTPIPv4Address *)(dat->GetRTCPDataAddress());
            ip = addr->GetIP();
            port = addr->GetPort()-1;
            std::cout << "Adding destination GetRTCPDataAddress "  << std::endl;
        }
        else
        {

            return;
        }
        

        RTPIPv4Address dest(ip,port);
        AddDestination(dest);

        struct in_addr inaddr;
        inaddr.s_addr = htonl(ip);
        std::cout << "Adding destination " << std::string(inet_ntoa(inaddr)) << ":" << port << std::endl;
    }

    void OnBYEPacket(RTPSourceData *dat)
    {
        if (dat->IsOwnSSRC())
            return;

        uint32_t ip;
        uint16_t port;

        if (dat->GetRTPDataAddress() != 0)
        {
            const RTPIPv4Address *addr = (const RTPIPv4Address *)(dat->GetRTPDataAddress());
            ip = addr->GetIP();
            port = addr->GetPort();
        }
        else if (dat->GetRTCPDataAddress() != 0)
        {
            const RTPIPv4Address *addr = (const RTPIPv4Address *)(dat->GetRTCPDataAddress());
            ip = addr->GetIP();
            port = addr->GetPort()-1;
        }
        else
            return;

        RTPIPv4Address dest(ip,port);
        DeleteDestination(dest);

        struct in_addr inaddr;
        inaddr.s_addr = htonl(ip);
        std::cout << "Deleting destination " << std::string(inet_ntoa(inaddr)) << ":" << port << std::endl;
    }

    void OnRemoveSource(RTPSourceData *dat)
    {
        if (dat->IsOwnSSRC())
            return;
        if (dat->ReceivedBYE())
            return;

        uint32_t ip;
        uint16_t port;

        if (dat->GetRTPDataAddress() != 0)
        {
            const RTPIPv4Address *addr = (const RTPIPv4Address *)(dat->GetRTPDataAddress());
            ip = addr->GetIP();
            port = addr->GetPort();
        }
        else if (dat->GetRTCPDataAddress() != 0)
        {
            const RTPIPv4Address *addr = (const RTPIPv4Address *)(dat->GetRTCPDataAddress());
            ip = addr->GetIP();
            port = addr->GetPort()-1;
        }
        else
            return;

        RTPIPv4Address dest(ip,port);
        DeleteDestination(dest);

        struct in_addr inaddr;
        inaddr.s_addr = htonl(ip);
        std::cout << "Deleting destination " << std::string(inet_ntoa(inaddr)) << ":" << port << std::endl;
    }
public:
    // MyRTPSession(MyRTPSession&& rv) = default;
};



class MyTCPTransmitter : public RTPTCPTransmitter
{
public:
    MyTCPTransmitter(const std::string &name) : RTPTCPTransmitter(0), m_name(name) { }

    void OnSendError(SocketType sock)
    {
        //std::cout << m_name << ": Error sending over socket " << sock << ", removing destination" << std::endl;
        DeleteDestination(RTPTCPAddress(sock));
    }

    void OnReceiveError(SocketType sock)
    {
        //std::cout << m_name << ": Error receiving from socket " << sock << ", removing destination" << std::endl;
        DeleteDestination(RTPTCPAddress(sock));
    }
private:
    std::string m_name;
};
#define PRTNTF_STR_LEN 10
typedef struct t_h264_nalu_header
{
    unsigned char forbidden_bit:1, nal_reference_idc:2, nal_unit_type:5;
} T_H264_NALU_HEADER;
typedef enum e_h264_nalu_priority
{
    NALU_PRIORITY_DISPOSABLE     = 0,
    NALU_PRIORITY_LOW             = 1,
    NALU_PRIORITY_HIGH           = 2,
    NALU_PRIORITY_HIGHEST        = 3,
} E_H264_NALU_PRIORITY;

typedef enum e_h264_nalu_type
{
    NALU_TYPE_SLICE        = 1,
    NALU_TYPE_DPA          = 2,
    NALU_TYPE_DPB          = 3,
    NALU_TYPE_DPC          = 4,
    NALU_TYPE_IDR          = 5,
    NALU_TYPE_SEI          = 6,
    NALU_TYPE_SPS          = 7,
    NALU_TYPE_PPS          = 8,
    NALU_TYPE_AUD          = 9,
    NALU_TYPE_EOSEQ        = 10,
    NALU_TYPE_EOSTREAM     = 11,
    NALU_TYPE_FILL         = 12,
} E_H264_NALU_TYPE;


class ReceiveRTPMsg {
public:
    ReceiveRTPMsg(std::string file, uint8_t video_index);
    ~ReceiveRTPMsg();
    bool Init(const std::string ip,const std::string port,const int flag,const int iCameraIndex);
    void Deinit();

private:
    void ReceiveMsg(const std::string ip,const std::string port,const int iCameraIndex);
    void ReceiveMsgStart(const std::string ip,const std::string port,const int iCameraIndex);
    void ReceiveMsgStop();
    void DecodeStartMsg();
    void DecodeStopMsg();
    void DecodeMsg();
    void checkerror(int rtperr);
    bool addQueueData(const char* data,long lsize);
    void ParseNaluData(const unsigned int naluLen, unsigned char* const nuluData);

private:

    char* m_buff;
    long m_pos = 0;
    bool m_decode_exit;
    bool m_receive_stat;
    int  m_got_picture = 0;
    int  m_file_index =0;
    bool  m_save_flag;
    int  m_total_frame =0;

    std::thread m_recvthread;
    std::thread m_decodethread;

    std::string m_camera_file;

    FILE *m_pOutFile = nullptr;
    AVFrame *m_frame;
    AVCodec *m_codec;
    AVFrame	*m_frame_rgb;
    AVPacket *m_packet;

    SocketType m_client;
    MyRTPSession m_sess;
    AVCodecContext *m_codec_ctx;
    MyTCPTransmitter m_trans2;
    RTPSessionParams m_sess_params;
    struct SwsContext *img_convert_ctx;

    std::mutex m_lck;
    std::condition_variable m_con_var;
    std::queue<std::pair<const char*, long>> m_decodecachecopy;

    const uint8_t video_index_;
};

}   // ParkVideo

#endif
