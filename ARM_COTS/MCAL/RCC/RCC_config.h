/********************************************************/
/********************************************************/
/*************	    Author: Khalid Arif		*************/
/*************		Layer: MCAL				*************/
/*************		SW: RCC					*************/
/*************		Version: 1.00			*************/
/*************		Date: 1/5/2023			*************/
/********************************************************/
/********************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options:     RCC_HSE
                     
                RCC_HSI        
               RCC_PLL */
#define CPU_CLK_SOURCE          RCC_HSI

//#if CPU_CLK_SOURCE == RCC_HSI
/* Options:    RCC_HSE_CRYSATL
               RCC_HSE_RC */
//#define RCC_HSE         RCC_HSE_CRYSATL
//#endif

/*Options:      RCC_HSE_CRYSATL
                RCC_HSE_RC     
                RCC_HSI*/
#define PLL_SOURCE              RCC_HSI

/* OPTIONS:		SYSCLK_DIVIDE_BY_2
				SYSCLK_DIVIDE_BY_4
				SYSCLK_DIVIDE_BY_8
				SYSCLK_DIVIDE_BY_16
*/
#define AHB_PRESCASLLER			SYSCLK_DEVIDE_BY_8

/* OPTIONS:		APB1_2_DIVIDE_BY_2
				APB1_2_DIVIDE_BY_4
				APB1_2_DIVIDE_BY_8
				APB1_2_DIVIDE_BY_16
*/
#define APB1_PRESCALLER		APB1_2_DIVIDE_BY_8
#define APB2_PRESCALLER		APB1_2_DIVIDE_BY_2



#endif
