add_compile_options(-Wall -std=c++17)

add_executable(vehicleControlUT
  Gtest_Entry.cpp
  VehicleControl_Client.cpp
)

target_include_directories(vehicleControlUT PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include
    ${PROJECT_SOURCE_DIR}/service/vehicle_control
    ${PROJECT_SOURCE_DIR}/utils/tdbc
    ${PROJECT_SOURCE_DIR}/app
    ${PROJECT_SOURCE_DIR}/third_part/NanoLogLite
    ${PROJECT_SOURCE_DIR}/
)

target_link_libraries(vehicleControlUT
    vconflictManageLib
    logLib
    ${PROJECT_SOURCE_DIR}/third_part/NanoLogLite/lib/libnanologlite.so
    ${PROJECT_SOURCE_DIR}/third_part/gtest/lib/libgtest.a
    pthread
    rt
)