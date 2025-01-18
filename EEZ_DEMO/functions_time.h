#pragma once
#include <Arduino.h>
#include <Time.h>

time_t cvt_date(char const *date, char const *time) {
  char s_month[5];
  int year;
  tmElements_t t;
  static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
  sscanf(date, "%s %hhd %d", s_month, &t.Day, &year); // %hhd = signed byte, %hhu = unsigned byte
  sscanf(time, "%2hhd %*c %2hhd %*c %2hhd", &t.Hour, &t.Minute, &t.Second);
  t.Month = (strstr(month_names, s_month) - month_names) / 3 + 1; // 월

  // TimeElements는 1970년부터 시작함
  if (year > 99) t.Year = year - 1970;
  else t.Year = year + 30;
  return makeTime(t);
}
