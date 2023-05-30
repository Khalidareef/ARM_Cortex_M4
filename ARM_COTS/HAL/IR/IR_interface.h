/*****************************************************************************************
 * Author:		        Khalid A. Mohamad
 * Creation Data:		30 May, 2023
 * Version:			    v1.0
 * Compiler:	        GNU ARM-GCC
 * Controller:	        STM32F401CCU6 (32-bit Architecture)
 * Processor:	        Cortex M4 (32-bit Architecture)
 * Layer:			    HAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  30 May, 2023	      Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/
 
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

void IR_voidInit(void);
void IR_voidTakeAction(void);
void IR_voidGetFrame(void);
void IR_voidPlay(void);



#endif