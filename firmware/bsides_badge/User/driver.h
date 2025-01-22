// ===================================================================================
// Tiny Joypad Drivers for CH32V003                                           *
// v1.0 *
// ===================================================================================
//
// MCU abstraction layer.
// 2023 by Stefan Wagner:   https://github.com/wagiminator

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "ch32v00x.h"
#include "gpio.h"
#include "oled_min.h"

#define DEBUG_ENABLE 1
#define DEV_VERSION  1

#define APP_DBG(X...)             \
  if (1) {                        \
    PRINT("[%s] ", __FUNCTION__); \
    PRINT(X);                     \
    PRINT("\r\n");                \
  }

// Pin assignments
// #define PIN_BEEP PA1  // pin connected to buzzer
// #define PIN_PAD  PC4  // pin conected to direction buttons
#define BUTTON_RIGHT_PIN PD0
#define BUTTON_LEFT_PIN  PC3
#define BUTTON_UP_PIN    PC4
#ifdef DEV_VERSION
  #define BUTTON_DOWN_PIN PC6
#else
  #define BUTTON_DOWN_PIN PA2
#endif

#define LED1_PIN PD3
#define LED2_PIN PD5
#define LED3_PIN PD4
#define LED4_PIN PA1
#define LED5_PIN PD2
#define LED6_PIN PC5
#define LED7_PIN PC0
#define LED8_PIN PD6

#define PIN_SCL PC2  // pin connected to OLED (I2C SCL)
#define PIN_SDA PC1  // pin connected to OLED (I2C SDA)

// Joypad calibration values
#define JOY_N   197  // joypad UP
#define JOY_NE  259  // joypad UP + RIGHT
#define JOY_E   90   // joypad RIGHT
#define JOY_SE  388  // joypad DOWN + RIGHT
#define JOY_S   346  // joypad DOWN
#define JOY_SW  616  // joypad DOWN + LEFT
#define JOY_W   511  // joypad LEFT
#define JOY_NW  567  // JOYPAD UP + LEFT
#define JOY_DEV 20   // deviation

// Sound enable
#define JOY_SOUND 1  // 0: no sound, 1: with sound

// Delays
#define JOY_DLY_ms Delay_Ms
#define JOY_DLY_us Delay_Us

// Additional Defines
#define abs(n) ((n >= 0) ? (n) : (-(n)))

// Game slow-down delay
#define JOY_SLOWDOWN()  // DLY_ms(10)

extern uint8_t leds[];
extern uint8_t leds_count;

#define JOY_pad_pressed()  (ADC_read() > 10)
#define JOY_pad_released() (ADC_read() <= 10)

// static inline void JOY_init(void);
void JOY_init(void);

// OLED commands
#define JOY_OLED_init            OLED_init
#define JOY_OLED_end             I2C_stop
#define JOY_OLED_send(b)         I2C_write(b)
#define JOY_OLED_send_command(c) OLED_send_command(c)
#define JOY_OLED_data_start(y) \
  {                            \
    OLED_setpos(0, y);         \
    OLED_data_start();         \
  }

// Buttons
#define JOY_pad_pressed()  (ADC_read() > 10)
#define JOY_pad_released() (ADC_read() <= 10)

uint8_t joy_up_pressed(void);
uint8_t joy_down_pressed(void);
uint8_t joy_left_pressed(void);
uint8_t joy_right_pressed(void);
void JOY_sound(uint8_t freq, uint8_t dur);
uint16_t JOY_random(void);
long map(long x, long in_min, long in_max, long out_min, long out_max);

#ifdef __cplusplus
};
#endif
