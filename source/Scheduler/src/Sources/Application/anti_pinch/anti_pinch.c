/* Includes */
/* -------- */

#include "window_lifter.h"
#include "led.h"

#define ZERO_MILLISECONDS           0
#define _LED10                      9
#define _LED_DOWN                   11
#define TOTALLY_OPEN                10
#define FIVE_SECONDS                125


extern StateMachineType rub_State;

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
			
	if(Get_LEDPosition() == TOTALLY_OPEN)
	{
		Set_LEDPosition(_LED10);
		LED_OFF(_LED_DOWN);
		rub_State = LOCK;
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
	if(rub_State == LOCK)
	{
		static T_UWORD luw_time_delay = ZERO_MILLISECONDS;
		luw_time_delay++;
		if(luw_time_delay == FIVE_SECONDS)
		{
			luw_time_delay = ZERO_MILLISECONDS;
			rub_State = IDLE;
		}	
	}
}   /**************** End function delay_5_seconds ***************/