#include "timer.h"


void wait(unsigned int time)
{
    volatile unsigned int* lowTime;
    lowTime = TIME_LCNT;
    
    int compareTime = *lowTime + time;
    
    while(1)
    {
        if(compareTime < *lowTime)
        {
            break;
        }
    }
    
    return;

}


