add_compile_options(-Wall -Wno-sign-compare -Wno-unused-function -Werror -O2 -g -std=c++17)

add_executable(LogCollectorService
    src/main.cpp
)

target_include_directories(LogCollectorService PUBLIC
    ${PROJECT_SOURCE_DIR}/service/log/log_collector_service/include
    ${PROJECT_SOURCE_DIR}/utils
)

target_link_libraries(LogCollectorService
    -pthread
    -ldl
)
