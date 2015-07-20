/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         window_lifter.c
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Mon Jun 22 2015
*=============================================================================*/
/* DESCRIPTION : This file contains the window control                        */
/*============================================================================*/
/* FUNCTION COMMENT :                                                         */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 22/06/2015  |                               | Gilberto Ochoa   */
/*============================================================================*/
/*  1.1      | 02/07/2015  | It is renamed one state of    | Gilberto Ochoa   */
/*           |             | the State Machine             |                  */
/*============================================================================*/
/*  1.2      | 03/07/2015  | Elimination some function and | Gilberto Ochoa   */
/*           |             | become in Macros              |                  */
/*============================================================================*/

/* Includes */
/* -------- */

/** Own headers */
#include "window_lifter.h"

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
T_UBYTE rub_State=IDLE, rub_LED_Position=_LED1;

/* WORD RAM variables */
T_UWORD ruw_time_button=ZERO_MILLISECONDS, ruw_time_transition=ZERO_MILLISECONDS;

/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */
void window_up(void);
void window_down(void);
void manual_up(void);
void manual_down(void);
void Selector_up(void);
void Selector_down(void);
void aintipinch(void);
void delay_5_seconds(void);


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	State_Machine
 *  Created by           :  Gilberto Ochoa
 *  Description          :  Control of the State Machine
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  NO
 **************************************************************/
void State_Machine(void)
{
	switch(rub_State)
	{
		case IDLE:
			Evaluate_bounce_button();     /* Function available in file (button.c) */
			break;
			
		
		case MANUAL_UP:
			manual_up();
			break;
			
			
		case MANUAL_DOWN:
			manual_down();
			break;
			
			
		case SELECTOR_UP:
			Selector_up();
			break;
			
			
		case SELECTOR_DOWN:
			Selector_down();
			break;
			
			
		case ANTIPINCH:	
			aintipinch();
			break;
			
		case DELAY_5_SECONDS:
			delay_5_seconds();
			break;
	}  /* End switch */
	
}        /* End State_Machine */



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : window_down
 *  Created by           : Gilberto Ochoa
 *  Description          : This function controls the movement down of the window
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void window_down(void)
{
	if(BUTTON_UP == BTN_ACTIVE)
	{
		LED_OFF(_LED_DOWN);
		rub_State=MANUAL_DOWN;
		ruw_time_button=ZERO_MILLISECONDS;
	}    /* End Evaliation Button Stop */
	
	else
	{
		ruw_time_transition++;
		if((ruw_time_transition==FOUR_HUNDRED_MILLISECONDS) && (rub_LED_Position<=_LED10))
		{
			LED_ON(_LED_DOWN);
			LED_OFF(rub_LED_Position);
			rub_LED_Position++;
			ruw_time_transition=ZERO_MILLISECONDS;
		}
		
		else
		{
			//Do nothing
		}
			
		if(rub_LED_Position==OPEN)
		{
			rub_State=IDLE;
			rub_LED_Position=_LED10;
			ruw_time_button=ZERO_MILLISECONDS;
			LED_OFF(_LED_DOWN);
		}
		
		else
		{
			//Do nothing
		}
	}   /* End ELSE Evaliation Button Stop */	
	
}  /*************** End function window_down ***************/



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : window_up
 *  Created by           : Gilberto Ochoa
 *  Description          : This function controls the movement UP of the window
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void window_up(void)
{	
	if(ANTI_PINCH==BTN_ACTIVE)
	{
		ruw_time_button=ZERO_MILLISECONDS;
		rub_State=ANTIPINCH;	
	} /* End Evaluation Anti Pinch*/
	
	else
	{	
		if(BUTTON_DOWN == BTN_ACTIVE)
		{
			LED_OFF(_LED_UP);
			rub_State=MANUAL_UP;
			ruw_time_button=ZERO_MILLISECONDS;
		}    /* End Evaliation Button Stop */
	
		else
		{
			ruw_time_transition++;
			if((ruw_time_transition==FOUR_HUNDRED_MILLISECONDS) && (rub_LED_Position>=_LED1))
			{
				LED_ON(_LED_UP);
				LED_ON(rub_LED_Position);
				rub_LED_Position--;
				ruw_time_transition=ZERO_MILLISECONDS;
			}
			
			else
			{
				//Do nothing
			}
			
			if(rub_LED_Position==CLOSED)
			{
				rub_State=IDLE;
				rub_LED_Position=_LED1;
				ruw_time_button=ZERO_MILLISECONDS;
				LED_OFF(_LED_UP);
			}	
			
			else
			{
				//Do nothing
			}
		}
	}
	
}  /*************** End function window_up ***************/



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : manual_up
 *  Created by           : Gilberto Ochoa
 *  Description          : Evaluate if the BUTTON_UP is pressed to continue UP
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void manual_up(void)
{
	if((BUTTON_UP == BTN_ACTIVE) || (BUTTON_DOWN == BTN_ACTIVE))
	{
		window_up();
	}
			
	else
	{
		ruw_time_button=ZERO_MILLISECONDS;
		rub_State=IDLE;	
		LED_OFF(_LED_UP);	
	}	
}   /*************** End function manual_up ***************/



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : manual_down
 *  Created by           : Gilberto Ochoa
 *  Description          : Evaluate if the BUTTON_DOWN is pressed to continue DOWN
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void manual_down(void)
{
	if((BUTTON_DOWN == BTN_ACTIVE) || (BUTTON_UP == BTN_ACTIVE))
	{
		window_down();
	}
			
	else
	{
		ruw_time_button=ZERO_MILLISECONDS;
		rub_State=IDLE;	
		LED_OFF(_LED_DOWN);	
	}
}    /*************** End function manual_down ***************/



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : Selector_up
 *  Created by           : Gilberto Ochoa
 *  Description          : Evaluate the time that the button was pressed to select (Manual or Automatic)
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void Selector_up(void)
{
	if(BUTTON_UP == BTN_ACTIVE)
	{
		ruw_time_button++;
		if((ruw_time_button>FIVE_HUNDRED_MILLISECONDS) && (BUTTON_UP == BTN_ACTIVE))
		{
			rub_State=MANUAL_UP;
		}
		
		else
		{
			//Do nothing
		}
	}
	
	else
	{
		window_up();	
	}
			
}   /*************** End function automatic_up_action ***************/



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : Selector_down
 *  Created by           : Gilberto Ochoa
 *  Description          : Evaluate the time that the button was pressed to select (Manual or Automatic)
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void Selector_down(void)
{
	if(BUTTON_DOWN == BTN_ACTIVE)
	{
		ruw_time_button++;
		if((ruw_time_button>FIVE_HUNDRED_MILLISECONDS) && (BUTTON_DOWN == BTN_ACTIVE))
		{
			rub_State=MANUAL_DOWN;
		}
		
		else
		{
			//Do nothing
		}
	}
	
	else
	{
		window_down();	
	}
}  /*************** End function automatic_down_action ***************/



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : aintipinch
 *  Created by           : Gilberto Ochoa
 *  Description          : Detected if the signal is present to open the window
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void aintipinch(void)
{
	ruw_time_button++;	       
	if(ruw_time_button>=TEN_MILLISECONDS)
	{
		ruw_time_transition++;
		if((ruw_time_transition==FOUR_HUNDRED_MILLISECONDS) && (rub_LED_Position<=_LED10))
		{
			LED_OFF(_LED_UP);
			LED_ON(_LED_DOWN);
			LED_OFF(rub_LED_Position);
			rub_LED_Position++;
			ruw_time_transition=ZERO_MILLISECONDS;
		}
			
		if(rub_LED_Position==OPEN)
		{
			rub_LED_Position=_LED10;
			ruw_time_button=ZERO_MILLISECONDS;
			LED_OFF(_LED_DOWN);
			rub_State=DELAY_5_SECONDS;
		}
	}
}   /*************** End function antipinch ***************/



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : delay_5_seconds
 *  Created by           : Gilberto Ochoa
 *  Description          : Generates a delay for 5 seconds to inactive the buttons
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void delay_5_seconds(void)
{
	static T_UWORD luw_time_delay;
	luw_time_delay++;
	if(luw_time_delay==FIVE_SECONDS)
	{
		luw_time_delay=ZERO_MILLISECONDS;
		rub_State=IDLE;
	}
}   /**************** End function delay_5_seconds ***************/
