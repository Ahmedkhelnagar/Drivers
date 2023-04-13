/******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Ahmed khaled
 *
 *******************************************************************************/

#ifndef USART_H_
#define USART_H_

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

#endif /* USART_H_ */
