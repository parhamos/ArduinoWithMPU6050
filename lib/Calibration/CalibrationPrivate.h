/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Calibration
 * File       : CalibrationPrivate.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Private runtime objects for Calibration module.
 *
 ******************************************************************************/

 #ifndef CALIBRATION_PRIVATE_H
 #define CALIBRATION_PRIVATE_H
 
 #include <Arduino.h>
 
 #include "Model.h"
 
 /*=============================================================================
     Runtime Data
 =============================================================================*/
 
 struct CalibrationRuntime
 {
     /*---------------------------------------------------------------------
         Calibration Status
     ---------------------------------------------------------------------*/
 
     bool calibrating;
 
     bool calibrated;
 
     /*---------------------------------------------------------------------
         Sample Counter
     ---------------------------------------------------------------------*/
 
     uint16_t sampleCount;
 
     /*---------------------------------------------------------------------
         Accumulator
     ---------------------------------------------------------------------*/
 
     Vector3f accumulator;
 
     /*---------------------------------------------------------------------
         Constructor
     ---------------------------------------------------------------------*/
 
     CalibrationRuntime()
         :
         calibrating(false),
         calibrated(false),
         sampleCount(0U)
     {
         accumulator.x = 0.0f;
         accumulator.y = 0.0f;
         accumulator.z = 0.0f;
     }
 };
 
 #endif // CALIBRATION_PRIVATE_H