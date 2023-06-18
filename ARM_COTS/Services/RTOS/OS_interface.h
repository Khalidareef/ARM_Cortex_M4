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

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


u8 OS_voidCreatTask(u8 Copy_u8ID, u16 copy_u16Priodicity, void (*Ptr) (void), u16 Copy_u16FirstDelay)void OS_voidStart(void);
void OS_voidSuspendTask(u8 Copy_u8ID);
void OS_voidResumeTask(u8 Copy_u8ID);
void OS_voidDeleteTask(u8 Copy_u8ID);

#endif
