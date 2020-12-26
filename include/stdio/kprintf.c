#ifndef _KPRINTF_C
#define _KPRINTF_C
#include<stdarg.h>
#include<types.h>
static void b2convert(unsigned int num, int base);
static void puts(String put_input);
//full support enabled
void kprintf(String format,...)
{
    va_list list;
    va_start(list,format);
    static String control;
    control=format;
    
    static int32 integer_to_print;
    static char character_to_print;
    static String string_to_print;
    static uint32 hexa_to_print;
    static uint32 octa_to_print;
        
    
    for(;*control!='\0';control++)
    {
       while((*control !='%')&&(*control != '\0'))
        {
            character_to_print=*control;
            putchar(character_to_print);
            control++;
        }
      
      
         if(*control!='\0')
         {
             control++;
           switch(*control)
            {
               
                case 'd':
                    
                    integer_to_print=va_arg(list,int32);
                    if(integer_to_print>0)
                    {
                        b2convert(integer_to_print,10);
                 
                    }
                    else if(integer_to_print<0)
                    {
                        putchar('-');
                        integer_to_print=-integer_to_print;
                        b2convert(integer_to_print,10);
                      
                    }
                    
                    break;
                case 's':
                    string_to_print=va_arg(list,String);
                    puts(string_to_print);
                    
                    break;
                case 'c':
                    character_to_print=(char)va_arg(list,int);
                    putchar(character_to_print);
                    
                    break;
                case 'x':
                    hexa_to_print=va_arg(list,uint32);
                    puts("0x");
                    b2convert(hexa_to_print,16);
                    
                    break;
                case 'o':
                    octa_to_print=va_arg(list,uint32);
                    b2convert(octa_to_print,8);
                    
                    
            }
         }
         if(*control=='\0')
         {
             break;
         }
             
       }
   
    
    
    va_end(list); 
    
}


void b2convert(unsigned int num, int base) 
{ 
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50]; 
	static String ptr; 
	
	ptr = &buffer[49]; 
	*ptr = '\0'; 
	
	do 
	{ 
		*--ptr = Representation[num%base]; 
		num /= base; 
	}while(num != 0); 
	
	puts(ptr); 
}
static void puts(String put_input)
{
    static char characterless;
    while(*put_input !='\0')
        {
            characterless=*put_input;
            putchar(characterless);
            put_input++;
        }
}
#endif
