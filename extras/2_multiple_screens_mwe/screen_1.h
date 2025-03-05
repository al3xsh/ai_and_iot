// SCREEN 1

// define the button(s) and coordinates

// for the screen 1 button(s) (i.e. switching screen), we have a standard 
// size of 40 pixels
int s1_button_size = 40;

// CODE

// set up function for screen 1
void screen_1_setup()
{
  // set the proper rotation and make the screen black
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);

  // create the title text, with a line underneath

  // display the title text using text size = 2
  // e.g. 16 pixels high x 12 pixels wide
  tft.setCursor(10, 5);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_GREEN, ILI9341_BLACK);
  tft.print("Multi-screen demo");
  tft.drawLine(0, 26, 320, 26, ILI9341_GREEN);
  
  // display some text on the screen
  tft.setCursor(10, 50);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_GREEN, ILI9341_BLACK);
  tft.print("Screen 1");
  
  // set the buttons up

  // switch screen button(s)

  // screen 1
  screen_1_button.initButton(&tft, 
                             screen_1_button_x, screen_1_button_y, 
                             screen_1_button_sz, s1_button_size, 
                             ILI9341_GREEN, ILI9341_BLACK, ILI9341_GREEN, 
                             "Screen 1", 1, 1);
  screen_1_button.drawButton(true);

  // screen 2
  screen_2_button.initButton(&tft, 
                             screen_2_button_x, screen_2_button_y, 
                             screen_2_button_sz, s1_button_size, 
                             ILI9341_LIGHTGREY, ILI9341_BLACK, ILI9341_LIGHTGREY, 
                             "Screen 2", 1, 1);
  screen_2_button.drawButton(true);

  // reset the screen rendering control flag
  just_changed_screen = false;

}

// loop function for screen 1
void screen_1_loop_ts()
{
  // if the touch screen has been pressed ...
  if (ts.touched())
  {
    // get the touch coordinate and flip it to match the orientation of the 
    // screen
    TS_Point p = ts.getPoint(); 
    p.x = map(p.x, 0, 240, 240, 0);
    p.y = map(p.y, 0, 320, 320, 0);
    int y = tft.height() - p.x;
    int x = p.y;

    // switch screens ...

    // check the monitoring screen button
    if (screen_2_button.contains(x, y))
    {
      screen_2_button.press(true);
    }
  }
  // as soon as it's released, reset all the button presses
  else
  {
    screen_2_button.press(false);
  }

  // switch screens

  // screen 2 button
  if (screen_2_button.justPressed())
  {
    screen_idx = 2;
    just_changed_screen = true;
  }
}
