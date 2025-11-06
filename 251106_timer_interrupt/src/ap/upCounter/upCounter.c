#include "upCounter.h"

enum {
    STOP,
    RUN_UP,
    RUN_DOWN,
    CLEAR
};

int counter = 0;
int upCounterState = STOP;

hLed upLed;
hLed downLed;

hBtn upBtn;      // UP (U)
hBtn clearBtn;   // CLEAR (L)
hBtn stopBtn;    // STOP (R)
hBtn downBtn;    // DOWN (D)


void initUpCounter() {
    FND_Init();
    LED_Init(&upLed, LED_GPIO, LED_1);
    LED_Init(&downLed, LED_GPIO, LED_2);
    BTN_Init(&upBtn, BTN_GPIO, BTN_0);
    BTN_Init(&clearBtn, BTN_GPIO, BTN_1);
    BTN_Init(&stopBtn, BTN_GPIO, BTN_2);
    BTN_Init(&downBtn, BTN_GPIO, BTN_3);
}

void exeUpCounter() {
    switch (upCounterState)
    {
    case STOP:
        // stopCounter();
        LED_On(&downLed);
        if (Button_getState(&stopBtn) == ACT_PUSHED)
            upCounterState = RUN_UP;
        else if (Button_getState(&upBtn) == ACT_PUSHED)
            upCounterState = RUN_UP;
        else if (Button_getState(&downBtn) == ACT_PUSHED)
            upCounterState = RUN_DOWN;
        else if (Button_getState(&clearBtn) == ACT_PUSHED)
            upCounterState = CLEAR;
        break;
    case RUN_UP:
        runUpCounter();
        if (Button_getState(&downBtn) == ACT_PUSHED)
            upCounterState = RUN_DOWN;
        else if (Button_getState(&stopBtn) == ACT_PUSHED)
            upCounterState = STOP;
        break;
    case RUN_DOWN:
        runDownCounter();
        if (Button_getState(&upBtn) == ACT_PUSHED)
            upCounterState = RUN_UP;
        else if (Button_getState(&stopBtn) == ACT_PUSHED)
            upCounterState = STOP;
        break;
    case CLEAR:
        clearUpCounter();
        upCounterState = STOP;
        break;
    default:
        break;
    }
}

void stopCounter() {
    static uint32_t prevTime = 0;
    uint32_t currentTime = millis();
    if (currentTime - prevTime < 1) return;
    prevTime = currentTime;

    FND_SetNumber(counter);
    LED_On(&downLed);
}

void runDownCounter() {
    static uint32_t prevTime = 0;
    uint32_t currentTime = millis();
    
    // non-blocking delay for FND update
    // Update every 100 ms
    if (currentTime - prevTime < 100) return;
    counter = --counter < 0 ? 9999 : counter;
    prevTime = currentTime;
    FND_SetNumber(counter);
    LED_Toggle(&upLed);
    LED_Off(&downLed);
}
void runUpCounter() {
    static uint32_t prevTime2 = 0;
    uint32_t currentTime2 = millis();
    
    // non-blocking delay for FND update
    // Update every 100 ms
    if (currentTime2 - prevTime2 < 100) return;
    counter = ++counter % 10000; // Wrap around at 10000
    prevTime2 = currentTime2;
    FND_SetNumber(counter);    
    LED_Toggle(&upLed);
    LED_Off(&downLed);
}

void clearUpCounter() {
    counter = 0;
    FND_SetNumber(counter);
    LED_Off(&downLed);
}