add_executable(netConfigService
    net_config.cpp
)

target_include_directories(netConfigService PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}
)

target_link_libraries(netConfigService 
    logLib
)

