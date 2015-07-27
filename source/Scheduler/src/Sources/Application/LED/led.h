/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         led.h
* version:          1
* created_by:       Gilberto Ochoa
* %date_created:    Jul  22 2015 
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 22/07/2015  |                               | Gilberto Ochoa   */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef LED_H                               /* To avoid double inclusion */
#define LED_H

/* Includes */
/* -------- */

#include "GPIO.h"

/*-- Defines -----------------------------------------------------------------*/

#define LED1       68
#define LED2       69
#define LED3       70
#define LED4       71

#define _LED1      0
#define _LED2      1
#define _LED3      2
#define _LED4      3
#define _LED5      4
#define _LED6      5
#define _LED7      6
#define _LED8      7
#define _LED9      8
#define _LED10     9
#define _LED_UP    10
#define _LED_DOWN    11

/****Embedded GPIO's****/


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
extern void LED_ON(T_UBYTE channel);
extern void LED_OFF(T_UBYTE channel);
extern void LED_TOGGLE(T_UBYTE channel);

/* Functions macros */


/* Exported defines */


#endif


