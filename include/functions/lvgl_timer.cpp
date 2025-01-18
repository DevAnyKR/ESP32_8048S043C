#include "lvgl_timer.h"
#include <lvgl.h>

timerTick timerTick_500ms;

void lv_timer1_callback(lv_timer_t *timer) {
  timerTick_500ms.flag = !timerTick_500ms.flag;
}

lv_timer_t *lv_timer1 = lv_timer_create(lv_timer1_callback, 500, 0);
