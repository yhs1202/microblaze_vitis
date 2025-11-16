/*
 * gpio.c
 *
 *  Created on: 2025. 11. 4.
 *      Author: Hoseung Yoon
 */

#include "gpio.h"

void GPIO_Init(GPIO_TypeDef *gpio, uint8_t dir) {
	gpio->CR = dir;
}
void GPIO_Write(GPIO_TypeDef *gpio, uint8_t data) {
	gpio->ODR = data;
}
void GPIO_WriteLow4(GPIO_TypeDef *gpio, uint8_t data) {
	gpio->ODR = (gpio->ODR & 0xF0) | (data & 0x0F);
}
void GPIO_WriteHigh4(GPIO_TypeDef *gpio, uint8_t data) {
	gpio->ODR = (gpio->ODR & 0x0F) | (data & 0xF0);
}
uint8_t GPIO_Read(GPIO_TypeDef *gpio) {
	return gpio->IDR;
}
int GPIO_ReadPin(GPIO_TypeDef *gpio, uint8_t pinNum) {
	return (gpio->IDR >> pinNum) & 0x01;
}
void GPIO_Set(GPIO_TypeDef *gpio, uint8_t pinNum) {
	gpio->ODR |= (1<<pinNum);
}
void GPIO_Reset(GPIO_TypeDef *gpio, uint8_t pinNum) {
	gpio->ODR &= ~(1<<pinNum);
}
void GPIO_Toggle(GPIO_TypeDef *gpio, uint8_t pinNum) {
	gpio->ODR ^= (1<<pinNum);
}


volatile uint8_t gpioB_shadow = 0xFF;
void GPIOB_Shadow_Write() {
	GPIOB->ODR = gpioB_shadow;
}
