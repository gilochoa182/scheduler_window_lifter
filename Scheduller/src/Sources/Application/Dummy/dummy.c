/*******************************************************************************/
/**
\file       dummy.c
\brief      Dummy Functions
\author     Francisco Martinez
\version    1.0
\date       04/04/2014
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
#include "dummy.h"

/* GPIO routines prototypes */ 
#include "GPIO.h"

/** Used modules */

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

extern TASKSTRUCT function_table_def[4];
extern TASKSTRUCT *rps_TaskPtr[4];

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/


/****************************************************************************************************/
/**
* \brief    Turn a combination of 4 LEDs with a unique blinking pattern, this funcation shall be 
* \brief    called periodically to operate. 
* \author   Francisco Martinez
* \return   void
*/



void dummy_500us(void){
	T_UWORD luw_dummy_counter;
	for (luw_dummy_counter = 0; luw_dummy_counter < 4; luw_dummy_counter++){
		rps_TaskPtr[luw_dummy_counter]->ruw_Counter++;
		
		if((rps_TaskPtr[luw_dummy_counter]->ruw_Counter) == (rps_TaskPtr[luw_dummy_counter] -> ruw_TopCount)){
			rps_TaskPtr[luw_dummy_counter]->cpfu_PerFunct();
			rps_TaskPtr[luw_dummy_counter]->ruw_Counter= 0;
		}
	}
	
}


void Task_5ms(void){
	LED_TOGGLE(LED1);
}

void Task_10ms(void){
	LED_TOGGLE(LED2);
}

void Task_50ms(void){
	LED_TOGGLE(LED3);
}

void Task_100ms(void){
	LED_TOGGLE(LED4);
}

void Test(void)
{
    static T_UWORD rub_U16Counter = 0;
    
    rub_U16Counter++;
    
    if (rub_U16Counter == 10)
    {
    	LED_TOGGLE(LED1);
    	rub_U16Counter = 0;	
    }

}


void dummy_endless_loop(void){
	for(;;){
	}
}