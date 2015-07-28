/*============================================================================*/
/*                        Continental Automotive                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %GPIO.h%
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

#ifndef GPIO_H                               /* To avoid double inclusion */
#define GPIO_H

/* Includes */
/* -------- */
#include "MPC5606B.h"
#include "GPIO_Types.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */
#define startA 0
#define startB 16
#define startC 32
#define startD 48
#define startE 64
#define startF 80
#define startG 96
#define startH 122
#define startI 138

#define endA 15
#define endB 31
#define endC 47
#define endD 63
#define endE 79
#define endF 95
#define endG 121
#define endH 137
#define endI 140	

#define COMPLETE_PORT 15

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
extern void GPIO_SetPin(T_UBYTE lub_port, T_UBYTE lub_pin, T_UBYTE lub_mode);

extern void GPIO_SetPort(T_UBYTE lub_port, T_UBYTE lub_mode);


/* Functions macros */

#define HIGH(channel)       (SIU.GPDO[channel].B.PDO =  1) 

#define LOW(channel)        (SIU.GPDO[channel].B.PDO =  0)

#define TOGGLE(channel)     (SIU.GPDO[channel].B.PDO ^= 1)


/* Exported defines */


#endif


