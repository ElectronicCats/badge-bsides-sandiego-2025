/********************************** (C) COPYRIGHT
 ******************************** File Name          : main.c Author : WCH
 * Version            : V1.0.0
 * Date               : 2023/12/25
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 *Multiprocessor communication mode routine:
 *Master:USART1_Tx(PD5)\USART1_Rx(PD6).
 *This routine demonstrates that USART1 receives the data sent by CH341 and
 *inverts it and sends it (baud rate 115200).
 *
 *Hardware connection:PD5 -- Rx
 *                     PD6 -- Tx
 *
 */

#include <limits.h>
#include "../SSD1306/include/ssd1306.h"
#include "bitmaps.h"
#include "debug.h"
#include "driver.h"
#include "hardware_tests.h"
#include "menus.h"
#include "tetris.h"

uint16_t valueInFlash;

void USARTx_CFG(void);

int main() {
  SystemCoreClockUpdate();
  Delay_Init();
#if (SDI_PRINT == SDI_PR_OPEN)
  SDI_Printf_Enable();
#else
  USART_Printf_Init(115200);
#endif

  // Setup
  // USARTx_CFG();
  JOY_init();
  ssd1306_setbuf(0);
  ssd1306_refresh();
  ssd1306_drawImage(epd_bitmap_bsides_logo, 0, 0, 128, 32, COLOR_NORMAL);
  ssd1306_refresh();

  // Blink all the LEDs
  uint8_t delay = 50;
  for (uint8_t i = 0; i < leds_count; i++) {
    PIN_high(leds[i]);
    JOY_DLY_ms(delay);
    PIN_low(leds[i]);
    JOY_DLY_ms(delay);
  }
  Delay_Ms(500);  // Keep the logo on the screen for a while
  // flash_test();
  // hardware_tests_start();
  menus_init();
  // tetris_start();
}

/*********************************************************************
 * @fn      USARTx_CFG
 *
 * @brief   Initializes the USART2 & USART3 peripheral.
 *
 * @return  none
 */
void USARTx_CFG(void) {
  GPIO_InitTypeDef GPIO_InitStructure = {0};
  USART_InitTypeDef USART_InitStructure = {0};

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1, ENABLE);

  /* USART1 TX-->D.5   RX-->D.6 */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl =
      USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

  USART_Init(USART1, &USART_InitStructure);
  USART_Cmd(USART1, ENABLE);
}
