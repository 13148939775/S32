cmake_minimum_required(VERSION 3.4)

project(
  hds-platform
  LANGUAGES CXX
  VERSION "1.08.00"
)

set (CMAKE_CXX_FLAGS " -g -Wall")

# 设置条件编译选项
#开关是USE_X86，可以填ON或OFF，
#默认是编译arm版本的，所以默认是OFF
#如果是想x86环境编译请用ON

option(USE_X86 "Build for x86 architecture" ON)
# option(USE_X86 "Build for arm architecture" OFF)
if (USE_X86)
	set(LIBRARY_DIR "lib_x86")
else()
	set(LIBRARY_DIR "lib_arm")
endif()

set(MASTER_ROOT ${PROJECT_SOURCE_DIR})
set(MASTER_3RDPARTY_LIBS_DIR ${MASTER_ROOT}/third_part)

include_directories(
    ${PROJECT_SOURCE_DIR}/base_library/comm/message
)
FILE (GLOB_RECURSE PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/base_library/comm/message/*.cxx
) 

# 开启代码覆盖率测试
option(CODE_COVERAGE "Enable coverage reporting" ON)
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang") 
  add_compile_options(-fprofile-arcs -ftest-coverage)
  add_link_options(-fprofile-arcs -ftest-coverage)
endif()

# add_subdirectory(app)
add_subdirectory(base_library)
add_subdirectory(service)
add_subdirectory(utils)
# add_subdirectory(ut_test)

message(STATUS "U PROJECT_SOURCE_DIR is " ${PROJECT_SOURCE_DIR})
