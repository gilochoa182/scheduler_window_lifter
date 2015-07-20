/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        buttons.c         
* version:         1.2
* created_by:      Gilberto Ochoa
* date_created:    Mon Jun 22 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file works with the buttons selection              */
/* Evaluate the rebound in the buttons                                        */
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
/*  1.2      | 10/07/2015  |                               | Gilberto Ochoa   */
/* Optimize memory                                                            */
/*============================================================================*/


/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */

/** Own headers */
#include "buttons.h"


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
 *  Name                 :	Evaluate_bounce_button
 *  Created by           :  Gilberto Ochoa
 *  Description          :  Evaluate if the button is pressed for more than 10 milliseconds
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  NO
 **************************************************************/
void Evaluate_bounce_button(T_UBYTE button)
{
	static T_UBYTE lub_time_button=0;
	
	if(button == BTN_PRESSED) 
	{	
		lub_time_button++;                       /*Increases time to 10 milliseconds*/
		if(lub_time_button>=TEN_MILLISECONDS)
		{
			lub_time_button=ZERO_MILLISECONDS;    /* Reset time*/               
		}
		
		else
		{
			//Do nothing
		}
	}
			
	else
	{
		lub_time_button=ZERO_MILLISECONDS;       /* Reset time*/
	}
}    /* End Evaluate_bounce_button*/