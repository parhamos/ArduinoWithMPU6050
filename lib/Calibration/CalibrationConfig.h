/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Calibration
 * File       : CalibrationConfig.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Configuration parameters for the Calibration module.
 *
 ******************************************************************************/

#ifndef CALIBRATION_CONFIG_H
#define CALIBRATION_CONFIG_H

#include <Arduino.h>

/*=============================================================================
    Module Version
=============================================================================*/

constexpr uint8_t kCalibrationVersionMajor = 1U;
constexpr uint8_t kCalibrationVersionMinor = 0U;
constexpr uint8_t kCalibrationVersionPatch = 0U;

/*=============================================================================
    Calibration Configuration
=============================================================================*/

// Number of samples used to calculate the zero offset.
constexpr uint16_t kCalibrationSampleCount = 100U;

#endif // CALIBRATION_CONFIG_H