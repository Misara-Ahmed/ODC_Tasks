/*
 * app.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Misara
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Dio.h"
#include "bit_math.h"
#include "Lcd.h"

int main()
{
	uint16_t temperature;
	LCD_Init();

	// Enable SREG
	// SET_BIT(SREG,7);

	// Select channel 0
	ADMUX |= 0<<0;

	// Handle Reference
	SET_BIT(ADMUX,6);

	// Select Prescaler
	ADCSRA |= 7<<0;

	// Enable interrupt
	// SET_BIT(ADCSRA,3);

	// Enable ADC
	SET_BIT(ADCSRA,7);

	LCD_SendStr("Temperature=");

	while(1)
	{
		// Start Conversion
		SET_BIT(ADCSRA,6);

		while( GET_BIT(ADCSRA,4) )
		{
			// Read the temperature
			temperature = ADCL;
			temperature |= ADCH << 7;

			// Change from F to C
			temperature *= 4.88;
			temperature /= 10;

			// Show the temperature on the LCD
			LCD_GoTo(12,0);
			LCD_SendNumber(temperature/10);
			LCD_SendNumber(temperature%10);
			LCD_SendStr("C");

			// CLear flag
			SET_BIT(ADCSRA,4);
		}
	}
}
