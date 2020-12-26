#include <types.h>
#include <stdio.h>
void kernel_main()
{
int32 test=52;
kprintf("Hello kernel world! now printing a number:  %d %d %s %x\ncheck complete",test,-896,"tester",vidmem);
port_init(COM1);
port_write_string(COM1,"Hello! tester!\nVideo address is %x\nMy name is %s ,my age is %d\nTrying to print a negetive number: %d",vidmem,"Sirjan Hansda",18,-8936);
}


