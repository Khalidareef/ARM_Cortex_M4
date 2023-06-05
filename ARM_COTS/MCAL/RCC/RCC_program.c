/********************************************************/
/********************************************************/
/*************	    Author: Khalid Arif		*************/
/*************		Layer: MCAL				*************/
/*************		SW: RCC					*************/
/*************		Version: 1.00			*************/
/*************		Date: 1/5/2023			*************/
/********************************************************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInit(void)
{
#if CPU_CLK_SOURCE == RCC_HSE
	/*Enable HSE*/
	SET_BIT(RCC -> CR, 16);
	//CLR_BIT(RCC -> CR, 18);
	/*Select HSE as System CLK*/
	SET_BIT(RCC -> CFGR, 0);
	CLR_BIT(RCC -> CFGR, 1);

	//#elif CPU_CLK_SOURCE == RCC_HSE_RC
	/*Enable HSE*/
	//SET_BIT(RCC -> CR, 16);
	//SET_BIT(RCC -> CR, 18);
	/*Select HSE as System CLK*/
	//SET_BIT(RCC -> CFGR, 0);
	//CLR_BIT(RCC -> CFGR, 1);

#elif CPU_CLK_SOURCE == RCC_HSI
	/*Enable HSI*/
	SET_BIT(RCC -> CR, 0);
	/*Select HSI as System CLK*/
	CLR_BIT(RCC -> CFGR, 0);
	CLR_BIT(RCC -> CFGR, 1);

#elif CPU_CLK_SOURCE == RCC_PLL
	#if PLL_SOURCE == RCC_HSE
		/*Enable HSE*/
		SET_BIT(RCC -> CR, 16);
		/*Select HSE As PLL Source*/
		SET_BIT(RCC -> PLLCFGR, 22);
		/*Enable PLL*/
		SET_BIT(RCC -> CR, 24);
		/*Select PLL As System Clock (CPU CLK Source)*/
		CLR_BIT(RCC -> CFGR, 0);
		SET_BIT(RCC -> CFGR, 1);

	#elif PLL_SOURCE == RCC_HSI
		/*Enable HSI*/
		SET_BIT(RCC -> CR, 0);
		/*Select HSI As PLL Source*/
		CLR_BIT(RCC -> PLLCFGR, 22);
		/*Enable PLL*/
		SET_BIT(RCC -> CR, 24);
		/*Select PLL As System Clock (CPU CLK Source)*/
		CLR_BIT(RCC -> CFGR, 0);
		SET_BIT(RCC -> CFGR, 1);
	#else
	#error "RCC PLL_SOURCE Configuration Error"
	#endif

#else
#error "RCC CPU_CLK_SOURCE Configuration Error"
#endif

#if AHB_PRESCASLLER == SYSCLK_DEVIDE_BY_2
    (RCC -> CFGR) &= 0xFFFFFF0F;
    (RCC -> CFGR ) |= AHB_PRESCASLLER << 4;
#endif
}

void MRCC_voidEnablePeripheralClock(u8 Copy_u8PerioheralBus, u8 Copy_u8erioheralID)
{
	switch(Copy_u8PerioheralBus)
	{
	case RCC_AHB1:
		SET_BIT(RCC -> AHB1ENR, Copy_u8erioheralID);    break;

	case RCC_AHB2:
		SET_BIT(RCC -> AHB2ENR, Copy_u8erioheralID);    break;

	case RCC_APB1:
		SET_BIT(RCC -> APB1ENR, Copy_u8erioheralID);    break;

	case RCC_APB2:
		SET_BIT(RCC -> APB2ENR, Copy_u8erioheralID);    break;

	default      :  /*Error*/                       break;

	}
}

void MRCC_voidDisablePeripheralClock(u8 Copy_u8PerioheralBus, u8 Copy_u8erioheralID)
{
	switch(Copy_u8PerioheralBus)
	{
	case RCC_AHB1:
		CLR_BIT(RCC -> AHB1ENR, Copy_u8erioheralID);    break;

	case RCC_AHB2:
		CLR_BIT(RCC -> AHB2ENR, Copy_u8erioheralID);    break;

	case RCC_APB1:
		CLR_BIT(RCC -> APB1ENR, Copy_u8erioheralID);    break;

	case RCC_APB2:
		CLR_BIT(RCC -> APB2ENR, Copy_u8erioheralID);    break;
		
	default      :  /*Error*/                       break;

	}
}
