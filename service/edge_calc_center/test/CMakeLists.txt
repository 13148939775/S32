cmake_minimum_required(VERSION 3.16)

project(test_demo)

add_subdirectory(trigger)
add_subdirectory(dumper)
add_subdirectory(powerofftrigger)

if (${CMAKE_CROSSCOMPILING} STREQUAL "FALSE")

add_subdirectory(receive_demo)

endif()