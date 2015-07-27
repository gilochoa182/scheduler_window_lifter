/*============================================================================*/
/*                        Continental Automotive                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %GPIO_Types.h%
* Instance:         CES
* %version:         1 %
* %created_by:      Armando Villa %
* %date_created:    Wed Jul  15
*=============================================================================*/
/* DESCRIPTION : A GPIO Types configuration                                   */
/*============================================================================*/
/* FUNCTION COMMENT : A GPIO data types configuration oriented to a GPIO      */
/*                    GPIO driver.        .                                   */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 15/08/2015  |                               | Armando Villa    */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef _GPIO_TYPES_H                            /* To avoid double inclusion */
#define _GPIO_TYPES_H

/* Includes */
/* -------- */
#include "typedefs.h"


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

enum PORTS{
	PORTA = 0,
	PORTB = 16,
	PORTC = 32,
	PORTD = 48,
	PORTE = 64,
	PORTF = 80,
	PORTG = 86,
	PORTH = 122,
	PORTI = 138
};

enum MODE{
	INPUT,
	OUTPUT
};

/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */


/* Functions macros */


/* Exported defines */


#endif


