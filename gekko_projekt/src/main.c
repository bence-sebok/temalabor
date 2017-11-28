// Gekk�hoz sz�ks�ges header f�jlok
#include "em_device.h"
#include "em_chip.h"
#include "InitDevice.h"
#include "em_usart.h"
#include "em_gpio.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_timer.h"
#include "segmentlcd.h"
// C std header f�jlok
#include <stdio.h>
#include <string.h>
// saj�t header f�jlok
#include "constants.h" // Konstansok a projektben.
#include "message.h" // �zenetkezel�shez tartoz� v�ltoz�k �s f�ggv�nyek.

extern uint8_t ch; // UART-on kapott karakter.
extern bool volatile new_char; // �rkezett-e �j karakter flag.

int main(void)
{
	Gekko_Init();

	while (1)
	{
		// �rkezett karakter echo-ja.
		if (new_char)
		{
			new_char = false;
			SegmentLCD_Number(ch);
			USART_Tx(UART0, ch); // Karakterenk�nti echo.
			if(ch == 'q')
			{
				string2USART("clear");
			}
		}
	}
}
