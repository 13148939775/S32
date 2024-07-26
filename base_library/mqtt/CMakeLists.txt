add_library(mqttLib SHARED
    mqtt_client.cpp
)

target_include_directories(mqttLib PUBLIC
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/third_part/sqlite/include
    ${PROJECT_SOURCE_DIR}/base_library/mqtt
)

target_link_libraries(mqttLib
    ${PROJECT_SOURCE_DIR}/third_part/mqtt/${LIBRARY_DIR}/libpaho-mqtt3a.so
    ${PROJECT_SOURCE_DIR}/third_part/mqtt/${LIBRARY_DIR}/libpaho-mqtt3c.so  
    ${PROJECT_SOURCE_DIR}/third_part/mqtt/${LIBRARY_DIR}/libpaho-mqttpp3.so
    logLib
)