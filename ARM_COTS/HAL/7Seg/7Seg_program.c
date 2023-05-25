/*****************************************************************************************
 * Author:				Khalid A. Mohamad
 * Creation Data:		12 May, 2023
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

 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "7Seg_interface.h"
#include "7Seg_private.h"
#include "7Seg_config.h"

void SSG_voidInit(SSG_t *SSGobj)
{
        for (u8 Local_u8ItrPin=0; Local_u8ItrPin < 7; Local_u8ItrPin++)
        {
            MGPIO_voidSetPinMode(SSGobj -> SSG_PORT, SSGobj -> PINS[Local_u8ItrPin], 0b01);
            MGPIO_voidSetPinOutputType(SSGobj -> SSG_PORT, SSGobj -> PINS[Local_u8ItrPin], 0);
            MGPIO_voidSetPinOutputSpeed(SSGobj -> SSG_PORT, SSGobj -> PINS[Local_u8ItrPin], 0);
        }

}

void SSG_voidSendNumber(SSG_t *SSGobj, u8 Copy_u8Number, u8 Copy_u8Mode)
{
    //u8 LocalArr_u8OfBit[7]={0};
    if(Copy_u8Mode == COM_ANODE)
    {
        for (u8 Local_u8ItrPin=0; Local_u8ItrPin<7; Local_u8ItrPin++)
        {
            MGPIO_voidSetPinValue(SSGobj -> SSG_PORT, SSGobj -> PINS[Local_u8ItrPin], ~(GET_BIT(Arr_u8OfNum[Copy_u8Number],Local_u8ItrPin)));
        }
    }
    else if (Copy_u8Mode == COM_CATHOD)
    {
       for (u8 Local_u8ItrPin=0; Local_u8ItrPin<7; Local_u8ItrPin++)
        {
            MGPIO_voidSetPinValue(SSGobj -> SSG_PORT, SSGobj -> PINS[Local_u8ItrPin], GET_BIT(Arr_u8OfNum[Copy_u8Number],Local_u8ItrPin));
        } 
    }
    else
    {
        /*Return Error*/
    }

}
