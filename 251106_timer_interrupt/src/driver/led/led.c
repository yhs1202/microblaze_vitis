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
}

void LED_On(hLed *pLed) {
	GPIO_Set(pLed->gpio, pLed->PinNum);
}
void LED_Off(hLed *pLed) {
	GPIO_Reset(pLed->gpio, pLed->PinNum);
}
void LED_Toggle(hLed *pLed) {
	GPIO_Toggle(pLed->gpio, pLed->PinNum);
}
