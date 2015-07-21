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

/*-- Defines -----------------------------------------------------------------*/

#define ZERO_MILLISECONDS           0
#define TEN_MILLISECONDS            4
#define FIVE_HUNDRED_MILLISECONDS   200
#define FOUR_HUNDRED_MILLISECONDS   160
#define FIVE_SECONDS                2000
#define CLOSED                      255
#define OPEN                        10


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
extern void State_Machine(void);

/* Functions macros */


/* Exported defines */


#endif /* _WINDOW_LIFTER_H */

/*******************************************************************************/
