/*****************************************************************************************
 * Author:				Khalid A. Mohamad
 * Creation Data:		12 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				HAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  14 May, 2023	Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/

#ifndef LEDMATRIX_INTERFACE_H
#define LEDMATRIX_INTERFACE_H

void HLEDMAT_voidInit(void);
void HLEDMAT_voidDisplay(u8 * Copy_u8Data);


#endif