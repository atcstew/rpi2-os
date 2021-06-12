#include "pi2.h"
#ifndef graphics_h
#define graphics_h

#define MAILBASE0  (PI2BASE + 0x00b880)


#define MAIL0_READ (unsigned int*)(MAILBASE0 + 0x00)
#define MAIL0_PEEK (unsigned int*)(MAILBASE0 + 0x10)
#define MAIL0_SNDR (unsigned int*)(MAILBASE0 + 0x14)
#define MAIL0_STAT (unsigned int*)(MAILBASE0 + 0x18)
#define MAIL0_CNFG (unsigned int*)(MAILBASE0 + 0x1c)
#define MAIL0_WRIT (unsigned int*)(MAILBASE0 + 0x20)

#define MAIL_FULL BIT31
#define MAIL_EMPT BIT30

int initFrameBuffer(unsigned int xres, unsigned int yres);
void drawPixel(unsigned int x, unsigned int y, unsigned char colour);

enum Colours {WHITE = 0xff};

typedef struct
{
    unsigned long int  buffersize;
    unsigned long int  gpurequest;
    
    unsigned long int  physicaltag;
    unsigned long int  physsize;
    unsigned long int  physlen;
    unsigned long int  physxres;
    unsigned long int  physyres;
    
    unsigned long int  virtualtag;
    unsigned long int  virtsize;
    unsigned long int  virtlen;
    unsigned long int  virtxres;
    unsigned long int  virtyres;
    
    unsigned long int  bpptag;
    unsigned long int  bppsize;
    unsigned long int  bpplen;
    unsigned long int  bpp;
    
    unsigned long int  framebuftag;
    unsigned long int  fbsize;
    unsigned long int  fblen;
    unsigned long int  fbptr;
    unsigned long int  fbptrsize;
    unsigned long int  end;
} FrameBufferInit;


#endif
