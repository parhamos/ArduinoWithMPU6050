/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : DisplayTypes.h
 *
 * Version    : 3.0.0
 *
 * Description:
 *      Display data types.
 *
 ******************************************************************************/

#ifndef DISPLAY_TYPES_H
#define DISPLAY_TYPES_H

#include <Arduino.h>

/*=============================================================================
    Display Pages
=============================================================================*/

enum class DisplayPage : uint8_t
{
    Acceleration = 0,

    Magnitude,

    Statistics,

    System,

    Settings
};

/*=============================================================================
    Display Refresh
=============================================================================*/

enum class DisplayRefresh : uint8_t
{
    None = 0,

    Partial,

    Full
};

/*=============================================================================
    Display Data
=============================================================================*/

// struct DisplayData
// {
//     DisplayPage page;

//     DisplayRefresh refresh;

//     bool pageChanged;

//     bool enabled;
// };

#endif // DISPLAY_TYPES_H