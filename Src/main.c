#include <stdint.h>
#include <stm32f446xx.h>
#include "main.h"

uint32_t numSend = 0;
uint32_t numRcv = 0;

int main(void)
{
	/* GPIO Init */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= OUTPUT_MODE<<10;


	/* USART2 Init */
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	GPIOA->MODER |= ALT_MODE<<4;
	GPIOA->AFR[0] |= 7<<8;
	USART2->BRR  = 139;
	USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;
	USART2->CR1 |= USART_CR1_UE;

	/* SPI2 Init */
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= ALT_MODE<<4 | ALT_MODE<<2;
	GPIOB->MODER |= ALT_MODE<<20;
	GPIOC->AFR[0] |= (5<<8) | (7<<4);
	GPIOB->AFR[1] |= (5<<8);
	SPI2->CR1 |= 0b011<<3;
	SPI2->CR1 |= SPI_CR1_CPHA | SPI_CR1_CPOL;
	SPI2->CR1 |= SPI_CR1_SSM  | SPI_CR1_SSI;
	SPI2->CR1 |= SPI_CR1_MSTR;
	SPI2->CR1 |= SPI_CR1_SPE;

	/* ADC Init */
	// RCC ADC1
	/*ADCCLK for all ADC in APB2
	RCC_APB2ENR for individual ADC
	ALIGN bit in the ADC_CR2
	ADC1->CR2 |= ADC_CR2_ADON;

	Select channel
	ADC1->CR2 |= ADC_CR2_SWSTART;	// Start
	EOC (End of conversion)
	ADC_DR has the result*/


	// Lire ADC temperature, et Voie AN1.
	// Envoyer sur le SPI MOSI > MISO
	// Envoyer sur l'USART2.
	// Toggle LED



	while(1){
		for(uint32_t i = 0 ; i<100000; i++);

		/* LED PA2 */
		GPIOA->ODR ^= 1<<5;

		/* SPI2 */
		SPI2->DR = (numSend++)%26+'a';
		while( (SPI2->SR & SPI_SR_TXE)==0 );
		while( (SPI2->SR & SPI_SR_RXNE)==0);
		numRcv = SPI2->DR;

		/* USART2 */
		USART2->DR = numRcv;
		while( (USART2->SR & USART_SR_TXE)==0 );
	}
}

