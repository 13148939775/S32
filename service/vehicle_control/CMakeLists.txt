
add_compile_options(-Wall -std=c++17 -g)

add_definitions(-DRTI_UNIX -DRTI_LINUX -DRTI_64BIT)

FILE(GLOB DDS_SOURCE ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle/*.cxx)

link_directories(${PROJECT_SOURCE_DIR}/third_part/dds/lib/${LIBRARY_DIR})

link_directories(${PROJECT_SOURCE_DIR}/third_part/glog/${LIBRARY_DIR})

message(STATUS "add_excutable VehicelControlService")
add_executable(VehicleControlService
    VehicleControl_Client.cpp
)

target_include_directories(VehicleControlService PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds/hpp

    ${PROJECT_SOURCE_DIR}/service/vehicle_control/TopicManage
    ${PROJECT_SOURCE_DIR}/service/vehicle_control/FaultInject
    ${PROJECT_SOURCE_DIR}/service/vehicle_control/service_Comm

    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/dds_reply/include
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/module

    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/utils/tdbc
)

message(STATUS "add_library servicedealLib")
add_library(servicedealLib SHARED
    service_Comm/serviceComm.cpp
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/dds_reply/src/DDSReplierManage.cpp
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/dds_reply/src/DDSReplierListener.cpp
    ${DDS_SOURCE}
)

target_include_directories(servicedealLib PUBLIC
    ${PROJECT_SOURCE_DIR}/tools/socket
    ${PROJECT_SOURCE_DIR}/service/vehicle_control
    ${PROJECT_SOURCE_DIR}/service/vehicle_control/service_Comm

    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/dds_reply/include
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/module

    ${PROJECT_SOURCE_DIR}/base_library/log

    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    
    ${PROJECT_SOURCE_DIR}/third_part/dds/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds/hpp
)

    
message(STATUS "add_library vconflictManageLib")
add_library(vconflictManageLib SHARED
    TopicManage/TopicManage.cpp
    TopicManage/TopicService.cpp
)

target_include_directories(vconflictManageLib PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/include
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds
    ${PROJECT_SOURCE_DIR}/third_part/dds/include/ndds/hpp

    ${PROJECT_SOURCE_DIR}/service/vehicle_control/TopicManage
    ${PROJECT_SOURCE_DIR}/service/vehicle_control/service_Comm

    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/dds_reply/include
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/vehicle
    ${PROJECT_SOURCE_DIR}/base_library/ddsservice/module

    ${PROJECT_SOURCE_DIR}/base_library/log

    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include

    ${PROJECT_SOURCE_DIR}/utils/tdbc

    ${PROJECT_SOURCE_DIR}/tools/socket
)


message(STATUS "target_link_libraries VehicelControlService")
target_link_libraries(VehicleControlService
    vconflictManageLib
    servicedealLib
    logLib
    pthread
    rticonnextmsgcpp2d
    nddscpp2d
    nddscd
    nddscored
    libglog.so
    -ldl -lm  -lrt -no-pie -rdynamic
)