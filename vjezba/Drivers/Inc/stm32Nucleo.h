/*
 * stm32Nucleo.h
 *
 *  Created on: Sep 24, 2021
 *      Author: emirc
 */

#ifndef INC_STM32NUCLEO_H_
#define INC_STM32NUCLEO_H_

#include "stdint.h"

//WRITTING BASE ADDRESS C MACROS
#define FLASH_BASEADDR                       0x08000000
#define SRAM1_BASEADDR                       0X20000000
#define ROM_BASEADDR

//defining base address of buses, on bus we can find different pheripherals like gpios i2c
#define APB1_PERIPH_BASE                     0X40000000
#define APB2_PERIPH_BASE                     0X40010000
#define AHB_PERIPH_BASE                      0X40020000
#define IOPORT_BASE                          0X50000000

//define base addresses hangging on different buses
//
#define GPIOA_BASSEADDR                      IOPORT_BASE
#define GPIOB_BASSEADDR                      (IOPORT_BASE+0x0400)
#define GPIOC_BASSEADDR                      (IOPORT_BASE+0x0800)

#define I2C1_BASEADDR                        (APB1_PERIPH_BASE+0X5400)
#define I2C2_BASEADDR                        (APB1_PERIPH_BASE+0X5800)

//pheripheral register definition structures
typedef struct{
 volatile uint32_t MODER;    //GPIO port mode register address offset 0x00
 volatile uint32_t OTYPER;    //                                offset 0x04
 volatile uint32_t OSPEEDR;   //                                offset 0x08
 volatile uint32_t PUPDR;     //                                offset 0x0C
 volatile uint32_t IDR;
 volatile uint32_t ODR;
 volatile uint32_t BSRR;
 volatile uint32_t LCKR;

}GPIO_RegDef_t;

typedef struct{
volatile uint32_t CR;        //address offset 0x00
volatile uint32_t ICSCR;     // 0x04
volatile uint32_t CFR;        //address offset 0x04
volatile uint32_t RESERVED;  //address offset 0x08
volatile uint32_t CFGR;      //Address offset 0x0C
volatile uint32_t CIER;      //address offset 0x10
volatile uint32_t CIFR;      //address offset 0x14
volatile uint32_t CICR;      //address offset 0x18
volatile uint32_t IOPRSTR;   //address offset 0x1c
volatile uint32_t AHBRSTR;   //address offset 0x10
volatile uint32_t APB2RSTR;       //address offset 0x24
volatile uint32_t APB1RSTR;       //address offset 0x28
volatile uint32_t IOPENR;       //address offset 0x2C
volatile uint32_t AHBENR;
volatile uint32_t APB2ENR;
volatile uint32_t APB1ENR;
//there are more register, but I defined those that I need
}RCC_RegDef_t;

//pheripheral definition

#define GPIOA        ((GPIO_RegDef_t*)(GPIOA_BASSEADDR))
//#define GPIOB  (GPIO_RegDef_t(GPIOA_BASSEADDR)) //OVA NIJE TACNA

#define RCC          ((RCC_RegDef_t*)(0X50000000))


//CLOCK ENABLE MACROS FOR GPIOx
#define GPIOA_PERIPHERAL_CLK_EN()      (RCC->IOPENR |=(1<<0))
#define GPIOB_PERIPHERAL_CLK_EN()      (RCC->IOPENR |=(1<<1))
#define GPIOC_PERIPHERAL_CLK_EN()      (RCC->IOPENR |=(1<<2))

//CLOCK ENABLE FOR I2C PHERIPHERALS
#define I2C1_PCLK_EN()                 (RCC->APB1ENR |=(1<<21))
#define I2C2_PCLK_EN()                 (RCC->APB1ENR |=(1<<22))


//CLOCK DISABLE MACROS FOR GPIOx
#define GPIOA_PERIPHERAL_CLK_DIS()      (RCC->IOPENR &=~(1<<0))
#define GPIOB_PERIPHERAL_CLK_DIS()      (RCC->IOPENR &=~(1<<1))
#define GPIOC_PERIPHERAL_CLK_DIS()      (RCC->IOPENR &=~(1<<2))

//CLOCK DISABLE FOR I2C PHERIPHERALS
#define I2C1_PCLK_DIS()                 (RCC->APB1ENR &=~(1<<21))
#define I2C2_PCLK_DIS()                 (RCC->APB1ENR &=~(1<<22))

#define ENABLE                        1
#define DISABLE                       0



#endif /* INC_STM32NUCLEO_H_ */
