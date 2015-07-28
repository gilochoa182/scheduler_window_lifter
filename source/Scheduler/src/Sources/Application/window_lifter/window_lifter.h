/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        window_lifter.h
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Mon Jun 22 2015
*=============================================================================*/
/* DESCRIPTION : Header of the control window lifter                          */
/*============================================================================*/
/* FUNCTION COMMENT : Header of the window_lifter.c file                      */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 22/06/2015  |                               | Gilberto Ochoa   */
/*                                                                            */
/*============================================================================*/

#ifndef _WINDOW_LIFTER_H        /*prevent duplicated includes*/
#define _WINDOW_LIFTER_H

/* Includes */

#include "typedefs.h"

/*-- Defines -----------------------------------------------------------------*/

#define TOTALLY_CLOSED              255
#define TOTALLY_OPEN                10
#define FIVE_SECONDS                125

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

typedef enum
{
	IDLE,
	VALIDATION,
	MANUAL_UP,
	MANUAL_DOWN,
	AUTOMATIC_UP,
	AUTOMATIC_DOWN,
	ANTIPINCH,
	LOCK
}StateMachineType;

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
extern void State_Machine(void);
extern void delay_5_seconds(void);
extern T_UBYTE Get_LEDPosition(void);
extern void Set_LEDPosition(T_UBYTE option);
extern T_UBYTE Get_rub_State(void);
extern void Set_rub_State(StateMachineType option);

/* Functions macros */


/* Exported defines */


#endif /* _WINDOW_LIFTER_H */

/*******************************************************************************/
