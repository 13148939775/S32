/*
 * @author 008196
 * @for test IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "cpp/comm_config.h"

#include <stdio.h>
#include "wait_c_kit.h"

bool exitThread = false;
int res = false;

int main(int argc, char *argv[]) 
{
  while (exitThread == false) {
      res = WaitEvt(1, 20);
      if (res == -1) {
        printf("error waiting for doip event\n");
      } else {
        printf("Get for doip event %d\n", res);
      }
  }
  return 0;
}
