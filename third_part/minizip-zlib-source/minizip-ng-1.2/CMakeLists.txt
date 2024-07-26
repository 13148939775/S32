#***************************************************************************
# Copyright:  Matthias Schmieder,
# E-Mail:     schmieder.matthias@gmail.com
# Year:       2016
#***************************************************************************
cmake_minimum_required(VERSION 2.8)


# Set a consistent MACOSX_RPATH default across all CMake versions. 
# When CMake 2.8.12 is required, change this default to 1.
# When CMake 3.0.0 is required, remove this block (see CMP0042).
if(NOT DEFINED CMAKE_MACOSX_RPATH)
  set(CMAKE_MACOSX_RPATH 0)
endif()

project("minizip")

# set cmake debug postfix to d
set(CMAKE_DEBUG_POSTFIX "d")

# Ensure correct version of zlib is referenced
#set(ZLIB_ROOT ${DEF_ZLIB_ROOT} CACHE PATH "Parent directory of zlib installation")
#find_package(ZLIB REQUIRED)
#if(ZLIB_FOUND)
#    include_directories(${ZLIB_INCLUDE_DIRS})
#endif()

# 设置 zlib 库的路径（根据实际安装路径进行替换）
set(ZLIB_ROOT /home/miaow/work/S32G-UP/s32-Apps/third_part/zlib-1.2.13/include)
FILE(GLOB_RECURSE
${ZLIB_ROOT}/*.h)

# 添加 zlib 的头文件搜索路径
include_directories(${ZLIB_ROOT})

# 添加 zlib 库文件的搜索路径
link_directories(${ZLIB_ROOT}/build_aarch64/lib)


set(MINIZIP_SRC "crypt.c"
  "ioapi.c"
  "ioapi_buf.c"
  "ioapi_mem.c"
  "unzip.c"
  "zip.c")

set(MINIZIP_PUBLIC_HEADERS "crypt.h"
  "ioapi.h"
  "ioapi_buf.h"
  "ioapi_mem.h"
  "unzip.h"
  "zip.h")

  option(USE_CRYPT "To disable the encryption password feature" OFF)
  if (USE_CRYPT)
    add_definitions(-DNOCRYPT)
  endif()

if(UNIX)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -O3")
  add_definitions(-D__USE_FILE_OFFSET64)
  add_definitions(-D__USE_LARGEFILE64)
  add_definitions(-D_LARGEFILE64_SOURCE)
  add_definitions(-D_FILE_OFFSET_BIT=64)
endif()

if(CMAKE_C_COMPILER MATCHES ".*clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -msse3 -msse4.1 -maes")
endif()
set(ZLIB
/home/miaow/work/S32G-UP/s32-Apps/third_part/zlib-1.2.13/lib_arm/libz.so.1.2.13
)

# create minizip library
add_library(minizip  SHARED  ${MINIZIP_SRC} ${MINIZIP_PUBLIC_HEADERS})
target_link_libraries(minizip ${ZLIB})


