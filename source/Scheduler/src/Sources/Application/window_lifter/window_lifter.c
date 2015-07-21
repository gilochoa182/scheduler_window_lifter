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

#include "button.h"


/*-- Defines -----------------------------------------------------------------*/

#define ZERO_MILLISECONDS           0
#define FIVE_HUNDRED_MILLISECONDS   100
#define FOUR_HUNDRED_MILLISECONDS   80
#define FIVE_SECONDS                125
#define TOTALLY_CLOSED              255
#define TOTALLY_OPEN                10

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */

typedef enum
{
	IDLE,
	VALIDATION,
	MANUAL_UP,
	MANUAL_DOWN,
	AUTOMATIC_UP,
	AUTOMATIC_DOWN,
	ANTIPINCH,
	LOCK
}StateMachineType;

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

StateMachineType rub_State=IDLE;

T_UBYTE rub_LED_Position=_LED1;

extern ButtonStateType status_button;


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
void automatic_up(void);
void automatic_down(void);
void aintipinch(void);
void delay_5_seconds(void);
void validation(void);


/* Private functions */
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
			ruw_time_button=ZERO_MILLISECONDS;
			ruw_time_transition=ZERO_MILLISECONDS;
			rub_State=VALIDATION;
			break;
			
		case VALIDATION:
			validation();
			break;
			
			
		case MANUAL_UP:
			manual_up();
			break;
			
			
		case MANUAL_DOWN:
			manual_down();
			break;
			
			
		case AUTOMATIC_UP:
			automatic_up();
			break;
			
			
		case AUTOMATIC_DOWN:
			automatic_down();
			break;
			
			
		case ANTIPINCH:	
			aintipinch();
			break;
			
		case LOCK:
			
			break;
	}  /* End switch */
	
}        /* End State_Machine */


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : validation
 *  Created by           : Gilberto Ochoa
 *  Description          : 
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void validation(void)
{
	if(status_button==BUTTON_DOWN_PRESS)
	{
		rub_State=AUTOMATIC_DOWN;
	}
			
	else if(status_button==BUTTON_UP_PRESS)
	{
		rub_State=AUTOMATIC_UP;
	}
	
	else if((status_button==SIGNAL_ANTIPINCH)&&((rub_State==AUTOMATIC_UP)||(rub_State==MANUAL_UP)))
	{
		rub_State=ANTIPINCH;
	}
			
	else
	{
		rub_State=IDLE;
	}
}



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : automatic_up
 *  Created by           : Gilberto Ochoa
 *  Description          : Evaluate the time that the button was pressed to select (Manual or Automatic)
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void automatic_up(void)
{
	if(status_button==BUTTON_UP_PRESS)        /* Evaluate if the button continues pressed TO MANUAL MODE */
	{
		ruw_time_button++;
		if(ruw_time_button>FIVE_HUNDRED_MILLISECONDS) 
		{
			ruw_time_button=ZERO_MILLISECONDS;
			rub_State=MANUAL_UP;
		}
		
		else
		{
			//Do nothing
		}
	}
	
	else                                /* AUTOMATIC MODE */
	{
		ruw_time_button=ZERO_MILLISECONDS;
		window_up();
		
		if(rub_LED_Position==TOTALLY_CLOSED)
		{
			rub_State=IDLE;
			rub_LED_Position=_LED1;
			LED_OFF(_LED_UP);
		}	
			
		else
		{
			//Do nothing
		}	
	}
	
	if(status_button==BUTTON_DOWN_PRESS)     
	{
		rub_State=MANUAL_DOWN;
	}
			
}   /*************** End function automatic_up_action ***************/



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : automatic_down
 *  Created by           : Gilberto Ochoa
 *  Description          : Evaluate the time that the button was pressed to select (Manual or Automatic)
 *  Parameters           : Void
 *  Return               : Void
 *  Critical/explanation : No
 **************************************************************/
void automatic_down(void)
{
	if(status_button==BUTTON_DOWN_PRESS)         /* Evaluate if the button continues pressed TO MANUAL MODE */
	{
		ruw_time_button++;
		if(ruw_time_button>FIVE_HUNDRED_MILLISECONDS)
		{
			ruw_time_button=ZERO_MILLISECONDS;
			rub_State=MANUAL_DOWN;
		}
		
		else
		{
			//Do nothing
		}
	}
	
	else                            /* AUTOMATIC MODE */
	{
		ruw_time_button=ZERO_MILLISECONDS;
		window_down();
		
		if(rub_LED_Position==TOTALLY_OPEN)
		{
			rub_State=IDLE;
			rub_LED_Position=_LED10;
			LED_OFF(_LED_DOWN);
		}
		
		else
		{
			//Do nothing
		}	
	}
	
	if(status_button==BUTTON_UP_PRESS)
	{
		rub_State=MANUAL_UP;
	}
	
	else
	{
		//Do nothing
	}
}  /*************** End function automatic_down_action ***************/



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
	LED_OFF(_LED_UP);
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
	LED_OFF(_LED_DOWN);
	if(ANTI_PINCH==BTN_ACTIVE)
	{
		ruw_time_button=ZERO_MILLISECONDS;
		rub_State=ANTIPINCH;	
	} /* End Evaluation Anti Pinch*/
	
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
	if(status_button==BUTTON_UP_PRESS)
	{
		window_up();
		
		if(rub_LED_Position==TOTALLY_CLOSED)
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
			
	else
	{
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
	if(status_button==BUTTON_DOWN_PRESS)
	{
		window_down();
		
		if(rub_LED_Position==TOTALLY_OPEN)
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
	}
			
	else
	{
		rub_State=IDLE;	
		LED_OFF(_LED_DOWN);	
	}
}    /*************** End function manual_down ***************/



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
	window_down();
			
	if(rub_LED_Position==TOTALLY_OPEN)
	{
		rub_LED_Position=_LED10;
		LED_OFF(_LED_DOWN);
		rub_State=LOCK;
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
	if(rub_State==LOCK)
	{
		static T_UWORD luw_time_delay=ZERO_MILLISECONDS;
		luw_time_delay++;
		if(luw_time_delay==FIVE_SECONDS)
		{
			luw_time_delay=ZERO_MILLISECONDS;
			rub_State=IDLE;
		}	
	}
}   /**************** End function delay_5_seconds ***************/
