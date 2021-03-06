/*
 * stm32_gpiox.c
 *
 *  Created on: Sep 25, 2021
 *      Author: emirc
 */

#include "stm32_gpiox.h"
#include <stdint.h>


void GPIO_PheripheralClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDis ){

	if(EnOrDis == ENABLE){

		if(pGPIOx==GPIOA){
			GPIOA_PERIPHERAL_CLK_EN();
		}
	//	else if (pGPIOx==GPIOB){
		//	GPIOB_PERIPHERAL_CLK_EN();
	 //	}
	}

		else{
		if(pGPIOx==GPIOA){
			GPIOA_PERIPHERAL_CLK_DIS();
		}
		// if (pGPIOx==GPIOB){
		//	 GPIOB_PERIPHERAL_CLK_DIS();
		// }

		}

}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	//1 configure the mode for gpio pin
	uint32_t temp=0;
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNum));
	pGPIOHandle->pGPIOx->MODER |=temp; // in physical register use |=
	temp=0;
	//2 configure speed
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNum));
	pGPIOHandle->pGPIOx->OSPEEDR |=temp;
	temp=0;

	//3 configure pull up pull down
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNum));
		pGPIOHandle->pGPIOx->PUPDR |=temp;
		temp=0;

	//4 configure output type
		temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType<<(pGPIOHandle->GPIO_PinConfig.GPIO_PinNum));
		pGPIOHandle->pGPIOx->OTYPER |=temp;
		temp=0;


}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){


}

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNum){
	uint8_t value;
	value=(uint8_t) ((pGPIOx->IDR >> PinNum) & 0x00000001); //stavit cemo nas pin number na prvi bit i ovo cemo mask
	return value; // will be zero or one

}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint8_t value;
	value=(uint16_t) pGPIOx->IDR; //ovdje cemo iscitati svih 16 bita, znaci od 0 do 15
	return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNum, uint8_t Value){
	if(Value==GPIO_PIN_SET){
		pGPIOx->ODR |=(1<<PinNum); //put your bit on 1
	}
	else {
		pGPIOx->ODR &=~ (1<<PinNum); // clear bit
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t Value){
	pGPIOx->ODR=Value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNum){
	pGPIOx->ODR ^= (1<<PinNum); //xor operation will toggle pin
}

void GPIO_IRQCofig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t ENorDi){

}
void GPIO_IRQHandling(uint8_t PinNum){

}



