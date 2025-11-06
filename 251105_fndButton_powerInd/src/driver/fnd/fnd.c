/*
 * fnd.c
 *
 *  Created on: 2025. 11. 4.
 *      Author: Hoseung Yoon
 */

#include "fnd.h"
#include "sleep.h"

enum {
	DIGIT_1 = 0,
	DIGIT_10,
	DIGIT_100,
	DIGIT_1000
};

hFnd fnd;
int fndNumber;

void FND_Init() {
	fnd.gpio_seg = GPIOA;
	fnd.gpio_com = GPIOB;
	fnd.digit_1 = GPIO_PIN_0;
	fnd.digit_10 = GPIO_PIN_1;
	fnd.digit_100 = GPIO_PIN_2;
	fnd.digit_1000 = GPIO_PIN_3;
	fnd.gpio_seg->CR = 0xff;
	fnd.gpio_com->CR = 0xff;
}

void FND_SetNumber(int number) {
	fndNumber = number;
}

int FND_GetNumber() {
	return fndNumber;
}

void FND_DispNumber() {
	FND_SetNumber(fndNumber);
	static int fndPos = 0;
	fndPos = (fndPos + 1) % 4;
	FND_AllOff();
	switch (fndPos)
	{
	case DIGIT_1:
		FND_ShowDigit(fndNumber % 10);
		FND_SelDigit(fnd.digit_1);
		break;
	case DIGIT_10:	
		FND_ShowDigit((fndNumber / 10) % 10);
		FND_SelDigit(fnd.digit_10);
		break;
	case DIGIT_100:
		FND_ShowDigit((fndNumber / 100) % 10);
		FND_SelDigit(fnd.digit_100);
		break;
	case DIGIT_1000:
		FND_ShowDigit((fndNumber / 1000) % 10);
		FND_SelDigit(fnd.digit_1000);
		break;
	}
}

void FND_AllOff() {
	// ALL Digit OFF
	GPIO_Set(fnd.gpio_com, fnd.digit_1);
	GPIO_Set(fnd.gpio_com, fnd.digit_10);
	GPIO_Set(fnd.gpio_com, fnd.digit_100);
	GPIO_Set(fnd.gpio_com, fnd.digit_1000);
}

void FND_SelDigit(int digit) {
	// Selected digit ON (active low)
	GPIO_Reset(fnd.gpio_com, digit);  // (same with)	fnd.gpio_com->ODR &= ~(1<<digit);
}

void FND_ShowDigit(int digit) {
	uint8_t segFont[10] = {
		0xC0,	// 0
		0xF9,	// 1
		0xA4,	// 2
		0xB0,	// 3
		0x99,	// 4
		0x92,	// 5
		0x82,	// 6
		0xF8,	// 7
		0x80,	// 8
		0x90	// 9
	};
	GPIO_Write(fnd.gpio_seg, segFont[digit]);

}
