为了使压缩裤支持加密，需要对源代码进行如下修改：

NOUNCRYPT和NOCRYPT代表不加密

s32-Apps/third_part/minizip-zlib-source/zlib-1.2.13/contrib/minizip/unzip.c
    注释掉71、72、73行的：
        // #ifndef NOUNCRYPT
        //      #define NOUNCRYPT
        // #endif

s32-Apps/third_part/minizip-zlib-source/minizip-ng-1.2/crypt.h
    注释掉22行的：
        // #define NOCRYPT

s32-Apps/third_part/minizip-ng-1.2/include/crypt.h
    注释掉22行的：
        // #define NOCRYPT

s32-Apps/third_part/minizip-zlib-source/minizip-ng-1.2/crypt.c
    注释掉115、116行的：
        // arc4random_buf(buf, len);
        // return len;

为了动态地配置加密/不加密功能，分别在minizip和zlib的CMakeLists.txt添加了如下代码：
其中，ON表示不加密，OFF表示加密
minizip:
  option(USE_CRYPT "To disable the encryption password feature" OFF)
  if (USE_CRYPT)
    add_definitions(-DNOCRYPT)
  endif()

zlib:
    option(USE_CRYPT "To disable the encryption password feature" OFF)
    if (USE_CRYPT)
        add_definitions(-DNOUNCRYPT)
    endif()

编译库： 
x86
    最终目的是使用minizip库，但是minizip库依赖zlib库，所以需要先编译zlib库：
    zlib:
        在CMakeLists.txt同级目录下，
                        mkdir build  --> 如果build文件夹已存在，则进入build文件夹执行  rm -rf *
                        在build目录下执行：cmake .. && make
    minizip：
        修改CMakeLists.txt文件中zlib的x86库路径
        与zlib类似，进入build目录执行：cmake .. && make

arm:
    先编译zlib库：
        直接执行minizip-zlib-source/zlib-1.2.13/build_aarch64.sh
    
    minizip:
        先配置CMakeLists.txt中zlib的arm库路径，直接执行minizip-zlib-source/minizip-ng-1.2/build_aarch64.sh
        

                        