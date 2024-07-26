set(SOURCES
    ${PROJECT_SOURCE_DIR}/ut_test/gtest_entry.cpp
    Norequest_Client.cpp
    
)

add_executable(norequest_client 
    ${SOURCES}
)

include_directories(norequest_client PUBLIC
    ${PROJECT_SOURCE_DIR}/tools/socket
    ${PROJECT_SOURCE_DIR}/service/norequest_manager/include
)

target_include_directories(norequest_client PUBLIC
    ${PROJECT_SOURCE_DIR}/tools/socket
    #${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/third_part/nlohmann/include
    ${PROJECT_SOURCE_DIR}/third_part/gtest/googletest/include

)

target_link_libraries(norequest_client PUBLIC 
    noReqLib
    ${PROJECT_SOURCE_DIR}/third_part/gtest/${LIBRARY_DIR}/libgtest.a
    pthread
)




