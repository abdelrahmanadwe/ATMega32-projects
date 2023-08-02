/*
 * main.c
 *
 *  Created on: Feb 21, 2023
 *  Author: AbdAlrahman
 */

#define F_CPU 8000000UL
#include <Util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "SW_interface.h"

void main()
{

	SW_Data SW1 = {SW_PORTC , SW_PIN0 , SW_INT_PUll_UP};
	SW_Data SW2 = {SW_PORTC , SW_PIN1 , SW_INT_PUll_UP};
    SW_Data SW3 = {SW_PORTC , SW_PIN2 , SW_INT_PUll_UP};
	SW_Data SW4 = {SW_PORTC , SW_PIN3 , SW_INT_PUll_UP};
    SW_Data SW5 = {SW_PORTC , SW_PIN4 , SW_INT_PUll_UP};
	SW_Data SW6 = {SW_PORTC , SW_PIN5 , SW_INT_PUll_UP};
    SW_Data SW7 = {SW_PORTC , SW_PIN6 , SW_INT_PUll_UP};
	SW_Data SW8 = {SW_PORTC , SW_PIN7 , SW_INT_PUll_UP};


	SW_voidInit ( SW1 );
	SW_voidInit ( SW2 );
	SW_voidInit ( SW3 );
	SW_voidInit ( SW4 );
	SW_voidInit ( SW5 );
	SW_voidInit ( SW6 );
	SW_voidInit ( SW7 );
	SW_voidInit ( SW8 );


	LED_voidPortInit (LED_PORTA);

	while(1)
	{
		if(SW_u8GetPressed(SW1) == SW_PRESSED)
		{
			LED_voidFlashPort  (LED_PORTA , 1);
		}
		if(SW_u8GetPressed(SW2) == SW_PRESSED)
		{
			LED_voidShiftLeft  ( LED_PORTA , ACTIVE_HIGH , 250/1000.0 );
		}
		if(SW_u8GetPressed(SW3) == SW_PRESSED)
		{
			LED_voidShiftRight ( LED_PORTA , ACTIVE_HIGH , 250/1000.0 );
		}
		if(SW_u8GetPressed(SW4) == SW_PRESSED)
		{
			LED_voidConverge ( LED_PORTA , ACTIVE_HIGH , 250/1000.0 );
		}
		if(SW_u8GetPressed(SW5) == SW_PRESSED)
		{
			LED_voidDiverge ( LED_PORTA , ACTIVE_HIGH , 250/1000.0 );
		}
		if(SW_u8GetPressed(SW6) == SW_PRESSED)
		{
			LED_voidPingPong ( LED_PORTA , ACTIVE_HIGH , 250/1000.0 );
		}
		if(SW_u8GetPressed(SW7) == SW_PRESSED)
		{
			 LED_voidSnakeEffect ( LED_PORTA , ACTIVE_HIGH , 250/1000.0 );
		}
		if(SW_u8GetPressed(SW8) == SW_PRESSED )
		{
			LED_voidConverge_Diverge ( LED_PORTA , ACTIVE_HIGH , 250/1000.0 );
		}

	}

}
