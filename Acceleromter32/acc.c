#include "adc.h"
#include "usart.h"

int main(void)
{

//	uint32 Str[20];
	uint32 x,y,z;

	UART_init();
	ADC_init(); /* initialize ADC driver */

    while(1)
    {

		x=ADC_readChannel(0);
		UART_sendByte(x);
		_delay_ms(1);

		y=ADC_readChannel(1);
		UART_sendByte(y);
		_delay_ms(1);

		z=ADC_readChannel(2);
		UART_sendByte(z);
		_delay_ms(1000);
    }
}








//		data = UART_recieveByte();

//		UART_receiveString(Str); //Receive String from Terminal
//	    UART_sendString(Str); //Resend the string to Terminal2



