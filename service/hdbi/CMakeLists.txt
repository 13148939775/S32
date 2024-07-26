cmake_minimum_required(VERSION 3.15)
project(app_hdbi)
add_definitions(-DRTI_UNIX -DRTI_LINUX -DRTI_64BIT)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -fPIC -O2")
# message(STATUS "===========>project:${PROJECT_NAME}<===========")

FILE(GLOB_RECURSE PROJECT_SOURCES
    ${MASTER_ROOT}/base_library/comm/message/*.cxx
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

link_directories(
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/lib/${LIBRARY_DIR}
    ${MASTER_3RDPARTY_LIBS_DIR}/glog/${LIBRARY_DIR}
)

set(RTI_DDS_LIBRARIES
    rticonnextmsgcpp2d
    nddscpp2d
    nddscd
    nddscored
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
    # dds
    ${MASTER_ROOT}/base_library/comm/hht_dds/include
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/include
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/include/ndds
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/include/ndds/hpp
    # glog
    ${MASTER_ROOT}/base_library/log
    # thread
    ${MASTER_ROOT}/utils/OSPosix/inc
    # socket
    ${MASTER_ROOT}/tools/socket
)
target_link_libraries(${PROJECT_NAME} ${RTI_DDS_LIBRARIES} OSPosix logLib -ldl -lm -lpthread -lrt -no-pie -rdynamic)
