"""
 * @author 001293
 * @someip data parse
 * @version 1.0
 * @date 2023-09 ~ 2023-09
 * @copyright Copyright (c) 2023
 * 
"""
import pandas as pd
import datetime
import glob
import configparser

# 创建配置文件对象
config = configparser.ConfigParser()

# 读取配置文件
config.read('docs/config.ini')

# 读取ZCUR配置项的值
file_path_ZCUR = config.get('ZCUR', 'file_path')
sheet_name_ZCUR_20ms = config.get('ZCUR', 'sheet_name_20ms')
sheet_name_ZCUR_50ms = config.get('ZCUR', 'sheet_name_50ms')
sheet_name_ZCUR_100ms = config.get('ZCUR', 'sheet_name_100ms')
sheet_name_ZCUR_500ms = config.get('ZCUR', 'sheet_name_500ms')
file_path_data_ZCUR_20ms = config.get('ZCUR', 'file_path_data_20ms')
file_path_data_ZCUR_50ms = config.get('ZCUR', 'file_path_data_50ms')
file_path_data_ZCUR_100ms = config.get('ZCUR', 'file_path_data_100ms')
file_path_data_ZCUR_500ms = config.get('ZCUR', 'file_path_data_500ms')
save_as_excel_name_ZCUR_20ms = config.get('ZCUR', 'save_as_excel_name_20ms')
save_as_excel_name_ZCUR_50ms = config.get('ZCUR', 'save_as_excel_name_50ms')
save_as_excel_name_ZCUR_100ms = config.get('ZCUR', 'save_as_excel_name_100ms')
save_as_excel_name_ZCUR_500ms = config.get('ZCUR', 'save_as_excel_name_500ms')
combined_excel_name_ZCUR = config.get('ZCUR', 'combined_excel_name_ZCUR')

# 读取ZCUL配置项的值
file_path_ZCUL = config.get('ZCUL', 'file_path')
sheet_name_ZCUL_20ms = config.get('ZCUL', 'sheet_name_20ms')
sheet_name_ZCUL_50ms = config.get('ZCUL', 'sheet_name_50ms')
sheet_name_ZCUL_100ms = config.get('ZCUL', 'sheet_name_100ms')
sheet_name_ZCUL_500ms = config.get('ZCUL', 'sheet_name_500ms')
file_path_data_ZCUL_20ms = config.get('ZCUL', 'file_path_data_20ms')
file_path_data_ZCUL_50ms = config.get('ZCUL', 'file_path_data_50ms')
file_path_data_ZCUL_100ms = config.get('ZCUL', 'file_path_data_100ms')
file_path_data_ZCUL_500ms = config.get('ZCUL', 'file_path_data_500ms')
save_as_excel_name_ZCUL_20ms = config.get('ZCUL', 'save_as_excel_name_20ms')
save_as_excel_name_ZCUL_50ms = config.get('ZCUL', 'save_as_excel_name_50ms')
save_as_excel_name_ZCUL_100ms = config.get('ZCUL', 'save_as_excel_name_100ms')
save_as_excel_name_ZCUL_500ms = config.get('ZCUL', 'save_as_excel_name_500ms')
combined_excel_name_ZCUL = config.get('ZCUL', 'combined_excel_name_ZCUL')

#获取CCC信号的起始位、长度、精度、偏移量
def get_ccc_signal_info(file_path_CCC, sheet_name):
    df = pd.read_excel(file_path_CCC, sheet_name=sheet_name)
    signal_info_list = []
    for index, row in df.iterrows():
        signal_name = row["CCC信号名"]
        signal_length = row["信号长度（bit）"]
        prev_signal_info = signal_info_list[-1] if signal_info_list else None
        start_bit = prev_signal_info["起始位"] + prev_signal_info["长度"] if prev_signal_info else 0
        resolution = row["精度"]
        offset = row["偏移量"]
        signal_info_list.append({"信号名": signal_name, "起始位": start_bit, "长度": signal_length,"精度": resolution, "偏移量": offset})
    return signal_info_list

def print_ccc_signal_info(ccc_signal_info):
    for signal_info in ccc_signal_info:
        print(f"信号名：{signal_info['信号名']}，起始位：{signal_info['起始位']}，长度：{signal_info['长度']}, 精度{signal_info['精度']}，偏移量：{signal_info['偏移量']}")

# 创建空表格，写入表头
def create_excel_with_signal_names(file_path, ccc_signal_info):
    df = pd.DataFrame(columns=["时间(ms)"] + [info["信号名"] for info in ccc_signal_info])
    df.to_excel(file_path, index=False)

# create_excel_with_signal_names(save_as_excel_name)

# 从数据文件读取时间戳和数据段
def read_data_from_file(file_path_data):
    timestamp_list = []
    data_segment_list = []

    # 打开文件
    with open(file_path_data, 'r') as file:
        # 逐行读取文件内容
        for line in file:
            # 分割每行内容为时间戳和数据段
            segments = line.strip().split(' ')
            timestamp = segments[0]
            data_segment = segments[1][16:]
            # print(data_segment)

            # 将时间戳和数据段分别添加到列表中
            timestamp_list.append(timestamp)
            data_segment_list.append(data_segment)
    
    # 返回时间戳和数据段列表
    return timestamp_list, data_segment_list

def convert_hex_to_decimal(hex_data,ccc_signal_info):
    # print(hex_data)
    #将16进制转换为二进制
    binary_data = bin(int(hex_data, 16))[2:].zfill(len(hex_data) * 4)   
    # print(binary_data)
    results = []  # 创建一个空列表来存储结果
    for signal_info in ccc_signal_info:
        signal_name = signal_info['信号名']
        start_bit = signal_info['起始位']
        signal_length = signal_info['长度']
        resolution = signal_info['精度']
        offset = signal_info['偏移量']
        a_binary = binary_data[start_bit:start_bit + signal_length]
        # print(a_binary)
        # a_decimal = int(a_binary[::-1], 2)  #二进制转换为十进制
        a_decimal = int(a_binary, 2)
        a_decimal = float(a_decimal * resolution + offset)
        # a_decimal = round(float(a_decimal * resolution + offset),2)     #设置保留至小数点后2位
        # print(f"信号名：{signal_name},数值：{a_decimal}")
        result = (signal_name, a_decimal)
        results.append(result)  # 将结果添加到列表中
    return results  # 返回包含所有结果的列表

def parse_someip(file_path_CCC,sheet_name,file_path_data,save_as_excel_name):
    ccc_signal_info = get_ccc_signal_info(file_path_CCC, sheet_name)
    # print_ccc_signal_info(ccc_signal_info)
    create_excel_with_signal_names(save_as_excel_name, ccc_signal_info)
    # 调用方法读取文件数据
    timestamp_list, data_segment_list = read_data_from_file(file_path_data)
    # print("时间戳列表:", timestamp_list)
    # print("数据段列表:", data_segment_list)
    counter = 0     #记录行号
    df = pd.read_excel(save_as_excel_name)  # 读取现有的 Excel 文件
    for hex_data in data_segment_list:
        # print("-----------------------------------------------------------------------------------------------------")
        print(f"==== 正在处理第 {counter+1} 条数据 ====")
        # print(f"时间戳：{timestamp_list[counter]}")
        timestamp = timestamp_list[counter]
        dt = datetime.datetime.fromtimestamp(int(timestamp) / 1000)  # 将时间戳转换为 datetime 对象
        # 获取毫秒部分
        milliseconds = int(timestamp) % 1000
        datetime_str = dt.strftime("%Y-%m-%d %H:%M:%S") + f".{str(milliseconds).zfill(3)}"  
        df.loc[counter, "时间(ms)"] = datetime_str        # 将对应值插入到 DataFrame 的相应行和列
        results = convert_hex_to_decimal(hex_data,ccc_signal_info)
        num_signals = len(results)
        for result in results:
            signal_name, a_decimal = result      # 解包元组中的值
            # print(f"信号名：{signal_name}，数值：{a_decimal}")
            df.loc[counter,signal_name] = str(a_decimal)
        counter += 1
        # print("结果中的 signal_name 数量为:", num_signals)

    df.to_excel(save_as_excel_name, index=False) 

parse_someip(file_path_ZCUR,sheet_name_ZCUR_20ms,file_path_data_ZCUR_20ms,save_as_excel_name_ZCUR_20ms)
print("文件 ZCUR_signal_data_20ms.xlsx 已生成")
parse_someip(file_path_ZCUR,sheet_name_ZCUR_50ms,file_path_data_ZCUR_50ms,save_as_excel_name_ZCUR_50ms)
print("文件 ZCUR_signal_data_50ms.xlsx 已生成")
parse_someip(file_path_ZCUR,sheet_name_ZCUR_100ms,file_path_data_ZCUR_100ms,save_as_excel_name_ZCUR_100ms)
print("文件 ZCUR_signal_data_100ms.xlsx 已生成")
parse_someip(file_path_ZCUR,sheet_name_ZCUR_500ms,file_path_data_ZCUR_500ms,save_as_excel_name_ZCUR_500ms)
print("文件 ZCUR_signal_data_500ms.xlsx 已生成")

parse_someip(file_path_ZCUL,sheet_name_ZCUL_20ms,file_path_data_ZCUL_20ms,save_as_excel_name_ZCUL_20ms)
print("文件 ZCUL_signal_data_20ms.xlsx 已生成")
parse_someip(file_path_ZCUL,sheet_name_ZCUL_50ms,file_path_data_ZCUL_50ms,save_as_excel_name_ZCUL_50ms)
print("文件 ZCUL_signal_data_50ms.xlsx 已生成")
parse_someip(file_path_ZCUL,sheet_name_ZCUL_100ms,file_path_data_ZCUL_100ms,save_as_excel_name_ZCUL_100ms)
print("文件 ZCUL_signal_data_100ms.xlsx 已生成")
parse_someip(file_path_ZCUL,sheet_name_ZCUL_500ms,file_path_data_ZCUL_500ms,save_as_excel_name_ZCUL_500ms)
print("文件 ZCUL_signal_data_500ms.xlsx 已生成")

selected_files_ZCUR = [save_as_excel_name_ZCUR_20ms,
                       save_as_excel_name_ZCUR_50ms,
                       save_as_excel_name_ZCUR_100ms,
                       save_as_excel_name_ZCUR_500ms
                      ]

selected_files_ZCUL = [save_as_excel_name_ZCUL_20ms,
                       save_as_excel_name_ZCUL_50ms,
                       save_as_excel_name_ZCUL_100ms,
                       save_as_excel_name_ZCUL_500ms
                      ]

# 将多个excel合并为一个excel文件
def merge_excels(selected_files, combined_excel_name):
    # 获取xlsx文件路径
    file_paths = glob.glob('someip_excels/*.xlsx')
    # 创建一个空的DataFrame来存储合并的数据
    combined_df = pd.DataFrame()
    # 循环读取每个xlsx文件，合并到combined_df中
    for file_path in file_paths:
        if file_path in selected_files:
            # 读取Excel文件
            df = pd.read_excel(file_path)
            # 将所有列的数据类型转换为字符串
            df = df.astype(str)
            # 合并数据，忽略原始索引
            combined_df = pd.concat([combined_df, df], ignore_index=True)
    # 按时间列对combined_df进行排序，假设时间列名为"时间"
    combined_df.sort_values('时间(ms)', inplace=True)
    # 按照时间列进行分组，获取每个时间组的第一个值所在的行
    df_first = combined_df.groupby('时间(ms)').transform('first')
    # 填充缺失值，将时间重复的行的数据复制到第一个时间对应的行
    df_filled = combined_df.fillna(df_first)
    # 删除重复的行
    combined_df = df_filled.drop_duplicates(subset='时间(ms)', keep='first')
    # print(combined_df.columns)
    # 将合并后的表格存储为新的Excel文件
    combined_df.to_excel(combined_excel_name, index=False)
    # 读取Excel文件数据
    df1 = pd.read_excel(combined_excel_name)  
    # 使用上一行的数据填充缺失值
    df1 = df1.fillna(method='ffill')
    df1 = df1.astype(str)
    # 将填充后的数据保存到原始 Excel 文件中
    df1.to_excel(combined_excel_name, index=False)
    print(f"合并后的表格已保存为: {combined_excel_name}")

merge_excels(selected_files_ZCUR, combined_excel_name_ZCUR)
merge_excels(selected_files_ZCUL, combined_excel_name_ZCUL)


#以20ms数据为基准保存合并后的数据(只保留20ms那个时间的数据)

# 从数据文件读取时间戳
def read_timelist_from_file(file_path_data):
    timestamp_list = []

    # 打开文件
    with open(file_path_data, 'r') as file:
        # 逐行读取文件内容
        for line in file:
            # 分割每行内容为时间戳和数据段
            segments = line.strip().split(' ')
            timestamp = segments[0]
            dt = datetime.datetime.fromtimestamp(int(timestamp) / 1000)  # 将时间戳转换为 datetime 对象
            # 获取毫秒部分
            milliseconds = int(timestamp) % 1000
            datetime_str = dt.strftime("%Y-%m-%d %H:%M:%S") + f".{str(milliseconds).zfill(3)}"  
            # 将时间戳和数据段分别添加到列表中
            timestamp_list.append(datetime_str)
    
    # 返回时间戳和数据段列表
    return timestamp_list

def delete_rows_not_in_timestamp_list(combined_excel_path, file_path_data):
    timestamp_list = read_timelist_from_file(file_path_data)
    # print(timestamp_list)
    # 读取 Excel 文件
    df = pd.read_excel(combined_excel_path)
    
    # 获取时间戳列的名称
    timestamp_column_name = df.columns[0]

    # 删除不在时间戳列表中的行
    df = df[df[timestamp_column_name].isin(timestamp_list)]

    # 保存修改后的文件
    df = df.astype(str)
    df.to_excel(combined_excel_path, index=False)

delete_rows_not_in_timestamp_list(combined_excel_name_ZCUL, file_path_data_ZCUL_20ms)
delete_rows_not_in_timestamp_list(combined_excel_name_ZCUR, file_path_data_ZCUR_20ms)