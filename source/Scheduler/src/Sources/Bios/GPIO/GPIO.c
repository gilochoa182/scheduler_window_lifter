/*============================================================================*/
/*                        Continental Automotive                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %GPIO.c%
* Instance:         CES
* %version:         1 %
* %created_by:      Armando Villa %
* %date_created:    Wed Jul  15
*=============================================================================*/
/* DESCRIPTION : A GPIO Driver                                                */
/*============================================================================*/
/* FUNCTION COMMENT : A GPIO header designed to configurate the indiviual pin */
/*                    or the complete port.                                   */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 15/08/2015  |                               | Armando Villa    */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "GPIO.h"


/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */
#define INPUT_MODE 0x100
#define OUTPUT_MODE 0x200

/*==================================================*/
/* Definition of constants                          */
/*==================================================*/
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/
/* Definition of RAM variables                          */
/*======================================================*/
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/
/* close variable declaration sections                  */
/*======================================================*/

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	GPIO_SetPin
 *  Description          :	A GPIO Individual Pin Driver
 *  Parameters           :  [Input]
 *  Return               :	[Void]
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void GPIO_SetPin(T_UBYTE lub_port, T_UBYTE lub_pin, T_UBYTE lub_mode){
	if (lub_mode == INPUT){
		switch(lub_port){
			case PORTA:
				SIU.PCR[startA + lub_pin].R = INPUT_MODE;
				break;

			case PORTB:
				SIU.PCR[startB + lub_pin].R = INPUT_MODE;
				break;

			case PORTC:
				SIU.PCR[startC + lub_pin].R = INPUT_MODE;
				break;

			case PORTD:
				SIU.PCR[startD + lub_pin].R = INPUT_MODE;
				break;

			case PORTE:
				SIU.PCR[startE + lub_pin].R = INPUT_MODE;
				break;

			case PORTF:
				SIU.PCR[startF + lub_pin].R = INPUT_MODE;
				break;

			case PORTG:
				SIU.PCR[startG + lub_pin].R = INPUT_MODE;
				break;

			case PORTH:
				SIU.PCR[startH + lub_pin].R = INPUT_MODE;
				break;

			case PORTI:
				SIU.PCR[startA + lub_pin].R = INPUT_MODE;
				break;

			default:
				/* Do nothing */
				break;
		}
	}

	else if(lub_mode == OUTPUT){
		switch(lub_port){
			case PORTA:
				SIU.PCR[startA + lub_pin].R = OUTPUT_MODE;
				break;

			case PORTB:
				SIU.PCR[startB + lub_pin].R = OUTPUT_MODE;
				break;

			case PORTC:
				SIU.PCR[startC + lub_pin].R = OUTPUT_MODE;
				break;

			case PORTD:
				SIU.PCR[startD + lub_pin].R = OUTPUT_MODE;
				break;

			case PORTE:
				SIU.PCR[startE + lub_pin].R = OUTPUT_MODE;
				break;

			case PORTF:
				SIU.PCR[startF + lub_pin].R = OUTPUT_MODE;
				break;

			case PORTG:
				SIU.PCR[startG + lub_pin].R = OUTPUT_MODE;
				break;

			case PORTH:
				SIU.PCR[startH + lub_pin].R = OUTPUT_MODE;
				break;

			case PORTI:
				SIU.PCR[startA + lub_pin].R = OUTPUT_MODE;
				break;

			default:
				/* Do nothing */
				break;
		}
	}

	else{
		/* Do nothing */
	}
}

/**************************************************************
 *  Name                 :	GPIO_SetPort
 *  Description          :	A GPIO Port Driver Configurator
 *  Parameters           :  [Input]
 *  Return               :	[Void]
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void GPIO_SetPort(T_UBYTE lub_port, T_UBYTE lub_mode){
	T_UBYTE lub_gpio_counter;

	if(lub_mode == INPUT){
		for(lub_gpio_counter = lub_port; lub_gpio_counter <= (lub_port+COMPLETE_PORT); lub_gpio_counter++){
			SIU.PCR[lub_gpio_counter].R = INPUT_MODE;
		}
	}

	else if(lub_mode == OUTPUT){
		for(lub_gpio_counter = lub_port; lub_gpio_counter <= (lub_port+COMPLETE_PORT); lub_gpio_counter++){
			SIU.PCR[lub_gpio_counter].R = OUTPUT_MODE;
		}
	}

	else{
		/* Do nothing */
	}

}
