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
  MENU_SETTINGS,
  // MENU_LEDS,
  /************/
  MENU_COUNT
} menu_item_t;

// char* menu_names[] = {"Game", "Name", "About"};
char* menu_names[] = {"Game", "Name"};
char* user_name = "Player";
uint8_t max_user_name_length = 5;

typedef enum { LAYER_MAIN, LAYER_SETTINGS } layer_t;

static menu_item_t current_menu = MENU_GAME;
// static layer_t current_layer = LAYER_MAIN;

void display_menu() {
  ssd1306_clear();
  ssd1306_drawImage(menus_bitmaps[current_menu], 0, 0, 128, 32, COLOR_NORMAL);
  // ssd1306_drawstr_sz(menu_names[current_menu], 0, 0,
  // COLOR_NORMAL,
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

// Ask the user to insert their name
void insert_name() {
  ssd1306_clear();
  // ssd1306_drawstr("Insert your name", 0, 0, COLOR_NORMAL);
  // ssd1306_drawstr("a", 0, 16, COLOR_NORMAL);
  ssd1306_refresh();
  // while (1) {
  //   if (joy_right_pressed()) {
  //     break;
  //   }
  //   if (joy_left_pressed()) {
  //     break;
  //   }
  //   if (joy_up_pressed()) {
  //     break;
  //   }
  //   if (joy_down_pressed()) {
  //     break;
  //   }
  //   Delay_Ms(100);
  // }
}

void display_credits() {
  ssd1306_clear();
  ssd1306_drawstr("ab", 0, 0, COLOR_NORMAL);
  // ssd1306_drawstr("BSides San Diego", 0, 0, COLOR_NORMAL);
  printf("size of fontdata: %d\r\n", sizeof(fontdata));
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
        // case MENU_SETTINGS:
        //   break;
        case MENU_ABOUT:
          display_credits();
          Delay_Ms(2000);
          break;
        case MENU_USER_NAME:
          // insert_name();
          break;
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