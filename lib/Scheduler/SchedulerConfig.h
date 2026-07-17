/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Scheduler
 * File       : SchedulerConfig.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Scheduler timing configuration.
 *
 ******************************************************************************/

 #ifndef SCHEDULER_CONFIG_H
 #define SCHEDULER_CONFIG_H
 
 #include <Arduino.h>
 
 /*=============================================================================
     Scheduler Tick
 =============================================================================*/
 
 constexpr uint16_t kSchedulerTick = 1U;          // ms
 
 /*=============================================================================
     Task Periods
 =============================================================================*/
 
 constexpr uint16_t kSensorPeriod        = 10U;   // 100 Hz
 
 constexpr uint16_t kCalibrationPeriod   = 10U;   // 100 Hz
 
 constexpr uint16_t kFilterPeriod        = 10U;   // 100 Hz
 
 constexpr uint16_t kStatisticsPeriod    = 10U;   // 100 Hz
 
 constexpr uint16_t kDisplayPeriod       = 100U;  // 10 Hz
 
 constexpr uint16_t kProtocolPeriod      = 50U;   // 20 Hz
 
 #endif // SCHEDULER_CONFIG_H