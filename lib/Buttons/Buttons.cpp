/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Buttons
 * File       : Buttons.cpp
 *
 * Version    : 2.1.0
 *
 * Description:
 *      Button manager implementation.
 *
 ******************************************************************************/

#include "Buttons.h"

#include "ButtonsConfig.h"

/*=============================================================================
    Global Instance
=============================================================================*/

Buttons buttons;

/*=============================================================================
    Constructor
=============================================================================*/

Buttons::Buttons()
{
}

/*=============================================================================
    Initialization
=============================================================================*/

bool Buttons::begin()
{
    /*
        Configure GPIO
    */

    pinMode(kButtonNextPin,     INPUT_PULLUP);

    pinMode(kButtonPreviousPin, INPUT_PULLUP);

    pinMode(kButtonOkPin,       INPUT_PULLUP);

    pinMode(kButtonF1Pin,       INPUT_PULLUP);

    pinMode(kButtonF2Pin,       INPUT_PULLUP);

    pinMode(kButtonF3Pin,       INPUT_PULLUP);

    /*
        Reset Runtime Objects
    */

    next_ = {};

    previous_ = {};

    ok_ = {};

    f1_ = {};

    f2_ = {};

    f3_ = {};

    /*
        Reset Event
    */

    event_.id   = ButtonId::None;

    event_.type = ButtonEventType::None;

    return true;
}

/*=============================================================================
    Update
=============================================================================*/

bool Buttons::update()
{
    /*
        Clear Previous Event
    */

    event_.id   = ButtonId::None;

    event_.type = ButtonEventType::None;

    /*
        Scan Buttons
    */

    updateButton(next_,
                 kButtonNextPin,
                 ButtonId::Next);

    updateButton(previous_,
                 kButtonPreviousPin,
                 ButtonId::Previous);

    updateButton(ok_,
                 kButtonOkPin,
                 ButtonId::Ok);

    updateButton(f1_,
                 kButtonF1Pin,
                 ButtonId::F1);

    updateButton(f2_,
                 kButtonF2Pin,
                 ButtonId::F2);

    updateButton(f3_,
                 kButtonF3Pin,
                 ButtonId::F3);

    return true;
}

/*=============================================================================
    Update Button
=============================================================================*/

void Buttons::updateButton(
    ButtonRuntime& button,
    uint8_t pin,
    ButtonId id)
{
    const bool level =
        (digitalRead(pin) == kButtonPressedLevel);

    /*
        State Changed
    */

    if(level != button.previousState)
    {
        button.debounceTimer = millis();

        button.previousState = level;
    }

    /*
        Debounce
    */

    if((millis() - button.debounceTimer) < kDebounceTime)
    {
        return;
    }

    /*
        Press
    */

    if(level != button.currentState)
    {
        button.currentState = level;

        if(level)
        {
            button.pressTimer = millis();

            button.longPressGenerated = false;

            event_.id   = id;

            event_.type = ButtonEventType::Press;
        }

        return;
    }

    /*
        Long Press
    */

    if(level)
    {
        if(!button.longPressGenerated)
        {
            if((millis() - button.pressTimer) >=
                kLongPressTime)
            {
                button.longPressGenerated = true;

                event_.id   = id;

                event_.type = ButtonEventType::LongPress;
            }
        }
    }
}
/*=============================================================================
    Get Event
=============================================================================*/

bool Buttons::getEvent(ButtonEvent& event)
{
    if(event_.type == ButtonEventType::None)
    {
        return false;
    }

    event = event_;

    event_.id   = ButtonId::None;

    event_.type = ButtonEventType::None;

    return true;
}
