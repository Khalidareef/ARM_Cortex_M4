/*****************************************************************************************
 * Author:				Khalid A. Mohamad
 * Creation Data:		12 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				HAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  12 May, 2023	Khalid A. Mohamad		  Initial Creation
 *****************************************************************************************/

#ifndef LEDMATRIX_CONFIG_H
#define LEDMATRIX_CONFIG_H

//u8 RowArray[16] ={HLEDMAT_R0_PIN,.........}  make counter in init function, 2steps

#define HLEDMAT_ROWS_PORT                   MGPIO_PORTA
    
#define HLEDMAT_R0_PIN                      MGPIO_PIN0
#define HLEDMAT_R1_PIN                      MGPIO_PIN1
#define HLEDMAT_R2_PIN                      MGPIO_PIN2
#define HLEDMAT_R3_PIN                      MGPIO_PIN3
#define HLEDMAT_R4_PIN                      MGPIO_PIN4
#define HLEDMAT_R5_PIN                      MGPIO_PIN5
#define HLEDMAT_R6_PIN                      MGPIO_PIN6
#define HLEDMAT_R7_PIN                      MGPIO_PIN7

#define HLEDMAT_COLOMNS_PORT                MGPIO_PORTB

#define HLEDMAT_C0_PIN                      MGPIO_PIN0
#define HLEDMAT_C1_PIN                      MGPIO_PIN1
#define HLEDMAT_C2_PIN                      MGPIO_PIN2
#define HLEDMAT_C3_PIN                      MGPIO_PIN3
#define HLEDMAT_C4_PIN                      MGPIO_PIN4
#define HLEDMAT_C5_PIN                      MGPIO_PIN5
#define HLEDMAT_C6_PIN                      MGPIO_PIN6
#define HLEDMAT_C7_PIN                      MGPIO_PIN7
/*
#define HLEDMAT_R0_PIN      MGPIO_PINA,MGPIO_PIN0
#define HLEDMAT_R1_PIN      MGPIO_PINA,MGPIO_PIN1
#define HLEDMAT_R2_PIN      MGPIO_PINA,MGPIO_PIN2
#define HLEDMAT_R3_PIN      MGPIO_PINA,MGPIO_PIN3
#define HLEDMAT_R4_PIN      MGPIO_PINA,MGPIO_PIN4
#define HLEDMAT_R5_PIN      MGPIO_PINA,MGPIO_PIN5
#define HLEDMAT_R6_PIN      MGPIO_PINA,MGPIO_PIN6
#define HLEDMAT_R7_PIN      MGPIO_PINA,MGPIO_PIN7

#define HLEDMAT_C0_PIN      MGPIO_PINB,MGPIO_PIN0
#define HLEDMAT_C1_PIN      MGPIO_PINB,MGPIO_PIN1
#define HLEDMAT_C2_PIN      MGPIO_PINB,MGPIO_PIN2
#define HLEDMAT_C3_PIN      MGPIO_PINB,MGPIO_PIN3
#define HLEDMAT_C4_PIN      MGPIO_PINB,MGPIO_PIN4
#define HLEDMAT_C5_PIN      MGPIO_PINB,MGPIO_PIN5
#define HLEDMAT_C6_PIN      MGPIO_PINB,MGPIO_PIN6
#define HLEDMAT_C7_PIN      MGPIO_PINB,MGPIO_PIN7
*/
#endif