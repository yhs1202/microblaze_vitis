#include "btnLEDToggle.h"

hBtn button;
hLed downLed;

void initBtnLEDToggle() {
    BTN_Init(&button, BTN_GPIO, BTN_1); // Initialize button on BTN_LEFT
    LED_Init(&downLed, LED_GPIO, LED_2); // Initialize LED_2 for toggle
}

void runBtnLEDToggle() {
    // uint8_t btnState;
    // static uint32_t prevTime = 0;
    // uint32_t currentTime = millis();

    // BTN_Read(&button, &btnState);
    // if (currentTime - prevTime < 100) return; // 100 milliseconds interval
    // prevTime = currentTime;
    // if (btnState == 0) { // Button pressed
    //     // Wait for button release
    //     while (1) {
    //         BTN_Read(&button, &btnState);
    //         if (btnState == 1) { // Button released
    //             LED_Toggle(&downLed);
    //             break; // Exit loop on button release
    //         }
    //     }
    // }

    if (Button_getState(&button) == ACT_RELEASED) {
        LED_Toggle(&downLed);
    }
}
