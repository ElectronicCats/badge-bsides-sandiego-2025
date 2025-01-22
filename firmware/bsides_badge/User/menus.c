#include "menus.h"
#include "../SSD1306/include/ssd1306.h"
#include "bitmaps.h"
#include "debug.h"
#include "driver.h"
#include "tetris.h"

typedef enum {
  /* Main layer */
  MENU_GAME,
  MENU_SETTINGS,
  MENU_ABOUT,
  /* Settings layer */
  // MENU_USER_NAME,
  // MENU_LEDS,
  /************/
  MENU_COUNT
} menu_item_t;

char* menu_names[] = {"Game", "Name", "About"};

typedef enum { LAYER_MAIN, LAYER_SETTINGS } layer_t;

static menu_item_t current_menu = MENU_GAME;
// static layer_t current_layer = LAYER_MAIN;

void display_menu() {
  // APP_DBG("Displaying %s", menu_names[current_menu]);
  ssd1306_clear();
  ssd1306_drawImage(menus_bitmaps[current_menu], 0, 0, 128, 32, COLOR_NORMAL);
  // ssd1306_drawstr_sz(menu_names[current_menu], 0, 0,
  // COLOR_NORMAL,
  //                    fontsize_16x16);
  // ssd1306_drawstr(menu_names[current_menu], 0, 0, COLOR_NORMAL);
  ssd1306_refresh();
}

void menus_move_down() {
  // if (current_layer == LAYER_MAIN) {
  //   current_menu = (current_menu + 1) % 3;
  // } else {
  //   current_menu = (current_menu + 1) % MENU_COUNT;
  // }
  current_menu = (current_menu + 1) % MENU_COUNT;
  display_menu();
}

void menus_move_up() {
  current_menu = (current_menu - 1) % MENU_COUNT;
  display_menu();
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
        case MENU_SETTINGS:
          break;
        case MENU_ABOUT:
          break;
        // case MENU_USER_NAME:
        //   break;
        // case MENU_LEDS:
        //   break;
        default:
          break;
      }
      display_menu();
    }
    Delay_Ms(100);
  }
}