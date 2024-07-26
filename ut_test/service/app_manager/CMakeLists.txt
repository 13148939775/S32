


add_executable(appManageUT
    ${PROJECT_SOURCE_DIR}/ut_test/gtest_entry.cpp
    test_hdbm_app.cpp
    test_app_manager.cpp
)

target_include_directories(appManageUT PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include
    ${PROJECT_SOURCE_DIR}
)

target_link_libraries(appManageUT
    appLib
    ${PROJECT_SOURCE_DIR}/third_part/gtest/${LIBRARY_DIR}/libgtest.a
    pthread
    rt
)