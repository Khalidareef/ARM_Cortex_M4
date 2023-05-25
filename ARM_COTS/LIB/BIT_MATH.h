/*****************************************************
 * Author:              Khalid A.Mohamad
 * Creatation Date:     22 MAR, 2023
 * Version:             v1.0
 * Compiler:            GNU GCC
******************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H
/***************** Function Like Micro To Mainpulate Over Specific Bit **********/

#define SET_BIT(REG,BIT)	((REG) |= (1<<BIT))
#define	CLR_BIT(REG,BIT)	(REG &= (~(1<<BIT)))
#define	TOG_BIT(REG,BIT)	(REG ^= (1<<BIT))
#define	GET_BIT(REG,BIT)	((REG >> BIT) & 0x01)

#define SET_2BIT(REG,BIT1,BIT2)		REG| = (1<<BIT1)|(1<<BIT2)
#define CLR_2BIT(REG,BIT1,BIT2)		REG& = ~((1<<BIT1)|(1<<BIT2))

/***************** Function Like Micro To Mainpulate Over Register ************/

#define	SET_REG(REG,VALUE)	(REG = VALUE)
#define	GET_REG(REG)		(REG)
#define	CLR_REG(REG)		(REG = 0x00)



#endif
