/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <unistd.h>
#include "publisher_c_wrapper.h"

int main(int argc, char *argv[]) 
{
  //while (true) {
      //PubDoipEvent(98);
      //sleep(3);
  //}

        newPubClass();
        int value = PubClass_Pub(1);
        printf("%d\n", value);
        deletePubClass();
  return 0;
}