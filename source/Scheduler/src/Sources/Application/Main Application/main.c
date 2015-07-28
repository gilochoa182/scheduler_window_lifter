/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         main.c
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Mon  Jul 13   2015 
*=============================================================================*/
/* DESCRIPTION :  This File contains initializations and main settings        */
/*============================================================================*/
/* FUNCTION COMMENT :                                                         */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               | Gilberto Ochoa   */
/*           |             |                               |                  */
/*============================================================================*/

/* Includes */
/* -------- */

#include    "SchM_Cfg.h"

#include    "MemAlloc_Cfg.h"

#include    "led.h"

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
void disableWatchdog(void);


/* Exported functions prototypes */
/* ----------------------------- */



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 :  main
 *  Description          :  The Main function
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  No
 **************************************************************/
void main(void) 

{
	T_UBYTE lub_gpio_counter=0;
	initModesAndClock();
	/* Disable Watchdog */
	disableWatchdog();
	MemAllocInit(&MemAllocConfig);
		for(lub_gpio_counter=0;lub_gpio_counter<4;lub_gpio_counter++)
	{
		GPIO_SetPin(PORTE,lub_gpio_counter,INPUT);
	}
	for(lub_gpio_counter=0;lub_gpio_counter<12;lub_gpio_counter++)
	{
		GPIO_SetPin(PORTA,lub_gpio_counter,OUTPUT);
	}
	LED_OFF(_LED_UP);
	LED_OFF(_LED_DOWN);	
	/*Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
    /* Initialize Scheduler */
    SchM_Init(&SchedulerConfig);
    /* Start Scheduler*/
    SchM_Start();
}



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 :  disableWatchdog
 *  Description          :  Disable the Watchdog
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  No
 **************************************************************/
void disableWatchdog(void) 
{
  SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000d928; 
  SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}