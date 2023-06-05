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

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


/**
* @brief A Function to set a specific pin mode on specific port
* @param    PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC> 
*           PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
*           PinMode     :   A macro for Pin Mode <MGPIO_INPUT, MGPIO_OUTPUT, MGPIO_AF, MGPIO_ANALOG>
*
* @note     None
*
* @return   void
*/
void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode)
{
    switch(Copy_u8PortName)
    {
        /*Checking The Port Name*/
        case MGPIO_PORTA:
            //GPIOA_REG -> GPIOA_MODER &=  ~ (0b11 << (Copy_u8PinNumber*2));
            /*We don't not need to CLR because it Equal 0b00 by default*/
            GPIOA -> MODER |= Copy_u8PinMode << (Copy_u8PinNumber * PIN_BITS_OFFSET);
            break;

        case MGPIO_PORTB:
            GPIOB -> MODER |= Copy_u8PinMode << (Copy_u8PinNumber * PIN_BITS_OFFSET);
            break;

        case MGPIO_PORTC:
            GPIOC -> MODER |= Copy_u8PinMode << (Copy_u8PinNumber * PIN_BITS_OFFSET);
            break;

        default:        /*Error*/       break;
    }
}

/**
* @brief A Function to set the Pin Output Type
* @param    PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC> 
*           PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
*           PinMode     :   A macro for Pin Output Type <MGPIO_PUSH_PULL, MGPIO_OPEN_DRAIN>
*
* @note     None
*
* @return   void
*/
void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputType)
{

    switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
            if (Copy_u8OutputType == MGPIO_PUSH_PULL)
            {
                CLR_BIT(GPIOA -> OTYPER, Copy_u8PinNumber);
            }
            else if (Copy_u8OutputType == MGPIO_OPEN_DRAIN)
            {
                SET_BIT(GPIOA -> OTYPER, Copy_u8PinNumber);
            }
            else
            {/*Return Error*/}
            break;
        case MGPIO_PORTB:
            if (Copy_u8OutputType == MGPIO_PUSH_PULL)
            {
                CLR_BIT(GPIOB -> OTYPER, Copy_u8PinNumber);
            }
            else if (Copy_u8OutputType == MGPIO_OPEN_DRAIN)
            {
                SET_BIT(GPIOB -> OTYPER, Copy_u8PinNumber);
            }
            else
            {/*Return Error*/}
            break;
        case MGPIO_PORTC:
            if (Copy_u8OutputType == MGPIO_PUSH_PULL)
            {
                CLR_BIT(GPIOC -> OTYPER, Copy_u8PinNumber);
            }
            else if (Copy_u8OutputType == MGPIO_OPEN_DRAIN)
            {
                SET_BIT(GPIOC -> OTYPER, Copy_u8PinNumber);
            }
            else
            {/*Return Error*/}
            break;
        default:        /*Error*/       break;
    }
}

/**
* @brief A Function to set the Output Pin Speed
* @param    PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC> 
*           PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
*           PinMode     :   A macro for Pin Output Speed <MGPIO_LOW_SPEED, MGPIO_MEDIUM_SPEED, MGPIO_HIGH_SPEED, MGPIO_VHIGH_SPEED>
*
* @note     None
*
* @return   void
*/
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed)
{
    switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
            GPIOA -> OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;

        case MGPIO_PORTB:
            GPIOB -> OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;

        case MGPIO_PORTC:
            GPIOC -> OSPEEDR |= (Copy_u8OutputSpeed << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        default:        /*Error*/       break;

    } 
}

/**
 * @brief A Function to set the pull up/down resistor for an input pin
 *
 * @param   PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
 *          PullUpDownState:A macro for Pull Up/Down Resistor State <MGPIO_FLOAT, MGPIO_PULLUP, MGPIO_PULLDOWN>
 *
 *
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPinPullUpDown(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8ConnnectionType)
{
    switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
            GPIOA -> PUPDR |= (Copy_u8ConnnectionType << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;

        case MGPIO_PORTB:
            GPIOB -> PUPDR |= (Copy_u8ConnnectionType << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;

        case MGPIO_PORTC:
            GPIOC -> PUPDR |= (Copy_u8ConnnectionType << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        default:        /*Error*/       break;

    } 
}

/**
 * @brief A Function that read a signal from an input pin
 *
 * @param   PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
 *
 * @note  None
 *
 * @return u8: The value of the input signal
 */
u8 MGPIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    u8 Local_u8ReturnValue;
    
   switch(Copy_u8PortName)
    {
    case MGPIO_PORTA:
        /*Assign The Pin Value For The Local Var*/
       Local_u8ReturnValue = GET_BIT(GPIOA -> IDR, Copy_u8PinNumber);
       break;

    case MGPIO_PORTB:
        /*Assign The Pin Value For The Local Var*/
       Local_u8ReturnValue = GET_BIT(GPIOB -> IDR, Copy_u8PinNumber);
       break;

    case MGPIO_PORTC:
       /*Assign The Pin Value For The Local Var*/
       Local_u8ReturnValue = GET_BIT(GPIOC -> IDR, Copy_u8PinNumber);
       break;
    
    default:        /*Error*/       break;
    } 
    /*Return The Piin Value*/ 
    return Local_u8ReturnValue;
}

/**
 * @brief A Function to Set the Value for Output Pin
 *
 * @param   PortName    :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PinNumber   :   A macro for Pin Number <MGPIO_PIN0, MGPIO_PIN1, ..., MGPIO_PIN15>
 *          PinValue    :   A macro for Pin Output Value <MGPIO_OUTPUT_LOW, MGPIO_OUTPUT_HIGH>
 *
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    /*Check The Port Name*/
    switch(Copy_u8PortName)
    {
    case MGPIO_PORTA:
        /*Check For The Pin Value*/
        switch(Copy_u8PinValue)
        {
        case MGPIO_OUTPUT_LOW:
            /*Set The Output Pin To Be Low, Atomic Reset*/
            GPIOA -> BSRR = 1 << (Copy_u8PinNumber + BSRR_PIN_OFFSET);
            break;
        case MGPIO_OUTPUT_HIGH:
            /*Set The Output Pin To Be High, Atomic Set*/
            GPIOA -> BSRR = 1 << (Copy_u8PinNumber);
            break;
        }
        break;
    case MGPIO_PORTB:
        switch(Copy_u8PinValue)
        {
        case MGPIO_OUTPUT_LOW:
            GPIOB -> BSRR = 1 << (Copy_u8PinNumber + BSRR_PIN_OFFSET);
            break;
        case MGPIO_OUTPUT_HIGH:
            GPIOB -> BSRR = 1 << (Copy_u8PinNumber);
            break;
        }
        break;
    case MGPIO_PORTC:
        switch(Copy_u8PinValue)
        {
        case MGPIO_OUTPUT_LOW:
            GPIOC -> BSRR = 1 << (Copy_u8PinNumber + BSRR_PIN_OFFSET);
            break;
        case MGPIO_OUTPUT_HIGH:
            GPIOC -> BSRR = 1 << (Copy_u8PinNumber);
            break;
        }
        break;
    }
}

/**
 * @brief A Function that set a specific mode for a whole port
 *
 * @param   PortName        :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PortModeValue   :   Mode value to be set for a port
 *
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPortMode(u8 Copy_u8PortName, u8 Copy_u8PortModeVal)
{
  switch(Copy_u8PortName)
  {
    case MGPIO_PORTA:
        /*Set The Specific Mode Value To Mode Register*/
        GPIOA -> MODER  = Copy_u8PortModeVal;
        break;

    case MGPIO_PORTB:
        /*Set The Specific Mode Value To Mode Register*/
        GPIOB -> MODER  = Copy_u8PortModeVal;
        break;

    case MGPIO_PORTC:
        /*Set The Specific Mode Value To Mode Register*/
        GPIOC -> MODER  = Copy_u8PortModeVal;
        break;
  }  
}

/**
 * @brief A Function that set a specific output value for a whole port
 *
 * @param   PortName         :   A macro for Port Name <MGPIO_PORTA, MGPIO_PORTB, MGPIO_PORTC>
 *          PortValue        :   Output value to be set for a port.
 * @note  None
 *
 * @return void
 */
void MGPIO_voidSetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
  switch(Copy_u8PortName)
  {
    case MGPIO_PORTA:
        /*Set The Specific Value To ODR Register*/
        GPIOA -> ODR  = Copy_u8PortValue;
        break;       
    case MGPIO_PORTB:
        /*Set The Specific Value To ODR Register*/
        GPIOB -> ODR  = Copy_u8PortValue;
        break;       
    case MGPIO_PORTC:
        /*Set The Specific Value To ODR Register*/
        GPIOC -> ODR  = Copy_u8PortValue;
        break;
  }    
}


void MGPIO_voidSetAlternative(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8AltNum)
{
    switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
            if(Copy_u8PinNum <= 7)
            {
                GPIOA->AFRL &= ~(0b1111 << (Copy_u8PinNum * 4));
                GPIOA->AFRL |= (Copy_u8AltNum << (Copy_u8PinNum * 4));
            }

            else if(Copy_u8PinNum <= 15)
            {
                GPIOA->AFRH &= ~(0b1111 << ((Copy_u8PinNum - 8) * 4));
                GPIOA->AFRH |= (Copy_u8AltNum << ((Copy_u8PinNum - 8) * 4));
            }
            break;
        
        case MGPIO_PORTB:
            if(Copy_u8PinNum <= 7)
            {
                GPIOB->AFRL &= ~(0b1111 << (Copy_u8PinNum * 4));
                GPIOB->AFRL |= (Copy_u8AltNum << (Copy_u8PinNum * 4));
            }

            else if(Copy_u8PinNum <= 15)
            {
                GPIOB->AFRH &= ~(0b1111 << ((Copy_u8PinNum - 8) * 4));
                GPIOB->AFRH |= (Copy_u8AltNum << ((Copy_u8PinNum - 8) * 4));
            }
            break;
        
        case MGPIO_PORTC:
            if(Copy_u8PinNum <= 7)
            {
                GPIOC->AFRL &= ~(0b1111 << (Copy_u8PinNum * 4));
                GPIOC->AFRL |= (Copy_u8AltNum << (Copy_u8PinNum * 4));
            }

            else if(Copy_u8PinNum <= 15)
            {
                GPIOC->AFRH &= ~(0b1111 << ((Copy_u8PinNum - 8) * 4));
                GPIOC->AFRH |= (Copy_u8AltNum << ((Copy_u8PinNum - 8) * 4));
            }
            break;
    }
}
