/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Buttons
 * File       : ButtonsPrivate.h
 *
 * Version    : 2.1.0
 *
 * Description:
 *      Internal button data structures.
 *      Used only by Buttons module.
 *
 ******************************************************************************/

#ifndef BUTTONS_PRIVATE_H
#define BUTTONS_PRIVATE_H

#include <Arduino.h>

/*=============================================================================
    Button Identifier
=============================================================================*/

enum class ButtonId : uint8_t
{
    None = 0,

    Next,
    Previous,
    Ok,

    F1,
    F2,
    F3
};

/*=============================================================================
    Button Event Type
=============================================================================*/

enum class ButtonEventType : uint8_t
{
    None = 0,

    Press,

    Release,

    LongPress
};

/*=============================================================================
    Button Event
=============================================================================*/

struct ButtonEvent
{
    ButtonId id = ButtonId::None;

    ButtonEventType type = ButtonEventType::None;
};

/*=============================================================================
    Button Runtime
=============================================================================*/

struct ButtonRuntime
{
    bool currentState = false;

    bool previousState = false;

    bool longPressGenerated = false;

    uint32_t debounceTimer = 0U;

    uint32_t pressTimer = 0U;
};

#endif