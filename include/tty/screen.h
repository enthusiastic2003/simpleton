//to print through VGA text mode.
#ifndef SCREEN_H
#define SCREEN_H
#include <types.h>
#include <String.h>

void putchar(uint32);
void setCursor();
void justPutTheCharacter(char);

static const String vidmem=(String) 0xb8000;
static uint32 printed=0;
static uint32 print_head=0;
void scrollUp();

//color defination
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHT_GREY 7
#define DARK_GREY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_MAGENTA 13
#define LIGHT_BROWN 14
#define WHITE 15
//color defination end
#include<stdarg.h>
static uint32 X=0;
static uint32 Y=0;

const uint32 width=80;
const uint32 height=25;




void putchar(uint32 pr_order)
{
if(pr_order=='\n')
{
   Y++;
   return;
}
//character keys here
   setCursor();
   justPutTheCharacter(pr_order);     
}


void justPutTheCharacter(char final_order)
{
print_head=2*printed;
vidmem[print_head]=final_order;
}


void setCursor()
{
       if(X==width)
         {
           Y++;
           X=0;
           if(Y==height)
               scrollUp();
         }
        printed=width*Y+X;
        X++;
   
}

void scrollUp()
{
    int op1;
    int op2;
    for(int rown=1;rown<=24;rown++)
    {
        for(int column=0;column<=79;column++)
        {
            op1=rown*80+column;
            op1=op1*2;
            op2=(rown-1)*80+column;
            op2=op2*2;
            vidmem[op2]=vidmem[op1];
            vidmem[op1]=' ';
        }
    }
    Y--;
}
#endif
