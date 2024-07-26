1、 在docs下的config.ini文件中，读取相关配置
    可根据需求，在config.ini文件中作修改
    一般来说，只需修改下面几个参数为实际数据即可，脚本文件会根据配置读取对应内容
        file_path_data_20ms 
        file_path_data_50ms 
        file_path_data_100ms 
        file_path_data_500ms 
    如果想要修改生成的文件名，可修改如下配置：
        其中，someip_excels是当前目录下的someip_excels文件夹，脚本文件会先生成四个不同频率下的文件，再将它们合并为一个文件
        当然了，也可修改someip_excels为其他路径
        save_as_excel_name_20ms = someip_excels/ZCUR_signal_data_20ms.xlsx
        save_as_excel_name_50ms = someip_excels/ZCUR_signal_data_50ms.xlsx
        save_as_excel_name_100ms = someip_excels/ZCUR_signal_data_100ms.xlsx
        save_as_excel_name_500ms = someip_excels/ZCUR_signal_data_500ms.xlsx
        combined_excel_name_ZCUR = someip_excels/ZCUR_combined.xlsx         -->   由上面四个文件合并而成

2、 会读取data_format目录下ipcf格式文件和ipcf_data下的数据文件，最终得到excel文件，保存在someip_excels文件夹下
        someip_data下的数据文件没有区分是ZCUR还是ZCUL，只是测试用，
        之后可以更改为对应的实际数据，再在config.ini文件中作相关配置

3、 执行脚本前，请确保data_format、docs、someip_data下文件完整性，以及someip_excels目录存在
    且config.ini中配置为正确路径