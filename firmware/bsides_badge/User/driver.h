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
// #define BUTTON_RIGHT_PIN PA2
#define BUTTON_DOWN_PIN PC6

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

// Game slow-down delay
#define JOY_SLOWDOWN()  // DLY_ms(10)

uint8_t leds[] = {LED1_PIN,
#ifndef DEBUG_ENABLE
                  LED2_PIN,
#endif
                  LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN, LED8_PIN};

// Init driver
static inline void JOY_init(void) {
  // PIN_input_AN(PIN_PAD);
  // PIN_output(PIN_BEEP);
  // PIN_high(PIN_BEEP);

  // Enable GPIO Ports
  PORTS_enable();

  // Set LED pins as output
  PIN_output(LED1_PIN);
#ifndef DEBUG_ENABLE
  PIN_output(LED2_PIN);
#endif
  PIN_output(LED3_PIN);
  PIN_output(LED4_PIN);
  PIN_output(LED5_PIN);
  PIN_output(LED6_PIN);
  PIN_output(LED7_PIN);
  PIN_output(LED8_PIN);

  GPIO_InitTypeDef GPIO_InitStruct;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_6;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_30MHz;
  GPIO_Init(GPIOC, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_30MHz;
  GPIO_Init(GPIOD, &GPIO_InitStruct);

  OLED_init();
  // ADC_init();
  // ADC_input(PIN_PAD);
}

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

static inline uint8_t JOY_up_pressed(void) {
  // uint16_t val = ADC_read();
  // return (((val > JOY_N - JOY_DEV) && (val < JOY_N + JOY_DEV)) |
  //         ((val > JOY_NE - JOY_DEV) && (val < JOY_NE + JOY_DEV)) |
  //         ((val > JOY_NW - JOY_DEV) && (val < JOY_NW + JOY_DEV)));
  return !PIN_read(BUTTON_UP_PIN);
}

static inline uint8_t JOY_down_pressed(void) {
  // uint16_t val = ADC_read();
  // return (((val > JOY_S - JOY_DEV) && (val < JOY_S + JOY_DEV)) |
  //         ((val > JOY_SE - JOY_DEV) && (val < JOY_SE + JOY_DEV)) |
  //         ((val > JOY_SW - JOY_DEV) && (val < JOY_SW + JOY_DEV)));
  return !PIN_read(BUTTON_DOWN_PIN);
}

static inline uint8_t JOY_left_pressed(void) {
  // uint16_t val = ADC_read();
  // return (((val > JOY_W - JOY_DEV) && (val < JOY_W + JOY_DEV)) |
  //         ((val > JOY_NW - JOY_DEV) && (val < JOY_NW + JOY_DEV)) |
  //         ((val > JOY_SW - JOY_DEV) && (val < JOY_SW + JOY_DEV)));
  return !PIN_read(BUTTON_LEFT_PIN);
}

static inline uint8_t JOY_right_pressed(void) {
  // uint16_t val = ADC_read();
  // return (((val > JOY_E - JOY_DEV) && (val < JOY_E + JOY_DEV)) |
  //         ((val > JOY_NE - JOY_DEV) && (val < JOY_NE + JOY_DEV)) |
  //         ((val > JOY_SE - JOY_DEV) && (val < JOY_SE + JOY_DEV)));
  return !PIN_read(BUTTON_RIGHT_PIN);
}

// Buzzer
void JOY_sound(uint8_t freq, uint8_t dur) {
  //   while (dur--) {
  // #if JOY_SOUND == 1
  //     if (freq)
  //       PIN_low(PIN_BEEP);
  // #endif
  //     Delay_Us(255 - freq);
  //     PIN_high(PIN_BEEP);
  //     Delay_Us(255 - freq);
  //   }
}

// Pseudo random number generator
uint16_t rnval = 0xACE1;
uint16_t JOY_random(void) {
  rnval = (rnval >> 0x01) ^ (-(rnval & 0x01) & 0xB400);
  return rnval;
}

// Delays
#define JOY_DLY_ms Delay_Ms
#define JOY_DLY_us Delay_Us

// Additional Defines
#define abs(n) ((n >= 0) ? (n) : (-(n)))

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

#ifdef __cplusplus
};
#endif
