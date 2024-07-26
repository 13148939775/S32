#!/bin/bash

if [ -d "UTest" ]; then
    rm -rf UTest
fi
mkdir UTest

# 循环运行
while true; do
  current_time=$(date "+%Y-%m-%d %H:%M:%S");
  # 执行你的脚本
  /home/root/sysbin/app/SystemManager > "/home/root/log/UTest/UTestLog_${current_time}.txt"
  
  # 睡眠10分钟（600秒）
  sleep 600
done