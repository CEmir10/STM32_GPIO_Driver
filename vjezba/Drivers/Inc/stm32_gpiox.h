/*
 * stm32_gpiox.h
 *
 *  Created on: Sep 25, 2021
 *      Author: emirc
 */

#ifndef INC_STM32_GPIOX_H_
#define INC_STM32_GPIOX_H_

#include "stm32Nucleo.h"

// This is configuration structure of GPIO pin
typedef struct{
	uint8_t GPIO_PinNum;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMoode;

}GPIO_PinConfig_t;

//lets create handle structure

typedef struct{
	//pointer to hold the base address of GPIO pheripheral
	GPIO_RegDef_t *pGPIOx; //this holds the base address of gpio port to wich pin belongs
	GPIO_PinConfig_t GPIO_PinConfig; //this holds GPIO pin configuration settings

}GPIO_Handle_t;

//@GPIO pin numbers

#define GPIO_PIN_NUM_0           0
#define GPIO_PIN_NUM_1           1
#define GPIO_PIN_NUM_2           2
#define GPIO_PIN_NUM_3           3
#define GPIO_PIN_NUM_4           4
#define GPIO_PIN_NUM_5           5
#define GPIO_PIN_NUM_6           6
#define GPIO_PIN_NUM_7           7
#define GPIO_PIN_NUM_8           8
#define GPIO_PIN_NUM_9           9
#define GPIO_PIN_NUM_10          10
#define GPIO_PIN_NUM_11          11
#define GPIO_PIN_NUM_12          12
#define GPIO_PIN_NUM_13          13
#define GPIO_PIN_NUM_14          14
#define GPIO_PIN_NUM_15          15



//@GPIO pin modes
//GPIO possible modes of pin

#define GPIO_MODE_IN             0
#define GPIO_MODE_OUT            1
#define GPIO_MODE_ALTFN          2
#define GPIO_MODE_ANALOG         3

//GPIO pin possible output speeds
#define GPIO_OP_TYPE_PP          0
#define GPIO_OP_TYPE_OD          1

//GPIO pin possible output speed
#define GPIO_SPEED_LOW           0
#define GPIO_SPEED_MEDIUM        1
#define GPIO_SPEED_FAST          2
#define GPIO_SPEED_HIGH          3

//GPIO port pull-up/pull-down
#define GPIO_NO_PUPD             0
#define GPIO_PU                  1
#define GPIO_PD                  2


# define GPIO_PIN_SET            1







void GPIO_Init(GPIO_Handle_t *pGPIOHandle); // port and pin
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);    //port

void GPIO_PheripheralClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDis );

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNum);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNum, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNum);

void GPIO_IRQCofig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t ENorDi);
void GPIO_IRQHandling(uint8_t PinNum); //from which pin interrupt is triggered








#endif /* INC_STM32_GPIOX_H_ */
