#include "stm32f4xx.h"

void static GPIO_Config(void) {

	////////// LED GPIO PA5 Setup Start //////////
	// 1) enable gpio clock
	RCC->AHB1ENR |= (1<<0);
	// 2) set pin as output
	GPIOA->MODER |= (1<<10);
	// 3) set pin output type
	GPIOA->OTYPER = 0; 
	GPIOA->OSPEEDR = 0;
	GPIOA->PUPDR &= ~(1<<10) | (1<<11);  
	////////// LED GPIO PA5 Setup End //////////

}