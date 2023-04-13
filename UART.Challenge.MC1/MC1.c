/*
 * MC1.c
 *
 *  Created on: Mar 28, 2021
 *      Author: dell
 */

#include"keypad.h"
#include"usart.h"

int main(void)
{
	uint8 key_num;
	UART_init();

	while(1)
	{
		key_num=KeyPad_getPressedKey(); //Get the pressed key
		UART_sendByte(key_num);         //Send the pressed key to the second micro using UART
		_delay_ms(500);

	}
}
