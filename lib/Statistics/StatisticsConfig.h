/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Statistics
 * File       : StatisticsConfig.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Configuration constants for Statistics module.
 *
 ******************************************************************************/

 #ifndef STATISTICS_CONFIG_H
 #define STATISTICS_CONFIG_H
 
 #include <Arduino.h>
 
 /*=============================================================================
     Module Version
 =============================================================================*/
 
 constexpr uint8_t kStatisticsVersionMajor = 2U;
 constexpr uint8_t kStatisticsVersionMinor = 0U;
 constexpr uint8_t kStatisticsVersionPatch = 0U;
 
 /*=============================================================================
     Statistics Window
 =============================================================================*/
 
 constexpr uint16_t kStatisticsWindowSize = 100U;
 
 /*=============================================================================
     Enable Calculations
 =============================================================================*/
 
 constexpr bool kEnableMagnitude  = true;
 constexpr bool kEnableMean       = true;
 constexpr bool kEnableRms        = true;
 constexpr bool kEnablePeak       = true;
 constexpr bool kEnableSampleRate = true;
 
 /*=============================================================================
     Peak Detection
 =============================================================================*/
 
 constexpr bool kPeakUseAbsoluteValue = true;
 
 /*=============================================================================
     Magnitude
 =============================================================================*/
 
 constexpr bool kMagnitudeUseFilteredData = true;
 
 /*=============================================================================
     Runtime Update
 =============================================================================*/
 
 constexpr bool kContinuousUpdate = true;
 
 #endif // STATISTICS_CONFIG_H