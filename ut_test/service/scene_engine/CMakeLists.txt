add_compile_options(-Wall -std=c++17)

add_executable(SceneEngineTest
    gtest_entry.cpp
    scene_engine_client.cpp
)

target_include_directories(SceneEngineTest PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include
    ${PROJECT_SOURCE_DIR}/service/scene_engine
    ${PROJECT_SOURCE_DIR}/ut_test/service/scene_engine
    ${PROJECT_SOURCE_DIR}/service/scene_engine/scheduler
    ${PROJECT_SOURCE_DIR}/service/scene_engine/event_occur
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/
    ${PROJECT_SOURCE_DIR}/app
)


target_link_libraries(SceneEngineTest
    SceneEngineLib
    logLib
    ${PROJECT_SOURCE_DIR}/third_part/NanoLogLite/lib/libnanologlite.so
    ${PROJECT_SOURCE_DIR}/third_part/gtest/lib/libgtest.a
    pthread
    rt
)