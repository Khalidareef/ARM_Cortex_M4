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

#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

 /*Options: AHB_DEVIDED_BY_8
            AHB */
#define MSTK_CLK_SOURCE             AHB_DEVIDED_BY_8

/*Options:  ENABLE
            DISABLE*/
#define MSTK_INTERRUPT              ENABLE

/*Options:  ENABLE
            DISABLE*/
#define MSTK_ENABLE                 ENABLE


#endif