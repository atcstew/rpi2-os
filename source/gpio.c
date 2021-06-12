#include "gpio.h"


void writePin(unsigned int pinNum, unsigned int value);
unsigned int readPint(unsigned int pinNum);

void setPinFunction(unsigned int pinNum, unsigned int funcCode)
{
    volatile unsigned int* pinFunction;
    unsigned int regNum = pinNum / 10;
    
    switch(regNum)
    {
        case 0:
            pinFunction = GPFSEL0;
            break;
        case 1:
            pinFunction = GPFSEL1;
            break;
        case 2:
            pinFunction = GPFSEL2;
            break;
        case 3:
            pinFunction = GPFSEL3;
            break;
        case 4:
            pinFunction = GPFSEL4;
            break;
        case 5:
            pinFunction = GPFSEL5;
            break;
            
        default:
            return;    
    }
    
    int clearMask = 0x111;
    int value = *pinFunction;
    
    clearMask = clearMask << (pinNum % 10);
    value = value & (~clearMask);       //clear pin number bits
   
    value = value | (funcCode << (pinNum % 10));//set function bits
    *pinFunction = value; 
    return;
}

