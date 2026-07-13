/******************************************************************************
 * Project : AccelMeter
 * Module  : Model
 * File    : ModelConfig.h
 * Version : 1.0.0
 *
 * Description:
 *      Global configuration for the Data Model.
 ******************************************************************************/

#ifndef MODEL_CONFIG_H
#define MODEL_CONFIG_H

#include <Arduino.h>

/*===========================================================================
    Model Version
===========================================================================*/

#define MODEL_VERSION_MAJOR      1
#define MODEL_VERSION_MINOR      0
#define MODEL_VERSION_PATCH      0

/*===========================================================================
    Internal Units
===========================================================================*/

/*
    IMPORTANT

    All acceleration values inside the firmware
    are stored in SI units (m/s²).

    Conversion to g is performed only by Display
    or Protocol modules.
*/

/*===========================================================================
    Measurement
===========================================================================*/

constexpr uint16_t DEFAULT_SAMPLE_RATE = 100;      // Hz
constexpr float STANDARD_GRAVITY = 9.80665f;       // m/s²

/*===========================================================================
    Statistics
===========================================================================*/

constexpr uint16_t RMS_WINDOW_SIZE = 100;

/*===========================================================================
    Communication
===========================================================================*/

constexpr uint32_t DEFAULT_BAUDRATE = 115200UL;

/*===========================================================================
    LCD
===========================================================================*/

constexpr uint16_t LCD_REFRESH_MS = 250;

#endif