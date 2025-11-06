#include "powerInd.h"

hLed powerLed;
void initPowerInd() {
    LED_Init(&powerLed, LED_GPIO, LED_0);
}
void dispPowerInd() {
    static uint32_t prevTime = 0;
    uint32_t currentTime = millis();

    if (currentTime - prevTime < 500) return; // 500 milliseconds interval
    prevTime = currentTime; // update previous time (non-blocking)
    LED_Toggle(&powerLed);
}