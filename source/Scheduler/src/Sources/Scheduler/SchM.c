/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         SchM.c
* version:          1.0
* created_by:       Gilberto Ochoa
* %date_created:    Mon Jul  13  2015
*=============================================================================*/
/* DESCRIPTION : Provides main functionality of the scheduler                 */
/*============================================================================*/
/* FUNCTION COMMENT : OS Tick callback shall be allocated on those files      */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               | Gilberto Ochoa   */
/*                                                                            */
/*============================================================================*/

/* Includes */
/* -------- */
#include "SchM.h"
#include    "PIT.h"

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

SchedulerControlType SchedulerControl=
{
	0,TASK_BKG,SCHEDULER_INIT
};

/* WORD RAM variables */

extern SchedulerTCB SchedulerTCB_Task[6];

/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */

void SchM_OsTick(void);
void SchM_Background(void);
void SchM_Task_1p56ms(void);

/* Exported functions prototypes */
/* ----------------------------- */




/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	SchM_Init
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_Init(const SchedulerConfigType *SchM_Config)
 {
 	T_UBYTE lub_index;
 	
 	PIT_device_init();
 	PIT_channel_configure(PIT_CHANNEL_0 , SchM_OsTick);
 	
 	for(lub_index=0;lub_index<=6;lub_index++)
 	{
 		SchedulerTCB_Task[lub_index].SchedulerTaskState=TASK_STATE_SUSPENDED;
 		//SchedulerTCB_Task[lub_index].TaskFunctionControlPtr=SchM_Config->SchedulerTaskDescriptorType->TaskFunctionPtr;
 		SchM_Config++;
 	}
 	
 	SchedulerControl.SchedulerStatus=SCHEDULER_INIT;
 	
 }
 
 
 	
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	SchM_DeInit
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_Stop(void)
 {
 	PIT_channel_stop(PIT_CHANNEL_0);
 	SchedulerControl.SchedulerStatus=SCHEDULER_HALTED;
 }
 
 
 
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	SchM_Start
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_Start(void)
 {
 	PIT_channel_start(PIT_CHANNEL_0);
 	SchedulerControl.SchedulerStatus=SCHEDULER_RUNNING;
 	SchM_Background();
 }
 
 
 
/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : SchM_OsTick
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_OsTick(void)
 {
 	SchedulerControl.SchedulerCounter++;
 }
 
 
 
/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 :	SchM_Background
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_Background(void)
 {
 	
 }
 
 
 
/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 :	SchM_Task_1p56ms
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_Task_1p56ms(void)
 {
 	
 }