/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : Display.h
 *
 * Version    : 2.0.0
 *
 * Description:
 *      LCD Display module interface.
 *
 ******************************************************************************/

 #ifndef DISPLAY_H
 #define DISPLAY_H
 
 #include <Arduino.h>
 #include <LiquidCrystal_I2C.h>
 
 #include "Model.h"
 #include "DisplayPrivate.h"
 
 /*=============================================================================
     Display Class
 =============================================================================*/
 
 class Display
 {
 public:
 
     Display();
 
     bool begin();
 
     bool update(Model& model);
 
 private:
 
     /*---------------------------------------------------------------------
         Runtime
     ---------------------------------------------------------------------*/
 
     DisplayRuntime runtime_;
 
     DisplayCache cache_;
 
     LiquidCrystal_I2C lcd_;
 
     /*---------------------------------------------------------------------
         Main Functions
     ---------------------------------------------------------------------*/
 
     void refresh(Model& model);
 
     /*---------------------------------------------------------------------
         Page Control
     ---------------------------------------------------------------------*/
 
     void nextPage();
 
     void previousPage();
 
     /*---------------------------------------------------------------------
         Page Renderers
     ---------------------------------------------------------------------*/
 
     void showAcceleration(const Model& model);
 
     void showMagnitude(const Model& model);
 
     void showStatistics(const Model& model);
 
     /*---------------------------------------------------------------------
         LCD Helpers
     ---------------------------------------------------------------------*/
 
     void clearCache();
 
     void updateLine(
         uint8_t row,
         const char* text);
 
     void writeCache();
 
     bool lineChanged(
         const char* source,
         const char* destination) const;
 };
 
 /*=============================================================================
     Global Instance
 =============================================================================*/
 
 extern Display display;
 
 #endif // DISPLAY_H