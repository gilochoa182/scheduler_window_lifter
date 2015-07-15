/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        SchM_Types.h
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Mon Jul 13 2015
*=============================================================================*/
/* DESCRIPTION :   Scheduler module types                                     */
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

#ifndef SCHM_TYPES_H
#define SCHM_TYPES_H

/* Includes */
/* -------- */

#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

typedef void (*TaskFunctionPtrType)(void);
typedef T_UBYTE SchedulerTaskOffsetType;

/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */

typedef enum
{
	MASK_3P125MS=   3,
	MASK_6P25MS =   7,
	MASK_12P5MS =   15,
	MASK_25MS   =   31,
	MASK_50MS   =   63,
	MASK_100MS  =   127
}SchedulerTaskMaskType;


typedef enum
{
	TASK_BKG,
	TASK_3P125MS,
	TASK_6P25MS,
	TASK_12P5MS,
	TASK_25MS,
	TASK_50MS,
	TASK_100MS
}SchedulerTaskIDType;


typedef enum
{
	TASK_STATE_SUSPENDED,
	TASK_STATE_READY,
	TASK_STATE_RUNNING	
}SchedulerTaskStateType;


typedef struct
{
	SchedulerTaskStateType SchedulerTaskState;
	TaskFunctionPtrType TaskFunctionControlPtr;
}SchedulerTCB;   


typedef struct
{
	SchedulerTaskOffsetType SchedulerTaskOffset;
	SchedulerTaskMaskType SchedulerTaskMask;
	SchedulerTaskIDType SchedulerTaskID;
	TaskFunctionPtrType TaskFunctionPtr;	
}SchedulerTaskDescriptorType;


typedef struct
{
	T_UBYTE SchedulerNumberOfTasks;
	const SchedulerTaskDescriptorType *SchedulerTaskDescriptor;
}SchedulerConfigType;


typedef enum
{
	SCHEDULER_UNINIT,
	SCHEDULER_INIT,
	SCHEDULER_RUNNING,
	SCHEDULER_OVERLOAD,
	SCHEDULER_HALTED
}SchedulerStateType;


typedef struct
{
	T_UBYTE SchedulerCounter;
	SchedulerTaskIDType SchedulerTaskRunning;
	SchedulerStateType SchedulerStatus;	
}SchedulerControlType;
/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */


/* Functions macros */


/* Exported defines */


#endif