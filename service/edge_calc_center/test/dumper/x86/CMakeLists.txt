cmake_minimum_required(VERSION 3.16)

project(test_dumper)

add_executable(DumpFileChecker
DumpFileChecker.cpp
)

target_include_directories(DumpFileChecker PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../inc/dumper
)
