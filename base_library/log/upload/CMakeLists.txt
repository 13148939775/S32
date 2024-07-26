cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

# 添加编译选项
add_compile_options("-Wno-unused-variable -Wall -Wno-sign-compare -Wno-unused-function -Werror -O0 -g -lgcov ")

# 开启代码覆盖率测试
option(CODE_COVERAGE "Enable coverage reporting" ON)
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-fprofile-arcs -ftest-coverage)
  add_link_options(-fprofile-arcs -ftest-coverage)
endif()


# 编译logUpload共享库
add_library(logUpload SHARED
    src/upload.cpp
    src/base64.cpp
    src/LogHttpClient.cpp
    src/LogUploadFile.cpp
    src/ObsUploader.cpp
    src/TspDownloader.cpp
    src/TspProxy.cpp
    src/TspUploader.cpp
    src/UploadPretend.cpp
    src/Control.cpp
)

# 添加头文件搜索路径
target_include_directories(logUpload PUBLIC
    include
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/third_part/curl-8.1.2/include/
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include   #这个实现也在头文件里，所以不需要动态库
    ${PROJECT_SOURCE_DIR}/third_part/openssl1.1.1/include  
    ${PROJECT_SOURCE_DIR}/third_part/minizip-ng-1.2/include
    ${PROJECT_SOURCE_DIR}/third_part/zlib-1.2.13/include
)


# 添加可执行文件
add_executable(logupload
    src/main.cpp
)

# 链接共享库
target_link_libraries(logupload 
    logUpload
)

# 链接第三方库
target_link_libraries(logUpload 
    logLib
    ${PROJECT_SOURCE_DIR}/third_part/curl-8.1.2/${LIBRARY_DIR}/libcurl.so
    ${PROJECT_SOURCE_DIR}/third_part/openssl1.1.1/${LIBRARY_DIR}/libcrypto.so
    ${PROJECT_SOURCE_DIR}/third_part/openssl1.1.1/${LIBRARY_DIR}/libssl.so
    ${PROJECT_SOURCE_DIR}/third_part/minizip-ng-1.2/${LIBRARY_DIR}/libminizip.so
    ${PROJECT_SOURCE_DIR}/third_part/zlib-1.2.13/${LIBRARY_DIR}/zlib.so.1.2.13
    ${PROJECT_SOURCE_DIR}/third_part/ota_get_vin_sn/${LIBRARY_DIR}/libhidiff.so
    ${PROJECT_SOURCE_DIR}/third_part/ota_get_vin_sn/${LIBRARY_DIR}/libota_mgr.so
    pthread 
)


# 输出调试信息
message(STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})
