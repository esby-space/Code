#include <Arduino.h>
#line 1 "/Users/esby/Documents/Spectroscopy/Code/08_8_LEDs/08_8_LEDs.ino"
#include "DEV_Config.hpp"
#include "TCS34725.hpp"
#include "SerialTransfer.h"

const int RED = 3;
const int GREEN = 5;
const int BLUE = 6;

const int RED_DISPLAY = 9;
const int GREEN_DISPLAY = 10;
const int BLUE_DISPLAY = 11;

SerialTransfer trans;

#line 15 "/Users/esby/Documents/Spectroscopy/Code/08_8_LEDs/08_8_LEDs.ino"
void setup();
#line 20 "/Users/esby/Documents/Spectroscopy/Code/08_8_LEDs/08_8_LEDs.ino"
void loop();
#line 15 "/Users/esby/Documents/Spectroscopy/Code/08_8_LEDs/08_8_LEDs.ino"
void setup()
{
    Config_Init();
}

void loop()
{
}

