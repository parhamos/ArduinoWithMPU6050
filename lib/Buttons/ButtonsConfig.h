/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Buttons
 * File       : ButtonsConfig.h
 *
 * Version    : 2.1.0
 *
 * Description:
 *      Hardware and timing configuration
 *      for the Buttons module.
 *
 ******************************************************************************/

#ifndef BUTTONS_CONFIG_H
#define BUTTONS_CONFIG_H

#include <Arduino.h>

/*=============================================================================
    Hardware Pins
=============================================================================*/

constexpr uint8_t kButtonNextPin     = 2U;

constexpr uint8_t kButtonPreviousPin = 3U;

constexpr uint8_t kButtonOkPin       = 4U;

constexpr uint8_t kButtonF1Pin       = 5U;

constexpr uint8_t kButtonF2Pin       = 6U;

constexpr uint8_t kButtonF3Pin       = 7U;

/*=============================================================================
    Button Logic
=============================================================================*/

/*
    LOW = Button pressed
    HIGH = Button released
*/

constexpr bool kButtonPressedLevel = LOW;

/*=============================================================================
    Timing (milliseconds)
=============================================================================*/

/*
    Debounce filter time
*/

constexpr uint16_t kDebounceTime = 30U;

/*
    Long press detection time
*/

constexpr uint16_t kLongPressTime = 1000U;

/*
    Auto-repeat period
    (Reserved for future versions)
*/

constexpr uint16_t kRepeatTime = 250U;

#endif // BUTTONS_CONFIG_H