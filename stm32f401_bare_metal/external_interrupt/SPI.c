#include "stm32f4xx.h"

void SPI_config(void) {
	// todo: disable JTDI to enable PA15
	
	RCC->APB2ENR |= (0b1<<12); // enable clock for SPI1
	SPI1->CR1 &= ~(0b1<<6); // disable SPI to config setttings 
	SPI1->CR1 |= (0b001<<3); // fpclk/2 = 84Mhz/2 = 42Mhz
	SPI1->CR1 &= ~(0b1<<0); // first clcok transition = first data capture edge
	SPI1->CR1 &= ~(0b1<<1); // CK to 0 when idle
	SPI1->CR1 &= ~(0b1<<11); // 8-bit data
	SPI1->CR1 |= (0b1<<7); // LSB transmitted first
	SPI1->CR2 |= (0b1<<2); // enable SSOE since SPI is in master mode
	SPI1->CR2 |= (0b1<<4); // enable TI mode
	SPI1->CR1 |= (0b1<<2); // enable master mode
	SPI1->CR1 |= (0b1<<6); // enable SPI
}

void SPI_write(uint8_t SPI1_write_data) {
	// while TXE is 0 (not empty) - wait for TXE buffer to be set (it is empty when set)
	while (!(SPI1->SR & (1<<1))); 
	SPI1->DR = SPI1_write_data; 
	while (!(SPI1->SR & (1<<1))); 
}

void SPI_read(void) {
	uint8_t read_buffer = SPI1->DR;
	// wait until receiver buffer is empty (RXNE=0)
	while(!(SPI1->SR & (1<<0)));
}

void SPI_stop(void) {
	SPI1->CR1 &= ~(0b1<<6); // disable SPI
}
