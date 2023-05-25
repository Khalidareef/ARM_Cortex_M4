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

#ifndef NVIC_CINFIG_H
#define NVIC_CINFIG_H

/*Options:  GRP_4_SUB_0_BITS
            GRP_3_SUB_1_BITS
            GRP_2_SUB_2_BITS
            GRP_1_SUB_3_BITS
            GRP_0_SUB_4_BITS*/

#define NVIC_GBP_SUB_DISTRIBUTION       GRP_2_SUB_2_BITS

#endif