cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(DataManager_recv_demo)

set(USING_ZMQ_VIDEO true)
set(USING_RTP_VIDEO true)


if(USING_ZMQ_VIDEO)
    set(ZMQ_NAME zmqVideoDemo)
    set(SRC_LIST1
        ${CMAKE_CURRENT_SOURCE_DIR}/src/SocketMng.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/structureddata.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/VideoZmqReceiver.cpp
    )

    add_executable(${ZMQ_NAME} ${SRC_LIST1} mainVideoZmq.cpp)

    target_include_directories(${ZMQ_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

    target_link_libraries(${ZMQ_NAME} PRIVATE
        zmq
    )
endif(USING_ZMQ_VIDEO)


if(USING_RTP_VIDEO)
    set(RTP_NAME rtpVideoDemo)
    set(SRC_LIST2
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ReceiveRTPMsg.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/SocketMng.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/structureddata.cpp
    )

    add_executable(${RTP_NAME} ${SRC_LIST2} mainVideoRtp.cpp)

    target_include_directories(${RTP_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        /usr/local/include/jrtplib3
    )

    target_link_libraries(${RTP_NAME} PRIVATE
        pthread
        jrtp
        jthread
        avcodec avdevice avfilter avformat avutil postproc swresample swscale
        zmq
    )
endif(USING_RTP_VIDEO)
