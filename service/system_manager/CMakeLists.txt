add_compile_options(-Wall -std=c++17)
add_definitions(-DRTI_UNIX -DRTI_LINUX -DRTI_64BIT)

link_directories(
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/lib/${LIBRARY_DIR}
)

set(RTI_DDS_LIBRARIES
    rticonnextmsgcpp2d
    nddscpp2d
    nddscd
    nddscored
)

add_executable(SystemManager
    system_manager.cpp
    ${MASTER_ROOT}/ut_test/base_library/comm/test_pub_wait.cpp
    ${MASTER_ROOT}/ut_test/base_library/comm/dds_comm/test_dds_pubsub.cpp
    ${MASTER_ROOT}/ut_test/base_library/log/log_client.cpp
    ${MASTER_ROOT}/ut_test/base_library/rdb/test_rdb.cpp
    ${PROJECT_SOURCES}
)

target_include_directories(SystemManager PUBLIC
    ${MASTER_ROOT}/third_part/gtest/googletest/include
    ##iceory
    ${MASTER_ROOT}/base_library/comm/hht_iox/cpp
    ${MASTER_3RDPARTY_LIBS_DIR}/iceoryx-v2.0.3/include
    ##dds
    ${MASTER_ROOT}/base_library/comm/hht_dds/include
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/include
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/include/ndds
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/include/ndds/hpp
    ${MASTER_ROOT}/base_library/comm/hht_dds/include
    ##sqlite
    ${PROJECT_SOURCE_DIR}/third_part/sqlite/include
    ${PROJECT_SOURCE_DIR}/base_library/rdb
    #app
    ${MASTER_ROOT}/app
    ${MASTER_ROOT}/base_library/log

)


target_link_libraries(SystemManager
    cppIOXPub
    cppIOXWait
    ${PROJECT_SOURCE_DIR}/third_part/iceoryx-v2.0.3/lib/${LIBRARY_DIR}/libattr.so
    ${PROJECT_SOURCE_DIR}/third_part/iceoryx-v2.0.3/lib/${LIBRARY_DIR}/libacl.so
    ${PROJECT_SOURCE_DIR}/third_part/iceoryx-v2.0.3/lib/${LIBRARY_DIR}/libiceoryx_hoofs.so
    ${PROJECT_SOURCE_DIR}/third_part/iceoryx-v2.0.3/lib/${LIBRARY_DIR}/libiceoryx_posh.so
    ${PROJECT_SOURCE_DIR}/third_part/iceoryx-v2.0.3/lib/${LIBRARY_DIR}/libiceoryx_platform.so
    ${PROJECT_SOURCE_DIR}/third_part/gtest/${LIBRARY_DIR}/libgtest.a

    ${RTI_DDS_LIBRARIES}
    logLib
    logUpload
    rdbLib
    pthread
    rt
)