/*****************************************************************************************
 * Author:				Khalid A. Mohamad
 * Creation Data:		4 Jun, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  4 May, 2023	Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(void);
u8 MSPI_u8TrancieveSynchronous(u8 Copy_u8Data, u8 * Copy_pu8ReceivedData);

#endif
