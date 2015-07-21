/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        GPIO.h
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Mon Jun 22 2015
*=============================================================================*/
/* DESCRIPTION : Macro definitions for registers access and I/O handling      */
/*============================================================================*/
/* FUNCTION COMMENT : Header of the GPIO.c file                               */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 22/06/2015  |                               | Gilberto Ochoa   */
/*                                                                            */
/*============================================================================*/

#ifndef _GPIO_H        /*prevent duplicated includes*/
#define _GPIO_H

/* Includes */

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"


/*-- Defines -----------------------------------------------------------------*/

#define on 0
#define off 1

/****Embedded GPIO's****/

#define _LED1      0
#define _LED2      1
#define _LED3      2
#define _LED4      3
#define _LED5      4
#define _LED6      5
#define _LED7      6
#define _LED8      7
#define _LED9      8
#define _LED10      9 
#define _LED_UP    10
#define _LED_DOWN  11




/** Set LED */ 
#define LED_ON(channel)                     (SIU.GPDO[channel].B.PDO =  on)
/** Clear LED */ 
#define LED_OFF(channel)                    (SIU.GPDO[channel].B.PDO =  off)
/** Toggle LED */ 
#define LED_TOGGLE(channel)                 (SIU.GPDO[channel].B.PDO ^= off) 

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
extern void EmbIOs_Config(void);

/* Functions macros */


/* Exported defines */


#endif /* _GPIO_H */

/*******************************************************************************/
