/*
 * main.c
 *
 *  Created on: Jul 23, 2023
 *      Author: AbdAlrahman
 */


#include<Util\delay.h>

#include"00-ATMEGA32-COTS\03-LIB\BIT_MATH.h"
#include"00-ATMEGA32-COTS\03-LIB\STD_TYPES.h"


#include"00-ATMEGA32-COTS\01-MCAL\01-DIO\DIO_interface.h"
#include"00-ATMEGA32-COTS\01-MCAL\02-EXTI\EXTI_interface.h"

#include"00-ATMEGA32-COTS\02-HAL\01-LED\LED_interface.h"
#include"00-ATMEGA32-COTS\02-HAL\02-SSD\SSD_interface.h"

#define SREG *((volatile u8*)0x5f)


LED_Type LED_Red  ={LED_PORTA,LED_PIN0,ACTIVE_HIGH};
LED_Type LED_Green ={LED_PORTA,LED_PIN1,ACTIVE_HIGH};
LED_Type LED_Blue   ={LED_PORTA,LED_PIN2,ACTIVE_HIGH};

void Init_App (void);
void ISR0     (void);
void ISR1     (void);
void ISR2     (void);

void main()
{

	Init_App ();
	while(1);
}

void Init_App      (void)
{

	/*init the leds */
	LED_voidInit        ( LED_Green  );
	LED_voidInit        ( LED_Blue   );
	LED_voidInit        ( LED_Red    );

	DIO_voidConnectIntPullup      (LED_PORTD , LED_PIN2       );
	DIO_voidConnectIntPullup      (LED_PORTD , LED_PIN3       );
    DIO_voidConnectIntPullup      (LED_PORTB , LED_PIN2       );

	/*init the External interrupt 0 */
	EXTI_voidInit();
    EXTI_voidEnableInterrupt( EXTI_LINE0        );
    EXTI_voidSetCallBack    ( ISR0 , EXTI_LINE0 );

    /*init the External interrupt 1 */
    EXTI_voidSetSignalLatch ( EXTI_LINE1 , EXTI_LOW_LEVEL );
    EXTI_voidEnableInterrupt( EXTI_LINE1                  );
    EXTI_voidSetCallBack    ( ISR1 , EXTI_LINE1           );

    /*init the External interrupt 2 */
    EXTI_voidSetSignalLatch ( EXTI_LINE2 , EXTI_FALLING_EDGE );
    EXTI_voidEnableInterrupt( EXTI_LINE2                  );
    EXTI_voidSetCallBack    ( ISR2 , EXTI_LINE2           );
	
	/* open the GIE */
	SET_BIT(SREG,7);

}

void ISR0()
{

	LED_voidOn ( LED_Red  );
	_delay_ms(500);
	LED_voidOff ( LED_Red );

}

void ISR1()
{

	LED_voidOn ( LED_Green  );
	_delay_ms(500);
	LED_voidOff ( LED_Green );

}

void ISR2()
{

	LED_voidOn ( LED_Blue  );
	_delay_ms(500);
	LED_voidOff ( LED_Blue );

}
