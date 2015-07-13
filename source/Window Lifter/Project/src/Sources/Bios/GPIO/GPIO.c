/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        GPIO,c         
* version:         1.1
* created_by:      Gilberto Ochoa
* date_created:    Mon Jun 22 2015
*=============================================================================*/
/* DESCRIPTION :                                                              */
/*============================================================================*/
/* FUNCTION COMMENT : This file configurated GPIO as output and input         */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 22/06/2015  |                               | Gilberto Ochoa   */
/* Start of this file                                                         */
/*============================================================================*/
/*  1.1      | 30/06/2015  |                               | Gilberto Ochoa   */
/* Organization of Private functions prototypes                               */
/*============================================================================*/


/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */

/** MCU derivative information */
#include "MCU_derivative.h"
/** Own headers */
/* GPIO routines prototypes */ 
#include "GPIO.h"


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
 *  Name                 :	EmbIOs_Config
 *  Created by           :  Gilberto Ochoa
 *  Description          :  Configuration diferentes components Embedded
 *  Description          :  called periodically to operate.
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  NO
 **************************************************************/
void EmbIOs_Config(void)
{
	T_UBYTE lub_i;
  
    /* Set Port A as OUTPUT*/
  	for(lub_i=0;lub_i<12;lub_i++)
  	{
  		SIU.PCR[lub_i].R = 0x200;	
  	}
  	
  	SIU.GPDO[10].B.PDO = off;
  	SIU.GPDO[11].B.PDO = off;
  	
  	
  	/* Embedded board buttons seted as inputs */
  	SIU.PCR[_BUTTON1].R = 0x100;	
  	SIU.PCR[_BUTTON2].R = 0x100;
  	SIU.PCR[_BUTTON3].R = 0x100;
  	SIU.PCR[_BUTTON4].R = 0x100;	
}