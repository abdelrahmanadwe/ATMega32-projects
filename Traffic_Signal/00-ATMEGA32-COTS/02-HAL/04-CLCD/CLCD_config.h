/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     CLCD_config.h     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdelrahman Adwe Ali 
 *  Layer  : HAL
 *  SWC    : CLCD
 *
 */
 
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_
  
/*

 Optoins :-
	1- 4
	2- 8
	
*/
#define CLCD_MODE 8
 
/*

 Optoins :-
	1-DIO_PORTA
	2-DIO_PORTB
	3-DIO_PORTC
	4-DIO_PORTD
	
*/

         /* D0:D7 */
#define CLCD_DATA_PORT    DIO_PORTA
         /* RS,RW,EN */
#define CLCD_CONTROL_PORT DIO_PORTC

 
/*

 Optoins :-
	1-DIO_PIN0
	2-DIO_PIN1
	3-DIO_PIN2
	4-DIO_PIN3
	5-DIO_PIN4
	6-DIO_PIN5
	7-DIO_PIN6
	8-DIO_PIN7
	
*/  

#define CLCD_RS DIO_PIN0
#define CLCD_RW DIO_PIN1
#define CLCD_EN DIO_PIN2
 
#endif /* CLCD_CONFIG_H_ */