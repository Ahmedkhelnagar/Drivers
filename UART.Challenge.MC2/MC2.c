/*
 * MC2.c
 *
 *  Created on: Mar 28, 2021
 *      Author: dell
 */

#include"lcd.h"
#include"usart.h"

int main(void)
{
	 uint8 key_num;
	 UART_init();
	 LCD_init();

	 DDRC=0xFF;
	 PORTC=0x00;

	 while(1)
	 {
		 key_num=UART_recieveByte();

		 if( (key_num >= 0) &&(key_num <= 9))
		 {
			 LCD_intgerToString(key_num);

		 }
		 else
		 {
			 LCD_displayCharacter(key_num);
		 }

	 }

}
