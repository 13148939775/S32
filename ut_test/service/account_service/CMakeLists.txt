add_compile_options(-Wall -Wno-sign-compare -Wno-unused-function -Werror -O2 -g -std=c++17)
add_definitions(-DRTI_UNIX -DRTI_LINUX -DRTI_64BIT)

link_directories(
    ${PROJECT_SOURCE_DIR}/third_part/dds/lib/${LIBRARY_DIR}
    ${PROJECT_SOURCE_DIR}/third_part/mqtt/lib/${LIBRARY_DIR}
)

set(RTI_DDS_LIBRARIES
    rticonnextmsgcpp2d
    nddscpp2d
    nddscd
    nddscored
)

set(MQTT_LIBRARIES
    paho-mqtt3a
    paho-mqtt3as
    paho-mqtt3c
    paho-mqtt3cs
    paho-mqttpp3
)

add_executable(accountServiceUT
    ${PROJECT_SOURCE_DIR}/ut_test/gtest_entry.cpp
    test_account_service.cpp
    ${PROJECT_SOURCE_DIR}/service/account_service/utils.cpp
    ${PROJECT_SOURCE_DIR}/base_library/message/DDSServiceInterfaceIV3.cxx
    ${PROJECT_SOURCE_DIR}/base_library/message/DDSServiceInterfaceIV3Plugin.cxx
)

target_include_directories(accountServiceUT PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/base_library/rdb
    ${PROJECT_SOURCE_DIR}/third_part/openssl1.1.1/include
    ${PROJECT_SOURCE_DIR}/third_part/curl-8.1.2/include
    ${PROJECT_SOURCE_DIR}/third_part/mqtt/include
    ${PROJECT_SOURCE_DIR}/service/account_service
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds/hpp
    ${PROJECT_SOURCE_DIR}/base_library/message
    ${PROJECT_SOURCE_DIR}/base_library/comm/hht_dds/include
)


target_link_libraries(accountServiceUT
    ${PROJECT_SOURCE_DIR}/third_part/sqlite/${LIBRARY_DIR}/libsqlite3.so.0.8.6
    ${PROJECT_SOURCE_DIR}/third_part/curl-8.1.2/${LIBRARY_DIR}/libcurl.so.4
    ${PROJECT_SOURCE_DIR}/third_part/openssl1.1.1/${LIBRARY_DIR}/libcrypto.so
    ${PROJECT_SOURCE_DIR}/third_part/openssl1.1.1/${LIBRARY_DIR}/libssl.so
    ${PROJECT_SOURCE_DIR}/third_part/gtest/${LIBRARY_DIR}/libgtest.a
    ${RTI_DDS_LIBRARIES}
    ${MQTT_LIBRARIES}
    -pthread
    -ldl
    logLib
    rdbLib
)