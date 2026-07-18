/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Calibration
 * File       : Calibration.cpp
 *
 * Version    : 2.0.0
 *
 * Description:
 *      Sensor calibration module.
 *
 ******************************************************************************/

 #include "Calibration.h"

 /*=============================================================================
     Global Instance
 =============================================================================*/
 
 Calibration calibration;
 
 /*=============================================================================
     Constructor
 =============================================================================*/
 
 Calibration::Calibration()
 {
 }
 
 /*=============================================================================
     Initialization
 =============================================================================*/
 
 bool Calibration::begin()
 {
     runtime_.calibrating = false;
     runtime_.calibrated  = false;
 
     runtime_.sampleCount = 0U;
 
     runtime_.accumulator.x = 0.0f;
     runtime_.accumulator.y = 0.0f;
     runtime_.accumulator.z = 0.0f;
 
     return true;
 }
 
 /*=============================================================================
     Update
 =============================================================================*/
 
 bool Calibration::update(Model& model)
 {
     /*
         Calibration in progress
     */
 
     if (runtime_.calibrating)
     {
         accumulateSamples(model);
 
         if (runtime_.sampleCount >= kCalibrationSampleCount)
         {
             calculateOffset(model);
 
             runtime_.calibrating = false;
             runtime_.calibrated  = true;
         }
     }
 
     /*
         Always produce calibrated data.
     */
 
     applyCalibration(model);
 
     return true;
 }
 /*=============================================================================
    Accumulate Samples
=============================================================================*/

void Calibration::accumulateSamples(Model& model)
{
    const MeasurementFrame& m = model.measurement();

    runtime_.accumulator.x += m.raw.x;
    runtime_.accumulator.y += m.raw.y;
    runtime_.accumulator.z += m.raw.z;

    runtime_.sampleCount++;
}

/*=============================================================================
    Calculate Offset
=============================================================================*/

void Calibration::calculateOffset(Model& model)
{
    CalibrationData& calibration = model.calibration();

    calibration.factoryOffset.x =
        runtime_.accumulator.x /
        static_cast<float>(runtime_.sampleCount);

    calibration.factoryOffset.y =
        runtime_.accumulator.y /
        static_cast<float>(runtime_.sampleCount);

    calibration.factoryOffset.z =
        runtime_.accumulator.z /
        static_cast<float>(runtime_.sampleCount);

    calibration.state = CalibrationState::Completed;

    model.status().calibration =
        CalibrationState::Completed;
}
/*=============================================================================
    Apply Calibration
=============================================================================*/

void Calibration::applyCalibration(Model& model)
{
    //const MeasurementFrame& raw = model.measurement();
    CalibrationData& calibration = model.calibration();
    MeasurementFrame& measurement = model.measurement();

    /*
        If calibration has not been completed yet,
        simply pass raw data to calibrated output.
    */

    if (!runtime_.calibrated)
    {
        measurement.calibrated = measurement.raw;
        return;
    }

    /*
        Apply offset compensation
    */

    measurement.calibrated.x =
        measurement.raw.x
        - calibration.factoryOffset.x
        - calibration.zeroOffset.x;

    measurement.calibrated.y =
        measurement.raw.y
        - calibration.factoryOffset.y
        - calibration.zeroOffset.y;

    measurement.calibrated.z =
        measurement.raw.z
        - calibration.factoryOffset.z
        - calibration.zeroOffset.z;
}

/*=============================================================================
    Start Calibration
=============================================================================*/

bool Calibration::start()
{
    runtime_.calibrating = true;
    runtime_.calibrated  = false;

    runtime_.sampleCount = 0U;

    runtime_.accumulator.x = 0.0f;
    runtime_.accumulator.y = 0.0f;
    runtime_.accumulator.z = 0.0f;

    return true;
}

/*=============================================================================
    Reset Calibration
=============================================================================*/

void Calibration::reset()
{
    runtime_.calibrating = false;
    runtime_.calibrated  = false;

    runtime_.sampleCount = 0U;

    runtime_.accumulator.x = 0.0f;
    runtime_.accumulator.y = 0.0f;
    runtime_.accumulator.z = 0.0f;
}

/*=============================================================================
    Calibration Status
=============================================================================*/

bool Calibration::isCalibrated() const
{
    return runtime_.calibrated;
}
/*=============================================================================
    Capture Offset
=============================================================================*/

/*=============================================================================
    Capture Zero Offset
=============================================================================*/

void Calibration::captureOffset(Model& model)
{
    CalibrationData& calibration = model.calibration();

    const MeasurementFrame& measurement = model.measurement();

    calibration.zeroOffset.x = measurement.calibrated.x;

    calibration.zeroOffset.y = measurement.calibrated.y;

    calibration.zeroOffset.z = measurement.calibrated.z;
}
/*=============================================================================
    Factory Reset
=============================================================================*/

/*=============================================================================
    Factory Reset
=============================================================================*/

void Calibration::factoryReset(Model& model)
{
    CalibrationData& calibration = model.calibration();

    calibration.factoryOffset.x = 0.0f;
    calibration.factoryOffset.y = 0.0f;
    calibration.factoryOffset.z = 0.0f;

    calibration.zeroOffset.x = 0.0f;
    calibration.zeroOffset.y = 0.0f;
    calibration.zeroOffset.z = 0.0f;
}