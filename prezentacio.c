while (1)
	{
		// Ha karakter érkezett az UART0-án:
		if (new_char)
		{
			new_char = false;
			SegmentLCD_Number(ch); // Minden karakter kijelzése az LCD-n.
			USART_Tx(UART0, ch);   // Karakterenkénti echo az UART0-n.
			// ************************************ VEZÉRLÉS  ***********************************
			// A 5-ös (STOP) billentyű hatására minden vezetékre logikai alacsony szintet teszünk
			if(ch == '5')
			{
				GPIO_PinOutClear(MOTOR_IN1_PORT, MOTOR_IN1_PIN); // IN1 = 0
				GPIO_PinOutClear(MOTOR_IN2_PORT, MOTOR_IN2_PIN); // IN2 = 0
				GPIO_PinOutClear(MOTOR_IN3_PORT, MOTOR_IN3_PIN); // IN3 = 0
				GPIO_PinOutClear(MOTOR_EN1_PORT, MOTOR_EN1_PIN); // EN1 = 0
				GPIO_PinOutClear(MOTOR_EN2_PORT, MOTOR_EN2_PIN); // EN2 = 0
				GPIO_PinOutClear(MOTOR_EN3_PORT, MOTOR_EN3_PIN); // EN3 = 0
			}
			// Az X vagy Y tengely kiválasztása a vezetékek átkötésével történik
			// A 4-es billentyű hatására balra hátrafelé mozog a tükör
			// 8-as billentyű hatására felfelé hátrafelé mozog a tükör
			if(ch == '4' || ch == '8')
			{
				GPIO_PinOutSet(MOTOR_EN1_PORT, MOTOR_EN1_PIN);   // EN1 = 1
				GPIO_PinOutSet(MOTOR_EN2_PORT, MOTOR_EN2_PIN);   // EN2 = 1
				GPIO_PinOutSet(MOTOR_IN1_PORT, MOTOR_IN1_PIN);   // IN1 = 1
				GPIO_PinOutClear(MOTOR_IN2_PORT, MOTOR_IN2_PIN); // IN2 = 0
			}
			// Az X vagy Y tengely kiválasztása a vezetékek átkötésével történik
			// A 6-os billentyű hatására jobbra hátrafelé mozog a tükör
			// 2-es billentyű hatására lefelé hátrafelé mozog a tükör
			if(ch == '6' || ch == '2')
			{
				GPIO_PinOutSet(MOTOR_EN1_PORT, MOTOR_EN1_PIN);     // EN1 = 1
				GPIO_PinOutSet(MOTOR_EN2_PORT, MOTOR_EN2_PIN);     // EN2 = 1
				GPIO_PinOutClear(MOTOR_IN1_PORT, MOTOR_IN1_PIN);   // IN1 = 0
				GPIO_PinOutSet(MOTOR_IN2_PORT, MOTOR_IN2_PIN);     // IN2 = 1
			}
		}
	}
