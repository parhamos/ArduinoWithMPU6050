#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

//==================================================
// Project Information
//==================================================

#define PROJECT_NAME        "AccelMeter"
#define PROJECT_VERSION     "1.0.0"

//==================================================
// Serial Port
//==================================================

constexpr uint32_t SERIAL_BAUD = 115200;

//==================================================
// System Timing (ms)
//==================================================

constexpr uint16_t SENSOR_PERIOD_MS  = 10;    // 100Hz
constexpr uint16_t LCD_PERIOD_MS     = 100;   // 10Hz
constexpr uint16_t SERIAL_PERIOD_MS  = 50;    // 20Hz
constexpr uint16_t BUTTON_PERIOD_MS  = 20;    // 50Hz

//==================================================
// General Settings
//==================================================

constexpr bool ENABLE_SERIAL = true;
constexpr bool ENABLE_LCD    = true;

#endif