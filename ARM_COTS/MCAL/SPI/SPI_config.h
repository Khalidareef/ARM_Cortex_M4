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
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define MSPI1_MOSI_PORTPIN		MGPIO_PORTA,PIN7
#define MSPI1_MISO_PORTPIN		MGPIO_PORTA,PIN6
#define MSPI1_SCK_PORTPIN		MGPIO_PORTA,PIN5
#define MSPI1_NSS_PORTPIN		MGPIO_PORTA,PIN4

#endif
