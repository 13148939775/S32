cmake_minimum_required(VERSION 3.0)
add_compile_options(-Wall -std=c++17)
project(HDBMNOREQUEST)

add_compile_options("-Wno-unused-variable -Wall -Wno-sign-compare -Wno-unused-function -Werror -O0 -g -lgcov ")

set(SOURCES
    src/NoReqManager.cpp
    src/GenerateNoReq.cpp
    src/SignalTimer.cpp
)

add_library(noReqLib SHARED 
    ${SOURCES}
)

target_include_directories(noReqLib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${MASTER_ROOT}/tools/socket
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${MASTER_ROOT}/base_library/log
    ${MASTER_ROOT}/third_part/nlohmann/include  
    ${MASTER_ROOT}/service/norequest_manager/src
)


