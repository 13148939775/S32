cmake_minimum_required(VERSION 3.15)
#project(custom_topic_name_test)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
message(STATUS "Build type:${CMAKE_BUILD_TYPE}")

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(OS "LINUX")
    set(OS_CXX_FLAGS "-D__LINUX__ -DNDEBUG -pthread")
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
add_definitions(-DRTI_UNIX -DRTI_LINUX -DRTI_64BIT -DRTI_STATIC)
set(TARGET_ARCH "armv8Linux4gcc7.3.0")
#设置交叉编译环境路径
set (CMAKE_C_COMPILER "/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++")
set (CMAKE_CXX_COMPILER "/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++")


#add_definitions(-DRTI_UNIX -DRTI_LINUX -DRTI_64BIT)
#set(TARGET_ARCH x64Linux4gcc7.3.0)

set(NDDSHOME /home/cuke/software/rti_connext_dds-6.1.1)

include_directories(
    ${PROJECT_SOURCE_DIR}/include/
    ${PROJECT_SOURCE_DIR}/message/
    ${NDDSHOME}/include/
    ${NDDSHOME}/include/ndds/
    ${NDDSHOME}/include/ndds/hpp/
    )
FILE(GLOB_RECURSE PROJECT_HEADERS
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/message/*.hpp
    ${NDDSHOME}/include/*.h
    ${NDDSHOME}/include/*.hpp
)
FILE (GLOB PROJECT_SOURCES_REQUEESTER 
    "src/requester/*.cpp"
    "message/*.cxx"
    )
FILE (GLOB PROJECT_SOURCES_REPLIER 
    "src/replier/*.cpp"
    "message/*.cxx"
    )

set(PROJECT_LIBRARIES
    ${NDDSHOME}/lib/${TARGET_ARCH}/librticonnextmsgcpp2d.so
    ${NDDSHOME}/lib/${TARGET_ARCH}/libnddscpp2d.so
    ${NDDSHOME}/lib/${TARGET_ARCH}/libnddscd.so
    ${NDDSHOME}/lib/${TARGET_ARCH}/libnddscored.so
)

link_directories(${NDDSHOME}/lib/${TARGET_ARCH}/)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_executable(requester ${PROJECT_SOURCES_REQUEESTER})
add_executable(replier ${PROJECT_SOURCES_REPLIER})
target_link_libraries(requester ${PROJECT_LIBRARIES} -ldl -lm -lpthread -lrt -no-pie -rdynamic)
target_link_libraries(replier ${PROJECT_LIBRARIES} -ldl -lm -lpthread -lrt -no-pie -rdynamic)