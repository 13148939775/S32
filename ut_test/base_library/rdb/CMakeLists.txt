add_executable(rdbUT
    ${PROJECT_SOURCE_DIR}/ut_test/gtest_entry.cpp
    test_rdb.cpp
)

target_include_directories(rdbUT PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include
    ${PROJECT_SOURCE_DIR}/third_part/sqlite/include
    ${PROJECT_SOURCE_DIR}/base_library/rdb
)

target_link_libraries(rdbUT
    rdbLib
    #${PROJECT_SOURCE_DIR}/third_part/sqlite/${LIBRARY_DIR}/libsqlite3.so.0.8.6
    ${PROJECT_SOURCE_DIR}/third_part/gtest/${LIBRARY_DIR}/libgtest.a
    pthread
    rt
)