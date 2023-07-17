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
#include "SW_interface.h"

void main()
{
	u8 i = 1 ;
	SW_Data SW1 = {SW_PORTA , SW_PIN0 ,  SW_EXT_PUll_DOWN};
	SSD_Data SSD1 = {SSD_COMMON_CATHODE , SSD_PORTC , SSD_PORTD , SSD_PIN0};

	SSD_voidInit (SSD1 );
	SSD_voidEnable (SSD1 );
	SW_voidInit (SW1 );

	SSD_voidSendNumber(SSD1 , 0) ;

	while(1)
	{

		if( SW_u8GetPressed(SW1) == SW_PRESSED )
		{
			SSD_voidSendNumber(SSD1 , i) ;
			i++ ;
			_delay_ms(40) ;
		}

		if(i == 10)
		{
			i = 0 ;
		}
	}

}
