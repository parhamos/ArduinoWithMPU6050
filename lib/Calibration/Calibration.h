/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Calibration
 * File       : Calibration.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Sensor calibration module.
 *
 ******************************************************************************/

 #ifndef CALIBRATION_H
 #define CALIBRATION_H
 
 #include <Arduino.h>
 
 #include "Model.h"
 #include "CalibrationConfig.h"
 #include "CalibrationPrivate.h"
 
 /*=============================================================================
     Calibration Module
 =============================================================================*/
 
 class Calibration
 {
 public:
 
     Calibration();
 
     bool begin();
 
     bool update(Model& model);
 
     bool start();
 
     void reset();
 
     bool isCalibrated() const;
 
 private:
 
     /*-----------------------------------------------------------------------
         Internal Processing
     -----------------------------------------------------------------------*/
 
     void accumulateSamples(Model& model);
 
     void calculateOffset(Model& model);
 
     void applyCalibration(Model& model);
 
 private:
 
     CalibrationRuntime runtime_;
 };
 
 /*=============================================================================
     Global Instance
 =============================================================================*/
 
 extern Calibration calibration;
 
 #endif // CALIBRATION_H