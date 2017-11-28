// Gekkóhoz szükséges header fájlok
#include "em_device.h"
#include "em_chip.h"
#include "InitDevice.h"
#include "em_usart.h"
#include "em_gpio.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_timer.h"
#include "segmentlcd.h"
// C std header fájlok
#include <stdio.h>
#include <string.h>
// saját header fájlok
#include "constants.h" // Konstansok a projektben.
#include "message.h" // Üzenetkezeléshez tartozó változók és függvények.

extern uint8_t ch; // UART-on kapott karakter.
extern bool volatile new_char; // Érkezett-e új karakter flag.

int main(void)
{
	Gekko_Init();

	while (1)
	{
		// Érkezett karakter echo-ja.
		if (new_char)
		{
			new_char = false;
			SegmentLCD_Number(ch);
			USART_Tx(UART0, ch); // Karakterenkénti echo.
			if(ch == 'q')
			{
				string2USART("clear");
			}
		}
	}
}
