/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : DisplayConfig.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Configuration constants for Display module.
 *
 ******************************************************************************/

 #ifndef DISPLAY_CONFIG_H
 #define DISPLAY_CONFIG_H
 
 #include <Arduino.h>
 
 /*=============================================================================
     Module Version
 =============================================================================*/
 
 constexpr uint8_t kDisplayVersionMajor = 1U;
 constexpr uint8_t kDisplayVersionMinor = 0U;
 constexpr uint8_t kDisplayVersionPatch = 0U;
 
 /*=============================================================================
     LCD Configuration
 =============================================================================*/
 
 constexpr uint8_t kLcdAddress = 0x27;
 
 constexpr uint8_t kLcdColumns = 16U;
 
 constexpr uint8_t kLcdRows = 4U;
 
 /*=============================================================================
     Display Refresh
 =============================================================================*/
 
 //constexpr uint16_t kDisplayRefreshPeriod = 100U;
 
 
 
 /*=============================================================================
     Formatting
 =============================================================================*/
 
 constexpr uint8_t kFloatPrecision = 2U;
 
 constexpr bool kAutoClearUnusedCharacters = true;
 
 #endif // DISPLAY_CONFIG_H