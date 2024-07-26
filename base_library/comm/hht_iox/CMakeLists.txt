cmake_minimum_required(VERSION 3.15)

add_compile_options(-Wall -std=c++17 -g)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${MASTER_3RDPARTY_LIBS_DIR}/iceoryx-v2.0.3/include
)

link_directories(${MASTER_3RDPARTY_LIBS_DIR}/iceoryx-v2.0.3/lib/${LIBRARY_DIR})
SET(ICEORYX_LIBS
    attr
    acl
    iceoryx_hoofs
    iceoryx_posh
    iceoryx_platform
)

add_library(cppIOXPub SHARED
    cpp/server/server_comm_factory.cpp
    cpp/server/server_comm_kit.cpp
)

target_include_directories(cppIOXPub PUBLIC
    ${PROJECT_SOURCE_DIR}/base_library/comm/hht_iox
    ${PROJECT_SOURCE_DIR}/base_library/comm/hht_iox/cpp
    ${PROJECT_SOURCE_DIR}/base_library/log
)

target_link_libraries(cppIOXPub
    logLib
)

add_library(cppIOXWait SHARED
    cpp/client/client_comm_factory.cpp
    cpp/client/client_comm_kit.cpp
)

target_include_directories(cppIOXWait PUBLIC
    ${PROJECT_SOURCE_DIR}/base_library/comm/hht_iox
    ${PROJECT_SOURCE_DIR}/base_library/comm/hht_iox/cpp
    ${PROJECT_SOURCE_DIR}/base_library/log
)

target_link_libraries(cppIOXWait
    logLib
)

