/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : DisplayConfig.h
 *
 * Version    : 2.0.0
 *
 ******************************************************************************/

 #ifndef DISPLAY_CONFIG_H
 #define DISPLAY_CONFIG_H
 
 #include <Arduino.h>
 
 /*=============================================================================
     LCD Configuration
 =============================================================================*/
 
 constexpr uint8_t kLcdAddress = 0x27;
 
 constexpr uint8_t kLcdColumns = 16U;
 
 constexpr uint8_t kLcdRows = 2U;
 
 /*=============================================================================
     Update Rate
 =============================================================================*/
 
 constexpr uint16_t kDisplayRefreshPeriod = 100U;
 
 /*=============================================================================
     Formatting
 =============================================================================*/
 
 constexpr uint8_t kAccelerationDigits = 2U;
 
 constexpr uint8_t kMagnitudeDigits = 2U;
 
 constexpr uint8_t kStatisticsDigits = 2U;
 
 /*=============================================================================
     Auto Page Change
 =============================================================================*/
 
 constexpr bool kAutoPageEnabled = false;
 
 constexpr uint32_t kAutoPagePeriod = 3000UL;
 
 #endif