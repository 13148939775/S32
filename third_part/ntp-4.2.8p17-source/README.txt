文件说明：
    ntp-4.2.8p17.tar.gz --> ntp源码，编译方式见：x86版本编译、arm版本编译 部分
                            x86: ntp-4.2.8p17/ntpdate 下生成的可执行文件ntpdate即为所需
                            arm: ntp-4.2.8p17/output/bin 下生成的可执行文件ntpdate即为所需
                            执行方式：sudo ./ntpdate 域名 或 ip
    ntp_start.cpp  -->  cpp程序定时执行ntpdate(这里执行的是同级目录下的名为 ntpdate 的可执行文件，根据x86/arm选择拷贝对应的文件到同级目录下)
                        x86和arm版本已编译好，分别名为ntp_start_x86、ntp_start_arm,
                        可直接执行ntp_start_x86、ntp_start_arm，不需要带参数，前提是同级目录下已有对应版本的ntpdate可执行文件(名字不能修改，必须为ntpdate,可以直接重命名)
    

改时区
    sudo timedatectl set-timezone Asia/Shanghai
    sudo timedatectl set-timezone Asia/Seoul
    注意：修改时区后，通过ntp得到的时间会根据系统时区做出修改
改时间(相对时间,用于验证ntp) (启动ntpdate后，ntpdate会自动修改系统时间)
    sudo date -s "now + 10 minutes"
    sudo date -s "now"
    sudo date -s "now - 10 minutes"

查看端口123是否正在监听：  netstat -ln | grep 123
查看有哪些进程在用端口123 :    sudo lsof -i :123
kill -9 pid杀死进程

执行：
    sudo ./ntpdate 119.28.183.184
    sudo ./ntpdate pool.ntp.org
    或者  sudo ./ntpdate -u pool.ntp.org 加-u替换端口
    pool.ntp.org是一个使用NTP协议提供时间同步服务的服务器池。
    通过指定pool.ntp.org作为时间服务器，计算机将尝试从服务器池中的某个时间服务器获取准确的时间信息并进行同步

其他ntp服务器(备用)：
    /*
    *   pool.ntp.org
    *   ntp.tencent.com
    *   ntp1.tencent.com
    *   ntp2.tencent.com
    *   ntp3.tencent.com
    *   ntp4.tencent.com
    *   ntp5.tencent.com
    *   ntp.aliyun.com
    *   ntp1.aliyun.com
    *   ntp2.aliyun.com
    *   ntp3.aliyun.com
    *   ntp4.aliyun.com
    *   ntp5.aliyun.com
    *   ntp6.aliyun.com
    *   ntp7.aliyun.com
    *   time.edu.cn
    *   s2c.time.edu.cn
    *   s2f.time.edu.cn
    */

执行演示：
    命令执行：
        root@ubt:/s32-Apps$ sudo ./ntpdate 119.28.183.184
        11 Oct 09:12:45 ntpdate[4101856]: adjust time server 119.28.183.184 offset +0.011011 sec
    cpp文件执行：
        miaow@ubt:/work/miaow/mytest/ntp$ ./ntp_start_x86 
        11 Oct 13:10:50 ntpdate[100858]: adjust time server 84.16.67.12 offset +0.010427 sec
        成功同步时间：pool.ntp.org
        11 Oct 13:10:59 ntpdate[100956]: adjust time server 84.16.67.12 offset +0.006756 sec
        成功同步时间：pool.ntp.org
    脚本文件执行：
        miaow@ubt:/work/miaow/mytest/ntp$ ./ntp.sh 
        11 Oct 13:18:10 ntpdate[103638]: adjust time server 84.16.67.12 offset -0.007373 sec
        成功同步时间：pool.ntp.org

查看时间
    date

NTP协议应用于分布式时间服务器和客户端之间，实现客户端和服务器的时间同步，从而使网络内所有设备的时钟基本保持一致

NTP客户端启动与NTP服务器的时间请求交换。交换的结果是，客户端能够计算链路延迟及其本地偏移，并调整其本地时钟以匹配服务器计算机上的时钟。

到网站下载源码
http://www.ntp.org/downloads.html

x86版本编译：
    tar -xvf ntp-4.2.8p17.tar.gz
    cd ntp-4.2.8p17
    ./configure
    make
    生成的可执行文件在ntp-4.2.8p17/ntpdate下
x86 .so库编译
    解压后
     ./configure  --prefix=$(pwd)/output --with-yielding-select=yes \
      CFLAGS=-fPIC --enable-shared=yes 
    make
    make install
    进入libntp文件夹：cp libntp.a ../ntpdate/        
    进入ntpdate文件夹，执行
     gcc -shared -fPIC -o libntpdate.so -Wl,--whole-archive libntp.a ntpdate.o version.o -L. -lrt -pthread -Wl,--no-whole-archive
     gcc -o main main.c -ldl -pthread
     sudo ./main 119.28.183.184

板子是help2416开发板，芯片是三星2416，操作系统linux kernel 3.2

arm版本编译：
    tar -xvf ntp-4.2.8p17.tar.gz
    cd ntp-4.2.8p17
    mkdir output
    cp -r /work/miaow/s32-Apps/third_part/openssl1.1.1/include/* include/
    export CROSSCOMP_DIR=/work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin
        ./configure CC=${CROSSCOMP_DIR}/aarch64-none-linux-gnu-gcc CXX=${CROSSCOMP_DIR}/aarch64-none-linux-gnu-g++ --host=arm-linux \
        --prefix=$(pwd)/output --with-yielding-select=yes \
        --with-openssl-libdir=/work/miaow/s32-Apps/third_part/openssl1.1.1/lib_arm \
        --enable-local-libevent CFLAGS=-fPIC --enable-shared=yes
    make -j32
    make install
    生成的可执行文件在/ntp-4.2.8p17/output/bin路径下

arm版本 .so编译：
    tar -xvf ntp-4.2.8p17.tar.gz
    cd ntp-4.2.8p17
    cp -r /work/miaow/s32-Apps/third_part/openssl1.1.1/include/* include/
    export CROSSCOMP_DIR=/work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin
    ./configure CC=${CROSSCOMP_DIR}/aarch64-none-linux-gnu-gcc CXX=${CROSSCOMP_DIR}/aarch64-none-linux-gnu-g++ --host=arm-linux \
        --prefix=$(pwd)/output --with-yielding-select=yes \
        --with-openssl-libdir=/work/miaow/s32-Apps/third_part/openssl1.1.1/lib_arm \
        --enable-local-libevent CFLAGS=-fPIC --enable-shared=yes
    make
    make install
    cd libntp
    cp libntp.a ../ntpdate/   
    cd ../ntpdate
    /work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc -shared -fPIC -o libntpdate.so \
    -Wl,--whole-archive libntp.a ntpdate.o version.o -L. /work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/aarch64-none-linux-gnu/libc/usr/lib64/librt.so\
    /work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/aarch64-none-linux-gnu/libc/usr/lib64/libpthread.so\
    -Wl,--no-whole-archive
    编译.c文件
        /work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ -o \
        ntp_main_cpp ntp_main.cpp /work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/aarch64-none-linux-gnu/libc/usr/lib64/libdl.so
    

参考：网上教程基本都是install安装ntp服务器的教程，内部使用·不适用与于arm开发板
https://help.aliyun.com/zh/ecs/user-guide/configure-the-ntp-service-for-ecs-instances-that-run-centos-6?spm=a2c4g.11186623.0.i0#TimeCalibrationLinux

编译cpp文件
x86:
    g++ ntp_start.cpp -o ntp_start_x86
arm:
    /work/miaow/s32-Apps/tools/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++  ntp_start.cpp -o ntp_start_arm