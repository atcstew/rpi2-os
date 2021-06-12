#include "pi2.h"
#include "graphics.h"


int kernel_main(void)
{
    /*CODE BODY STARTS HERE (called from _start)*/
    
    
    initFrameBuffer(1024, 768);    
    drawPixel(100, 100, 0xa0);
    return 0;
    
    /*CODE BODY ENDS HERE (returns to _stop )*/

}

  
