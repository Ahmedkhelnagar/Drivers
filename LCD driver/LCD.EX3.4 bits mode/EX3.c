/*
 * EX3.c
 *
 *  Created on: Feb 17, 2021
 *      Author: dell
 */


#include "LCD.h"

int main(void)
{
	LCD_init(); /* initialize LCD */
	LCD_displayString("Welcome To LCD");
	LCD_displayStringRowColumn(1,0,"4 Bits Data Mode");

    while(1)
    {
		/* Note: we write the code before while(1) because we want to execute it only once */
    }

}

