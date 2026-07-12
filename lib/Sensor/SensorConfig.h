#ifndef SENSOR_CONFIG_H
#define SENSOR_CONFIG_H

#include <Arduino.h>
#include <Adafruit_MPU6050.h>

/**************************************************
 * MPU6050 Configuration
 **************************************************/

constexpr auto ACC_RANGE =
MPU6050_RANGE_8_G;

constexpr auto GYRO_RANGE =
MPU6050_RANGE_500_DEG;

constexpr auto FILTER_BAND =
MPU6050_BAND_21_HZ;

/**************************************************
 * Sample Rate
 **************************************************/

constexpr uint16_t SENSOR_RATE_HZ = 100;

#endif


//#include <Adafruit_MPU6050.h>

//constexpr auto ACC_RANGE  = MPU6050_RANGE_8_G;
//constexpr auto GYRO_RANGE = MPU6050_RANGE_500_DEG;
//constexpr auto DLPF_BW    = MPU6050_BAND_21_HZ;