/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Statistics
 * File       : Statistics.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Statistical processing module.
 *
 ******************************************************************************/

 #ifndef STATISTICS_H
 #define STATISTICS_H
 
 #include <Arduino.h>
 
 #include "Model.h"
 #include "StatisticsConfig.h"
 #include "StatisticsPrivate.h"
 
 /*=============================================================================
     Statistics Module
 =============================================================================*/
 
 class Statistics
 {
 public:
 
     Statistics();
 
     bool begin();
 
     bool update(Model& model);
 
 private:
 
     /*-----------------------------------------------------------------------
         Processing
     -----------------------------------------------------------------------*/
 
     void updateMagnitude(Model& model);
 
     void updateMean(Model& model);
 
     void updateRms(Model& model);
 
     void updatePeak(Model& model);
 
     void updateSampleRate(Model& model);
 
     /*-----------------------------------------------------------------------
         Runtime
     -----------------------------------------------------------------------*/
 
     StatisticsRuntime runtime_;
 };
 
 /*=============================================================================
     Global Instance
 =============================================================================*/
 
 extern Statistics statistics;
 
 #endif // STATISTICS_H