
# DataManager 测试 Demo

PC 上接收视频和结构化数据 demo, 用于测试 DataManager.

## 1. x86 ubuntu 编译

0. 最新 DataManager 仅支持通过 ZMQ 发送视频数据, 若仍需要通过 RTP 接收视频数据, 请现在下面提到的代码, 使用最新 commit 自行编译 jrtplib 和 jthread.
    - https://github.com/j0r1/JThread.git
    - https://github.com/j0r1/JRTPLIB.git

1. ( 若不需要 RTP 或者不清楚具体细节, 可跳过 )首先需要使用 cmake 编译 jthread, 然后编译 jrtplib. 编译先后顺序有要求. 默认安装到 /usr/local 路径下.

2. 依赖 ffmpeg, ubuntu 可以通过 sudo apt install ffmpeg 安装

3. 依赖 zmq, ubuntu 可以通过 sudo apt install libzmq3-dev 安装

4. 使用 cmake 编译代码

## 2. 使用示例

``./zmqVideoDemo 2``

接收 2 路视频数据, 在执行命令的目录下创建 recv_data 文件夹
- 结构化数据的信息保存在 structured.bin.txt 文件内(没有保存完整结构化数据, 仅保存了数据长度等信息)
- 视频数据保存在 v[cameraIndex].zmq.h264 文件夹内, 可以通过 smplayer/mpv 实时播放, 支持边接收数据边播放.
- 视频帧索引及视频戳保存在 v[cameraIndex].zmq.h264.txt 文件内.
