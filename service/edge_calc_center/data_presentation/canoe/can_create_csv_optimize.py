"""
 * @author 001293
 * @simplifying tabular data
 * @version 1.0
 * @date 2023-08 ~ 2023-09
 * @copyright Copyright (c) 2023
 * 
"""
#合并多个时间戳内的数据为最近一次的数据 --> 精简文件内容
#先执行can_create_csv.py，生成Trace111SingalFlow.csv后，再执行此程序
#!/usr/bin/python3
import csv
from datetime import datetime, timedelta

start_time = datetime(2023, 1, 1, 0, 0)  # 设置起始时间
increment = timedelta(minutes=20)  # 设置递增时间间隔

# 打开原始的CSV文件和新的CSV文件
with open('Trace111SingalFlow.csv', 'r') as file_in, open('Trace111SingalFlowLessa.csv', 'w', newline='') as file_out:
    reader = csv.reader(file_in)
    writer = csv.writer(file_out)
    
    # 读取CSV文件的标题行
    header = next(reader)

    # # 删除源文件标题行的第1个元素
    # header.pop(0)

    # 修改标题行，在首列加入"Time"列名
    header.insert(0, "Time")
    writer.writerow(header)
    
    # 记录每个区间的结束时间
    end_time = 0
    
    # 循环读取每一行数据
    for row in reader:
        time = float(row[0])
        
        # 判断当前行是否在指定区间内
        if time >= end_time:
            # writer.writerow(row)

            # # 删除源文件第首列
            # del row[0]

            writer.writerow([start_time.strftime("%Y/%m/%d,%H:%M")] + row)  # 每行的时间为格式化后的时间
            start_time += increment  # 时间递增
            end_time += 0.02