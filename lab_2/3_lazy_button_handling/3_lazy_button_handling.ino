/*
 * 3_lazy_button_handling.ino
 * 
 * a simple example of using the EasyButton library to handle button presses
 * without a loads of extra code. this provides all the functionality in the 
 * previous debouncing and latching examples, just without the need to manage
 * timings ourselves.
 *
 * this program uses pins 8 and 9 for the push buttons and pins 6 and 7 for the
 * leds (pin 6 is the built in led on the MKR series of boards).
 *
 * author: prof. alex shenfield
 * date:   2024-11-12
 */

// LIBRARY IMPORTS

// include our lazy button library
#include <EasyButton.h>

// BUTTON AND LED DECLARATIONS

// light bulb settings
const int light_bulb_1 = 6;
const int light_bulb_2 = 7;
int light_state_1 = LOW;
int light_state_2 = LOW;

// light switch 1 (on pin 8) and 2 (on pin 9) 
EasyButton light_switch_1(8);
EasyButton light_switch_2(9);

// CODE

// this method runs once (when the sketch starts)
void setup() 
{
  // set up serial comms for debugging 
  Serial.begin(9600);
  while (!Serial);
  Serial.println("starting lazy button handler ..."); 
  
  // set up the first light bulb and light switch (including the button 
  // pressed callback function)
  pinMode(light_bulb_1, OUTPUT);
  light_switch_1.begin();
  light_switch_1.onPressed(light_toggle_1);
  
  // set up the second light bulb and light switch (including the button 
  // pressed callback function)
  pinMode(light_bulb_2, OUTPUT);
  light_switch_2.begin();
  light_switch_2.onPressed(light_toggle_2);
}

// this methods loops continuously
void loop() 
{
  // read the buttons statuses
  light_switch_1.read();
  light_switch_2.read();
}

// APPLICATION FUNCTIONS

// callback function attached to the first light switch button
void light_toggle_1()
{
  // print a status message
  Serial.println("button 1 pressed!");
  
  // toggle the state of the light
  light_state_1 = !light_state_1;
  digitalWrite(light_bulb_1, light_state_1);
}

// callback function attached to the second light switch button
void light_toggle_2()
{
  // print a status message
  Serial.println("button 2 pressed!");
  
  // toggle the state of the light
  light_state_2 = !light_state_2;
  digitalWrite(light_bulb_2, light_state_2);
}
