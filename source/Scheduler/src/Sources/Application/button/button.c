/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        button,c         
* version:         1.2
* created_by:      Gilberto Ochoa
* date_created:    Mon Jun 22 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file works with the buttons selection              */
/* Button Up & Button Down, Evaluate the rebound in the button                */
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

#include "button.h"

/*-- Defines -----------------------------------------------------------------*/


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

ButtonStateType status_button=BUTTON_DOWN_UNPRESS;

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
void Evaluate_bounce_button(void)
{
	static T_UBYTE lub_time_button = ZERO_MILLISECONDS;
	
	if((BUTTON_DOWN == BTN_ACTIVE) && (BUTTON_UP == BTN_INACTIVE))
	{	
		lub_time_button++;                       /*Increases time to 10 milliseconds*/
		if(lub_time_button >= TEN_MILLISECONDS)
		{
			lub_time_button = ZERO_MILLISECONDS;    /* Reset time*/
			status_button = BUTTON_DOWN_PRESS;               
		}
		
		else
		{
			//Do nothing
		}
	}
			
			
	else if((BUTTON_UP == BTN_ACTIVE) && (BUTTON_DOWN == BTN_INACTIVE) )
	{		
		lub_time_button++;	             /*Increases time to 10 milliseconds*/
		if(lub_time_button >= TEN_MILLISECONDS)
		{
			lub_time_button = ZERO_MILLISECONDS;    /* Reset time*/
			status_button = BUTTON_UP_PRESS;
		}
		
		else
		{
			//Do nothing
		}
	}
	
	
	else if(ANTI_PINCH == BTN_ACTIVE)
	{		
		lub_time_button++;	             /*Increases time to 10 milliseconds*/
		if(lub_time_button >= TEN_MILLISECONDS)
		{
			lub_time_button = ZERO_MILLISECONDS;    /* Reset time*/
			status_button = SIGNAL_ANTIPINCH;
		}
		
		else
		{
			//Do nothing
		}
	}
			
	else
	{
		lub_time_button = ZERO_MILLISECONDS;       /* Reset time*/
		status_button = BUTTON_DOWN_UNPRESS;
	}
}    /* End Evaluate_bounce_button*/



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	Get_Status_button
 *  Created by           :  Gilberto Ochoa
 *  Description          :  
 *  Parameters           :  void
 *  Return               :  T_UBYTE status_button
 *  Critical/explanation :  NO
 **************************************************************/
T_UBYTE Get_Status_button(void)
{
	return status_button;
}