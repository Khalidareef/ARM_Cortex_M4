/********************************************************/
/********************************************************/
/*************	    Author: Khalid Arif		*************/
/*************		Layer: MCAL				*************/
/*************		SW: RCC					*************/
/*************		Version: 1.00			*************/
/*************		Date: 1/5/2023			*************/
/********************************************************/
/********************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB1        0
#define RCC_AHB2        1
#define RCC_APB1        2
#define RCC_APB2        3

#define RCC_GPIOA       0
#define RCC_GPIOB       1
#define RCC_GPIOC       2

#define RCC_SPI1		12

void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClock(u8 Copy_u8PerioheralBus, u8 Copy_u8erioheralID);
void MRCC_voidDisablePeripheralClock(u8 Copy_u8PerioheralBus, u8 Copy_u8erioheralID);

#endif
