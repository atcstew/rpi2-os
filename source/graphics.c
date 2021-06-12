#include "graphics.h"

//align to 16 byte boundaries
static FrameBufferInit data __attribute__ ((aligned (16)));
volatile unsigned char * frameBuffer __attribute__ ((aligned (16)));

static unsigned int xResolution = 0;
static unsigned int yResolution = 0;
static unsigned int bitDepth = 0;


void drawPixel(unsigned int x, unsigned int y, unsigned char colour)
{
    if(0 <= x && x < xResolution)
    {
        if(0 <= y && y < yResolution)
        {
            unsigned int elementOffset = ((y*yResolution)+x) * (bitDepth/8);
            *(frameBuffer + elementOffset) = colour;
            
        }
    }
    return;
}

int initFrameBuffer(unsigned int xres, unsigned int yres)
{
    
    data.buffersize = 88;
    data.gpurequest = 0;
    
    data.physicaltag = 0x00048003;
    data.physsize = 8;
    data.physlen = 8;
    data.physxres = xres;
    data.physyres = yres;
    
    data.virtualtag = 0x00048004;
    data.virtsize = 8;
    data.virtlen = 8;
    data.virtxres = xres;
    data.virtyres = yres;
    
    data.bpptag = 0x00048005;
    data.bppsize = 4;
    data.bpplen = 4;
    data.bpp = 8;
    
    data.framebuftag = 0x00040001;
    data.fbsize = 8;
    data.fblen = 8;
    data.fbptr = 0;
    data.fbptrsize = 0;
    
    data.end = 0;
    
    unsigned int value = 0;
    volatile FrameBufferInit* fbinit;
    fbinit = &data; 
    do
    {
        value = *MAIL0_STAT;  
    }
    while(value & MAIL_FULL);
    

    
    value = (unsigned int) (fbinit + 0x40000000);
    value = value | 0x8;
    *MAIL0_WRIT = value;
    value = *MAIL0_STAT;
    
    while(1)
    {
        do
        {
            value = *MAIL0_STAT;
        }
        while(value & MAIL_EMPT);
        
        value = *MAIL0_READ;
        value = value & 0xf;
        
        if(value & 0x8)
        {
            if(fbinit->gpurequest & BIT31)
            {
                unsigned int* ptr;
                do
                {        
                    
                    ptr = (unsigned int*)fbinit->fbptr;                                
                    
                }                
                while(ptr == 0);
                
                frameBuffer = (unsigned char *) ptr;
                xResolution = xres;
                yResolution = yres;
                bitDepth = 8;
                

                return 1;
                
            }
            else
            {   
                
                return 0;
            }
        }
    
    }
    
    return 0;
}

