/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Calibration
 * File       : CalibrationConfig.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Configuration constants for Calibration module.
 *
 ******************************************************************************/

 #ifndef CALIBRATION_CONFIG_H
 #define CALIBRATION_CONFIG_H
 
 #include <Arduino.h>
 
 /*=============================================================================
     Module Version
 =============================================================================*/
 
 constexpr uint8_t kCalibrationVersionMajor = 2U;
 constexpr uint8_t kCalibrationVersionMinor = 0U;
 constexpr uint8_t kCalibrationVersionPatch = 0U;
 
 /*=============================================================================
     Calibration Samples
 =============================================================================*/
 
 constexpr uint16_t kCalibrationSampleCount = 200U;
 
 /*=============================================================================
     Features
 =============================================================================*/
 
 constexpr bool kEnableAutoCalibration = true;
 
 constexpr bool kEnableOffsetCompensation = true;
 
 /*=============================================================================
     Gravity Compensation
 =============================================================================
     Remove 1g from Z-axis after calibration.
     (Reserved for future implementation)
 =============================================================================*/
 
 constexpr bool kEnableGravityCompensation = false;
 
 /*=============================================================================
     Runtime Behaviour
 =============================================================================*/
 
 constexpr bool kContinuousCalibration = false;
 
 #endif // CALIBRATION_CONFIG_H