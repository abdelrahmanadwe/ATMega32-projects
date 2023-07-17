/*
 * main.c
 *
 *  Created on: Feb 11, 2023
 *      Author: AbdAlrahman
 */

#define F_CPU 8000000UL

#include <Util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "LED_interface.h"
#include "SW_interface.h"

void main()
{
	LED_voidInit (LED_PORTA , LED_PIN0 );

	SW_Data SW1 = {SW_PORTA , SW_PIN1 , SW_EXT_PUll_DOWN };
	SW_voidInit(SW1);

	while(1)
	{

		if(SW_u8GetPressed(SW1)== SW_PRESSED)
		{
			LED_voidOn (LED_PORTA , LED_PIN0 , ACTIVE_HIGH);
		}
		else if(SW_u8GetPressed(SW1) == SW_NOT_PRESSED)
		{
			LED_voidOff (LED_PORTA , LED_PIN0 , ACTIVE_HIGH);
		}

	}

}


