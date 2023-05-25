/*****************************************************************************************
 * Author:				Khalid A. Mohamad
 * Creation Data:		11 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  11 May, 2023	Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#define MSTK_CLK_AHB                    1
#define MSTK_CLK_AHB_DIV_BY_8           0

#define STK_MODE_ENABLE                 1
#define STK_MODE_DISABLE                0

#define STK_INT_ENABLE                 	1
#define STK_INT_DISABLE                 0
      
void MSTK_voidInit(void);

void MSTK_voidSTKMode(u8 Copy_u8Mode);
void MSTK_voidSetClkSource(u8 Copy_u8ClkSource);
void MSTK_voidInterruptMode(u8 Copy_u8Mode);
u32  MSTK_u32ElapsedTime(void);
u32  MSTK_u32RemainingTime(void);
void MSTK_voidSetBusyWait(u32 Copy_u32TicksToWait);
void MSTK_voidSetPreloadVal(u32 Copy_u32LoadVal);
void MSTK_voidResetSTK(void);

#endif
