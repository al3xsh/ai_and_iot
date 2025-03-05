// COMMON CONTROLS FOR DIFFERENT SCREENS

// TRACKING VARIABLES

// keep track of which screen we are on and whether we have just switched
// screen
int  screen_idx = 1;
bool just_changed_screen   = true;

// BUTTONS

// button to switch screen to screen 1
Adafruit_GFX_Button screen_1_button;
int screen_1_button_x  = 80;
int screen_1_button_y  = 210;
int screen_1_button_sz = 140;

// button to switch screen to screen 2
Adafruit_GFX_Button screen_2_button;
int screen_2_button_x  = 240;
int screen_2_button_y  = 210;
int screen_2_button_sz = 140;
