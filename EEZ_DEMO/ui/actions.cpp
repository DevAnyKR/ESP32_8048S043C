#include <lvgl.h>
#include "actions.h"
#include "screens.h"
#include "ui.h"
#include "vars.h"
#include "structs.h"
#include <Arduino.h>

void action_print_message(lv_event_t *e)
{
    Serial.println("Message printed from action");
}