/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Model
 * File       : ModelConfig.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      Global configuration constants for the firmware data model.
 *
 ******************************************************************************/

#ifndef MODEL_CONFIG_H
#define MODEL_CONFIG_H

#include <Arduino.h>

/*=============================================================================
    Model Version
=============================================================================*/

constexpr uint8_t kModelVersionMajor = 1U;
constexpr uint8_t kModelVersionMinor = 0U;
constexpr uint8_t kModelVersionPatch = 0U;

/*=============================================================================
    Internal Units
=============================================================================*/

/*
 * IMPORTANT
 *
 * All acceleration values inside the firmware shall be stored
 * in SI units (m/s²).
 *
 * Conversion to "g" shall only be performed by the Display
 * or Protocol modules.
 */

/*=============================================================================
    Physical Constants
=============================================================================*/

constexpr float kStandardGravity = 9.80665f;

/*=============================================================================
    Sampling Configuration
=============================================================================*/

constexpr uint16_t kDefaultSampleRate = 100U;      // Hz

/*=============================================================================
    Statistics Configuration
=============================================================================*/

constexpr uint16_t kRmsWindowSize = 100U;

/*=============================================================================
    Communication
=============================================================================*/

constexpr uint32_t kDefaultBaudRate = 115200UL;

/*=============================================================================
    Display
=============================================================================*/

constexpr uint16_t kLcdRefreshPeriod = 250U;       // ms

#endif // MODEL_CONFIG_H