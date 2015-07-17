/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        buttons.h
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

#ifndef _BUTTONS_H        /* To avoid double inclusion */
#define _BUTTONS_H

/* Includes */
#include "typedefs.h"

/*-- Defines -----------------------------------------------------------------*/

#define BTN_PRESSED                 0
#define BTN_NOT_PRESSED             1
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
void Evaluate_bounce_button(T_UBYTE button);

/* Functions macros */



/* Exported defines */


#endif /* _BUTTONS_H */

/*******************************************************************************/
