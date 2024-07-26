执行程序：
拷贝s32-Apps/base_library/log/upload/docs、s32-Apps/base_library/log/upload/certificate

Vin Sn存储在加密文件/home/root/ota/encrydid_data.dat中
一个可用的vin、sn
vin:H0322332002070786
sn:AA2304290000002556

config.json文件中：
    flagTest：true --> 当前是测试 --> 每次上传文件过后模拟车端创建日志文件
                                     每次间隔时间的单位是秒
              false --> 当前是实际情况
    maxSizeInBytes --> 目录里的文件最大总大小,超过这个值，就删除时间最早的fileCount个文件，单位是GB
    fileCount --> 每次删除的文件数量
    upload_files_num_eachtime --> 设置每次上传的文件最大数量，若目录下符合条件的文件数量小于这个值，就全部上传
    intervalTime  --> 设置两次日志上传的时间间隔，单位是秒(s)
    delete_source_file  -->  上传成功后是否删除压缩文件中的源文件
    delete_compressed_file  -->  上传成功后是否删除压缩文件

去掉所有后缀名.uploadbak命令：
sudo find . -type f -name "*.uploadbak" -exec sh -c 'mv "$0" "${0%.uploadbak}"' {} \;