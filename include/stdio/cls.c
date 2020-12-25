#include <types.h>
void clearScreen()
{
   for(uint32 clea=1;clea<=25;clea++)
      {
         clearLine(clea);
      }
   X=0;
   Y=0;
}

