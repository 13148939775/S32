/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ICEORYX_WAIT_C_H
#define ICEORYX_WAIT_C_H

// 备注 ：
// para: eventID : 等待的事件， 1 表示在等待是否Doip诊断仪连接上。
// timeout :设置最大的等待时间, 单位是second
// 关于返回值 -1 表示有误；0:表示当前没有 1：表示当前连接上

extern int WaitEvt(const int evtID, const int timeout);

#endif /* WAIT_SET_C_KIT_H */
