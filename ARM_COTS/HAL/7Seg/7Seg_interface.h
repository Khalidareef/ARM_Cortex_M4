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
 * v1.0		  12 May, 2023	Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/

#ifndef SEVSEG_INTERFACE_H
#define SEVSEG_INTERFACE_H

typedef struct {

    u8 SSG_PORT;
    u16 PINS[7];

}SSG_t;

#define COM_ANODE       1
#define COM_CATHOD      0

void SSG_voidInit(SSG_t *SSGobj);
void SSG_voidSendNumber(SSG_t *SSGobj, u8 Copy_u8Number, u8 Copy_u8Mode);


#endif
