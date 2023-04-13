/*
 * UART.h
 *
 *  Created on: Mar 30, 2021
 *      Author: dell
 */

#ifndef UART_H_
#define UART_H_

#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"

/********************************************************************************
 *                       preprocessor Macros
 ********************************************************************************/

/*UART DRIVER BUAD RATE*/
#define USART_BAUDRATE 9600

/*********************************************************************************
 *                       Function prototype
 *********************************************************************************/

void UART_init(void);

void UART_sendByte(const uint8 data);

uint8 UART_recieveByte(void);

void UART_sendString(const uint8 *str);

void UART_receiveString(uint8 *str); //receive until #


#endif /* UART_H_ */
