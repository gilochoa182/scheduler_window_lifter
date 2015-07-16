/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         window_lifter.c
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Mon Jul 13 2015
*=============================================================================*/
/* DESCRIPTION :                                                              */
/*============================================================================*/
/* FUNCTION COMMENT :                                                         */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               | Gilberto Ochoa   */
/*============================================================================*/

/* Includes */
/* -------- */

/** Core modules */
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
#include "window_lifter.h"

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
extern TASKSTRUCT function_table_def[4];
extern TASKSTRUCT *rps_TaskPtr[4];

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



void dummy_500us(void)
{
	T_UBYTE lub_dummy_counter;
	
	for(lub_dummy_counter=0;lub_dummy_counter<4;lub_dummy_counter++)
	{
		rps_TaskPtr[lub_dummy_counter]->ruw_Counter++;
		if((rps_TaskPtr[lub_dummy_counter]->ruw_Counter) == (rps_TaskPtr[lub_dummy_counter]->ruw_TopCount))
		{
			rps_TaskPtr[lub_dummy_counter]->cpfu_PerFunct();
			rps_TaskPtr[lub_dummy_counter]->ruw_Counter=0;
		}
	}
}

void Task_5ms(void)
{
	LED_TOGGLE(LED1);
}

void Task_10ms(void)
{
	LED_TOGGLE(LED2);
}

void Task_50ms(void)
{
	LED_TOGGLE(LED3);
}

void Task_100ms(void)
{
	LED_TOGGLE(LED4);
}



void Test_8second(void)
{
    static T_UWORD rub_U16Counter = 0;
    
    rub_U16Counter++;
    
    if (rub_U16Counter == 80)
    {
    	LED_TOGGLE(LED1);
    	rub_U16Counter = 0;	
    }

}



void Test_4second(void)
{
    static T_UWORD rub_U16Counter = 0;
    
    rub_U16Counter++;
    
    if (rub_U16Counter == 80)
    {
    	LED_TOGGLE(LED2);
    	rub_U16Counter = 0;	
    }

}


void Test_2second(void)
{
    static T_UWORD rub_U16Counter = 0;
    
    rub_U16Counter++;
    
    if (rub_U16Counter == 80)
    {
    	LED_TOGGLE(LED3);
    	rub_U16Counter = 0;	
    }

}



void Test_1second(void)
{
    static T_UWORD rub_U16Counter = 0;
    
    rub_U16Counter++;
    
    if (rub_U16Counter == 80)
    {
    	LED_TOGGLE(LED4);
    	rub_U16Counter = 0;	
    }

}



void dummy_endless_loop(void)
{
	for(;;)
	{
		
	}
}