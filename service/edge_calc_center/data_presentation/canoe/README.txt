can_create_csv.py文件：

        根据dbc文件和asc文件，得到csv文件，其中没有信号的时候，用上一次最近的信号的数据填充

        can.ASCReader这个函数源码做了修改，以去掉asc文件中Rx/Tx收发这一列，具体修改如下：
        在/home/miaow/.local/lib/python3.8/site-packages/can/io/asc.py的209行左右：
                # channel, direction, rest_of_message = line.split(None, 2) #改动：去掉direction，2改为1
                channel,  rest_of_message = line.split(None, 1) 
                # See ASCWriter
                msg_kwargs["channel"] = int(channel) - 1
                # msg_kwargs["is_rx"] = direction == "Rx"   #改动：注释本行


can_create_csv_optimize.py文件：
        根据can_create_csv.py生成的csv文件，做出优化，增加指定格式时间列，以指定时间间隔简化数据

        这里的Trace111a.asc文件是去掉Rx/Tx收发一列、并且只取了部分数据的文件，因为原来的文件Trace111.asc太大了，这里只是做测试用