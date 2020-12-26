#ifndef _CLL_C
#define _CLL_C
#include<types.h>
void clearLine(uint32 to_clean)
{
   uint32 Y_bak=Y;
   uint32 X_bak=X;
   Y=to_clean-1;
  for(uint32 loopr=0;loopr<=width-1;loopr++)
     {
         X=loopr;
         setCursor();
         justPutTheCharacter((char)0x0);
     }
  X=X_bak;
  Y=Y_bak;
}
#endif
