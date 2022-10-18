#include <stdint.h>
#include <stm32f446xx.h>
#include "main.h"
#include "gpio.h"
#include "spi.h"
#include "usart.h"
#include "adc.h"

uint32_t spiSend = 0;
uint32_t spiRcv = 0;
uint32_t adcValue=0;

int main(void)
{
	GPIO_Init();
	SPI2_Init();
	USART2_Init();
	ADC_Init();

	while(1){
		for(uint32_t i = 0 ; i<100000; i++);

		/* LED PA2 */
		GPIOA->ODR ^= 1<<5;

		/* SPI2 */
		SPI2->DR = (spiSend++)%26+'a';
		while( (SPI2->SR & SPI_SR_TXE)==0 );
		while( (SPI2->SR & SPI_SR_RXNE)==0 );
		spiRcv = SPI2->DR;

		/* USART2 */
		USART2->DR = spiRcv;
		while( (USART2->SR & USART_SR_TXE)==0 );

		/* ADC1 IN0 */
		ADC1->CR2 |= ADC_CR2_SWSTART;
		while( (ADC1->SR & ADC_SR_EOC) == 0 );
		adcValue = ADC1->DR;

	}
}

