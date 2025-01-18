#pragma once
#include <Arduino.h>

//////////////// 고정 ////////////////
extern char S[];

#include <Wire.h>

// TIME
#include <TimeLib.h>

// Debug
struct Debug {
  bool Serial = true;
};
extern struct Debug debug;
