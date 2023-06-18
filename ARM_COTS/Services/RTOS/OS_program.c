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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


/*Array of Tasks: of Srtuct*/
static Task OS_Tasks[NUM_OF_TASKS] = {NULL};

u8 OS_voidCreatTask(u8 Copy_u8ID, u16 copy_u16Priodicity, void (*Ptr) (void), u16 Copy_u16FirstDelay)
{
    u8 Local_u8ErrorState = OK;
    /*Check if the Required Priority is Empty or Used Befor Another Task*/
    if(OS_Tasks[Copy_u8ID].Fptr == NULL)
    {
        OS_Tasks[Copy_u8ID].Priodicity = copy_u16Priodicity;
        OS_Tasks[Copy_u8ID].Fptr = Ptr;
        OS_Tasks[Copy_u8ID].State = TASK_RESUMED;   //Init The Task State
        OS_Tasks[Copy_u8ID].FirstDelay = Copy_u16FirstDelay;
    }
    /*Check if the Reserved before, don't Creat The Task*/
    else
    {
      Local_u8ErrorState = NOK;  
    }
    return Local_u8ErrorState;
}

void OS_voidStart(void)
{
	MSTK_voidInit();
    /*Tick Time -> 1000 Micro Sec -> 1m Sec*/
	MSTK_voidSetPeriodicInterval(1000, Scheduler);

}

//volatile u16 TickCounts = 0;
/*without First Delay*/
/*void Scheduler(void)
{

    for(u8 i = 0; i < NUM_OF_TASKS; i++)
    {
        if((TickCounts % OS_Tasks[i].Priodicity) == 0)
        {
            OS_Tasks[i].Fptr();
        }

    }
    TickCounts++;
}*/

/*With First Delay*/
void Scheduler(void)
{

    for(u8 i = 0; i < NUM_OF_TASKS; i++)
    {
        /*Check if the Task Suspended or not*/
        if((OS_Tasks[i].Fptr != NULL) && (OS_Tasks[i].State == TASK_RESUMED))
        {
            if(OS_Tasks[i].FirstDelay == 0)
            {
                OS_Tasks[i].Fptr();
                /*Assign the First Delay Parameter to the Priodicity - 1*/
                OS_Tasks[i].FirstDelay = OS_Tasks[i].Priodicity - 1;
              
            }
            else
            {
                /*Decrement The First Delay*/
                OS_Tasks[i].FirstDelay--;
            }
        }
    }
    
}

void OS_voidSuspendTask(u8 Copy_u8ID)
{
    OS_Tasks[Copy_u8ID].State = TASK_SUSPENDED;
}

void OS_voidResumeTask(u8 Copy_u8ID)
{
    OS_Tasks[Copy_u8ID].State = TASK_RESUMED;
}


void OS_voidDeleteTask(u8 Copy_u8ID)
{
    OS_Tasks[Copy_u8ID].Fptr = NULL;
}




















