add_subdirectory(socket_comm)


#[[add_compile_options(-Wall -std=c++17 -g)

add_definitions(-DRTI_UNIX -DRTI_LINUX -DRTI_64BIT)

FILE(GLOB DDS_SOURCE ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle/*.cxx)

link_directories(${PROJECT_SOURCE_DIR}/third_part/dds/lib/${LIBRARY_DIR})



message(STATUS "add_excutable SceneEngine")
add_executable(SceneEngine
    scene_engine_entry.cpp
)

target_include_directories(SceneEngine PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/third_part/mqtt/include
    ${PROJECT_SOURCE_DIR}/third_part/glog/include
    ${PROJECT_SOURCE_DIR}/third_part/curl/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/x64/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/x64/include/ndds
    ${PROJECT_SOURCE_DIR}/third_part/dds/x64/include/ndds/hpp
    ${PROJECT_SOURCE_DIR}/third_part/glog/gloginclude

    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/service/scene_engine
    ${PROJECT_SOURCE_DIR}/service/scene_engine/scheduler
    ${PROJECT_SOURCE_DIR}/service/scene_engine/mqtt_comm
    ${PROJECT_SOURCE_DIR}/service/scene_engine/http_comm
    ${PROJECT_SOURCE_DIR}/service/scene_engine/socket_comm

    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/include
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice
    ${PROJECT_SOURCE_DIR}/tools/socket

    ${PROJECT_SOURCE_DIR}/app
    ${PROJECT_SOURCE_DIR}
)

message(STATUS "add_library sceneEngineLib")
add_library(sceneEngineLib SHARED
    custom_scene_manager.cpp
    custom_scene.cpp
    sceneCard.cpp
    meta_ability.cpp
    sceneCloud.cpp
)

message(STATUS "target_include_directories")
target_include_directories(sceneEngineLib PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/third_part/glog/gloginclude
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/service/scene_engine
    ${PROJECT_SOURCE_DIR}/service/scene_engine/scheduler

    ${PROJECT_SOURCE_DIR}/base_library/ddsservice
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/include
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle

    ${PROJECT_SOURCE_DIR}/third_part/dds/x64/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/x64/include/ndds
    ${PROJECT_SOURCE_DIR}/third_part/dds/x64/include/ndds/hpp
    ${PROJECT_SOURCE_DIR}/service/scene_engine/mqtt_comm
    ${PROJECT_SOURCE_DIR}/service/scene_engine/http_comm
    ${PROJECT_SOURCE_DIR}
)

message(STATUS "add_library CloudCommLib")
add_library(CloudCommLib SHARED
    http_comm/UploadExeResult.cpp
    http_comm/GetSceneDetail.cpp
    http_comm/LoginCloud.cpp
    mqtt_comm/mqtt.cpp
)


message(STATUS "target_include_directories")
target_include_directories(CloudCommLib PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/third_part/mqtt/include
    ${PROJECT_SOURCE_DIR}/third_part/curl/include
    ${PROJECT_SOURCE_DIR}/service/scene_engine
    ${PROJECT_SOURCE_DIR}/service/scene_engine/mqtt_comm
    ${PROJECT_SOURCE_DIR}/service/scene_engine/http_comm
    ${PROJECT_SOURCE_DIR}
)

message(STATUS "add_library ddsLib")
add_library(ddsLib SHARED
    ${DDS_SOURCE}
)

message(STATUS "target_include_directories")
target_include_directories(ddsLib PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/dds/x64/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/x64/include/ndds
    ${PROJECT_SOURCE_DIR}/third_part/dds/x64/include/ndds/hpp
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/include
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice
    ${PROJECT_SOURCE_DIR}
)


message(STATUS "target_link_libraries SceneEngine")
target_link_libraries(SceneEngine PUBLIC
    sceneEngineLib
    CloudCommLib
    ddsLib
    logLib

    ${PROJECT_SOURCE_DIR}/third_part/mqtt/lib_x86/libpaho-mqtt3a.so
    ${PROJECT_SOURCE_DIR}/third_part/mqtt/lib_x86/libpaho-mqtt3c.so  
    ${PROJECT_SOURCE_DIR}/third_part/mqtt/lib_x86/libpaho-mqttpp3.so
    ${PROJECT_SOURCE_DIR}/third_part/glog/lib_x86/libglog.so
    ${PROJECT_SOURCE_DIR}/third_part/curl/lib_x86/libcurl.so
    rticonnextmsgcpp2d
    nddscpp2d
    nddscd
    nddscored
    pthread
    libssl.so
    libcrypto.so
    librt.so
    libdl.so
    -ldl -lm  -lrt -no-pie -rdynamic
)]]