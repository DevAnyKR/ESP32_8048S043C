#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _timerTick_t {
  bool flag;
  int value;
} timerTick;

extern timerTick timerTick_500ms;

#ifdef __cplusplus
}
#endif
