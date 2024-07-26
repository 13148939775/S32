# 设置 C++ 编译标准（可选）
set(CMAKE_CXX_STANDARD 14)




add_compile_options(-Wall -std=c++17)

add_executable(tomcu_logUT
  gtest_entry.cpp
  VControl_client.cpp
  )

target_include_directories(tomcu_logUT PUBLIC
    ${PROJECT_SOURCE_DIR}/service/vehicle_control/DataDistribution
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include
    ${PROJECT_SOURCE_DIR}/app
    ${PROJECT_SOURCE_DIR}/third_part/NanoLogLite
    ${PROJECT_SOURCE_DIR}/base_library/log
)

target_link_libraries(tomcu_logUT
    toMcuLib
)

add_library(toMcuLib 
    ${PROJECT_SOURCE_DIR}/service/vehicle_control/DataDistribution/McuControl.hpp
    # /home/fanbh/fbh/s32g-upload/s32-Apps/service/vehicle_control/.cpp
)

# 指定目标的链接语言为 C++
set_target_properties(toMcuLib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(toMcuLib PUBLIC
    ${PROJECT_SOURCE_DIR}/service/vehicle_control/data_distribution/
   # /home/fanbh/fbh/s32g-upload/s32-Apps/service/vehicle_control3/MCUManager/src
    ${PROJECT_SOURCE_DIR}/service/vehicle_control3/MCUManager/inc/
    ${PROJECT_SOURCE_DIR}/service/vehicle_control3/SignalManager/inc/
    ${PROJECT_SOURCE_DIR}/utils/tdbc
    ${PROJECT_SOURCE_DIR}/app
    ${PROJECT_SOURCE_DIR}/
)

target_link_libraries(tomcu_logUT
    #logLib
    # ${PROJECT_SOURCE_DIR}/third_part/NanoLogLite/lib/libnanologlite.so
    ${PROJECT_SOURCE_DIR}/third_part/gtest/lib/libgtest.a
    pthread
    rt
)