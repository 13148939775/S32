此curl库依赖的是openssl3.1.1和zlib-1.2.13

curl-8.1.2
mkdir lib_x86
./configure --prefix=/work/miaow/curl_compile/curl-8.1.2-source/lib_x86
CPPFLAGS="-I/work/miaow/curl_compile/openssl3/include -I/work/miaow/curl_compile/zlib-1.2.13/include"
LDFLAGS="-L/work/miaow/curl_compile/openssl3/lib_x86 -L/work/miaow/curl_compile/zlib-1.2.13/lib_x86"
--with-ssl --with-zlib
make -j16 && make install


mkdir lib_arm
./configure --prefix=/work/miaow/curl_compile/curl-8.1.2-source/lib_arm \
CPPFLAGS="-I/work/miaow/curl_compile/openssl3/include -I/work/miaow/curl_compile/zlib-1.2.13/include" \
LDFLAGS="-L/work/miaow/curl_compile/openssl3/lib_arm -L/work/miaow/curl_compile/zlib-1.2.13/lib_arm" \
CC=/work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc \
CXX=/work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ \
AR=/work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-ar \
LIBS="/work/miaow/curl_compile/openssl3/lib_arm/libssl.so.3 /work/miaow/curl_compile/openssl3/lib_arm/libcrypto.so.3 /work/miaow/curl_compile/zlib-1.2.13/lib_arm/zlib.so.1.2.13" \
--with-ssl=/work/miaow/curl_compile/openssl3 --with-zlib=/work/miaow/curl_compile/zlib-1.2.13 \
--target=arm-linux --host=aarch64-linux-gnu
make -j16 && make install

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
openssl3.1.1
x86 
./Configure
make
make test	

arm
prefix:openssl安装目录
–cross-compile-prefix:交叉编译器前缀
no-asm:不使用汇编代码。由于是交叉编译，如不使用该选项，会出现汇编指令不识别的问题，因为openssl默认使用的汇编指令为X86平台下的指令，而一般的交叉编译器使用时ARM平台下的交叉编译器。
shared:生成动态库

./Configure \
--prefix=/work/miaow/curl_compile/openssl-3.1.1/output \
--cross-compile-prefix=/work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-  \
CC=gcc \
CXX=g++ \
-no-asm shared
注意：编译之前，需要Makefile中将-m64选项全部删除掉，因为aarch64-linux-gnu-gcc编译器不识别该选项。
make


curl_version_info_data* vinfo = curl_version_info(CURLVERSION_NOW);
HHT_LOG(INFO) << "CURL version: " << vinfo->version;
HHT_LOG(INFO) << "TLS version: " << vinfo->ssl_version;
在x86输出：
            CURL version: 8.1.2
            TLS version: OpenSSL/3.1.1
在arm输出：
            CURL version: 7.72.0
            TLS version: GnuTLS/3.6.14