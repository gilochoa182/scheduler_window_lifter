/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         led.c
* version:          1
* created_by:       Gilberto Ochoa
* %date_created:    Jul  22 2015 
*=============================================================================*/
/* DESCRIPTION :                                                              */
/*============================================================================*/
/* FUNCTION COMMENT :                                                         */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 22/07/2015  |                               | Gilberto Ochoa   */
/*                                                                            */
/*============================================================================*/

/* Includes */
/* -------- */

#include "led.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

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
 *  Name                 :	LED_ON
 *  Description          :
 *  Parameters           :  T_UBYTE channel
 *  Return               :  Void
 *  Critical/explanation :  No
 **************************************************************/
void LED_ON(T_UBYTE channel)
{
	LOW(channel);
}


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	LED_OFF
 *  Description          :
 *  Parameters           :  T_UBYTE channel
 *  Return               :  Void
 *  Critical/explanation :  No
 **************************************************************/
void LED_OFF(T_UBYTE channel)
{
	HIGH(channel);
}


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	LED_TOGGLE
 *  Description          :
 *  Parameters           :  T_UBYTE channel
 *  Return               :  Void
 *  Critical/explanation :  No
 **************************************************************/
void LED_TOGGLE(T_UBYTE channel)
{
	TOGGLE(channel);
}