add_compile_options(-Wall -Wno-sign-compare -Wno-unused-function -Werror -O2 -g -std=c++17)

add_library(logLib SHARED
    node_log.cpp
    hht_log_impl.cpp    
)

target_include_directories(logLib PUBLIC
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/third_part/glog/gloginclude
)

target_link_libraries(logLib
    ${PROJECT_SOURCE_DIR}/third_part/glog/${LIBRARY_DIR}/libglog.so.0.7.0
)

add_executable(nodeLogTest
    ./examples/node_log_test.cpp
    node_log.cpp
    hht_log_impl.cpp    
)

target_include_directories(nodeLogTest PUBLIC
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/third_part/glog/gloginclude
)

target_link_libraries(nodeLogTest
      ${PROJECT_SOURCE_DIR}/third_part/glog/${LIBRARY_DIR}/libglog.so
    pthread
    rt
)

add_subdirectory(upload)
add_subdirectory(ntpdate)
