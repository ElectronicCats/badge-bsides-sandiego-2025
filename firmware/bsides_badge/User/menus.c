#include "menus.h"
#include "../SSD1306/include/ssd1306.h"
#include "bitmaps.h"
#include "debug.h"
#include "driver.h"
#include "tetris.h"

typedef enum {
  /* Main layer */
  MENU_GAME,
  MENU_USER_NAME,
  MENU_ABOUT,
  /* Settings layer */
  // MENU_SETTINGS,
  // MENU_LEDS,
  /************/
  MENU_COUNT
} menu_item_t;

char* menu_names[] = {"game", "nickname", "about"};
const uint8_t MAX_USER_NAME_LENGTH = 6;
uint8_t user_name_length = 0;
uint8_t user_name[6] = {0};

typedef enum { LAYER_MAIN, LAYER_SETTINGS } layer_t;

static menu_item_t current_menu = MENU_GAME;
// static layer_t current_layer = LAYER_MAIN;

void display_menu() {
  ssd1306_clear();
  ssd1306_drawImage(menus_bitmaps[current_menu], 0, 0, 128, 32, COLOR_NORMAL);
  // ssd1306_drawstr_sz(menu_names[current_menu], 0, 0, COLOR_NORMAL,
  //                    fontsize_16x16);
  // ssd1306_drawstr(menu_names[current_menu], 0, 0, COLOR_NORMAL);
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
  // for (uint8_t i = 0; i < MAX_USER_NAME_LENGTH; i++) {
  //   ssd1306_drawchar(user_name[i], i * 8 + 40, 16, COLOR_NORMAL);
  // }
  ssd1306_refresh();
}

// Ask the user to insert their name
void insert_name() {
  ssd1306_clear();
  ssd1306_drawstr("insert", 0, 0, COLOR_NORMAL);
  ssd1306_drawstr("your", 7 * 8, 0, COLOR_NORMAL);
  ssd1306_drawstr("name", 12 * 8, 0, COLOR_NORMAL);
  // ssd1306_drawstr("a", 16, 16, COLOR_INVERT);
  ssd1306_refresh();
  Delay_Ms(1000);
  char selection = 'a';
  user_name_length = 0;
  memset(user_name, 0, sizeof(user_name));

  uint8_t refresh_counter = 0;
  uint8_t refresh_rate_s = 5;
  ssd1306_color_mode_t color = COLOR_NORMAL;
  uint8_t start_x = 40;
  uint8_t x = start_x;
  uint8_t y = 16;
  ssd1306_drawchar(selection, x, y, color);
  ssd1306_refresh();
  while (1) {
    refresh_counter++;
    if (joy_right_pressed()) {
      user_name[user_name_length] = selection;
      user_name_length++;
      ssd1306_drawchar(selection, x, y, COLOR_NORMAL);
      x += 8;
      if (user_name_length >= MAX_USER_NAME_LENGTH) {
        display_saving_name();
        Delay_Ms(1500);
        break;
      }
      ssd1306_drawchar(selection, x, y, color);
      ssd1306_refresh();
      Delay_Ms(250);
    }
    if (joy_left_pressed()) {
      display_saving_name();
      Delay_Ms(1500);
      break;
    }
    if (joy_up_pressed()) {
      if (selection == 'a') {
        selection = 'z';
      } else {
        selection--;
      }
      refresh_counter = refresh_rate_s;
    }
    if (joy_down_pressed()) {
      if (selection == 'z') {
        selection = 'a';
      } else {
        selection++;
      }
      refresh_counter = refresh_rate_s;
    }
    Delay_Ms(100);

    if (refresh_counter == refresh_rate_s) {
      color = color == COLOR_NORMAL ? COLOR_INVERT : COLOR_NORMAL;
      ssd1306_drawchar(selection, x, y, color);
      ssd1306_refresh();
      refresh_counter = 0;
    }
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
  while (1) {
    if (joy_up_pressed()) {
      menus_move_up();
    }
    if (joy_down_pressed()) {
      menus_move_down();
    }
    if (joy_right_pressed()) {
      switch (current_menu) {
        case MENU_GAME:
          tetris_start();
          break;
        case MENU_USER_NAME:
          insert_name();
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
    }
    Delay_Ms(100);
  }
}