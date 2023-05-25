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
 
#ifndef EXTI_CONFIG
#define EXTI_CONFIG

/*Options: 	EXTI_LINE0
			EXTI_LINE1
			EXTI_LINE2
			EXTI_LINE3
			EXTI_LINE4
			EXTI_LINE5
			EXTI_LINE6
			EXTI_LINE7
			EXTI_LINE8
			EXTI_LINE9
			EXTI_LINE10
			EXTI_LINE11
			EXTI_LINE12
			EXTI_LINE13
			EXTI_LINE14
			EXTI_LINE15	*/
#define EXTI_LINE		EXTI_LINE1

/*Options: 	EXTI_ENABLE_INT
			EXTIDISABLE_INT*/
#define EXTI_MODE		EXTI_ENABLE_INT

/*Options: 	EXTI_RISING_EDGE
			EXTI_FALLING_EDGE
			EXTI_ON_CHANGE		*/
#define EXTI_SENSE_MODE		EXTI_RISING_EDGE


#endif
