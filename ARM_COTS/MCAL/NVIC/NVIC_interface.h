/*****************************************************************************************
 * Author:				Khalid A. Mohamad
 * Creation Data:		21 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  21 May, 2023	Khalid A. Mohamad		  Initial Creation
*****************************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


#define  NVIC_EXTI0      6
#define  NVIC_EXTI1      7


void MNVIC_voidInit(void);
void MNVIC_voidEnablePeripheralINT(u8 Copy_u8PeripheralID);
void MNVIC_voidDisablePeripheralINT(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority);

#endif