#include <types.h>
#include <stdio.h>
void kernel_main()
{
int32 test=52;
kprintf("Hello kernel world! now printing a number:  %d %d %s %x\ncheck complete",test,-896,"Sirjan",vidmem);
port_init(COM1);
write_serial(COM1,'H');
}


