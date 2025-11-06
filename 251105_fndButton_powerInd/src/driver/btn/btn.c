#include "btn.h"

void BTN_Init(hBtn *pBtn, GPIO_TypeDef *gpio, uint8_t pinNum) {
    uint8_t pinMode;
    pBtn->gpio = gpio;
    pBtn->pinNum = pinNum;
    pBtn->prevState = RELEASED;

    pinMode = pBtn->gpio->CR;
    pinMode &= ~(1 << pBtn->pinNum); // off

    GPIO_Init(pBtn->gpio, pinMode);
}

void BTN_Read(hBtn *pBtn, uint8_t *state) {
    int data = GPIO_ReadPin(pBtn->gpio, pBtn->pinNum);
    if (data) {
        *state = 0; // Button not pressed
    } else {
        *state = 1; // Button pressed
    }
}

int Button_getState(hBtn *pBtn) {
    int curState = GPIO_ReadPin(pBtn->gpio, pBtn->pinNum);

    if ((curState == PUSHED) & (pBtn->prevState == RELEASED)) {
        usleep(5000); // Debounce delay
        pBtn->prevState = PUSHED;
        return ACT_PUSHED;
    } else if ((curState == RELEASED) && (pBtn->prevState == PUSHED)) {
        usleep(5000); // Debounce delay
        pBtn->prevState = RELEASED;
        return ACT_RELEASED;
    }
    return NO_ACT;
}