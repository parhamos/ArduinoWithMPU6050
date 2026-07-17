/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Buttons
 * File       : ButtonsConfig.h
 *
 * Version    : 1.0.0
 *
 ******************************************************************************/

 #ifndef BUTTONS_CONFIG_H
 #define BUTTONS_CONFIG_H
 
 #include <Arduino.h>
 
 /*=============================================================================
     Hardware
 =============================================================================*/
 
 constexpr uint8_t kButtonNextPin = 2;
 
 constexpr uint8_t kButtonPreviousPin = 3;
 
 constexpr uint8_t kButtonOkPin = 4;
 
 /*=============================================================================
     Logic
 =============================================================================*/
 
 constexpr bool kButtonActiveLevel = LOW;
 
 constexpr uint16_t kDebounceTime = 30U;
 
 #endif