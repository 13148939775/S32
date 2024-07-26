if [ -d "build_aarch64" ]; then
    rm -rf build_aarch64
fi
mkdir build_aarch64
(cd build_aarch64 && cmake -DCMAKE_INSTALL_PREFIX=/home/miaow/work/S32G-UP/s32-Apps/third_part/minizip-zlib/zlib-1.2.13/build_aarch64 -DUSE_CC_AARCH64=ON -DCMAKE_C_COMPILER=/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc -DCMAKE_CXX_COMPILER=/home/cuke/xjl_work/soft/arm_linux_compile_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++ .. && make -j8  && make install)
