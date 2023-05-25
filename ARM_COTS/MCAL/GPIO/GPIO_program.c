#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Mode)
{
    switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
            //GPIOA_REG -> GPIOA_MODER &=  ~ (0b11 << (Copy_u8PinNumber*2));
            /*We not need to CLR because it Equal 0b00 by default*/
            GPIOA_REG -> GPIOx_MODER |= Copy_u8Mode << (Copy_u8PinNumber*2);
        break;

        case MGPIO_PORTB:
            GPIOB_REG -> GPIOx_MODER |= Copy_u8Mode << (Copy_u8PinNumber*2);
        break;

        case MGPIO_PORTC:
            GPIOC_REG -> GPIOx_MODER |= Copy_u8Mode << (Copy_u8PinNumber*2);
        break;

        default:        /*Error*/       break;
    }
}

void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputType)
{
    switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
            if (Copy_u8OutputType == OUTPUT_PUSH_PULL)
            {
                CLR_BIT(GPIOA_REG -> GPIOx_OTYPER, Copy_u8PinNumber);
            }
            else if (Copy_u8OutputType == OUTPUT_OPEN_DRAIN)
            {
                SET_BIT(GPIOA_REG -> GPIOx_OTYPER, Copy_u8PinNumber);
            }
            else
            {/*Return Error*/}
            break;
        case MGPIO_PORTB:
            if (Copy_u8OutputType == OUTPUT_PUSH_PULL)
            {
                CLR_BIT(GPIOB_REG -> GPIOx_OTYPER, Copy_u8PinNumber);
            }
            else if (Copy_u8OutputType == OUTPUT_OPEN_DRAIN)
            {
                SET_BIT(GPIOB_REG -> GPIOx_OTYPER, Copy_u8PinNumber);
            }
            else
            {/*Return Error*/}
            break;
        case MGPIO_PORTC:
            if (Copy_u8OutputType == OUTPUT_PUSH_PULL)
            {
                CLR_BIT(GPIOC_REG -> GPIOx_OTYPER, Copy_u8PinNumber);
            }
            else if (Copy_u8OutputType == OUTPUT_OPEN_DRAIN)
            {
                SET_BIT(GPIOC_REG -> GPIOx_OTYPER, Copy_u8PinNumber);
            }
            else
            {/*Return Error*/}
            break;
        default:        /*Error*/       break;
    }
}

void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed)
{
    switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
            GPIOA_REG -> GPIOx_OSPEEDR |= Copy_u8OutputSpeed << (Copy_u8PinNumber*2);
            break;

        case MGPIO_PORTB:
            GPIOB_REG -> GPIOx_OSPEEDR |= Copy_u8OutputSpeed << (Copy_u8PinNumber*2);
            break;

        case MGPIO_PORTC:
            GPIOC_REG -> GPIOx_OSPEEDR |= Copy_u8OutputSpeed << (Copy_u8PinNumber*2);
            break;
        default:        /*Error*/       break;

    } 
}

void MGPIO_voidSetConnnectionType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8ConnnectionType)
{
    switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
            GPIOA_REG -> GPIOx_PUPDR |= Copy_u8ConnnectionType << (Copy_u8PinNumber*2);
            break;

        case MGPIO_PORTB:
            GPIOB_REG -> GPIOx_PUPDR |= Copy_u8ConnnectionType << (Copy_u8PinNumber*2);
            break;

        case MGPIO_PORTC:
            GPIOC_REG -> GPIOx_PUPDR |= Copy_u8ConnnectionType << (Copy_u8PinNumber*2);
            break;
        default:        /*Error*/       break;

    } 
}

u8 MGPIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    u8 Local_u8ReturnValue;
    
   switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
           Local_u8ReturnValue = GET_BIT(GPIOA_REG -> GPIOx_IDR, Copy_u8PinNumber);
           break;
        case MGPIO_PORTB:
           Local_u8ReturnValue = GET_BIT(GPIOB_REG -> GPIOx_IDR, Copy_u8PinNumber);
           break;
        case MGPIO_PORTC:
           Local_u8ReturnValue = GET_BIT(GPIOC_REG -> GPIOx_IDR, Copy_u8PinNumber);
           break;
        
        default:        /*Error*/       break;
    }  
    return Local_u8ReturnValue;
}

void MGPIO_voidSetPinValueODR(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    switch(Copy_u8PortName)
    {
        case MGPIO_PORTA:
            if (Copy_u8PinValue == GPIO_LOW)
            {
                CLR_BIT(GPIOA_REG -> GPIOx_ODR, Copy_u8PinNumber);
            }
            else if (Copy_u8PinValue == GPIO_HIGH)
            {
                SET_BIT(GPIOA_REG -> GPIOx_ODR, Copy_u8PinNumber);
            }
            else
            {/*Return Error*/}
        break;
        case MGPIO_PORTB:
            if (Copy_u8PinValue == GPIO_LOW)
            {
                CLR_BIT(GPIOB_REG -> GPIOx_ODR, Copy_u8PinNumber);
            }
            else if (Copy_u8PinValue == GPIO_HIGH)
            {
                SET_BIT(GPIOB_REG -> GPIOx_ODR, Copy_u8PinNumber);
            }
            else
            {/*Return Error*/}
        break;
        case MGPIO_PORTC:
            if (Copy_u8PinValue == GPIO_LOW)
            {
                CLR_BIT(GPIOC_REG -> GPIOx_ODR, Copy_u8PinNumber);
            }
            else if (Copy_u8PinValue == GPIO_HIGH)
            {
                SET_BIT(GPIOC_REG -> GPIOx_ODR, Copy_u8PinNumber);
            }
            else
            {/*Return Error*/}
        break;
        default:        /*Error*/       break;
    } 
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    
}
