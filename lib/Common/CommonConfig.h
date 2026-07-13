/******************************************************************************
 * Project : AccelMeter
 * Module  : Common
 * File    : CommonConfig.h
 * Version : 1.0.0
 ******************************************************************************/

#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

#include <Arduino.h>

namespace Constants
{
    constexpr float GRAVITY = 9.80665f;

    constexpr float PI = 3.14159265f;

    constexpr float RAD2DEG = 57.2957795f;

    constexpr float DEG2RAD = 0.0174532925f;
}

#endif