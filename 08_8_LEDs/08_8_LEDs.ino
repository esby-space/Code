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

void setup()
{
    Config_Init();
}

void loop()
{
}
