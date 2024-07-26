link_directories(${MASTER_3RDPARTY_LIBS_DIR}/iceoryx-v2.0.3/lib/${LIBRARY_DIR})

SET(ICEORYX_LIBS
    attr
    acl
    iceoryx_hoofs
    iceoryx_posh
    iceoryx_platform
)
add_library(CCCLib SHARED
    buffer_manager/buf_pool.cpp
    signal_inject/signal_inject.cpp
    data_storage/recorder_mode/signal_store_ctrl.cpp
    signal_receive/signal_ipcf/signal_ipcfrecv.cpp
    signal_receive/signal_pfe/signal_pferecv.cpp
    signal_receive/signal_someip/signal_subscriber.cpp
)

target_include_directories(CCCLib PUBLIC
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/service/app_manager
    ${PROJECT_SOURCE_DIR}/tools
    ${PROJECT_SOURCE_DIR}/utils/OSPosix/inc
    ${PROJECT_SOURCE_DIR}/service/edge_calc_center
    ${PROJECT_SOURCE_DIR}/base_library/rdb

    ${MASTER_ROOT}/base_library/comm/hht_iox
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${MASTER_3RDPARTY_LIBS_DIR}/iceoryx-v2.0.3/include
)

target_link_libraries(CCCLib
    OSPosix
    logLib
    ${ICEORYX_LIBS}
    pthread
    ${PROJECT_SOURCE_DIR}/third_part/sqlite/${LIBRARY_DIR}/libsqlite3.so.0.8.6
    rdbLib
)


add_executable(CCCEntry
    ccc_entry.cpp
)

target_include_directories(CCCEntry PUBLIC
    ${PROJECT_SOURCE_DIR}/base_library/log
)

target_link_libraries(CCCEntry
    CCCLib
    pthread
)

message(STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})
