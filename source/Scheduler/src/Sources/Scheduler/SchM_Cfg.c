/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         SchM_Cfg.c
* version:          1.0
* created_by:       Gilberto Ochoa
* %date_created:    Mon Jul  13  2015
*=============================================================================*/
/* DESCRIPTION : Provides the general scheduler configuration and tasks       */
/*               descriptor table                                             */
/*=================================	==========================================*/
/* FUNCTION COMMENT : Here is the table to configure the tasks of the system  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               | Gilberto Ochoa   */
/* This file is created based on mw_schm_cfg module from the old version of   */
/* this scheduler.                                                            */
/*============================================================================*/

/* Includes */
/* -------- */
#include "SchM_Cfg.h"
#include "SchM_Tasks.h"


const SchedulerTaskDescriptorType SchedulerTaskDescConfig [] =
{
	/* Offset,    MASK,        Task ID,     Function Pointer*/
	{   0,     MASK_3P125MS, TASK_3P125MS, &SchM_3p125ms_Task   },
	{   1,     MASK_6P25MS,  TASK_6P25MS,  &SchM_6p25ms_Task    },
	{   2,     MASK_12P5MS,  TASK_12P5MS,  &SchM_12p5ms_Task    },
	{   3,     MASK_25MS,    TASK_25MS,    &SchM_25ms_Task      },
	{   5,     MASK_50MS,    TASK_50MS,    &SchM_50ms_Task      },
	{   6,     MASK_100MS,   TASK_100MS,   &SchM_100ms_Task     }
};

const SchedulerConfigType SchedulerConfig = 
{
	(sizeof(SchedulerTaskDescConfig)/sizeof(SchedulerTaskDescConfig[0])),
	SchedulerTaskDescConfig
};

SchedulerTCB SchedulerTCB_Task[6]=
{
};

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
