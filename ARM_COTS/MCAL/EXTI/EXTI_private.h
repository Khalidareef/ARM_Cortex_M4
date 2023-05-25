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

#ifndef EXTI_PRIVATE
#define EXTI_PRIVATE

typedef struct {

    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;

}EXTI_t;

#define MEXTI           ((volatile EXTI_t*)0x40013C00)
#define SYSCFG_CR1      *((volatile u32 *)0x40013808)
#define NULL 			 (void *) 0

#define EXTI_ENABLE_INT			1
#define EXTI_DISABLE_INT		0

#define EXTI_RISING_EDGE	0
#define EXTI_FALLING_EDGE	1
#define EXTI_ON_CHANGE		2


#define EXTI_LINE0			0
#define EXTI_LINE1			1
#define EXTI_LINE2			2
#define EXTI_LINE3			3
#define EXTI_LINE4			4
#define EXTI_LINE5			5
#define EXTI_LINE6			6
#define EXTI_LINE7			7
#define EXTI_LINE8			8
#define EXTI_LINE9			9
#define EXTI_LINE10			10
#define EXTI_LINE11			11
#define EXTI_LINE12			12
#define EXTI_LINE13			13
#define EXTI_LINE14			14
#define EXTI_LINE15			15


#endif
