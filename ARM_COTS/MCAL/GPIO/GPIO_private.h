
#ifndef GPIO_PRIVATE
#define GPIO_PRIVATE

typedef struct
{
    volatile u32 GPIOx_MODER;
    volatile u32 GPIOx_OTYPER;
    volatile u32 GPIOx_OSPEEDR;
    volatile u32 GPIOx_PUPDR;
    volatile u32 GPIOx_IDR;
    volatile u32 GPIOx_ODR;
    volatile u32 GPIOx_BSRR;
    volatile u32 GPIOx_LCKR;
    volatile u32 GPIOx_AFRL;
    volatile u32 GPIOx_AFRH;
}GPIO_t;

#define GPIOA_REG           ((volatile GPIO_t *)0x40020000)
#define GPIOB_REG           ((volatile GPIO_t *)0x40020400)
#define GPIOC_REG           ((volatile GPIO_t *)0x40020800)

#define MGPIO_INPUT         0b00
#define MGPIO_OUTPUT        0b01
#define MGPIO_AF            0b10
#define MGPIO_Analog        0b11

#define PUSH_PULL           0
#define OPEN_DRAIN          1

#define LOW_SPEED           0b00
#define MEDIUM_SPEED        0b01
#define HIGH_SPEED          0b10
#define VERY_SPEED          0b11

#define FLOAT               0b00
#define PULL_UP             0b01
#define PULL_DOWN           0b10

#define HIGH                1
#define LOW                 0

#endif