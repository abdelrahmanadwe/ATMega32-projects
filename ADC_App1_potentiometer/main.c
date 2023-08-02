/*
 * main.c
 *
 *  Created on: Jul 25, 2023
 *      Author: AbdAlrahman
 */

#include<Util\delay.h>

#include"00-ATMEGA32-COTS\03-LIB\BIT_MATH.h"
#include"00-ATMEGA32-COTS\03-LIB\STD_TYPES.h"

#include"00-ATMEGA32-COTS\01-MCAL\01-DIO\DIO_interface.h"
#include"00-ATMEGA32-COTS\01-MCAL\04-ADC\ADC_interface.h"

#include"00-ATMEGA32-COTS\02-HAL\04-CLCD\CLCD_interface.h"


#define STEP (5.0/1024)

void Init_App();
void main()
{

	Init_App();
	u16 digital ;

	while(1)
	{

		ADC_u8GetResult  (ADC_CHANNEL0 , & digital);

		CLCD_voidSetPosition (CLCD_ROW_1 , CLCD_COL_11 );
		CLCD_voidSendNumber  ( digital*STEP );

	}

}


void Init_App()
{

	 CLCD_voidInit();
	 ADC_voidInit ();
	 CLCD_voidSendString  ( "Voltage = " );

	 CLCD_voidSetPosition   (CLCD_ROW_1 , CLCD_COL_12 );
	 CLCD_voidSendString  ( " V"    );

}
