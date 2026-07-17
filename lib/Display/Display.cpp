/******************************************************************************
 *
 * Project    : Robonix AccelMeter
 * Module     : Display
 * File       : Display.cpp
 *
 * Version    : 2.0.0
 *
 ******************************************************************************/

 #include "Display.h"

 #include <stdio.h>
 #include <string.h>
 
 /*=============================================================================
     Global Instance
 =============================================================================*/
 
 Display display;
 
 /*=============================================================================
     Constructor
 =============================================================================*/
 
 Display::Display()
     :
     lcd_(kLcdAddress,
          kLcdColumns,
          kLcdRows)
 {
     runtime_.initialized   = false;
     runtime_.autoPageEnabled = kAutoPageEnabled;
     runtime_.currentPage   = DisplayPage::Acceleration;
 
     runtime_.lastRefresh   = 0U;
     runtime_.lastPageChange = 0U;
 
     clearCache();
 }
 
 /*=============================================================================
     Initialization
 =============================================================================*/
 
 bool Display::begin()
 {
     lcd_.init();
 
     lcd_.backlight();
 
     lcd_.clear();
 
     runtime_.initialized = true;
 
     runtime_.lastRefresh = millis();
 
     runtime_.lastPageChange = millis();
 
     return true;
 }
 
 /*=============================================================================
     Update
 =============================================================================*/
 
 bool Display::update(Model& model)
 {
     if (!runtime_.initialized)
     {
         return false;
     }
 
     refresh(model);
 
     return true;
 }