/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        window_lifter.h
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Mon Jul 13 2015
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
/*  1.0      | 13/07/2015  |                               | Gilberto Ochoa   */
/*                                                                            */
/*============================================================================*/

#ifndef _WINDOW_LIFTER_H        /*prevent duplicated includes*/
#define _WINDOW_LIFTER_H

/* Includes */

#include "typedefs.h"

/*-- Defines -----------------------------------------------------------------*/



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
typedef struct
{
	T_UWORD ruw_Counter;
	T_UWORD ruw_TopCount;
	tCallbackFunction   cpfu_PerFunct; 
} TASKSTRUCT;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
void Test(void);
void dummy_500us(void);
void dummy_endless_loop(void);

void Task_5ms(void);    /*Period = 5ms*/
void Task_10ms(void);   /*Period = 10ms*/
void Task_50ms(void);   /*Period = 50ms*/
void Task_100ms(void);  /*Period = 100ms*/

/* Functions macros */


/* Exported defines */


#endif /* _WINDOW_LIFTER_H */

/*******************************************************************************/
