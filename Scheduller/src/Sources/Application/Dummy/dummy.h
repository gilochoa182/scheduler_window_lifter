/*******************************************************************************/
/**
\file       dummy.h
\brief      Dummy Functions
\author     Francisco Martinez
\version    1.0
\date       04/04/2014
*/
/*******************************************************************************/

#ifndef _DUMMY_H        /*prevent duplicated includes*/
#define _DUMMY_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** Variable types and common definitions */

#include "typedefs.h"

/*-- Variables ---------------------------------------------------------------*/

/*-- Types Definitions -------------------------------------------------------*/

typedef struct TaskStructTag{
	T_UWORD ruw_Counter;
	T_UWORD ruw_TopCount;
	tCallbackFunction   cpfu_PerFunct;
}TASKSTRUCT;

/*-- Defines -----------------------------------------------------------------*/


/*-- Function Prototypes -----------------------------------------------------*/

void Test(void);
void dummy_500us(void);
void dummy_endless_loop(void);

void Task_5ms(void);	/* Period = 5ms */
void Task_10ms(void);	/* Period = 10ms */
void Task_50ms(void);	/* Period = 50ms */
void Task_100ms(void);	/* Period = 100ms */



#endif /* _DUMMY_H */

/*******************************************************************************/
