目录说明：
    signal inject: 模拟注入CAN 数据；完成仿真的闭环数据存贮；

    

目的：VX1 客户车辆（VIN：LJD8AC3F4M0010326）在KL15 OFF后出现VDCM KL15硬线采集信号周期变化的情况，
导致小电池馈电时无法正常进行智能补电的问题。为了确认这是单车问题还是普遍问题，需要对行驶里程在25000km以上的客户车辆进行持续监控。

关于数据过滤
1、someip 里的数据一定是需要上传的数据

3、事件判断  HOD 传感器异常监控

1	BDCM_FLSeatOccupied_St	    主驾占位信号	BDCM	车端原始频率	条件判断	车端信号
2	SCMFR_Occupied_St	        副驾占位信号	BDCM	车端原始频率	条件判断	车端信号
3	BDCM_LogicLock_St	        整车逻辑锁状态	BDCM	车端原始频率	条件判断	车端信号
4	DCM_FL_WindowPosition_Rsp	主驾车窗开度	BDCM	车端原始频率	条件判断	车端信号
5	BDCM_HOD_TouchIntensityZone1	内圈感应区1	BDCM	车端原始频率	结果输出	车端信号
6	BDCM_HOD_TouchIntensityZone2	右外圈感应区2	BDCM	车端原始频率	结果输出	车端信号
7	BDCM_HOD_TouchIntensityZone3	左外圈感应区3	BDCM	车端原始频率	结果输出	车端信号
8	BDCM_HOD_TouchState	            HOD状态	       BDCM	   车端原始频率	   故障判断	   车端信号
9	HOD_Fault_alarm	HOD故障报警信号	 BDCM	        实时（EXD边缘计算结果）	报警信号变量	其他

1、监控逻辑（车端）
     车端边缘计算进行监控逻辑判断。
     使能条件：(1)主驾、副驾座椅无占位；(2)主驾车窗关闭（＜15%）；(3)整车逻辑锁闭锁状态 
     报警条件：HOD为接触状态（1~7），上传报警数据。
2、报警机器人（云端）
     TSP收到车端上传报警数据后触发报警机器人推送告警信息，如果15min之内同一车辆有连续报警，仅推送一次。
3、EXD算法相关信息
    ①EXD边缘端算法下发域：BDCM
    ②算法版本号前11位：BDCM_100002
    ③算法信号及值定义：报警信号HOD_Fault_alarm=1时为报警状态
4、算法批量部署
     对所有VX1客户车辆监控，TSP需进行批量算法下发，所有用户车辆都需部署（不区分BDCM软件版本）。