#include <iostream>
#include "ReceiveRTPMsg.h"
#include <string.h>

#ifdef __linux__
#include <unistd.h>
#endif

//#undef RTP_SUPPORT_THREAD

#define RECEIVEBUF 10*1024*1024
#define GETBIT(x, y)   ((x>>y) & 1)

using ParkVideo::ReceiveRTPMsg;

ReceiveRTPMsg::ReceiveRTPMsg(std::string file, uint8_t video_index)
    : m_receive_stat(false), m_decode_exit(true), m_camera_file(file), m_trans2(file)
    , video_index_(video_index)
{
    m_save_flag = false;

}

ReceiveRTPMsg::~ReceiveRTPMsg()
{

}

void ReceiveRTPMsg::checkerror(int rtperr)
{
    if (rtperr < 0)
    {
        exit(-1);
    }
}

bool ReceiveRTPMsg::Init(const std::string ip,const std::string port,const int flag,const int iCameraIndex)
{
    m_save_flag = flag;

    if(m_save_flag)
    {
#ifdef _WIN32
        // 支持中文路径.
        m_pOutFile = _wfopen(m_camera_file.toStdWString().data(), QString("wb").toStdWString().data());
#else
        m_pOutFile = fopen(m_camera_file.data(), "wb");
#endif

        if(m_pOutFile == NULL)
        {
            return false;
        }
    }

    m_frame = av_frame_alloc();
    m_frame_rgb = av_frame_alloc();

    av_register_all();

    m_codec = avcodec_find_decoder(AV_CODEC_ID_H264);
    m_codec_ctx = avcodec_alloc_context3(m_codec);

#if 0
    switch (iCameraIndex) {
    case 0:
    case 1:
        m_codec_ctx->width = 3840;
        m_codec_ctx->height = 2160;
        break;
    default:
        m_codec_ctx->width = 1920;
        m_codec_ctx->height = 1080;
        break;
    }
#endif

    m_codec_ctx->width = 1920;
    m_codec_ctx->height = 1280;

    m_codec_ctx->pix_fmt = AV_PIX_FMT_YUV420P;

    if (int i = avcodec_open2(m_codec_ctx, m_codec, NULL) < 0)
    {
        return false;
    }

    unsigned char *out_buffer = (unsigned char *)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_RGB32, m_codec_ctx->width, m_codec_ctx->height, 1));

    av_image_fill_arrays(m_frame_rgb->data, m_frame_rgb->linesize, out_buffer,
                         AV_PIX_FMT_RGB32, m_codec_ctx->width, m_codec_ctx->height, 1);

    img_convert_ctx = sws_getContext(m_codec_ctx->width, m_codec_ctx->height, m_codec_ctx->pix_fmt,
                                     m_codec_ctx->width, m_codec_ctx->height, AV_PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL);


    //DecodeStartMsg();
    ReceiveMsgStart(ip,port,iCameraIndex);

    return true;
}

void ReceiveRTPMsg::Deinit()
{
    ReceiveMsgStop();
    DecodeStopMsg();

#ifdef _WIN32
    closesocket(m_client);
#elif __linux__
	close(m_client);
#endif

    m_total_frame = 0;
}

void ReceiveRTPMsg::ReceiveMsg(const std::string ip,const std::string port,const int iCameraIndex)
{
#ifdef RTP_SOCKETTYPE_WINSOCK
    WSADATA dat;
    WSAStartup(MAKEWORD(2,2),&dat);
#endif // RTP_SOCKETTYPE_WINSOCK

    m_file_index = iCameraIndex;
    std::cout<<"ip :"<<ip<<" port "<<port<<std::endl;
    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(atoi(port.c_str()));

    m_client = socket(AF_INET, SOCK_STREAM, 0);

    if (m_client == -1)
    {
        std::cout << "--->return::" << m_client << "\n";
        return ;
    }

    std::cout << "-->inet_addr\n";

    servAddr.sin_addr.s_addr = inet_addr(ip.c_str());//10.19.197.16 xiaweiji

#if 1
    bool bflag = false;
    while(m_receive_stat)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        if (::connect(m_client, (struct sockaddr *)&servAddr, sizeof(servAddr)) != 0)
        {
            if(!bflag)
            {
                bflag = true;
            }
            continue;
        }else{
            break;
        }

    }
#endif

    std::cout << "-->m_receive_stat::" << m_receive_stat << "\n";

    const int packSize = 61440;

    m_sess_params.SetOwnTimestampUnit(1.0/packSize);
    m_sess_params.SetMaximumPacketSize(packSize + 64); // some extra room for rtp header

    bool threadsafe = false;
#ifdef RTP_SUPPORT_THREAD
    threadsafe = true;
#endif // RTP_SUPPORT_THREAD

    checkerror(m_trans2.Init(threadsafe));

    checkerror(m_trans2.Create(65535, 0));

    checkerror(m_sess.Create(m_sess_params, &m_trans2));

    checkerror(m_sess.AddDestination(RTPTCPAddress(m_client)));


    m_buff = new char [RECEIVEBUF];

    if (nullptr == m_buff)
    {
        return ;
    }

    std::cout << "-->pack\n";

    RTPPacket *pack;
    m_packet = av_packet_alloc();
    av_init_packet(m_packet);
    m_pos  = 0;
    while (m_receive_stat)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        m_sess.BeginDataAccess();
        if (m_sess.GotoFirstSourceWithData())
        {
            do
            {
                while ((pack = m_sess.GetNextPacket()) != NULL)
                {
                    uint8_t *loaddata = pack->GetPayloadData();

                    long len = pack->GetPayloadLength();

                    std::cout << "--->len::" << len << "\n";

                    if(pack->GetPayloadType() == 96) //H264
                    {
                        if(pack->HasMarker()){

                            m_total_frame++;
                            memcpy(&m_buff[m_pos],loaddata,len);

                            // 将接收到数据写入文件中（.264文件）
                            if(m_save_flag)
                            {
                                fwrite(m_buff, 1, m_pos+len, m_pOutFile);
                            }

                            std::cout << "-->sgtGetFrameCount::" << video_index_ << m_total_frame << "\n";
                            // emit sgtGetFrameCount(video_index_, m_total_frame);

                            if(!m_decode_exit)
                            {
                                //qDebug() << "m_file_index" << m_file_index << "m_decoed_exit:" << m_decode_exit;
                                char *buff = new char [m_pos+len + 1];
                                memcpy(buff,m_buff,m_pos+len);

                                addQueueData(buff,m_pos+len);
                            }

                            if(m_total_frame % 30 == 0)
                            {
                                std::cout << "get camere frame::" << m_file_index << m_total_frame << "\n";
                            }


                            m_pos = 0;
                        }
                        else
                        {
                            memcpy(&m_buff[m_pos],loaddata,len);
                            m_pos = m_pos + len;
                        }
                    }
                    else
                    {
                    }

                    m_sess.DeletePacket(pack);

                    std::cout << "--->DeletePacket\n";

                }
            } while (m_sess.GotoNextSourceWithData());
        } else {
        }
        m_sess.EndDataAccess();

#ifndef RTP_SUPPORT_THREAD
	#ifdef _WIN32
        status = m_sess.Poll();
        checkerror(swtatus);
	#elif __linux__
		int status = m_sess.Poll();
	#endif
#endif // RTP_SUPPORT_THREAD
    }
    if (nullptr != m_buff)
    {
        delete[] m_buff;
    }

    if(m_save_flag)
    {
        fflush(m_pOutFile);
        fclose(m_pOutFile);
    }

    if(m_decode_exit)
    {
        av_frame_free(&m_frame);
        av_frame_free(&m_frame_rgb);
        avcodec_close(m_codec_ctx);  //AVCodecContext
        sws_freeContext(img_convert_ctx);
        img_convert_ctx =nullptr;
    }

//    av_frame_free(&m_frame);
//    avcodec_close(m_codec_ctx);  //AVCodecContext
//    sws_freeContext(img_convert_ctx);
//    img_convert_ctx =nullptr;
    m_sess.BYEDestroy(RTPTime(3,0),0,0);
    m_sess.Destroy();

    m_trans2.Destroy();

}

void ReceiveRTPMsg::ReceiveMsgStart(const std::string ip,const std::string port,const int iCameraIndex)
{
    m_receive_stat = true;
    m_recvthread = std::thread(&ReceiveRTPMsg::ReceiveMsg,this,ip,port,iCameraIndex);
}

void ReceiveRTPMsg::ReceiveMsgStop()
{
    if(!m_receive_stat)
    {
        return;
    }

    m_receive_stat = false;
    m_recvthread.join();
}

bool ReceiveRTPMsg::addQueueData(const char *data, long lsize)
{
    std::unique_lock<std::mutex> lck(m_lck);
    if (m_decodecachecopy.empty())
    {
        m_decodecachecopy.push(std::make_pair(data, lsize));
        m_con_var.notify_one();
    }
    else
    {
        m_decodecachecopy.push(std::make_pair(data, lsize));
    }
    lck.unlock();

    return true;
}

void ReceiveRTPMsg::DecodeMsg()
{
    while (1)
    {
        std::unique_lock<std::mutex> lck(m_lck);
        if (m_decodecachecopy.empty())
        {
            if(m_decode_exit)
            {
                lck.unlock();
                break;
            }

            m_con_var.wait(lck);

            if (m_decode_exit)
            {
                lck.unlock();
                break;
            }
        }
        else if(!m_decode_exit)
        {
            std::cout << "m_file_index" << m_file_index << "m_decodecachecopy size:" << m_decodecachecopy.size() << "\n";
            std::pair<const char *, long> decodecache = m_decodecachecopy.front();
            const char *packet = decodecache.first;
            long lsize = decodecache.second;

            av_new_packet(m_packet, lsize);
            memcpy(m_packet->data, packet, lsize);
            m_decodecachecopy.pop();
            delete [] packet;
            lck.unlock();
            int ret = avcodec_decode_video2(m_codec_ctx, m_frame, &m_got_picture, m_packet);

            if (ret > 0)
            {
                if(m_got_picture)
                {
                    sws_scale(img_convert_ctx, (const unsigned char* const*)m_frame->data,
                              m_frame->linesize, 0, m_codec_ctx->height,
                              m_frame_rgb->data, m_frame_rgb->linesize);

                    // QImage img((uchar*)m_frame_rgb->data[0],m_codec_ctx->width,m_codec_ctx->height,QImage::Format_RGB32);
                    // emit signalGetOneFrame(img);
                }
            }
            else
            {
                std::cout << "ret = " << ret << "\n";
            }
            av_free_packet(m_packet);


        }
        else
        {
            std::pair<const char *, long> decodecache = m_decodecachecopy.front();
            const char *packet = decodecache.first;
            m_decodecachecopy.pop();
            lck.unlock();
            delete [] packet;
        }
    }
}

void ReceiveRTPMsg::DecodeStartMsg()
{
    if(!m_decodethread.joinable())
    {
        m_decode_exit = false;
        m_decodethread = std::thread(&ReceiveRTPMsg::DecodeMsg,this);
    }
}

void ReceiveRTPMsg::DecodeStopMsg()
{

    std::unique_lock<std::mutex> lck(m_lck);
    if (!m_decodethread.joinable() && m_decode_exit)
    {
        lck.unlock();
        return;
    }
    m_decode_exit = true;
    //std::queue<std::pair<const char*, long>> empty;
    //swap(m_decodecachecopy ,empty);
    m_con_var.notify_one();
    lck.unlock();
    m_decodethread.join();

}

void ReceiveRTPMsg::ParseNaluData(const unsigned int naluLen, unsigned char* const nuluData)
{
    static int naluNum = 0;

    unsigned char *data = NULL;
    char priorityStr[PRTNTF_STR_LEN+1] = {0};
    char typeStr[PRTNTF_STR_LEN+1] = {0};

    T_H264_NALU_HEADER h264NaluHeader = {0};

    data = nuluData;

    memset(&h264NaluHeader, 0x0, sizeof(T_H264_NALU_HEADER));
    h264NaluHeader.nal_unit_type = data[0] & 0x1f;
    h264NaluHeader.nal_reference_idc = data[0]>>5 & 0x3;


    naluNum++;


    switch (h264NaluHeader.nal_reference_idc)
    {
    case NALU_PRIORITY_DISPOSABLE:
        sprintf(priorityStr, "DISPOS");
        break;

    case NALU_PRIORITY_LOW:
        sprintf(priorityStr, "LOW");
        break;

    case NALU_PRIORITY_HIGH:
        sprintf(priorityStr, "HIGH");
        break;

    case NALU_PRIORITY_HIGHEST:
        sprintf(priorityStr, "HIGHEST");
        break;

    default:
        break;
    }

    switch (h264NaluHeader.nal_unit_type)
    {
    case NALU_TYPE_SLICE:
        sprintf(typeStr, "SLICE");
        break;

    case NALU_TYPE_DPA:
        sprintf(typeStr, "DPA");
        break;

    case NALU_TYPE_DPB:
        sprintf(typeStr, "DPB");
        break;

    case NALU_TYPE_DPC:
        sprintf(typeStr, "DPC");
        break;

    case NALU_TYPE_IDR:
        sprintf(typeStr, "IDR");
        break;

    case NALU_TYPE_SEI:
        sprintf(typeStr, "SEI");
        break;

    case NALU_TYPE_SPS:
        sprintf(typeStr, "SPS");
        break;

    case NALU_TYPE_PPS:
        sprintf(typeStr, "PPS");
        break;

    case NALU_TYPE_AUD:
        sprintf(typeStr, "AUD");
        break;

    case NALU_TYPE_EOSEQ:
        sprintf(typeStr, "EOSEQ");
        break;

    case NALU_TYPE_EOSTREAM:
        sprintf(typeStr, "EOSTREAM");
        break;

    case NALU_TYPE_FILL:
        sprintf(typeStr, "FILL");
        break;

    default:
        //printf("typeStr ===== %d\n", h264NaluHeader.nal_unit_type);
        break;
    }

    printf("%5d| %7s| %6s| %8d|\n", naluNum, priorityStr, typeStr, naluLen);
    std::cout << "priorityStr = " << priorityStr << "\n" << "typeStr = " << typeStr << "\n" << "naluLen = " << naluLen << "\n";

}
