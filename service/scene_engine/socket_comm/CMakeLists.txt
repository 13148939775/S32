add_compile_options(-Wall -std=c++17 -g)

add_definitions(-DRTI_UNIX -DRTI_LINUX -DRTI_64BIT)

FILE(GLOB DDS_SOURCE ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle/*.cxx)

FILE(GLOB_RECURSE PROJECT_SOURCES ${PROJECT_SOURCE_DIR}/base_library/ddsservice/dds_request/src/*.cpp)

link_directories(${PROJECT_SOURCE_DIR}/third_part/dds/lib/${LIBRARY_DIR})

link_directories(${PROJECT_SOURCE_DIR}/third_part/glog/${LIBRARY_DIR})

message(STATUS "add_excutable DDSClient")
add_executable(DDSClient
    DDSClient_entry.cpp
    ${PROJECT_SOURCES}
    ${DDS_SOURCE}
)

target_include_directories(DDSClient PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/third_part/glog/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds/hpp
    ${PROJECT_SOURCE_DIR}/third_part/glog/gloginclude

    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/service/scene_engine/socket_comm

    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/dds_request/include
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/module
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle

    ${PROJECT_SOURCE_DIR}/tools/socket

    ${PROJECT_SOURCE_DIR}/app
    ${PROJECT_SOURCE_DIR}
)

message(STATUS "add_library commLib")
add_library(commLib SHARED
    socketComm.cpp
)


message(STATUS "target_include_directories")
target_include_directories(commLib PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/tools/socket
    ${PROJECT_SOURCE_DIR}/base_library/log

    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/dds_request/include
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/module
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle

    ${PROJECT_SOURCE_DIR}/service/scene_engine/socket_comm

    ${PROJECT_SOURCE_DIR}/

    ${PROJECT_SOURCE_DIR}/third_part/dds/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds/hpp
)


message(STATUS "target_link_libraries DDSClient")


target_link_libraries(DDSClient PUBLIC
    commLib
    logLib
    libglog.so
    rticonnextmsgcpp2d
    nddscpp2d
    nddscd
    nddscored
    pthread
    -ldl -lm  -lrt -no-pie -rdynamic
)