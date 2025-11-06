#ifndef SRC_DRIVER_MILLIS_MILLIS_H_
#define SRC_DRIVER_MILLIS_MILLIS_H_
#include <stdint.h>

void incMillis();
void clearMillis();
void setMillis(uint32_t t);
uint32_t millis();

#endif /* SRC_DRIVER_MILLIS_MILLIS_H_ */