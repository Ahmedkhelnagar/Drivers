 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Ahmed khaled
 *
 *******************************************************************************/

#include "LCD.h"

/********************************************************************************
 *                      Fuunctions Definitions                                  *
 *******************************************************************************/

/*function at the beginnig of LCD*/
void LCD_init(void)
{
	LCD_DATA_PORT_DIR=0xFF; /*configure the data as output pins*/
	LCD_CTRL_PORT_DIR=(1<<RS)|(1<<RW)|(1<<E); /*configure the control pins as output pins*/

	LCD_sendcommand(TWO_LINE_LCD_Eight_BIT_MODE); /*Selection the mode*/

	LCD_sendcommand(CURSOR_OFF); /*cursor off*/

	LCD_sendcommand(CLEAR_COMMAND); /*At the beginning clear LCD*/

}


/*function to recevie my commands that i want*/
void LCD_sendcommand(uint8 command)
{
   CLEAR_BIT(LCD_CTRL_PORT,RS); /*RS=0*/
   CLEAR_BIT(LCD_CTRL_PORT,RW); /*RW=0*/
   _delay_ms(1); /*Delay for processing Tas=50ns*/

   SET_BIT(LCD_CTRL_PORT,E);  /*Enable=1*/
   _delay_ms(1); /*Delay for processing Tpw - Tdsw =190ns*/

   LCD_DATA_PORT=command; /* out the required command to the data bus D0 --> D7 */
   _delay_ms(1); /* Delay for processing Tdsw=100ns*/

   CLEAR_BIT(LCD_CTRL_PORT,E); /*Enable=0*/
   _delay_ms(1); /*Delay for processing Th=13ns*/
}


/*Display data that I send it*/
void LCD_displaycharacter(uint8 data)
{
	SET_BIT(LCD_CTRL_PORT,RS); /*RS=1*/
	CLEAR_BIT(LCD_CTRL_PORT,RW); /*RW=0*/
	_delay_ms(1); /*Delay for processing Tas=50ns*/

	SET_BIT(LCD_CTRL_PORT,E);  /*Enable=1*/
	_delay_ms(1); /*Delay for processing Tpw - Tdsw =190ns*/

	LCD_DATA_PORT=data;/* out the required data to the data bus D0 --> D7 */
	_delay_ms(1); /* Delay for processing Tdsw=100ns*/

	CLEAR_BIT(LCD_CTRL_PORT,E); /*Enable=0*/
	_delay_ms(1); /*Delay for processing Th=13ns*/
}


/*Display string*/
void LCD_displayString(const char *Str)
{
  while( (*Str) !='\0')
  {
	  LCD_displaycharacter(*Str);
	  Str++;
  }
  /***************************Another method************************************
   * uint8 i-0;
     while(Str[i]!='\0')
     {
    	 LCD_displaycharacter(Str[i]);
    	 i++;
     }
   ******************************************************************************/
}


/*selection where I write exactly on the screen of LCD*/
void LCD_goToRowColumn(uint8 row,uint8 col)
{
   uint8 address;

   /* first of all calculate the required address */
   switch(row)
   {
      case 0: address=col;
              break;
      case 1: address=(col+0x40);
              break;
      case 2: address=(col+0x10);
              break;
      case 3: address=(col+0x50);
              break;
   }
   /* to write to a specific address in the LCD
   	 * we need to apply the corresponding command 0b10000000+Address */
   LCD_sendcommand(address | SET_CURSOR_LOCATION);

}


/*Display specific string at specific row and col*/
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row,col); /*Go to the required LCD position*/
	LCD_displayString(Str); /*Display this string*/
}


/*Display integer on LCD */
void LCD_intgerToString(int data)
{
	char Buff[16]; /*string to hold to ASCII result*/
	itoa(data,Buff,10); /* 10 for decimal*/
	LCD_displayString(Buff);
}


void LCD_clearScreen(void)
{
	LCD_sendcommand(CLEAR_COMMAND); //clear display
}
