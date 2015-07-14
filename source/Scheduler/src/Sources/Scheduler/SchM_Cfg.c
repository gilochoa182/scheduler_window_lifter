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
/* DESCRIPTION : Configuartion file of the "Grandpa´s Clock Scheduler" core   */
/*============================================================================*/
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


const SchedulerTaskDescriptorType SchedulerTaskDescConfig [] =
{
	/* Offset,    MASK,        Task ID,     Function Pointer*/
	{   0,     MASK_3P125MS, TASK_3P125MS, (void*)0    },
	{   1,     MASK_6P25MS,  TASK_6P25MS,  (void*)0    },
	{   2,     MASK_12P5MS,  TASK_12P5MS,  (void*)0    },
	{   3,     MASK_25MS,    TASK_25MS,    (void*)0    },
	{   5,     MASK_50MS,    TASK_50MS,    (void*)0    },
	{   6,     MASK_100MS,   TASK_100MS,   (void*)0    }
};

const SchedulerConfigType SchedulerConfig = 
{
	(sizeof(SchedulerTaskDescConfig)/sizeof(SchedulerTaskDescConfig[0])),
	SchedulerTaskDescConfig
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

