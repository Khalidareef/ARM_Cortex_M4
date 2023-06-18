#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct 
{
    u16 Priodicity;
    void (*Fptr) (void);
    u8 FirstDelay;
    u8 State;   //do task play or suspend or pause
}Task;

static void Scheduler(void);
/*****************************************************************************************
 * Author:				Khalid A. Mohamad
 * Creation Data:		18 Jun, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				Service Layer, RTOS
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  18 Jun, 2023	      Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/


#define         TASK_RESUMED        0
#define         TASK_SUSPENDED      1 

#define         OK                  0
#define         NOK                 1

#define         NULL                0

#endif