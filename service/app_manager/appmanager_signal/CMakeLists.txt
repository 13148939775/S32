# 设置项目名称
project(MyApp)

# 指定最低的 CMake 版本
cmake_minimum_required(VERSION 3.0)

# 添加可执行文件并指定源文件
add_executable(AppExample 
    app_example.cpp
    main.cpp
)

# 添加头文件搜索路径
target_include_directories(AppExample PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/base_library/log
)
target_link_libraries(AppExample
    appLib
    pthread
)


