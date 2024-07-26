if [ -d "build_aarch64" ]; then
    rm -rf build_aarch64
fi
mkdir build_aarch64


DUMP_PATH=`pwd`/crashdump

# 检查当前用户是否具有sudo权限
if [ "$(id -u)" != "0" ]; then
  echo "请使用sudo运行此脚本"
  exit 1
fi

# 配置Coredump
echo 2 > /proc/sys/fs/suid_dumpable
echo "$DUMP_PATH/%e.%p.%t.coredump" > /proc/sys/kernel/core_pattern

# 创建Coredump保存目录
mkdir -p $DUMP_PATH
chmod 777 $DUMP_PATH

# Coredump功能已开启 配置信息
cat /proc/sys/fs/suid_dumpable
cat /proc/sys/kernel/core_pattern

CURRENT_PATH=$(pwd | sed 's/\n//')

COMLIER_TOOL_PATH=`pwd`/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin
echo "${COMLIER_TOOL_PATH}"
(cd build_aarch64 && cmake -DUSE_CC_AARCH64=ON -DCMAKE_C_COMPILER=${COMLIER_TOOL_PATH}/aarch64-none-linux-gnu-gcc \
-DCMAKE_CXX_COMPILER=${COMLIER_TOOL_PATH}/aarch64-none-linux-gnu-g++ -DCMAKE_CXX_FLAGS="-std=c++17 " .. && make -j8)