add_compile_options(-Wall -std=c++17)
add_library(appLib SHARED 
    app_manager.cpp
    app_manager_config.cpp
    linux/process.cpp 
)

target_include_directories(appLib PUBLIC
    ${PROJECT_SOURCE_DIR}/service/app_manager
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}
)

target_link_libraries(appLib
    logLib
)

add_executable(appManagerEntry 
    app_manager_entry.cpp 
)

target_include_directories(appManagerEntry PUBLIC
    ${PROJECT_SOURCE_DIR}/base_library/log
)

target_link_libraries(appManagerEntry
    appLib
    pthread
)
add_subdirectory(appmanager_signal)
