/*
 * btn.h
 *
 *  Created on: 2025. 11. 5.
 *      Author: kccistc
 */

#ifndef SRC_DRIVER_BTN_BTN_H_
#define SRC_DRIVER_BTN_BTN_H_
#include <stdint.h>
#include "../../device/gpio/gpio.h"
#include "sleep.h"

#define BTN_0	GPIO_PIN_0  // T18 (BTN_UP)
#define BTN_1	GPIO_PIN_1  // W19 (BTN_LEFT)
#define BTN_2	GPIO_PIN_2  // T17 (BTN_RIGHT)
#define BTN_3	GPIO_PIN_3  // U17 (BTN_DOWN)

#define BTN_GPIO 	GPIOC

typedef struct {
    GPIO_TypeDef *gpio;
    int pinNum;
    int prevState;
} hBtn;

enum {
    RELEASED = 0,
    PUSHED = 1
} BtnState;

enum {
    ACT_PUSHED = 0,
    ACT_RELEASED,
    NO_ACT,
} BtnAction;


void BTN_Init(hBtn *pBtn, GPIO_TypeDef *gpio, uint8_t pinNum);
void BTN_Read(hBtn *pBtn, uint8_t *state);
int Button_getState(hBtn *pBtn);


#endif /* SRC_DRIVER_BTN_BTN_H_ */
