#include "adc.h"
#include "lcd.h"

int main(void)
{
	uint32 temp;
	uint32 res_value;
	SREG |= (1<<7);/* Enable Global Interrupts */

	LCD_init(); /* initialize LCD driver */
	ADC_init(); /* initialize ADC driver */
	LCD_clearScreen(); /* clear LCD at the beginning */
	/* display this string "Temp =    " only once at LCD */
	LCD_displayString("Temp = ");
	LCD_goToRowColumn(0,10);
	/* display character 'C' on the screen "Temp =   C" */
	LCD_displayCharacter('C');
    while(1)
    {
		LCD_goToRowColumn(0,7); /* display the number every time at this position */
//		ADC_readChannel(2); /* read channel two where the temp sensor is connect */
//		temp = ((uint32)g_adcResult*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/

		res_value=ADC_readChannel(2);
		res_value= (res_value*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/

		LCD_intgerToString(res_value); /* display the temp on LCD screen */
    }
}
