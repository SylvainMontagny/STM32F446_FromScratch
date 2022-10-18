#include <stdint.h>
#include <stm32f446xx.h>
#include "main.h"
#include "usart.h"


void USART2_Init(void){
	/* USART2 Init */
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	GPIOA->MODER |= ALT_MODE<<4;
	GPIOA->AFR[0] |= 7<<8;
	USART2->BRR  = 139;
	USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;
	USART2->CR1 |= USART_CR1_UE;

}


void USART2_Transmit(void){

}


void USART2_Receive(void){

}
