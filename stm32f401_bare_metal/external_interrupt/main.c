// External Interrupt Driver

#include "stm32f4xx.h"
#include "Sys_Clock_Config.h"
#include "GPIO_Config.h"
#include "Delay.h"
#include "uart.h"
#include "i2c.h"
#include "ADC.h"
#include "EXT_interrupt.h"

uint16_t ADC_VAL[2] = {0,0}; // store ADC data

int flag = 0; // flag for ext interrupt 1

int count = 0; // count for ext interrupt 1

int main(void) {
	
	Sys_Clock_Config();
	TIM3_Config();
	GPIO_Config();
	//USART2_config();
	//I2C_config();
	//I2C_start();
	//I2C_address(0x4E);
	//I2C_write(0x01); // light up first LED
	//I2C_stop();
	//ADC_init();
	//ADC_enable();
	//MPU6050_init();
	Interrupt_config();

	while(1) {
		if (flag) {
			Delay_ms(1000);
			count++;
			flag = 0;
		}
		//MPU6050_read_accel();
		
		/*
		ADC_start(1);
		ADC_wait_for_conv();
		ADC_VAL[0] = ADC_get_val();
		
		ADC_start(4);
		ADC_wait_for_conv();
		ADC_VAL[1] = ADC_get_val();
		*/

		//USART2_send_char('G');
		//USART2_send_string("Hello World\n");
		//uint8_t data = USART2_get_char();
		//USART2_send_char(data);

		/*
		// if button is not pressed, light LED
		if (GPIOC->IDR){ 						
			GPIOA->BSRR |= (1<<5);
			Delay_ms(500);
			GPIOA->BSRR |= (1<<21);
			Delay_ms(500);
		}
		*/
		
	}
	
}	