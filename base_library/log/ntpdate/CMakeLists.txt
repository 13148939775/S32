cmake_minimum_required(VERSION 3.10)
project(ntpdate)
# set(LIBNTPDATE_PATH "${MASTER_3RDPARTY_LIBS_DIR}/ntp-4.2.8p17/${LIBRARY_DIR}/libntpdate.so")
# add_definitions(-DLIBNTPDATE_PATH="${LIBNTPDATE_PATH}")

# 添加可执行文件
add_executable(${PROJECT_NAME}
    ntp_main.cpp
)

# 链接第三方库
target_link_libraries(${PROJECT_NAME}
    -pthread 
    -ldl
)
