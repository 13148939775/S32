
add_library(OSPosix SHARED
    src/HhtAtomicFile.cpp
    src/HhtBufPool.cpp
    src/HhtLooperThread.cpp
    src/HhtMutex.cpp
    src/HhtTaskLooper.cpp
    src/HhtThread.cpp
    src/HhtTimeTick.cpp
    #src/HhtVariant.cpp
)

target_include_directories(OSPosix PUBLIC
    ${PROJECT_SOURCE_DIR}/utils/OSPosix/inc
)

target_link_libraries(OSPosix
    pthread
)

message(STATUS "utils PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})