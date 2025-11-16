/*
 * led.c
 *
 *  Created on: 2025. 11. 4.
 *      Author: Hoseung Yoon
 */

#include "led.h"

void LED_Init(hLed *pLed, GPIO_TypeDef *gpio, int pinNum) {
	uint8_t pin;
	pLed->gpio = gpio;
	pLed->PinNum = pinNum;
	pin = pLed->gpio->CR;
	pin |= (1 << pLed->PinNum);	// on

	GPIO_Init(pLed->gpio, pin);
	gpioB_shadow &= 0; // off
}

void LED_On(hLed *pLed) {
	// GPIO_Set(pLed->gpio, pLed->PinNum);
	// uint8_t cur = pLed->gpio->ODR;
	// uint8_t cur_com = cur & 0x0f;
	// uint8_t cur_led = cur & 0xf0;
	// cur_led |= (1 << pLed->PinNum);
	// pLed->gpio->ODR = cur_led | cur_com;

	gpioB_shadow |= (1 << pLed->PinNum);
	
}
void LED_Off(hLed *pLed) {
	// GPIO_Reset(pLed->gpio, pLed->PinNum);
	gpioB_shadow &= ~(1 << pLed->PinNum);
}
void LED_Toggle(hLed *pLed) {
	// GPIO_Toggle(pLed->gpio, pLed->PinNum);
	gpioB_shadow ^= (1 << pLed->PinNum);
}
