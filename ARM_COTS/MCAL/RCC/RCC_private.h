/********************************************************/
/********************************************************/
/*************	    Author: Khalid Arif		*************/
/*************		Layer: MCAL				*************/
/*************		SW: RCC					*************/
/*************		Version: 1.00			*************/
/*************		Date: 1/5/2023			*************/
/********************************************************/
/********************************************************/



#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

//#define RCC_BASE_ADDRESS        0x40023800
//#define RCC_CR          *((volatile u32 *)(RCC_BASE_ADDRESS + 0x00))        //RCC Control Register

/*GPIO PINS*/

#define AHB1RSTR_GPIOARST        0
#define AHB1RSTR_GPIOBRST        1
#define AHB1RSTR_GPIOCRST        2


#define AHB1ENR_GPIOAEN         0       
#define AHB1ENR_GPIOBEN         1
#define AHB1ENR_GPIOCEN         2


#define AHB1LPENR_GPIOALPEN     0
#define AHB1LPENR_GPIOBLPEN     1
#define AHB1LPENR_GPIOCLPEN     2


typedef struct
{
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1[2]; 
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Reserved8[2];
    volatile u32 DCKCFGR;

}RCC_t;


#define RCC     ((volatile RCC_t*)0x40023800)

/*CLK Types*/

#define RCC_HSE                 0
#define RCC_HSI                 1
#define RCC_PLL                 2

#define RCC_HSE_CRYSATL         0
#define RCC_HSE_RC              1

/*prescaller for APB1 & APB2*/
#define APB1_2_DIVIDE_BY_2		0b100
#define APB1_2_DIVIDE_BY_4		0b101
#define APB1_2_DIVIDE_BY_8		0b110
#define APB1_2_DIVIDE_BY_16		0b111

/*prescaller for AHB
  SYSCLK OPTIONS: HSI - HSE - PLL*/
#define SYSCLK_DEVIDE_BY_2		0b1000
#define SYSCLK_DEVIDE_BY_4		0b1001
#define SYSCLK_DEVIDE_BY_8		0b1010
#define SYSCLK_DEVIDE_BY_16		0b1011




#endif
