/*****************************************************************************************
 * Author:				Khalid A. Mohamad
 * Creation Data:		22 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  22 May, 2023	Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*pvCallBack[16])(void) = {NULL};//NULL = (void *) 0

void MEXTI_voidInit(void)
{

#if EXTI_MODE == EXTI_ENABLE_INT
	SET_BIT(MEXTI -> IMR, EXTI_LINE);

#elif EXTI_MODE == EXTI_DISABLE_INT
	CLR_BIT(MEXTI -> IMR, EXTI_LINE);

#else
#error "EXTI Mode Configuration Error"
#endif

#if EXTI_SENSE_MODE == EXTI_RISING_EDGE
	CLR_BIT(MEXTI -> FTSR, EXTI_LINE); //Clear The FAlling Edge*/
	SET_BIT(MEXTI -> RTSR, EXTI_LINE);

#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
	CLR_BIT(MEXTI -> RTSR, Copy_u8EXTILine); //Clear The Rissing Edge*/
	SET_BIT(MEXTI -> FTSR, Copy_u8EXTILine);

#elif EXTI_SENSE_MODE == EXTI_ON_CHANGE
	SET_BIT(MEXTI -> RTSR, Copy_u8EXTILine);
	SET_BIT(MEXTI -> FTSR, Copy_u8EXTILine);
#else
#error "EXTI Sense Configuration Error"
#endif

}

void MEXTI_voidEnableINT(u8 Copy_u8EXTILine)
{
	if(Copy_u8EXTILine < 16)
	{
		SET_BIT(MEXTI -> IMR, Copy_u8EXTILine);
	}

	else
	{
		/*return Error*/
	}

}

void MEXTI_voidDisableINT(u8 Copy_u8EXTILine)
{
	if(Copy_u8EXTILine < 16)
	{
		CLR_BIT(MEXTI -> IMR, Copy_u8EXTILine);
	}
	else
	{
		/*return Error*/
	}


}

void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal)
{
	switch(Copy_u8SenseSignal)
	{
	case MEXTI_RISING_EDGE:
		CLR_BIT(MEXTI -> FTSR, Copy_u8EXTILine); //Clear The FAlling Edge*/
		SET_BIT(MEXTI -> RTSR, Copy_u8EXTILine);
		break;
	case MEXTI_FALLING_EDGE:
		CLR_BIT(MEXTI -> RTSR, Copy_u8EXTILine); //Clear The Rissing Edge*/
		SET_BIT(MEXTI -> FTSR, Copy_u8EXTILine);
		break;
	case MEXTI_ON_CHANGE:
		SET_BIT(MEXTI -> RTSR, Copy_u8EXTILine);
		SET_BIT(MEXTI -> FTSR, Copy_u8EXTILine);
		break;

	}
}

void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void))
{
	pvCallBack[Copy_u8EXTILine] = pvNotificationFunction;
}

void EXTI0_IRQHandler(void)
{
	if(pvCallBack[0] != NULL)
	{
		pvCallBack[0]();

	}
	SET_BIT(MEXTI -> PR, 0);
}

void EXTI1_IRQHandler(void)
{
	if(pvCallBack[1] != NULL)
	{
		pvCallBack[1]();

	}
	SET_BIT(MEXTI -> PR, 1);
}

void EXTI2_IRQHandler(void)
{
	if(pvCallBack[2] != NULL)
	{
		pvCallBack[2]();

	}
	SET_BIT(MEXTI -> PR, 2);
}

void EXTI3_IRQHandler(void)
{
	if(pvCallBack[3] != NULL)
	{
		pvCallBack[3]();

	}
	SET_BIT(MEXTI -> PR, 3);
}

void EXTI4_IRQHandler(void)
{
	if(pvCallBack[4] != NULL)
	{
		pvCallBack[4]();

	}
	SET_BIT(MEXTI -> PR, 4);
}

void EXTI5_IRQHandler(void)
{
	if(pvCallBack[5] != NULL)
	{
		pvCallBack[5]();

	}
	SET_BIT(MEXTI -> PR, 5);
}

void EXTI6_IRQHandler(void)
{
	if(pvCallBack[6] != NULL)
	{
		pvCallBack[6]();

	}
	SET_BIT(MEXTI -> PR, 6);
}

void EXTI7_IRQHandler(void)
{
	if(pvCallBack[7] != NULL)
	{
		pvCallBack[7]();

	}
	SET_BIT(MEXTI -> PR, 7);
}

void EXTI8_IRQHandler(void)
{
	if(pvCallBack[8] != NULL)
	{
		pvCallBack[8]();

	}
	SET_BIT(MEXTI -> PR, 8);
}

void EXTI9_IRQHandler(void)
{
	if(pvCallBack[9] != NULL)
	{
		pvCallBack[9]();

	}
	SET_BIT(MEXTI -> PR, 9);
}

void EXTI10_IRQHandler(void)
{
	if(pvCallBack[10] != NULL)
	{
		pvCallBack[10]();

	}
	SET_BIT(MEXTI -> PR, 10);
}

void EXTI11_IRQHandler(void)
{
	if(pvCallBack[11] != NULL)
	{
		pvCallBack[11]();

	}
	SET_BIT(MEXTI -> PR, 11);
}

void EXTI12_IRQHandler(void)
{
	if(pvCallBack[12] != NULL)
	{
		pvCallBack[12]();

	}
	SET_BIT(MEXTI -> PR, 12);
}

void EXTI13_IRQHandler(void)
{
	if(pvCallBack[13] != NULL)
	{
		pvCallBack[13]();

	}
	SET_BIT(MEXTI -> PR, 13);
}

void EXTI14_IRQHandler(void)
{
	if(pvCallBack[14] != NULL)
	{
		pvCallBack[14]();

	}
	SET_BIT(MEXTI -> PR, 14);
}

void EXTI15_IRQHandler(void)
{
	if(pvCallBack[15] != NULL)
	{
		pvCallBack[15]();

	}
	SET_BIT(MEXTI -> PR, 15);
}
