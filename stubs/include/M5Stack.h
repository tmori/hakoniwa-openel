#ifndef _M5STACK_H_
#define _M5STACK_H_

#include <stdint.h>

typedef int SemaphoreHandle_t;

typedef int hw_timer_t;

typedef int portMUX_TYPE;
#define portMUX_INITIALIZER_UNLOCKED 0
#define IRAM_ATTR


extern void portENTER_CRITICAL_ISR(void *ptr);
extern void portEXIT_CRITICAL_ISR(void *ptr);
extern uint32_t millis();
extern void xSemaphoreGiveFromISR(SemaphoreHandle_t arg1, void *ptr);
extern SemaphoreHandle_t xSemaphoreCreateBinary();
extern hw_timer_t *timerBegin(int arg1, int arg2, bool arg3);
extern void timerAttachInterrupt(hw_timer_t *arg1, void (*func) (void), bool arg3);

extern void timerAlarmEnable(hw_timer_t *ptr);
extern void timerEnd(hw_timer_t *ptr);
extern void timerAlarmWrite(hw_timer_t *ptr, uint64_t arg2, bool arg3);

#endif /* _M5STACK_H_ */