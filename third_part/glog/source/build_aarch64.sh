if [ -d "build_aarch64" ]; then
    rm -rf build_aarch64
fi
mkdir build_aarch64

CURRENT_PATH=$(pwd | sed 's/\n//')

COMLIER_TOOL_PATH=/work/xjl_work/gcc-arm-11.2-2022.02-x86_64-aarch64-none-linux-gnu/bin
echo "${COMLIER_TOOL_PATH}"
(cd build_aarch64 && cmake -DUSE_CC_AARCH64=ON -DCMAKE_C_COMPILER=${COMLIER_TOOL_PATH}/aarch64-none-linux-gnu-gcc \
-DCMAKE_CXX_COMPILER=${COMLIER_TOOL_PATH}/aarch64-none-linux-gnu-g++ -DCMAKE_CXX_FLAGS="-std=c++17 " .. && make -j8)