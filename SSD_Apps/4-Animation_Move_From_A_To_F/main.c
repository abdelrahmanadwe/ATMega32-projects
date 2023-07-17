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


void SSD_voidMoveLed(SSD_Data SSD_Config);

void main()
{
	SSD_Data SSD1 = { SSD_COMMON_CATHODE , SSD_PORTC };
	SSD_voidInit (SSD1 );

	while (1)
	{

		SSD_voidMoveLed(SSD1);

	}

}

void SSD_voidMoveLed(SSD_Data SSD_Config)
{
	for(u8 i = 0 ; i<6 ; i++)
	{
		DIO_enumSetPortValue (SSD_Config.Port , 1<<i );
		_delay_ms(100);
	}

}
