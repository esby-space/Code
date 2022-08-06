#include "DEV_Config.hpp"
#include "TCS34725.hpp"
#include "SerialTransfer.h"

#define RED 9
#define GREEN 10
#define BLUE 11

#define RED2 6
#define GREEN2 5
#define BLUE2 3

SerialTransfer trans;

void setup()
{
    Config_Init();
    if (TCS34725_Init() != 0)
    {
        Serial.print("TCS34725 initialization error!!\r\n");
    }

    Serial.print("TCS34725 initialization success!!\r\n");

    trans.begin(Serial);

    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);

    pinMode(RED2, OUTPUT);
    pinMode(GREEN2, OUTPUT);
    pinMode(BLUE2, OUTPUT);
}

RGB rgb, RGB888;
void loop()
{
    rgb = TCS34725_Get_RGBData();
    RGB888 = TCS34725_GetRGB888(rgb);
    sendData(RGB888);

    printSensor(rgb);
    displayLED(RGB888);
    changeColor();

    delay(500);
}

int incomingByte = 0;
void changeColor()
{
    if (Serial.available() > 0)
    {
        incomingByte = Serial.read();
        if (incomingByte == 114)
        {
            // r -> red
            digitalWrite(RED, HIGH);
            digitalWrite(GREEN, LOW);
            digitalWrite(BLUE, LOW);
            Serial.println("changing color to red");
        }
        else if (incomingByte == 103)
        {
            // g -> green
            digitalWrite(RED, LOW);
            digitalWrite(GREEN, HIGH);
            digitalWrite(BLUE, LOW);
            Serial.println("changing color to green");
        }
        else if (incomingByte == 98)
        {
            // b -> blue
            digitalWrite(RED, LOW);
            digitalWrite(GREEN, LOW);
            digitalWrite(BLUE, HIGH);
            Serial.println("changing color to blue");
        }
        else if (incomingByte == 111)
        {
            // o --> off
            digitalWrite(RED, LOW);
            digitalWrite(GREEN, LOW);
            digitalWrite(BLUE, LOW);
            Serial.println("turning off the led");
        }
    }
}

void displayLED(RGB rgb)
{
    analogWrite(RED2, rgb.R);
    analogWrite(GREEN2, rgb.G);
    analogWrite(BLUE2, rgb.B);
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

void sendData(RGB rgb)
{
    u16 arr[] = {rgb.R, rgb.G, rgb.B};
    trans.sendDatum(arr);
}
