#include "DEV_Config.hpp"
#include "TCS34725.hpp"

const int RED = 3;
const int GREEN = 5;
const int BLUE = 6;

const int RED_DISPLAY = 9;
const int GREEN_DISPLAY = 10;
const int BLUE_DISPLAY = 11;

void setup()
{
    Config_Init();
    if (TCS34725_Init() != 0)
    {
        Serial.print("TCS34725 initialization error!!\r\n");
    }

    Serial.print("TCS34725 initialization success!!\r\n");

    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(RED_DISPLAY, OUTPUT);
    pinMode(GREEN_DISPLAY, OUTPUT);
    pinMode(BLUE_DISPLAY, OUTPUT);

    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}

RGB rgb, RGB888;
void loop()
{
    rgb = TCS34725_Get_RGBData();
    RGB888 = TCS34725_GetRGB888(rgb);
    printSensor(rgb);
    displayLED(RGB888);
    changeColor();

    delay(500);
}

int incomingByte = 0;
int CURRENT_COLOR = RED;
void changeColor()
{
    if (Serial.available() > 0)
    {
        incomingByte = Serial.read();
    }

    if (incomingByte >= 48 && incomingByte <= 56)
    {
        int brightness = (incomingByte - 48) * 32;
        if (brightness == 256) brightness = 255;
        
        Serial.print("\nchanging brightness to ");
        Serial.print(brightness);
        Serial.print("\n");
        analogWrite(CURRENT_COLOR, brightness);
    }
    else
    {
        switch (incomingByte)
        {
        case 114:
            Serial.print("\nchanging color to red\n");
            analogWrite(CURRENT_COLOR, 0);
            CURRENT_COLOR = RED;
            break;
        case 103:
            Serial.print("\nchanging color to green\n");
            analogWrite(CURRENT_COLOR, 0);
            CURRENT_COLOR = GREEN;
            break;
        case 98:
            Serial.print("\nchanging color to blue\n");
            analogWrite(CURRENT_COLOR, 0);
            CURRENT_COLOR = BLUE;
            break;
        }
    }
}

void displayLED(RGB rgb)
{
    analogWrite(RED_DISPLAY, rgb.R);
    analogWrite(GREEN_DISPLAY, rgb.G);
    analogWrite(BLUE_DISPLAY, rgb.B);
}

void printSensor(RGB rgb)
{
    Serial.print("R = ");
    Serial.print(rgb.R);
    Serial.print(" G = ");
    Serial.print(rgb.G);
    Serial.print(" B = ");
    Serial.print(rgb.B);
    Serial.print("\r\n");
}
