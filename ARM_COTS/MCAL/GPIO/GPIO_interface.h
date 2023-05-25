

#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE

#define MGPIO_PORTA         0
#define MGPIO_PORTB         1
#define MGPIO_PORTC         2

#define PIN0                0 
#define PIN1                1 
#define PIN2                2 
#define PIN3                3 
#define PIN4                4 
#define PIN5                5 
#define PIN6                6 
#define PIN7                7 
#define PIN8                8 
#define PIN9                9 
#define PIN10               10
#define PIN11               11
#define PIN12               12
#define PIN13               13
#define PIN14               14
#define PIN15               15 


#define GPIO_INPUT_MODE             0b00
#define GPIO_OUTPUT_MODE            0b01
#define GPIO_ALT_FUNC_MODE          0b10
#define GPIO_ANALOG_MODE            0b11

#define OUTPUT_PUSH_PULL            0
#define OUTPUT_OPEN_DRAIN           1

#define OUTPUT_LOW_SPEED            0b00
#define OUTPUT_MEDIUM_SPEED         0b01
#define OUTPUT_HIGH_SPEED           0b10
#define OUTPUT_VERY_SPEED           0b11

#define INPUT_FLOAT                 0b00
#define INPUT_PULL_UP               0b01
#define INPUT_PULL_DOWN             0b10

#define GPIO_HIGH                  	1
#define GPIO_LOW                    0

void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Mode);
void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputType);
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed);
void MGPIO_voidSetConnnectionType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8ConnnectionType);
u8 MGPIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
void MGPIO_voidSetPinValueODR(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);

#endif
