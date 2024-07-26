cmake_minimum_required(VERSION 3.4)


set (CMAKE_CXX_FLAGS " -g -Wall -fprofile-arcs -ftest-coverage")

add_subdirectory(curl)
#add_subdirectory(libzip-1.9.2)
#add_subdirectory(zlib-1.2.13)


message(STATUS "U PROJECT_SOURCE_DIR is " ${PROJECT_SOURCE_DIR})
