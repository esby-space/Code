# 1 "/Users/esby/Documents/Spectroscopy/Code/06_feedback/06_feedback.ino"
# 2 "/Users/esby/Documents/Spectroscopy/Code/06_feedback/06_feedback.ino" 2
# 3 "/Users/esby/Documents/Spectroscopy/Code/06_feedback/06_feedback.ino" 2

const int RED = 9;
const int GREEN = 10;
const int BLUE = 11;

const int RED_DISPLAY = 6;
const int GREEN_DISPLAY = 5;
const int BLUE_DISPLAY = 3;

void setup()
{
    Config_Init();
    if (TCS34725_Init() != 0)
    {
        Serial.print("TCS34725 initialization error!!\r\n");
    }

    Serial.print("TCS34725 initialization success!!\r\n");

    pinMode(RED, 0x1);
    pinMode(GREEN, 0x1);
    pinMode(BLUE, 0x1);

    pinMode(RED_DISPLAY, 0x1);
    pinMode(GREEN_DISPLAY, 0x1);
    pinMode(BLUE_DISPLAY, 0x1);
}

void loop()
{
    RGB rgb = TCS34725_Get_RGBData();
    RGB RGB888 = TCS34725_GetRGB888(rgb);
    printSensor(rgb);

    changeColor(RGB888);
    displayLED(RGB888);

    delay(500);
}

void changeColor(RGB rgb)
{
    analogWrite(RED, rgb.R);
    analogWrite(GREEN, rgb.G);
    analogWrite(BLUE, rgb.B);
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
