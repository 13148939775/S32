add_compile_options(-Wall -std=c++17 -g)

add_executable(mqtt_test2
  mqtt_test.cpp
)

target_include_directories(mqtt_test2 PUBLIC
    ${PROJECT_SOURCE_DIR}/base_library/mqtt
)

target_link_libraries(mqtt_test2 PUBLIC
    mqttLib
)