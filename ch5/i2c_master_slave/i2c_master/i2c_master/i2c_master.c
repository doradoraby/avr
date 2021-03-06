/*
 * i2c_master.c
 *
 * Created: 2016-04-17 오후 5:43:18
 * Author : sela
 */ 

#include <stdio.h>
#include <avr/io.h>
#include "uart.h"
#include "i2c.h"
#include "cmd.h"
#include "e2p_24c32.h"

#define AVR_SLAVE_ADDR	0x10

int main(void)
{
	uart_init();
	i2c_init(100);
	
	printf("ATmega328P monitor\n");
	cmd_loop();
}

int write_avr(uint8_t addr, uint8_t *data, int len)
{
	if(i2c_write_bytes(AVR_SLAVE_ADDR, addr, data, len) < 0)
		return -1;
	else
		return 0;
}

int read_avr(uint8_t addr, uint8_t *data, int len)
{
	if(i2c_read_bytes(AVR_SLAVE_ADDR, addr, data, len) < 0)
		return -1;
	else
		return 0;
}


int write_e2p16(uint16_t addr, uint8_t *data, int len)
{
	if(i2c_write16a_bytes(E2P_ADDR, addr, data, len) < 0)
		return -1;
	else
		return 0;
}

int read_e2p16(uint16_t addr, uint8_t *data, int len)
{
	if(i2c_read16a_bytes(E2P_ADDR, addr, data, len) < 0)
		return -1;
	else
		return 0;
}

