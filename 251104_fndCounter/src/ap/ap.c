/*
 * ap.c
 *
 *  Created on: 2025. 11. 4.
 *      Author: Hoseung Yoon
 */

#include "ap.h"
#include "sleep.h"

hLed powerLed;
hLed upLed;
hLed downLed;


void ap_main() {

	LED_Init(&powerLed, LED_GPIO, LED_0);
	LED_Init(&upLed, LED_GPIO, LED_1);
	LED_Init(&downLed, LED_GPIO, LED_2);
	FND_Init();

	int counter = 0;
	while (1) {
//		 LED_On(&powerLed);
//		 usleep(100000);
//		 LED_On(&upLed);
//		 LED_On(&upLed);
//		 usleep(100000);
//		 LED_On(&downLed);
//		 usleep(100000);
//
//		 LED_Off(&powerLed);
//		 usleep(100000);
//		 LED_Off(&upLed);
//		 usleep(100000);
//		 LED_Off(&downLed);
//		 usleep(100000);

		for (int i = 0; i < 100; i++)
			FND_DispNumber(counter++);

		LED_On(&powerLed);
		LED_On(&upLed);
		LED_On(&downLed);

		for (int i = 0; i < 100; i++)
			FND_DispNumber(counter++);

		LED_Off(&powerLed);
		LED_Off(&upLed);
		LED_Off(&downLed);
	}
}

