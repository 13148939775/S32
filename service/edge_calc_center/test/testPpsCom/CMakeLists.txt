cmake_minimum_required(VERSION 3.16)

project(AMPObstacle_Site_Array)

add_executable(testAMPObstacle_Site_Array  main.cpp)

target_link_libraries(testAMPObstacle_Site_Array PRIVATE
    pps_com
)
