/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        button.h
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Mon Jun 22 2015
*=============================================================================*/
/* DESCRIPTION : Header of the button selector                                */
/*============================================================================*/
/* FUNCTION COMMENT : Header of the button.c file                             */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 22/06/2015  |                               | Gilberto Ochoa   */
/*                                                                            */
/*============================================================================*/

#ifndef _BUTTON_H        /* To avoid double inclusion */
#define _BUTTON_H

/* Includes */

/*-- Defines -----------------------------------------------------------------*/

#define ZERO_MILLISECONDS           0
#define TEN_MILLISECONDS            10


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */

enum ESTATUS
{
	IDLE,
	MANUAL_UP,
	MANUAL_DOWN,
	SELECTOR_UP,
	SELECTOR_DOWN,
	ANTIPINCH,
	DELAY_5_SECONDS
};

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
extern void Evaluate_bounce_button(void);

/* Functions macros */


/* Exported defines */


#endif /* _BUTTON_H */

/*******************************************************************************/
