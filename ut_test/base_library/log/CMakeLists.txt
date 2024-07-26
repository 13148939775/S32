add_compile_options(-Wall -std=c++17)


# 设置 glog 动态库路径


add_executable(logUT
  gtest_entry.cpp
  log_client.cpp
  )

target_include_directories(logUT PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include
    ${PROJECT_SOURCE_DIR}/app
    #${PROJECT_SOURCE_DIR}/third_part/NanoLogLite
    ${PROJECT_SOURCE_DIR}/base_library/log
)

target_link_libraries(logUT
    logLib
    #${PROJECT_SOURCE_DIR}/third_part/NanoLogLite/lib/libnanologlite.so
    ${PROJECT_SOURCE_DIR}/third_part/gtest/${LIBRARY_DIR}/libgtest.a
    pthread
    rt
)

add_subdirectory(upload)
