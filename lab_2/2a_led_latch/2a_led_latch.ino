/*
 * 2a_led_latch.ino
 *
 * this is a simple Arduino program to use a push button to latch an led (i.e. 
 * one press turns it on, the next press turns it off, etc.).
 *
 * this program uses pin 7 for the push button and pin 6 for the led (this 
 * is the built in led on the MKR series of boards).
 *
 * author: alex shenfield
 * date:   2024-11-12
 */

// set pin numbers for button and led
const int button_pin = 7;
const int led_pin    = 6;  

// variable for latching the led
int led_state = LOW;

// CODE

// set up code
void setup()
{
  // set pin i/o
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
}

// main program
void loop()
{
  // read the state of the pushbutton value:
  int button_state = digitalRead(button_pin);

  // if the button is pressed toggle the state of the led
  if (button_state == HIGH)
  {
    led_state = !led_state;
    digitalWrite(led_pin, led_state);
  }
}
