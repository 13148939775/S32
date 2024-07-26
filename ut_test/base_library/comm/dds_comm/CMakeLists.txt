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

add_executable(test_dds_pubsub
    ${PROJECT_SOURCE_DIR}/ut_test/gtest_entry.cpp
    test_dds_pubsub.cpp
    ${PROJECT_SOURCES}
)

target_include_directories(test_dds_pubsub PRIVATE
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include
    ${PROJECT_SOURCE_DIR}/base_library/comm/hht_dds/include
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/include
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/include/ndds
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/include/ndds/hpp
)

target_link_libraries(test_dds_pubsub
    ${RTI_DDS_LIBRARIES}
    ${PROJECT_SOURCE_DIR}/third_part/gtest/${LIBRARY_DIR}/libgtest.a
    pthread
    rt
)

add_test(NAME dds_commUT COMMAND dds_commUT)



