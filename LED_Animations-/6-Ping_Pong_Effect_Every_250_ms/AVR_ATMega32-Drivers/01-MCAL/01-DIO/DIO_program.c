/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   DIO_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdelrahman Adwe Ali 
 *  Layer  : MCAL
 *  SWC    : GPIO/DIO
 *
 */

#include "..\..\AVR_ATMega32-Drivers\03-LIB\BIT_MATH.h"
#include "..\..\AVR_ATMega32-Drivers\03-LIB\STD_TYPES.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*------------------------------------------------------------------------------------------------------------------------------------------------------
 *         	                                  this function set the direction of the Pin (INPUT or OUTPUt)
 *                                            *--------------------------------------------------------------*
 * Parameters :
         -> Copy_u8Port      : Port name     [DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD]
         -> Copy_u8Pin       : Pin number    [DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6,DIO_PIN7]
         -> Copy_u8Directoin : Pin Direction [DIO_PIN_OUTPUT , DIO_PIN_INPUT]

 * return DIO_Status :
 *      -> DIO_OK  --> if the set is done.
 *      -> DIO_NOK --> if the set isn't done.
 */
DIO_Status DIO_enumSetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Directoin)
{

	DIO_Status LOC_enumStatus = DIO_OK;

	if( (Copy_u8Port <= DIO_PORTD) && (Copy_u8Pin <= DIO_PIN7) )
	{
		if(Copy_u8Directoin == DIO_PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
				case DIO_PORTA : SET_BIT(DDRA,Copy_u8Pin); break;
				case DIO_PORTB : SET_BIT(DDRB,Copy_u8Pin); break;
				case DIO_PORTC : SET_BIT(DDRC,Copy_u8Pin); break;
				case DIO_PORTD : SET_BIT(DDRD,Copy_u8Pin); break;
			}   
		}
		else if(Copy_u8Directoin == DIO_PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
				case DIO_PORTA : CLR_BIT(DDRA,Copy_u8Pin); break;
				case DIO_PORTB : CLR_BIT(DDRB,Copy_u8Pin); break;
				case DIO_PORTC : CLR_BIT(DDRC,Copy_u8Pin); break;
				case DIO_PORTD : CLR_BIT(DDRD,Copy_u8Pin); break;
			}   
		}
		else
		{
			LOC_enumStatus = DIO_NOK;
		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;

}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------
 *         	                                     this function set the value of the Pin (HIGH or LOW)
 *                                               *------------------------------------------------------*
 * Parameters :
          -> Copy_u8Port  : Port name   [DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD]
          -> Copy_u8Pin   : Pin number  [DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6,DIO_PIN7]
          -> Copy_u8Value : Pin Value   [DIO_PIN_HIGH , DIO_PIN_LOW]

 * return DIO_Status :
 *      -> DIO_OK  --> if the set is done.
 *      -> DIO_NOK --> if the set isn't done.
 */
DIO_Status DIO_enumSetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{

	DIO_Status LOC_enumStatus = DIO_OK;

	if( (Copy_u8Port <= DIO_PORTD) && (Copy_u8Pin <= DIO_PIN7) )
	{
		if(Copy_u8Value == DIO_PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
				case DIO_PORTA : SET_BIT(PORTA,Copy_u8Pin); break;
				case DIO_PORTB : SET_BIT(PORTB,Copy_u8Pin); break;
				case DIO_PORTC : SET_BIT(PORTC,Copy_u8Pin); break;
				case DIO_PORTD : SET_BIT(PORTD,Copy_u8Pin); break;
			}   
		}
		else if(Copy_u8Value == DIO_PIN_LOW)
		{
			switch(Copy_u8Port)
			{
				case DIO_PORTA : CLR_BIT(PORTA,Copy_u8Pin); break;
				case DIO_PORTB : CLR_BIT(PORTB,Copy_u8Pin); break;
				case DIO_PORTC : CLR_BIT(PORTC,Copy_u8Pin); break;
				case DIO_PORTD : CLR_BIT(PORTD,Copy_u8Pin); break;
			}   
		}
		else
		{
			LOC_enumStatus = DIO_NOK;
		}
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;

}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
 *         	                                          this function get the value of the Pin (HIGH or LOW)
 *                                                   *-------------------------------------------------------*
 * Parameters :
         -> Copy_u8Port  : Port name        [DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD]
         -> Copy_u8Pin   : Pin number       [DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6,DIO_PIN7]
         -> Copy_PtrVar  : Pointer to Pin Value.   

 * return DIO_Status :
 *      -> DIO_OK  --> if the get is done.
 *      -> DIO_NOK --> if the get isn't done.
 */
DIO_Status DIO_enumGetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 * Copy_PtrVar)
{

	DIO_Status LOC_enumStatus = DIO_OK;

	if( (Copy_u8Port <= DIO_PORTD) && (Copy_u8Pin <= DIO_PIN7) )
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA : * Copy_PtrVar = GET_BIT(PINA,Copy_u8Pin); break;
			case DIO_PORTB : * Copy_PtrVar = GET_BIT(PINB,Copy_u8Pin); break;
			case DIO_PORTC : * Copy_PtrVar = GET_BIT(PINC,Copy_u8Pin); break;
			case DIO_PORTD : * Copy_PtrVar = GET_BIT(PIND,Copy_u8Pin); break;
		}   

	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;

}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------
 *         	                                    This function toggle the value of the Pin
 *                                             *---------------------------------------------*
 * Parameters :
         -> Copy_u8Port  : Port name   [DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD]
         -> Copy_u8Pin   : Pin number  [DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6,DIO_PIN7]  

 * return DIO_Status :
 *      -> DIO_OK  --> if the toggle is done.
 *      -> DIO_NOK --> if the toggle isn't done.
 */
DIO_Status DIO_enumTogglePinValue (u8 Copy_u8Port , u8 Copy_u8Pin)
{

	DIO_Status LOC_enumStatus = DIO_OK;

	if( (Copy_u8Port<=DIO_PORTD) && (Copy_u8Pin<=DIO_PIN7) )
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA : TOG_BIT(PORTA,Copy_u8Pin); break;
			case DIO_PORTB : TOG_BIT(PORTB,Copy_u8Pin); break;
			case DIO_PORTC : TOG_BIT(PORTC,Copy_u8Pin); break;
			case DIO_PORTD : TOG_BIT(PORTD,Copy_u8Pin); break;
		}

	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;

}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
 *         	                             this function set the direction of the Port (INPUT or OUTPUt)
 *                                       *---------------------------------------------------------------*
 * Parameters :
         -> Copy_u8Port      : Port name     [DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD]
         -> Copy_u8Directoin : Pin Direction [DIO_PORT_OUTPUT , DIO_PORT_INPUT]

 * return DIO_Status :
 *      -> DIO_OK  --> if the set is done.
 *      -> DIO_NOK --> if the set isn't done.
 */
DIO_Status DIO_enumSetPortDirection (u8 Copy_u8Port , u8 Copy_u8Directoin)
{

	DIO_Status LOC_enumStatus = DIO_OK;

	if( (Copy_u8Port <= DIO_PORTD) )
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA : DDRA = Copy_u8Directoin; break;
			case DIO_PORTB : DDRB = Copy_u8Directoin; break;
			case DIO_PORTC : DDRC = Copy_u8Directoin; break;
			case DIO_PORTD : DDRD = Copy_u8Directoin; break;
		}   
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;

}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
 *         	                                 this function set the value of the Port (HIGH or LOW)
 *                                            *------------------------------------------------------*
 * Parameters :
          -> Copy_u8Port  : Port name   [DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD]
          -> Copy_u8Value : Port Value  [DIO_PORT_HIGH , DIO_PORT_LOW]

 * return DIO_Status :
 *      -> DIO_OK  --> if the set is done.
 *      -> DIO_NOK --> if the set isn't done.
 */
DIO_Status DIO_enumSetPortValue (u8 Copy_u8Port , u8 Copy_u8Value)
{

	DIO_Status LOC_enumStatus = DIO_OK;

	if( (Copy_u8Port <= DIO_PORTD) )
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA : DDRA = Copy_u8Value; break;
			case DIO_PORTB : DDRB = Copy_u8Value; break;
			case DIO_PORTC : DDRC = Copy_u8Value; break;
			case DIO_PORTD : DDRD = Copy_u8Value; break;
		} 
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus;

}

/*-------------------------------------------------------------------------------------------------------------------------------------------------
 *         	                                    this function get the value of the Port
 *                                             *-------------------------------------------*
 * Parameters :
         -> Copy_u8Port  : Port name    [DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD]
         -> Copy_PtrVar  : Pointer to Port Value.   

 * return DIO_Status :
 *      -> DIO_OK  --> if the get is done.
 *      -> DIO_NOK --> if the get isn't done.
 */
DIO_Status DIO_enumGetPortValue (u8 Copy_u8Port , u8 * Copy_PtrVar)
{

	DIO_Status LOC_enumStatus = DIO_OK;

	if( (Copy_u8Port <= DIO_PORTD) )
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA : * Copy_PtrVar = PINA; break;
			case DIO_PORTB : * Copy_PtrVar = PINB; break;
			case DIO_PORTC : * Copy_PtrVar = PINC; break;
			case DIO_PORTD : * Copy_PtrVar = PIND; break;
		} 
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}
	return LOC_enumStatus; 

}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------
 *         	                                     This function toggle the value of the Port
 *                                               *---------------------------------------------*
 * Parameters :
         -> Copy_u8Port  : Port name  [DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD]  

 * return DIO_Status :
 *      -> DIO_OK  --> if the toggle is done.
 *      -> DIO_NOK --> if the toggle isn't done.
 */
DIO_Status DIO_enumTogglePortValue (u8 Copy_u8Port)
{

	DIO_Status LOC_enumStatus = DIO_OK;

	if( (Copy_u8Port <= DIO_PORTD) )
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA : PORTA ^=0xFF; break;
			case DIO_PORTB : PORTB ^=0xFF; break;
			case DIO_PORTC : PORTC ^=0xFF; break;
			case DIO_PORTD : PORTD ^=0xFF; break;
		} 
	}
	else
	{
		LOC_enumStatus = DIO_NOK;
	}

	return LOC_enumStatus;

}
