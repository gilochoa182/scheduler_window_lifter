/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %template.c%
* Instance:         RPL_1
* %version:         2 %
* %created_by:      uid02495 %
* %date_created:    Fri Jan  9 14:38:03 2004 %
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "SchM.h"
#include "PIT.h"

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

static T_UBYTE rub_SchInitCounter;

const SchConfigType * rp_SchM_Config;

SchControlType SchControl= {
	0,TASK_BKG,SCH_UNINIT
};


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */
SchControlType SchM_Control;

SchTaskControlType *SchM_TaskControlPtr;


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 
	
/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */
void SchM_Background(void);

void SchM_OsTick(void);


/* Exported functions prototypes */
/* ----------------------------- */


/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_Init(const SchConfigType *SchM_Config){
 	T_UBYTE lub_SchInitCounter;	
 	
    rp_SchM_Config = SchM_Config;
    
    SchM_Control.SchStatus = SCH_INIT;
    
	//SchM_TaskControlPtr = (SchTaskControlType *)(sizeof(SchM_Config->SchNumberOfTask));

 	for(lub_SchInitCounter = 0; lub_SchInitCounter<=6; lub_SchInitCounter++){
 		SchM_TaskControlPtr[lub_SchInitCounter].SchTaskState = TASK_STATE_SUSPENDED; 
		SchM_TaskControlPtr[lub_SchInitCounter].TaskFunctionControlPtr = SchM_Config[lub_SchInitCounter].SchTaskTable->TaskFunctionPtr;
 	}
	PIT_device_init();
 	PIT_channel_configure(PIT_CHANNEL_0, &SchM_OsTick);
 	
	SchM_Control.SchCounter = 0;
 }


/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_Stop(void){
 	PIT_channel_stop(PIT_CHANNEL_0);
 	SchControl.SchStatus=SCH_HALTED;
 }
 
 
 /**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_Start(void){
 	PIT_channel_start(PIT_CHANNEL_0);
 	enableIrq();
 	SchControl.SchStatus=SCH_RUNNING;
 	SchM_Background();
 }
 
 
  /**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_OsTick(void){
 	T_UBYTE lub_SchInitCounter;
 	
	const SchConfigType *lp_SchM_Config;
	lp_SchM_Config = rp_SchM_Config;
	SchM_Control.SchCounter++;
	for(lub_SchInitCounter = 0; lub_SchInitCounter < lp_SchM_Config->SchNumberOfTask; lub_SchInitCounter++){
		if( ((lp_SchM_Config+lub_SchInitCounter)->SchTaskTable->SchTaskMask & SchM_Control.SchCounter) == (lp_SchM_Config+lub_SchInitCounter)->SchTaskTable->SchTaskOffset ){
			(SchM_TaskControlPtr+lub_SchInitCounter)->SchTaskState = TASK_STATE_READY;
		}
		else{
			//Do nothing
		}
	}
 }	

 
   /**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 /*void void Sch_Task_##period(void){
 	
 }*/
 
 
   /**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_Background(void){
 	const SchConfigType *lp_SchM_Config;
	lp_SchM_Config = rp_SchM_Config;
 	for(;;){
 		for(rub_SchInitCounter = 0; rub_SchInitCounter < lp_SchM_Config->SchNumberOfTask; rub_SchInitCounter++){
 			if((SchM_TaskControlPtr+rub_SchInitCounter)->SchTaskState == TASK_STATE_READY){
 				(SchM_TaskControlPtr+rub_SchInitCounter)->SchTaskState = TASK_STATE_RUNNING;
 				(SchM_TaskControlPtr+rub_SchInitCounter)->TaskFunctionControlPtr();
 				(SchM_TaskControlPtr+rub_SchInitCounter)->SchTaskState = TASK_STATE_SUSPENDED;
 			}
 		}
 	}
 }