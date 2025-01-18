/*******************************************************************************
 * Touch libraries:
 * FT6X36: https://github.com/strange-v/FT6X36.git
 * GT911: https://github.com/TAMCTec/gt911-arduino.git
 * XPT2046: https://github.com/PaulStoffregen/XPT2046_Touchscreen.git
 ******************************************************************************/

/* uncomment for GT911 */
#define TOUCH_GT911
#define TOUCH_GT911_SCL      20
#define TOUCH_GT911_SDA      19
#define TOUCH_GT911_INT      18
#define TOUCH_GT911_RST      38
#define TOUCH_GT911_ROTATION ROTATION_NORMAL
#define TOUCH_MAP_X1         0
#define TOUCH_MAP_X2         480
#define TOUCH_MAP_Y1         0
#define TOUCH_MAP_Y2         272

/* uncomment for XPT2046 */
// #define TOUCH_XPT2046
// #define TOUCH_XPT2046_SCK 12
// #define TOUCH_XPT2046_MISO 13
// #define TOUCH_XPT2046_MOSI 11
// #define TOUCH_XPT2046_CS 38
// #define TOUCH_XPT2046_INT 18
// #define TOUCH_XPT2046_ROTATION 0
// #define TOUCH_MAP_X1 4000
// #define TOUCH_MAP_X2 100
// #define TOUCH_MAP_Y1 100
// #define TOUCH_MAP_Y2 4000

int touch_last_x = 0, touch_last_y = 0;

#if defined(TOUCH_GT911)
#  include <Wire.h>
#  include <TAMC_GT911.h>
TAMC_GT911 ts = TAMC_GT911(TOUCH_GT911_SDA, TOUCH_GT911_SCL, TOUCH_GT911_INT, TOUCH_GT911_RST, max(TOUCH_MAP_X1, TOUCH_MAP_X2), max(TOUCH_MAP_Y1, TOUCH_MAP_Y2));

#elif defined(TOUCH_XPT2046)
#  include <XPT2046_Touchscreen.h>
#  include <SPI.h>
XPT2046_Touchscreen ts(TOUCH_XPT2046_CS, TOUCH_XPT2046_INT);

#endif

void touch_init() {
#if defined(TOUCH_GT911)
  // Wire.begin(TOUCH_GT911_SDA, TOUCH_GT911_SCL);
  // ts.begin();
  // ts.setRotation(TOUCH_GT911_ROTATION);

  // Begin init wire, and Reset the device also, no need wire.begin() to be done here
  // Wire.begin(TOUCH_GT911_SDA, TOUCH_GT911_SCL);
  ts.begin(GT911_ADDR1);

  // Need to solve floating INT pin so on reset changes between the 2 addresses
  Wire.beginTransmission(GT911_ADDR1);
  Wire.write(highByte(GT911_PRODUCT_ID));
  Wire.write(lowByte(GT911_PRODUCT_ID));
  Wire.endTransmission();
  // returns rxLength - if 0 we have a problem
  uint8_t returnSize = Wire.requestFrom(GT911_ADDR1, (uint8_t)1);
  if (returnSize == 0) {
    Serial.println("Setting address to ADDR2");
    // restart with other address
    ts.begin(GT911_ADDR2);
  }

  // Now do your normal job
  ts.setRotation(TOUCH_GT911_ROTATION);

#elif defined(TOUCH_XPT2046)
  SPI.begin(TOUCH_XPT2046_SCK, TOUCH_XPT2046_MISO, TOUCH_XPT2046_MOSI, TOUCH_XPT2046_CS);
  ts.begin();
  ts.setRotation(TOUCH_XPT2046_ROTATION);

#endif
}

bool touch_has_signal() {
#if defined(TOUCH_GT911)
  return true;

#elif defined(TOUCH_XPT2046)
  return ts.tirqTouched();

#else
  return false;
#endif
}

bool touch_touched() {
#if defined(TOUCH_GT911)
  ts.read();
  if (ts.isTouched) {
#  if (TOUCH_SWAP_XY)
    touch_last_x = map(ts.points[0].y, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, DISPLAY_WIDTH - 1);
    touch_last_y = map(ts.points[0].x, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, DISPLAY_HEIGHT - 1);
#  else
    touch_last_x = map(ts.points[0].x, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, DISPLAY_WIDTH - 1);
    touch_last_y = map(ts.points[0].y, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, DISPLAY_HEIGHT - 1);
#  endif
    return true;
  } else {
    return false;
  }

#elif defined(TOUCH_XPT2046)
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
#  if (TOUCH_SWAP_XY == 1)
    touch_last_x = map(p.y, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, DISPLAY_WIDTH - 1);
    touch_last_y = map(p.x, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, DISPLAY_HEIGHT - 1);
#  else
    touch_last_x = map(p.x, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, DISPLAY_WIDTH - 1);
    touch_last_y = map(p.y, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, DISPLAY_HEIGHT - 1);
#  endif
    return true;
  } else {
    return false;
  }

#else
  return false;
#endif
}

bool touch_released() {
#if defined(TOUCH_GT911)
  return true;

#elif defined(TOUCH_XPT2046)
  return true;

#else
  return false;
#endif
}
