/*
 * main.c
 *
 *  Created on: Jul 21, 2023
 *  Author: AbdAlrahman
 */

#include<Util\delay.h>

#include"00-ATMEGA32-COTS\03-LIB\BIT_MATH.h"
#include"00-ATMEGA32-COTS\03-LIB\STD_TYPES.h"


#include"00-ATMEGA32-COTS\01-MCAL\01-DIO\DIO_interface.h"
#include"00-ATMEGA32-COTS\01-MCAL\02-EXTI\EXTI_interface.h"

#include"00-ATMEGA32-COTS\02-HAL\01-LED\LED_interface.h"
#include"00-ATMEGA32-COTS\02-HAL\02-SSD\SSD_interface.h"

#define SREG *((volatile u8 *)0x5F)

LED_Type LED_Green  ={LED_PORTB,LED_PIN0,ACTIVE_HIGH};
LED_Type LED_Yellow ={LED_PORTB,LED_PIN1,ACTIVE_HIGH};
LED_Type LED_Red    ={LED_PORTB,LED_PIN2,ACTIVE_HIGH};

SSD_Data SSD_Counter ={SSD_COMMON_CATHODE,SSD_PORTA,SSD_PORTD,SSD_PIN0};

enum Mode{Normal_Mode,Pedestrian_Mode}mode;


void Init_App      (void);
void ISR_SW_Pressed(void);
void Pedestrian_func(void);
void Normal_func   (void);
void Start_App     (void);
void leds_off      (void);

void main()
{

	Init_App ();
	while(1)
	{
		Start_App();
	}

}

void Init_App()
{
	/* open the GIE */
	SET_BIT(SREG,7);

	/*init the leds */
	LED_voidInit        ( LED_Green  );
	LED_voidInit        ( LED_Yellow );
	LED_voidInit        ( LED_Red    );

	/*init the External interrupt */
	EXTI_voidInit();
    EXTI_voidEnableInterrupt(                  EXTI_LINE0 );
    EXTI_voidSetCallBack    ( ISR_SW_Pressed , EXTI_LINE0 );

    /*init the 7segment */
    SSD_voidInit   (SSD_Counter );
    SSD_voidEnable (SSD_Counter );

    mode = Normal_Mode;
}


void Pedestrian_func()
{

	u8 Status_Red , Status_Green;
	DIO_enumGetPinValue     (LED_Green.Port , LED_Green.Pin , & Status_Green );
	DIO_enumGetPinValue     (LED_Red.Port   , LED_Red.Pin   , & Status_Red   );
	if( Status_Red )
	{
		leds_off();
		LED_voidOn ( LED_Red );
		for(u8 i =1; i<=9; i++)
		{

			SSD_voidSendNumber (SSD_Counter , i );
			_delay_ms(1000);

		}
		LED_voidOff ( LED_Red );

		for(u8 i =1; i<=3; i++)
		{
			LED_voidToggle     ( LED_Yellow );
			SSD_voidSendNumber (SSD_Counter , i );
			_delay_ms(1000);

		}
		LED_voidOff ( LED_Yellow );
		LED_voidOn ( LED_Red );
	}
	else if( Status_Green )
	{
		leds_off();
		for(u8 i =1; i<=3; i++)
		{
			LED_voidToggle     ( LED_Yellow );
			SSD_voidSendNumber (SSD_Counter , i );
			_delay_ms(1000);

		}
		LED_voidOff ( LED_Yellow );

		LED_voidOn ( LED_Red );
		for(u8 i =1; i<=9; i++)
		{

			SSD_voidSendNumber (SSD_Counter , i );
			_delay_ms(1000);

		}
		LED_voidOff ( LED_Red );

		for(u8 i =1; i<=3; i++)
		{
			LED_voidToggle     ( LED_Yellow );
			SSD_voidSendNumber (SSD_Counter , i );
			_delay_ms(1000);

		}
		LED_voidOff ( LED_Yellow );
		LED_voidOn ( LED_Green );
	}
	else
	{

		leds_off();
		for(u8 i =1; i<=3; i++)
		{
			LED_voidToggle     ( LED_Yellow );
			SSD_voidSendNumber (SSD_Counter , i );
			_delay_ms(1000);

		}
		LED_voidOff ( LED_Yellow );

		LED_voidOn ( LED_Red );
		for(u8 i =1; i<=9; i++)
		{

			SSD_voidSendNumber (SSD_Counter , i );
			_delay_ms(1000);

		}
		LED_voidOff ( LED_Red );
		for(u8 i =1; i<=3; i++)
		{
			LED_voidToggle     ( LED_Yellow );
			SSD_voidSendNumber (SSD_Counter , i );
			_delay_ms(1000);

		}
		LED_voidOff ( LED_Yellow );

	}
	mode = Normal_Mode;

}

void Normal_func()
{

	LED_voidOn ( LED_Green );
	for(u8 i =1; i<=9; i++)
	{

		SSD_voidSendNumber (SSD_Counter , i );
		_delay_ms(1000);

	}
	LED_voidOff ( LED_Green );

	for(u8 i =1; i<=3; i++)
	{
		LED_voidToggle     ( LED_Yellow );
		SSD_voidSendNumber (SSD_Counter , i );
		_delay_ms(1000);

	}
	LED_voidOff ( LED_Yellow );

	LED_voidOn ( LED_Red );
	for(u8 i =1; i<=9; i++)
	{

		SSD_voidSendNumber (SSD_Counter , i );
		_delay_ms(1000);

	}
	LED_voidOff ( LED_Red );

	for(u8 i =1; i<=3; i++)
	{
		LED_voidToggle     ( LED_Yellow );
		SSD_voidSendNumber (SSD_Counter , i );
		_delay_ms(1000);

	}
	LED_voidOff ( LED_Yellow );

}

void ISR_SW_Pressed()
{

	mode = Pedestrian_Mode;
	Start_App();

}

void Start_App()
{

	if(mode == Pedestrian_Mode)
	{

		Pedestrian_func();

	}
	else if(mode == Normal_Mode)
	{

		Normal_func();

	}

}

void leds_off()
{

	LED_voidOff ( LED_Green );
	LED_voidOff ( LED_Yellow );
	LED_voidOff ( LED_Red );
}
