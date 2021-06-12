#include "pi2.h"
#ifndef timer_h
#define timer_h


#define TIMERBASE   (PI2BASE + 0x003000)

#define TIME_CTRL    (unsigned int *)(TIMERBASE + 0x00)
#define TIME_LCNT    (unsigned int *)(TIMERBASE + 0x04)
#define TIME_HCNT    (unsigned int *)(TIMERBASE + 0x08)
#define TIME_CMP0    (unsigned int *)(TIMERBASE + 0x0c)     
#define TIME_CMP1    (unsigned int *)(TIMERBASE + 0x10)
#define TIME_CMP2    (unsigned int *)(TIMERBASE + 0x14)
#define TIME_CMP3    (unsigned int *)(TIMERBASE + 0x18)

void wait(unsigned int time);

#endif
