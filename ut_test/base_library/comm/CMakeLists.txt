
add_executable(commUT
    ${PROJECT_SOURCE_DIR}/ut_test/gtest_entry.cpp
    test_pub_wait.cpp
)

target_include_directories(commUT PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include
    ${PROJECT_SOURCE_DIR}/base_library/comm/hht_iox
    ${PROJECT_SOURCE_DIR}/base_library/comm/hht_iox/cpp
    ${MASTER_3RDPARTY_LIBS_DIR}/iceoryx-v2.0.3/include
    ${PROJECT_SOURCE_DIR}/base_library/log
)

target_link_libraries(commUT
    cppIOXPub
    cppIOXWait
    ${PROJECT_SOURCE_DIR}/third_part/iceoryx-v2.0.3/lib/${LIBRARY_DIR}/libattr.so
    ${PROJECT_SOURCE_DIR}/third_part/iceoryx-v2.0.3/lib/${LIBRARY_DIR}/libacl.so
    ${PROJECT_SOURCE_DIR}/third_part/iceoryx-v2.0.3/lib/${LIBRARY_DIR}/libiceoryx_hoofs.so
    ${PROJECT_SOURCE_DIR}/third_part/iceoryx-v2.0.3/lib/${LIBRARY_DIR}/libiceoryx_posh.so
    ${PROJECT_SOURCE_DIR}/third_part/iceoryx-v2.0.3/lib/${LIBRARY_DIR}/libiceoryx_platform.so
    ${PROJECT_SOURCE_DIR}/third_part/gtest/${LIBRARY_DIR}/libgtest.a
    pthread
    rt
)

add_test(NAME commUT COMMAND commUT)

add_subdirectory(dds_comm)