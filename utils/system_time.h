#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

#include <sys/time.h>

namespace Utils {
static timeval GetTimeofDay()
{
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv; 
}

}


#endif /* SYSTEM_TIME_H */
