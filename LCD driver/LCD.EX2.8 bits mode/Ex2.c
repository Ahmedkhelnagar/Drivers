/*
 * Ex2.c
 *
 *  Created on: Feb 17, 2021
 *      Author: dell
 */

#include"LCD.h"

int main(void)
{
	LCD_init(); /* initialize LCD */
	LCD_displayStringRowColumn(0,2,"My LCD Driver");
	LCD_displayStringRowColumn(1,3,"Embedded WS");
	_delay_ms(4000); /* wait four seconds */

	LCD_clearScreen(); /* clear the LCD display */
	LCD_displayString("Interf. Course ");
	LCD_displayStringRowColumn(1,5,"Group ");
	LCD_intgerToString(53);

    while(1)
    {
		/* Note: we write the code before while(1) because we want to execute it only once */
    }

}
