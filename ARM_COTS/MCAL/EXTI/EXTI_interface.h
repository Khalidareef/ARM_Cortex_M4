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

#ifndef EXTI_INTERFACE
#define EXTI_INTERFACE

#define MEXTI_RISING_EDGE   0
#define MEXTI_FALLING_EDGE  1
#define MEXTI_ON_CHANGE     2

#define MEXTI_LINE0			0
#define MEXTI_LINE1			1
#define MEXTI_LINE2			2
#define MEXTI_LINE3			3
#define MEXTI_LINE4			4
#define MEXTI_LINE5			5
#define MEXTI_LINE6			6
#define MEXTI_LINE7			7
#define MEXTI_LINE8			8
#define MEXTI_LINE9			9
#define MEXTI_LINE10		10
#define MEXTI_LINE11		11
#define MEXTI_LINE12		12
#define MEXTI_LINE13		13
#define MEXTI_LINE14		14
#define MEXTI_LINE15		15

void MEXTI_voidInit(void);
void MEXTI_voidEnableINT(u8 Copy_u8EXTILine);
void MEXTI_voidDisableINT(u8 Copy_u8EXTILine);
void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal);
void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void));

#endif
