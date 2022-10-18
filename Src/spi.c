#include <stdint.h>
#include <stm32f446xx.h>
#include "main.h"
#include "spi.h"


void SPI2_Init(void){
	/* Clock Init */
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

	/* GPIO Init */
	GPIOC->MODER |= ALT_MODE<<4 | ALT_MODE<<2;
	GPIOB->MODER |= ALT_MODE<<20;
	GPIOC->AFR[0] |= (5<<8) | (7<<4);
	GPIOB->AFR[1] |= (5<<8);

	/* SPI2 Init */
	SPI2->CR1 |= 0b011<<3;						// SCK
	SPI2->CR1 |= SPI_CR1_CPHA | SPI_CR1_CPOL;	// SPI Mode
	SPI2->CR1 |= SPI_CR1_SSM  | SPI_CR1_SSI;	// Slave Select
	SPI2->CR1 |= SPI_CR1_MSTR;					// Master
	SPI2->CR1 |= SPI_CR1_SPE;					// Enalbe
}


void SPI2_Transmit(void){

}


void SPI2_Receive(void){

}
