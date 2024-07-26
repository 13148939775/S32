1、ipcf数据解析相较于someip需要更多算力，所以解析需要的时间要长很多
    
    经测试，解析数据大概需要：100行数据10秒，500行2分10秒，1000行数据11分钟

2、执行脚本文件parse_ipcf.py会解析IPCF_Data_Structure.xlsx和test_data.txt得到具体信号值，保存在ipcf_signal_data.xlsx中