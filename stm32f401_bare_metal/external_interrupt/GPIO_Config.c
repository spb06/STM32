#include "stm32f4xx.h"

void GPIO_Config(void) {

	//////////////////////// LED GPIO PA5 Setup Start /////////////////////////
	// 1) enable gpio port A clock
	RCC->AHB1ENR |= (1<<0);
	
	// 2) set pin as output
	GPIOA->MODER |= (1<<10);
	
	// 3) set pin output type
	GPIOA->OTYPER &= ~(1<<5); 
	GPIOA->OSPEEDR |= (1<<11);
	GPIOA->PUPDR &= ~((1<<10) | (1<<11));  
	//////////////////////// LED GPIO PA5 Setup End ////////////////////////////
	
	//////////////////////// Push Button GPIO PC13 Setup Start /////////////////
	RCC->AHB1ENR |= (1<<2);
	GPIOC->MODER |= (0<<26) | (0<<27);
	GPIOC->OTYPER &= ~(1<<13);
	GPIOC->OSPEEDR |= (1<<26);
	GPIOC->PUPDR |= ~((0<<26) | (0<<27));
	//////////////////////// Push Button GPIO PC13 Setup Start /////////////////
	
	//////////////////////// UART-TX PA2 Setup Start ///////////////////////////
	RCC->AHB1ENR |= (1<<0); //enable GPIOA
	GPIOA->MODER |= (1<<5); // alternate function
	GPIOA->OSPEEDR |= ((0<<4)|(1<<5)); // very high speed
	GPIOA->AFR[0] |= (7<<8); // AF7 alternate function for PA2
	//////////////////////// UART-TX PA2 Setup End /////////////////////////////
	
	//////////////////////// UART-RX PA3 Setup Start ///////////////////////////
	RCC->AHB1ENR |= (1<<0);
	GPIOA->MODER |= (1<<7);
	GPIOA->OSPEEDR |= ((0<<6)|(1<<7)); 
	GPIOA->AFR[0] |= (7<<12); // AF7 alternate function for PA3
	//////////////////////// UART-RX PA3 Setup End /////////////////////////////
	
	//////////////////////// I2C_1 SCL - PB8 Setup Start ///////////////////////
	RCC->AHB1ENR |= (0b1<<1);
	GPIOB->MODER |= (0b10<<16); // alternate function
	GPIOB->OTYPER |= (0b1<<8); // open drain
	GPIOB->OSPEEDR |= (0b10<<16); // high speed
	GPIOB->PUPDR |= (0b01<<16); //pull up resistor
	GPIOB->AFR[1] |= (0b0100<<0); 
	//////////////////////// I2C_1 SCL - PB8 Setup End /////////////////////////
	
	//////////////////////// I2C_1 SDA - PB9 Setup Start ///////////////////////
	RCC->AHB1ENR |= (0b1<<1); 
	GPIOB->MODER |= (0b10<<18); // alternate function
	GPIOB->OTYPER |= (0b1<<9); // open drain
	GPIOB->OSPEEDR |= (0b10<<18); // high speed
	GPIOB->PUPDR |= (0b01<<18); //pull up resistor
	GPIOB->AFR[1] |= (0b0100<<4); 
	//////////////////////// I2C_1 SDA - PB9 Setup End /////////////////////////
	
	///////////////////////// ADC - PA1 and PA4 Setup Start ////////////////////
	GPIOA->MODER |= (3<<2); // analog mode for PA 1
	GPIOA->MODER |= (3<<8); // analog mode for PA 4
	///////////////////////// ADC - PA1 Setup Start ////////////////////////////
	
	//////////////////////// External Reset - PA1 Setup Start //////////////////
	RCC->AHB1ENR |= (0b1<<0); 
	GPIOA->MODER &= ~(3<<2); //config as input
	GPIOA->PUPDR |= (1<<2);
	//////////////////////// External Reset - PA1 Setup End ////////////////////	
	
	//////////////////////// SPI1 - NSS - PA15 Setup Start //////////////////////
	RCC->AHB1ENR |= (0b1<<0); // enable clock for GPIO port A
	GPIOA->MODER |= (0b10<<30); // AF mode
	GPIOA->OTYPER &= ~(0b1<<15); // push 0 value to output push pull
	GPIOA->OSPEEDR |= (0b10<<30); // high speed
	GPIOA->PUPDR &= ~(0b11<<30); // push 0 value for no pull up/down
	GPIOA->AFR[1] |= (0b0101<<28); // configuring AF5 alternate function for PA15
	//////////////////////// SPI1 - NSS - PA4 Setup End ////////////////////////
	
	//////////////////////// SPI1 - SCK - PB3 Setup Start //////////////////////
	RCC->AHB1ENR |= (0b1<<1); // enable clock for GPIO port B
	GPIOB->MODER |= (0b10<<6); // AF mode
	GPIOB->OTYPER &= ~(0b1<<3); // push 0 value to output push pull
	GPIOB->OSPEEDR |= (0b10<<6); // high speed
	GPIOB->PUPDR &= ~(0b11<<6); // push 0 value for no pull up/down
	GPIOB->AFR[0] |= (0b0101<<12); // configuring AF5 alternate function for PB3
	//////////////////////// SPI1 - SCK - PB3 Setup End ////////////////////////	
	
	//////////////////////// SPI1 - MISO - PA6 Setup Start /////////////////////
	RCC->AHB1ENR |= (0b1<<0); // enable clock for GPIO port A
	GPIOA->MODER |= (0b10<<12); // AF mode
	GPIOA->OTYPER &= ~(0b1<<6); // push 0 value to output push pull
	GPIOA->OSPEEDR |= (0b10<<12); // high speed
	GPIOA->PUPDR &= ~(0b11<<12); // push 0 value for no pull up/down
	GPIOA->AFR[0] |= (0b0101<<24); // configuring AF5 alternate function for PA6
	//////////////////////// SPI1 - MISO - PA6 Setup End ///////////////////////
	
	//////////////////////// SPI1 - MOSI - PA7 Setup Start /////////////////////
	RCC->AHB1ENR |= (0b1<<0); // enable clock for GPIO port A
	GPIOA->MODER |= (0b10<<14); // AF mode
	GPIOA->OTYPER &= ~(0b1<<7); // push 0 value to output push pull
	GPIOA->OSPEEDR |= (0b10<<14); // high speed
	GPIOA->PUPDR &= ~(0b11<<14); // push 0 value for no pull up/down
	GPIOA->AFR[0] |= (0b0101<<28); // configuring AF5 alternate function for PA7
	//////////////////////// SPI1 - MOSI - PA7 Setup End ///////////////////////	
	
}

