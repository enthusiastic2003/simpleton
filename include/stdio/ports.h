#ifndef _PORTS_H
#define _PORTS_H
#include <types.h>
#include <stdio.h>
#define COM1 0x3F8
#define COM2 0x2F8
#define COM3 0x3E8
#define COM4 0x2E8

uint8 inportb (uint16 _port)
{
    	uint8 rv;
    	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    	return rv;
}

void outportb (uint16 _port, uint8 _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void port_init(uint16 port_to_init)
{
   kprintf("\nPORT: ORDER RECEIVED TO INIT PORT %x",port_to_init);
   outportb(port_to_init + 1, 0x00);    // Disable all interrupts
   outportb(port_to_init + 3, 0x80);    // Enable DLAB (set baud rate divisor)
   outportb(port_to_init + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
   outportb(port_to_init + 1, 0x00);    //                  (hi byte)
   outportb(port_to_init + 3, 0x03);    // 8 bits, no parity, one stop bit
   outportb(port_to_init + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
   outportb(port_to_init + 4, 0x0B);    // IRQs enabled, RTS/DSR set
   outportb(port_to_init + 4, 0x1E);    // Set in loopback mode, test the serial chip
   outportb(port_to_init + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)
 
   // Check if serial is faulty (i.e: not same byte as sent)
   if(inportb(port_to_init + 0) != 0xAE) {
      kprintf("\nPORT: Cannot init port %x",port_to_init);
   }
 
   // If serial is not faulty set it in normal operation mode
   // (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
   outportb(port_to_init + 4, 0x0F);
   kprintf("\nPORT: INIT SUCCESSFULL FOR %x",port_to_init);
}




//FOR DATA RECEIVE
int serial_received(uint16 chk1) {
   return inportb(chk1 + 5) & 1;
}
 
char read_port(uint16 read_from_port) {
   kprintf("\nPORT: trying to read %x",read_from_port);
   while (serial_received(read_from_port) == 0);
   return inportb(read_from_port);
}



//FOR TRANSMIT
int is_transmit_empty(uint16 chk2) {
   return inportb(chk2 + 5) & 0x20;
}
 
void write_serial(uint32 write_port_data,char write_data) {
   kprintf("\nPORT: trying to send %c %x",write_data,write_port_data);
   while (is_transmit_empty(write_port_data) == 0);
 
   outportb(write_port_data,write_data);
   kprintf("\nPORT: data write successful %x, %c",write_port_data, write_data);

}




#endif
