#include <stdint.h>
#include "stm32f446xx.h"
#include "timer.h"

uint32_t SystemCoreClock = 16000000;
uint32_t ticks = 0;

void SYSTICK_Init(void){
	SysTick_Config(SystemCoreClock / 1000);
}

void SYSTICK_Delay(uint32_t Delay)
{
	  uint32_t tickstart = SYSTICK_Get();

	  while((SYSTICK_Get() - tickstart) < Delay);
}

uint32_t SYSTICK_Get(void){
	return ticks;
}

// Get MCO HSE to PA8 (D7)
// the MCO1PRE[2:0] and MCO1[1:0]

