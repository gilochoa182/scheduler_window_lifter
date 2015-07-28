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

#include "GPIO.h"

/* define */

#define _BUTTON1 64
#define _BUTTON2 65
#define _BUTTON3 66
#define _BUTTON4 67

#define BUTTON_UP        SIU.GPDI[_BUTTON1].B.PDI
#define BUTTON_DOWN      SIU.GPDI[_BUTTON2].B.PDI
#define BUTTON3          SIU.GPDI[_BUTTON3].B.PDI
#define ANTI_PINCH       SIU.GPDI[_BUTTON4].B.PDI

#define BTN_ACTIVE                  1
#define BTN_INACTIVE                0

#define ZERO_MILLISECONDS           0
#define TEN_MILLISECONDS            8


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

typedef enum
{
	BUTTON_DOWN_UNPRESS,
	BUTTON_UP_UNPRESS,
	BUTTON_DOWN_PRESS,
	BUTTON_UP_PRESS,
	SIGNAL_ANTIPINCH
}ButtonStateType;

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
extern void Evaluate_bounce_button(void);

/* Functions macros */


/* Exported defines */


#endif /* _BUTTON_H */

/*******************************************************************************/
