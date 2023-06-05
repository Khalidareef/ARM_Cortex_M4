/*****************************************************************************************
 * Author:				Khalid A. Mohamad
 * Creation Data:		01 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v2.0		  26 May, 2023	Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/

#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE

/**************************************************************************************************************
*                                               Public Macros
**************************************************************************************************************/
/*Port Name Macros*/
#define MGPIO_PORTA                  0
#define MGPIO_PORTB                  1
#define MGPIO_PORTC                  2
/*Pin Name Macros*/      
#define PIN0                         0 
#define PIN1                         1 
#define PIN2                         2 
#define PIN3                         3 
#define PIN4                         4 
#define PIN5                         5 
#define PIN6                         6 
#define PIN7                         7 
#define PIN8                         8 
#define PIN9                         9 
#define PIN10                        10
#define PIN11                        11
#define PIN12                        12
#define PIN13                        13
#define PIN14                        14
#define PIN15                        15 
/*Pin Mode Macros*/
#define MGPIO_INPUT		             0b00
#define MGPIO_OUTPUT           		 0b01
#define MGPIO_AF			         0b10
#define MGPIO_ANALOG_MODE            0b11
/*Pin Output Types Macros*/
#define MGPIO_PUSH_PULL              0
#define MGPIO_OPEN_DRAIN             1
/*Output Speed Macros*/
#define MGPIO_LOW_SPEED              0b00
#define MGPIO_MEDIUM_SPEED           0b01
#define MGPIO_HIGH_SPEED             0b10
#define MGPIO_VHIGH_SPEED            0b11
/*Pull Up/Down Resistor Macros*/     
#define MGPIO_FLOAT                  0b00
#define MGPIO_PULLUP                 0b01
#define MGPIO_PULLDOWN               0b10
/*Output State Macros*/  
#define MGPIO_OUTPUT_HIGH            1
#define MGPIO_OUTPUT_LOW             0

#define MGPIO_AF07     0b0111
#define MGPIO_AF05     0b0101


void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode);
void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputType);
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed);
void MGPIO_voidSetPinPullUpDown(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8ConnnectionType);
u8 MGPIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
void MGPIO_voidSetPortMode(u8 Copy_u8PortName, u8 Copy_u8PortModeVal);
void MGPIO_voidSetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue);
void MGPIO_voidSetAlternative(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8AltNum);
#endif
