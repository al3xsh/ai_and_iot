/*
 * 2_multiple_screens_mwe.ino
 * 
 * developing a minimum working example for a multiscreen touch screen demo 
 * using the adafruit gfx libraries and drivers for the adafruit 2.8" TFT + 
 * capactive touchscreen display breakout:
 * 
 * https://www.adafruit.com/product/2090
 *  
 * some notes:
 * 1) the x,y coordinates start at 0,0 in the top left corner
 * 2) calculating positions for text is actually quite complicated - the base 
 *    font size is 6x8 pixels (with the size parameter multiplying that)
 * 
 * author: alex shenfield
 * date:   26/01/2024
 */

// LIBRARY IMPORTS
 
// include the necessary libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>

// INITIAL VARIABLES

// OUTPUTS

// ...

// SENSORS

// ...

// TIMING VARIABLES

// ...

// LCD AND TOUCHSCREEN

// define the custom pins
#define TFT_DC 6
#define TFT_CS 7
#define TFT_RST 5

// create display and touchscreen objects
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
Adafruit_FT6206   ts = Adafruit_FT6206();

// include my additional files and functions
#include "common_screens.h"
#include "screen_1.h"
#include "screen_2.h"

// CODE

// this method runs once (when the sketch starts)
void setup() 
{  
  // SERIAL COMMS FOR DEBUGGING
  
  // initialise serial communication at 115200 bits per second, wait for 
  // the serial port to become available, and print a start up message
  Serial.begin(115200);
  while (!Serial) ;
  Serial.println("multi screen demo!");

  // SCREEN
  
  // start the touchscreen and the tft screen
  ts.begin();
  tft.begin();
  print_diagnostics();
}

// this method loops continuously
void loop() 
{
  // manage the screen
  switch (screen_idx)
  {
    // if we're on screen 1 ...
    case 1:
    
      // if we need to set the screen up ...
      if (just_changed_screen)
      {
        screen_1_setup();
      }
      
      // check the touchscreen
      screen_1_loop_ts();  
      break;   

    // if we're on screen 2 ...
    case 2:
    
      // if we need to set the screen up ...
      if (just_changed_screen)
      {
        screen_2_setup();
      }

      // check the touchscreen
      screen_2_loop_ts();
      break;   
  }

  // DO GENERAL ACTIONS (E.G. READ SENSORS) HERE

  // ...

}

// UTILITY FUNCTIONS

// print some simple diagnostic information about the TFT LCD
// (this is optional but can help debug problems – e.g. the lcd not  
// properly connected)
void print_diagnostics()
{
  uint8_t x = 0;
  x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("display power mode: 0x"); 
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL mode: 0x"); 
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("pixel format: 0x"); 
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("image format: 0x"); 
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("self diagnostic: 0x"); 
  Serial.println(x, HEX); 
}
