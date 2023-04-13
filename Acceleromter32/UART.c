/*
 * UART.c
 *
 *  Created on: Mar 30, 2021
 *      Author: dell
 */


#include"UART.h"

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)

void UART_init(void)
{
	UCSRnA = (1<<U2Xn);
	
}
