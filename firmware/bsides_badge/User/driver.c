#include "driver.h"

uint8_t leds[] = {LED1_PIN,
#ifndef DEBUG_ENABLE
                  LED2_PIN,
#endif
                  LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN, LED8_PIN};
uint8_t leds_count = sizeof(leds) / sizeof(leds[0]);

// Init driver
void JOY_init(void) {
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
#ifndef DEV_VERSION
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_6;
#else
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
#endif
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_30MHz;
  GPIO_Init(GPIOC, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_30MHz;
  GPIO_Init(GPIOD, &GPIO_InitStruct);

#ifndef DEV_VERSION
  GPIO_PinRemapConfig(GPIO_Remap_PA1_2, DISABLE);
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_30MHz;
  GPIO_Init(GPIOA, &GPIO_InitStruct);
#endif

  OLED_init();
}

uint8_t joy_up_pressed(void) {
  return !PIN_read(BUTTON_UP_PIN);
}

uint8_t joy_down_pressed(void) {
  return !PIN_read(BUTTON_DOWN_PIN);
}

uint8_t joy_left_pressed(void) {
  return !PIN_read(BUTTON_LEFT_PIN);
}

uint8_t joy_right_pressed(void) {
  return !PIN_read(BUTTON_RIGHT_PIN);
}

// Pseudo random number generator
uint16_t rnval = 0xACE1;
uint16_t JOY_random(void) {
  rnval = (rnval >> 0x01) ^ (-(rnval & 0x01) & 0xB400);
  return rnval;
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
