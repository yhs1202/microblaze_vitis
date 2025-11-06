#ifndef SRC_DRIVER_UPCOUNTER_UPCOUNTER_H_
#define SRC_DRIVER_UPCOUNTER_UPCOUNTER_H_

#include "../../driver/fnd/fnd.h"
#include "../../driver/led/led.h"
#include "../../driver/btn/btn.h"
#include "../../driver/common/millis.h"
#include <stdint.h>

void initUpCounter();
void exeUpCounter();
void stopCounter();
void runUpCounter();
void runDownCounter();
void clearUpCounter();

#endif /* SRC_DRIVER_UPCOUNTER_UPCOUNTER_H_ */