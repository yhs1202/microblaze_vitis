#include "millis.h"

uint32_t m_counter = 0;
Timer_TypeDef*  millisTimer;

void Millis_Init(Timer_TypeDef* tmr) {
    millisTimer = tmr;
    TMR_SetPSC(millisTimer, 100000); // 100 MHz / 100000 = 1 kHz -> counter increases 1 ms
    TMR_SetARR(millisTimer, 0xffffffff); // max
    TMR_Start(millisTimer);
}

void incMillis() {
    m_counter++;
}

void clearMillis() {
    m_counter = 0;
}

void setMillis(uint32_t t) {
    m_counter = t;
}

uint32_t millis() {
    // return m_counter;
    return TMR_ReadCNT(TIMER1);
}