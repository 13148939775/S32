add_compile_options(-Wall -std=c++17)

# 设置代码覆盖率的相关参数
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -fprofile-arcs -ftest-coverage -O0 -lgcov ")

add_executable(uplogUT
  UploadTestEentry.cpp
  LogUploadFileTest.cpp
  # BaseEncodeTest.cpp
  UploaderTest.cpp
  UploadPretendTest.cpp
  ControlTest.cpp
  )

target_include_directories(uplogUT PUBLIC
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include
    # ${PROJECT_SOURCE_DIR}/third_part/gtest/googlemock/include
    ${PROJECT_SOURCE_DIR}/third_part/NanoLogLite
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/base_library/log/upload/include
)

target_link_libraries(uplogUT
    ${PROJECT_SOURCE_DIR}/third_part/gtest/${LIBRARY_DIR}/libgtest.a
    # ${PROJECT_SOURCE_DIR}/third_part/gtest/${LIBRARY_DIR}/libgmock.a
    logUpload
    pthread
    rt
)
