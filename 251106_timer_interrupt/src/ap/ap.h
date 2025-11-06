/*
 * ap.h
 *
 *  Created on: 2025. 11. 4.
 *      Author: Hoseung Yoon
 */

#ifndef SRC_AP_AP_H_
#define SRC_AP_AP_H_

#include "../driver/led/led.h"
#include "../driver/fnd/fnd.h"
#include "../driver/common/millis.h"
#include "powerInd/powerInd.h"
#include "../ap/upCounter/upCounter.h"
#include "../ap/btnLEDToggle/btnLEDToggle.h"


void ap_main();
void intc_init();
void TIMER_Intr_Init();
void ISR();
// void millisCounter();

#endif /* SRC_AP_AP_H_ */
