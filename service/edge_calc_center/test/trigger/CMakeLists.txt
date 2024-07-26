cmake_minimum_required(VERSION 3.16)

project(test_trigger)

add_executable(LoadTriggerTest
LoadTriggerTest.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/LogicNode.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/Trigger.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/TriggerManager.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/TriggerManagerGen.cpp

)

target_include_directories(LoadTriggerTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
)

target_link_libraries(LoadTriggerTest PRIVATE
    glog
    jsoncpp
    hhtutils
    yaml-cpp
    pps_com
)

add_executable(TriggerTest
TriggerTest.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/LogicNode.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/Trigger.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/TriggerManager.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/TriggerManagerGen.cpp

)

target_include_directories(TriggerTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
)

target_link_libraries(TriggerTest PRIVATE
    glog
    jsoncpp
    hhtutils
    yaml-cpp
    pps_com
)


add_executable(TriggerTimeTest
TriggerTimeTest.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/LogicNode.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/Trigger.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/TriggerManager.cpp
${CMAKE_CURRENT_SOURCE_DIR}/../../src/TriggerManagerGen.cpp

)

target_include_directories(TriggerTimeTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
)

target_link_libraries(TriggerTimeTest PRIVATE
    glog
    jsoncpp
    hhtutils
    yaml-cpp
    pps_com
)


add_executable(SendTriggerData
SendTriggerData.cpp
)

target_link_libraries(SendTriggerData PRIVATE
    pps_com
)

add_executable(EvaluatorTest
EvaluatorTest.cpp
)

target_include_directories(EvaluatorTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
)


add_executable(LogicVariantTest
LogicVariantTest.cpp
)

target_include_directories(LogicVariantTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
)

add_executable(StructChecker
StructChecker.cpp
)