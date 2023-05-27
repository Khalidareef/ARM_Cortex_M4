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

#ifndef STK_CONFIG_H
#define STK_CONFIG_H

 /*Options: AHB_DEVIDED_BY_8
            AHB */
#define MSTK_CLK_SOURCE             AHB_DEVIDED_BY_8

/*Options:  ENABLE
            DISABLE*/
#define MSTK_INTERRUPT              DISABLE

/*Options:  ENABLE
            DISABLE*/
#define MSTK_ENABLE                 ENABLE


#endif
