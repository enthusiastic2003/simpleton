#ifndef _STRING_H
#define _STRING_H
#include "types.h"
int strnlen(String org)
{
   int len=0;
   while(org[len]!='\0')
   {
       len++;
   }
   return len;
}
#endif

