/*****************************************************************************************
 * Author:				Khalid A. Mohamad
 * Creation Data:		4 Jun, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				HAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  4 Jun, 2023	Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/

#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

#define HTFT_A0_PORT_PIN		MGPIO_PORTA, PIN0
 //#define HTFT_CS_PORT_PIN		MGPIO_PORTA, PIN2
#define HTFT_RST_PORT_PIN		MGPIO_PORTA, PIN1

#endif
