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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



void MNVIC_voidInit(void)
{
    /*Set The Group And Sub Priority Distribution*/
    SCB_AIRCR |= (AIRCR_PRIVKEY << 16) | (NVIC_GBP_SUB_DISTRIBUTION << 8);
}

void MNVIC_voidEnablePeripheralINT(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISRERIndex;
    Local_u8ISRERIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ISER[Local_u8ISRERIndex] = (1 << (Copy_u8PeripheralID % 32));
}

void MNVIC_voidDisablePeripheralINT(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISRERIndex;
    Local_u8ISRERIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ICER[Local_u8ISRERIndex] = (1 << (Copy_u8PeripheralID % 32));
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISRERIndex;
    Local_u8ISRERIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ISPR[Local_u8ISRERIndex] = (1 << (Copy_u8PeripheralID % 32));
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISRERIndex;
    Local_u8ISRERIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ICPR[Local_u8ISRERIndex] = (1 << (Copy_u8PeripheralID % 32));
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID)
{

}

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority)
{
    MNVIC ->  IPR[Copy_u8PeripheralID] = (Copy_u8Priority << 4);
}