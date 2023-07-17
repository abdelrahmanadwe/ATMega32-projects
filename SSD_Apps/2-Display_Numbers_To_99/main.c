/*
 * main.c
 *
 *  Created on: Feb 13, 2023
 *  Author: AbdAlrahman
 */

#define F_CPU 8000000UL
#include <Util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "SSD_interface.h"

void main()
{
	SSD_Data SSD2 = { SSD_COMMON_CATHODE , SSD_PORTA , SSD_PORTD , SSD_PIN1};
	SSD_Data SSD1 = { SSD_COMMON_CATHODE , SSD_PORTC , SSD_PORTD , SSD_PIN0};

	SSD_voidInit (SSD1 );
	SSD_voidEnable (SSD1 );

	SSD_voidInit (SSD2 );
	SSD_voidEnable (SSD2 );

	while (1)
	{

		for(u8 i = 0 ; i<=99 ; i++)
		{
			SSD_voidSendNumber (SSD2 , i/10 );
			SSD_voidSendNumber (SSD1 , i%10 );
			_delay_ms(1000);

		}

	}

}

