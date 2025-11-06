/*
 * ap.c
 *
 *  Created on: 2025. 11. 4.
 *      Author: Hoseung Yoon
 */

#include "ap.h"
#include "sleep.h"
#include "powerInd/powerInd.h"
#include "../ap/upCounter/upCounter.h"
#include "../ap/btnLEDToggle/btnLEDToggle.h"



// Application main function
void ap_main() {
	// Power Indicator LED Initialization
	initPowerInd();
	// FND Upcounter Initialization
	initUpCounter();
	// Button System Initialization
	initBtnLEDToggle();

	while (1) {
		// Update power indicator LED	
		dispPowerInd();

		// Run up counter w/ RUN/STOP and CLEAR buttons
		exeUpCounter();

		// LED Toggle w/ BTN_LEFT
		// runBtnLEDToggle();

		// Call ISR to handle millis and FND display
		ISR();			
	}
}

// Interrupt Service Routine
void ISR() {
	millisCounter();
	FND_DispNumber();
}

void millisCounter() {
	incMillis();
	usleep(1000);
}