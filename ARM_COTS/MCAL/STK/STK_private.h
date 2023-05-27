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

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;

}STK_t;

#define     STK     ((volatile STK_t *)0xE000E010)

#define AHB_DEVIDED_BY_8    0
#define AHB                 1

#define ENABLE				1
#define DISABLE				0

#define CTRL_ENABLE          0
#define CTRL_TICKINT         1
#define CTRL_CLKSOURCE       2
#define CTRL_COUNTFLAG       16

#define SINGLE_INTERVAL     0
#define PERIODIC_INTERVAL   1

#define NULL		0


#endif
