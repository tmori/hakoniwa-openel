#include "M5Stack.h"
#include <stdlib.h>

void portENTER_CRITICAL_ISR(void *ptr)
{
    return;
}

void portEXIT_CRITICAL_ISR(void *ptr)
{
    return;
}

uint32_t millis()
{
    return 0;
}

void xSemaphoreGiveFromISR(SemaphoreHandle_t arg1, void *ptr)
{
    return;
}

SemaphoreHandle_t xSemaphoreCreateBinary()
{
    return 0;
}

hw_timer_t *timerBegin(int arg1, int arg2, bool arg3)
{
    return NULL;
}

void timerAttachInterrupt(hw_timer_t *arg1, void (*func) (void), bool arg3)
{
    return;
}

void timerAlarmEnable(hw_timer_t *ptr)
{
    return;
}

void timerEnd(hw_timer_t *ptr)
{
    return;
}

void timerAlarmWrite(hw_timer_t *ptr, uint64_t arg2, bool arg3)
{
    return;
}
