/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : Display.h
 *
 * Version    : 1.0.0
 *
 * Description:
 *      LCD Display module.
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
 
     void nextPage();
 
     void previousPage();
 
     DisplayPage currentPage() const;
 
     void setPage(DisplayPage page);
 
 private:
 
     /*
         Runtime
     */
 
     DisplayRuntime runtime_;
 
     /*
         LCD
     */
 
     LiquidCrystal_I2C lcd_;
 
     /*
         Cache
     */
 
     DisplayCache cache_;
 
     /*
         Main Refresh
     */
 
     void refresh(Model& model);
 
     /*
         Individual Pages
     */
 
     void pageAcceleration(const Model& model);
 
     void pageMagnitude(const Model& model);
 
     void pageStatistics(const Model& model);
 
     void pageStatus(const Model& model);
 
     /*
         LCD Helpers
     */
 
     void clearCache();
 
     void printLine(uint8_t row,
                    const char* text);
 
     void printValue(uint8_t row,
                     const char* label,
                     float value,
                     uint8_t precision = 2);
 
     void printStatus(uint8_t row,
                      const char* label,
                      const char* value);
 };
 
 /*=============================================================================
     Global Instance
 =============================================================================*/
 
 extern Display display;
 
 #endif // DISPLAY_H