#include <stdbool.h> // bool, true, false
#include "em_usart.h"
#include "em_timer.h"
#include "message.h" // �zenetkezel�shez tartoz� v�ltoz�k �s f�ggv�nyek.
#include "constants.h" // END_CHAR
#include "segmentlcd.h"
#include <stdlib.h>
#include "initDevice.h" // LED-ekhez
#include "em_gpio.h"

uint8_t ch; // UART-on kapott karakter.
bool volatile new_char = false; // �rkezett-e �j karakter flag.

void string2USART(char * string)
{
	int i;
	for(i = 0; string[i] != '\0'; i++)
	{
			USART_Tx(UART0, string[i]);
	}
}

void UART0_RX_IRQHandler(void)
{
	ch = USART_RxDataGet(UART0);
	GPIO_PinOutToggle(LED0_PORT, LED0_PIN);
	GPIO_PinOutToggle(LED1_PORT, LED1_PIN);
	new_char = true;
	//USART_IntClear(UART0, USART_IF_RXDATAV);
}
