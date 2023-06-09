 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Ahmed khaled
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_


#include"std_types.h"
#include"common_macros.h"
#include"micro_config.h"

/**********************************************************************************
 *                        Preprocessor Macros                                     *
 **********************************************************************************/
/*LCD HW Pins*/

#define RS PD4
#define RW PD5
#define E  PD6

#define LCD_CTRL_PORT PORTD
#define LCD_CTRL_PORT_DIR DDRD

#define LCD_DATA_PORT PORTC
#define LCD_DATA_PORT_DIR DDRC

/*LCD COMMANDS*/
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80


/*********************************************************************************
 *                       Function prototypes                                     *
 *********************************************************************************/

void LCD_sendcommand(uint8 command);
void LCD_displaycharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_intgerToString(int data);

#endif /* LCD_H_ */
