/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ADC_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdelrahman Adwe Ali 
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */

#include "..\..\03-LIB\BIT_MATH.h"
#include "..\..\03-LIB\STD_TYPES.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_voidInit  ( void )
{
	
		/*Select the voltage reference*/
	#ifdef ADC_VREF
	
		ADMUX &= 0x3f;
		ADMUX |= (ADC_VREF<<6);
		
	#endif
	
		/*Set Left Adjust Result*/
	#ifdef ADC_ADJUSTMENT
	
		#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
		
			CLR_BIT(ADMUX,ADMUX_ADLAR);
			
		#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
		
			SET_BIT(ADMUX,ADMUX_ADLAR);
			
		#else
			
			#error "Wrong ADC_ADJUSTMENT config"
			
		#endif
		
	#endif
	
		/*Set Prescaler Value*/
	#ifdef ADC_PRESCALLER
	
		ADCSRA &= 0xf9;
		ADCSRA |= ADC_PRESCALLER;
		
	#endif
	
		/*Set Trigger Source Value*/
	#ifdef ADC_TRIGGERING_SOURCE
	
		#if ADC_TRIGGERING_SOURCE <= ADC_SINGLE_CONVERSION
		
			#if ADC_TRIGGERING_SOURCE ==  ADC_SINGLE_CONVERSION
			
				CLR_BIT(ADCSRA,ADCSRA_ADATE);
				
			#else 
				
				SET_BIT(ADCSRA,ADCSRA_ADATE);
				SFIOR &= 0x1f;
				SFIOR |= (ADC_TRIGGERING_SOURCE<<5);
			
			#endif
			
		#else 
			
			#error "Wrong ADC_TRIGGERING_SOURCE config"
		
		#endif
		
	#endif
	
		/*Enable ADC Peripheral*/
	#ifdef ADC_STATUS
	
		#if ADC_STATUS == ADC_ENABLE

				SET_BIT(ADCSRA , ADCSRA_ADEN) ;

		#elif ADC_STATUS == ADC_DISABLE
		
			CLR_BIT(ADCSRA , ADCSRA_ADEN) ;

		#else
			
			#error "Wrong ADC_STATUS config"
		
		#endif 
		
	#endif
	
		/*Enable ADC Interrupt*/
	#ifdef ADC_INT_STATUS
	
		#if ADC_INT_STATUS == INT_DISABLE
		
			CLR_BIT(ADCSRA , ADCSRA_ADIE) ;
			
		#elif ADC_INT_STATUS == INT_ENABLE
		
			SET_BIT(ADCSRA , ADCSRA_ADIE) ;
			
		#else
			
			#error "Wrong INT_STATUS config"
		
		#endif 

	#endif
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void ADC_voidEnable (void)
{
	
	SET_BIT(ADCSRA , ADCSRA_ADEN) ;
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void ADC_voidDisable (void)
{
	
	CLR_BIT(ADCSRA , ADCSRA_ADEN) ;
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void ADC_voidInterruptEnable (void)
{
	
	SET_BIT(ADCSRA , ADCSRA_ADIE) ;
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void ADC_voidInterruptDisable (void)
{
	
	CLR_BIT(ADCSRA , ADCSRA_ADIE) ;
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

u8 ADC_u8SetPrescaler (u8 Copy_u8Prescaler)
{
	
	u8 Local_u8ErrorState = 0 ;

	if (Copy_u8Prescaler < 8)
	{
		/*Set Prescaler Value*/
		ADCSRA &= 0xf9;
		ADCSRA |= Copy_u8Prescaler;
		Local_u8ErrorState = 1 ;
	
	}

	return Local_u8ErrorState ;
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
u8 ADC_u8GetResult (u8 Copy_u8Channel , u16 * Copy_pu16Result)
{
	u8 Local_u8ErrorState = 1 ;
	u32 Local_u32TimeoutCounter = 0 ;

	if (Copy_pu16Result != NULL)
	{

		/*Set required channel*/
		ADMUX &= 0xE0 ;
		ADMUX |= Copy_u8Channel ;

		/*Start Conversion*/
		SET_BIT(ADCSRA , ADCSRA_ADSC) ;

		/*Waiting until the conversion is complete*/
		while (!(GET_BIT(ADCSRA , ADCSRA_ADIF)));

      	/*Clear the interrupt flag*/
			SET_BIT(ADCSRA , ADCSRA_ADIF) ;

			/*Return Conversion Result*/
			#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
			
				*Copy_pu16Result = (ADCL|(ADCH << 8)) ;

			#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
			
				*Copy_pu16Result = (ADCH<<2) ;
				
			#else
				
				#error "Wrong ADC_ADJUSTMENT config"

			#endif
	}

	else
	{
		Local_u8ErrorState = 0 ;
	}

	return Local_u8ErrorState ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
