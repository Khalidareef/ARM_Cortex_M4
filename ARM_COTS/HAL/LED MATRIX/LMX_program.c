/*****************************************************************************************
 * Author:				  Khalid A. Mohamad
 * Creation Data:		14 May, 2023
 * Version:				  v1.0
 * Compiler:			  GNU ARM-GCC
 * Controller:		  STM32F401CCU6 (32-bit Architecture)
 * Processor:			  Cortex M4 (32-bit Architecture)
 * Layer:				    HAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  14 May, 2023	Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LMX_interface.h"
#include "LMX_private.h"
#include "LMX_config.h"

void HLEDMAT_voidInit(void)
{
    /*Init Rows Pins To Output Pins*/
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R0_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R1_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R2_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R3_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R4_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R5_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R6_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R7_PIN, 0b01);

    MGPIO_voidSetPinOutputType(HLEDMAT_ROWS_PORT, HLEDMAT_R0_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROWS_PORT, HLEDMAT_R1_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROWS_PORT, HLEDMAT_R2_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROWS_PORT, HLEDMAT_R3_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROWS_PORT, HLEDMAT_R4_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROWS_PORT, HLEDMAT_R5_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROWS_PORT, HLEDMAT_R6_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROWS_PORT, HLEDMAT_R7_PIN, 0b00);

    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROWS_PORT, HLEDMAT_R0_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROWS_PORT, HLEDMAT_R1_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROWS_PORT, HLEDMAT_R2_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROWS_PORT, HLEDMAT_R3_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROWS_PORT, HLEDMAT_R4_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROWS_PORT, HLEDMAT_R5_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROWS_PORT, HLEDMAT_R6_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROWS_PORT, HLEDMAT_R7_PIN, 0b00);
    
    /*Init Col Pins To Output Pins*/
    MGPIO_voidSetPinMode(HLEDMAT_COLOMNS_PORT, HLEDMAT_C0_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_COLOMNS_PORT, HLEDMAT_C1_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_COLOMNS_PORT, HLEDMAT_C2_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_COLOMNS_PORT, HLEDMAT_C3_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_COLOMNS_PORT, HLEDMAT_C4_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_COLOMNS_PORT, HLEDMAT_C5_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_COLOMNS_PORT, HLEDMAT_C6_PIN, 0b01);
    MGPIO_voidSetPinMode(HLEDMAT_COLOMNS_PORT, HLEDMAT_C7_PIN, 0b01);

    MGPIO_voidSetPinOutputType(HLEDMAT_COLOMNS_PORT, HLEDMAT_C0_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_COLOMNS_PORT, HLEDMAT_C1_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_COLOMNS_PORT, HLEDMAT_C2_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_COLOMNS_PORT, HLEDMAT_C3_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_COLOMNS_PORT, HLEDMAT_C4_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_COLOMNS_PORT, HLEDMAT_C5_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_COLOMNS_PORT, HLEDMAT_C6_PIN, 0b00);
    MGPIO_voidSetPinOutputType(HLEDMAT_COLOMNS_PORT, HLEDMAT_C7_PIN, 0b00);

    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COLOMNS_PORT, HLEDMAT_C0_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COLOMNS_PORT, HLEDMAT_C1_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COLOMNS_PORT, HLEDMAT_C2_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COLOMNS_PORT, HLEDMAT_C3_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COLOMNS_PORT, HLEDMAT_C4_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COLOMNS_PORT, HLEDMAT_C5_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COLOMNS_PORT, HLEDMAT_C6_PIN, 0b00);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COLOMNS_PORT, HLEDMAT_C7_PIN, 0b00);

    voidDisableAllColumns();
    
}

void HLEDMAT_voidDisplay(u8 * Copy_pu8Data) //Data = Data of Rows
{
    u8 Local_u8Bit = 0;
    u8 Local_u8ColumnsIndex = 0;
    u8 Local_u8RowsIndex = 0;
    static u8 RowsArray[8] = {  HLEDMAT_R0_PIN,
                                HLEDMAT_R1_PIN,
                                HLEDMAT_R2_PIN,
                                HLEDMAT_R3_PIN,
                                HLEDMAT_R4_PIN,
                                HLEDMAT_R5_PIN,
                                HLEDMAT_R6_PIN,
                                HLEDMAT_R7_PIN};
                        
    static u8 ColmnsArray[8] = {  HLEDMAT_C0_PIN,
                                  HLEDMAT_C1_PIN,
                                  HLEDMAT_C2_PIN,
                                  HLEDMAT_C3_PIN,
                                  HLEDMAT_C4_PIN,
                                  HLEDMAT_C5_PIN,
                                  HLEDMAT_C6_PIN,
                                  HLEDMAT_C7_PIN};

    for(Local_u8ColumnsIndex = 0; Local_u8ColumnsIndex < 8; Local_u8ColumnsIndex++)
    {
      voidDisableAllColumns();
      for(Local_u8RowsIndex = 0; Local_u8RowsIndex < 8; Local_u8RowsIndex++) 
      {
        Local_u8Bit = GET_BIT(Copy_pu8Data[Local_u8ColumnsIndex],Local_u8RowsIndex);
        MGPIO_voidSetPinValue(HLEDMAT_ROWS_PORT, RowsArray[Local_u8RowsIndex],Local_u8Bit);
      }
      MGPIO_voidSetPinValue(HLEDMAT_COLOMNS_PORT,ColmnsArray[Local_u8ColumnsIndex],LOW);
      MSTK_voidSetBusyWait(2500);   //2.5ms
    }
    
}

/*Disable All Columns*/
static void voidDisableAllColumns(void)
{
    MGPIO_voidSetPinValue(HLEDMAT_COLOMNS_PORT, HLEDMAT_C0_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLOMNS_PORT, HLEDMAT_C1_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLOMNS_PORT, HLEDMAT_C2_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLOMNS_PORT, HLEDMAT_C3_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLOMNS_PORT, HLEDMAT_C4_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLOMNS_PORT, HLEDMAT_C5_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLOMNS_PORT, HLEDMAT_C6_PIN, HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COLOMNS_PORT, HLEDMAT_C7_PIN, HIGH);
}
