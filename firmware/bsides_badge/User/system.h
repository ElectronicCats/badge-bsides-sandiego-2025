// ===================================================================================
// Basic System Functions for CH32V003                                        * v1.6 *
// ===================================================================================
//
// This file must be included!!! The system configuration and the system clock are 
// set up automatically on system start.
//
// System clock functions available:
// ---------------------------------
// CLK_init_HSI()           init internal oscillator (non PLL) as system clock source
// CLK_init_HSI_PLL()       init internal oscillator with PLL as system clock source
// CLK_init_HSE()           init external crystal (non PLL) as system clock source
// CLK_init_HSE_PLL()       init external crystal (PLL) as system clock source
// CLK_reset()              reset system clock to default state
//
// HSI_enable()             enable internal 8MHz high-speed clock (HSI)
// HSI_disable()            disable HSI
// HSI_ready()              check if HSI is stable
//
// HSE_enable()             enable external high-speed clock (HSE)
// HSE_disable()            disable HSE
// HSE_ready()              check if HSE is stable
// HSE_bypass_on()          enable HSE clock bypass
// HSE_bypass_off()         disable HSE clock bypass
//
// LSI_enable()             enable internal 128kHz low-speed clock (LSI)
// LSI_disable()            disable LSI
// LSI_ready()              check if LSI is stable
//
// PLL_enable()             enable phase-locked loop (PLL)
// PLL_disable()            disable PLL
// PLL_ready()              check if PLL is stable
// PLL_setHSI()             set HSI as PLL input (PLL muste be disabled)
// PLL_setHSE()             set HSE as PLL input (PLL muste be disabled)
//
// MCO_init()               init clock output to pin PC4
// MCO_setSYS()             output SYS_CLK on pin PC4
// MCO_setHSI()             output internal oscillator on pin PC4
// MCO_setHSE()             output external crystal on pin PC4 (if available)
// MCO_setPLL()             output PLL on pin PC4
//
// Delay (DLY) functions available:
// --------------------------------
// DLY_ticks(n)             delay n clock cycles
// DLY_us(n)                delay n microseconds
// DLY_ms(n)                delay n milliseconds
//
// Reset (RST) and Bootloader (BOOT) functions available:
// ------------------------------------------------------
// BOOT_now()               conduct software reset and jump to bootloader
// RST_now()                conduct software reset
// RST_clearFlags()         clear all reset flags
// RST_wasLowPower()        check if last reset was caused by low power
// RST_wasWWDG()            check if last reset was caused by window watchdog
// RST_wasIWDG()            check if last reset was caused by independent watchdog
// RST_wasSoftware()        check if last reset was caused by software
// RST_wasPower()           check if last reset was caused by power up
// RST_wasPin()             check if last reset was caused by RST pin low
//
// Independent Watchdog Timer (IWDG) functions available:
// ------------------------------------------------------
// IWDG_start(n)            start independent watchdog timer, n milliseconds, n<=8191
// IWDG_reload(n)           reload watchdog counter with n milliseconds, n<=8191
// IWDG_feed()              feed the dog (reload last time)
//
// Automatic Wake-up Timer (AWU) functions available:
// --------------------------------------------------
// AWU_start(n)             start AWU with n milliseconds period and event trigger
// AWU_stop()               stop AWU and event trigger
// AWU_set(n)               set AWU period to n milliseconds
//
// AWU_enable()             enable AWU (without LSI and PWR module)
// AWU_disable()            disable AWU (without LSI and PWR module)
// AWU_RT_enable()          enable AWU rising edge trigger
// AWU_RT_disable()         disable AWU rising edge trigger
// AWU_EV_enable()          enable AWU event
// AWU_EV_disable()         disable AWU event
// AWU_INT_enable()         enable AWU interrupt (without NVIC)
// AWU_INT_disable()        disable AWU interrupt (without NVIC)
//
// Sleep functions available:
// --------------------------
// SLEEP_WFI_now()          put device into sleep, wake up by interrupt
// SLEEP_WFE_now()          put device into sleep, wake up by event
// STDBY_WFI_now()          put device into standby (deep sleep), wake by interrupt
// STDBY_WFE_now()          put device into standby (deep sleep), wake by event
//
// SLEEP_ms(n)              put device into SLEEP for n milliseconds (uses AWU)
// STDBY_ms(n)              put device into STANDBY for n milliseconds (uses AWU)
//
// Programmable Voltage Detector (PVD) functions available:
// --------------------------------------------------------
// PVD_enable()             enable PVD
// PVD_set_2V7()            set detection level to 2.7V  falling / 2.85V rising edge
// PVD_set_2V9()            set detection level to 2.9V  falling / 3.05V rising edge
// PVD_set_3V15()           set detection level to 3.15V falling / 3.3V  rising edge
// PVD_set_3V3()            set detection level to 3.3V  falling / 3.5V  rising edge
// PVD_set_3V5()            set detection level to 3.5V  falling / 3.7V  rising edge
// PVD_set_3V7()            set detection level to 3.7V  falling / 3.9V  rising edge
// PVD_set_3V9()            set detection level to 3.9V  falling / 4.1V  rising edge
// PVD_set_4V2()            set detection level to 4.2V  falling / 4.4V  rising edge
// PVD_isLow()              check if VDD is below detection level
//
// Interrupt (INT) functions available:
// ------------------------------------
// INT_enable()             global interrupt enable
// INT_disable()            global interrupt disable
// INT_ATOMIC_BLOCK { }     execute block without being interrupted
//
// References:
// -----------
// - CNLohr ch32v003fun: https://github.com/cnlohr/ch32v003fun
// - WCH Nanjing Qinheng Microelectronics: http://wch.cn
//
// 2023 by Stefan Wagner:   https://github.com/wagiminator

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "ch32v00x.h"

// ===================================================================================
// System Options (set "1" to activate)
// ===================================================================================
#define SYS_CLK_INIT      1         // 1: init system clock on startup
#define SYS_TICK_INIT     1         // 1: init and start SYSTICK on startup
#define SYS_GPIO_EN       1         // 1: enable GPIO ports on startup
#define SYS_CLEAR_BSS     1         // 1: clear uninitialized variables
#define SYS_USE_VECTORS   0         // 1: create interrupt vector table
#define SYS_USE_HSE       0         // 1: use external crystal

// ===================================================================================
// Sytem Clock Defines
// ===================================================================================
// Set system clock frequency
#ifndef F_CPU
  #define F_CPU           24000000  // 24Mhz if not otherwise defined
#endif

// Calculate system clock settings
#if   F_CPU == 48000000
  #define CLK_DIV         RCC_HPRE_DIV1
  #define SYS_USE_PLL
#elif F_CPU == 24000000
  #define CLK_DIV         RCC_HPRE_DIV1
#elif F_CPU == 16000000
  #define CLK_DIV         RCC_HPRE_DIV3
  #define SYS_USE_PLL
#elif F_CPU == 12000000
  #define CLK_DIV         RCC_HPRE_DIV2
#elif F_CPU ==  8000000
  #define CLK_DIV         RCC_HPRE_DIV3
#elif F_CPU ==  6000000
  #define CLK_DIV         RCC_HPRE_DIV4
#elif F_CPU ==  4000000
  #define CLK_DIV         RCC_HPRE_DIV6
#elif F_CPU ==  3000000
  #define CLK_DIV         RCC_HPRE_DIV8
#elif F_CPU ==  1500000
  #define CLK_DIV         RCC_HPRE_DIV16
#elif F_CPU ==   750000
  #define CLK_DIV         RCC_HPRE_DIV32
#elif F_CPU ==   375000
  #define CLK_DIV         RCC_HPRE_DIV64
#elif F_CPU ==   187500
  #define CLK_DIV         RCC_HPRE_DIV128
#elif F_CPU ==    93750
  #define CLK_DIV         RCC_HPRE_DIV256
#else
  #warning Unsupported system clock frequency, using internal 24MHz
  #define CLK_DIV         RCC_HPRE_DIV1
  #undef  F_CPU
  #define F_CPU           24000000
#endif

#if SYS_USE_HSE > 0
  #ifdef SYS_USE_PLL
    #define CLK_init      CLK_init_HSE_PLL
  #else
    #define CLK_init      CLK_init_HSE
  #endif
#else
  #ifdef SYS_USE_PLL
    #define CLK_init      CLK_init_HSI_PLL
  #else
    #define CLK_init      CLK_init_HSI
  #endif
#endif

#ifdef __cplusplus
};
#endif
