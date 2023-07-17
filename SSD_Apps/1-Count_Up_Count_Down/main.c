/*
 * main.c
 *
 *  Created on: Feb 12, 2023
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

	SSD_Data SSD1 = { SSD_COMMON_CATHODE , SSD_PORTC , SSD_PORTD , SSD_PIN0};
	SSD_voidInit (SSD1 );
	SSD_voidEnable (SSD1 );

	while (1)
	{
		for(u8 i=0 ; i<=9 ; i++)
		{
			_delay_ms(1000);
			SSD_voidSendNumber (SSD1 , i );

		}

		for(s8 i=9 ; i>=0 ; --i)
		{
			_delay_ms(1000);
			SSD_voidSendNumber (SSD1 , i );
		}

	}

}

