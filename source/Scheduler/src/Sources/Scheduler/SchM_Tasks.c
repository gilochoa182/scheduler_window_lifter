/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         SchM_Tasks.c
* version:          1.0
* created_by:       Gilberto Ochoa
* %date_created:    Mon Jul  13  2015
*=============================================================================*/
/* DESCRIPTION : Periodic tasks are allocated in the following files:         */
/*============================================================================*/
/* FUNCTION COMMENT :                                                         */
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

#include "SchM_Tasks.h"
#include "window_lifter.h"

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


/* Exported functions */
/* ----------------- */
/**************************************************************
 *  Name                 :	SchM_3p125ms_Task
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_3p125ms_Task(void)
 {
 	
 }



/* Exported functions */
/* ----------------- */
/**************************************************************
 *  Name                 :	SchM_6p25ms_Task
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_6p25ms_Task(void)
 {
 	
 }
 
 
 
 /* Exported functions */
/* ----------------- */
/**************************************************************
 *  Name                 :	SchM_12p5ms_Task
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_12p5ms_Task(void)
 {
 	Test_1second();
 }
 
 
 
  /* Exported functions */
/* ----------------- */
/**************************************************************
 *  Name                 :	SchM_25ms_Task
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_25ms_Task(void)
 {
 	Test_2second();
 }
 
 
 
   /* Exported functions */
/* ----------------- */
/**************************************************************
 *  Name                 :	SchM_50ms_Task
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_50ms_Task(void)
 {
 	Test_3second();
 }
 
 
 
   /* Exported functions */
/* ----------------- */
/**************************************************************
 *  Name                 :	SchM_100ms_Task
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SchM_100ms_Task(void)
 {
 	Test_4second();	
 }