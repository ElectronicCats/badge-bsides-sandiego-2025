#include <limits.h>
#include <string.h>

#include "../SSD1306/include/ssd1306.h"
#include "bitmaps.h"
#include "ch32v003_flash.h"
#include "debug.h"
#include "driver.h"
#include "hardware_tests.h"

void test_buttons() {
  APP_DBG("Testing buttons");
  ssd1306_clear();
  ssd1306_drawstr_sz("Press", 28, 0, COLOR_NORMAL, fontsize_16x16);
  ssd1306_drawstr_sz("Right", 28, 16, COLOR_NORMAL, fontsize_16x16);
  ssd1306_refresh();
  while (1) {
    if (JOY_right_pressed()) {
      break;
    }
    Delay_Ms(100);
  }

  ssd1306_clear();
  ssd1306_drawstr_sz("Press", 28, 0, COLOR_NORMAL, fontsize_16x16);
  ssd1306_drawstr_sz("Left", 28, 16, COLOR_NORMAL, fontsize_16x16);
  ssd1306_refresh();
  while (1) {
    if (JOY_left_pressed()) {
      break;
    }
    Delay_Ms(100);
  }

  ssd1306_clear();
  ssd1306_drawstr_sz("Press", 28, 0, COLOR_NORMAL, fontsize_16x16);
  ssd1306_drawstr_sz("Up", 28, 16, COLOR_NORMAL, fontsize_16x16);
  ssd1306_refresh();
  while (1) {
    if (JOY_up_pressed()) {
      break;
    }
    Delay_Ms(100);
  }

  ssd1306_clear();
  ssd1306_drawstr_sz("Press", 28, 0, COLOR_NORMAL, fontsize_16x16);
  ssd1306_drawstr_sz("Down", 28, 16, COLOR_NORMAL, fontsize_16x16);
  ssd1306_refresh();
  while (1) {
    if (JOY_down_pressed()) {
      break;
    }
    Delay_Ms(100);
  }
}

void test_leds() {
  APP_DBG("Testing LEDs");
  ssd1306_clear();
  ssd1306_drawstr_sz("Right to", 0, 0, COLOR_NORMAL, fontsize_16x16);
  ssd1306_drawstr_sz("continue", 0, 16, COLOR_NORMAL, fontsize_16x16);
  ssd1306_refresh();
  Delay_Ms(1000);
  ssd1306_drawstr_sz("Right to", 0, 0, COLOR_INVERT, fontsize_16x16);
  ssd1306_drawstr_sz("continue", 0, 16, COLOR_INVERT, fontsize_16x16);
  ssd1306_refresh();
  Delay_Ms(1000);

  for (uint8_t i = 0; i < leds_count; i++) {
    const char* text = "LED %d on";
    char buffer[16];
    snprintf(buffer, sizeof(buffer), text, i + 1);

    PIN_high(leds[i]);
    ssd1306_clear();
    ssd1306_drawstr_sz(buffer, 0, 8, COLOR_NORMAL, fontsize_16x16);
    ssd1306_refresh();

    if (i == leds_count - 1) {
      Delay_Ms(1000);
      break;
    }

    while (1) {
      if (JOY_right_pressed()) {
        break;
      }
      Delay_Ms(100);
    }
    Delay_Ms(1000);
  }
}

void hardware_tests_start() {
  test_buttons();
  test_leds();
  ssd1306_clear();
  ssd1306_drawstr_sz("Test", 32, 0, COLOR_NORMAL, fontsize_16x16);
  ssd1306_drawstr_sz("finished", 0, 16, COLOR_NORMAL, fontsize_16x16);
  ssd1306_refresh();

  Delay_Ms(1000);
  // Turn off all LEDs
  for (uint8_t i = 0; i < leds_count; i++) {
    PIN_low(leds[i]);
  }

  while (1) {
    Delay_Ms(100);
  }
}
