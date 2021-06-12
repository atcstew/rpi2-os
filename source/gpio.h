#include "pi2.h"

#ifndef gpio_h
#define gpio_h

#define GPIOBASE (PI2BASE + 0x200000)


#define GPFSEL0   (unsigned int *)(GPIOBASE + 0x00)
#define GPFSEL1   (unsigned int *)(GPIOBASE + 0x04)
#define GPFSEL2   (unsigned int *)(GPIOBASE + 0x08)
#define GPFSEL3   (unsigned int *)(GPIOBASE + 0x0c)
#define GPFSEL4   (unsigned int *)(GPIOBASE + 0x10)
#define GPFSEL5   (unsigned int *)(GPIOBASE + 0x14)

#define GPSET0    (unsigned int *)(GPIOBASE + 0x1c)
#define GPSET1    (unsigned int *)(GPIOBASE + 0x20)

#define GPCLR0    (unsigned int *)(GPIOBASE + 0x28)
#define GPCLR1    (unsigned int *)(GPIOBASE + 0x2c)

#define GPLEV0    (unsigned int *)(GPIOBASE + 0x34)
#define GPLEV1    (unsigned int *)(GPIOBASE + 0x38)

#define GPEDS0    (unsigned int *)(GPIOBASE + 0x40)
#define GPEDS1    (unsigned int *)(GPIOBASE + 0x44)

#define GPREN0    (unsigned int *)(GPIOBASE + 0x4c)
#define GPREN1    (unsigned int *)(GPIOBASE + 0x50)

#define GPFEN0    (unsigned int *)(GPIOBASE + 0x58)
#define GPFEN1    (unsigned int *)(GPIOBASE + 0x5c)

#define GPHEN0    (unsigned int *)(GPIOBASE + 0x64)
#define GPHEN1    (unsigned int *)(GPIOBASE + 0x68)

#define GPLEN0    (unsigned int *)(GPIOBASE + 0x70)
#define GPLEN1    (unsigned int *)(GPIOBASE + 0x74)

#define GPAREN0   (unsigned int *)(GPIOBASE + 0x7c)
#define GPAREN1   (unsigned int *)(GPIOBASE + 0x80)

#define GPAFEN0   (unsigned int *)(GPIOBASE + 0x88)
#define GPAFEN1   (unsigned int *)(GPIOBASE + 0x8c)

#define GPPUD     (unsigned int *)(GPIOBASE + 0x94)
#define GPPUDCLK0 (unsigned int *)(GPIOBASE + 0x98)
#define GPPUDCLK1 (unsigned int *)(GPIOBASE + 0x9c)


void setPinFunction(unsigned int pinNum, unsigned int funcCode);
void writePin(unsigned int pinNum, unsigned int value);
unsigned int readPint(unsigned int pinNum);


enum pinFunctionCodes {INPUT, OUTPUT, ALT5, ALT4, ALT0, ALT1, ALT2, ALT3};

#endif
