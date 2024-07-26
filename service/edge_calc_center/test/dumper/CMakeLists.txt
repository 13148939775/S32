cmake_minimum_required(VERSION 3.16)

project(test_dumper)

add_executable(RingBufferTest
RingBufferTest.cpp
)

target_include_directories(RingBufferTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/dumper
)

target_link_libraries(RingBufferTest PRIVATE
    glog
    hhtutils
    crypto
)

add_executable(DumperTest
DumperTest.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/DataDumper.cpp

)

target_include_directories(DumperTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/dumper
)

target_link_libraries(DumperTest PRIVATE
    glog
    hhtutils
    crypto
)
