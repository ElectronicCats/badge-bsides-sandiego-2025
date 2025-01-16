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
#include "ch32v003_flash.h"
#include "debug.h"
#include "driver.h"
#include "tetris.h"

// Define this constant to use compile-time
// flash addresses in the below example code.
#define USE_COMPILE_TIME_ADDRESSES 1

#ifdef USE_COMPILE_TIME_ADDRESSES
  // Compile-time determined address for flash memory
  #define NONVOLATILE_START_ADDR FLASH_PRECALCULATE_NONVOLATILE_ADDR(0)
  #define NONVLOATILE_VAR_ADDR   FLASH_PRECALCULATE_NONVOLATILE_ADDR(10)
#else
// Runtime determined address for flash memory
uint32_t nonvolatile_var_addr;
uint32_t nonvolatile_start_addr;
#endif

uint16_t valueInFlash;

void USARTx_CFG(void);
void flash_test();

int main() {
  SystemCoreClockUpdate();
  Delay_Init();
#if (SDI_PRINT == SDI_PR_OPEN)
  SDI_Printf_Enable();
#else
  USART_Printf_Init(115200);
#endif
  APP_DBG("SystemClk: %d MHz", SystemCoreClock / 1000000);
  APP_DBG("ChipID:%08x\r\n", DBGMCU_GetCHIPID());

  // Setup
  USARTx_CFG();
  JOY_init();
  ssd1306_setbuf(0);
  ssd1306_refresh();
  ssd1306_drawImage(epd_bitmap_bsides_logo, 0, 0, 128, 32, 0);
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
  flash_test();

  // Loop
  APP_DBG("Starting...\r\n");
  tetris_start();
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

void flash_test() {
  // Set the flash latency for proper operation.
  flash_set_latency();
  APP_DBG("FLASH_LENGTH_OVERRIDE is        %u\r\n",
          (uint16_t) (uintptr_t) FLASH_LENGTH_OVERRIDE);

#ifdef USE_COMPILE_TIME_ADDRESSES
  APP_DBG("non-volatile start address is   %lu\r\n", NONVOLATILE_START_ADDR);
  APP_DBG("non-volatile var address is     %lu\r\n", NONVLOATILE_VAR_ADDR);
#else
  nonvolatile_start_addr = flash_calcualte_nonvolatile_addr(
      0);  // Calculate the start address for non-volatile data at runtime.
  nonvolatile_var_addr = flash_calcualte_nonvolatile_addr(
      10);  // Calculate the variable address for non-volatile data at runtime.
  APP_DBG("non-volatile start address is   %lu\r\n", nonvolatile_start_addr);
  APP_DBG("non-volatile var address is     %lu\r\n", nonvolatile_var_addr);
#endif

  int writeCount = 0;

#ifdef USE_COMPILE_TIME_ADDRESSES
  valueInFlash = flash_read_16_bits(
      NONVLOATILE_VAR_ADDR);  // Read a 16-bit value from flash memory at the
                              // predefined address.
  if (valueInFlash == UINT16_MAX) {
    APP_DBG("Value not found. Setting to 0.\r\n");
    valueInFlash = 0;
  }
#else
  valueInFlash = flash_read_16_bits(
      nonvolatile_var_addr);  // Read a 16-bit value from flash memory at the
                              // runtime determined address.
#endif

  APP_DBG("   Saved value is %u\r\n", valueInFlash);

  // Prevent more than 5 writes per power-on, as writing to flash is a limited
  // resource.
  if (writeCount >= 5) {
    APP_DBG("Done writing. Wait...\r\n");
    Delay_Ms(1000);  // Delay for 1000 milliseconds (1 second).
    // continue;
  } else {
    writeCount++;

    // Decrease the value to be written to flash by 1
    valueInFlash++;

    // Unlock writing to flash memory
    flash_unlock();
    APP_DBG("Memory unlocked\r\n");

    // This erases a 64-byte page in the flash memory.
    // Note: smaller erases are not possible on the CH32V003.
#ifdef USE_COMPILE_TIME_ADDRESSES
    flash_erase_page(
        NONVOLATILE_START_ADDR);  // Erase a 64-bit block of flash memory at the
                                  // predefined start address.
#else
    flash_erase_page(
        nonvolatile_start_addr);  // Erase a 64-bit block of flash memory at the
                                  // runtime determined start address.
#endif
    APP_DBG("Memory erased\r\n");

#ifdef USE_COMPILE_TIME_ADDRESSES
    flash_program_16(NONVLOATILE_VAR_ADDR,
                     valueInFlash);  // Write a 16-bit value to flash memory at
                                     // the predefined address.
#else
    flash_program_16(nonvolatile_var_addr,
                     valueInFlash);  // Write a 16-bit value to flash memory at
                                     // the runtime determined address.
#endif
    APP_DBG("Memory written\r\n");

    // Lock flash memory
    flash_lock();
    APP_DBG("Memory locked. \r\nWaiting...\r\n");
  }
}
