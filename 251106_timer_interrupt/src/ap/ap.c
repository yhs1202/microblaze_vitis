/*
 * ap.c
 *
 *  Created on: 2025. 11. 4.
 *      Author: Hoseung Yoon
 */

#include "ap.h"
#include "sleep.h"
#include "xintc.h"	// interrupt controller (hardware)
#include "xil_exception.h" // interrupt handling (software)
#include "xparameters.h" // device parameters


#include "../driver/common/millis.h"
#include "../device/timer/timer.h"


// hLed powerLed;
XIntc intc; // interrupt controller instance

// Application main function
void ap_main() {
	// Power Indicator LED Initialization
	initPowerInd();
	// FND Upcounter Initialization
	initUpCounter();
	// Button System Initialization
	// initBtnLEDToggle();

	
	Millis_Init(TIMER1);	
	intc_init();
	TIMER_Intr_Init();
	// LED_Init(&powerLed, LED_GPIO, LED_0);
	// uint32_t prevTime = 0;
	// uint32_t curTime;

	// TIMER0: Interrupt timer init
	// TIMER1: Millis timer init
	while (1) {
		// Update power indicator LED	
		dispPowerInd();

		// Run up counter w/ RUN/STOP and CLEAR buttons
		exeUpCounter();

		// LED Toggle w/ BTN_LEFT
		// runBtnLEDToggle();

		// Call ISR to handle millis and FND display
		// ISR();			


		// Toggle power LED every 500ms
		// curTime = millis();
		// if (curTime - prevTime > 500) {
		// 	prevTime = curTime;
		// 	LED_Toggle(&powerLed);

		// }
	}
}

// Interrupt Controller Initialization
void intc_init() {
	// Initialize the interrupt controller
	int status = XIntc_Initialize(&intc, XPAR_INTC_0_DEVICE_ID);
	if (status == XST_SUCCESS) {
		xil_printf("INTC initialized successfully.\n");
	} else {
		xil_printf("INTC initialization failed.\n");
	}
	status = XIntc_SelfTest(&intc);
	if (status == XST_SUCCESS) {
		xil_printf("INTC self-test passed.\n");
	} else {
		xil_printf("INTC self-test failed.\n");
	}


	// Register the interrupt handler
	Xil_ExceptionInit();
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			(Xil_ExceptionHandler)XIntc_InterruptHandler,
			&intc);
			// (void *)&intc);
	Xil_ExceptionEnable();


	// Connect the timer interrupt to the handler and enable it
	XIntc_Connect(&intc, XPAR_INTC_0_TIMER_0_VEC_ID,
			(Xil_ExceptionHandler)ISR, 0);
	XIntc_Enable(&intc, XPAR_INTC_0_TIMER_0_VEC_ID);

	// Start the interrupt controller
	XIntc_Start(&intc, XIN_REAL_MODE);

}

void TIMER_Intr_Init() {
	TMR_SetPSC(TIMER0, 100);
	TMR_SetARR(TIMER0, 1000); // 10ms
	TMR_Start(TIMER0);
	TMR_IntrStart(TIMER0);
}

// Interrupt Service Routine
void ISR() {
	// millisCounter();
	FND_DispNumber();
}

// void millisCounter() {
// 	incMillis();
// 	usleep(1000);
// }