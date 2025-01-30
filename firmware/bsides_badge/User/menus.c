#include "menus.h"
#include "../SSD1306/include/ssd1306.h"
#include "bitmaps.h"
#include "debug.h"
#include "driver.h"
#include "tetris.h"

typedef enum {
  /* Main layer */
  MENU_GAME,
  MENU_LEDS,
  MENU_ABOUT,
  /************/
  MENU_COUNT
} menu_item_t;

typedef enum {
  LEDS_FAST,
  LEDS_SLOW,
  LEDS_OFF,
} leds_speed_t;

char* leds_options[] = {"fast", "slow", "off"};
uint8_t leds_speeds[] = {50, 200, 0};
leds_speed_t leds_speed = LEDS_FAST;
uint8_t refrese_rate_s;

typedef enum { LAYER_MAIN, LAYER_SETTINGS } layer_t;

static menu_item_t current_menu = MENU_GAME;

void display_menu() {
  ssd1306_clear();
  ssd1306_drawImage(menus_bitmaps[current_menu], 0, 0, 128, 32, COLOR_NORMAL);
  ssd1306_refresh();
}

void menus_move_down() {
  current_menu = (current_menu + 1) % MENU_COUNT;
  display_menu();
}

void menus_move_up() {
  current_menu = (current_menu - 1) % MENU_COUNT;
  display_menu();
}

void display_saving_name() {
  ssd1306_clear();
  ssd1306_drawstr("saving", 5 * 8, 8, COLOR_NORMAL);
  ssd1306_refresh();
}

void move_leds_options_down() {
  leds_speed = (leds_speed + 1) % 3;
}

void move_leds_options_up() {
  leds_speed = (leds_speed - 1) % 3;
}

void leds_control_menu() {
  ssd1306_clear();
  ssd1306_drawstr("select", 0, 0, COLOR_NORMAL);
  ssd1306_drawstr("led", 7 * 8, 0, COLOR_NORMAL);
  ssd1306_drawstr("speed", 11 * 8, 0, COLOR_NORMAL);
  ssd1306_drawstr(leds_options[leds_speed], 48, 16, COLOR_NORMAL);
  ssd1306_refresh();

  while (1) {
    if (joy_left_pressed()) {
      break;
    }

    if (joy_up_pressed()) {
      move_leds_options_up();
      ssd1306_clear();
      ssd1306_drawstr("select", 0, 0, COLOR_NORMAL);
      ssd1306_drawstr("led", 7 * 8, 0, COLOR_NORMAL);
      ssd1306_drawstr("speed", 11 * 8, 0, COLOR_NORMAL);
      ssd1306_drawstr(leds_options[leds_speed], 48, 16, COLOR_NORMAL);
      ssd1306_refresh();
      refrese_rate_s = leds_speeds[leds_speed];
    }

    if (joy_down_pressed()) {
      move_leds_options_down();
      ssd1306_clear();
      ssd1306_drawstr("select", 0, 0, COLOR_NORMAL);
      ssd1306_drawstr("led", 7 * 8, 0, COLOR_NORMAL);
      ssd1306_drawstr("speed", 11 * 8, 0, COLOR_NORMAL);
      ssd1306_drawstr(leds_options[leds_speed], 48, 16, COLOR_NORMAL);
      ssd1306_refresh();
      refrese_rate_s = leds_speeds[leds_speed];
    }

    Delay_Ms(100);
  }
}

void leds_control_handler() {
  if (leds_speed == LEDS_OFF) {
    for (uint8_t i = 0; i < leds_count; i++) {
      PIN_low(leds[i]);
    }
    return;
  }

  static uint8_t counter = 0;
  static uint8_t led_index = 0;

  if (led_index == 0) {
    PIN_high(leds[led_index]);
    for (uint8_t i = 1; i < leds_count; i++) {
      PIN_low(leds[i]);
    }
  } else {
    PIN_low(leds[led_index - 1]);
    PIN_high(leds[led_index]);
  }

  counter++;
  if (counter == refrese_rate_s) {
    counter = 0;
    led_index = (led_index + 1) % (leds_count + 1);
  }
}

/**
 * @brief Display the credits
 *
 * @note Since font was modified, it only displays lowercase characters,
 * so the spaces between words have to be calculated manually.
 *
 * @return void
 */
void display_credits() {
  ssd1306_clear();
  ssd1306_drawstr("developed", 0, 0, COLOR_NORMAL);
  ssd1306_drawstr("with", 10 * 8, 0, COLOR_NORMAL);
  ssd1306_drawstr("love", 0, 8, COLOR_NORMAL);
  ssd1306_drawstr("from", 5 * 8, 8, COLOR_NORMAL);
  ssd1306_drawstr("mexico", 10 * 8, 8, COLOR_NORMAL);
  ssd1306_drawstr("by", 0, 16, COLOR_NORMAL);
  ssd1306_drawstr("electronic", 3 * 8, 16, COLOR_NORMAL);
  ssd1306_drawstr("cats", 0, 24, COLOR_NORMAL);
  ssd1306_refresh();
}

void menus_init() {
  display_menu();
  refrese_rate_s = leds_speeds[leds_speed];
  while (1) {
    static uint8_t counter = 0;
    counter++;

    if (joy_up_pressed() && counter > 200) {
      menus_move_up();
      counter = 0;
    }

    if (joy_down_pressed() && counter > 200) {
      menus_move_down();
      counter = 0;
    }

    if (joy_right_pressed()) {
      for (uint8_t i = 1; i < leds_count; i++) {
        PIN_low(leds[i]);
      }

      switch (current_menu) {
        case MENU_GAME:
          tetris_start();
          break;
        case MENU_LEDS:
          leds_control_menu();
          break;
        case MENU_ABOUT:
          display_credits();
          while (1) {
            if (joy_left_pressed()) {
              break;
            }
          }
          break;
        default:
          break;
      }
      display_menu();
      Delay_Ms(100);
    }

    Delay_Ms(1);
    leds_control_handler();
  }
}