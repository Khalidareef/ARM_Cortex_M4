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
 * v2.0		  27 May, 2023	Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"

static void(*pvCallBackFunction) (void) = NULL;
static u8 u8IntervalFlag = SINGLE_INTERVAL;

/****************************************   Pre Processing  ***********************************************/

void MSTK_voidInit(void)
{
	/*Clk Source*/
#if MSTK_CLK_SOURCE == AHB
	SET_BIT(STK -> CTRL , 2);

#elif MSTK_CLK_SOURCE == AHB_DEVIDED_BY_8
	CLR_BIT(STK -> CTRL , 2);

#else
#error "MSTK_CLK_SOURCE Configuration Error"
#endif

	/*SYSTICK Interrupt*/
#if MSTK_INTERRUPT == ENABLE
	SET_BIT(STK -> CTRL , 1);

#elif MSTK_INTERRUPT == DISABLE
	CLR_BIT(STK -> CTRL , 1);

#else
#error "MSTK_INTERRUPT Configuration Error"
#endif

	/*SYSTICK Enable*/
#if MSTK_ENABLE == ENABLE
	SET_BIT(STK -> CTRL , 0);
#elif MSTK_ENABLE  == DISABLE
	CLR_BIT(STK -> CTRL , 0);
#else
#error "MSTK_ENABLE Configuration Error"
#endif
}

/****************************************   Post Processing  ***********************************************/

void MSTK_voidSTKMode(u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
	case ENABLE:
		SET_BIT(STK -> CTRL , 0);
		break;

	case DISABLE:
		CLR_BIT(STK -> CTRL , 0);
		break;

	default:    /*Return Error*/    break;
	}
}


void MSTK_voidSetClkSource(u8 Copy_u8ClkSource)
{
	switch(Copy_u8ClkSource)
	{
	case AHB:
		SET_BIT(STK -> CTRL , 2);
		break;

	case AHB_DEVIDED_BY_8:
		CLR_BIT(STK -> CTRL , 2);
		break;

	default:    /*Return Error*/    break;
	}
	/*Enable STK*/
	SET_BIT(STK -> CTRL , 0);
}

void MSTK_voidInterruptMode(u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
	case ENABLE:
		SET_BIT(STK -> CTRL , 1);
		break;

	case DISABLE:
		CLR_BIT(STK -> CTRL , 1);
		break;

	default:    /*Return Error*/    break;
	}
}

u32  MSTK_u32ElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = (STK -> LOAD) - (STK -> VAL);
	return Local_u32ElapsedTime;
}

u32  MSTK_u32RemainingTime(void)
{
	u32 Local_u32ReaminingTime;
	Local_u32ReaminingTime = STK -> VAL;
	return Local_u32ReaminingTime;
}

void MSTK_voidSetBusyWait(u32 Copy_u32TicksToWait)
{
	STK -> LOAD =  Copy_u32TicksToWait;
	/*Flag Returns 1 if Timer Counted To 0, since last time this was read. */
	while(GET_BIT(STK -> CTRL, 16) == 0);
	STK -> VAL = 0;
}

void MSTK_voidSetPreloadVal(u32 Copy_u32LoadVal)
{
	STK -> LOAD = Copy_u32LoadVal;
}

void MSTK_voidResetSTK(void)
{
	STK -> VAL = 0;
}

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void(*NotificationFunction) (void))
{
	/*Disable STK*/
	CLR_BIT(STK -> CTRL, 0);
	/*Reset STK*/
	STK -> VAL = 0;
	STK -> LOAD = Copy_u32Ticks;

	pvCallBackFunction = NotificationFunction;
	u8IntervalFlag = SINGLE_INTERVAL;

	SET_BIT(STK -> CTRL, 1);
	SET_BIT(STK -> CTRL, 0);
}

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void(*NotificationFunction) (void))
{
	STK -> LOAD = Copy_u32Ticks;

	pvCallBackFunction = NotificationFunction;
	u8IntervalFlag = PERIODIC_INTERVAL;

	SET_BIT(STK -> CTRL, 1);
	SET_BIT(STK -> CTRL, 0);
}

void SysTick_Handler(void)
{
	u32 Local_u32TempVar;
	if(u8IntervalFlag == SINGLE_INTERVAL)
	{
		STK -> LOAD = 0;
		STK -> VAL = 0;
		CLR_BIT(STK -> CTRL, 0);
	}
	if(pvCallBackFunction != NULL)
	{
		pvCallBackFunction();
	}
	Local_u32TempVar = GET_BIT(STK -> CTRL, 16);
}


