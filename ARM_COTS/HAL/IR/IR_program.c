/*****************************************************************************************
 * Author:		        Khalid A. Mohamad
 * Creation Data:		30 May, 2023
 * Version:			    v1.0
 * Compiler:	        GNU ARM-GCC
 * Controller:	        STM32F401CCU6 (32-bit Architecture)
 * Processor:	        Cortex M4 (32-bit Architecture)
 * Layer:			    HAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  30 May, 2023	      Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"



u8 Global_u8StartEdgeFlag = 0;
u32 Global_u32ReceivedFrame[50] = {0};
u8 Global_u8EdgeCounter = 0;
u32 Global_u32Buttondata = 0;

void IR_voidInit(void)
{
    /*RCC Init*/
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_GPIOA);
    /*Pin Mode of Pin A0*/
	MGPIO_voidSetPinMode(MGPIO_PORTA,PIN0,MGPIO_INPUT_MODE);
	MGPIO_voidSetPinPullUpDown(MGPIO_PORTA,PIN0,MGPIO_PULLUP);

    /*Set Init of RGB*/
    MGPIO_voidSetPinMode(MGPIO_PORTA,PIN1,MGPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(MGPIO_PORTA,PIN1,MGPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(MGPIO_PORTA,PIN3,MGPIO_OUTPUT_MODE);

    /*Init STK*/
    MSTK_voidInit();

    /*Setup EXTI Line 0*/
	//MEXTI_voidInit();
	MEXTI_voidChangeSenseMode(MEXTI_LINE0, MEXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(MEXTI_LINE0 ,&IR_voidGetFrame);
    MEXTI_voidEnableINT(MEXTI_LINE0);

	/*Initialize NVIC*/
	MNVIC_voidInit();
    /*Enable EXTI Peripheral In NVIC*/
	MNVIC_voidEnablePeripheralINT(NVIC_EXTI0);

}

void IR_voidGetFrame(void)
{
	if(Global_u8StartEdgeFlag == 0)
	{
		MSTK_voidSetSingleInterval(60000, &IR_voidTakeAction);
		Global_u8StartEdgeFlag = 1;
	}
	else
	{
		/*Get Time*/
		Global_u32ReceivedFrame[Global_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		/*Reset Timer*/
		MSTK_voidResetSysTick();
		//MSTK_voidSetPreLoadValue(1000000);
		MSTK_voidSetSingleInterval(60000, &IR_voidTakeAction);
		/*Increment Edge Counter*/
		Global_u8EdgeCounter++;

	}
}

void IR_voidTakeAction(void)
{
	u8 Local_u8LoopCounter = 0;
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
	{
		if((Global_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000)&&(Global_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
		{
			CLR_BIT(Global_u32Buttondata, Local_u8LoopCounter);
		}
		else
		{
			SET_BIT(Global_u32Buttondata, Local_u8LoopCounter);
		}
	}
	Global_u8StartEdgeFlag = 0;
	Global_u8EdgeCounter = 0;
}

void IR_voidPlay(void)
{
	switch(Global_u32Buttondata)
    {
        case 20://0(
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN1,MGPIO_OUTPUT_HIGH);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN2,MGPIO_OUTPUT_LOW);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN3,MGPIO_OUTPUT_LOW);
            break;
        case 21://1
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN1,MGPIO_OUTPUT_LOW);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN2,MGPIO_OUTPUT_HIGH);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN3,MGPIO_OUTPUT_LOW);
            break;
        
        case 22://2
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN1,MGPIO_OUTPUT_LOW);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN2,MGPIO_OUTPUT_LOW);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN3,MGPIO_OUTPUT_HIGH);
            break;

        case 23://3
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN1,MGPIO_OUTPUT_HIGH);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN2,MGPIO_OUTPUT_HIGH);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN3,MGPIO_OUTPUT_LOW);
            break;

        case 24://4
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN1,MGPIO_OUTPUT_HIGH);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN2,MGPIO_OUTPUT_LOW);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN3,MGPIO_OUTPUT_HIGH);
            break;

        case 25://5
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN1,MGPIO_OUTPUT_LOW);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN2,MGPIO_OUTPUT_HIGH);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN3,MGPIO_OUTPUT_HIGH);
            break;

        case 25://5
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN1,MGPIO_OUTPUT_HIGH);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN2,MGPIO_OUTPUT_HIGH);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN3,MGPIO_OUTPUT_HIGH);
            break;

        case 26://6
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN1,MGPIO_OUTPUT_LOW);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN2,MGPIO_OUTPUT_LOW);
            MGPIO_voidSetPinValue(MGPIO_PORTA,PIN3,MGPIO_OUTPUT_LOW);
            break;
    }
}


