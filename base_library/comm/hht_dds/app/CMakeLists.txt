# message(STATUS "PROJECT: ${PROJECT_NAME}")

link_directories(
    ${MASTER_3RDPARTY_LIBS_DIR}/dds/lib/${LIBRARY_DIR}
)

set(RTI_DDS_LIBRARIES
    rticonnextmsgcpp2d
    nddscpp2d
    nddscd
    nddscored
)

function(add_app_executable target source)
    add_executable(${target} ${source} ${PROJECT_SOURCES} )
    target_include_directories(${target} PRIVATE
        ${MASTER_3RDPARTY_LIBS_DIR}/dds/include
        ${MASTER_3RDPARTY_LIBS_DIR}/dds/include/ndds
        ${MASTER_3RDPARTY_LIBS_DIR}/dds/include/ndds/hpp)
    target_link_libraries(${target} ${RTI_DDS_LIBRARIES} -ldl -lm -lpthread -lrt -no-pie -rdynamic)
endfunction()
add_app_executable(app_request app_request.cpp)
add_app_executable(app_reply app_reply.cpp)
add_app_executable(app_pub app_pub.cpp)
add_app_executable(app_sub app_sub.cpp)