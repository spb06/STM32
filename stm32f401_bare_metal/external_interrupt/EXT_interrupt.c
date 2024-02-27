#include "stm32f4xx.h"

void Interrupt_config(void) {
	
	// enable SYSCONFIG clock
	RCC->APB2ENR |= (1<<14); 
	
	// configure EXTI reg in SYSCONFIG
	SYSCFG-> EXTICR[0] &= ~(0xf<<4);
	
	// disable mask for PA1
	EXTI->IMR |= (1<<1); 
	
	// enable rising edge trigger - trigger when button is released
	EXTI->RTSR |= (1<<1);
	
	// disable falling edge trigger
	EXTI->RTSR &= ~(1<<1);
	
	// set interrupt priority - 1 is highest priority
	NVIC_SetPriority(EXTI1_IRQn, 1);
	
	//enable interrupt
	NVIC_EnableIRQ(EXTI1_IRQn);
}	

extern int flag_EXTI;

void EXT1_IRQHandler(void) {
	
	// check which pin triggered interrupt
	if (EXTI->PR & (1<<1)) {
		EXTI->PR |= (1<<1); // clear interrupt pending bit
		flag_EXTI = 1; 
	}
	
}
