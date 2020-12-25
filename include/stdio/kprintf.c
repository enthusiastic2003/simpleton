#include<stdarg.h>
#include<types.h>
void kprintf(uint32 count,...)
{
    va_list list;
    uint32 argn=0;
    
    va_start(list,count);
    
    uint32 i=0;
    i=strnlen(str);
    for(uint32 j=0;j<=i-1;j++)
    {
        putchar(str[j]);
    }
 
}
