add_compile_options(-Wall -Wno-sign-compare -Wno-unused-function -Werror -O2 -g -std=c++17)

add_library(rdbLib SHARED
    sqlite_operator.cpp
)

target_include_directories(rdbLib PUBLIC
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/third_part/sqlite/include
    ${PROJECT_SOURCE_DIR}/base_library/rdb
)

target_link_libraries(rdbLib
    ${PROJECT_SOURCE_DIR}/third_part/sqlite/${LIBRARY_DIR}/libsqlite3.so.0.8.6
    -pthread
    -ldl
    logLib
)