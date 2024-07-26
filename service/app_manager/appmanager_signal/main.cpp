/* @author T001285
 * @for client application main
 * @version 0.1
 * @date 2023-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "application_scaffold.h"
#include "app_example.h"
#include "node_log.h"

int main()
{
  HHT::NodeLog node("app_example");    //送入进程名字
  node.InitLog(LOG_LEVEL_INFO,LOG_LEVEL_INFO); //初始化consle和日志文件的初始记录等级
  return HHT::ApplicationScaffold<HHT::AppExample>::Main();
}
