
add_executable(KMeans
    algorithm/KMeans-GMM-HMM/KMeans.cpp
    algorithm/KMeans-GMM-HMM/KMeans-test.cpp
    #algorithm/KMeans-GMM-HMM/opencv-kmeans-test.cpp
    algorithm/KMeans-GMM-HMM/opencv-gmm.cpp
)

target_include_directories(KMeans PRIVATE
    algorithm/KMeans-GMM-HMM
    ${PROJECT_SOURCE_DIR}/base_library/log
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/core/include/
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/calib3d/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/features2d/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/flann/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/dnn/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/highgui/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/imgproc/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/imgcodecs/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/videoio/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/ml/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/objdetect/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/gapi/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/highgui/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/imgproc/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/ml/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/photo/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/video/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/obj/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/stitching/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/videoio/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/ts/include
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/modules/world/include
)

option(USE_X86 "Build for x86 architecture" ON)
# 设置 glog 动态库路径
if (USE_X86)
	set(LIBRARY_DIR "lib_x86")
else()
	set(LIBRARY_DIR "lib_arm")
endif()

message("check env platform is :" ${LIBRARY_DIR})

target_link_libraries(KMeans PRIVATE
    logLib
    #${PROJECT_SOURCE_DIR}/third_part/glog/${LIBRARY_DIR}/libglog.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_core.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_imgcodecs.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_imgproc.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_calib3d.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_dnn.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_features2d.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_gapi.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_highgui.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_ml.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_objdetect.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_stitching.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_photo.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_video.so
    ${PROJECT_SOURCE_DIR}/third_part/opencv-4.7.0/${LIBRARY_DIR}/libopencv_videoio.so
)
