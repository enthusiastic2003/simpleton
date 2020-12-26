#include <types.h>
#include <stdio.h>
void kernel_main()
{
//*((int*)0xb8000)=0x07690748;
String fucker="The James Bond series focuses on a fictional British Secret Service agent created in 1953 by writer Ian Fleming, who featured him in twelve novels and two short-story collections. Since Fleming's death in 1964, eight other authors have written authorised Bond novels or novelisations: Kingsley Amis, Christopher Wood, John Gardner, Raymond Benson, Sebastian Faulks, Jeffery Deaver, William Boyd and Anthony Horowitz. The latest novel is Forever and a Day by Anthony Horowitz, published in May 2018. Additionally Charlie Higson wrote a series on a young James Bond, and Kate Westbrook wrote three novels based on the diaries of a recurring series character, Moneypenny.I am Sirjan.I am Sirjan.I am Sirjan.I am Sirjan.I am\n";

//int32 test=52;
//kprintf("Hello kernel world! now printing a number:  %d %d %s %x",test,-896,"Sirjan",vidmem);


kprintf(fucker);
kprintf("================================================================================");
kprintf(fucker);
kprintf("1\n");
kprintf("2\n");
kprintf("3\n");

}
// note this example will always write to the top
// line of the screen


