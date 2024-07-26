
add_compile_options(-Wall -std=c++17 -g)
message(STATUS "add_excutable")
add_executable(VConflictManage
    VehicelControl_Client.cpp
)

message(STATUS "target_include_directories VConflictManage")

target_include_directories(VConflictManage PUBLIC
    ${PROJECT_SOURCE_DIR}/service/vehicle_control/TopicManage
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/utils/tdbc
    ${PROJECT_SOURCE_DIR}/app
)
    
message(STATUS "target_link_libraries VConflictManage")
target_link_libraries(VConflictManage
    vconflictManageLib
)
message(STATUS "add_library vconflictManageLib")
add_library(vconflictManageLib 
    TopicManage.cpp
    Topic.cpp
)

message(STATUS "target_include_directories")
target_include_directories(vconflictManageLib PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/service/vehicle_control/TopicManage
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/utils/tdbc
    ${PROJECT_SOURCE_DIR}/app
    ${PROJECT_SOURCE_DIR}
)
message(STATUS "target_link_libraries")
target_link_libraries(
    vconflictManageLib
    logLib
    pthread
)