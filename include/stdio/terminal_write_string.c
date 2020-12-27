#ifndef _PORT_WRITE_STRING_C
#include<stdio.h>
#include<types.h>
#include<stdarg.h>

static void port_conversion(uint16,uint32,int32);
static void port_string_org(uint16,String);

void port_write_string(uint16 COM_PORT_CODE,String port_string_input,...)
{
    va_list port_controller;
    
    int32 port_data_integer;
    String port_data_string;
    char port_data_char;
    uint32 port_data_octa;
    uint32 port_data_hexa;
    
    va_start(port_controller,port_string_input);
    String control_string_port=port_string_input;
    kprintf("\nPORT: trying to send %s to %x",control_string_port,COM_PORT_CODE);
    
    for(;*control_string_port!='\0';control_string_port++)
    {
        while((*control_string_port!='\0')&&(*control_string_port!='%'))
        {
            write_serial(COM_PORT_CODE,*control_string_port);
            control_string_port++;
        }
        control_string_port++;
        if(*control_string_port!='\0')
        {
            switch(*control_string_port)
            {
                case 'd':
                    port_data_integer=va_arg(port_controller,int32);
                    if(port_data_integer<0)
                    {
                        port_data_integer=-port_data_integer;
                        write_serial(COM_PORT_CODE,'-');
                    }
                    port_conversion(COM_PORT_CODE,port_data_integer,10);
                    break;
                
                case 's':
                    port_data_string=va_arg(port_controller,String);
                    port_string_org(COM_PORT_CODE,port_data_string);
                    break;
                    
                case 'x':
                    port_data_hexa=va_arg(port_controller,uint32);
                    port_string_org(COM_PORT_CODE,"0x");
                    port_conversion(COM_PORT_CODE,port_data_hexa,16);
                    break;
                    
                case 'c':
                    port_data_char=(char)(va_arg(port_controller,int));
                    write_serial(COM_PORT_CODE,port_data_char);
                    break;
                    
                case 'o':
                    port_data_octa=va_arg(port_controller,uint32);
                    port_conversion(COM_PORT_CODE,port_data_octa,8);
                    break;
                    
            }
        }
        if(*control_string_port=='\0')
            break;
    }
    kprintf("\nPORT: send succeeded to %s %x",control_string_port,COM_PORT_CODE);
    
    va_end(port_controller);
    
}





static void port_conversion(uint16 PORT_INFO,uint32 kady,int32 base_port)
{
    static char repo[]= "0123456789ABCDEF";
	static char port_buffer[50]; 
	static String ptr_port; 
	
	ptr_port = &port_buffer[49]; 
	*ptr_port = '\0'; 
	
	do 
	{ 
		*--ptr_port = repo[kady%base_port]; 
		kady /= base_port; 
	}while(kady != 0); 
	
	port_string_org(PORT_INFO,ptr_port); 
}

static void port_string_org(uint16 PORTER,String port_printer)
{
    while(*port_printer!='\0')
        {
            write_serial(PORTER,*port_printer);
            port_printer++;
        }
}
#endif
