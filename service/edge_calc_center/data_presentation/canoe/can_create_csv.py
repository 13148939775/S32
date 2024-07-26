"""
 * @author 001293
 * @excel sheets were generated according to dbc and asc files
 * @version 1.0
 * @date 2023-08 ~ 2023-09
 * @copyright Copyright (c) 2023
 * 
"""
#!/usr/bin/python3
import cantools
import can
import csv

dbc_file = 'HH_AN1(IVCar)_HDBM_VBackbone1_CAN_Matrix_V1.5.dbc'
asc_file = 'Trace111a.asc'
csv_filename = 'Trace111SingalFlow.csv'

# 加载DBC文件
dbc = cantools.database.load_file(dbc_file)

# 从DBC文件中获取所有信号名称
signal_names = []
for message in dbc.messages:
    for signal in message.signals:
        signal_names.append(signal.name)

# 创建一个字典用于存储每个信号的值
signals_values = {signal: [] for signal in signal_names}

# 打开ASC文件
asc = can.ASCReader(asc_file)

# 获取所有消息ID
dbc_message_ids = set(message.frame_id for message in dbc.messages)

timestamps = []  # 存储时间戳
prev_signals = {signal: None for signal in signal_names}  # 上一次时间戳的信号值

# 逐行读取ASC文件并解析信号值
for msg in asc:
    if msg.arbitration_id in dbc_message_ids:
        timestamps.append(msg.timestamp)  # 保存时间戳
        signal_values = dbc.decode_message(msg.arbitration_id, msg.data)
        # print(signal_values)
        for signal in signal_names:
            if signal in signal_values:
                if hasattr(signal_values[signal], 'value'):
                    # print(signal_values[signal].value)
                    signals_values[signal].append(signal_values[signal].value)
                    prev_signals[signal] = signal_values[signal].value   #记录本次信号值
                else:
                    signals_values[signal].append(signal_values[signal])
                    prev_signals[signal] = signal_values[signal]   #记录本次信号值
            else:
                # signals_values[signal].append(None)   #如果此时没有信号，就填充空
                signals_values[signal].append(prev_signals[signal]) #填充上一次信号值

# 写入CSV文件,设置编码方式是latin1(防止中文乱码)
with open(csv_filename, 'w', newline='', encoding='latin1') as csv_file:
    writer = csv.writer(csv_file)
    
    # 写入CSV文件头（时间戳列和信号列）
    header = ['Timestamp']
    for signal in signal_names:
        for message in dbc.messages:
            if signal in [s.name for s in message.signals]:
                # header.append(f"{dbc_filename}::{message.name}::{signal}")
                header.append(f"{message.name}::{signal}")
                break  # 找到消息后停止
    writer.writerow(header)

    # 根据信号值列表中最长的列表确定行数
    num_rows = max(len(signals_values[signal]) for signal in signal_names)
    
    # 根据行数逐行写入
    for i in range(num_rows):
        row = [timestamps[i]]  # 使用保存的时间戳
        for signal in signal_names:
            row.append(signals_values[signal][i] if i < len(signals_values[signal]) else None)  
        writer.writerow(row)
